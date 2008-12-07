/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004-12-13 08:38:54 $
// $Revision: 1.2 $
// 
/////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <cassert>
#include <iomanip>
#include "BasicTransport/PSTypes.h"
#include "Miscellaneous/BeamBeamLuminosity.h"

namespace {

	using namespace std;

	// Exception
	struct BadMatrix {};

	typedef PSmoments SigmaMatrix;

	double DetSymm3Mtrx(const double Q[3][3])
	{
		//*debug<<endl;
		//*debug<<"finding determinant of:"<<endl;
		//Print3Matrix(Q,*debug);
		double d1 = -Q[0][2]*Q[0][2]*Q[1][1];
		double d2 = 2*Q[0][1]*Q[0][2]*Q[1][2];
		double d3 = -Q[0][1]*Q[0][1]*Q[2][2];
		double d4 = Q[0][0]*(Q[1][1]*Q[2][2]-Q[1][2]*Q[1][2]);
		double det = d1+d2+d3+d4;
		//*debug<<"result = "<<det<<endl;
		return det;
			/*
		return -Q[0][2]*Q[0][2]*Q[1][1]+2*Q[0][1]*Q[0][2]*Q[1][2]-
			Q[0][1]*Q[0][1]*Q[2][2]+Q[0][0]*(-Q[1][2]*Q[1][2]+Q[1][1]*Q[2][2]);
			*/
	}
	
	void BuildQu(const SigmaMatrix& s,double z,double Q[3][3])
	{
		// Constructs R(z).s.R'(z) and takes the
		// projection on the X-Y plane, returning it in Q
		Q[0][0]        =s(0,0)+z*s(0,1)+z*(s(0,1)+z*s(1,1));
		Q[0][1]=Q[1][0]=s(0,2)+z*s(1,2)+z*(s(0,3)+z*s(1,3));
		Q[0][2]=Q[2][0]=s(0,4)+z*s(1,4);
		Q[1][1]        =s(2,2)+z*s(2,3)+z*(s(2,3)+z*s(3,3));
		Q[1][2]=Q[2][1]=s(2,4)+z*s(3,4);
		Q[2][2]        =s(4,4);
	}	

	double InvertSymm3Mtrx(const double Q[3][3], double Qi[3][3])
	{
		Qi[0][0] = -Q[1][2]*Q[1][2]+Q[1][1]*Q[2][2];
		Qi[0][1] = Q[0][2]*Q[1][2]-Q[0][1]*Q[2][2];
		Qi[0][2] = -Q[0][2]*Q[1][1]+Q[0][1]*Q[1][2];
		Qi[1][1] = -Q[0][2]*Q[0][2]+Q[0][0]*Q[2][2];
		Qi[1][2] = Q[0][1]*Q[0][2]-Q[0][0]*Q[1][2];
		Qi[2][2] = -Q[0][1]*Q[0][1]+Q[0][0]*Q[1][1];
		
		Qi[1][0] = Qi[0][1];
		Qi[2][0] = Qi[0][2];
		Qi[2][1] = Qi[1][2];
		
		return DetSymm3Mtrx(Q);
	}
	
	struct LumiIntegrand {
	public:
		
		LumiIntegrand(const SigmaMatrix& s1, const SigmaMatrix& s2)
			: S1(s1),S2(s2) 
		{}
		
		// z is the independent integration variable
		double operator()(double z) const;
		
	private:
		
		const SigmaMatrix& S1;
		const SigmaMatrix& S2;
	};
	
	
	double LumiIntegrand::operator()(double z) const 
	{
		double A[3];
		double Q1[3][3];
		double Q2[3][3];
		double Q[3][3];
		double Qi[3][3];
		
		A[0]=S1[0]-S2[0]+z*(S1[1]+S2[1]);
		A[1]=S1[2]-S2[2]+z*(S1[3]+S2[3]);
		A[2]=S1[4]-S2[4]-2*z;
		
		// As we only have to deal with 3x3 matrices here, lets
		// do the inversion explicitly !
		
		// Set up the Q matrix
		BuildQu(S1,z,Q1);
		BuildQu(S2,-z,Q2);
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				Q[i][j]=Q1[i][j]+Q2[i][j];

		/* ***DEBUG
		Print3Vector(A,*debug);
		*debug<<endl;
		Print3Matrix(Q1,*debug);
		*debug<<endl;
		Print3Matrix(Q2,*debug);
		*debug<<endl;
		Print3Matrix(Q,*debug);
		*debug<<endl;
		*/

		// Calculate its inverse
		try {
			double det = InvertSymm3Mtrx(Q,Qi);
			/* ***DEBUG
			Print3Matrix(Qi,*debug);
			*debug<<"determinant ="<<det<<endl;
			*/
			double prod=0.0;
			for(int i=0; i<3; i++) {
				for(int j=0; j<3; j++) {
					prod+=A[i]*Qi[i][j]*A[j];
				}
			}
			/* ***DEBUG
			*debug<<prod<<' ';
			prod/=det;
			*debug<<prod<<endl;
			*/
			return exp(-prod/det/2)/sqrt(det);
		}
		catch(BadMatrix) {
			cerr<<"*** bad luminosity matrix in lumi calculation"<<endl;
			assert(false);
		}
		return 0;
	}
	

}; 

// CalculateLumi
// Calculates luminosity of two colliding beams with 6D gaussian distributions,
// represented by their first and second order moments (beam1 and beam2)
// This calculation does not include any beam-beam effects

double CalculateLuminosity(const SigmaMatrix& beam1, const SigmaMatrix& beam2)
{
	static const int nsteps = 100;
	static const double pi = 4*atan(1.0);
	static const double a0 = 1/sqrt(2*pi*pi*pi);
	
	double sigz = sqrt(beam1.variance(4)+beam2.variance(4));
	double dz = 6*sigz/nsteps;

	double lumi=0.0;

	LumiIntegrand integrand(beam1,beam2);

	double z=-3*sigz;
	for(int i=0;i<=nsteps;i++){
		double x=integrand(z);
		lumi+=x;
		z+=dz;
	}
	lumi*=a0*dz;
	
	return lumi;
}

//## begin module%396B2620019A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\GroundMotionModels\ATL2D.cpp
 * last modified 28/03/01 17:26:52
 */
//## end module%396B2620019A.cm

//## begin module%396B2620019A.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 *
 * Copyright (c) 2000 by The Merlin Collaboration.  
 * ALL RIGHTS RESERVED. 
 *
 * Permission to use, copy, modify, distribute and sell this
 * software and its documentation for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * No representations about the suitability of this software for
 * any purpose is made. It is provided "as is" without express
 * or implied warranty.
 */
//## end module%396B2620019A.cp

//## Module: ATL2D%396B2620019A; Pseudo Package body
//## Subsystem: Merlin::GroundMotionModels%396B6A3101D6
//## Source file: D:\dev\Merlin\GroundMotionModels\ATL2D.cpp

//## begin module%396B2620019A.includes preserve=yes
#include <fstream>
#include <algorithm>
#include <iomanip>
//## end module%396B2620019A.includes

// RandomNG
#include "Random/RandomNG.h"
// ATL2D
#include "GroundMotionModels/ATL2D.h"
//## begin module%396B2620019A.additionalDeclarations preserve=yes

#undef ATL_XY

namespace {

	using namespace std;

	inline void ResetSupport(AcceleratorSupport* s)
	{
		s->Reset();
	}

	struct ApplyATL {
		
		ApplyATL(RealVector& gmy, double vibv, RandGenerator* rg, ATL2D::ATLMode theMode) 
			: n(0),yy(gmy),vv(vibv),rng(rg),atlMode(theMode) {}

		void operator()(AcceleratorSupport* s)
		{
			if(atlMode == ATL2D::increment)
				s->IncrementOffset(0,yy(n),0);
			else
			{
				// add random 'noise'
				double yv = vv!=0 ? rng->normal(0,vv) : 0.0;
				s->SetOffset(0,yy(n)+yv,0);
			}

			n++;
		}

		// data members
		int n;
		RealVector yy;
		double vv;
		RandGenerator* rng;
		ATL2D::ATLMode atlMode;
	};

	struct DumpOffset {

		DumpOffset(ostream& anOS, const double t): os(anOS),time(t) {}

		void operator()(const AcceleratorSupport* s) 
		{
			using std::setw;
			os<<setw(14)<<time;
			double arcs =s->GetArcPosition();
			os<<setw(14)<<arcs;
			Point2D locn=s->GetLocation();
			os<<setw(14)<<locn.x;
			os<<setw(14)<<locn.y;
			Vector3D offset=s->GetOffset();
//			os<<setw(14)<<offset.x;
			os<<setw(14)<<offset.y;
//			os<<setw(14)<<offset.z;
			os<<endl;
		}

		ostream& os;
		double time;
	};

}; // end of anonymous namespace

//## end module%396B2620019A.additionalDeclarations


// Class ATL2D 

//## Operation: ATL2D%963324079; C++
ATL2D::ATL2D (double anA, const AcceleratorSupportList& supports, const Point2D refPoint, ifstream* evecTFile, ifstream* evalFile)
  //## begin ATL2D::ATL2D%963324079.initialization preserve=yes
  : t(0),A(anA),seed(0),vv(0),theSupports(supports),rg(new RandGenerator()),atlMode(absolute)
  //## end ATL2D::ATL2D%963324079.initialization
{
  //## begin ATL2D::ATL2D%963324079.body preserve=yes
	const int n = theSupports.size();

	evecsT.redim(n,n);
	evals.redim(n);

	if(evecTFile && evalFile)
	{
		double element;
		for(int row=0;   row<n; row++)
		for(int col=row; col<n; col++)
		{
			(*evecTFile)>>element;
			evecsT(row,col) = evecsT(col,row) = element;
		}

		for(    row=0; row<n; row++)
			(*evalFile)>>evals(row);
	}
	else
	{
		for(int row=0;   row<n; row++)
		for(int col=row; col<n; col++)
			evecsT(row,col) = evecsT(col,row) = (Distance(col,refPoint) + Distance(row,refPoint) - Distance(row,col))/2.0;
	
		EigenSystemSymmetricMatrix(evecsT, evals);
	}

	rg->init(seed);
  //## end ATL2D::ATL2D%963324079.body
}

//## Operation: ~ATL2D%963324087; C++
ATL2D::~ATL2D ()
{
  //## begin ATL2D::~ATL2D%963324087.body preserve=yes
	delete rg;
  //## end ATL2D::~ATL2D%963324087.body
}

//## Other Operations (implementation)
//## Operation: Reset%963324080; C++
void ATL2D::Reset ()
{
  //## begin ATL2D::Reset%963324080.body preserve=yes
	for_each(theSupports.begin(),theSupports.end(),ResetSupport);
	t=0;
  //## end ATL2D::Reset%963324080.body
}

//## Operation: DoStep%963324081; C++
double ATL2D::DoStep (double dt)
{
  //## begin ATL2D::DoStep%963324081.body preserve=yes
	RealVector yy(theSupports.size());

	double at = (atlMode==increment) ? A * dt : A * t;

	for(int n=0; n<theSupports.size(); n++)
		yy(n) = rg->normal(0,at*evals[n]);

	RealVector dy = evecsT * yy;

	for_each(theSupports.begin(),theSupports.end(),ApplyATL(dy,vv,rg,atlMode));

	return t+=dt;
  //## end ATL2D::DoStep%963324081.body
}

//## Operation: RecordOffsets%963324082; C++
void ATL2D::RecordOffsets (std::ostream& os) const
{
  //## begin ATL2D::RecordOffsets%963324082.body preserve=yes
	ios_base::fmtflags oldFlags = os.flags();
	int prec = os.precision();

	os.setf(ios_base::scientific,ios_base::floatfield);
	os.precision(4);

	for_each(theSupports.begin(),theSupports.end(),DumpOffset(os,t));

	os.flags(oldFlags);
	os.precision(prec);
  //## end ATL2D::RecordOffsets%963324082.body
}

//## Operation: GetTime%963324083; C++
double ATL2D::GetTime () const
{
  //## begin ATL2D::GetTime%963324083.body preserve=yes
	return t;
  //## end ATL2D::GetTime%963324083.body
}

//## Operation: SetRandomSeed%963324084; C++
void ATL2D::SetRandomSeed (unsigned int nseed)
{
  //## begin ATL2D::SetRandomSeed%963324084.body preserve=yes
	rg->reset(nseed);
  //## end ATL2D::SetRandomSeed%963324084.body
}

//## Operation: GetRandomSeed%963324085; C++
unsigned int ATL2D::GetRandomSeed () const
{
  //## begin ATL2D::GetRandomSeed%963324085.body preserve=yes
	return rg->getSeed();
  //## end ATL2D::GetRandomSeed%963324085.body
}

//## Operation: ResetRandomSeed%963324086; C++
void ATL2D::ResetRandomSeed ()
{
  //## begin ATL2D::ResetRandomSeed%963324086.body preserve=yes
	rg->reset();
  //## end ATL2D::ResetRandomSeed%963324086.body
}

bool ATL2D::SetATLMode(const ATLMode mode)
{
	if( (atlMode==increment) && (vv>0) )
		return false;

	atlMode = mode;
	return true;
}

bool ATL2D::SetVibration(const double vrms)
{
	if(atlMode==increment)
		return false;

	vv = vrms*vrms;
	return true;
}

void ATL2D::RecordEigenSystem(ofstream* evecTFile, ofstream* evalFile)
{
	const int n = evals.size();

	for(int row=0;   row<n; row++)
	{
		for(int col=row; col<n; col++)
			(*evecTFile)<<std::setw(14)<<evecsT(row,col);
		(*evecTFile)<<endl;
	}

	for(    row=0; row<n; row++)
		(*evalFile)<<std::setw(14)<<evals(row)<<endl;
}

double ATL2D::Distance(const int n1, const int n2)
{
	const Point2D x1 = theSupports[n1]->GetLocation();
	const Point2D x2 = theSupports[n2]->GetLocation();

	const Point2D dx = x1 - x2;

	return sqrt( dx.x * dx.x + dx.y * dx.y );
}

double ATL2D::Distance(const int n1, const Point2D x2)
{
	const Point2D x1 = theSupports[n1]->GetLocation();

	const Point2D dx = x1 - x2;

	return sqrt( dx.x * dx.x + dx.y * dx.y );
}

//## begin module%396B2620019A.epilog preserve=yes
//## end module%396B2620019A.epilog

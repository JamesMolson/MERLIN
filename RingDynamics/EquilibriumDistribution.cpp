#include <fstream>
#include "NumericalUtils/PhysicalConstants.h"
#include "NumericalUtils/PhysicalUnits.h"
#include "BeamDynamics/ProcessStepManager.h"
#include "BeamDynamics/ParticleTracking/ParticleTransportProcess.h"
#include "BeamDynamics/ParticleTracking/SynchRadParticleProcess.h"
#include "RingDynamics/DoTrack.h"
#include "RingDynamics/ClosedOrbit.h"
#include "RingDynamics/TransferMatrix.h"
#include "RingDynamics/DampingParameters.h"
#include "NumericalUtils/MatrixPrinter.h"

using namespace std;
using namespace PhysicalConstants;
using namespace PhysicalUnits;

EquilibriumDistribution::EquilibriumDistribution(AcceleratorModel* aModel, double refMomentum, vector<double>& dampingConst)
: theModel(aModel), p0(refMomentum), dampingConstant(&dampingConst) {}

void EquilibriumDistribution::FindA2()
{
	using RingDynamicsImpl::DoTrack;

	const double dscale = 1.0e-6;

	AcceleratorModel::BeamlineIterator beginBL = (*theModel).GetBeamline().begin();
	AcceleratorModel::BeamlineIterator endBL = (*theModel).GetBeamline().end();

	int k; // used twice, but MS doesn't following ANSI scoping rules

	double SumE5[3];
	for(k=0; k<3; k++)
		SumE5[k] = 0.0;
	

	ClosedOrbit CO(theModel,p0);
	CO.transverseOnly = false;
	CO.radiation = false;

	PSvector orbit(0);
	CO.FindClosedOrbit(orbit);

	RealMatrix M(6);
	ComplexVector eigenvalues(3);
	ComplexMatrix eigenvectors(3,6);
	ComplexVector newEigenvector(6);

	TransferMatrix TM(theModel, p0, false);
	TM.FindTM(M, orbit);

	ofstream rmatrix("matrix.dat");
	rmatrix<<"Before symplectic adjustment\n\n";
	MatrixForm(M,rmatrix,OPFormat().precision(12).fixed());

//	for(int row=0; row<6; row++)
//	{
//		for(int col=0; col<6; col++) rmatrix<<std::setw(20)<<std::setprecision(12)<<M(row,col);
//		rmatrix<<endl;
//	}

	//Need to fix the R53 and R54 terms, which are not calculated correctly
	//for a distorted closed orbit (tracking problem!)
//	M(4,2) = -( -M(2,2)*M(3,1)*M(4,0) + M(2,1)*M(3,2)*M(4,0)
//				+M(2,2)*M(3,0)*M(4,1) - M(2,0)*M(3,2)*M(4,1)
//				+M(2,5)*M(3,2)*M(4,4) - M(2,2)*M(3,5)*M(4,4)
//				-M(2,4)*M(3,2)*M(4,5) + M(2,2)*M(3,4)*M(4,5) )
//				/(M(2,3)*M(3,2)-M(2,2)*M(3,3));

//	M(4,3) =  ( -M(3,3)*M(2,1)*M(4,0) + M(3,3)*M(2,0)*M(4,1)
//				-M(3,3)*M(2,5)*M(4,4) + M(3,3)*M(2,4)*M(4,5)
//				+M(2,3)*M(3,1)*M(4,0) - M(2,3)*M(3,0)*M(4,1)
//				+M(2,3)*M(3,5)*M(4,4) - M(2,3)*M(3,4)*M(4,5) )
//				/(M(2,3)*M(3,2)-M(2,2)*M(3,3));

	//Just make sure the matrix is symplectic
	Symplectify(M);
	rmatrix<<"\n\nAfter symplectic adjustment\n\n"<<endl;
	MatrixForm(M,rmatrix,OPFormat().precision(12).fixed());

	EigenSystem(M, eigenvalues, eigenvectors);

	ParticleBunch particle(p0, 1.0);
	for(int n=0; n<7; n++)
	{
		Particle p = orbit;
		if(n!=6) 
			p[n] += dscale;
		particle.push_back(p);
	}

	ProcessStepManager myPSM;
	ParticleTransportProcess* transport = new ParticleTransportProcess();
	transport->UseFullAcceleration(false);

	myPSM.AddProcess(transport);
	myPSM.Initialise(particle);

	int n1, n2;
	n1 = n2 = 0;
	for(AcceleratorModel::BeamlineIterator itrBL=beginBL; itrBL!=endBL; itrBL++)
	{
		SectorBend* sb = dynamic_cast<SectorBend*>(&(*itrBL)->GetComponent());
		if(sb && sb->GetB0())
		{
		        // ANSI C++ forbids passing non-const references
		        // to temporaries - NJW
		        DoTrack dotrack(myPSM,particle);
			(*theModel).GetBeamline(n1,n2-1).Track(dotrack);
			// (*theModel).GetBeamline(n1,n2-1).Track(DoTrack(myPSM,particle));
			n1 = n2;
			
			const Particle& p_ref = particle.GetParticles().back();
			
			for(k=0; k<3; k++)
			{
				newEigenvector = 0;

				for(int row=0; row<6; row++) {
					ParticleBunch::const_iterator p = particle.begin();
					for(int col=0; col<6; col++,p++)
						newEigenvector(row) += ((*p)[row] - p_ref[row]) * eigenvectors[k](col) / dscale;
				}
				SumE5[k] += IntegralEk5(newEigenvector,sb) / fabs(pow(p0/eV/SpeedOfLight/sb->GetB0(),3));
			}
		}
		n2++;
	}

	double C_L = 2.15813e-19;
	double gamma5 = pow(p0*ElectronCharge/eV/ElectronMass/SpeedOfLight/SpeedOfLight,5);

	for(k=0; k<3; k++)
		A2[k] = SumE5[k] * C_L * gamma5 / SpeedOfLight / (*dampingConstant)[k];
}

double EquilibriumDistribution::IntegralEk5(ComplexVector& Ek, SectorBend* sb)
{
	int nsteps = 200;
	double h = sb->GetB0() * eV * SpeedOfLight / p0;
	double dl = sb->GetLength() / nsteps;
	double hdl = h * dl;
	Complex k = sqrt(Complex(sb->GetB1() * eV * SpeedOfLight / p0,0));
	Complex kdl = k * dl;
	SectorBend::PoleFace* pf = (sb->GetPoleFaceInfo()).entrance;
	double tanE1 = pf ? tan( pf->rot ) : 0.0;
	double intgrl = 0.0;

	if(abs(k)==0)
	for(int nn=0; nn<nsteps; nn++)
	{
		double n = nn + 0.5;
		Complex sbendTM52 = -n * dl * n * hdl / 2;
		Complex sbendTM51 = -n * hdl + h * tanE1 * sbendTM52;
		Complex sbendTM56 = -pow(n*hdl,3) / h / 6;

		Complex Ek5l = sbendTM51 * Ek(0) + sbendTM52 * Ek(1) + Ek(4) + sbendTM56 * Ek(5);
		intgrl += abs(Ek5l) * abs(Ek5l);
	}
	else
	for(int nn=0; nn<nsteps; nn++)
	{
		double n = nn + 0.5;

		// Need to calculate cos(n * kdl)
		// but can't do it directly because of a bug in IBM VisualAge C++ Compiler!
		// A.Wolski 29/11/01
		double nkdl_re = n * kdl.real();
		double nkdl_im = n * kdl.imag();
		Complex cosnkdl = cos(nkdl_re) * cosh(nkdl_im) - Complex(0,1) * sin(nkdl_re) * sinh(nkdl_im);	

		Complex sbendTM52 = -(Complex(1,0) - cosnkdl) * h / k / k;
		Complex sbendTM51 = -sin(n * kdl) * h / k + h * tanE1 * sbendTM52;
		Complex sbendTM56 = -pow(h/k,2) * (n * dl - sin(n * kdl) / k);

		Complex Ek5l = sbendTM51 * Ek(0) + sbendTM52 * Ek(1) + Ek(4) + sbendTM56 * Ek(5);
		intgrl += abs(Ek5l) * abs(Ek5l);
	}


	return intgrl * dl;
}

void EquilibriumDistribution::FindMoment(int i, int j, double& moment, int ncpt)
{
	PSvector p(0);
	ClosedOrbit CO(theModel, p0, false, false);
	CO.FindClosedOrbit(p, ncpt);

	ComplexVector eigenvalues(3);
	ComplexMatrix eigenvectors(6,3);
	RealMatrix M(6);
	TransferMatrix TM(theModel, p0, false);

	TM.FindTM(M, p, ncpt);
	EigenSystem(M, eigenvalues, eigenvectors);
	
	moment = 0;
	for(int k=0; k<3; k++)
		moment += 2 * A2[k] * (eigenvectors(k,i).real() * eigenvectors(k,j).real() 
		+ eigenvectors(k,i).imag() * eigenvectors(k,j).imag());
}

#include "BeamDynamics/ParticleTracking/ParticleTracker.h" // NEW! NJW
#include "BeamDynamics/ParticleTracking/ParticleTransportProcess.h"
#include "BeamDynamics/ParticleTracking/SynchRadParticleProcess.h"
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"
#include "RingDynamics/ClosedOrbit.h"
#include "RingDynamics/DoTrack.h"
#include "TLAS/TLAS.h"
#include "TLAS/TMatrixLib.h"
#include "TLAS/TLASimp.h"

using namespace std;
using namespace TLAS;

ClosedOrbit::ClosedOrbit(AcceleratorModel* aModel, double refMomentum, bool isTransverseOnly, bool isRadiation)
	: theModel(aModel), p0(refMomentum), transverseOnly(isTransverseOnly), radiation(isRadiation), useFullAcc(false) {}

void ClosedOrbit::FindClosedOrbit(PSvector& p, int ncpt)
{
	const int cpt = transverseOnly ? 4 : 6;
	const double dscale = 1.0e-6;

	ParticleBunch particle(p0,1.0);
	int k=0;
	for(k=0; k<cpt+1; k++)
		particle.push_back(p);

	// Use high level ParticleTracker class for tracking.
	// ParticleTracker knows how to track a ring for one-turn
	// starting at any point (ncpt)
	// AcceleratorModel::GetRing(int) returns a AcceleratorModel::RingIterator!

	ParticleTracker tracker(theModel->GetRing(ncpt),&particle,false);
	tracker.UseFullAcceleration(useFullAcc);

	// We can still add additional processes
	// (ParticleTransportProcess is now automatically added)
	if(radiation) {
		SynchRadParticleProcess* syncrad = new SynchRadParticleProcess(1,50); //Must split dipole with radiation A.Wolski 1/10/01
		syncrad->AdjustBunchReferenceEnergy(useFullAcc);
		tracker.AddProcess(syncrad);
	}

	RealVector g(cpt);
	RealMatrix dg(cpt);
	w = 1.0;
	iter = 1;

	while((w>1e-26) && (iter<20))  //1e-32 reduced to 1e-26 A.Wolski 1/10/01
	{
		// Note that 'particle' now always corresponds to
		// the initial bunch (it is *not* the tracked bunch)

		// Note that I have now also defined the *first* particle
		// to be the reference ray

		ParticleBunch::iterator pp;

		k=0;
		for(pp=particle.begin(); pp!=particle.end(); pp++,k++)
		{
			*pp = p;
			if(k>0)
				(*pp)[k-1] += dscale;
		}

		// Do the 1-turn tracking, and get the result
		tracker.Run();

		ParticleBunch& particle1 = tracker.GetTrackedBunch();

		pp = particle1.begin();
		const Particle& p1 = *pp++; // reference particle

		for(k=0; k<cpt; k++,pp++)
		{
			for(int m=0; m<cpt; m++) dg(m,k) = ((*pp)[m] - p1[m]) / dscale;
			dg(k,k) -= 1.;
			g(k) = p1[k] - p[k];
		}

		SVDMatrix<double> invdg(dg);
		g = invdg(g);
		for(int row=0; row<cpt; row++) p[row] -= g(row);

		w = g*g; // dot product!
		iter++;

//		cout<<"Distance from closed orbit..."<<w<<endl;
//		cout<<"dp = "<<p[5]<<endl;
	}

}

void ClosedOrbit::FindRMSOrbit(PSvector& p)
{
	ParticleTracker tracker(theModel->GetBeamline(),p,p0);
	tracker.UseFullAcceleration(false);

	double len = 0.0;
	double dl = 0.0;
	PSvector prev = p;
	PSvector rms(0);

	tracker.InitStepper();
	bool loop=true;
	do {
		dl = tracker.GetCurrentComponent().GetLength();
		loop = tracker.StepComponent();

		PSvector pres = tracker.GetTrackedBunch().FirstParticle();

		for(int m=0; m<6; m++)
			rms[m] += dl * (pres[m] + prev[m]) * (pres[m] + prev[m]) / 4;

		prev = pres;
		len += dl;
	} while(loop);

	for(int m=0; m<6; m++)
		p[m] = sqrt(rms[m]/len);
}


/***********
void ClosedOrbit::FindRMSOrbit(PSvector& p)
{
	using RingDynamicsImpl::DoTrack;

	AcceleratorModel::BeamlineIterator beginBL = (*theModel).GetBeamline().begin();
	AcceleratorModel::BeamlineIterator endBL = (*theModel).GetBeamline().end();

	ParticleBunch particle(p0,1.0);
	particle.push_back(p);

	ProcessStepManager myPSM;

	myPSM.AddProcess(new ParticleTransportProcess());
	if(radiation) myPSM.AddProcess(new SynchRadParticleProcess(1));
	myPSM.Initialise(particle);

	double len = 0.0;
	double dl = 0.0;
	PSvector prev = p;
	PSvector rms(0);

	int n=0;
	for(AcceleratorModel::BeamlineIterator itrBL=beginBL; itrBL!=endBL; itrBL++)
	{
		dl = (*itrBL)->GetComponent().GetLength();

		(*theModel).GetBeamline(n,n).Track(DoTrack(myPSM,particle));

		PSvector pres = particle.FirstParticle();
		for(int m=0; m<6; m++)
			rms[m] += dl * (pres[m] + prev[m]) * (pres[m] + prev[m]) / 4;

		prev = pres;
		len += dl;
		n++;
	}

	for(int m=0; m<6; m++) p[m] = sqrt(rms[m] / len);
}
***************/

#include "BeamDynamics/ParticleTracking/ParticleTracker.h"
#include "BeamDynamics/ParticleTracking/SynchRadParticleProcess.h"
#include "RingDynamics/TransferMatrix.h"

TransferMatrix::TransferMatrix(AcceleratorModel* aModel, double refMomentum, bool isRadiation)
	: theModel(aModel), p0(refMomentum), radiation(isRadiation) {}

void TransferMatrix::FindTM(RealMatrix& M, PSvector& orbit, int ncpt)
{
	const double dscale = 1.0e-6;
	ParticleBunch particle(p0,1.0);

	for(int n=0; n<6; n++)
	{
		Particle p = orbit;
		p[n] += dscale;
		particle.push_back(p);
		p[n] -= 2.*dscale;
		particle.push_back(p);
	}

	ParticleTracker tracker(theModel->GetRing(ncpt),&particle,false);
	tracker.UseFullAcceleration(false);
	tracker.UseExactChromaticity(false);

	if(radiation) {
		SynchRadParticleProcess* srproc = new SynchRadParticleProcess(1,50); //Must split dipole with radiation A.Wolski 1/10/01
		srproc->AdjustBunchReferenceEnergy(false);
		tracker.AddProcess(srproc);
	}

	tracker.Run();

	ParticleBunch::const_iterator p = tracker.GetTrackedBunch().begin();
	ParticleBunch::const_iterator q = p;
	q++;

	for(n=0; n<6; p++,q++,n++)
	{
		for(int m=0; m<6; m++)
			M(m,n) = ((*p)[m] - (*q)[m]) / (2.*dscale);
		p++;
		q++;
	}
}

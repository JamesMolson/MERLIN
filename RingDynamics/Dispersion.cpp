#include "BeamDynamics/ParticleTracking/ParticleTracker.h"
#include "BeamDynamics/ParticleTracking/SynchRadParticleProcess.h"
#include "RingDynamics/ClosedOrbit.h"
#include "RingDynamics/Dispersion.h"
#include "NumericalUtils/utils.h"

namespace {

	using namespace std;

};


Dispersion::Dispersion(AcceleratorModel* aModel, double refMomentum)
: theModel(aModel), p0(refMomentum) {}

void Dispersion::FindDispersion(int n)
{
	double dscale = 1e-6;

	ClosedOrbit co(theModel, p0, true, false);

	PSvector p(0);
	p.dp() = -dscale;
	co.FindClosedOrbit(p, n);

	PSvector q(0);
	q.dp() = dscale;
	co.FindClosedOrbit(q, n);

	Dx  = (q.x() - p.x())/2/dscale;
	Dxp = (q.xp() - p.xp())/2/dscale;
	Dy  = (q.y() - p.y())/2/dscale;
	Dyp = (q.yp() - p.yp())/2/dscale;
}

void Dispersion::FindRMSDispersion(ofstream* file)
{
	double dscale = 1e-6;

	ClosedOrbit co(theModel, p0, true, false);

	PSvector p(0);
	p.dp() = -dscale;
	co.FindClosedOrbit(p);

	PSvector q(0);
	q.dp() = dscale;
	co.FindClosedOrbit(q);

	ParticleBunch* particle = new ParticleBunch(p0, 1.0);
	particle->push_back(p);
	particle->push_back(q);

	ParticleTracker tracker(theModel->GetBeamline(),particle);
	tracker.UseFullAcceleration(false);

	double len = 0.0;
	double dl = 0.0;
	double prev[2];
	prev[0] = prev[1] = 0;
	double pres[2];
	double rmsD[2];
	rmsD[0] = rmsD[1] = 0;

	bool loop = true;
	tracker.InitStepper();

	do {
		if(file) 
			*file<<std::setw(14)<<len;

		dl = tracker.GetCurrentComponent().GetLength();
		loop = tracker.StepComponent();

		// This is a little clumsy, but is a direct
		// result of not having random access
		// for std::list!
		ParticleBunch::const_iterator ip = tracker.GetTrackedBunch().begin();
		const Particle& p0 = *ip++;
		const Particle& p1 = *ip;

		for(int m=0; m<2; m++)
		{
			pres[m] = (p1[2*m] - p0[2*m])/2/dscale;
			rmsD[m] += dl * (pres[m]*pres[m] + prev[m]*prev[m]) / 2;
			prev[m] = pres[m];
			if(file) 
				*file<<std::setw(14)<<pres[m];
		}

		if(file)
			*file<<endl;

		len += dl;

	} while(loop);

	DxRMS = sqrt(rmsD[0] / len);
	DyRMS = sqrt(rmsD[1] / len);
}

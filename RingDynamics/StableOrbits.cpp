#include "BeamDynamics/ProcessStepManager.h"
#include "BeamDynamics/ParticleTracking/ParticleTransportProcess.h"
#include "RingDynamics/StableOrbits.h"
#include "RingDynamics/DoTrack.h"

using namespace std;

StableOrbits::StableOrbits(AcceleratorModel* aModel) : theModel(aModel) {}

void StableOrbits::SelectStable(ParticleBunch* aBunch, int nturns, double limit)
{
	using RingDynamicsImpl::DoTrack;

	ParticleBunch* trackingBunch = new ParticleBunch(*aBunch);
	ProcessStepManager myPSM;
	ParticleTransportProcess* transport = new ParticleTransportProcess();
	transport->UseFullAcceleration(false);
	myPSM.AddProcess(transport);
	myPSM.Initialise(*trackingBunch);

	char cr = char(13);

	for(int turn_count=1; turn_count<=nturns; turn_count++)
	{
		cout<<"Tracking turn "<<turn_count<<": ";
		cout<<trackingBunch->size()<<" particles remaining.    "<<cr;
		// ANSI C++ forbids non-const references to temporaries -NJW
		//(*theModel).GetBeamline().Track(DoTrack(myPSM,*trackingBunch));
		DoTrack dotrack(myPSM,*trackingBunch);
		(*theModel).GetBeamline().Track(dotrack);
		
		ParticleBunch::iterator p = trackingBunch->begin();
		ParticleBunch::iterator q = aBunch->begin();

		for(;p!=trackingBunch->end();p++,q++)
		{
			if(abs(p->x())>limit  || abs(p->y())>limit)
			{
				p = trackingBunch->erase(p);
				q = aBunch->erase(q);
			}
		}
	}

	cout<<endl;
	delete trackingBunch;
}

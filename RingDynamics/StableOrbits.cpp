#include <fstream>

#include "BeamDynamics/ProcessStepManager.h"
#include "BeamDynamics/ParticleTracking/ParticleTransportProcess.h"
#include "BeamDynamics/ParticleTracking/CollimateParticleProcess.h"
#include "RingDynamics/StableOrbits.h"
#include "RingDynamics/DoTrack.h"

using namespace std;

StableOrbits::StableOrbits(AcceleratorModel* aModel) : theModel(aModel) {}

void StableOrbits::SelectStable(ParticleBunch* aBunch, int nturns, list<size_t>* index)
{
	using RingDynamicsImpl::DoTrack;

	ProcessStepManager myPSM;
	ParticleTransportProcess* transport = new ParticleTransportProcess();
	transport->UseFullAcceleration(false);
	myPSM.AddProcess(transport);
	
	ofstream collimlog("DataFiles/CollimationLog.dat");
	CollimateParticleProcess* collimate = new CollimateParticleProcess(1,COLL_AT_CENTER,&collimlog);
	collimate->IndexParticles(*index);
	myPSM.AddProcess(collimate);

	ParticleBunch trackingBunch(*aBunch);
	myPSM.Initialise(trackingBunch);

	for(int turn_count=1; turn_count<=nturns; turn_count++)
	{
		cout<<"Tracking turn "<<turn_count<<": ";
		cout<<trackingBunch.size()<<" particles remaining.    "<<char(13);
		// ANSI C++ forbids non-const references to temporaries -NJW
		//(*theModel).GetBeamline().Track(DoTrack(myPSM,*trackingBunch));
		DoTrack dotrack(myPSM,trackingBunch);
		(*theModel).GetBeamline().Track(dotrack);
	}

	cout<<endl;
}

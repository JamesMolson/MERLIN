#include "AcceleratorModel/AcceleratorModel.h"
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"

class StableOrbits
{
public:
	StableOrbits(AcceleratorModel* aModel);
	void SelectStable(ParticleBunch* aBunch, int nturns, list<size_t>* index);

private:
	AcceleratorModel* theModel;
};


#include "AcceleratorModel/AcceleratorModel.h"
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"

class StableOrbits
{
public:
	StableOrbits(AcceleratorModel* aModel);
	void SelectStable(ParticleBunch* aBunch, int nturns, double limit =1.0);

private:
	AcceleratorModel* theModel;
};


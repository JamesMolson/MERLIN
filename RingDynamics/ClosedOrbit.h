#include "AcceleratorModel/AcceleratorModel.h"
#include "BeamModel/PSTypes.h"

class ClosedOrbit
{
public:
	ClosedOrbit(AcceleratorModel* aModel, double refMomentum, bool isTransverseOnly = false, bool isRadiation = true);
	
	void FindClosedOrbit(PSvector& p, int ncpt = 0);
	void FindRMSOrbit(PSvector& p);
	
	bool transverseOnly;
	bool radiation;
	bool useFullAcc; // default false

	// The following member variables
	// are used for diagnostics purposes

	// The final achieved figure of merit
	// for the iteration
	double w;

	// The number of iterations
	int iter;

private:
	AcceleratorModel* theModel;
	double p0;
};

#include "AcceleratorModel/AcceleratorModel.h"
#include "BeamModel/PSTypes.h"

class BetatronTunes
{
public:
	BetatronTunes(AcceleratorModel* aModel, double refMomentum);
	void FindTunes(PSvector& aPSvector, int nturns = 256);
	double Qx, Qy;

private:
	AcceleratorModel* theModel;
	double p0;
	double FindTune(vector<double>& data);
	void FFT(vector<double>& data);
};


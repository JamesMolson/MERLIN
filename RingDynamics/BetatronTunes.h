#include "AcceleratorModel/AcceleratorModel.h"
#include "BeamModel/PSTypes.h"

class BetatronTunes
{
public:
	BetatronTunes(AcceleratorModel* aModel, double refMomentum);
	void FindTunes(PSvector& aPSvector, int nturns = 256, bool diffusion = true);
	double Qx, Qy, dQx, dQy;

private:
	AcceleratorModel* theModel;
	double p0;
	double FindTune(vector<double>& data);
	void FFT(vector<double>& data);
	double amp(double a, double b, double c);
};


#include "AcceleratorModel/AcceleratorModel.h"

class TwissParameters
{
public:

	struct TwissSet
	{
		double beta;
		double alpha;
		double gamma;
	};

	TwissParameters(AcceleratorModel* aModel, double refMomentum);
	void FindTwiss(int ncpt=0);
	TwissSet TwissX;
	double mux;
	TwissSet TwissY;
	double muy;

private:
	AcceleratorModel* theModel;
	double p0;
};

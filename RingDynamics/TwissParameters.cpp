#include "RingDynamics/TwissParameters.h"
#include "RingDynamics/ClosedOrbit.h"
#include "RingDynamics/TransferMatrix.h"

using namespace std;
using namespace TLAS;

TwissParameters::TwissParameters(AcceleratorModel* aModel, double refMomentum)
	: theModel(aModel), p0(refMomentum) {}

void TwissParameters::FindTwiss(int ncpt)
{
	RealMatrix M(6);

	ClosedOrbit theClosedOrbit(theModel, p0, true, false);
	PSvector p(0);
	theClosedOrbit.FindClosedOrbit(p, ncpt);

	TransferMatrix TM(theModel, p0, false);
	TM.FindTM(M, p, ncpt);

	double cosmux = (M(0,0) + M(1,1))/2.;
	double sinmux = sqrt(1. - cosmux * cosmux);
	TwissX.beta  = M(0,1) / sinmux;
	TwissX.alpha = (M(0,0) - M(1,1))/2./sinmux;
	TwissX.gamma = -M(1,0) / sinmux;

	double cosmuy = (M(2,2) + M(3,3))/2.;
	double sinmuy = sqrt(1. - cosmuy * cosmuy);
	TwissY.beta  = M(2,3) / sinmuy;
	TwissY.alpha = (M(2,2) - M(3,3))/2./sinmuy;
	TwissY.gamma = -M(3,2) / sinmuy;
}


#include <fstream>
#include "AcceleratorModel/AcceleratorModel.h"

class Dispersion
{
public:
	Dispersion(AcceleratorModel* aModel, double refMomentum);
	void FindDispersion(int n=0);
	void FindRMSDispersion(ofstream* file=0);
	double Dx, Dxp, Dy, Dyp;
	double DxRMS, DyRMS;

private:
	AcceleratorModel* theModel;
	double p0;
};

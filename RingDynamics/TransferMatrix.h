#include "AcceleratorModel/AcceleratorModel.h"
#include "BeamModel/PSTypes.h"
#include "TLAS/TLAS.h"

using namespace TLAS;

class TransferMatrix
{
public:
	TransferMatrix(AcceleratorModel* aModel, double refMomentum, bool isRadiation = true);
	void FindTM(RealMatrix& M, PSvector& orbit, int ncpt=0);
	bool radiation;

private:
	AcceleratorModel* theModel;
	double p0;
};

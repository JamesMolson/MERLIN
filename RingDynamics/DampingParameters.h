#include "AcceleratorModel/AcceleratorModel.h"
#include "AcceleratorModel/StdComponent/SectorBend.h"
#include "TLAS/LinearAlgebra.h"

class DampingParameters 
{
public:
	DampingParameters(AcceleratorModel* aModel, double refMomentum);
	void FindEnergyLoss(double& U0);
	void FindDampingConstants();
	double Tune[3];
	vector<double> dampingConstant;

private:
	AcceleratorModel* theModel;
	double p0;
};

class EquilibriumDistribution 
{
public:
	EquilibriumDistribution(AcceleratorModel* aModel, double refMomentum, vector<double>& dampingConstant);
	void FindA2();
	void FindMoment(int i, int j, double& moment, int ncpt=0);
	double A2[3];

private:
	AcceleratorModel* theModel;
	double p0;
	vector<double>* dampingConstant;
	double IntegralEk5(ComplexVector& Ek, SectorBend* sb);
};
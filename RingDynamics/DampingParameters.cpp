#include "NumericalUtils/PhysicalConstants.h"
#include "NumericalUtils/PhysicalUnits.h"
#include "BeamDynamics/ParticleTracking/ParticleTracker.h"
#include "BeamDynamics/ParticleTracking/SynchRadParticleProcess.h"
#include "RingDynamics/DoTrack.h"
#include "RingDynamics/ClosedOrbit.h"
#include "RingDynamics/TransferMatrix.h"
#include "RingDynamics/DampingParameters.h"

using namespace std;
using namespace PhysicalConstants;
using namespace PhysicalUnits;

DampingParameters::DampingParameters(AcceleratorModel* aModel, double refMomentum)
: theModel(aModel), p0(refMomentum) {}

void DampingParameters::FindEnergyLoss(double& U0)
{
	ParticleTracker tracker(theModel->GetRing(),PSvector(0),p0);
	tracker.UseFullAcceleration(false);
	SynchRadParticleProcess* srp = new SynchRadParticleProcess(0);
	srp->AdjustBunchReferenceEnergy(false);
	tracker.AddProcess(srp);
	tracker.Run();	
	U0 = -p0*tracker.GetTrackedBunch().FirstParticle().dp();
}

void DampingParameters::FindDampingConstants()
{
	PSvector p(0);
	ClosedOrbit CO(theModel, p0);
	CO.FindClosedOrbit(p);

	RealMatrix M(6);
	TransferMatrix TM(theModel, p0);
	TM.FindTM(M,p);

	ComplexVector eigenvalues(3);
	ComplexMatrix eigenvectors(6,3);
	EigenSystem(M,eigenvalues,eigenvectors);

	dampingConstant.reserve(3);
	for(int m=0; m<3; m++)
	{
		Tune[m] = arg(eigenvalues[m])/twoPi;
		dampingConstant.push_back(-log(abs(eigenvalues[m])));
	}
}


// WakeFieldProcess.h
//
//

#ifndef _h_WakeFieldProcess
#define _h_WakeFieldProcess

#include "BeamDynamics/ParticleTracking/ParticleBunchProcess.h"
#include "Utility/StringPattern.h"

#include <vector>

class WakePotentials;
class Interpolation;

class WakeFieldProcess : public ParticleBunchProcess 
{
public:
	
	WakeFieldProcess (int prio, size_t nb =100, double ns = 3.0);
	~WakeFieldProcess();
	
	virtual void SetCurrentComponent (AcceleratorComponent& component);
	virtual void DoProcess (double ds);
	virtual double GetMaxAllowedStepSize () const;
	
	void IncludeTransverseWake(bool flg) { inc_tw = flg; }

private:
	
	size_t nbins;
	double nsig;
	bool inc_tw;

	void Init();
	size_t CalculateQdist();
	void CalculateWakeL();
	void CalculateWakeT();
	
	WakePotentials* currentWake;

	std::vector<ParticleBunch::iterator> bunchSlices;
	std::vector<double> Qd;
	std::vector<double> wake_z;
	std::vector<double> wake_x;
	std::vector<double> wake_y;

	double zmin,zmax,dz;
	
	double s;
	bool recalc;
};


#endif

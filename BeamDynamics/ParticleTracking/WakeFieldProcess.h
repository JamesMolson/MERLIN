// WakeFieldProcess.h
//
// Modified by A.Wolski 12/2/2003
// to include the derivative of the charge distribution
// for handling CSR wake fields.

#ifndef _h_WakeFieldProcess
#define _h_WakeFieldProcess

#include "BeamDynamics/ParticleTracking/ParticleBunchProcess.h"
#include "utility/StringPattern.h"

#include <vector>

class WakePotentials;

class WakeFieldProcess : public ParticleBunchProcess 
{
public:
	
	enum ImpulseLocation {atCentre,atExit};

	WakeFieldProcess (int prio, size_t nb =100, double ns = 3.0);
	~WakeFieldProcess();
	
	virtual void InitialiseProcess (Bunch& bunch);
	virtual void SetCurrentComponent (AcceleratorComponent& component);
	virtual void DoProcess (double ds);
	virtual double GetMaxAllowedStepSize () const;
	
	void ApplyImpulseAt(ImpulseLocation loc) { imploc=loc; }

	void IncludeTransverseWake(bool flg) { inc_tw = flg; }

	void DumpSliceCentroids(ostream&) const;

	void SetFilter(int n, int m, int d);

private:

	void ApplyWakefield(double ds);

	ImpulseLocation imploc;
	double current_s;
	double impulse_s;
	double clen;

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
	std::vector<double> Qdp;
	std::vector<double>* filter;
	std::vector<double> wake_z;
	std::vector<double> wake_x;
	std::vector<double> wake_y;

	double zmin,zmax,dz;
	
	bool recalc;
};

void savgol(vector<double>& c, int nl, int nr, int ld, int m);

#endif

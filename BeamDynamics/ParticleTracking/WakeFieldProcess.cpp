#include "BeamDynamics/ParticleTracking/WakeFieldProcess.h"
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"
#include "BeamDynamics/ParticleTracking/ParticleBunchUtilities.h"

#include "AcceleratorModel/StdComponent/SWRFStructure.h"
#include "AcceleratorModel/StdComponent/TWRFStructure.h"
#include "AcceleratorModel/StdComponent/SectorBend.h"
#include "NumericalUtils/PhysicalConstants.h"
#include "NumericalUtils/PhysicalUnits.h"
#include "NumericalUtils/utils.h"
#include "IO/MerlinIO.h"

#include <stdexcept>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <fstream>

namespace {

#define COUT(x) cout<<std::setw(12)<<scientific<<std::setprecision(4)<<(x);

	using namespace std;
	using namespace PhysicalConstants;
	using namespace PhysicalUnits;

	Point2D GetSliceCentroid(ParticleBunch::const_iterator first, 
								ParticleBunch::const_iterator last)
	{
		Point2D c(0,0);
		double n=0;
		while(first!=last) {
			c.x += first->x();
			c.y += first->y();
			first++;
			n++;
		}
		return n>1 ? c/n : c;
	}

	PSvector GetSliceCentroid6D(ParticleBunch::const_iterator first, 
								ParticleBunch::const_iterator last)
	{
		PSvector c(0);
		double n=0;
		while(first!=last) {
			c += *first;
			first++;
			n++;
		}
		if(n>1)
			c/=n;

		return c;
	}

};



WakeFieldProcess::WakeFieldProcess (int prio, size_t nb, double ns)
: ParticleBunchProcess("WAKEFIELD",prio),nbins(nb),nsig(ns),currentWake(0),s(0),
	wake_x(0),wake_y(0),wake_z(0),Qd(),recalc(true),inc_tw(true)
{}

WakeFieldProcess::~WakeFieldProcess()
{}

size_t WakeFieldProcess::CalculateQdist()
{
	pair<double,double> v = currentBunch->GetMoments(ps_CT);
	double z0 = v.first;
	double sigz = v.second;

	// calculate binning ranges
	zmin = -nsig*sigz+z0;
	zmax =  nsig*sigz+z0;
	dz = (zmax-zmin)/nbins;

	bunchSlices.clear();
	Qd.clear();
	size_t lost = ParticleBinList(*currentBunch,zmin,zmax,nbins,bunchSlices,Qd);
	
#ifndef NDEBUG
	ofstream os("qdist.dat");
	os<<zmin<<' '<<zmax<<' '<<dz<<endl;
	copy(Qd.begin(),Qd.end(),ostream_iterator<double>(os,"\n"));
#endif

	return lost;
}


void WakeFieldProcess::SetCurrentComponent (AcceleratorComponent& component)
{
	TWRFStructure* cavity = dynamic_cast<TWRFStructure*>(&component);
	WakePotentials* wake = cavity!=0 ? cavity->GetWakePotentials() : 0;
	
	if(currentBunch!=0 && wake!=0) {
		s = component.GetLength();
		active = true;
		if(recalc || wake!=currentWake) {
			currentWake = wake;
			Init();
		}
	}
	else {
		active = false;

		// check if we have a sector bend. If so, then
		// the bunch length will change and we need to
		// rebin
		if(dynamic_cast<SectorBend*>(&component))
			recalc = true;
	}
}


void WakeFieldProcess::DoProcess (double ds)
{
	// here we apply the wake field for 
	// the step ds
	size_t n=0;
	double p0 = currentBunch->GetReferenceMomentum();

	// If the bunch length or binning has been changed,
	// we must recalculate the wakes
	if(recalc)
		Init();

	// We always need to recalculate the transverse wake
	if(inc_tw)
		CalculateWakeT();
	
	// Now iterate over the bunch slices,
	// calculating the wakefield kicks using
	// linear interpolation between the values
	// at the slice boundaries

	double bload=0;

#define WAKE_GRADIENT(wake) (wake).empty() ? 0 : ((wake[nslice+1]-wake[nslice])/dz);

	double z=zmin;

	for(size_t nslice = 0; nslice<nbins; nslice++) {

		double gz = WAKE_GRADIENT(wake_z);
		double gx = WAKE_GRADIENT(wake_x);
		double gy = WAKE_GRADIENT(wake_y);


//		cout<<nslice<<" ("<<flush<<distance(bunchSlices[nslice],bunchSlices[nslice+1])<<") ";

		for(ParticleBunch::iterator p=bunchSlices[nslice]; p!=bunchSlices[nslice+1]; p++) {
			double zz = p->ct()-z;
			double ddp = -ds*(wake_z[nslice]+gz*zz)/p0;
			p->dp() += ddp;
			bload += ddp;
			
			double dxp =  inc_tw? ds*(wake_x[nslice]+gx*zz)/p0 : 0;
			double dyp =  inc_tw? ds*(wake_y[nslice]+gy*zz)/p0 : 0;
			
			p->xp() = (p->xp()+dxp)/(1+ddp);
			p->yp() = (p->yp()+dyp)/(1+ddp);
		}
		z+=dz;
	}
	currentBunch->AdjustRefMomentum(bload/currentBunch->size());
//	currentBunch->AdjustRefMomentumToMean();
}

double WakeFieldProcess::GetMaxAllowedStepSize () const
{
	return s;
}

void WakeFieldProcess::Init()
{
	double Qt  = currentBunch->GetTotalCharge();
	size_t nloss = CalculateQdist();
	if(nloss!=0) {
		// Even though we have truncated particles, we still keep the
		// the bunch charge constant
		currentBunch->SetMacroParticleCharge(Qt/(currentBunch->size()));
//		MerlinIO::warning()<<"WakefieldProcess: "<<nloss<<" particles truncated"<<endl;
	}

	// Calculate the long. bunch wake.
	CalculateWakeL();
	recalc=false;
}



void WakeFieldProcess::CalculateWakeL()
{
	wake_z = vector<double>(bunchSlices.size(),0.0);
	double a0 = dz*(currentBunch->GetTotalCharge())*ElectronCharge*Volt;
	
	// Estimate the bunch wake at the slice boundaries by
	// convolving the point-like wake over the current bunch
	// charge distribution Qd.
	//
	// Note that the distribution Qd is estimated at the
	// centre of each slice, not the slice boundary.

	for(int i=0; i<bunchSlices.size(); i++) {
		for(int j=i; j<bunchSlices.size(); j++) {
			wake_z[i] += Qd[j]*(currentWake->Wlong((j-i+0.5)*dz));
		}
		wake_z[i]*=a0;
	}

#ifndef NDEBUG
	ofstream os("bunchWake.dat");
	os<<zmin<<' '<<zmax<<' '<<dz<<endl;
	copy(wake_z.begin(),wake_z.end(),ostream_iterator<double>(os,"\n"));
#endif

}

void WakeFieldProcess::CalculateWakeT()
{
	// This routine is rather cpu intensive.
	// First, calculate the transverse centroid of
	// each bunch slice by taking the mean of the
	// particle positions

	vector<Point2D> xyc;
	xyc.reserve(nbins);
	size_t i;
	for(i=0; i<nbins; i++)
		xyc.push_back(GetSliceCentroid(bunchSlices[i],bunchSlices[i+1]));

	// Now estimate the transverse bunch wake at the slice
	// boundaries in the same way we did for the longitudinal wake.

	double a0 = dz*(currentBunch->GetTotalCharge())*ElectronCharge*Volt;
	wake_x = vector<double>(bunchSlices.size(),0.0);
	wake_y = vector<double>(bunchSlices.size(),0.0);
	for(i=0; i<bunchSlices.size(); i++) {
		for(int j=i; j<bunchSlices.size(); j++) {
			double wxy = Qd[j]*(currentWake->Wtrans((j-i+0.5)*dz));
			wake_x[i] += wxy*xyc[j].x;
			wake_y[i] += wxy*xyc[j].y;
		}
		wake_x[i]*=a0;
		wake_y[i]*=a0;
	}
}

void WakeFieldProcess::DumpSliceCentroids(ostream& os) const
{
	for(size_t i=0; i<nbins; i++) {
		os<<std::setw(4)<<i;
		os<<GetSliceCentroid6D(bunchSlices[i],bunchSlices[i+1]);
	}
}
		

void WakeFieldProcess::InitialiseProcess (Bunch& bunch)
{
	ParticleBunchProcess::InitialiseProcess(bunch);
	currentWake = 0;
	recalc = true;
}


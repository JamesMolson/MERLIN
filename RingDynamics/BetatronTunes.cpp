#include "BeamDynamics/ParticleTracking/ParticleTracker.h"
#include "BetatronTunes.h"
#include <algorithm>

using namespace std;

BetatronTunes::BetatronTunes(AcceleratorModel* aModel, double refMomentum)
	: theModel(aModel), p0(refMomentum) {}

void BetatronTunes::FindTunes(PSvector& aPSvector, int ntrack)
{
//	const int ntrack = 256;
	vector<double> xData;
	xData.reserve(ntrack * 2);
	xData.push_back( aPSvector.x() );
	xData.push_back( aPSvector.xp() );

	vector<double> yData;
	yData.reserve(ntrack * 2);
	yData.push_back( aPSvector.y() );
	yData.push_back( aPSvector.yp() );

	ParticleTracker tracker(theModel->GetRing(),aPSvector,p0);

	for(int nturn=0; nturn<ntrack-1; nturn++)
	{
		tracker.Run(false);
		Particle& p1 = tracker.GetTrackedBunch().FirstParticle();

		if( _isnan(p1.x()) || _isnan(p1.y()) ) break;

		xData.push_back( p1.x() );
		xData.push_back( p1.xp() );
		yData.push_back( p1.y() );
		yData.push_back( p1.yp() );
	}

	Qx = (xData.size()==2*ntrack) ? FindTune(xData) : 0;
	Qy = (yData.size()==2*ntrack) ? FindTune(yData) : 0;
}

double BetatronTunes::FindTune(vector<double>& data)
{
	vector<double> spectrum;
	spectrum.reserve(data.size()/2);

	FFT(data);
	double peak_height = 0.0;
	int peak_position = 0;

	for(int i=0; i<data.size()/2; i+=2)
	{
		double amp = sqrt(data[i]*data[i] + data[i+1]*data[i+1]);
		spectrum.push_back(amp);
		if(amp > peak_height)
		{
			peak_height = amp;
			peak_position = i/2;
		}
	}

	double left_peak = spectrum[peak_position-1];
	double right_peak = spectrum[peak_position+1];

	double sign = 1.0;
	if(left_peak > right_peak)
		sign = -1.0;

	double k = left_peak*right_peak/pow(spectrum[peak_position],2);
	double peak_correction = sign*sqrt(k/(1+k));

	double tune = 2*(peak_position + peak_correction)/data.size();
	if(_isnan(tune))
		tune = 0.0;

	return tune;
}

void BetatronTunes::FFT(vector<double>& data)
{
	int n = data.size();
	int j = 1;
	for(int i=1; i<n; i+=2)
	{
		if(j>i)
		{
			swap(data[j-1],data[i-1]);
			swap(data[j],data[i]);
		}

		int m = n >> 1;
		while(m >= 2 && j > m)
		{
			j -= m;
			m >>= 1;
		}
		j += m;
	}

	int mmax = 2;
	while(n > mmax)
	{
		int istep = mmax << 1;
		double theta = 6.28318530717959 / mmax;
		double wtemp = sin(theta/2.);
		double wpr = -2.0 * wtemp * wtemp;
		double wpi = sin(theta);
		double wr = 1.;
		double wi = 0.;
		for(int m=1; m<mmax; m+=2)
		{
			for(int i=m; i<=n; i+=istep)
			{
				j = i + mmax;
				double tempr = wr * data[j-1] - wi * data[j];
				double tempi = wr * data[j] + wi * data[j-1];
				data[j-1] = data[i-1] - tempr;
				data[j] = data[i] - tempi;
				data[i-1] += tempr;
				data[i] += tempi;
			}
			wr = (wtemp=wr)*wpr - wi*wpi + wr;
			wi = wi*wpr + wtemp*wpi + wi;
		}
		mmax = istep;
	}

}

/*
* Merlin C++ Class Library for Charged Particle Accelerator Simulations
* 
* Class library version 2.0 (2000)
* 
* file Merlin/BeamDynamics/SliceMPTracking/SMPBunch.h
* last modified 10/01/03
*
* This file is derived from software bearing the following
* restrictions:
*
* MERLIN C++ class library for 
* Charge Particle Accelerator Simulations
*
* Copyright (c) 2003 by The Merlin Collaboration.  
* ALL RIGHTS RESERVED. 
*
* Permission to use, copy, modify, distribute and sell this
* software and its documentation for any purpose is hereby
* granted without fee, provided that the above copyright notice
* appear in all copies and that both that copyright notice and
* this permission notice appear in supporting documentation.
* No representations about the suitability of this software for
* any purpose is made. It is provided "as is" without express
* or implied warranty.
*/

#include "BeamDynamics/SMPTracking/SMPBunch.h"
#include <fstream>

namespace SMPTracking {
	
	using namespace std;
	
	SMPBunch::SMPBunch (double p, double q) 
		: Bunch(p,q),Qt(0)
	{}
	
	SMPBunch::SMPBunch (const std::string& fname) 
		: Bunch(1,1),Qt(0)
	{
		ifstream ifs(fname.c_str());
		if(!ifs) {
			cerr<<"SMPBunch file not found: "<<fname<<endl;
			abort();
		}
		
		double p0,ct0,nmp;
		
		if(ifs>>p0>>ct0>>nmp) {
			SetReferenceMomentum(p0);
			SetReferenceTime(ct0);
			slices.reserve(nmp);
		}
		else {
			cerr<<"Bad SMPBunch file format: "<<fname<<endl;
			abort();
		}
		while(ifs) {
			SliceMacroParticle p;
			p.Read(ifs);
			if(ifs) {
				slices.push_back(p);
				Qt+=p.Q();
				nmp--;
			}
		}
		
		if(nmp!=0) {
			cerr<<"Bad SMPBunch file format: "<<fname<<endl;
			abort();
		}
		
		sort(begin(),end());
		SetChargeSign(Qt);
	};
	
	SMPBunch::~SMPBunch ()
	{
		// nothing to do
	}
	
	double SMPBunch::GetTotalCharge () const
	{
		return Qt;
	}
	
	PSmoments& SMPBunch::GetMoments (PSmoments& sigma) const
	{
		sigma.zero();
		int i,j;
		for(const_iterator p=begin(); p!=end(); p++) {
			const SliceMacroParticle& x = (*p);
			double w = x.Q()/Qt;
			for(i=0; i<6; i++) {
				sigma[i]+=w*x[i];  // centroid
				for(j=0; j<=i; j++) //2nd-order moments
					sigma(i,j)+= w*(x[i]*x[j]+x(i,j));
			}
		}
		for(i=0; i<6; i++)
			for(j=0; j<=i; j++)
				sigma(i,j)-=sigma[i]*sigma[j];
			
			return sigma;
	}
	
	PSmoments2D& SMPBunch::GetProjectedMoments (PScoord u, PScoord v, PSmoments2D& sigma) const
	{
		for(const_iterator p=begin(); p!=end(); p++) {
			const SliceMacroParticle& x = (*p);
			double w = x.Q()/Qt;
			
			sigma[0]+=w*x[u];
			sigma[1]+=w*x[v];
			
			sigma(0,0)+=w*(x(u,u)+x[u]*x[u]);
			sigma(0,1)+=w*(x(u,v)+x[u]*x[v]);
			sigma(1,1)+=w*(x(v,v)+x[v]*x[v]);
		}
		sigma(0,0)-=sigma[0]*sigma[0];
		sigma(0,1)-=sigma[0]*sigma[1];
		sigma(1,1)-=sigma[1]*sigma[1];
		
		return sigma;
		
	}
	
	PSvector& SMPBunch::GetCentroid (PSvector& x) const
	{
		x.zero();
		for(const_iterator p=begin(); p!=end(); p++)
			x+=p->GetChargeWeightedCentroid();
		x/=Qt;
		return x;
	}
	
	Point2D SMPBunch::GetProjectedCentroid (PScoord u, PScoord v) const
	{
		Point2D x0(0,0);
		for(const_iterator p=begin(); p!=end(); p++)
			x0+=p->GetChargeWeightedCentroid(u,v);
		x0/=Qt;
		return x0;
	}
	
	double SMPBunch::AdjustRefMomentumToMean ()
	{
		double dp0=0;
		for(const_iterator cp=begin(); cp!=end(); cp++)
			dp0+=(cp->dp())*(cp->Q());
		double ddp=dp0/Qt+1.0;
		for(iterator p=begin(); p!=end(); p++)
			p->dp()/=ddp;
		SetReferenceMomentum(GetReferenceMomentum()*ddp);
		return GetReferenceMomentum();
	}
	
	double SMPBunch::AdjustRefTimeToMean ()
	{
		double ct=0;
		for(const_iterator p=begin(); p!=end(); p++)
			ct+=(p->ct())*(p->Q());
		IncrReferenceTime(ct/Qt);
		return GetReferenceTime();
	}
	
	void SMPBunch::Output (std::ostream& os) const
	{
		static char delim[]=" ";
		
		os<<GetReferenceMomentum()<<delim;
		os<<GetReferenceTime()<<delim;
		os<<slices.size()<<endl;
		copy(begin(),end(),ostream_iterator<SliceMacroParticle>(os,""));
	}
	
	Histogram& SMPBunch::ProjectDistribution (PScoord axis, Histogram& hist) const
	{
		// TO DO
		return hist;
	}
	
	bool SMPBunch::ApplyTransformation (const Transform3D& t)
	{
		// TO DO
		return false;
	}
	
	void SMPBunch::AddParticle(const SliceMacroParticle& p)
	{
		slices.push_back(p);
		sort(begin(),end());
		Qt+=p.Q();
	}
	
};
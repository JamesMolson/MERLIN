/*
* Merlin C++ Class Library for Charged Particle Accelerator Simulations
* 
* Class library version 2.0 (1999)
* 
* file Merlin\BeamDynamics\SMPTracking\SMPBunchConstructor.h
* last modified 14/10/02 11:01:55
*
* This file is derived from software bearing the following
* restrictions:
*
* MERLIN C++ class library for 
* Charge Particle Accelerator Simulations
* Copyright (c) 2001 by The Merlin Collaboration.
* - ALL RIGHTS RESERVED - 
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

#include "BeamDynamics/SMPTracking/SMPBunchConstructor.h"
#include "BasicTransport/NormalTransform.h"
#include "NumericalUtils/utils.h"

namespace {

	void MakeDistribution(double ns, vector<double>& d)
	{
		double dx = 2*ns/d.size();
		double x = -ns;
		for(size_t n=0; n<d.size(); n++, x+=dx)
			d[n] = NormalBin(x,x+dx);
	}

};


namespace SMPTracking {
	
	
	SMPBunchConstructor::SMPBunchConstructor (const BeamData& beam, size_t ns1, size_t nsm)
		: ns(ns1),np(nsm),beamdat(beam),nSigZ(3.0),nSigDP(3.0)
	{}
	
	SMPBunchConstructor::~SMPBunchConstructor ()
	{}
	
	Bunch* SMPBunchConstructor::ConstructBunch (int) const
	{
		SMPBunch* bunch = new SMPBunch(beamdat.p0,beamdat.charge);
		PSmoments S = BeamDataToSigmaMtrx(beamdat);
		
		// the macroparticles are constructed to represent the 
		// total charge in a bin of width 6sigma/ns
		
		double q0 = beamdat.charge;
		double qt = 0;

		vector<double> zdist(ns);
		vector<double> dpdist(np);
	
		MakeDistribution(nSigZ,zdist);
		MakeDistribution(nSigDP,dpdist);

		double dz  = 2*nSigZ*beamdat.sig_z/ns;
		double ddp = 2*nSigDP*beamdat.sig_dp/np;

		double z   =-nSigZ*beamdat.sig_z+dz/2;
		for(size_t nSlice = 0; nSlice<ns; nSlice++, z+=dz) {
			double dp = -nSigDP*beamdat.sig_dp+ddp/2.0;
			for(size_t nPart = 0; nPart<np; nPart++,dp+=ddp) {
				double q = q0*zdist[nSlice]*dpdist[nPart];
				bunch->AddParticle(SliceMacroParticle(S,z,dp,q));
				qt+=q;
			}
		}
		cout<<"total generated charge = "<<qt<<endl;

		return bunch;
	}
	
	SMPBunch* SMPBunchConstructor::ConstructSMPBunch () const
	{
		return static_cast<SMPBunch*>(ConstructBunch());
	}
	
};


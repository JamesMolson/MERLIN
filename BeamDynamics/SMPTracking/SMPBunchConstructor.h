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


#ifndef SMPBunchConstructor_h
#define SMPBunchConstructor_h 1

#include "merlin_config.h"

// BeamData
#include "BeamModel/BeamData.h"
// BunchConstructor
#include "BeamModel/BunchConstructor.h"
// SMPBunch
#include "BeamDynamics/SMPTracking/SMPBunch.h"


namespace SMPTracking {
	
	class SMPBunchConstructor : public BunchConstructor {
	public:
		
		// Constructor taking the beam definition, the number of z slices
		// (ns) and the number of SMPs per slice. Total number of SMPs
		// generated will be nsm*ns
		SMPBunchConstructor (const BeamData& beam, size_t ns, size_t nsm);
		
		~SMPBunchConstructor ();
		
		virtual Bunch* ConstructBunch (int bunchIndex =0) const;
		
		//	Returns typed particle bunch.
		SMPBunch* ConstructSMPBunch () const;
		
	private:
		
		size_t ns,np;
		BeamData beamdat;
		double nSigZ,nSigDP;
	};
};

#endif

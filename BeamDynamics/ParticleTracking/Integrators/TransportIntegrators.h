/*
* Merlin C++ Class Library for Charged Particle Accelerator Simulations
* 
* Class library version 2.0 (1999)
* 
* file Merlin\BeamDynamics\ParticleTracking\Integrators\TransportIntegrators.h
* last modified 11/12/01 15:32:02
*/

/*
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

#ifndef TransportIntegrators_h
#define TransportIntegrators_h 1

#include "merlin_config.h"

// SectorBend
#include "AcceleratorModel/StdComponent/SectorBend.h"
// RectMultipole
#include "AcceleratorModel/StdComponent/RectMultipole.h"
// Drift
#include "AcceleratorModel/StdComponent/Drift.h"
// SWRFStructure
#include "AcceleratorModel/StdComponent/SWRFStructure.h"
// ParticleBunchIntegrator
#include "BeamDynamics/ParticleTracking/ParticleBunchIntegrator.h"

namespace TRANSPORT {
	
	class DriftPI : public TParticleI<Drift> {
	public:
		virtual double TrackStep (double ds);
	};
	
	class SectorBendPI : public TParticleI<SectorBend> {
	public:
		virtual double TrackStep (double ds);
		
	protected:		
		void ApplyPoleFaceRotation (double h, double k, const SectorBend::PoleFace* pf);
	};
		
	class RectMultipolePI : public TParticleI<RectMultipole> {
	public:
		virtual double TrackStep (double ds);
	};
	
	class SWRFStructurePI : public TParticleI<SWRFStructure> {
	public:
		SWRFStructurePI(bool ufa =true) : useFullAcc(ufa) {}
		virtual double TrackStep (double ds);
	public:
		bool useFullAcc;
	};
	
	
}; // end of namespace TRANSPORT

#endif

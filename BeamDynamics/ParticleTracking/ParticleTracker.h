//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3AE807FC01EA.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleTracker.h
 * last modified 09/06/01 02:15:18 PM
 */
//## end module%3AE807FC01EA.cm

//## begin module%3AE807FC01EA.cp preserve=no
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
//## end module%3AE807FC01EA.cp

//## Module: ParticleTracker%3AE807FC01EA; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleTracker.h

#ifndef ParticleTracker_h
#define ParticleTracker_h 1

//## begin module%3AE807FC01EA.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE807FC01EA.additionalIncludes

//## begin module%3AE807FC01EA.includes preserve=yes
//## end module%3AE807FC01EA.includes

// TrackingSimulation
#include "BeamDynamics/TrackingSimulation.h"
// ParticleBunch
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"

class ParticleTransportProcess;

//## begin module%3AE807FC01EA.additionalDeclarations preserve=yes
//## end module%3AE807FC01EA.additionalDeclarations


//## Class: ParticleTracker%3AE805520064
//	A Particle Tracking simulation. ParticleTracker is a
//	TrackingSimulation whose primary Transport process is
//	particle tracking.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AE80A1E0078;StaticBunchCtor { -> }
//## Uses: <unnamed>%3AE95E7B01EA;ParticleBunch { -> }
//## Uses: <unnamed>%3AE95EB8026C;Particle { -> }

class ParticleTracker : public TrackingSimulation  //## Inherits: <unnamed>%3AE8058E012C
{
  public:
    //## Constructors (specified)
      //## Operation: ParticleTracker%3AE806C10294
      //	Constructor taking the beamline to be tracked and a
      //	pointer to the initial ParticleBunch. If bunch0=0
      //	(default) the initial beam must be specified by either a
      //	call to SetInitialBeam(), or to SetInitialBeamCtor (from
      //	TrackingSimulation).
      explicit ParticleTracker (const AcceleratorModel::Beamline& bline, ParticleBunch* bunch0 = 0, bool del = false);

      //## Operation: ParticleTracker%3AE95BD103CA
      //	Constructor used for single particle tracking. The
      //	constructor takes the beamline to be tracked, and the
      //	initial particle.
      ParticleTracker (const AcceleratorModel::Beamline& bline, const Particle& p, double Pref);

      //## Operation: ParticleTracker%3B66AB940018
      //	Constructor taking the beamline to be tracked and a
      //	pointer to the initial ParticleBunch. If bunch0=0
      //	(default) the initial beam must be specified by either a
      //	call to SetInitialBeam(), or to SetInitialBeamCtor (from
      //	TrackingSimulation).
      explicit ParticleTracker (const AcceleratorModel::RingIterator& ring, ParticleBunch* bunch0 = 0, bool del = false);

      //## Operation: ParticleTracker%3B66AB940040
      //	Constructor used for single particle tracking. The
      //	constructor takes the beamline to be tracked, and the
      //	initial particle.
      ParticleTracker (const AcceleratorModel::RingIterator& ring, const Particle& p, double Pref);


    //## Other Operations (specified)
      //## Operation: SetInitialBunch%3AE809BE0262
      //	Sets the initial ParticleBunch for future tracking
      //	operations. Use of a template memebr function
	  //	insures that the correct derivative of ParticleBunch
	  //	is constructed.
	  template<class B>
		  void SetInitialBunch (B* pbunch0, bool del = false) {
		  if(pbunch0!=0)
			  SetInitialBunchCtor(MakeBunchCtor(pbunch0,del));
	  }

	  // Overrides the current bunch constructor and
	  // tracks the supplied bunch.
	  ParticleBunch* Track(ParticleBunch*);

      //## Operation: SetInitialParticle%3AE95C37038E
      //	Sets the initial particle for single-particle tracking.
      void SetInitialParticle (const Particle& p, double Pref);

      //## Operation: GetTrackedBunch%3AE807780122
      //	Returns a reference to the current tracked bunch.
      const ParticleBunch& GetTrackedBunch () const;
      ParticleBunch& GetTrackedBunch ();

      //## Operation: LinearTrackingOnly%3AE805B80064
      //	When set to true, causes only linear tracking to be
      //	performed.
      void LinearTrackingOnly (bool flg);

      //## Operation: UseExactChromaticity%3AE805B800D2
      //	When set to true, the quadrupole map is calculated
      //	exactly for each magnet. Default is false (i.e. each
      //	quadrupole is expanded to second-order).
      void UseExactChromaticity (bool flg);

      //## Operation: UseExactSectorBend%3AE805B80104
      //	If exactSB is true, calculate the exact solution for a
      //	sector bend, rather than using the standard (small
      //	angle) transport matrix.
      void UseExactSectorBend (bool exactSB);

      //## Operation: UseFullAcceleration%3B97661F029C
      //	If fullacc==true, then the reference energy of the
      //	particle bunch is adjusted to represent the mean energy
      //	gain due to acceleration. If false, then the reference
      //	energy is unchanged, and the effects of the acceleration
      //	are only applied to the individual dp/p of the
      //	particles. Full acceleration is the default, and should
      //	be used when modelling linacs etc. fullacc == false may
      //	be beneficial when modelling storage rings.
      void UseFullAcceleration (bool fullacc);

  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::<unnamed>%3AE80566024E
      //## Role: ParticleTracker::transportProc%3AE805670276
      //## begin ParticleTracker::transportProc%3AE805670276.role preserve=no  private: ParticleTransportProcess { -> 0..1VFHgAN}
      ParticleTransportProcess* transportProc;
      //## end ParticleTracker::transportProc%3AE805670276.role

  private: //## implementation
};

// Class ParticleTracker 


//## Other Operations (inline)
//## Operation: GetTrackedBunch%3AE807780122
inline const ParticleBunch& ParticleTracker::GetTrackedBunch () const
{
  //## begin ParticleTracker::GetTrackedBunch%3AE807780122.body preserve=yes
	return static_cast<ParticleBunch&>(*bunch);
  //## end ParticleTracker::GetTrackedBunch%3AE807780122.body
}
inline ParticleBunch& ParticleTracker::GetTrackedBunch ()
{
	return static_cast<ParticleBunch&>(*bunch);
}

//## begin module%3AE807FC01EA.epilog preserve=yes
//## end module%3AE807FC01EA.epilog


#endif

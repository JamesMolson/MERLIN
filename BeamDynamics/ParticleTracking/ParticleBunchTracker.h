//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3729F8A002B2.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunchTracker.h
 * last modified 09/11/01 04:10:33 PM
 */
//## end module%3729F8A002B2.cm

//## begin module%3729F8A002B2.cp preserve=no
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
//## end module%3729F8A002B2.cp

//## Module: ParticleBunchTracker%3729F8A002B2; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleBunchTracker.h

#ifndef ParticleBunchTracker_h
#define ParticleBunchTracker_h 1

//## begin module%3729F8A002B2.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3729F8A002B2.additionalIncludes

//## begin module%3729F8A002B2.includes preserve=yes
//## end module%3729F8A002B2.includes

// ParticleBunch
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"

class ParticleBunchIntegrator;

//## begin module%3729F8A002B2.additionalDeclarations preserve=yes
//## end module%3729F8A002B2.additionalDeclarations


//## Class: ParticleBunchTracker%36EE489E0292
//	A Tracker class which tracks a ParticleBunch object.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%36EE48C300A0;ParticleBunchIntegrator { -> F}
//## Uses: <unnamed>%3AE03860017C;TWRFStructurePI { -> }
//## Uses: <unnamed>%3AE03861035C;DriftPI { -> }
//## Uses: <unnamed>%3AE0386301FE;ExactRectMultipolePI { -> }
//## Uses: <unnamed>%3AE0386403AC;MonitorPI { -> }
//## Uses: <unnamed>%3AE038660320;RectMultipolePI { -> }
//## Uses: <unnamed>%3AE038680230;SectorBendPI { -> }
//## Uses: <unnamed>%3AE0386903DE;SWRFStructurePI { -> }
//## Uses: <unnamed>%3AE81F4C01E0;ExactSectorBendPI { -> }
//## Uses: <unnamed>%3B73D7110238;ParticleMapPI { -> }

class ParticleBunchTracker : public ComponentTracker  //## Inherits: <unnamed>%36EE48AA013A
{
  public:
    //## Constructors (specified)
      //## Operation: ParticleBunchTracker%36EE50EB026F
      //	Constructor taking the bunch to track.
      ParticleBunchTracker (ParticleBunch& bunch);

      //## Operation: ParticleBunchTracker%3B9E189100C1
      //	Default constructor. Only used for prototype
      //	construction (see SetDefaultTracker).
      ParticleBunchTracker ();


    //## Other Operations (specified)
      //## Operation: GetBunch%36EE510701C5
      ParticleBunch& GetBunch ();

      //## Operation: LinearTrackingOnly%3969B65901E3
      //	When set to true, causes only linear tracking to be
      //	performed.
      void LinearTrackingOnly (bool flg);

      //## Operation: UseExactChromaticity%3969B6860292
      //	When set to true, the quadrupole map is calculated
      //	exactly for each magnet. Default is false (i.e. each
      //	quadrupole is expanded to second-order).
      void UseExactChromaticity (bool flg);

      //## Operation: UseExactSectorBend%3AE7DC030014
      //	If exactSB is true, calculate the exact solution for a
      //	sector bend, rather than using the standard (small
      //	angle) transport matrix.
      void UseExactSectorBend (bool exactSB);

      //## Operation: UseFullAcceleration%3B9764AD039E
      //	If fullacc==true, then the reference energy of the
      //	particle bunch is adjusted to represent the mean energy
      //	gain due to acceleration. If false, then the reference
      //	energy is unchanged, and the effects of the acceleration
      //	are only applied to the individual dp/p of the
      //	particles. Full acceleration is the default, and should
      //	be used when modelling linacs etc. fullacc == false may
      //	be beneficial when modelling storage rings.
      void UseFullAcceleration (bool fullacc);

      //## Operation: NewTracker%3B9E163301C4
      //	Returns a new ParticleBunchTracker object, initialised
      //	with the specified bunch.
      virtual ParticleBunchTracker* NewTracker (ParticleBunch& bunch) const;

      //## Operation: ConstructNewTracker%3B9E16950247
      //	Static function that constructs a new ParticleBunch
      //	Tracker object, initialised with the specified bunch.
      //	The ParticleBunchTracker is constructed from the current
      //	defaultTracker (static) object.
      static ParticleBunchTracker* ConstructNewTracker (ParticleBunch& bunch);

      //## Operation: SetDefaultTracker%3B9E17780080
      //	Sets the default tracker for future calls to ConstructNew
      //	Tracker().
      static void SetDefaultTracker (ParticleBunchTracker* aTracker);

  protected:

    //## Other Operations (specified)
      //## Operation: InitialiseIntegrator%3729F4B90366
      //	Initialises the integrator with the currrent beam.
      virtual void InitialiseIntegrator ();

  private:
    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::<unnamed>%36EE4F0C032F
      //## Role: ParticleBunchTracker::theBunch%36EE4F0D013B
      //## begin ParticleBunchTracker::theBunch%36EE4F0D013B.role preserve=no  private: ParticleBunch { -> 1RHAN}
      ParticleBunch* theBunch;
      //## end ParticleBunchTracker::theBunch%36EE4F0D013B.role

      //## Association: Merlin::BeamDynamics::ParticleTracking::tracker construction%3B9E14DD0276
      //## Role: ParticleBunchTracker::defaultTracker%3B9E14E000A4
      //	Prototype static member for tracker construction.
      //## begin ParticleBunchTracker::defaultTracker%3B9E14E000A4.role preserve=no  private: static ParticleBunchTracker { -> RHAN}
      static ParticleBunchTracker* defaultTracker;
      //## end ParticleBunchTracker::defaultTracker%3B9E14E000A4.role

  private: //## implementation
};

// Class ParticleBunchTracker 

//## begin module%3729F8A002B2.epilog preserve=yes
//## end module%3729F8A002B2.epilog


#endif

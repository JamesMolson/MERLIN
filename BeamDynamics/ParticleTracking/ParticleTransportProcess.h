//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3AE7DDD1006E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleTransportProcess.h
 * last modified 09/06/01 02:14:07 PM
 */
//## end module%3AE7DDD1006E.cm

//## begin module%3AE7DDD1006E.cp preserve=no
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
//## end module%3AE7DDD1006E.cp

//## Module: ParticleTransportProcess%3AE7DDD1006E; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleTransportProcess.h

#ifndef ParticleTransportProcess_h
#define ParticleTransportProcess_h 1

//## begin module%3AE7DDD1006E.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE7DDD1006E.additionalIncludes

//## begin module%3AE7DDD1006E.includes preserve=yes
//## end module%3AE7DDD1006E.includes

// ParticleBunchProcess
#include "BeamDynamics/ParticleTracking/ParticleBunchProcess.h"

class ParticleBunchTracker;

//## begin module%3AE7DDD1006E.additionalDeclarations preserve=yes
//## end module%3AE7DDD1006E.additionalDeclarations


//## Class: ParticleTransportProcess%36E926B002E0
//	Used to transport (track) particles through a section of
//	an AcceleratorComponent. A ParticleTransportProcess is
//	genally the only process which advances the independent
//	variable s.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ParticleTransportProcess : public ParticleBunchProcess  //## Inherits: <unnamed>%3AE7D89D00A0
{
  public:
    //## Constructors (specified)
      //## Operation: ParticleTransportProcess%37C3E6170028
      ParticleTransportProcess ();

    //## Destructor (specified)
      //## Operation: ~ParticleTransportProcess%37C3E62A017C
      ~ParticleTransportProcess ();


    //## Other Operations (specified)
      //## Operation: InitialiseProcess%37C3E45E010E
      //	Initialise this process with the specified Bunch.
      virtual void InitialiseProcess (Bunch& bunch);

      //## Operation: SetCurrentComponent%37C3E45E017C
      //	Sets the current accelerator component. This function
      //	should be called just before tracking of the component
      //	begins. Concrete processes should override this function
      //	to perform component and preocess dependent
      //	initialisation.
      virtual void SetCurrentComponent (AcceleratorComponent& component);

      //## Operation: DoProcess%37C3E45E01AE
      //	Preform the process for the specified step ds.
      virtual void DoProcess (double ds);

      //## Operation: GetMaxAllowedStepSize%37C3E45E021C
      //	Returns the current maximum step length for this process.
      virtual double GetMaxAllowedStepSize () const;

      //## Operation: LinearTrackingOnly%3969BD8001F0
      //	When set to true, causes only linear tracking to be
      //	performed.
      void LinearTrackingOnly (bool flg);

      //## Operation: UseExactChromaticity%3969BD80022C
      //	When set to true, the quadrupole map is calculated
      //	exactly for each magnet. Default is false (i.e. each
      //	quadrupole is expanded to second-order).
      void UseExactChromaticity (bool flg);

      //## Operation: UseExactSectorBend%3AE7DB3501EA
      //	If exactSB is true, calculate the exact solution for a
      //	sector bend, rather than using the standard (small
      //	angle) transport matrix.
      void UseExactSectorBend (bool exactSB);

      //## Operation: UseFullAcceleration%3B9765DD011A
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
    // Data Members for Class Attributes

      //## Attribute: first_order%3969BD4C017D
      //## begin ParticleTransportProcess::first_order%3969BD4C017D.attr preserve=no  private: bool {UA} 
      bool first_order;
      //## end ParticleTransportProcess::first_order%3969BD4C017D.attr

      //## Attribute: exact_chrom%3969BD610191
      //## begin ParticleTransportProcess::exact_chrom%3969BD610191.attr preserve=no  private: bool {UA} 
      bool exact_chrom;
      //## end ParticleTransportProcess::exact_chrom%3969BD610191.attr

      //## Attribute: exact_sb%3AE7DB6E033E
      //## begin ParticleTransportProcess::exact_sb%3AE7DB6E033E.attr preserve=no  private: bool {UA} 
      bool exact_sb;
      //## end ParticleTransportProcess::exact_sb%3AE7DB6E033E.attr

      //## Attribute: full_acc%3B9768800356
      //## begin ParticleTransportProcess::full_acc%3B9768800356.attr preserve=no  private: bool {UA} 
      bool full_acc;
      //## end ParticleTransportProcess::full_acc%3B9768800356.attr

    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::<unnamed>%36EE5E81007C
      //## Role: ParticleTransportProcess::itsTracker%36EE5E8102A2
      //## begin ParticleTransportProcess::itsTracker%36EE5E8102A2.role preserve=no  private: ParticleBunchTracker { -> 0..1VFHgAN}
      ParticleBunchTracker* itsTracker;
      //## end ParticleTransportProcess::itsTracker%36EE5E8102A2.role

  private: //## implementation
};

// Class ParticleTransportProcess 


//## Other Operations (inline)
//## Operation: UseExactSectorBend%3AE7DB3501EA
inline void ParticleTransportProcess::UseExactSectorBend (bool exactSB)
{
  //## begin ParticleTransportProcess::UseExactSectorBend%3AE7DB3501EA.body preserve=yes
	exact_sb = exactSB;
  //## end ParticleTransportProcess::UseExactSectorBend%3AE7DB3501EA.body
}

//## Operation: UseFullAcceleration%3B9765DD011A
inline void ParticleTransportProcess::UseFullAcceleration (bool fullacc)
{
  //## begin ParticleTransportProcess::UseFullAcceleration%3B9765DD011A.body preserve=yes
	full_acc=fullacc;
  //## end ParticleTransportProcess::UseFullAcceleration%3B9765DD011A.body
}

//## begin module%3AE7DDD1006E.epilog preserve=yes
//## end module%3AE7DDD1006E.epilog


#endif

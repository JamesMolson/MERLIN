//## begin module%3AE7DDB203B6.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunchProcess.h
 * last modified 26/04/01 11:36:21
 */
//## end module%3AE7DDB203B6.cm

//## begin module%3AE7DDB203B6.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 *
 * Copyright (c) 2000 by The Merlin Collaboration.  
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
//## end module%3AE7DDB203B6.cp

//## Module: ParticleBunchProcess%3AE7DDB203B6; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: D:\dev\Merlin\BeamDynamics\ParticleTracking\ParticleBunchProcess.h

#ifndef ParticleBunchProcess_h
#define ParticleBunchProcess_h 1

//## begin module%3AE7DDB203B6.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE7DDB203B6.additionalIncludes

//## begin module%3AE7DDB203B6.includes preserve=yes
//## end module%3AE7DDB203B6.includes

// ParticleBunch
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"
// BunchProcess
#include "BeamDynamics/BunchProcess.h"
// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"
//## begin module%3AE7DDB203B6.declarations preserve=no
//## end module%3AE7DDB203B6.declarations

//## begin module%3AE7DDB203B6.additionalDeclarations preserve=yes
//## end module%3AE7DDB203B6.additionalDeclarations


//## Class: ParticleBunchProcess%3AE7D8C400DC; Abstract
//	Root class for processes which act on a ParticleBunch.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ParticleBunchProcess : public BunchProcess  //## Inherits: <unnamed>%3AE7D8CF0398
{
  public:
    //## Constructors (specified)
      //## Operation: ParticleBunchProcess%988274694
      //	Constructing taking the process ID and its priority
      //	(default =0, high).
      explicit ParticleBunchProcess (const string& anID, int aPriority = 0);


    //## Other Operations (specified)
      //## Operation: InitialiseProcess%988274688
      //	Initialise this process with the specified Bunch.
      virtual void InitialiseProcess (Bunch& bunch);

  protected:
    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::<unnamed>%3AE7D8EF0226
      //## Role: ParticleBunchProcess::currentBunch%3AE7D8F0010E
      //## begin ParticleBunchProcess::currentBunch%3AE7D8F0010E.role preserve=no  protected: ParticleBunch { -> RHAN}
      ParticleBunch* currentBunch;
      //## end ParticleBunchProcess::currentBunch%3AE7D8F0010E.role

      //## Association: Merlin::BeamDynamics::ParticleTracking::class details::<unnamed>%3AE7EB98035C
      //## Role: ParticleBunchProcess::currentComponent%3AE7EB99019A
      //## begin ParticleBunchProcess::currentComponent%3AE7EB99019A.role preserve=no  protected: AcceleratorComponent { -> 0..1RHAN}
      AcceleratorComponent* currentComponent;
      //## end ParticleBunchProcess::currentComponent%3AE7EB99019A.role

  private:
  private:  //## implementation
};

// Class ParticleBunchProcess 

//## Operation: ParticleBunchProcess%988274694
inline ParticleBunchProcess::ParticleBunchProcess (const string& anID, int aPriority)
  //## begin ParticleBunchProcess::ParticleBunchProcess%988274694.initialization preserve=yes
  : BunchProcess(anID,aPriority),currentBunch(0)
  //## end ParticleBunchProcess::ParticleBunchProcess%988274694.initialization
{
  //## begin ParticleBunchProcess::ParticleBunchProcess%988274694.body preserve=yes
  //## end ParticleBunchProcess::ParticleBunchProcess%988274694.body
}


//## begin module%3AE7DDB203B6.epilog preserve=yes
//## end module%3AE7DDB203B6.epilog


#endif

//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3B73D4FB0316.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\Integrators\ParticleMapPI.h
 * last modified 08/10/01 02:40:06 PM
 */
//## end module%3B73D4FB0316.cm

//## begin module%3B73D4FB0316.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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
//## end module%3B73D4FB0316.cp

//## Module: ParticleMapPI%3B73D4FB0316; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\Integrators\ParticleMapPI.h

#ifndef ParticleMapPI_h
#define ParticleMapPI_h 1

//## begin module%3B73D4FB0316.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3B73D4FB0316.additionalIncludes

//## begin module%3B73D4FB0316.includes preserve=yes
//## end module%3B73D4FB0316.includes

// ParticleBunchIntegrator
#include "BeamDynamics/ParticleTracking/ParticleBunchIntegrator.h"
// ParticleMapComponent
#include "BeamDynamics/ParticleTracking/ParticleMapComponent.h"
//## begin module%3B73D4FB0316.additionalDeclarations preserve=yes
//## end module%3B73D4FB0316.additionalDeclarations


//## Class: ParticleMapPI%3B73D4A200D4
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ParticleMapPI : public TParticleI< ParticleMapComponent  >  //## Inherits: <unnamed>%3B73D4B003A5
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3B73D4DD03D2
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation
};

// Class ParticleMapPI 

//## begin module%3B73D4FB0316.epilog preserve=yes
//## end module%3B73D4FB0316.epilog


#endif

//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3B73CF1E02E6.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\LinearParticleMap.h
 * last modified 08/10/01 02:26:02 PM
 */
//## end module%3B73CF1E02E6.cm

//## begin module%3B73CF1E02E6.cp preserve=no
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
//## end module%3B73CF1E02E6.cp

//## Module: LinearParticleMap%3B73CF1E02E6; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\LinearParticleMap.h

#ifndef LinearParticleMap_h
#define LinearParticleMap_h 1

//## begin module%3B73CF1E02E6.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3B73CF1E02E6.additionalIncludes

//## begin module%3B73CF1E02E6.includes preserve=yes
//## end module%3B73CF1E02E6.includes

// MatrixMaps
#include "BasicTransport/MatrixMaps.h"
// ParticleMap
#include "BeamDynamics/ParticleTracking/ParticleMap.h"

class ParticleBunch;

//## begin module%3B73CF1E02E6.additionalDeclarations preserve=yes
//## end module%3B73CF1E02E6.additionalDeclarations


//## Class: LinearParticleMap%3B73CBC60209
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B73D2D4002F;ParticleBunch { -> F}

class LinearParticleMap : public ParticleMap  //## Inherits: <unnamed>%3B73CBD20061
{
  public:

    //## Other Operations (specified)
      //## Operation: Apply%3B73CC5C010A
      //	Applies the map to the specified ParticleBunch.
      virtual ParticleBunch& Apply (ParticleBunch& bunch) const;

      //## Operation: Invert%3B73CE4D00C9
      virtual void Invert ();

    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::<unnamed>%3B73CBE60309
      //## Role: LinearParticleMap::R%3B73CBE7010C
      //## begin LinearParticleMap::R%3B73CBE7010C.role preserve=no  public: RMtrx { -> 1VHgAN}
      RMtrx R;
      //## end LinearParticleMap::R%3B73CBE7010C.role

  protected:
  private:
  private: //## implementation
};

// Class LinearParticleMap 

//## begin module%3B73CF1E02E6.epilog preserve=yes
//## end module%3B73CF1E02E6.epilog


#endif

//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3B73CECB021E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleMap.h
 * last modified 08/10/01 02:14:16 PM
 */
//## end module%3B73CECB021E.cm

//## begin module%3B73CECB021E.cp preserve=no
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
//## end module%3B73CECB021E.cp

//## Module: ParticleMap%3B73CECB021E; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleMap.h

#ifndef ParticleMap_h
#define ParticleMap_h 1

//## begin module%3B73CECB021E.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3B73CECB021E.additionalIncludes

//## begin module%3B73CECB021E.includes preserve=yes
//## end module%3B73CECB021E.includes


class ParticleBunch;

//## begin module%3B73CECB021E.additionalDeclarations preserve=yes
//## end module%3B73CECB021E.additionalDeclarations


//## Class: ParticleMap%3B73CB830253; Abstract
//	An arbitrary map that can be applied to a ParticleBunch.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B73CBB30284;ParticleBunch { -> F}

class ParticleMap 
{
  public:
    //## Destructor (specified)
      //## Operation: ~ParticleMap%3B73CE3A0216
      virtual ~ParticleMap ();


    //## Other Operations (specified)
      //## Operation: Apply%3B73CC0A003A
      //	Applies the map to the specified ParticleBunch.
      virtual ParticleBunch& Apply (ParticleBunch& bunch) const = 0;

      //## Operation: Invert%3B73CE13013D
      virtual void Invert () = 0;

  protected:
  private:
  private: //## implementation
};

// Class ParticleMap 

//## Operation: ~ParticleMap%3B73CE3A0216
inline ParticleMap::~ParticleMap ()
{
  //## begin ParticleMap::~ParticleMap%3B73CE3A0216.body preserve=yes
  //## end ParticleMap::~ParticleMap%3B73CE3A0216.body
}


// Class ParticleMap 


//## begin module%3B73CECB021E.epilog preserve=yes
//## end module%3B73CECB021E.epilog


#endif

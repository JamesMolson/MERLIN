//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3B73CF2B019A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\LinearParticleMap.cpp
 * last modified 08/10/01 02:26:02 PM
 */
//## end module%3B73CF2B019A.cm

//## begin module%3B73CF2B019A.cp preserve=no
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
//## end module%3B73CF2B019A.cp

//## Module: LinearParticleMap%3B73CF2B019A; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\LinearParticleMap.cpp

//## begin module%3B73CF2B019A.includes preserve=yes
//## end module%3B73CF2B019A.includes

// ParticleBunch
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"
// LinearParticleMap
#include "BeamDynamics/ParticleTracking/LinearParticleMap.h"


//## begin module%3B73CF2B019A.additionalDeclarations preserve=yes
#include <cassert>
//## end module%3B73CF2B019A.additionalDeclarations


// Class LinearParticleMap 



//## Other Operations (implementation)
//## Operation: Apply%3B73CC5C010A
ParticleBunch& LinearParticleMap::Apply (ParticleBunch& bunch) const
{
  //## begin LinearParticleMap::Apply%3B73CC5C010A.body preserve=yes
	R.Apply(bunch.GetParticles());
	return bunch;
  //## end LinearParticleMap::Apply%3B73CC5C010A.body
}

//## Operation: Invert%3B73CE4D00C9
void LinearParticleMap::Invert ()
{
  //## begin LinearParticleMap::Invert%3B73CE4D00C9.body preserve=yes
	// TODO:
	assert(false);
  //## end LinearParticleMap::Invert%3B73CE4D00C9.body
}

//## begin module%3B73CF2B019A.epilog preserve=yes
//## end module%3B73CF2B019A.epilog

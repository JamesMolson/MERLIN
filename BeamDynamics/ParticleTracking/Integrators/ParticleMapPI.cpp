//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3B73D4FD0233.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\Integrators\ParticleMapPI.cpp
 * last modified 08/10/01 02:40:06 PM
 */
//## end module%3B73D4FD0233.cm

//## begin module%3B73D4FD0233.cp preserve=no
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
//## end module%3B73D4FD0233.cp

//## Module: ParticleMapPI%3B73D4FD0233; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\Integrators\ParticleMapPI.cpp

//## begin module%3B73D4FD0233.includes preserve=yes
//## end module%3B73D4FD0233.includes

// ParticleMapPI
#include "BeamDynamics/ParticleTracking/Integrators/ParticleMapPI.h"
//## begin module%3B73D4FD0233.additionalDeclarations preserve=yes
//## end module%3B73D4FD0233.additionalDeclarations


// Class ParticleMapPI 


//## Other Operations (implementation)
//## Operation: TrackStep%3B73D4DD03D2
double ParticleMapPI::TrackStep (double ds)
{
  //## begin ParticleMapPI::TrackStep%3B73D4DD03D2.body preserve=yes
	assert(ds==0);
	Component().Apply(GetBunch());
	return IncrStep(ds);
  //## end ParticleMapPI::TrackStep%3B73D4DD03D2.body
}

//## begin module%3B73D4FD0233.epilog preserve=yes
//## end module%3B73D4FD0233.epilog

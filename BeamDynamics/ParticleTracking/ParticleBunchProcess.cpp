//## begin module%3AE7DDBF02BC.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunchProcess.cpp
 * last modified 26/04/01 11:36:20
 */
//## end module%3AE7DDBF02BC.cm

//## begin module%3AE7DDBF02BC.cp preserve=no
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
//## end module%3AE7DDBF02BC.cp

//## Module: ParticleBunchProcess%3AE7DDBF02BC; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: D:\dev\Merlin\BeamDynamics\ParticleTracking\ParticleBunchProcess.cpp

//## begin module%3AE7DDBF02BC.includes preserve=yes
//## end module%3AE7DDBF02BC.includes

// ParticleBunchProcess
#include "BeamDynamics/ParticleTracking/ParticleBunchProcess.h"
//## begin module%3AE7DDBF02BC.declarations preserve=no
//## end module%3AE7DDBF02BC.declarations

//## begin module%3AE7DDBF02BC.additionalDeclarations preserve=yes
//## end module%3AE7DDBF02BC.additionalDeclarations


// Class ParticleBunchProcess 




//## Other Operations (implementation)
//## Operation: InitialiseProcess%988274688
void ParticleBunchProcess::InitialiseProcess (Bunch& bunch)
{
  //## begin ParticleBunchProcess::InitialiseProcess%988274688.body preserve=yes
	currentBunch = dynamic_cast<ParticleBunch*>(&bunch);
  //## end ParticleBunchProcess::InitialiseProcess%988274688.body
}

//## begin module%3AE7DDBF02BC.epilog preserve=yes
//## end module%3AE7DDBF02BC.epilog

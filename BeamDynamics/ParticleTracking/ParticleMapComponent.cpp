//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3B73CEA900C1.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleMapComponent.cpp
 * last modified 08/10/01 02:23:07 PM
 */
//## end module%3B73CEA900C1.cm

//## begin module%3B73CEA900C1.cp preserve=no
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
//## end module%3B73CEA900C1.cp

//## Module: ParticleMapComponent%3B73CEA900C1; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleMapComponent.cpp

//## begin module%3B73CEA900C1.includes preserve=yes
//## end module%3B73CEA900C1.includes

// ParticleBunch
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"
// ParticleMapComponent
#include "BeamDynamics/ParticleTracking/ParticleMapComponent.h"


//## begin module%3B73CEA900C1.additionalDeclarations preserve=yes
#include <cassert>
//## end module%3B73CEA900C1.additionalDeclarations


// Class ParticleMapComponent 

//## begin ParticleMapComponent::ID%3B73CD3D00A0.attr preserve=no  public: static const int {UA} UniqueIndex()
const int ParticleMapComponent::ID = UniqueIndex();
//## end ParticleMapComponent::ID%3B73CD3D00A0.attr


//## Operation: ParticleMapComponent%3B73CCE10115
ParticleMapComponent::ParticleMapComponent (const std::string& id, ParticleMap* pmap)
  //## begin ParticleMapComponent::ParticleMapComponent%3B73CCE10115.initialization preserve=yes
  : AcceleratorComponent(id),itsMap(pmap)
  //## end ParticleMapComponent::ParticleMapComponent%3B73CCE10115.initialization
{
  //## begin ParticleMapComponent::ParticleMapComponent%3B73CCE10115.body preserve=yes
	assert(pmap);
  //## end ParticleMapComponent::ParticleMapComponent%3B73CCE10115.body
}



//## Other Operations (implementation)
//## Operation: GetType%3B73CD0E0297
const string& ParticleMapComponent::GetType () const
{
  //## begin ParticleMapComponent::GetType%3B73CD0E0297.body preserve=yes
	_TYPESTR(ParticleMap);
  //## end ParticleMapComponent::GetType%3B73CD0E0297.body
}

//## Operation: Copy%3B73CD1503E1
ModelElement* ParticleMapComponent::Copy () const
{
  //## begin ParticleMapComponent::Copy%3B73CD1503E1.body preserve=yes
	return new ParticleMapComponent(*this);
  //## end ParticleMapComponent::Copy%3B73CD1503E1.body
}

//## Operation: GetIndex%3B73CD710018
int ParticleMapComponent::GetIndex () const
{
  //## begin ParticleMapComponent::GetIndex%3B73CD710018.body preserve=yes
	return ID;
  //## end ParticleMapComponent::GetIndex%3B73CD710018.body
}

//## Operation: RotateY180%3B73CD7F03E4
void ParticleMapComponent::RotateY180 ()
{
  //## begin ParticleMapComponent::RotateY180%3B73CD7F03E4.body preserve=yes
	itsMap->Invert();
  //## end ParticleMapComponent::RotateY180%3B73CD7F03E4.body
}

//## Operation: PrepareTracker%3B73D1520124
void ParticleMapComponent::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin ParticleMapComponent::PrepareTracker%3B73D1520124.body preserve=yes
	_PREPTRACK(aTracker,AcceleratorComponent)
  //## end ParticleMapComponent::PrepareTracker%3B73D1520124.body
}

//## begin module%3B73CEA900C1.epilog preserve=yes
//## end module%3B73CEA900C1.epilog

//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3AE7DDDC0136.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleTransportProcess.cpp
 * last modified 09/06/01 02:14:07 PM
 */
//## end module%3AE7DDDC0136.cm

//## begin module%3AE7DDDC0136.cp preserve=no
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
//## end module%3AE7DDDC0136.cp

//## Module: ParticleTransportProcess%3AE7DDDC0136; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleTransportProcess.cpp

//## begin module%3AE7DDDC0136.includes preserve=yes
//## end module%3AE7DDDC0136.includes

// ParticleBunchTracker
#include "BeamDynamics/ParticleTracking/ParticleBunchTracker.h"
// ParticleTransportProcess
#include "BeamDynamics/ParticleTracking/ParticleTransportProcess.h"


//## begin module%3AE7DDDC0136.additionalDeclarations preserve=yes
//## end module%3AE7DDDC0136.additionalDeclarations


// Class ParticleTransportProcess 







//## Operation: ParticleTransportProcess%37C3E6170028
ParticleTransportProcess::ParticleTransportProcess ()
  //## begin ParticleTransportProcess::ParticleTransportProcess%37C3E6170028.initialization preserve=yes
  : ParticleBunchProcess("PARTICLE TRANSPORT",0),first_order(false),
  exact_chrom(false),exact_sb(false),full_acc(true),itsTracker(0)
  //## end ParticleTransportProcess::ParticleTransportProcess%37C3E6170028.initialization
{
  //## begin ParticleTransportProcess::ParticleTransportProcess%37C3E6170028.body preserve=yes
  //## end ParticleTransportProcess::ParticleTransportProcess%37C3E6170028.body
}


//## Operation: ~ParticleTransportProcess%37C3E62A017C
ParticleTransportProcess::~ParticleTransportProcess ()
{
  //## begin ParticleTransportProcess::~ParticleTransportProcess%37C3E62A017C.body preserve=yes
	if(itsTracker)
		delete itsTracker;
  //## end ParticleTransportProcess::~ParticleTransportProcess%37C3E62A017C.body
}



//## Other Operations (implementation)
//## Operation: InitialiseProcess%37C3E45E010E
void ParticleTransportProcess::InitialiseProcess (Bunch& bunch)
{
  //## begin ParticleTransportProcess::InitialiseProcess%37C3E45E010E.body preserve=yes
	ParticleBunchProcess::InitialiseProcess(bunch);
	
	if(itsTracker)
		delete itsTracker;

	itsTracker = currentBunch!=0 ? ParticleBunchTracker::ConstructNewTracker(*currentBunch) : 0;

	if(itsTracker) {
		itsTracker->UseExactChromaticity(exact_chrom);
		itsTracker->UseExactChromaticity(exact_sb);
		itsTracker->LinearTrackingOnly(first_order);
		itsTracker->UseFullAcceleration(full_acc);
	}
  //## end ParticleTransportProcess::InitialiseProcess%37C3E45E010E.body
}

//## Operation: SetCurrentComponent%37C3E45E017C
void ParticleTransportProcess::SetCurrentComponent (AcceleratorComponent& component)
{
  //## begin ParticleTransportProcess::SetCurrentComponent%37C3E45E017C.body preserve=yes
	if(itsTracker) {
		component.PrepareTracker(*itsTracker);
		active=true;
	}
	else
		active = false;
  //## end ParticleTransportProcess::SetCurrentComponent%37C3E45E017C.body
}

//## Operation: DoProcess%37C3E45E01AE
void ParticleTransportProcess::DoProcess (double ds)
{
  //## begin ParticleTransportProcess::DoProcess%37C3E45E01AE.body preserve=yes
	assert(itsTracker);
	itsTracker->TrackStep(ds);
  //## end ParticleTransportProcess::DoProcess%37C3E45E01AE.body
}

//## Operation: GetMaxAllowedStepSize%37C3E45E021C
double ParticleTransportProcess::GetMaxAllowedStepSize () const
{
  //## begin ParticleTransportProcess::GetMaxAllowedStepSize%37C3E45E021C.body preserve=yes
	assert(itsTracker);
	return itsTracker->GetRemainingTrackLength();
  //## end ParticleTransportProcess::GetMaxAllowedStepSize%37C3E45E021C.body
}

//## Operation: LinearTrackingOnly%3969BD8001F0
void ParticleTransportProcess::LinearTrackingOnly (bool flg)
{
  //## begin ParticleTransportProcess::LinearTrackingOnly%3969BD8001F0.body preserve=yes
	first_order = flg;
  //## end ParticleTransportProcess::LinearTrackingOnly%3969BD8001F0.body
}

//## Operation: UseExactChromaticity%3969BD80022C
void ParticleTransportProcess::UseExactChromaticity (bool flg)
{
  //## begin ParticleTransportProcess::UseExactChromaticity%3969BD80022C.body preserve=yes
	exact_chrom = flg;
  //## end ParticleTransportProcess::UseExactChromaticity%3969BD80022C.body
}

//## begin module%3AE7DDDC0136.epilog preserve=yes
//## end module%3AE7DDDC0136.epilog

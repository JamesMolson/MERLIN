//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3AE80804015E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleTracker.cpp
 * last modified 09/06/01 02:15:19 PM
 */
//## end module%3AE80804015E.cm

//## begin module%3AE80804015E.cp preserve=no
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
//## end module%3AE80804015E.cp

//## Module: ParticleTracker%3AE80804015E; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleTracker.cpp

//## begin module%3AE80804015E.includes preserve=yes
//## end module%3AE80804015E.includes

// BunchConstructor
#include "BeamModel/BunchConstructor.h"
// ParticleTransportProcess
#include "BeamDynamics/ParticleTracking/ParticleTransportProcess.h"
// ParticleTracker
#include "BeamDynamics/ParticleTracking/ParticleTracker.h"


//## begin module%3AE80804015E.additionalDeclarations preserve=yes
//## end module%3AE80804015E.additionalDeclarations


// Class ParticleTracker 


//## Operation: ParticleTracker%3AE806C10294
ParticleTracker::ParticleTracker (const AcceleratorModel::Beamline& bline, ParticleBunch* bunch0, bool del)
  //## begin ParticleTracker::ParticleTracker%3AE806C10294.initialization preserve=yes
  : TrackingSimulation(bline),transportProc(new ParticleTransportProcess)
  //## end ParticleTracker::ParticleTracker%3AE806C10294.initialization
{
  //## begin ParticleTracker::ParticleTracker%3AE806C10294.body preserve=yes
	SetInitialBunch(bunch0,del);
	AddProcess(transportProc);
  //## end ParticleTracker::ParticleTracker%3AE806C10294.body
}

//## Operation: ParticleTracker%3AE95BD103CA
ParticleTracker::ParticleTracker (const AcceleratorModel::Beamline& bline, const Particle& p, double Pref)
  //## begin ParticleTracker::ParticleTracker%3AE95BD103CA.initialization preserve=yes
  : TrackingSimulation(bline),transportProc(new ParticleTransportProcess)
  //## end ParticleTracker::ParticleTracker%3AE95BD103CA.initialization
{
  //## begin ParticleTracker::ParticleTracker%3AE95BD103CA.body preserve=yes
	SetInitialParticle(p,Pref);
	AddProcess(transportProc);
  //## end ParticleTracker::ParticleTracker%3AE95BD103CA.body
}

//## Operation: ParticleTracker%3B66AB940018
ParticleTracker::ParticleTracker (const AcceleratorModel::RingIterator& ring, ParticleBunch* bunch0, bool del)
  //## begin ParticleTracker::ParticleTracker%3B66AB940018.initialization preserve=yes
  : TrackingSimulation(ring),transportProc(new ParticleTransportProcess)
  //## end ParticleTracker::ParticleTracker%3B66AB940018.initialization
{
  //## begin ParticleTracker::ParticleTracker%3B66AB940018.body preserve=yes
	SetInitialBunch(bunch0,del);
	AddProcess(transportProc);
  //## end ParticleTracker::ParticleTracker%3B66AB940018.body
}

//## Operation: ParticleTracker%3B66AB940040
ParticleTracker::ParticleTracker (const AcceleratorModel::RingIterator& ring, const Particle& p, double Pref)
  //## begin ParticleTracker::ParticleTracker%3B66AB940040.initialization preserve=yes
  : TrackingSimulation(ring),transportProc(new ParticleTransportProcess)
  //## end ParticleTracker::ParticleTracker%3B66AB940040.initialization
{
  //## begin ParticleTracker::ParticleTracker%3B66AB940040.body preserve=yes
	SetInitialParticle(p,Pref);
	AddProcess(transportProc);
  //## end ParticleTracker::ParticleTracker%3B66AB940040.body
}


//## Operation: SetInitialParticle%3AE95C37038E
void ParticleTracker::SetInitialParticle (const Particle& p, double Pref)
{
  //## begin ParticleTracker::SetInitialParticle%3AE95C37038E.body preserve=yes
	ParticleBunch* b = new ParticleBunch(Pref);
	b->AddParticle(p);
	SetInitialBunch(b,true);
  //## end ParticleTracker::SetInitialParticle%3AE95C37038E.body
}

//## Operation: LinearTrackingOnly%3AE805B80064
void ParticleTracker::LinearTrackingOnly (bool flg)
{
  //## begin ParticleTracker::LinearTrackingOnly%3AE805B80064.body preserve=yes
	transportProc->LinearTrackingOnly(flg);
  //## end ParticleTracker::LinearTrackingOnly%3AE805B80064.body
}

//## Operation: UseExactChromaticity%3AE805B800D2
void ParticleTracker::UseExactChromaticity (bool flg)
{
  //## begin ParticleTracker::UseExactChromaticity%3AE805B800D2.body preserve=yes
	transportProc->UseExactChromaticity(flg);
  //## end ParticleTracker::UseExactChromaticity%3AE805B800D2.body
}

//## Operation: UseExactSectorBend%3AE805B80104
void ParticleTracker::UseExactSectorBend (bool exactSB)
{
  //## begin ParticleTracker::UseExactSectorBend%3AE805B80104.body preserve=yes
	transportProc->UseExactSectorBend(exactSB);
  //## end ParticleTracker::UseExactSectorBend%3AE805B80104.body
}

//## Operation: UseFullAcceleration%3B97661F029C
void ParticleTracker::UseFullAcceleration (bool fullacc)
{
  //## begin ParticleTracker::UseFullAcceleration%3B97661F029C.body preserve=yes
	transportProc->UseFullAcceleration(fullacc);
  //## end ParticleTracker::UseFullAcceleration%3B97661F029C.body
}

//## begin module%3AE80804015E.epilog preserve=yes
//## end module%3AE80804015E.epilog

//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3729F8AE038E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunchTracker.cpp
 * last modified 09/11/01 04:10:34 PM
 */
//## end module%3729F8AE038E.cm

//## begin module%3729F8AE038E.cp preserve=no
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
//## end module%3729F8AE038E.cp

//## Module: ParticleBunchTracker%3729F8AE038E; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleBunchTracker.cpp

//## begin module%3729F8AE038E.includes preserve=yes
//## end module%3729F8AE038E.includes

// ParticleBunchTracker
#include "BeamDynamics/ParticleTracking/ParticleBunchTracker.h"
// ParticleBunchIntegrator
#include "BeamDynamics/ParticleTracking/ParticleBunchIntegrator.h"
// StdIntegrators
#include "BeamDynamics/ParticleTracking/Integrators/StdIntegrators.h"
// ExactSectorBendPI
#include "BeamDynamics/ParticleTracking/Integrators/ExactSectorBendPI.h"
// ParticleMapPI
#include "BeamDynamics/ParticleTracking/Integrators/ParticleMapPI.h"

#include "BeamDynamics/ParticleTracking/Integrators/TransportIntegrators.h"

//## begin module%3729F8AE038E.additionalDeclarations preserve=yes
#define _REGI(_I) Register(new _I ())
//## end module%3729F8AE038E.additionalDeclarations


// Class ParticleBunchTracker 




//## begin ParticleBunchTracker::defaultTracker%3B9E14E000A4.role preserve=no  private: static ParticleBunchTracker { -> RHAN}
ParticleBunchTracker* ParticleBunchTracker::defaultTracker = 0;
//## end ParticleBunchTracker::defaultTracker%3B9E14E000A4.role

//## Operation: ParticleBunchTracker%36EE50EB026F
ParticleBunchTracker::ParticleBunchTracker (ParticleBunch& bunch)
  //## begin ParticleBunchTracker::ParticleBunchTracker%36EE50EB026F.initialization preserve=yes
  : ComponentTracker(),theBunch(&bunch)
  //## end ParticleBunchTracker::ParticleBunchTracker%36EE50EB026F.initialization
{
  //## begin ParticleBunchTracker::ParticleBunchTracker%36EE50EB026F.body preserve=yes
#ifdef USE_TRANSPORT_INTEGRATORS
	_REGI(TRANSPORT::DriftPI);
	_REGI(TRANSPORT::SectorBendPI);
	_REGI(TRANSPORT::RectMultipolePI);
	_REGI(TRANSPORT::SWRFStructurePI);
#else
	_REGI(DriftPI);
	_REGI(SectorBendPI);
	_REGI(RectMultipolePI);
#endif // USE_TRANSPORT_INTEGRATORS

	_REGI(MonitorPI);
	_REGI(TWRFStructurePI);
	_REGI(SWRFStructurePI);
	_REGI(ParticleMapPI);
	_REGI(SolenoidPI);
  //## end ParticleBunchTracker::ParticleBunchTracker%36EE50EB026F.body
}

//## Operation: ParticleBunchTracker%3B9E189100C1
ParticleBunchTracker::ParticleBunchTracker ()
  //## begin ParticleBunchTracker::ParticleBunchTracker%3B9E189100C1.initialization preserve=yes
  : ComponentTracker(),theBunch(0)
  //## end ParticleBunchTracker::ParticleBunchTracker%3B9E189100C1.initialization
{
  //## begin ParticleBunchTracker::ParticleBunchTracker%3B9E189100C1.body preserve=yes
  //## end ParticleBunchTracker::ParticleBunchTracker%3B9E189100C1.body
}



//## Other Operations (implementation)
//## Operation: GetBunch%36EE510701C5
ParticleBunch& ParticleBunchTracker::GetBunch ()
{
  //## begin ParticleBunchTracker::GetBunch%36EE510701C5.body preserve=yes
	return *theBunch;
  //## end ParticleBunchTracker::GetBunch%36EE510701C5.body
}

//## Operation: InitialiseIntegrator%3729F4B90366
void ParticleBunchTracker::InitialiseIntegrator ()
{
  //## begin ParticleBunchTracker::InitialiseIntegrator%3729F4B90366.body preserve=yes
	ComponentTracker::InitialiseIntegrator();
	static_cast<ParticleBunchIntegrator*>(integrator)->SetParticleBunch(theBunch);
  //## end ParticleBunchTracker::InitialiseIntegrator%3729F4B90366.body
}

//## Operation: LinearTrackingOnly%3969B65901E3
void ParticleBunchTracker::LinearTrackingOnly (bool flg)
{
  //## begin ParticleBunchTracker::LinearTrackingOnly%3969B65901E3.body preserve=yes
	// TODO!
  //## end ParticleBunchTracker::LinearTrackingOnly%3969B65901E3.body
}

//## Operation: UseExactChromaticity%3969B6860292
void ParticleBunchTracker::UseExactChromaticity (bool flg)
{
  //## begin ParticleBunchTracker::UseExactChromaticity%3969B6860292.body preserve=yes
	// Here we simple replace the existing integrator
	return;
	if(flg)
		Register(new ExactRectMultipolePI());
	else
		Register(new RectMultipolePI());
  //## end ParticleBunchTracker::UseExactChromaticity%3969B6860292.body
}

//## Operation: UseExactSectorBend%3AE7DC030014
void ParticleBunchTracker::UseExactSectorBend (bool exactSB)
{
  //## begin ParticleBunchTracker::UseExactSectorBend%3AE7DC030014.body preserve=yes
	if(exactSB)
		Register(new ExactSectorBendPI());
	else
		Register(new TRANSPORT::SectorBendPI());
  //## end ParticleBunchTracker::UseExactSectorBend%3AE7DC030014.body
}

//## Operation: UseFullAcceleration%3B9764AD039E
void ParticleBunchTracker::UseFullAcceleration (bool fullacc)
{
	//## begin ParticleBunchTracker::UseFullAcceleration%3B9764AD039E.body preserve=yes
	Register(new TWRFStructurePI(fullacc));
#ifdef USE_TRANSPORT_INTEGRATORS
	Register(new TRANSPORT::SWRFStructurePI(fullacc));
#else
	Register(new SWRFStructurePI(fullacc));
#endif
	Register(new SWRFStructurePI(fullacc));
	//## end ParticleBunchTracker::UseFullAcceleration%3B9764AD039E.body
}

//## Operation: NewTracker%3B9E163301C4
ParticleBunchTracker* ParticleBunchTracker::NewTracker (ParticleBunch& bunch) const
{
  //## begin ParticleBunchTracker::NewTracker%3B9E163301C4.body preserve=yes
	return new ParticleBunchTracker(bunch);
  //## end ParticleBunchTracker::NewTracker%3B9E163301C4.body
}

//## Operation: ConstructNewTracker%3B9E16950247
ParticleBunchTracker* ParticleBunchTracker::ConstructNewTracker (ParticleBunch& bunch)
{
  //## begin ParticleBunchTracker::ConstructNewTracker%3B9E16950247.body preserve=yes
	if(defaultTracker==0)
		defaultTracker = new ParticleBunchTracker();
	return defaultTracker->NewTracker(bunch);
  //## end ParticleBunchTracker::ConstructNewTracker%3B9E16950247.body
}

//## Operation: SetDefaultTracker%3B9E17780080
void ParticleBunchTracker::SetDefaultTracker (ParticleBunchTracker* aTracker)
{
  //## begin ParticleBunchTracker::SetDefaultTracker%3B9E17780080.body preserve=yes
	assert(aTracker);
	if(defaultTracker!=0)
		delete defaultTracker;
	defaultTracker = aTracker;
  //## end ParticleBunchTracker::SetDefaultTracker%3B9E17780080.body
}

//## begin module%3729F8AE038E.epilog preserve=yes
//## end module%3729F8AE038E.epilog

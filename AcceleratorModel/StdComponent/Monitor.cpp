//## begin module%331FFA130074.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\Monitor.cpp
 * last modified 04/04/01 15:25:44
 */
//## end module%331FFA130074.cm

//## begin module%331FFA130074.cp preserve=no
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
//## end module%331FFA130074.cp

//## Module: Monitor%331FFA130074; Pseudo Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\Monitor.cpp

//## begin module%331FFA130074.includes preserve=yes
//## end module%331FFA130074.includes

// Bunch
#include "BeamModel/Bunch.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"
// Monitor
#include "AcceleratorModel/StdComponent/Monitor.h"
//## begin module%331FFA130074.additionalDeclarations preserve=yes
//## end module%331FFA130074.additionalDeclarations


// Class Monitor 




//## begin Monitor::all_inactive%3725876E00D2.attr preserve=no  public: static bool {UA} false
bool Monitor::all_inactive = false;
//## end Monitor::all_inactive%3725876E00D2.attr

//## begin Monitor::ID%3724B06D0212.attr preserve=no  public: static const int {VA} UniqueIndex()
const int Monitor::ID = UniqueIndex();
//## end Monitor::ID%3724B06D0212.attr

//## Operation: Monitor%857738670
Monitor::Monitor (const string& id, double len, double mpt)
  //## begin Monitor::Monitor%857738670.initialization preserve=yes
  : TAccCompG<RectangularGeometry>(id,new RectangularGeometry(len)),mp(mpt),active(true)
  //## end Monitor::Monitor%857738670.initialization
{
  //## begin Monitor::Monitor%857738670.body preserve=yes
  //## end Monitor::Monitor%857738670.body
}


//## Operation: ~Monitor%880624262
Monitor::~Monitor ()
{
  //## begin Monitor::~Monitor%880624262.body preserve=yes
  //## end Monitor::~Monitor%880624262.body
}



//## Other Operations (implementation)
//## Operation: MakeMeasurement%857738671; C++
//## Qualification: abstract
void Monitor::MakeMeasurement (const Bunch& )
{
  //## begin Monitor::MakeMeasurement%857738671.body preserve=yes
  //## end Monitor::MakeMeasurement%857738671.body
}

//## Operation: SetMeasurementPt%857738673; C++
//## Exceptions: AcceleratorGeometry::BeyondExtent
void Monitor::SetMeasurementPt (double mpt) throw (AcceleratorGeometry::BeyondExtent)
{
  //## begin Monitor::SetMeasurementPt%857738673.body preserve=yes
	//GetGeometry().CheckBounds(mpt); // might throw
	mp=mpt;
  //## end Monitor::SetMeasurementPt%857738673.body
}

//## Operation: GetMeasurementPt%868960724
double Monitor::GetMeasurementPt () const
{
  //## begin Monitor::GetMeasurementPt%868960724.body preserve=yes
	return mp;
  //## end Monitor::GetMeasurementPt%868960724.body
}

//## Operation: RotateY180%884089489; C++
//## Qualification: virtual
void Monitor::RotateY180 ()
{
  //## begin Monitor::RotateY180%884089489.body preserve=yes
	reflected=!reflected;
  //## end Monitor::RotateY180%884089489.body
}

//## Operation: GetIndex%925300213
int Monitor::GetIndex () const
{
  //## begin Monitor::GetIndex%925300213.body preserve=yes
	return ID;
  //## end Monitor::GetIndex%925300213.body
}

//## Operation: GetType%925300214
const string& Monitor::GetType () const
{
  //## begin Monitor::GetType%925300214.body preserve=yes
	_TYPESTR(Monitor)
  //## end Monitor::GetType%925300214.body
}

//## Operation: PrepareTracker%925300215
void Monitor::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Monitor::PrepareTracker%925300215.body preserve=yes
	_PREPTRACK(aTracker,AcceleratorComponent)
  //## end Monitor::PrepareTracker%925300215.body
}

//## Operation: Copy%925300216
ModelElement* Monitor::Copy () const
{
  //## begin Monitor::Copy%925300216.body preserve=yes
	return new Monitor(*this);
  //## end Monitor::Copy%925300216.body
}

//## begin module%331FFA130074.epilog preserve=yes
//## end module%331FFA130074.epilog

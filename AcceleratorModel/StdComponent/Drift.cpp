//## begin module%3734090602C6.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\Drift.cpp
 * last modified 04/04/01 15:25:43
 */
//## end module%3734090602C6.cm

//## begin module%3734090602C6.cp preserve=no
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
//## end module%3734090602C6.cp

//## Module: Drift%3734090602C6; Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\Drift.cpp

//## begin module%3734090602C6.includes preserve=yes
//## end module%3734090602C6.includes

// Drift
#include "AcceleratorModel/StdComponent/Drift.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"


//## begin module%3734090602C6.declarations preserve=no
//## end module%3734090602C6.declarations

//## begin module%3734090602C6.additionalDeclarations preserve=yes
//## end module%3734090602C6.additionalDeclarations


// Class Drift 

//## begin Drift::ID%371EEB700046.attr preserve=no  public: static const int {UA} UniqueIndex()
const int Drift::ID = UniqueIndex();
//## end Drift::ID%371EEB700046.attr

//## Operation: Drift%924771612
Drift::Drift (const string& id, double len)
  //## begin Drift::Drift%924771612.initialization preserve=yes
  : TAccCompG<RectangularGeometry>(id,new RectangularGeometry(len))
  //## end Drift::Drift%924771612.initialization
{
  //## begin Drift::Drift%924771612.body preserve=yes
  //## end Drift::Drift%924771612.body
}



//## Other Operations (implementation)
//## Operation: GetType%924771613
const string& Drift::GetType () const
{
  //## begin Drift::GetType%924771613.body preserve=yes
	_TYPESTR(Drift);
  //## end Drift::GetType%924771613.body
}

//## Operation: GetIndex%924771614
int Drift::GetIndex () const
{
  //## begin Drift::GetIndex%924771614.body preserve=yes
	return  ID;
  //## end Drift::GetIndex%924771614.body
}

//## Operation: PrepareTracker%924771615
void Drift::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Drift::PrepareTracker%924771615.body preserve=yes
	_PREPTRACK(aTracker,AcceleratorComponent);
  //## end Drift::PrepareTracker%924771615.body
}

//## Operation: RotateY180%924771616
void Drift::RotateY180 ()
{
  //## begin Drift::RotateY180%924771616.body preserve=yes
	// nothing to do
  //## end Drift::RotateY180%924771616.body
}

//## Operation: Copy%924771617
ModelElement* Drift::Copy () const
{
  //## begin Drift::Copy%924771617.body preserve=yes
	return new Drift(*this);
  //## end Drift::Copy%924771617.body
}

//## begin module%3734090602C6.epilog preserve=yes
//## end module%3734090602C6.epilog

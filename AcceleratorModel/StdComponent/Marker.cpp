//## begin module%356ACBD70358.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\Marker.cpp
 * last modified 03/04/01 15:01:20
 */
//## end module%356ACBD70358.cm

//## begin module%356ACBD70358.cp preserve=no
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
//## end module%356ACBD70358.cp

//## Module: Marker%356ACBD70358; Pseudo Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\Marker.cpp

//## begin module%356ACBD70358.includes preserve=yes
//## end module%356ACBD70358.includes

// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"
// Marker
#include "AcceleratorModel/StdComponent/Marker.h"
//## begin module%356ACBD70358.additionalDeclarations preserve=yes
//## end module%356ACBD70358.additionalDeclarations


// Class Marker 

//## begin Marker::ID%371EE4FB038E.attr preserve=no  public: static const int {UA} UniqueIndex()
const int Marker::ID = UniqueIndex();
//## end Marker::ID%371EE4FB038E.attr


//## Other Operations (implementation)
//## Operation: PrepareTracker%924771607
void Marker::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Marker::PrepareTracker%924771607.body preserve=yes
	_PREPTRACK(aTracker,AcceleratorComponent);
  //## end Marker::PrepareTracker%924771607.body
}

//## Operation: GetIndex%924771608
int Marker::GetIndex () const
{
  //## begin Marker::GetIndex%924771608.body preserve=yes
	return ID;
  //## end Marker::GetIndex%924771608.body
}

//## Operation: GetType%924771609
const string& Marker::GetType () const
{
  //## begin Marker::GetType%924771609.body preserve=yes
	_TYPESTR(Marker)
  //## end Marker::GetType%924771609.body
}

//## Operation: Copy%924771610
ModelElement* Marker::Copy () const
{
  //## begin Marker::Copy%924771610.body preserve=yes
	return new Marker(*this);
  //## end Marker::Copy%924771610.body
}

//## Operation: RotateY180%924771611
void Marker::RotateY180 ()
{
  //## begin Marker::RotateY180%924771611.body preserve=yes
	// Nothing to do
  //## end Marker::RotateY180%924771611.body
}

//## begin module%356ACBD70358.epilog preserve=yes
//## end module%356ACBD70358.epilog

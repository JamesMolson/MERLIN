//## begin module%37248564012C.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\CorrectorDipoles.cpp
 * last modified 03/04/01 14:21:37
 */
//## end module%37248564012C.cm

//## begin module%37248564012C.cp preserve=no
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
//## end module%37248564012C.cp

//## Module: CorrectorDipoles%37248564012C; Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\CorrectorDipoles.cpp

//## begin module%37248564012C.includes preserve=yes
//## end module%37248564012C.includes

// CorrectorDipoles
#include "AcceleratorModel/StdComponent/CorrectorDipoles.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"


//## begin module%37248564012C.declarations preserve=no
//## end module%37248564012C.declarations

//## begin module%37248564012C.additionalDeclarations preserve=yes
//## end module%37248564012C.additionalDeclarations


// Class XCor 

//## begin XCor::ID%372486E20104.attr preserve=no  public: static const int {UA} UniqueIndex()
const int XCor::ID = UniqueIndex();
//## end XCor::ID%372486E20104.attr


//## Other Operations (implementation)
//## Operation: Copy%925120611
ModelElement* XCor::Copy () const
{
  //## begin XCor::Copy%925120611.body preserve=yes
	return new XCor(*this);
  //## end XCor::Copy%925120611.body
}

//## Operation: GetIndex%925120613
int XCor::GetIndex () const
{
  //## begin XCor::GetIndex%925120613.body preserve=yes
	return ID;
  //## end XCor::GetIndex%925120613.body
}

//## Operation: GetType%925120614
const string& XCor::GetType () const
{
  //## begin XCor::GetType%925120614.body preserve=yes
	_TYPESTR(XCor)
  //## end XCor::GetType%925120614.body
}

//## Operation: PrepareTracker%925120615
void XCor::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin XCor::PrepareTracker%925120615.body preserve=yes
	_PREPTRACK(aTracker,RectMultipole)
  //## end XCor::PrepareTracker%925120615.body
}

// Class YCor 

//## begin YCor::ID%372486F602B2.attr preserve=no  public: static const int {UA} UniqueIndex()
const int YCor::ID = UniqueIndex();
//## end YCor::ID%372486F602B2.attr


//## Other Operations (implementation)
//## Operation: Copy%925120616
ModelElement* YCor::Copy () const
{
  //## begin YCor::Copy%925120616.body preserve=yes
	return new YCor(*this);
  //## end YCor::Copy%925120616.body
}

//## Operation: GetIndex%925120618
int YCor::GetIndex () const
{
  //## begin YCor::GetIndex%925120618.body preserve=yes
	return ID;
  //## end YCor::GetIndex%925120618.body
}

//## Operation: GetType%925120619
const string& YCor::GetType () const
{
  //## begin YCor::GetType%925120619.body preserve=yes
	_TYPESTR(YCor)
  //## end YCor::GetType%925120619.body
}

//## Operation: PrepareTracker%925120620
void YCor::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin YCor::PrepareTracker%925120620.body preserve=yes
	_PREPTRACK(aTracker,RectMultipole)
  //## end YCor::PrepareTracker%925120620.body
}

//## begin module%37248564012C.epilog preserve=yes
//## end module%37248564012C.epilog

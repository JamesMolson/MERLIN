//## begin module%373408790302.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\TWRFStructure.cpp
 * last modified 05/04/01 17:58:09
 */
//## end module%373408790302.cm

//## begin module%373408790302.cp preserve=no
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
//## end module%373408790302.cp

//## Module: TWRFStructure%373408790302; Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\TWRFStructure.cpp

//## begin module%373408790302.includes preserve=yes
//## end module%373408790302.includes

// TWRFStructure
#include "AcceleratorModel/StdComponent/TWRFStructure.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"


//## begin module%373408790302.declarations preserve=no
//## end module%373408790302.declarations

//## begin module%373408790302.additionalDeclarations preserve=yes
//## end module%373408790302.additionalDeclarations


// Class TWRFStructure 

//## begin TWRFStructure::ID%372452710096.attr preserve=no  public: static const int {VA} UniqueIndex()
const int TWRFStructure::ID = UniqueIndex();
//## end TWRFStructure::ID%372452710096.attr

//## Operation: TWRFStructure%925120599
TWRFStructure::TWRFStructure (const string& id, double len, double f, double Epk, double phi)
  //## begin TWRFStructure::TWRFStructure%925120599.initialization preserve=yes
  : RectTWRF(id,len,new TWRFfield(f,Epk,phi))
  //## end TWRFStructure::TWRFStructure%925120599.initialization
{
  //## begin TWRFStructure::TWRFStructure%925120599.body preserve=yes
  //## end TWRFStructure::TWRFStructure%925120599.body
}



//## Other Operations (implementation)
//## Operation: GetType%925120600
const string& TWRFStructure::GetType () const
{
  //## begin TWRFStructure::GetType%925120600.body preserve=yes
	_TYPESTR(TWRFStructure)
  //## end TWRFStructure::GetType%925120600.body
}

//## Operation: GetIndex%925120601
int TWRFStructure::GetIndex () const
{
  //## begin TWRFStructure::GetIndex%925120601.body preserve=yes
	return ID;
  //## end TWRFStructure::GetIndex%925120601.body
}

//## Operation: PrepareTracker%925120602
void TWRFStructure::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin TWRFStructure::PrepareTracker%925120602.body preserve=yes
	_PREPTRACK(aTracker,AcceleratorComponent)
  //## end TWRFStructure::PrepareTracker%925120602.body
}

//## Operation: RotateY180%925120603
void TWRFStructure::RotateY180 ()
{
  //## begin TWRFStructure::RotateY180%925120603.body preserve=yes
	double E = GetField().GetAmplitude();
	GetField().SetAmplitude(-E);
  //## end TWRFStructure::RotateY180%925120603.body
}

//## Operation: Copy%925120604
ModelElement* TWRFStructure::Copy () const
{
  //## begin TWRFStructure::Copy%925120604.body preserve=yes
	return new TWRFStructure(*this);
  //## end TWRFStructure::Copy%925120604.body
}

//## begin module%373408790302.epilog preserve=yes
//## end module%373408790302.epilog

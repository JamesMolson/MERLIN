//## begin module%37135540032A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\AcceleratorComponent.cpp
 * last modified 03/04/01 14:32:34
 */
//## end module%37135540032A.cm

//## begin module%37135540032A.cp preserve=no
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
//## end module%37135540032A.cp

//## Module: AcceleratorComponent%37135540032A; Package body
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: D:\dev\Merlin\AcceleratorModel\AcceleratorComponent.cpp

//## begin module%37135540032A.includes preserve=yes
//## end module%37135540032A.includes

// Aperture
#include "AcceleratorModel/Aperture.h"
// AcceleratorGeometry
#include "AcceleratorModel/AcceleratorGeometry.h"
// EMField
#include "AcceleratorModel/EMField.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"
// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"


//## begin module%37135540032A.declarations preserve=no
//## end module%37135540032A.declarations

//## begin module%37135540032A.additionalDeclarations preserve=yes
//## end module%37135540032A.additionalDeclarations


// Class AcceleratorComponent 

//## begin AcceleratorComponent::ID%371463CE019A.attr preserve=no  public: static const int {UA} UniqueIndex()
const int AcceleratorComponent::ID = UniqueIndex();
//## end AcceleratorComponent::ID%371463CE019A.attr






//## Operation: ~AcceleratorComponent%924014182
AcceleratorComponent::~AcceleratorComponent ()
{
  //## begin AcceleratorComponent::~AcceleratorComponent%924014182.body preserve=yes
  if(itsGeometry) delete itsGeometry;
  if(itsField) delete itsField;
  //## end AcceleratorComponent::~AcceleratorComponent%924014182.body
}



//## Other Operations (implementation)
//## Operation: GetIndex%924072843
int AcceleratorComponent::GetIndex () const
{
  //## begin AcceleratorComponent::GetIndex%924072843.body preserve=yes
	return ID;
  //## end AcceleratorComponent::GetIndex%924072843.body
}

//## Operation: GetLength%924014184
//## Semantics:
//	return itsGeometry!=0 ? itsGeometry->GetLength() : 0.0;
double AcceleratorComponent::GetLength () const
{
  //## begin AcceleratorComponent::GetLength%924014184.body preserve=yes
	return itsGeometry ? itsGeometry->GetGeometryLength() : 0;
  //## end AcceleratorComponent::GetLength%924014184.body
}

//## Operation: PrepareTracker%924014185
void AcceleratorComponent::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin AcceleratorComponent::PrepareTracker%924014185.body preserve=yes
	if(!aTracker.SelectIntegrator(AcceleratorComponent::ID,*this))
		throw ComponentTracker::UnknownComponent();
  //## end AcceleratorComponent::PrepareTracker%924014185.body
}

//## begin module%37135540032A.epilog preserve=yes
//## end module%37135540032A.epilog

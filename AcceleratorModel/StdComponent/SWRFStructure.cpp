//## begin module%3734081701CC.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\SWRFStructure.cpp
 * last modified 05/04/01 17:58:10
 */
//## end module%3734081701CC.cm

//## begin module%3734081701CC.cp preserve=no
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
//## end module%3734081701CC.cp

//## Module: SWRFStructure%3734081701CC; Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\SWRFStructure.cpp

//## begin module%3734081701CC.includes preserve=yes
#include "NumericalUtils/PhysicalConstants.h"
//## end module%3734081701CC.includes

// SWRFStructure
#include "AcceleratorModel/StdComponent/SWRFStructure.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"


//## begin module%3734081701CC.declarations preserve=no
//## end module%3734081701CC.declarations

//## begin module%3734081701CC.additionalDeclarations preserve=yes
namespace {
	inline double Wavelength(double f) { 
		using PhysicalConstants::SpeedOfLight;
		return SpeedOfLight/f;
	}
};
//## end module%3734081701CC.additionalDeclarations


// Class SWRFStructure 

//## begin SWRFStructure::ID%372454B403AC.attr preserve=no  public: static const int {UA} UniqueIndex()
const int SWRFStructure::ID = UniqueIndex();
//## end SWRFStructure::ID%372454B403AC.attr

//## Operation: SWRFStructure%925120605
SWRFStructure::SWRFStructure (const string& id, int ncells, double f, double E0, double phi)
  //## begin SWRFStructure::SWRFStructure%925120605.initialization preserve=yes
  : RectSWRF(id,Wavelength(f)*ncells/2,new SWRFfield(f,E0,phi))
  //## end SWRFStructure::SWRFStructure%925120605.initialization
{
  //## begin SWRFStructure::SWRFStructure%925120605.body preserve=yes
  //## end SWRFStructure::SWRFStructure%925120605.body
}



//## Other Operations (implementation)
//## Operation: GetType%925120606
const string& SWRFStructure::GetType () const
{
  //## begin SWRFStructure::GetType%925120606.body preserve=yes
	_TYPESTR(SWRFStructure)
  //## end SWRFStructure::GetType%925120606.body
}

//## Operation: GetIndex%925120607
int SWRFStructure::GetIndex () const
{
  //## begin SWRFStructure::GetIndex%925120607.body preserve=yes
	return ID;
  //## end SWRFStructure::GetIndex%925120607.body
}

//## Operation: PrepareTracker%925120608
void SWRFStructure::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin SWRFStructure::PrepareTracker%925120608.body preserve=yes
	_PREPTRACK(aTracker,AcceleratorComponent)
  //## end SWRFStructure::PrepareTracker%925120608.body
}

//## Operation: RotateY180%925120609
void SWRFStructure::RotateY180 ()
{
  //## begin SWRFStructure::RotateY180%925120609.body preserve=yes
	double E = GetField().GetAmplitude();
	GetField().SetAmplitude(-E);
  //## end SWRFStructure::RotateY180%925120609.body
}

//## Operation: Copy%925120610
ModelElement* SWRFStructure::Copy () const
{
  //## begin SWRFStructure::Copy%925120610.body preserve=yes
	return new SWRFStructure(*this);
  //## end SWRFStructure::Copy%925120610.body
}

//## begin module%3734081701CC.epilog preserve=yes
//## end module%3734081701CC.epilog

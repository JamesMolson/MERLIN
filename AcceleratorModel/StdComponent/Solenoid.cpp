//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3C14B28B02D1.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdComponent\Solenoid.cpp
 * last modified 10/12/01 16:41:41
 */
//## end module%3C14B28B02D1.cm

//## begin module%3C14B28B02D1.cp preserve=no
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
//## end module%3C14B28B02D1.cp

//## Module: Solenoid%3C14B28B02D1; Pseudo Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: C:\C++\Merlin\AcceleratorModel\StdComponent\Solenoid.cpp

//## begin module%3C14B28B02D1.includes preserve=yes
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"
//## end module%3C14B28B02D1.includes

// Solenoid
#include "AcceleratorModel/StdComponent/Solenoid.h"
//## begin module%3C14B28B02D1.additionalDeclarations preserve=yes
//## end module%3C14B28B02D1.additionalDeclarations


// Class Solenoid 

//## begin Solenoid::ID%3C14B5CD005A.attr preserve=no  public: static int {UAC} UniqueIndex()
const int Solenoid::ID = UniqueIndex();
//## end Solenoid::ID%3C14B5CD005A.attr

//## Operation: Solenoid%3C14B2C20104
Solenoid::Solenoid (const std::string& id, double len, double Bz)
  //## begin Solenoid::Solenoid%3C14B2C20104.initialization preserve=yes
  : SimpleSolenoid(id,new RectangularGeometry(len),new BzField(Bz))
  //## end Solenoid::Solenoid%3C14B2C20104.initialization
{
  //## begin Solenoid::Solenoid%3C14B2C20104.body preserve=yes
  //## end Solenoid::Solenoid%3C14B2C20104.body
}



//## Other Operations (implementation)
//## Operation: RotateY180%3C14B5870009
void Solenoid::RotateY180 ()
{
  //## begin Solenoid::RotateY180%3C14B5870009.body preserve=yes
	BzField& field = GetField();
	field.SetStrength(-field.GetStrength());
  //## end Solenoid::RotateY180%3C14B5870009.body
}

//## Operation: GetType%3C14B5630332
const string& Solenoid::GetType () const
{
  //## begin Solenoid::GetType%3C14B5630332.body preserve=yes
	_TYPESTR(Solenoid);
  //## end Solenoid::GetType%3C14B5630332.body
}

//## Operation: Copy%3C14B572013F
ModelElement* Solenoid::Copy () const
{
  //## begin Solenoid::Copy%3C14B572013F.body preserve=yes
	return new Solenoid(*this);
  //## end Solenoid::Copy%3C14B572013F.body
}

//## Operation: GetIndex%3C14D4E300D5
int Solenoid::GetIndex () const
{
  //## begin Solenoid::GetIndex%3C14D4E300D5.body preserve=yes
	return Solenoid::ID;
  //## end Solenoid::GetIndex%3C14D4E300D5.body
}

//## Operation: PrepareTracker%3C14D7A20130
void Solenoid::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Solenoid::PrepareTracker%3C14D7A20130.body preserve=yes
	_PREPTRACK(aTracker,AcceleratorComponent);
  //## end Solenoid::PrepareTracker%3C14D7A20130.body
}

//## begin module%3C14B28B02D1.epilog preserve=yes
//## end module%3C14B28B02D1.epilog

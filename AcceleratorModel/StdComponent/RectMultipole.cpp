//## begin module%371F50160000.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\RectMultipole.cpp
 * last modified 04/04/01 15:24:07
 */
//## end module%371F50160000.cm

//## begin module%371F50160000.cp preserve=no
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
//## end module%371F50160000.cp

//## Module: RectMultipole%371F50160000; Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\RectMultipole.cpp

//## begin module%371F50160000.includes preserve=yes
//## end module%371F50160000.includes

// RectMultipole
#include "AcceleratorModel/StdComponent/RectMultipole.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"


//## begin module%371F50160000.declarations preserve=no
//## end module%371F50160000.declarations

//## begin module%371F50160000.additionalDeclarations preserve=yes
//## end module%371F50160000.additionalDeclarations


// Class RectMultipole 

//## begin RectMultipole::ID%371F374A0140.attr preserve=no  public: static const int {VA} UniqueIndex()
const int RectMultipole::ID = UniqueIndex();
//## end RectMultipole::ID%371F374A0140.attr


//## Operation: RectMultipole%868526148; C++
RectMultipole::RectMultipole (const string& id, double length, int npole, double b, double r0, bool skew)
  //## begin RectMultipole::RectMultipole%868526148.initialization preserve=yes
  : TAccCompGF<RectangularGeometry,MultipoleField>(id,new RectangularGeometry(length),
		new MultipoleField(npole,b,r0,skew))
  //## end RectMultipole::RectMultipole%868526148.initialization
{
  //## begin RectMultipole::RectMultipole%868526148.body preserve=yes
  //## end RectMultipole::RectMultipole%868526148.body
}

//## Operation: RectMultipole%924771668
RectMultipole::RectMultipole (const string& id, double len, int np, double b, bool skew)
  //## begin RectMultipole::RectMultipole%924771668.initialization preserve=yes
  : TAccCompGF<RectangularGeometry,MultipoleField>(id,new RectangularGeometry(len),
		new MultipoleField(np,b,skew))
  //## end RectMultipole::RectMultipole%924771668.initialization
{
  //## begin RectMultipole::RectMultipole%924771668.body preserve=yes
  //## end RectMultipole::RectMultipole%924771668.body
}



//## Other Operations (implementation)
//## Operation: GetIndex%924771665
int RectMultipole::GetIndex () const
{
  //## begin RectMultipole::GetIndex%924771665.body preserve=yes
	return ID;
  //## end RectMultipole::GetIndex%924771665.body
}

//## Operation: PrepareTracker%924771666
void RectMultipole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin RectMultipole::PrepareTracker%924771666.body preserve=yes
	_PREPTRACK(aTracker,AcceleratorComponent);
  //## end RectMultipole::PrepareTracker%924771666.body
}

//## Operation: RotateY180%924771667
void RectMultipole::RotateY180 ()
{
  //## begin RectMultipole::RotateY180%924771667.body preserve=yes
	GetField().RotateY180();
  //## end RectMultipole::RotateY180%924771667.body
}

//## begin module%371F50160000.epilog preserve=yes
//## end module%371F50160000.epilog

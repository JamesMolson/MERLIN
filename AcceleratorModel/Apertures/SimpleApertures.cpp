//## begin module%3965D20F037E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Apertures\SimpleApertures.cpp
 * last modified 03/04/01 14:20:42
 */
//## end module%3965D20F037E.cm

//## begin module%3965D20F037E.cp preserve=no
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
//## end module%3965D20F037E.cp

//## Module: SimpleApertures%3965D20F037E; Package body
//## Subsystem: Merlin::AcceleratorModel::Apertures%3AC48B8F014A
//## Source file: D:\dev\Merlin\AcceleratorModel\Apertures\SimpleApertures.cpp

//## begin module%3965D20F037E.includes preserve=yes
//## end module%3965D20F037E.includes

// SimpleApertures
#include "AcceleratorModel/Apertures/SimpleApertures.h"
//## begin module%3965D20F037E.declarations preserve=no
//## end module%3965D20F037E.declarations

//## begin module%3965D20F037E.additionalDeclarations preserve=yes
#include "NumericalUtils/NumericalConstants.h"
//## end module%3965D20F037E.additionalDeclarations


// Class RectangularAperture 




//## Other Operations (implementation)
//## Operation: GetRadiusAt%962967923
double RectangularAperture::GetRadiusAt (double phi, double z) const
{
  //## begin RectangularAperture::GetRadiusAt%962967923.body preserve=yes
	//using namespace std;

	if(hh==0 || hw==0)
		return 0;

	const double phi0=atan(hh/hw);
	const double piOverTwo = pi/2.0;

	phi=fmod(phi,piOverTwo)*piOverTwo;

	return phi<phi0 ? hw/cos(phi) : hh/sin(phi);
  //## end RectangularAperture::GetRadiusAt%962967923.body
}

// Class CircularAperture 



//## Other Operations (implementation)
//## Operation: GetRadiusAt%962967916
double CircularAperture::GetRadiusAt (double phi, double z) const
{
  //## begin CircularAperture::GetRadiusAt%962967916.body preserve=yes
	return GetRadius();
  //## end CircularAperture::GetRadiusAt%962967916.body
}

//## begin module%3965D20F037E.epilog preserve=yes
//## end module%3965D20F037E.epilog

//## begin module%37146B2B0154.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\EMField.cpp
 * last modified 03/04/01 13:09:47
 */
//## end module%37146B2B0154.cm

//## begin module%37146B2B0154.cp preserve=no
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
//## end module%37146B2B0154.cp

//## Module: EMField%37146B2B0154; Package body
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: D:\dev\Merlin\AcceleratorModel\EMField.cpp

//## begin module%37146B2B0154.includes preserve=yes
//## end module%37146B2B0154.includes

// EMField
#include "AcceleratorModel/EMField.h"
//## begin module%37146B2B0154.declarations preserve=no
//## end module%37146B2B0154.declarations

//## begin module%37146B2B0154.additionalDeclarations preserve=yes
//## end module%37146B2B0154.additionalDeclarations


// Class EMField 


//## Operation: ~EMField%924021910
EMField::~EMField ()
{
  //## begin EMField::~EMField%924021910.body preserve=yes
	// Nothing to do
  //## end EMField::~EMField%924021910.body
}



//## Other Operations (implementation)
//## Operation: GetForceAt%924021913
Vector3D EMField::GetForceAt (const Point3D& x, const Vector3D& v, double q, double t) const
{
  //## begin EMField::GetForceAt%924021913.body preserve=yes
	Vector3D B = GetBFieldAt(x,t);
	Vector3D E = GetEFieldAt(x,t);
	return q*(E+cross(v,B));
  //## end EMField::GetForceAt%924021913.body
}

//## begin module%37146B2B0154.epilog preserve=yes
//## end module%37146B2B0154.epilog

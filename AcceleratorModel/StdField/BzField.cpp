//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3C14B38C028B.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdField\BzField.cpp
 * last modified 10/12/01 14:24:58
 */
//## end module%3C14B38C028B.cm

//## begin module%3C14B38C028B.cp preserve=no
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
//## end module%3C14B38C028B.cp

//## Module: BzField%3C14B38C028B; Pseudo Package body
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Source file: C:\C++\Merlin\AcceleratorModel\StdField\BzField.cpp

//## begin module%3C14B38C028B.includes preserve=yes
//## end module%3C14B38C028B.includes

// BzField
#include "AcceleratorModel/StdField/BzField.h"
//## begin module%3C14B38C028B.additionalDeclarations preserve=yes
//## end module%3C14B38C028B.additionalDeclarations


// Class BzField 


//## Other Operations (implementation)
//## Operation: GetBFieldAt%3C14B4280126
Vector3D BzField::GetBFieldAt (const Point3D& x, double t) const
{
  //## begin BzField::GetBFieldAt%3C14B4280126.body preserve=yes
	return Vector3D(0,0,Bz);
  //## end BzField::GetBFieldAt%3C14B4280126.body
}

//## Operation: GetEFieldAt%3C14B4280131
Vector3D BzField::GetEFieldAt (const Point3D& x, double t) const
{
  //## begin BzField::GetEFieldAt%3C14B4280131.body preserve=yes
	return Vector3D(0,0,0);
  //## end BzField::GetEFieldAt%3C14B4280131.body
}

//## begin module%3C14B38C028B.epilog preserve=yes
//## end module%3C14B38C028B.epilog

//## begin module%37146B3F0118.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\AcceleratorGeometry.cpp
 * last modified 03/04/01 13:09:47
 */
//## end module%37146B3F0118.cm

//## begin module%37146B3F0118.cp preserve=no
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
//## end module%37146B3F0118.cp

//## Module: AcceleratorGeometry%37146B3F0118; Package body
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: D:\dev\Merlin\AcceleratorModel\AcceleratorGeometry.cpp

//## begin module%37146B3F0118.includes preserve=yes
//## end module%37146B3F0118.includes

// AcceleratorGeometry
#include "AcceleratorModel/AcceleratorGeometry.h"
//## begin module%37146B3F0118.declarations preserve=no
//## end module%37146B3F0118.declarations

//## begin module%37146B3F0118.additionalDeclarations preserve=yes
//## end module%37146B3F0118.additionalDeclarations


// Class AcceleratorGeometry::BeyondExtent 

// Class AcceleratorGeometry 




//## Other Operations (implementation)
//## Operation: GetTotalGeometryTransform%924021906
Transform3D AcceleratorGeometry::GetTotalGeometryTransform () const
{
  //## begin AcceleratorGeometry::GetTotalGeometryTransform%924021906.body preserve=yes
	Extent extnt = GetGeometryExtent();
	return GetGeometryTransform(extnt.first,extnt.second);
  //## end AcceleratorGeometry::GetTotalGeometryTransform%924021906.body
}

//## begin module%37146B3F0118.epilog preserve=yes
//## end module%37146B3F0118.epilog

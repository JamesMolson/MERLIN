//## begin module%396B5F7F028A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Supports\AcceleratorSupport.cpp
 * last modified 28/03/01 17:24:55
 */
//## end module%396B5F7F028A.cm

//## begin module%396B5F7F028A.cp preserve=no
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
//## end module%396B5F7F028A.cp

//## Module: AcceleratorSupport%396B5F7F028A; Package body
//## Subsystem: Merlin::AcceleratorModel::Supports%395B6FFB0186
//## Source file: D:\dev\Merlin\AcceleratorModel\Supports\AcceleratorSupport.cpp

//## begin module%396B5F7F028A.includes preserve=yes
#include <cmath>
//## end module%396B5F7F028A.includes

// AcceleratorSupport
#include "AcceleratorModel/Supports/AcceleratorSupport.h"
//## begin module%396B5F7F028A.declarations preserve=no
//## end module%396B5F7F028A.declarations

//## begin module%396B5F7F028A.additionalDeclarations preserve=yes
using namespace std;
//## end module%396B5F7F028A.additionalDeclarations


// Class AcceleratorSupport 








//## Other Operations (implementation)
//## Operation: DistanceTo%962293965
double AcceleratorSupport::DistanceTo (const AcceleratorSupport& aSupport) const
{
  //## begin AcceleratorSupport::DistanceTo%962293965.body preserve=yes
	Point2D dx = aSupport.pos-pos;
	return sqrt(dx*dx);
  //## end AcceleratorSupport::DistanceTo%962293965.body
}

//## begin module%396B5F7F028A.epilog preserve=yes
//## end module%396B5F7F028A.epilog

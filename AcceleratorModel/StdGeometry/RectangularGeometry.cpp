//## begin module%33772D8B0357.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdGeometry\RectangularGeometry.cpp
 * last modified 03/04/01 13:43:33
 */
//## end module%33772D8B0357.cm

//## begin module%33772D8B0357.cp preserve=no
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
//## end module%33772D8B0357.cp

//## Module: RectangularGeometry%33772D8B0357; Pseudo Package body
//## Subsystem: Merlin::AcceleratorModel::StdGeometry%3AB0A71501AE
//## Source file: D:\dev\Merlin\AcceleratorModel\StdGeometry\RectangularGeometry.cpp

//## begin module%33772D8B0357.includes preserve=yes
//## end module%33772D8B0357.includes

// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"
//## begin module%33772D8B0357.additionalDeclarations preserve=yes
//## end module%33772D8B0357.additionalDeclarations


// Class RectangularGeometry 


//## Other Operations (implementation)
//## Operation: GetGeometryTransform%984653901
//## Exceptions: BeyondExtent
Transform3D RectangularGeometry::GetGeometryTransform (double s0, double s) const throw (BeyondExtent)
{
  //## begin RectangularGeometry::GetGeometryTransform%984653901.body preserve=yes
	CheckBounds(s,s0);
	return Transform3D::translation(0,0,s-s0);
  //## end RectangularGeometry::GetGeometryTransform%984653901.body
}

//## Operation: GetGeometryTransform%984653902
Transform3D RectangularGeometry::GetGeometryTransform (BoundaryPlane p) const
{
  //## begin RectangularGeometry::GetGeometryTransform%984653902.body preserve=yes
	double s = p==entrance ? -len/2 : len/2;
	return Transform3D::translation(0,0,s);
  //## end RectangularGeometry::GetGeometryTransform%984653902.body
}

//## Operation: GetTotalGeometryTransform%984653903
Transform3D RectangularGeometry::GetTotalGeometryTransform () const
{
  //## begin RectangularGeometry::GetTotalGeometryTransform%984653903.body preserve=yes
	return Transform3D::translation(0,0,len);
  //## end RectangularGeometry::GetTotalGeometryTransform%984653903.body
}

//## begin module%33772D8B0357.epilog preserve=yes
//## end module%33772D8B0357.epilog

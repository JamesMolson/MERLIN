//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3AB0A819033E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdGeometry\ArcGeometry.cpp
 * last modified 08/30/01 10:02:55 AM
 */
//## end module%3AB0A819033E.cm

//## begin module%3AB0A819033E.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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
//## end module%3AB0A819033E.cp

//## Module: ArcGeometry%3AB0A819033E; Package body
//## Subsystem: Merlin::AcceleratorModel::StdGeometry%3AB0A71501AE
//## Source file: C:\C++\Merlin\AcceleratorModel\StdGeometry\ArcGeometry.cpp

//## begin module%3AB0A819033E.includes preserve=yes
//## end module%3AB0A819033E.includes

// ArcGeometry
#include "AcceleratorModel/StdGeometry/ArcGeometry.h"
//## begin module%3AB0A819033E.additionalDeclarations preserve=yes
namespace {

	inline Transform3D MakeTransform(double phi, double h)
	{
		return Transform3D(Point3D((cos(phi)-1)/h,0,sin(phi)/h),Rotation3D::rotationY(-phi));
	}

}; // end annonymous namespace

//## end module%3AB0A819033E.additionalDeclarations


// Class ArcGeometry 




//## Other Operations (implementation)
//## Operation: GetGeometryTransform%3AB0AD6A0154
//## Exceptions: BeyondExtent
Transform3D ArcGeometry::GetGeometryTransform (double s0, double s) const throw (BeyondExtent)
{
  //## begin ArcGeometry::GetGeometryTransform%3AB0AD6A0154.body preserve=yes
	CheckBounds(s,s0);
	return MakeTransform((s-s0)*h,h);
  //## end ArcGeometry::GetGeometryTransform%3AB0AD6A0154.body
}

//## Operation: GetGeometryTransform%3AB0AD6A0186
Transform3D ArcGeometry::GetGeometryTransform (BoundaryPlane p) const
{
  //## begin ArcGeometry::GetGeometryTransform%3AB0AD6A0186.body preserve=yes
	double phi = p==entrance ? -GetAngle()/2 : GetAngle()/2;
	return MakeTransform(phi,h);
  //## end ArcGeometry::GetGeometryTransform%3AB0AD6A0186.body
}

//## Operation: GetTotalGeometryTransform%3AB0AD6A01C2
Transform3D ArcGeometry::GetTotalGeometryTransform () const
{
  //## begin ArcGeometry::GetTotalGeometryTransform%3AB0AD6A01C2.body preserve=yes
	return MakeTransform(GetAngle(),h);
  //## end ArcGeometry::GetTotalGeometryTransform%3AB0AD6A01C2.body
}

//## begin module%3AB0A819033E.epilog preserve=yes
//## end module%3AB0A819033E.epilog

//## begin module%38BB9E7F02C6.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file EuclideanGeometry\GeometryObject3D.cpp
 * last modified 29/02/00 18:20:49
 */
//## end module%38BB9E7F02C6.cm

//## begin module%38BB9E7F02C6.cp preserve=no
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
//## end module%38BB9E7F02C6.cp

//## Module: GeometryObject3D%38BB9E7F02C6; Pseudo Package body
//## Subsystem: EuclideanGeometry%33797280015C
//## Source file: D:\Dev\Merlin\EuclideanGeometry\GeometryObject3D.cpp

//## begin module%38BB9E7F02C6.includes preserve=yes
//## end module%38BB9E7F02C6.includes

// GeometryObject3D
#include "EuclideanGeometry/GeometryObject3D.h"
//## begin module%38BB9E7F02C6.additionalDeclarations preserve=yes
//## end module%38BB9E7F02C6.additionalDeclarations


// Class GeometryObject3D 


//## begin module%38BB9E7F02C6.epilog preserve=yes
//## end module%38BB9E7F02C6.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin GeometryObject3D::Rotate%951841375.body preserve=no
	Transform3D t0 = Transform3D::rotationZ(z_angle);
	if(x_angle!=0)
		t0*=Transform3D::rotationX(x_angle);
	if(y_angle!=0)
		t0*Transform3D::rotationY(y_angle);

	t*=t0;
//## end GeometryObject3D::Rotate%951841375.body

#endif

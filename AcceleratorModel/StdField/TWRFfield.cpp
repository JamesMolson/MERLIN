//## begin module%3724284E0258.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdField\TWRFfield.cpp
 * last modified 03/04/01 13:44:20
 */
//## end module%3724284E0258.cm

//## begin module%3724284E0258.cp preserve=no
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
//## end module%3724284E0258.cp

//## Module: TWRFfield%3724284E0258; Pseudo Package body
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Source file: D:\dev\Merlin\AcceleratorModel\StdField\TWRFfield.cpp

//## begin module%3724284E0258.includes preserve=yes
//## end module%3724284E0258.includes

// TWRFfield
#include "AcceleratorModel/StdField/TWRFfield.h"
//## begin module%3724284E0258.additionalDeclarations preserve=yes
//## end module%3724284E0258.additionalDeclarations


// Class TWRFfield 


//## Other Operations (implementation)
//## Operation: GetBFieldAt%925120576
Vector3D TWRFfield::GetBFieldAt (const Point3D& x, double t) const
{
  //## begin TWRFfield::GetBFieldAt%925120576.body preserve=yes
	return Vector3D(0,0,0);
  //## end TWRFfield::GetBFieldAt%925120576.body
}

//## Operation: GetEFieldAt%925120577
Vector3D TWRFfield::GetEFieldAt (const Point3D& x, double t) const
{
  //## begin TWRFfield::GetEFieldAt%925120577.body preserve=yes
	return Vector3D(0,0,TWRFfield::Ez(x.z,t));
  //## end TWRFfield::GetEFieldAt%925120577.body
}

//## Operation: GetForceAt%925120578
Vector3D TWRFfield::GetForceAt (const Point3D& x, const Vector3D& v, double q, double t) const
{
  //## begin TWRFfield::GetForceAt%925120578.body preserve=yes
	return Vector3D(0,0,q*TWRFfield::Ez(x.z,t));
  //## end TWRFfield::GetForceAt%925120578.body
}

//## begin module%3724284E0258.epilog preserve=yes
//## end module%3724284E0258.epilog

//## begin module%372440EC0366.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdField\SWRFfield.cpp
 * last modified 03/04/01 13:44:19
 */
//## end module%372440EC0366.cm

//## begin module%372440EC0366.cp preserve=no
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
//## end module%372440EC0366.cp

//## Module: SWRFfield%372440EC0366; Pseudo Package body
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Source file: D:\dev\Merlin\AcceleratorModel\StdField\SWRFfield.cpp

//## begin module%372440EC0366.includes preserve=yes
//## end module%372440EC0366.includes

// SWRFfield
#include "AcceleratorModel/StdField/SWRFfield.h"
//## begin module%372440EC0366.additionalDeclarations preserve=yes
//## end module%372440EC0366.additionalDeclarations


// Class SWRFfield 


//## Other Operations (implementation)
//## Operation: GetBFieldAt%925120587
Vector3D SWRFfield::GetBFieldAt (const Point3D& x, double t) const
{
  //## begin SWRFfield::GetBFieldAt%925120587.body preserve=yes
	return Vector3D(0,0,0);
  //## end SWRFfield::GetBFieldAt%925120587.body
}

//## Operation: GetEFieldAt%925120588
Vector3D SWRFfield::GetEFieldAt (const Point3D& x, double t) const
{
  //## begin SWRFfield::GetEFieldAt%925120588.body preserve=yes
	return Vector3D(0,0,SWRFfield::Ez(x.z,t));
  //## end SWRFfield::GetEFieldAt%925120588.body
}

//## Operation: GetForceAt%925120589
Vector3D SWRFfield::GetForceAt (const Point3D& x, const Vector3D& v, double q, double t) const
{
  //## begin SWRFfield::GetForceAt%925120589.body preserve=yes
	return Vector3D(0,0,q*SWRFfield::Ez(x.z,t));
  //## end SWRFfield::GetForceAt%925120589.body
}

//## begin module%372440EC0366.epilog preserve=yes
//## end module%372440EC0366.epilog

//## begin module%37146B2301EA.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\EMField.h
 * last modified 03/04/01 13:09:48
 */
//## end module%37146B2301EA.cm

//## begin module%37146B2301EA.cp preserve=no
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
//## end module%37146B2301EA.cp

//## Module: EMField%37146B2301EA; Package specification
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: D:\dev\Merlin\AcceleratorModel\EMField.h

#ifndef EMField_h
#define EMField_h 1

//## begin module%37146B2301EA.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37146B2301EA.additionalIncludes

//## begin module%37146B2301EA.includes preserve=yes
//## end module%37146B2301EA.includes

// Space3D
#include "EuclideanGeometry/Space3D.h"
//## begin module%37146B2301EA.declarations preserve=no
//## end module%37146B2301EA.declarations

//## begin module%37146B2301EA.additionalDeclarations preserve=yes
//## end module%37146B2301EA.additionalDeclarations


//## Class: EMField%36EFAD52027A; Abstract
//	Represents an electro-magnetic field region. The field
//	is defined in a implicit rectangular coordinate frame
//	(x,y,z).
//## Category: Merlin::AcceleratorModel%370B943B0384
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%36EFC2C400D9;Point3D { -> }
//## Uses: <unnamed>%36EFC2C50095;Vector3D { -> }

class EMField 
{
  public:
    //## Destructor (specified)
      //## Operation: ~EMField%924021910
      //	Virtual destructor.
      virtual ~EMField ();


    //## Other Operations (specified)
      //## Operation: GetBFieldAt%924021911
      //	Returns the magnetic field at the point x and time t.
      virtual Vector3D GetBFieldAt (const Point3D& x, double t = 0) const = 0;

      //## Operation: GetEFieldAt%924021912
      //	Returns the electric field at the point x and time t
      virtual Vector3D GetEFieldAt (const Point3D& x, double t = 0) const = 0;

      //## Operation: GetForceAt%924021913
      //	Returns the force due to this field on a particle of
      //	charge q with position x and velocity v at time t.
      virtual Vector3D GetForceAt (const Point3D& x, const Vector3D& v, double q, double t = 0) const;

  protected:
  private:
  private:  //## implementation
};

// Class EMField 

//## begin module%37146B2301EA.epilog preserve=yes
//## end module%37146B2301EA.epilog


#endif

//## begin module%3AC8795900D2.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Aperture.h
 * last modified 03/04/01 13:09:44
 */
//## end module%3AC8795900D2.cm

//## begin module%3AC8795900D2.cp preserve=no
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
//## end module%3AC8795900D2.cp

//## Module: Aperture%3AC8795900D2; Package specification
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: D:\dev\Merlin\AcceleratorModel\Aperture.h

#ifndef Aperture_h
#define Aperture_h 1

//## begin module%3AC8795900D2.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AC8795900D2.additionalIncludes

//## begin module%3AC8795900D2.includes preserve=yes
//## end module%3AC8795900D2.includes

// Space3D
#include "EuclideanGeometry/Space3D.h"
//## begin module%3AC8795900D2.declarations preserve=no
//## end module%3AC8795900D2.declarations

//## begin module%3AC8795900D2.additionalDeclarations preserve=yes
//## end module%3AC8795900D2.additionalDeclarations


//## Class: Aperture%36CD8DF301AE; Abstract
//	Represents the cross section of the vacuum pipe or other
//	collimating aperture.
//## Category: Merlin::AcceleratorModel%370B943B0384
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3965CDB902E1;Point3D { -> }

class Aperture 
{
  public:
    //## Destructor (specified)
      //## Operation: ~Aperture%935667569
      virtual ~Aperture ();


    //## Other Operations (specified)
      //## Operation: PointInside%962967907
      //	Returns true if the point (x,y,z) is within the aperture.
      virtual bool PointInside (double x, double y, double z) const = 0;

      //## Operation: PointInside%962967908
      //	Returns true if the point p is within the aperture.
      bool PointInside (const Point3D& p) const;

      //## Operation: GetRadiusAt%962967909
      //	Returns the radius to the aperture at location z and
      //	angle phi.
      virtual double GetRadiusAt (double phi, double z) const = 0;

  protected:
  private:
  private:  //## implementation
};

// Class Aperture 

//## Operation: ~Aperture%935667569
inline Aperture::~Aperture ()
{
  //## begin Aperture::~Aperture%935667569.body preserve=yes
  //## end Aperture::~Aperture%935667569.body
}



//## Other Operations (inline)
//## Operation: PointInside%962967908
inline bool Aperture::PointInside (const Point3D& p) const
{
  //## begin Aperture::PointInside%962967908.body preserve=yes
	return PointInside(p.x,p.y,p.z);
  //## end Aperture::PointInside%962967908.body
}

// Class Aperture 


//## begin module%3AC8795900D2.epilog preserve=yes
//## end module%3AC8795900D2.epilog


#endif

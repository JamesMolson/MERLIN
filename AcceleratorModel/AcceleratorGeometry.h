//## begin module%37146B36028A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\AcceleratorGeometry.h
 * last modified 03/04/01 13:09:47
 */
//## end module%37146B36028A.cm

//## begin module%37146B36028A.cp preserve=no
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
//## end module%37146B36028A.cp

//## Module: AcceleratorGeometry%37146B36028A; Package specification
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: D:\dev\Merlin\AcceleratorModel\AcceleratorGeometry.h

#ifndef AcceleratorGeometry_h
#define AcceleratorGeometry_h 1

//## begin module%37146B36028A.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37146B36028A.additionalIncludes

//## begin module%37146B36028A.includes preserve=yes
#include <utility>
//## end module%37146B36028A.includes

// Transform3D
#include "EuclideanGeometry/Transform3D.h"
//## begin module%37146B36028A.declarations preserve=no
//## end module%37146B36028A.declarations

//## begin module%37146B36028A.additionalDeclarations preserve=yes
//## end module%37146B36028A.additionalDeclarations


//## Class: AcceleratorGeometry%36EFA5B80344; Abstract
//	Represents a frame of reference for a section of
//	accelerator lattice. An AcceleratorGeometry can be
//	considered a type of three-dimensional space line
//	(R(s)), which is characterised by a single scalar s, the
//	distance along the space line from the origin. Each
//	AcceleratorGeometry has a specific length which bounds
//	the allowed values of s (with respect to the local
//	geometry origin).  At each  position s on the geometry,
//	a local rectangular coordinate frame can be uniquely
//	defined, with its origin at the point s, and its z-axis
//	tangential to the geometry at s. The orientation of the
//	local x- and y-axes are also uniquely determined by the
//	sum of any rotations applied going from the origin to s.
//
//	The primary responsibilty for an AcceleratorGeometry
//	object is to supply transformations between coordinate
//	frames defined on that geometry.
//## Category: Merlin::AcceleratorModel%370B943B0384
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%36EFAAAF0319;Transform3D { -> }
//## Uses: <unnamed>%3713A1160302;AcceleratorGeometry::BeyondExtent { -> F}
//## Uses: <unnamed>%3AB0A1F800E6;AcceleratorGeometry::BoundaryPlane { -> F}

class AcceleratorGeometry 
{
  public:
    //## Class: BeyondExtent%3713A0EA0230
    //	Exception thrown indicating that an s-distance was
    //	outside of the current geometry extent.
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel%371355260226
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class BeyondExtent 
    {
      public:
      protected:
      private:
      private:  //## implementation
    };

    //## Class: Extent%38BC0F6B017C
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef std::pair<double,double> Extent;

    //## Class: BoundaryPlane%3AB0A14D01D6
    //	A BoundaryPlane is the X-Y plane (z=0) of the coordinate
    //	frame defined at the entrance (start) or exit (end) of
    //	the Geometry.
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef enum {entrance,exit} BoundaryPlane;

  public:
    //## Destructor (specified)
      //## Operation: ~AcceleratorGeometry%924072842
      //	Virtual destructor.
      virtual ~AcceleratorGeometry ();


    //## Other Operations (specified)
      //## Operation: GetGeometryTransform%924021905
      //	Return the three-dimensional transformation from the
      //	frame at s0 to the frame at s. s and s0 are in the
      //	geometry's s-frame, and must be within the geometry
      //	extents.
      virtual Transform3D GetGeometryTransform (double s0, double s) const throw (BeyondExtent) = 0;

      //## Operation: GetGeometryTransform%985850580
      //	Return the three-dimensional transformation from the
      //	local origin to the frame at s. s is  in the geometry's
      //	s-frame, and must be within the geometry extents.
      Transform3D GetGeometryTransform (double s) const throw (BeyondExtent);

      //## Operation: GetGeometryTransform%984653900
      //	Returns the transformation from the geometry origin to
      //	the specified boundary plane.
      virtual Transform3D GetGeometryTransform (BoundaryPlane p) const = 0;

      //## Operation: GetTotalGeometryTransform%924021906
      //	Returns the transformation from the entrance plane frame
      //	to the exit plane frame.
      virtual Transform3D GetTotalGeometryTransform () const;

      //## Operation: GetGeometryExtent%924021907
      //	Returns the local extent of this geometry.
      virtual Extent GetGeometryExtent () const = 0;

      //## Operation: GetGeometryLength%924021908
      //	Returns the total arc-length of the geometry.
      virtual double GetGeometryLength () const = 0;

  protected:
  private:
  private:  //## implementation
};

// Class AcceleratorGeometry::BeyondExtent 

// Class AcceleratorGeometry 

//## Operation: ~AcceleratorGeometry%924072842
inline AcceleratorGeometry::~AcceleratorGeometry ()
{
  //## begin AcceleratorGeometry::~AcceleratorGeometry%924072842.body preserve=yes
  //## end AcceleratorGeometry::~AcceleratorGeometry%924072842.body
}



//## Other Operations (inline)
//## Operation: GetGeometryTransform%985850580
//## Exceptions: BeyondExtent
inline Transform3D AcceleratorGeometry::GetGeometryTransform (double s) const throw (BeyondExtent)
{
  //## begin AcceleratorGeometry::GetGeometryTransform%985850580.body preserve=yes
	return GetGeometryTransform(0,s);
  //## end AcceleratorGeometry::GetGeometryTransform%985850580.body
}

//## begin module%37146B36028A.epilog preserve=yes
inline double ToLength(const AcceleratorGeometry::Extent& extent)
{
	return extent.second-extent.first;
}
//## end module%37146B36028A.epilog


#endif

//## begin module%33772D8B0357.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdGeometry\RectangularGeometry.h
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

//## Module: RectangularGeometry%33772D8B0357; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdGeometry%3AB0A71501AE
//## Source file: D:\dev\Merlin\AcceleratorModel\StdGeometry\RectangularGeometry.h

#ifndef RectangularGeometry_h
#define RectangularGeometry_h 1

//## begin module%33772D8B0357.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%33772D8B0357.additionalIncludes

//## begin module%33772D8B0357.includes preserve=yes
//## end module%33772D8B0357.includes

// CenteredGeometry
#include "AcceleratorModel/StdGeometry/CenteredGeometry.h"
//## begin module%33772D8B0357.additionalDeclarations preserve=yes
//## end module%33772D8B0357.additionalDeclarations


//## Class: RectangularGeometry%33772D8B0357
//	Represents a straight line segment. Transformations from
//	points on a RectangularGeometry are pure translations
//	along the z-axis.
//## Category: Merlin::AcceleratorModel::StdGeometry%337727B1003C
//## Subsystem: Merlin::AcceleratorModel::StdGeometry%3AB0A71501AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class RectangularGeometry : public CenteredGeometry  //## Inherits: <unnamed>%371DD51D0190
{
  public:
    //## Constructors (specified)
      //## Operation: RectangularGeometry%867411289
      //	Constructor taking the length of the rectangular
      //	geometry (total z extent).
      RectangularGeometry (double l);


    //## Other Operations (specified)
      //## Operation: GetGeometryTransform%984653901
      //	Returns a translation along the z-axis of (s-s0).
      virtual Transform3D GetGeometryTransform (double s0, double s) const throw (BeyondExtent);

      //## Operation: GetGeometryTransform%984653902
      //	Returns a translation along the z-axis of either +l/2 or
      //	-l/2 for the entrance and exit boundary planes
      //	respectively.
      virtual Transform3D GetGeometryTransform (BoundaryPlane p) const;

      //## Operation: GetTotalGeometryTransform%984653903
      //	Returns a translation along the z-axis of +l.
      virtual Transform3D GetTotalGeometryTransform () const;

  protected:
  private:
  private:  //## implementation
};

// Class RectangularGeometry 

//## Operation: RectangularGeometry%867411289
inline RectangularGeometry::RectangularGeometry (double l)
  //## begin RectangularGeometry::RectangularGeometry%867411289.initialization preserve=yes
  :CenteredGeometry(l)
  //## end RectangularGeometry::RectangularGeometry%867411289.initialization
{
  //## begin RectangularGeometry::RectangularGeometry%867411289.body preserve=yes
  //## end RectangularGeometry::RectangularGeometry%867411289.body
}


//## begin module%33772D8B0357.epilog preserve=yes
//## end module%33772D8B0357.epilog


#endif

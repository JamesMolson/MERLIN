//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3AB0A7FE00D2.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdGeometry\ArcGeometry.h
 * last modified 08/30/01 10:02:55 AM
 */
//## end module%3AB0A7FE00D2.cm

//## begin module%3AB0A7FE00D2.cp preserve=no
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
//## end module%3AB0A7FE00D2.cp

//## Module: ArcGeometry%3AB0A7FE00D2; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdGeometry%3AB0A71501AE
//## Source file: C:\C++\Merlin\AcceleratorModel\StdGeometry\ArcGeometry.h

#ifndef ArcGeometry_h
#define ArcGeometry_h 1

//## begin module%3AB0A7FE00D2.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AB0A7FE00D2.additionalIncludes

//## begin module%3AB0A7FE00D2.includes preserve=yes
//## end module%3AB0A7FE00D2.includes

// CenteredGeometry
#include "AcceleratorModel/StdGeometry/CenteredGeometry.h"
//## begin module%3AB0A7FE00D2.additionalDeclarations preserve=yes
//## end module%3AB0A7FE00D2.additionalDeclarations


//## Class: ArcGeometry%33772DA201AC
//	An ArcGeometry represents a constant radius curve in the
//	local x-z plane. By convention, a positive curvature (h)
//	defines a curve towards negative x. Transformations
//	between two points (s1,s2) on an ArcGeometry are
//	specified by a translation in the x-z plane of
//	[(cos(phi)-1)/h, 0, sin(phi)/h], and a rotation about
//	the y-axis of -phi (phi = h*(s2-s1)).
//
//	An ArcGeometry can have an additional tilt, which is
//	defined as a rotation about the local z-axis of the
//	entrance plane by an angle theta, with an additional
//	rotation about the exit plane z-axis by -theta.
//## Category: Merlin::AcceleratorModel::StdGeometry%337727B1003C
//## Subsystem: Merlin::AcceleratorModel::StdGeometry%3AB0A71501AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ArcGeometry : public CenteredGeometry  //## Inherits: <unnamed>%371DD5200244
{
  public:
    //## Constructors (specified)
      //## Operation: ArcGeometry%3383F89B0204; C++
      //	Constructor taking the arc length and the curvature
      //	(1/r) of the geometry.
      ArcGeometry (double l, double curv);


    //## Other Operations (specified)
      //## Operation: GetCurvature%3378221101DC; C++
      //	Return the curvature of the ArcGeometry.
      double GetCurvature () const;

      //## Operation: GetAngle%337822DC0288; C++
      //	Return the total arc angle of the geometry.
      double GetAngle () const;

      //## Operation: GetGeometryTransform%3AB0AD6A0154
      //	Returns the arc transform from s0 to s (angle=h*(s-s0)).
      virtual Transform3D GetGeometryTransform (double s0, double s) const throw (BeyondExtent);

      //## Operation: GetGeometryTransform%3AB0AD6A0186
      //	Returns the arc transform for either -angle/2 or
      //	+angle/2 for the entrance and exit planes respectively.
      virtual Transform3D GetGeometryTransform (BoundaryPlane p) const;

      //## Operation: GetTotalGeometryTransform%3AB0AD6A01C2
      //	Returns the arc transformation from the entrance plane
      //	frame to the exit plane frame.
      virtual Transform3D GetTotalGeometryTransform () const;

      //## Operation: SetCurvature%3AB8B6570280
      //	Sets the curvature (=1/r) of the arc.
      void SetCurvature (double curv);

      //## Operation: SetTilt%3B8DF28700E6
      //	Sets the tilt of the geomety in radians.
      void SetTilt (double t);

      //## Operation: GetTilt%3B8DF29101B2
      //	Returns the tilt of the geometry in radians.
      double GetTilt () const;

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: h%33772E3C03B6
      //## begin ArcGeometry::h%33772E3C03B6.attr preserve=no  private: double {UA} 
      double h;
      //## end ArcGeometry::h%33772E3C03B6.attr

      //## Attribute: tilt%3B8DF21302A2
      //## begin ArcGeometry::tilt%3B8DF21302A2.attr preserve=no  private: double {UA} 
      double tilt;
      //## end ArcGeometry::tilt%3B8DF21302A2.attr

  private: //## implementation
};

// Class ArcGeometry 

//## Operation: ArcGeometry%3383F89B0204; C++
//## Qualification: inline
inline ArcGeometry::ArcGeometry (double l, double curv)
  //## begin ArcGeometry::ArcGeometry%3383F89B0204.initialization preserve=yes
  : CenteredGeometry(l),h(curv),tilt(0)
  //## end ArcGeometry::ArcGeometry%3383F89B0204.initialization
{
  //## begin ArcGeometry::ArcGeometry%3383F89B0204.body preserve=yes
  //## end ArcGeometry::ArcGeometry%3383F89B0204.body
}



//## Other Operations (inline)
//## Operation: GetCurvature%3378221101DC; C++
//## Qualification: const inline
inline double ArcGeometry::GetCurvature () const
{
  //## begin ArcGeometry::GetCurvature%3378221101DC.body preserve=yes
	return h;
  //## end ArcGeometry::GetCurvature%3378221101DC.body
}

//## Operation: GetAngle%337822DC0288; C++
//## Qualification: const inline
//## Semantics:
//	return h*len;
inline double ArcGeometry::GetAngle () const
{
  //## begin ArcGeometry::GetAngle%337822DC0288.body preserve=yes
	return len*h;
  //## end ArcGeometry::GetAngle%337822DC0288.body
}

//## Operation: SetCurvature%3AB8B6570280
inline void ArcGeometry::SetCurvature (double curv)
{
  //## begin ArcGeometry::SetCurvature%3AB8B6570280.body preserve=yes
	h=curv;
  //## end ArcGeometry::SetCurvature%3AB8B6570280.body
}

//## Operation: SetTilt%3B8DF28700E6
inline void ArcGeometry::SetTilt (double t)
{
  //## begin ArcGeometry::SetTilt%3B8DF28700E6.body preserve=yes
	tilt=t;
  //## end ArcGeometry::SetTilt%3B8DF28700E6.body
}

//## Operation: GetTilt%3B8DF29101B2
inline double ArcGeometry::GetTilt () const
{
  //## begin ArcGeometry::GetTilt%3B8DF29101B2.body preserve=yes
	return tilt;
  //## end ArcGeometry::GetTilt%3B8DF29101B2.body
}

//## begin module%3AB0A7FE00D2.epilog preserve=yes
//## end module%3AB0A7FE00D2.epilog


#endif

//## begin module%38BB9E7F02C6.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file EuclideanGeometry\GeometryObject3D.h
 * last modified 29/02/00 20:38:22
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

//## Module: GeometryObject3D%38BB9E7F02C6; Pseudo Package specification
//## Subsystem: EuclideanGeometry%33797280015C
//## Source file: D:\Dev\Merlin\EuclideanGeometry\GeometryObject3D.h

#ifndef GeometryObject3D_h
#define GeometryObject3D_h 1

//## begin module%38BB9E7F02C6.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%38BB9E7F02C6.additionalIncludes

//## begin module%38BB9E7F02C6.includes preserve=yes
//## end module%38BB9E7F02C6.includes

// Transform3D
#include "EuclideanGeometry/Transform3D.h"
//## begin module%38BB9E7F02C6.additionalDeclarations preserve=yes
//## end module%38BB9E7F02C6.additionalDeclarations


//## Class: GeometryObject3D%38BB9E7F02C6; Abstract
//	A mixin class which represents an geometric entity which
//	can be rotated and translated with respect to some
//	(implicit) reference frame.
//## Category: EuclideanGeometry%3625FD0E0014; Global
//## Subsystem: EuclideanGeometry%33797280015C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%38BBFD740050;Transform3D { -> }

class GeometryObject3D 
{
  public:
    //## Destructor (specified)
      //## Operation: ~GeometryObject3D%951841373
      //	Virtual constructor.
      virtual ~GeometryObject3D ();


    //## Other Operations (specified)
      //## Operation: Translate%951841374
      //	Translate the object by the relative vector (dx,dy,dz).
      void Translate (double dx, double dy, double dz);

      //## Operation: RotateX%951841382
      //	Rotates the object about the current x-axis by angle.
      void RotateX (double angle);

      //## Operation: RotateY%951841383
      //	Rotates the object about the current y-axis by angle.
      void RotateY (double angle);

      //## Operation: RotateZ%951841384
      //	Rotates the object about the current z-axis by angle.
      void RotateZ (double angle);

      //## Operation: ApplyTransformation%951841376
      //	Transform the object (with respect to the current axes)
      //	by the transformation t.
      void ApplyTransformation (const Transform3D& t1);

      //## Operation: ClearTransformation%951841377
      //	Clear all transformations.
      void ClearTransformation ();

      //## Operation: SetTransformation%951841378
      //	Set the absolute transformation for this object.
      void SetTransformation (const Transform3D& t1);

      //## Operation: GetTransformation%951841379
      //	Return the current transformation.
      const Transform3D& GetTransformation () const;

      //## Operation: IsTransformed%951841380
      //	Returns true if this object has been transformed.
      bool IsTransformed () const;

  protected:
    //## Constructors (specified)
      //## Operation: GeometryObject3D%951841381
      //	Protected constructor taking the initial transformation.
      explicit GeometryObject3D (const Transform3D& t0 = Transform3D());


    //## Other Operations (specified)
      //## Operation: HasChanged%951848914
      //	Virtual function used to notify derived classes that the
      //	state of the transformation has changed. Default action
      //	does nothing.
      virtual void HasChanged () const;

  private:
    // Data Members for Class Attributes

      //## Attribute: t%38BBFC840262
      //## begin GeometryObject3D::t%38BBFC840262.attr preserve=no  private: Transform3D {UA} 
      Transform3D t;
      //## end GeometryObject3D::t%38BBFC840262.attr

  private:  //## implementation
};

// Class GeometryObject3D 

//## Operation: GeometryObject3D%951841381
inline GeometryObject3D::GeometryObject3D (const Transform3D& t0)
  //## begin GeometryObject3D::GeometryObject3D%951841381.initialization preserve=yes
  : t(t0)
  //## end GeometryObject3D::GeometryObject3D%951841381.initialization
{
  //## begin GeometryObject3D::GeometryObject3D%951841381.body preserve=yes
  //## end GeometryObject3D::GeometryObject3D%951841381.body
}


//## Operation: ~GeometryObject3D%951841373
inline GeometryObject3D::~GeometryObject3D ()
{
  //## begin GeometryObject3D::~GeometryObject3D%951841373.body preserve=yes
  //## end GeometryObject3D::~GeometryObject3D%951841373.body
}



//## Other Operations (inline)
//## Operation: Translate%951841374
inline void GeometryObject3D::Translate (double dx, double dy, double dz)
{
  //## begin GeometryObject3D::Translate%951841374.body preserve=yes
	t*=Transform3D::translation(dx,dy,dz);
	HasChanged();
  //## end GeometryObject3D::Translate%951841374.body
}

//## Operation: RotateX%951841382
inline void GeometryObject3D::RotateX (double angle)
{
  //## begin GeometryObject3D::RotateX%951841382.body preserve=yes
	t*=Transform3D::rotationX(angle);
	HasChanged();
  //## end GeometryObject3D::RotateX%951841382.body
}

//## Operation: RotateY%951841383
inline void GeometryObject3D::RotateY (double angle)
{
  //## begin GeometryObject3D::RotateY%951841383.body preserve=yes
	t*=Transform3D::rotationY(angle);
	HasChanged();
  //## end GeometryObject3D::RotateY%951841383.body
}

//## Operation: RotateZ%951841384
inline void GeometryObject3D::RotateZ (double angle)
{
  //## begin GeometryObject3D::RotateZ%951841384.body preserve=yes
	t*=Transform3D::rotationZ(angle);
	HasChanged();
  //## end GeometryObject3D::RotateZ%951841384.body
}

//## Operation: ApplyTransformation%951841376
inline void GeometryObject3D::ApplyTransformation (const Transform3D& t1)
{
  //## begin GeometryObject3D::ApplyTransformation%951841376.body preserve=yes
	t*=t1;
	HasChanged();
  //## end GeometryObject3D::ApplyTransformation%951841376.body
}

//## Operation: ClearTransformation%951841377
inline void GeometryObject3D::ClearTransformation ()
{
  //## begin GeometryObject3D::ClearTransformation%951841377.body preserve=yes
	t=Transform3D();
	HasChanged();
  //## end GeometryObject3D::ClearTransformation%951841377.body
}

//## Operation: SetTransformation%951841378
inline void GeometryObject3D::SetTransformation (const Transform3D& t1)
{
  //## begin GeometryObject3D::SetTransformation%951841378.body preserve=yes
	t=t1;
	HasChanged();
  //## end GeometryObject3D::SetTransformation%951841378.body
}

//## Operation: GetTransformation%951841379
inline const Transform3D& GeometryObject3D::GetTransformation () const
{
  //## begin GeometryObject3D::GetTransformation%951841379.body preserve=yes
	return t;
  //## end GeometryObject3D::GetTransformation%951841379.body
}

//## Operation: IsTransformed%951841380
inline bool GeometryObject3D::IsTransformed () const
{
  //## begin GeometryObject3D::IsTransformed%951841380.body preserve=yes
	return !t.isIdentity();
  //## end GeometryObject3D::IsTransformed%951841380.body
}

//## Operation: HasChanged%951848914
inline void GeometryObject3D::HasChanged () const
{
  //## begin GeometryObject3D::HasChanged%951848914.body preserve=yes
  //## end GeometryObject3D::HasChanged%951848914.body
}

// Class GeometryObject3D 


//## begin module%38BB9E7F02C6.epilog preserve=yes
//## end module%38BB9E7F02C6.epilog


#endif

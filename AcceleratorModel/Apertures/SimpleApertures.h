//## begin module%3965D20D0140.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Apertures\SimpleApertures.h
 * last modified 03/04/01 14:20:43
 */
//## end module%3965D20D0140.cm

//## begin module%3965D20D0140.cp preserve=no
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
//## end module%3965D20D0140.cp

//## Module: SimpleApertures%3965D20D0140; Package specification
//## Subsystem: Merlin::AcceleratorModel::Apertures%3AC48B8F014A
//## Source file: D:\dev\Merlin\AcceleratorModel\Apertures\SimpleApertures.h

#ifndef SimpleApertures_h
#define SimpleApertures_h 1

//## begin module%3965D20D0140.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3965D20D0140.additionalIncludes

//## begin module%3965D20D0140.includes preserve=yes
#include <cmath>
//## end module%3965D20D0140.includes

// Aperture
#include "AcceleratorModel/Aperture.h"
//## begin module%3965D20D0140.declarations preserve=no
//## end module%3965D20D0140.declarations

//## begin module%3965D20D0140.additionalDeclarations preserve=yes
//## end module%3965D20D0140.additionalDeclarations


//## Class: RectangularAperture%3965CF1C00D9
//	Represents an aperture with a rectangular cross-section.
//	The aperture is assumed symmetric about the axis, and
//	extruded along its geometry.
//## Category: Merlin::AcceleratorModel::Apertures%3AC48AB900B4
//## Subsystem: Merlin::AcceleratorModel::Apertures%3AC48B8F014A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class RectangularAperture : public Aperture  //## Inherits: <unnamed>%3965CF3100A7
{
  public:
    //## Constructors (specified)
      //## Operation: RectangularAperture%962967917
      RectangularAperture (double width, double height);


    //## Other Operations (specified)
      //## Operation: GetFullWidth%962967918
      double GetFullWidth () const;

      //## Operation: GetFullHeight%962967919
      double GetFullHeight () const;

      //## Operation: SetFullWidth%962967920
      void SetFullWidth (double w);

      //## Operation: SetFullHeight%962967921
      void SetFullHeight (double h);

      //## Operation: PointInside%962967922
      //	Returns true if the point (x,y,z) is within the
      //	aperture. The z coordinate is ignored.
      virtual bool PointInside (double x, double y, double z) const;

      //## Operation: GetRadiusAt%962967923
      //	Returns the radius to the aperture at the angle phi. The
      //	z coordinate is ignored.
      virtual double GetRadiusAt (double phi, double z) const;

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: hw%3965CFA20367
      //## begin RectangularAperture::hw%3965CFA20367.attr preserve=no  private: double {UA} 
      double hw;
      //## end RectangularAperture::hw%3965CFA20367.attr

      //## Attribute: hh%3965CFA902A9
      //## begin RectangularAperture::hh%3965CFA902A9.attr preserve=no  private: double {UA} 
      double hh;
      //## end RectangularAperture::hh%3965CFA902A9.attr

  private:  //## implementation
};

//## Class: CircularAperture%3965CF260264
//	Represents an aperture with a circular cross-section.
//	The aperture is assumed to be extruded along its
//	geometry.
//## Category: Merlin::AcceleratorModel::Apertures%3AC48AB900B4
//## Subsystem: Merlin::AcceleratorModel::Apertures%3AC48B8F014A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CircularAperture : public Aperture  //## Inherits: <unnamed>%3965CF3303D5
{
  public:
    //## Constructors (specified)
      //## Operation: CircularAperture%962967910
      explicit CircularAperture (double r);


    //## Other Operations (specified)
      //## Operation: GetRadius%962967911
      double GetRadius () const;

      //## Operation: GetDiameter%962967912
      double GetDiameter () const;

      //## Operation: SetRadius%962967913
      void SetRadius (double r);

      //## Operation: SetDiameter%962967914
      void SetDiameter (double d);

      //## Operation: PointInside%962967915
      //	Returns true if the point (x,y,z) is within the
      //	aperture. The z coordinate is ignored.
      virtual bool PointInside (double x, double y, double z) const;

      //## Operation: GetRadiusAt%962967916
      //	Returns the radius.
      virtual double GetRadiusAt (double phi, double z) const;

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: r2%3965D0D003A7
      //## begin CircularAperture::r2%3965D0D003A7.attr preserve=no  private: double {UA} 
      double r2;
      //## end CircularAperture::r2%3965D0D003A7.attr

  private:  //## implementation
};

// Class RectangularAperture 

//## Operation: RectangularAperture%962967917
inline RectangularAperture::RectangularAperture (double width, double height)
  //## begin RectangularAperture::RectangularAperture%962967917.initialization preserve=yes
  :hw(fabs(width)/2),hh(fabs(height)/2)
  //## end RectangularAperture::RectangularAperture%962967917.initialization
{
  //## begin RectangularAperture::RectangularAperture%962967917.body preserve=yes
  //## end RectangularAperture::RectangularAperture%962967917.body
}



//## Other Operations (inline)
//## Operation: GetFullWidth%962967918
inline double RectangularAperture::GetFullWidth () const
{
  //## begin RectangularAperture::GetFullWidth%962967918.body preserve=yes
	return 2*hw;
  //## end RectangularAperture::GetFullWidth%962967918.body
}

//## Operation: GetFullHeight%962967919
inline double RectangularAperture::GetFullHeight () const
{
  //## begin RectangularAperture::GetFullHeight%962967919.body preserve=yes
	return 2*hh;
  //## end RectangularAperture::GetFullHeight%962967919.body
}

//## Operation: SetFullWidth%962967920
inline void RectangularAperture::SetFullWidth (double w)
{
  //## begin RectangularAperture::SetFullWidth%962967920.body preserve=yes
	hw=fabs(w)/2;
  //## end RectangularAperture::SetFullWidth%962967920.body
}

//## Operation: SetFullHeight%962967921
inline void RectangularAperture::SetFullHeight (double h)
{
  //## begin RectangularAperture::SetFullHeight%962967921.body preserve=yes
	hh=fabs(h)/2;
  //## end RectangularAperture::SetFullHeight%962967921.body
}

//## Operation: PointInside%962967922
inline bool RectangularAperture::PointInside (double x, double y, double z) const
{
  //## begin RectangularAperture::PointInside%962967922.body preserve=yes
	return fabs(x)<hw && fabs(y)<hh;
  //## end RectangularAperture::PointInside%962967922.body
}

// Class CircularAperture 

//## Operation: CircularAperture%962967910
inline CircularAperture::CircularAperture (double r)
  //## begin CircularAperture::CircularAperture%962967910.initialization preserve=yes
  : r2(r*r)
  //## end CircularAperture::CircularAperture%962967910.initialization
{
  //## begin CircularAperture::CircularAperture%962967910.body preserve=yes
  //## end CircularAperture::CircularAperture%962967910.body
}



//## Other Operations (inline)
//## Operation: GetRadius%962967911
inline double CircularAperture::GetRadius () const
{
  //## begin CircularAperture::GetRadius%962967911.body preserve=yes
	return sqrt(r2);
  //## end CircularAperture::GetRadius%962967911.body
}

//## Operation: GetDiameter%962967912
inline double CircularAperture::GetDiameter () const
{
  //## begin CircularAperture::GetDiameter%962967912.body preserve=yes
	return 2*GetRadius();
  //## end CircularAperture::GetDiameter%962967912.body
}

//## Operation: SetRadius%962967913
inline void CircularAperture::SetRadius (double r)
{
  //## begin CircularAperture::SetRadius%962967913.body preserve=yes
	r2=r*r;
  //## end CircularAperture::SetRadius%962967913.body
}

//## Operation: SetDiameter%962967914
inline void CircularAperture::SetDiameter (double d)
{
  //## begin CircularAperture::SetDiameter%962967914.body preserve=yes
	r2=d*d/4.0;
  //## end CircularAperture::SetDiameter%962967914.body
}

//## Operation: PointInside%962967915
inline bool CircularAperture::PointInside (double x, double y, double z) const
{
  //## begin CircularAperture::PointInside%962967915.body preserve=yes
	return x*x+y*y<r2;
  //## end CircularAperture::PointInside%962967915.body
}

//## begin module%3965D20D0140.epilog preserve=yes
//## end module%3965D20D0140.epilog


#endif

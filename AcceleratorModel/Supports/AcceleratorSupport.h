//## begin module%396B5F7C02B2.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Supports\AcceleratorSupport.h
 * last modified 28/03/01 17:24:56
 */
//## end module%396B5F7C02B2.cm

//## begin module%396B5F7C02B2.cp preserve=no
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
//## end module%396B5F7C02B2.cp

//## Module: AcceleratorSupport%396B5F7C02B2; Package specification
//## Subsystem: Merlin::AcceleratorModel::Supports%395B6FFB0186
//## Source file: D:\dev\Merlin\AcceleratorModel\Supports\AcceleratorSupport.h

#ifndef AcceleratorSupport_h
#define AcceleratorSupport_h 1

//## begin module%396B5F7C02B2.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%396B5F7C02B2.additionalIncludes

//## begin module%396B5F7C02B2.includes preserve=yes
#include <vector>
//## end module%396B5F7C02B2.includes

// Space2D
#include "EuclideanGeometry/Space2D.h"
// Space3D
#include "EuclideanGeometry/Space3D.h"
//## begin module%396B5F7C02B2.declarations preserve=no
//## end module%396B5F7C02B2.declarations

//## begin module%396B5F7C02B2.additionalDeclarations preserve=yes
//## end module%396B5F7C02B2.additionalDeclarations


//## Class: AcceleratorSupport%395B5FED0280
//	Represents a single support structure. Support can be
//	translated in either x, y or z directions. Support is
//	primarily intended for ground motion application.
//## Category: Merlin::AcceleratorModel::Supports%3AB8BC620154
//## Subsystem: Merlin::AcceleratorModel::Supports%395B6FFB0186
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%396B64ED0366;Point2D { -> }
//## Uses: <unnamed>%396B65020050;Vector3D { -> }

class AcceleratorSupport 
{
  public:
    //## Constructors (specified)
      //## Operation: AcceleratorSupport%962293961
      AcceleratorSupport ();


    //## Other Operations (specified)
      //## Operation: SetPosition%962293962
      //	Sets the location of the support in the global
      //	coordinate frame. (x,z) represent the location in the
      //	accelerator plane, while s is the arc position of the
      //	support.
      void SetPosition (double s, double x, double z);

      //## Operation: GetArcPosition%962293963
      //	Returns the arc position.
      double GetArcPosition () const;

      //## Operation: GetLocation%962293964
      //	Returns the location of the support in the accelerator
      //	plane (x,z). Note that  Point2D::y here refers to the
      //	z-coordinate.
      Point2D GetLocation () const;

      //## Operation: DistanceTo%962293965
      //	Returns the linear distance from this support to a
      //	Support.
      double DistanceTo (const AcceleratorSupport& aSupport) const;

      //## Operation: SetOffset%962293966
      //	Set the support offset to (x,y,z).
      void SetOffset (double x, double y, double z);

      //## Operation: SetOffset%962293967
      //	Set the support offset to X
      void SetOffset (const Vector3D& X);

      //## Operation: GetOffset%962293968
      //	Returns the current offset.
      const Vector3D& GetOffset () const;

      //## Operation: IncrementOffset%962293969
      //	Increment the current offset by (dx,dy,dz),
      const Vector3D& IncrementOffset (double dx, double dy, double dz);

      //## Operation: IncrementOffset%962293970
      //	Increment the current offset by dX.
      const Vector3D& IncrementOffset (const Vector3D& dX);

      //## Operation: Reset%962293971
      //	Reset the offset to (0,0,0).
      void Reset ();

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: offset%395B60B70334
      //## begin AcceleratorSupport::offset%395B60B70334.attr preserve=no  private: Vector3D {UA} 
      Vector3D offset;
      //## end AcceleratorSupport::offset%395B60B70334.attr

      //## Attribute: modified%395B60CC0320
      //## begin AcceleratorSupport::modified%395B60CC0320.attr preserve=no  private: bool {UA} 
      bool modified;
      //## end AcceleratorSupport::modified%395B60CC0320.attr

      //## Attribute: pos%395B6F7F00C8
      //## begin AcceleratorSupport::pos%395B6F7F00C8.attr preserve=no  private: Point2D {UA} 
      Point2D pos;
      //## end AcceleratorSupport::pos%395B6F7F00C8.attr

      //## Attribute: s_pos%395B6F950186
      //## begin AcceleratorSupport::s_pos%395B6F950186.attr preserve=no  private: double {UA} 
      double s_pos;
      //## end AcceleratorSupport::s_pos%395B6F950186.attr

  private:  //## implementation
    friend class SupportStructure;
};

//## Class: AcceleratorSupportList%395B630A000A
//	An array of AcceleratorSupport pointers.
//## Category: Merlin::AcceleratorModel::Supports%3AB8BC620154
//## Subsystem: Merlin::AcceleratorModel::Supports%395B6FFB0186
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AC2023D0212;AcceleratorSupport { -> }

typedef std::vector<AcceleratorSupport*> AcceleratorSupportList;

// Class AcceleratorSupport 

//## Operation: AcceleratorSupport%962293961
inline AcceleratorSupport::AcceleratorSupport ()
  //## begin AcceleratorSupport::AcceleratorSupport%962293961.initialization preserve=yes
  :offset(0,0,0),modified(false),pos(0,0),s_pos(0)
  //## end AcceleratorSupport::AcceleratorSupport%962293961.initialization
{
  //## begin AcceleratorSupport::AcceleratorSupport%962293961.body preserve=yes
  //## end AcceleratorSupport::AcceleratorSupport%962293961.body
}



//## Other Operations (inline)
//## Operation: SetPosition%962293962
inline void AcceleratorSupport::SetPosition (double s, double x, double z)
{
  //## begin AcceleratorSupport::SetPosition%962293962.body preserve=yes
	pos.x=x;
	pos.y=z;
	s_pos=s;
  //## end AcceleratorSupport::SetPosition%962293962.body
}

//## Operation: GetArcPosition%962293963
inline double AcceleratorSupport::GetArcPosition () const
{
  //## begin AcceleratorSupport::GetArcPosition%962293963.body preserve=yes
	return s_pos;
  //## end AcceleratorSupport::GetArcPosition%962293963.body
}

//## Operation: GetLocation%962293964
inline Point2D AcceleratorSupport::GetLocation () const
{
  //## begin AcceleratorSupport::GetLocation%962293964.body preserve=yes
	return pos;
  //## end AcceleratorSupport::GetLocation%962293964.body
}

//## Operation: SetOffset%962293966
inline void AcceleratorSupport::SetOffset (double x, double y, double z)
{
  //## begin AcceleratorSupport::SetOffset%962293966.body preserve=yes
	SetOffset(Vector3D(x,y,z));
  //## end AcceleratorSupport::SetOffset%962293966.body
}

//## Operation: SetOffset%962293967
inline void AcceleratorSupport::SetOffset (const Vector3D& X)
{
  //## begin AcceleratorSupport::SetOffset%962293967.body preserve=yes
	offset=X;
	modified=true;
  //## end AcceleratorSupport::SetOffset%962293967.body
}

//## Operation: GetOffset%962293968
inline const Vector3D& AcceleratorSupport::GetOffset () const
{
  //## begin AcceleratorSupport::GetOffset%962293968.body preserve=yes
	return offset;
  //## end AcceleratorSupport::GetOffset%962293968.body
}

//## Operation: IncrementOffset%962293969
inline const Vector3D& AcceleratorSupport::IncrementOffset (double dx, double dy, double dz)
{
  //## begin AcceleratorSupport::IncrementOffset%962293969.body preserve=yes
	return IncrementOffset(Vector3D(dx,dy,dz));
  //## end AcceleratorSupport::IncrementOffset%962293969.body
}

//## Operation: IncrementOffset%962293970
inline const Vector3D& AcceleratorSupport::IncrementOffset (const Vector3D& dX)
{
  //## begin AcceleratorSupport::IncrementOffset%962293970.body preserve=yes
	modified=true;
	return offset+=dX;
  //## end AcceleratorSupport::IncrementOffset%962293970.body
}

//## Operation: Reset%962293971
inline void AcceleratorSupport::Reset ()
{
  //## begin AcceleratorSupport::Reset%962293971.body preserve=yes
	modified=true;
	offset=Vector3D(0,0,0);
  //## end AcceleratorSupport::Reset%962293971.body
}

//## begin module%396B5F7C02B2.epilog preserve=yes
//## end module%396B5F7C02B2.epilog


#endif

//## begin module%3957AC4D02A8.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Supports\MagnetMover.h
 * last modified 26/03/01 11:54:35
 */
//## end module%3957AC4D02A8.cm

//## begin module%3957AC4D02A8.cp preserve=no
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
//## end module%3957AC4D02A8.cp

//## Module: MagnetMover%3957AC4D02A8; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::Supports%3AB8BC620154
//## Source file: D:\dev\Merlin\AcceleratorModel\Supports\MagnetMover.h

#ifndef MagnetMover_h
#define MagnetMover_h 1

//## begin module%3957AC4D02A8.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3957AC4D02A8.additionalIncludes

//## begin module%3957AC4D02A8.includes preserve=yes
//## end module%3957AC4D02A8.includes

// SequenceFrame
#include "AcceleratorModel/Frames/SequenceFrame.h"
// Transform2D
#include "EuclideanGeometry/Transform2D.h"
//## begin module%3957AC4D02A8.additionalDeclarations preserve=yes
//## end module%3957AC4D02A8.additionalDeclarations


//## Class: MagnetMover%3957AC4D02A8
//	Represents a mechanical magnet mover, or a remotely
//	translatable stage.  A magnet mover can effectively
//	apply a 2-D transformation with respect to its local
//	reference frame. The transformation is characterised by
//	a rotation about the local z-axis (roll) followed by a
//	translation in the (x-y) plane.
//
//	The local coordinate frame can be rotated and translated
//	using the methods inherited from LatticeFrame. The
//	additional 2-D mover transformations are in addition to
//	any local (3-D) frame modification. In this way, magnet
//	mover alignment errors can be simulated.
//## Category: Merlin::AcceleratorModel::Supports%3AB8BC620154
//## Subsystem: Merlin::AcceleratorModel::Supports%3AB8BC620154
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class MagnetMover : public SequenceFrame  //## Inherits: <unnamed>%3AB8BF4800DC
{
  public:
    //## Constructors (specified)
      //## Operation: MagnetMover%962031292
      //	Constructor taking the name of the mover, and the Lattice
      //	Frame which the mover adjusts.
      explicit MagnetMover (const string& id);


    //## Other Operations (specified)
      //## Operation: GetX%962031293
      //	Returns the horizontal displacement in meters.
      double GetX () const;

      //## Operation: GetY%962031294
      //	Returns the vertical displacement in meters.
      double GetY () const;

      //## Operation: GetRoll%962031295
      //	Returns the roll angle about the local entrance z-axis
      //	in radians.
      double GetRoll () const;

      //## Operation: SetX%962031296
      //	Sets the horizontal offset in meters.
      void SetX (double x);

      //## Operation: SetY%962031297
      //	Sets the vertical offset in meters.
      void SetY (double y);

      //## Operation: SetRoll%962031298
      //	Sets the roll angle in radians.
      void SetRoll (double roll);

      //## Operation: Reset%962031299
      //	Resets the mover to zero.
      void Reset ();

      //## Operation: GetType%962031300
      //	Returns "MagnetMover".
      virtual const string& GetType () const;

      //## Operation: Copy%962031301
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

      //## Operation: GetLocalFrameTransform%985600393
      //	Returns the total frame transformation, i.e. the
      //	combined transformation of the local frame transforms
      //	and the x, y and roll  mover adjustments.
      virtual Transform3D GetLocalFrameTransform () const;

  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::ComplexGeometry::class details::<unnamed>%3957AF9102F8
      //## Role: MagnetMover::t%3957AF9200FA
      //## begin MagnetMover::t%3957AF9200FA.role preserve=no  private: Transform2D { -> 1VHAN}
      Transform2D t;
      //## end MagnetMover::t%3957AF9200FA.role

  private:  //## implementation
};

// Class MagnetMover 

//## Operation: MagnetMover%962031292
inline MagnetMover::MagnetMover (const string& id)
  //## begin MagnetMover::MagnetMover%962031292.initialization preserve=yes
  : SequenceFrame(id)
  //## end MagnetMover::MagnetMover%962031292.initialization
{
  //## begin MagnetMover::MagnetMover%962031292.body preserve=yes
  //## end MagnetMover::MagnetMover%962031292.body
}



//## Other Operations (inline)
//## Operation: GetX%962031293
inline double MagnetMover::GetX () const
{
  //## begin MagnetMover::GetX%962031293.body preserve=yes
	return t.translation().x;
  //## end MagnetMover::GetX%962031293.body
}

//## Operation: GetY%962031294
inline double MagnetMover::GetY () const
{
  //## begin MagnetMover::GetY%962031294.body preserve=yes
	return t.translation().y;
  //## end MagnetMover::GetY%962031294.body
}

//## Operation: GetRoll%962031295
inline double MagnetMover::GetRoll () const
{
  //## begin MagnetMover::GetRoll%962031295.body preserve=yes
	return t.rotationAngle();
  //## end MagnetMover::GetRoll%962031295.body
}

//## Operation: SetX%962031296
inline void MagnetMover::SetX (double x)
{
  //## begin MagnetMover::SetX%962031296.body preserve=yes
	t.setTranslationX(x);
  //## end MagnetMover::SetX%962031296.body
}

//## Operation: SetY%962031297
inline void MagnetMover::SetY (double y)
{
  //## begin MagnetMover::SetY%962031297.body preserve=yes
	t.setTranslationY(y);
  //## end MagnetMover::SetY%962031297.body
}

//## Operation: SetRoll%962031298
inline void MagnetMover::SetRoll (double roll)
{
  //## begin MagnetMover::SetRoll%962031298.body preserve=yes
	t.setRotation(roll);
  //## end MagnetMover::SetRoll%962031298.body
}

//## Operation: Reset%962031299
inline void MagnetMover::Reset ()
{
  //## begin MagnetMover::Reset%962031299.body preserve=yes
	t=Transform2D();
  //## end MagnetMover::Reset%962031299.body
}

//## begin module%3957AC4D02A8.epilog preserve=yes
//## end module%3957AC4D02A8.epilog


#endif

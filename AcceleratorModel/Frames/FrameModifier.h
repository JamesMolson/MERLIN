//## begin module%3AB8C9CC00AA.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Frames\FrameModifier.h
 * last modified 21/03/01 17:09:32
 */
//## end module%3AB8C9CC00AA.cm

//## begin module%3AB8C9CC00AA.cp preserve=no
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
//## end module%3AB8C9CC00AA.cp

//## Module: FrameModifier%3AB8C9CC00AA; Package specification
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Source file: D:\dev\Merlin\AcceleratorModel\Frames\FrameModifier.h

#ifndef FrameModifier_h
#define FrameModifier_h 1

//## begin module%3AB8C9CC00AA.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AB8C9CC00AA.additionalIncludes

//## begin module%3AB8C9CC00AA.includes preserve=yes
//## end module%3AB8C9CC00AA.includes

// LatticeFrame
#include "AcceleratorModel/Frames/LatticeFrame.h"
//## begin module%3AB8C9CC00AA.declarations preserve=no
//## end module%3AB8C9CC00AA.declarations

//## begin module%3AB8C9CC00AA.additionalDeclarations preserve=yes
//## end module%3AB8C9CC00AA.additionalDeclarations


//## Class: FrameModifier%3AB8C1F90398
//	A utility class which adds an additional layer to the
//	frame hierachy, and thus another level of coordinate
//	transformations. FrameModifier effectively "wraps" a
//	single LatticeFrame object. It can insert and remove
//	itself in the lattice frame hierachy.
//## Category: Merlin::AcceleratorModel::Frames%3AB0B5BC015E
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class FrameModifier : public LatticeFrame  //## Inherits: <unnamed>%3AB8C226012C
{
  public:
    //## Constructors (specified)
      //## Operation: FrameModifier%985182999
      //	Constructor taking the LatticeFrame object above which
      //	this is to be inserted.
      explicit FrameModifier (LatticeFrame* frame);


    //## Other Operations (specified)
      //## Operation: Copy%985183000
      //	Returns a copy of the sub-frame.
      ModelElement* Copy () const;

      //## Operation: GetType%985183001
      //	Returns the type string of the sub-frame.
      const string& GetType () const;

      //## Operation: Invalidate%985183004
      //	Causes any cached state to be invalidated. The cached
      //	state should be re-calculated if and when required.
      virtual void Invalidate () const;

      //## Operation: ConsolidateConstruction%985183005
      //	Function called after construction of the Accelerator
      //	Model is complete. Allows the nested frame hierachy to
      //	perform certain state checks and updates, which are only
      //	possible once the entire model is complete.
      virtual void ConsolidateConstruction ();

  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Frames::<unnamed>%3AB8CB030032
      //## Role: FrameModifier::subFrame%3AB8CB080064
      //## begin FrameModifier::subFrame%3AB8CB080064.role preserve=no  private: LatticeFrame { -> RHAN}
      LatticeFrame* subFrame;
      //## end FrameModifier::subFrame%3AB8CB080064.role

  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: IsBoundaryPlane%985183003
      virtual bool IsBoundaryPlane (BoundaryPlane p, const LatticeFrame* aSubFrame) const;

};

// Class FrameModifier 

//## begin module%3AB8C9CC00AA.epilog preserve=yes
//## end module%3AB8C9CC00AA.epilog


#endif

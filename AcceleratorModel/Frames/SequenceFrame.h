//## begin module%3AB2348400A0.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Frames\SequenceFrame.h
 * last modified 21/03/01 16:20:32
 */
//## end module%3AB2348400A0.cm

//## begin module%3AB2348400A0.cp preserve=no
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
//## end module%3AB2348400A0.cp

//## Module: SequenceFrame%3AB2348400A0; Package specification
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Source file: D:\dev\Merlin\AcceleratorModel\Frames\SequenceFrame.h

#ifndef SequenceFrame_h
#define SequenceFrame_h 1

//## begin module%3AB2348400A0.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AB2348400A0.additionalIncludes

//## begin module%3AB2348400A0.includes preserve=yes
#include <list>
//## end module%3AB2348400A0.includes

// LatticeFrame
#include "AcceleratorModel/Frames/LatticeFrame.h"

class SequenceGeometry;

//## begin module%3AB2348400A0.declarations preserve=no
//## end module%3AB2348400A0.declarations

//## begin module%3AB2348400A0.additionalDeclarations preserve=yes
#define DEF_SEQUENCE_LABEL "<UNNAMED>"
//## end module%3AB2348400A0.additionalDeclarations


//## Class: SequenceFrame%38BBB025014A
//	A  LatticeFrame object which is composed of a contiguous
//	sequence of other (sub-)LatticeFrame objects.
//## Category: Merlin::AcceleratorModel::Frames%3AB0B5BC015E
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%38BC2D8600FA;deleter { -> }
//## Uses: <unnamed>%396C7E9A0024;SequenceFrame::Origin { -> F}

class SequenceFrame : public LatticeFrame  //## Inherits: <unnamed>%3AB09BC70384
{
  public:
    //## Class: Origin%396C7E8C036D
    //	Enumeration constants which define location of origin
    //	for this frame.
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef enum {originAtEntrance,originAtCenter,originAtExit} Origin;

    //## Class: FrameList%3AB22F590226
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef std::list<LatticeFrame*> FrameList;

  public:
	  virtual void Traverse(FrameTraverser& ft);
    //## Constructors (specified)
      //## Operation: SequenceFrame%951848945
      explicit SequenceFrame (const string& id = DEF_SEQUENCE_LABEL, Origin originLoc = originAtCenter);

      //## Operation: SequenceFrame%956820766
      //	Copy constructor
      SequenceFrame (const SequenceFrame& rhs);

    //## Destructor (specified)
      //## Operation: ~SequenceFrame%951848934
      virtual ~SequenceFrame ();


    //## Other Operations (specified)
      //## Operation: AppendFrame%951848935
      //	Sequence construction: append aFrame to the sequence.
      void AppendFrame (LatticeFrame& aFrame);

      //## Operation: ConsolidateConstruction%962031290
      //	Function called after construction of the Accelerator
      //	Model is complete. Allows the nested frame hierachy to
      //	perform certain state checks and updates, which are only
      //	possible once the entire model is complete.
      virtual void ConsolidateConstruction ();

      //## Operation: Invalidate%962313325
      //	Causes any cached state to be invalidated. The cached
      //	state should be re-calculated if and when required.
      virtual void Invalidate () const;

      //## Operation: Copy%956754080
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

      //## Operation: ReplaceSubFrame%985182998
      //	Replace subFrame with newSubFrame. Returns true if
      //	successful (i.e. subFrame is a sub-frame of this Lattice
      //	Frame).
      virtual bool ReplaceSubFrame (LatticeFrame* subFrame, LatticeFrame* newSubFrame);

      //## Operation: GetType%956754081
      //	Return the type string for the element.
      virtual const string& GetType () const;

  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::ComplexGeometry::<unnamed>%38BBB0880168
      //## Role: SequenceFrame::subFrames%38BBB08C0029
      //## Constraints:
      //	ordered
      //## begin SequenceFrame::subFrames%38BBB08C0029.role preserve=no  private: LatticeFrame { -> 0..nVHOAN}
      //## end SequenceFrame::subFrames%38BBB08C0029.role

      //## Association: Merlin::AcceleratorModel::Frames::<unnamed>%3AB22F8902D0
      //## Role: SequenceFrame::subFrames%3AB22F8A01AE
      //## begin SequenceFrame::subFrames%3AB22F8A01AE.role preserve=no  private: SequenceFrame::FrameList { -> 1VHAN}
      FrameList subFrames;
      //## end SequenceFrame::subFrames%3AB22F8A01AE.role

  private:  //## implementation
    //## Assignment Operation (generated)
      const SequenceFrame & operator=(const SequenceFrame &right);


    //## Other Operations (specified)
      //## Operation: CopySubFrames%956820768
      //	Copies the subframes from frames.
      void CopySubFrames (const list<LatticeFrame*>& frames);

      //## Operation: IsBoundaryPlane%984757504
      //	Returns true if aSubFrame is the first (entrance)
      //	sub-frame of this frame.
      virtual bool IsBoundaryPlane (BoundaryPlane p, const LatticeFrame* aSubFrame) const;

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Frames::<unnamed>%3AB22D75010E
      //## Role: SequenceFrame::itsSeqGeom%3AB22D7600D2
      //## begin SequenceFrame::itsSeqGeom%3AB22D7600D2.role preserve=no  implementation: SequenceGeometry { -> 0..1VFHAN}
      SequenceGeometry* itsSeqGeom;
      //## end SequenceFrame::itsSeqGeom%3AB22D7600D2.role

};

// Class SequenceFrame 

//## begin module%3AB2348400A0.epilog preserve=yes
//## end module%3AB2348400A0.epilog


#endif

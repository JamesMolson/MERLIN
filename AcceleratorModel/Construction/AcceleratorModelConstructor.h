//## begin module%39084BAD0178.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Construction\AcceleratorModelConstructor.h
 * last modified 03/04/01 14:50:57
 */
//## end module%39084BAD0178.cm

//## begin module%39084BAD0178.cp preserve=no
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
//## end module%39084BAD0178.cp

//## Module: AcceleratorModelConstructor%39084BAD0178; Package specification
//## Subsystem: Merlin::AcceleratorModel::Construction%3AC8765A000A
//## Source file: D:\dev\Merlin\AcceleratorModel\Construction\AcceleratorModelConstructor.h

#ifndef AcceleratorModelConstructor_h
#define AcceleratorModelConstructor_h 1

//## begin module%39084BAD0178.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%39084BAD0178.additionalIncludes

//## begin module%39084BAD0178.includes preserve=yes
#include <stack>
//## end module%39084BAD0178.includes

// TComponentFrame
#include "AcceleratorModel/Frames/TComponentFrame.h"
// AcceleratorModel
#include "AcceleratorModel/AcceleratorModel.h"

class SequenceFrame;

//## begin module%39084BAD0178.declarations preserve=no
//## end module%39084BAD0178.declarations

//## begin module%39084BAD0178.additionalDeclarations preserve=yes
//## end module%39084BAD0178.additionalDeclarations


//## Class: AcceleratorModelConstructor%3908332D031D
//	Responsible for constructing an AcceleratorModel object.
//	The nested frame hierachy is constructed internally
//	using a frame stack: each call to NewFrame(aFrame)
//	pushes the current frame onto the stack, and makes the
//	new frame the current frame. A subsequent call to End
//	Frame(aFrame) causes the current frame (aFrame) to be
//	popped from the stack. At any time between calls to New
//	Frame and EndFrame can AppendComponent be called.
//## Category: Merlin::AcceleratorModel::Construction%3AC875BD0208
//## Subsystem: Merlin::AcceleratorModel::Construction%3AC8765A000A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3908369B0077;TComponentFrame { -> }
//## Uses: <unnamed>%3908386F007A;SequenceFrame { -> F}
//## Uses: <unnamed>%39083C200281;Drift { -> }

class AcceleratorModelConstructor 
{
  public:
    //## Class: FrameStack%3AC875FC038E; Instantiated Class
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: <unnamed>%3AC876170302;SequenceFrame { -> F}

    typedef std::stack< SequenceFrame* > FrameStack;

  public:
    //## Constructors (specified)
      //## Operation: AcceleratorModelConstructor%956820806
      AcceleratorModelConstructor ();

    //## Destructor (specified)
      //## Operation: ~AcceleratorModelConstructor%956820807
      ~AcceleratorModelConstructor ();


    //## Other Operations (specified)
      //## Operation: NewModel%956820796
      //	Initialises a new AcceleratorModel. Must be called
      //	before any subsequent constructor calls.
      void NewModel ();

      //## Operation: GetModel%956820797
      //	Ends the current model construction and returns the
      //	model. The model must be in a valid (complete) state.
      AcceleratorModel* GetModel ();

      //## Operation: NewFrame%956820798
      //	Begin construction of a new LatticeFrame.
      void NewFrame (SequenceFrame* aFrame);

      //## Operation: EndFrame%956820799
      //	Finish construction of the specified frame.
      void EndFrame ();

      //## Operation: AppendComponent%956820800
      //	Append the specified component a distance d meters
      //	downstream of the last component.
      template<class T> void AppendComponent (T& acc, double d = 0)
      {
        //## begin AcceleratorModelConstructor::AppendComponent%956820800.body preserve=yes
		if(d!=0) 
			AppendDrift(d);
		AppendComponentFrame(new TComponentFrame<T>(acc));
        //## end AcceleratorModelConstructor::AppendComponent%956820800.body
      }

	  template<class T> void AppendComponent(T* acc, double d=0)
	  {
		 AppendComponent(*acc,d);
	  }

	  // Append an entire SequenceFrame (or derivative) to the current model.
	  // This function allows complex structures (eg. girders) which have
	  // been externally constructed to placed in the current model
	  void AppendFrame(SequenceFrame* aFrame);

      //## Operation: GetCurrentFrame%956820801
      //	Returns a const reference to the current frame.
      SequenceFrame& GetCurrentFrame () const
      {
        //## begin AcceleratorModelConstructor::GetCurrentFrame%956820801.body preserve=yes
		return *(frameStack.top());
        //## end AcceleratorModelConstructor::GetCurrentFrame%956820801.body
      }

      //## Operation: GetCurrentFrameDepth%956820802
      //	Returns the depth of the current frame. 0 refers to the
      //	global frame (top level).
      int GetCurrentFrameDepth () const
      {
        //## begin AcceleratorModelConstructor::GetCurrentFrameDepth%956820802.body preserve=yes
		return frameStack.size()-1;
        //## end AcceleratorModelConstructor::GetCurrentFrameDepth%956820802.body
      }

      //## Operation: AppendDrift%956820803
      //	Appends a simple drift to the current model.
      void AppendDrift (double d);

      //## Operation: AddModelElement%985183006
      //	Adds a ModelElement to the Accelerator Model.
      void AddModelElement (ModelElement* element);

      //## Operation: ReportStatistics%956820805
      //	Prints a table to os  containing statistics on the type
      //	and number of ModelElement current contained in the
      //	model.
      void ReportStatistics (std::ostream& os) const;

  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Construction::<unnamed>%3908335102F7
      //## Role: AcceleratorModelConstructor::currentModel%39083352019A
      //## begin AcceleratorModelConstructor::currentModel%39083352019A.role preserve=no  private: AcceleratorModel { -> RHAN}
      AcceleratorModel* currentModel;
      //## end AcceleratorModelConstructor::currentModel%39083352019A.role

  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: AppendComponentFrame%956820804
      void AppendComponentFrame (ComponentFrame* cf);

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Construction::<unnamed>%3AC8752802DA
      //## Role: AcceleratorModelConstructor::frameStack%3AC875290226
      //## begin AcceleratorModelConstructor::frameStack%3AC875290226.role preserve=no  implementation: AcceleratorModelConstructor::FrameStack { -> 1VHAN}
      FrameStack frameStack;
      //## end AcceleratorModelConstructor::frameStack%3AC875290226.role

};

//## begin module%39084BAD0178.epilog preserve=yes
//## end module%39084BAD0178.epilog


#endif

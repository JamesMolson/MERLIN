//## begin module%3AB7B51E00E6.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Frames\ComponentFrame.h
 * last modified 21/03/01 16:36:57
 */
//## end module%3AB7B51E00E6.cm

//## begin module%3AB7B51E00E6.cp preserve=no
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
//## end module%3AB7B51E00E6.cp

//## Module: ComponentFrame%3AB7B51E00E6; Package specification
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Source file: D:\dev\Merlin\AcceleratorModel\Frames\ComponentFrame.h

#ifndef ComponentFrame_h
#define ComponentFrame_h 1

//## begin module%3AB7B51E00E6.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AB7B51E00E6.additionalIncludes

//## begin module%3AB7B51E00E6.includes preserve=yes
//## end module%3AB7B51E00E6.includes

// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"
// LatticeFrame
#include "AcceleratorModel/Frames/LatticeFrame.h"
//## begin module%3AB7B51E00E6.declarations preserve=no
//## end module%3AB7B51E00E6.declarations

//## begin module%3AB7B51E00E6.additionalDeclarations preserve=yes
//## end module%3AB7B51E00E6.additionalDeclarations


//## Class: ComponentFrame%38BBB03A0172
//	An atomic LatticeFrame object which represents a single
//	instance of an AcceleratorComponent in a beamline.
//## Category: Merlin::AcceleratorModel::Frames%3AB0B5BC015E
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ComponentFrame : public LatticeFrame  //## Inherits: <unnamed>%3AB09BCC0082
{
  public:
    //## Constructors (specified)
      //## Operation: ComponentFrame%951848916
      //	Constructor taking the associated AcceleratorComponent
      //	object.
      explicit ComponentFrame (AcceleratorComponent& ac, const string& id = "");

      //## Operation: ComponentFrame%956820763
      //	Copy constructor.
      ComponentFrame (const ComponentFrame& rhs);

    //## Destructor (specified)
      //## Operation: ~ComponentFrame%951848917
      virtual ~ComponentFrame ();


    //## Other Operations (specified)
      //## Operation: GetComponent%951848918
      AcceleratorComponent& GetComponent ();

      //## Operation: GetComponent%951848919
      const AcceleratorComponent& GetComponent () const;

      //## Operation: Invalidate%951848929
      //	Causes any cached state to be invalidated. The cached
      //	state should be re-calculated if and when required.
      virtual void Invalidate () const;

      //## Operation: GetName%956754078
      //	Return the name of the element. Returns the name of the
      //	AcceleratorComponent if the label for this frame has not
      //	been explicitely set.
      virtual const string& GetName () const;

      //## Operation: GetType%956754079
      //	Returns the type of the referenced AcceleratorComponent.
      virtual const string& GetType () const;

      //## Operation: Copy%956754077
      //	Returns a copy of this ComponentFrame. Note that only
      //	the reference to the AcceleratorComponent is copied, not
      //	the AcceleratorComponent itself.
      virtual ModelElement* Copy () const;

  protected:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::ComplexGeometry::<unnamed>%38BBB05D0316
      //## Role: ComponentFrame::theComponent%38BBB05E02DA
      //## begin ComponentFrame::theComponent%38BBB05E02DA.role preserve=no  protected: AcceleratorComponent { -> 1RHAN}
      AcceleratorComponent* theComponent;
      //## end ComponentFrame::theComponent%38BBB05E02DA.role

  private:
  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: IsBoundaryPlane%985116519
      //	Should  never be called.
      virtual bool IsBoundaryPlane (BoundaryPlane p, const LatticeFrame* aSubFrame) const;

};

// Class ComponentFrame 

//## Operation: ComponentFrame%951848916
inline ComponentFrame::ComponentFrame (AcceleratorComponent& ac, const string& id)
  //## begin ComponentFrame::ComponentFrame%951848916.initialization preserve=yes
  : LatticeFrame(id.empty()?ac.GetName():id),theComponent(&ac)
  //## end ComponentFrame::ComponentFrame%951848916.initialization
{
  //## begin ComponentFrame::ComponentFrame%951848916.body preserve=yes
	SetGeometry(theComponent->GetGeometry());
  //## end ComponentFrame::ComponentFrame%951848916.body
}

//## Operation: ComponentFrame%956820763
inline ComponentFrame::ComponentFrame (const ComponentFrame& rhs)
  //## begin ComponentFrame::ComponentFrame%956820763.initialization preserve=yes
  : LatticeFrame(rhs),theComponent(rhs.theComponent)
  //## end ComponentFrame::ComponentFrame%956820763.initialization
{
  //## begin ComponentFrame::ComponentFrame%956820763.body preserve=yes
  //## end ComponentFrame::ComponentFrame%956820763.body
}



//## Other Operations (inline)
//## Operation: GetComponent%951848918
inline AcceleratorComponent& ComponentFrame::GetComponent ()
{
  //## begin ComponentFrame::GetComponent%951848918.body preserve=yes
	return *theComponent;
  //## end ComponentFrame::GetComponent%951848918.body
}

//## Operation: GetComponent%951848919
inline const AcceleratorComponent& ComponentFrame::GetComponent () const
{
  //## begin ComponentFrame::GetComponent%951848919.body preserve=yes
	return *theComponent;
  //## end ComponentFrame::GetComponent%951848919.body
}

//## Operation: GetName%956754078
inline const string& ComponentFrame::GetName () const
{
  //## begin ComponentFrame::GetName%956754078.body preserve=yes
	const string& id = LatticeFrame::GetName();
	return (id.length()!=0)? id : (theComponent->GetName());
  //## end ComponentFrame::GetName%956754078.body
}

//## begin module%3AB7B51E00E6.epilog preserve=yes
//## end module%3AB7B51E00E6.epilog


#endif

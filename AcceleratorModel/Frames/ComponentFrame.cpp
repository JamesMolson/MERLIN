//## begin module%3AB7B52003D4.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Frames\ComponentFrame.cpp
 * last modified 21/03/01 16:36:57
 */
//## end module%3AB7B52003D4.cm

//## begin module%3AB7B52003D4.cp preserve=no
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
//## end module%3AB7B52003D4.cp

//## Module: ComponentFrame%3AB7B52003D4; Package body
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Source file: D:\dev\Merlin\AcceleratorModel\Frames\ComponentFrame.cpp

//## begin module%3AB7B52003D4.includes preserve=yes
//## end module%3AB7B52003D4.includes

// ComponentFrame
#include "AcceleratorModel/Frames/ComponentFrame.h"
//## begin module%3AB7B52003D4.declarations preserve=no
//## end module%3AB7B52003D4.declarations

//## begin module%3AB7B52003D4.additionalDeclarations preserve=yes
//## end module%3AB7B52003D4.additionalDeclarations


// Class ComponentFrame 



//## Operation: ~ComponentFrame%951848917
ComponentFrame::~ComponentFrame ()
{
  //## begin ComponentFrame::~ComponentFrame%951848917.body preserve=yes
  //## end ComponentFrame::~ComponentFrame%951848917.body
}



//## Other Operations (implementation)
//## Operation: Invalidate%951848929
void ComponentFrame::Invalidate () const
{
  //## begin ComponentFrame::Invalidate%951848929.body preserve=yes
  //## end ComponentFrame::Invalidate%951848929.body
}

//## Operation: GetType%956754079
const string& ComponentFrame::GetType () const
{
  //## begin ComponentFrame::GetType%956754079.body preserve=yes
	_TYPESTR(ComponentFrame);
  //## end ComponentFrame::GetType%956754079.body
}

//## Operation: Copy%956754077
ModelElement* ComponentFrame::Copy () const
{
  //## begin ComponentFrame::Copy%956754077.body preserve=yes
	return new ComponentFrame(*this);
  //## end ComponentFrame::Copy%956754077.body
}

//## Operation: IsBoundaryPlane%985116519
bool ComponentFrame::IsBoundaryPlane (BoundaryPlane p, const LatticeFrame* aSubFrame) const
{
  //## begin ComponentFrame::IsBoundaryPlane%985116519.body preserve=yes
	// Should never be called!
	assert(false);
	return false;
  //## end ComponentFrame::IsBoundaryPlane%985116519.body
}

//## begin module%3AB7B52003D4.epilog preserve=yes
//## end module%3AB7B52003D4.epilog

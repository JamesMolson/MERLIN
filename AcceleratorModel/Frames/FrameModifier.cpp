//## begin module%3AB8C9CE02EE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Frames\FrameModifier.cpp
 * last modified 21/03/01 17:09:32
 */
//## end module%3AB8C9CE02EE.cm

//## begin module%3AB8C9CE02EE.cp preserve=no
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
//## end module%3AB8C9CE02EE.cp

//## Module: FrameModifier%3AB8C9CE02EE; Package body
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Source file: D:\dev\Merlin\AcceleratorModel\Frames\FrameModifier.cpp

//## begin module%3AB8C9CE02EE.includes preserve=yes
//## end module%3AB8C9CE02EE.includes

// FrameModifier
#include "AcceleratorModel/Frames/FrameModifier.h"
//## begin module%3AB8C9CE02EE.declarations preserve=no
//## end module%3AB8C9CE02EE.declarations

//## begin module%3AB8C9CE02EE.additionalDeclarations preserve=yes
//## end module%3AB8C9CE02EE.additionalDeclarations


// Class FrameModifier 



//## Operation: FrameModifier%985182999
FrameModifier::FrameModifier (LatticeFrame* frame)
  //## begin FrameModifier::FrameModifier%985182999.initialization preserve=yes
  : LatticeFrame(),subFrame(frame)
  //## end FrameModifier::FrameModifier%985182999.initialization
{
  //## begin FrameModifier::FrameModifier%985182999.body preserve=yes
	LatticeFrame* oldSuperFrame = frame->SetSuperFrame(this);
	if(oldSuperFrame)
		oldSuperFrame->ReplaceSubFrame(frame,this);

	SetGeometry(frame->GetGeometry());
  //## end FrameModifier::FrameModifier%985182999.body
}



//## Other Operations (implementation)
//## Operation: Copy%985183000
ModelElement* FrameModifier::Copy () const
{
  //## begin FrameModifier::Copy%985183000.body preserve=yes
	return subFrame->Copy();
  //## end FrameModifier::Copy%985183000.body
}

//## Operation: GetType%985183001
const string& FrameModifier::GetType () const
{
  //## begin FrameModifier::GetType%985183001.body preserve=yes
	return subFrame->GetType();
  //## end FrameModifier::GetType%985183001.body
}

//## Operation: Invalidate%985183004
void FrameModifier::Invalidate () const
{
  //## begin FrameModifier::Invalidate%985183004.body preserve=yes
	subFrame->Invalidate();
  //## end FrameModifier::Invalidate%985183004.body
}

//## Operation: IsBoundaryPlane%985183003
bool FrameModifier::IsBoundaryPlane (BoundaryPlane p, const LatticeFrame* aSubFrame) const
{
  //## begin FrameModifier::IsBoundaryPlane%985183003.body preserve=yes
	assert(aSubFrame==subFrame);
	return true;
  //## end FrameModifier::IsBoundaryPlane%985183003.body
}

//## Operation: ConsolidateConstruction%985183005
void FrameModifier::ConsolidateConstruction ()
{
  //## begin FrameModifier::ConsolidateConstruction%985183005.body preserve=yes
	subFrame->SetLocalPosition(0);
  //## end FrameModifier::ConsolidateConstruction%985183005.body
}

//## begin module%3AB8C9CE02EE.epilog preserve=yes
//## end module%3AB8C9CE02EE.epilog

//## begin module%3957AC4D02A8.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Supports\MagnetMover.cpp
 * last modified 26/03/01 11:54:36
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

//## Module: MagnetMover%3957AC4D02A8; Pseudo Package body
//## Subsystem: Merlin::AcceleratorModel::Supports%3AB8BC620154
//## Source file: D:\dev\Merlin\AcceleratorModel\Supports\MagnetMover.cpp

//## begin module%3957AC4D02A8.includes preserve=yes
//## end module%3957AC4D02A8.includes

// MagnetMover
#include "AcceleratorModel/Supports/MagnetMover.h"
//## begin module%3957AC4D02A8.additionalDeclarations preserve=yes
//## end module%3957AC4D02A8.additionalDeclarations


// Class MagnetMover 



//## Other Operations (implementation)
//## Operation: GetType%962031300
const string& MagnetMover::GetType () const
{
  //## begin MagnetMover::GetType%962031300.body preserve=yes
	_TYPESTR(MagnetMover);
  //## end MagnetMover::GetType%962031300.body
}

//## Operation: Copy%962031301
ModelElement* MagnetMover::Copy () const
{
  //## begin MagnetMover::Copy%962031301.body preserve=yes
	// Not sure what to do here!
	assert(false);
	return 0;
  //## end MagnetMover::Copy%962031301.body
}

//## Operation: GetLocalFrameTransform%985600393
Transform3D MagnetMover::GetLocalFrameTransform () const
{
  //## begin MagnetMover::GetLocalFrameTransform%985600393.body preserve=yes
	return Transform3D(t)*LatticeFrame::GetLocalFrameTransform();
  //## end MagnetMover::GetLocalFrameTransform%985600393.body
}

//## begin module%3957AC4D02A8.epilog preserve=yes
//## end module%3957AC4D02A8.epilog

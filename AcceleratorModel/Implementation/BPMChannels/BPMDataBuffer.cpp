//## begin module%3ACC65070000.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\BPMChannels\BPMDataBuffer.cpp
 * last modified 05/04/01 15:17:48
 */
//## end module%3ACC65070000.cm

//## begin module%3ACC65070000.cp preserve=no
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
//## end module%3ACC65070000.cp

//## Module: BPMDataBuffer%3ACC65070000; Package body
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\BPMChannels\BPMDataBuffer.cpp

//## begin module%3ACC65070000.includes preserve=yes
//## end module%3ACC65070000.includes

// BPMDataBuffer
#include "AcceleratorModel/Implementation/BPMChannels/BPMDataBuffer.h"
//## begin module%3ACC65070000.declarations preserve=no
//## end module%3ACC65070000.declarations

//## begin module%3ACC65070000.additionalDeclarations preserve=yes
//## end module%3ACC65070000.additionalDeclarations


// Class BPMDataBuffer 







//## Other Operations (implementation)
//## Operation: Record%986466245
void BPMDataBuffer::Record (const BPM& aBPM, const BPM::Data& data)
{
  //## begin BPMDataBuffer::Record%986466245.body preserve=yes
	x = data.x.value;
	y = data.y.value;
  //## end BPMDataBuffer::Record%986466245.body
}

//## begin module%3ACC65070000.epilog preserve=yes
//## end module%3ACC65070000.epilog

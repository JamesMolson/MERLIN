//## begin module%3ACC651E01FE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\BPMChannels\BPMChannel.cpp
 * last modified 05/04/01 14:38:12
 */
//## end module%3ACC651E01FE.cm

//## begin module%3ACC651E01FE.cp preserve=no
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
//## end module%3ACC651E01FE.cp

//## Module: BPMChannel%3ACC651E01FE; Package body
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\BPMChannels\BPMChannel.cpp

//## begin module%3ACC651E01FE.includes preserve=yes
#include <cassert>
//## end module%3ACC651E01FE.includes

// BPMDataBuffer
#include "AcceleratorModel/Implementation/BPMChannels/BPMDataBuffer.h"
// BPMChannel
#include "AcceleratorModel/Implementation/BPMChannels/BPMChannel.h"


//## begin module%3ACC651E01FE.declarations preserve=no
//## end module%3ACC651E01FE.declarations

//## begin module%3ACC651E01FE.additionalDeclarations preserve=yes
//## end module%3ACC651E01FE.additionalDeclarations


// Class BPMChannel 



//## Operation: BPMChannel%986466249
BPMChannel::BPMChannel (char XorY, BPMDataBuffer* dataBuff)
  //## begin BPMChannel::BPMChannel%986466249.initialization preserve=yes
  : xy(XorY),itsData(dataBuff)
  //## end BPMChannel::BPMChannel%986466249.initialization
{
  //## begin BPMChannel::BPMChannel%986466249.body preserve=yes
	assert((xy=='X'||xy=='Y')&&(dataBuff!=0));
  //## end BPMChannel::BPMChannel%986466249.body
}



//## Other Operations (implementation)
//## Operation: GetID%986466250
std::string BPMChannel::GetID () const
{
  //## begin BPMChannel::GetID%986466250.body preserve=yes
	return std::string("BPM."+itsData->id+'.'+xy);
  //## end BPMChannel::GetID%986466250.body
}

//## Operation: Read%986466251
double BPMChannel::Read () const
{
  //## begin BPMChannel::Read%986466251.body preserve=yes
	return xy=='X' ? itsData->x : itsData->y;
  //## end BPMChannel::Read%986466251.body
}

//## begin module%3ACC651E01FE.epilog preserve=yes
//## end module%3ACC651E01FE.epilog

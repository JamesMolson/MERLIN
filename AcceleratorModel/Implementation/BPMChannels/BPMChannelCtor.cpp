//## begin module%3ACC646B0230.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\BPMChannels\BPMChannelCtor.cpp
 * last modified 05/04/01 15:04:22
 */
//## end module%3ACC646B0230.cm

//## begin module%3ACC646B0230.cp preserve=no
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
//## end module%3ACC646B0230.cp

//## Module: BPMChannelCtor%3ACC646B0230; Package body
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\BPMChannels\BPMChannelCtor.cpp

//## begin module%3ACC646B0230.includes preserve=yes
#include <cassert>
//## end module%3ACC646B0230.includes

// BPM
#include "AcceleratorModel/ActiveMonitors/BPM.h"
// BPMChannelCtor
#include "AcceleratorModel/Implementation/BPMChannels/BPMChannelCtor.h"
// BPMChannel
#include "AcceleratorModel/Implementation/BPMChannels/BPMChannel.h"


//## begin module%3ACC646B0230.declarations preserve=no
//## end module%3ACC646B0230.declarations

//## begin module%3ACC646B0230.additionalDeclarations preserve=yes
//## end module%3ACC646B0230.additionalDeclarations


// Class BPMChannelCtor 

//## begin BPMChannelCtor::theServer%3ACC5B1B00F0.role preserve=no  public: static BPMDataBufferServer { -> 1VHAN}
BPMDataBufferServer BPMChannelCtor::theServer;
//## end BPMChannelCtor::theServer%3ACC5B1B00F0.role

//## Operation: BPMChannelCtor%986466246
BPMChannelCtor::BPMChannelCtor (char xy)
  //## begin BPMChannelCtor::BPMChannelCtor%986466246.initialization preserve=yes
  : ChannelCtor("BPM",std::string(1,xy))
  //## end BPMChannelCtor::BPMChannelCtor%986466246.initialization
{
  //## begin BPMChannelCtor::BPMChannelCtor%986466246.body preserve=yes
	assert(xy=='X'||xy=='Y');
  //## end BPMChannelCtor::BPMChannelCtor%986466246.body
}



//## Other Operations (implementation)
//## Operation: ConstructRO%986466247
ROChannel* BPMChannelCtor::ConstructRO (ModelElement* anElement)
{
  //## begin BPMChannelCtor::ConstructRO%986466247.body preserve=yes
#ifndef NDEBUG
	BPM* bpm = dynamic_cast<BPM*>(anElement);
	assert(bpm!=0);
#else
	BPM* bpm = static_cast<BPM*>(anElement);
#endif

	BPMDataBuffer* dataBuffer = theServer.GetDataBuffer(bpm);
	return new BPMChannel(key[0],dataBuffer);
  //## end BPMChannelCtor::ConstructRO%986466247.body
}

//## Operation: ConstructRW%986466252
RWChannel* BPMChannelCtor::ConstructRW (ModelElement* anElement)
{
  //## begin BPMChannelCtor::ConstructRW%986466252.body preserve=yes
	return (RWChannel*)0;
  //## end BPMChannelCtor::ConstructRW%986466252.body
}

//## begin module%3ACC646B0230.epilog preserve=yes
//## end module%3ACC646B0230.epilog

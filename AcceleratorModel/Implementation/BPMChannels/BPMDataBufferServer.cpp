//## begin module%3ACC65620046.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\BPMChannels\BPMDataBufferServer.cpp
 * last modified 05/04/01 15:06:57
 */
//## end module%3ACC65620046.cm

//## begin module%3ACC65620046.cp preserve=no
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
//## end module%3ACC65620046.cp

//## Module: BPMDataBufferServer%3ACC65620046; Package body
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\BPMChannels\BPMDataBufferServer.cpp

//## begin module%3ACC65620046.includes preserve=yes
//## end module%3ACC65620046.includes

// BPMDataBufferServer
#include "AcceleratorModel/Implementation/BPMChannels/BPMDataBufferServer.h"
//## begin module%3ACC65620046.declarations preserve=no
//## end module%3ACC65620046.declarations

//## begin module%3ACC65620046.additionalDeclarations preserve=yes
//## end module%3ACC65620046.additionalDeclarations


// Class BPMDataBufferServer 




//## Other Operations (implementation)
//## Operation: GetDataBuffer%986466248
BPMDataBuffer* BPMDataBufferServer::GetDataBuffer (BPM* bpm, bool create)
{
  //## begin BPMDataBufferServer::GetDataBuffer%986466248.body preserve=yes
	map<BPM*,BPMDataBuffer>::iterator b = dataBuffers.find(bpm);

	if(b!=dataBuffers.end())
		return &(b->second);

	if(!create)
		return (BPMDataBuffer*)0;

	// make new buffer
	BPMDataBuffer* newbuf = &(dataBuffers[bpm]);
	newbuf->SetID(bpm->GetName());
	bpm->AddBuffer(newbuf);
	return newbuf;
  //## end BPMDataBufferServer::GetDataBuffer%986466248.body
}

//## begin module%3ACC65620046.epilog preserve=yes
//## end module%3ACC65620046.epilog

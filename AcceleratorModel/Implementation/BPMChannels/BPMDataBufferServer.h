//## begin module%3ACC652B0352.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\BPMChannels\BPMDataBufferServer.h
 * last modified 05/04/01 15:06:57
 */
//## end module%3ACC652B0352.cm

//## begin module%3ACC652B0352.cp preserve=no
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
//## end module%3ACC652B0352.cp

//## Module: BPMDataBufferServer%3ACC652B0352; Package specification
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\BPMChannels\BPMDataBufferServer.h

#ifndef BPMDataBufferServer_h
#define BPMDataBufferServer_h 1

//## begin module%3ACC652B0352.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3ACC652B0352.additionalIncludes

//## begin module%3ACC652B0352.includes preserve=yes
#include <map>
//## end module%3ACC652B0352.includes

// BPMDataBuffer
#include "AcceleratorModel/Implementation/BPMChannels/BPMDataBuffer.h"
//## begin module%3ACC652B0352.declarations preserve=no
//## end module%3ACC652B0352.declarations

//## begin module%3ACC652B0352.additionalDeclarations preserve=yes
//## end module%3ACC652B0352.additionalDeclarations


//## Class: BPMDataBufferServer%3ACC5AA2019A
//	Singleton instance of a strorage class for BPMChannel
//	Data objects. BPMChannelData are indexed by their
//	associated BPM pointer.
//## Category: Merlin::AcceleratorModel::Implementation::BPMChannel%3ACC52E30032
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3ACC61310104;BPM::Buffer { -> F}

class BPMDataBufferServer 
{
  public:

    //## Other Operations (specified)
      //## Operation: GetDataBuffer%986466248
      BPMDataBuffer* GetDataBuffer (BPM* bpm, bool create = true);

  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Implementation::BPMChannel::<unnamed>%3ACC5AB70118
      //## Role: BPMDataBufferServer::dataBuffers%3ACC5AB703DF
      //## Qualifier: bpm%3ACC5ACF0078; BPM*
      //## begin BPMDataBufferServer::dataBuffers%3ACC5AB703DF.role preserve=no  private: BPMDataBuffer { -> 1VHAN}
      std::map<BPM*, BPMDataBuffer> dataBuffers;
      //## end BPMDataBufferServer::dataBuffers%3ACC5AB703DF.role

  private:  //## implementation
};

// Class BPMDataBufferServer 

//## begin module%3ACC652B0352.epilog preserve=yes
//## end module%3ACC652B0352.epilog


#endif

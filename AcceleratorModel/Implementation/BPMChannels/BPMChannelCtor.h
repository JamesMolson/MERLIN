//## begin module%3ACC645E00D2.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\BPMChannels\BPMChannelCtor.h
 * last modified 05/04/01 15:04:23
 */
//## end module%3ACC645E00D2.cm

//## begin module%3ACC645E00D2.cp preserve=no
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
//## end module%3ACC645E00D2.cp

//## Module: BPMChannelCtor%3ACC645E00D2; Package specification
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\BPMChannels\BPMChannelCtor.h

#ifndef BPMChannelCtor_h
#define BPMChannelCtor_h 1

//## begin module%3ACC645E00D2.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3ACC645E00D2.additionalIncludes

//## begin module%3ACC645E00D2.includes preserve=yes
//## end module%3ACC645E00D2.includes

// ChannelServer
#include "AcceleratorModel/Implementation/ChannelServer.h"
// BPMDataBufferServer
#include "AcceleratorModel/Implementation/BPMChannels/BPMDataBufferServer.h"

class BPMChannel;

//## begin module%3ACC645E00D2.declarations preserve=no
//## end module%3ACC645E00D2.declarations

//## begin module%3ACC645E00D2.additionalDeclarations preserve=yes
//## end module%3ACC645E00D2.additionalDeclarations


//## Class: BPMChannelCtor%3ACC50C101D6
//	Specialised constructor for BPM channels. The type of
//	channel constructed depends on the value of the
//	inherited key string (='X' or 'Y').
//## Category: Merlin::AcceleratorModel::Implementation::BPMChannel%3ACC52E30032
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: constructs%3ACC50E60334;BPMChannel { -> F}
//## Uses: <unnamed>%3ACC62ED0370;BPM { -> }

class BPMChannelCtor : public ChannelServer::ChannelCtor  //## Inherits: <unnamed>%3ACC50CB03C0
{
  public:
    //## Constructors (specified)
      //## Operation: BPMChannelCtor%986466246
      BPMChannelCtor (char xy);


    //## Other Operations (specified)
      //## Operation: ConstructRO%986466247
      //	Constructs and returns a BPMChannel.
      virtual ROChannel* ConstructRO (ModelElement* anElement);

      //## Operation: ConstructRW%986466252
      //	Returns NULL.
      virtual RWChannel* ConstructRW (ModelElement* anElement);

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Implementation::BPMChannel::<unnamed>%3ACC5B190366
      //## Role: BPMChannelCtor::theServer%3ACC5B1B00F0
      //## begin BPMChannelCtor::theServer%3ACC5B1B00F0.role preserve=no  public: static BPMDataBufferServer { -> 1VHAN}
      static BPMDataBufferServer theServer;
      //## end BPMChannelCtor::theServer%3ACC5B1B00F0.role

  protected:
  private:
  private:  //## implementation
};

// Class BPMChannelCtor 

//## begin module%3ACC645E00D2.epilog preserve=yes
//## end module%3ACC645E00D2.epilog


#endif

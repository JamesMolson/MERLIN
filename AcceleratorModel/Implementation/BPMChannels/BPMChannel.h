//## begin module%3ACC65170096.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\BPMChannels\BPMChannel.h
 * last modified 05/04/01 14:38:13
 */
//## end module%3ACC65170096.cm

//## begin module%3ACC65170096.cp preserve=no
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
//## end module%3ACC65170096.cp

//## Module: BPMChannel%3ACC65170096; Package specification
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\BPMChannels\BPMChannel.h

#ifndef BPMChannel_h
#define BPMChannel_h 1

//## begin module%3ACC65170096.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3ACC65170096.additionalIncludes

//## begin module%3ACC65170096.includes preserve=yes
//## end module%3ACC65170096.includes

// Channels
#include "Channels/Channels.h"

class BPMDataBuffer;

//## begin module%3ACC65170096.declarations preserve=no
//## end module%3ACC65170096.declarations

//## begin module%3ACC65170096.additionalDeclarations preserve=yes
//## end module%3ACC65170096.additionalDeclarations


//## Class: BPMChannel%3ACC4E6F00B4
//## Category: Merlin::AcceleratorModel::Implementation::BPMChannel%3ACC52E30032
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class BPMChannel : public ROChannel  //## Inherits: <unnamed>%3ACC4E8D00AA
{
  public:
    //## Constructors (specified)
      //## Operation: BPMChannel%986466249
      //	Constructor taking the BPMDataBuffer, and the type of
      //	channel ('X' or 'Y').
      BPMChannel (char XorY, BPMDataBuffer* dataBuff);


    //## Other Operations (specified)
      //## Operation: GetID%986466250
      //	Returns the ID of the channel (parameter).
      virtual std::string GetID () const;

      //## Operation: Read%986466251
      //	Returns the current value of the parameter/attribute
      //	associated with the channel.
      virtual double Read () const;

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: xy%3ACC57F00032
      //## begin BPMChannel::xy%3ACC57F00032.attr preserve=no  private: char {UA} 
      char xy;
      //## end BPMChannel::xy%3ACC57F00032.attr

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Implementation::BPMChannel::<unnamed>%3ACC58B10000
      //## Role: BPMChannel::itsData%3ACC58B10370
      //## begin BPMChannel::itsData%3ACC58B10370.role preserve=no  private: BPMDataBuffer {n -> 1RFHAN}
      BPMDataBuffer* itsData;
      //## end BPMChannel::itsData%3ACC58B10370.role

  private:  //## implementation
};

// Class BPMChannel 

//## begin module%3ACC65170096.epilog preserve=yes
//## end module%3ACC65170096.epilog


#endif

//## begin module%3ACC64FE0366.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\BPMChannels\BPMDataBuffer.h
 * last modified 05/04/01 15:17:48
 */
//## end module%3ACC64FE0366.cm

//## begin module%3ACC64FE0366.cp preserve=no
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
//## end module%3ACC64FE0366.cp

//## Module: BPMDataBuffer%3ACC64FE0366; Package specification
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\BPMChannels\BPMDataBuffer.h

#ifndef BPMDataBuffer_h
#define BPMDataBuffer_h 1

//## begin module%3ACC64FE0366.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3ACC64FE0366.additionalIncludes

//## begin module%3ACC64FE0366.includes preserve=yes
//## end module%3ACC64FE0366.includes

// BPM
#include "AcceleratorModel/ActiveMonitors/BPM.h"
//## begin module%3ACC64FE0366.declarations preserve=no
//## end module%3ACC64FE0366.declarations

//## begin module%3ACC64FE0366.additionalDeclarations preserve=yes
//## end module%3ACC64FE0366.additionalDeclarations


//## Class: BPMDataBuffer%3ACC4EC7033E
//	A BPM buffer which stores a single (x,y) pair from a
//	BPM. The cached data is updated on each call to Record().
//## Category: Merlin::AcceleratorModel::Implementation::BPMChannel%3ACC52E30032
//## Subsystem: Merlin::AcceleratorModel::Implementation::BPMChannels%3ACC643C01AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class BPMDataBuffer : public BPM::Buffer  //## Inherits: <unnamed>%3ACC4ED401CC
{
  public:
    //## Constructors (specified)
      //## Operation: BPMDataBuffer%986466244
      //	Constructor
      BPMDataBuffer ();


    //## Other Operations (specified)
      //## Operation: Record%986466245
      virtual void Record (const BPM& aBPM, const BPM::Data& data);

      //## Operation: SetID%986466254
      void SetID (const string& anID);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: x%3ACC58FC008C
      //## begin BPMDataBuffer::x%3ACC58FC008C.attr preserve=no  private: double {UA} 
      double x;
      //## end BPMDataBuffer::x%3ACC58FC008C.attr

      //## Attribute: y%3ACC58FE03AC
      //## begin BPMDataBuffer::y%3ACC58FE03AC.attr preserve=no  private: double {UA} 
      double y;
      //## end BPMDataBuffer::y%3ACC58FE03AC.attr

      //## Attribute: id%3ACC627B0280
      //## begin BPMDataBuffer::id%3ACC627B0280.attr preserve=no  private: string {UA} 
      string id;
      //## end BPMDataBuffer::id%3ACC627B0280.attr

  private:  //## implementation
    friend class BPMChannel;
};

// Class BPMDataBuffer 

//## Operation: BPMDataBuffer%986466244
inline BPMDataBuffer::BPMDataBuffer ()
  //## begin BPMDataBuffer::BPMDataBuffer%986466244.initialization preserve=yes
  :x(0),y(0),id()
  //## end BPMDataBuffer::BPMDataBuffer%986466244.initialization
{
  //## begin BPMDataBuffer::BPMDataBuffer%986466244.body preserve=yes
  //## end BPMDataBuffer::BPMDataBuffer%986466244.body
}



//## Other Operations (inline)
//## Operation: SetID%986466254
inline void BPMDataBuffer::SetID (const string& anID)
{
  //## begin BPMDataBuffer::SetID%986466254.body preserve=yes
	id=anID;
  //## end BPMDataBuffer::SetID%986466254.body
}

//## begin module%3ACC64FE0366.epilog preserve=yes
//## end module%3ACC64FE0366.epilog


#endif

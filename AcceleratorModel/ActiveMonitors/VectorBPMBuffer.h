//## begin module%3992B30C00E3.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\ActiveMonitors\VectorBPMBuffer.h
 * last modified 08/10/00 04:21:53
 */
//## end module%3992B30C00E3.cm

//## begin module%3992B30C00E3.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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
//## end module%3992B30C00E3.cp

//## Module: VectorBPMBuffer%3992B30C00E3; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
//## Source file: C:\C++\Merlin\AcceleratorModel\ActiveMonitors\VectorBPMBuffer.h

#ifndef VectorBPMBuffer_h
#define VectorBPMBuffer_h 1

//## begin module%3992B30C00E3.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3992B30C00E3.additionalIncludes

//## begin module%3992B30C00E3.includes preserve=yes
//## end module%3992B30C00E3.includes

// BPM
#include "AcceleratorModel/ActiveMonitors/BPM.h"
//## begin module%3992B30C00E3.additionalDeclarations preserve=yes
//## end module%3992B30C00E3.additionalDeclarations


//## Class: VectorBPMBuffer%3992B30C00E3
//	A BPM buffer which stores the BPM readings as a
//	continous vector of readings.
//## Category: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class VectorBPMBuffer : public BPMBuffer, //## Inherits: <unnamed>%3992B31D00CA
                            	public std::list< BPM::Data >  //## Inherits: <unnamed>%3992B84202B8
{
  public:

    //## Other Operations (specified)
      //## Operation: Record%965916319
      virtual void Record (const BPM& aBPM, const BPM::Data& data);

      //## Operation: Reset%965916320
      //	Clears the buffer.
      void Reset ();

  protected:
  private:
  private:  //## implementation
};

// Class VectorBPMBuffer 

//## begin module%3992B30C00E3.epilog preserve=yes
//## end module%3992B30C00E3.epilog


#endif

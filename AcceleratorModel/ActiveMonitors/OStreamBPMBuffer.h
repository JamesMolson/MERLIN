//## begin module%37341CC80168.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\ActiveMonitors\OStreamBPMBuffer.h
 * last modified 08/10/00 04:09:26
 */
//## end module%37341CC80168.cm

//## begin module%37341CC80168.cp preserve=no
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
//## end module%37341CC80168.cp

//## Module: OStreamBPMBuffer%37341CC80168; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
//## Source file: C:\C++\Merlin\AcceleratorModel\ActiveMonitors\OStreamBPMBuffer.h

#ifndef OStreamBPMBuffer_h
#define OStreamBPMBuffer_h 1

//## begin module%37341CC80168.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37341CC80168.additionalIncludes

//## begin module%37341CC80168.includes preserve=yes
#include <iostream>
//## end module%37341CC80168.includes

// BPM
#include "AcceleratorModel/ActiveMonitors/BPM.h"
//## begin module%37341CC80168.additionalDeclarations preserve=yes
//## end module%37341CC80168.additionalDeclarations


//## Class: OStreamBPMBuffer%37341CC80168
//	A simple BPM buffer which outputs the data in a single
//	row to a specified ostream. The data row has the format
//
//	label    ct    x     y     q     x_err     y_err   q_err
//
//	As well as the the ostream, the output units can be set
//	for each numerical value with a call to SetOutputUnits().
//## Category: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class OStreamBPMBuffer : public BPMBuffer  //## Inherits: <unnamed>%37341D0D00F0
{
  public:
    //## Constructors (specified)
      //## Operation: OStreamBPMBuffer%926157717
      OStreamBPMBuffer ();


    //## Other Operations (specified)
      //## Operation: Record%926157718
      virtual void Record (const BPM& aBPM, const BPM::Data& data);

      //## Operation: SetStream%926157719
      void SetStream (std::ostream& os1);

      //## Operation: SetUnits%926157720
      void SetUnits (double ct_unit, double xy_unit, double q_unit = 1.0e+10);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: os%37341E1201CC
      //## begin OStreamBPMBuffer::os%37341E1201CC.attr preserve=no  private: std::ostream* {UA} 
      std::ostream* os;
      //## end OStreamBPMBuffer::os%37341E1201CC.attr

      //## Attribute: ctu%37341E1F01AE
      //## begin OStreamBPMBuffer::ctu%37341E1F01AE.attr preserve=no  private: double {UA} 
      double ctu;
      //## end OStreamBPMBuffer::ctu%37341E1F01AE.attr

      //## Attribute: xyu%37341E350348
      //## begin OStreamBPMBuffer::xyu%37341E350348.attr preserve=no  private: double {UA} 
      double xyu;
      //## end OStreamBPMBuffer::xyu%37341E350348.attr

      //## Attribute: qu%3992873B0241
      //## begin OStreamBPMBuffer::qu%3992873B0241.attr preserve=no  private: double {UA} 
      double qu;
      //## end OStreamBPMBuffer::qu%3992873B0241.attr

  private:  //## implementation
};

// Class OStreamBPMBuffer 

//## begin module%37341CC80168.epilog preserve=yes
//## end module%37341CC80168.epilog


#endif

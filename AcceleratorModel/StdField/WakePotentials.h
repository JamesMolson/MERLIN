//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3C5018DF03BA.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdField\WakePotentials.h
 * last modified 24/01/02 15:36:47
 */
//## end module%3C5018DF03BA.cm

//## begin module%3C5018DF03BA.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 2001 by The Merlin Collaboration.
 * - ALL RIGHTS RESERVED - 
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
//## end module%3C5018DF03BA.cp

//## Module: WakePotentials%3C5018DF03BA; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Source file: C:\C++\Merlin\AcceleratorModel\StdField\WakePotentials.h

#ifndef WakePotentials_h
#define WakePotentials_h 1

//## begin module%3C5018DF03BA.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3C5018DF03BA.additionalIncludes

//## begin module%3C5018DF03BA.includes preserve=yes
//## end module%3C5018DF03BA.includes

//## begin module%3C5018DF03BA.additionalDeclarations preserve=yes
//## end module%3C5018DF03BA.additionalDeclarations


//## Class: WakePotentials%3C5018DF03BA; Abstract
//	Abstract class for calculating the longitudinal and
//	transverse single-bunch wakefield potentials (Greens
//	functions).
//## Category: Merlin::AcceleratorModel::StdField%371DC8870244
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Persistence: Transient
//## Cardinality/Multiplicity: n



class WakePotentials 
{
  public:
    //## Destructor (specified)
      //## Operation: ~WakePotentials%3C501ACF0056
      virtual ~WakePotentials ();


    //## Other Operations (specified)
      //## Operation: Wlong%3C5019E500C7
      virtual double Wlong (double z) const = 0;

      //## Operation: Wtrans%3C501A2E02C1
      virtual double Wtrans (double z) const = 0;

  protected:
  private:
  private: //## implementation
};

// Class WakePotentials 

//## Operation: ~WakePotentials%3C501ACF0056
inline WakePotentials::~WakePotentials ()
{
  //## begin WakePotentials::~WakePotentials%3C501ACF0056.body preserve=yes
  //## end WakePotentials::~WakePotentials%3C501ACF0056.body
}


// Class WakePotentials 

//## begin module%3C5018DF03BA.epilog preserve=yes
//## end module%3C5018DF03BA.epilog


#endif

//## begin module%396B2620019A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\GroundMotionModels\SimpleATL.h
 * last modified 28/03/01 17:26:52
 */
//## end module%396B2620019A.cm

//## begin module%396B2620019A.cp preserve=no
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
//## end module%396B2620019A.cp

//## Module: SimpleATL%396B2620019A; Pseudo Package specification
//## Subsystem: Merlin::GroundMotionModels%396B6A3101D6
//## Source file: D:\dev\Merlin\GroundMotionModels\SimpleATL.h

#ifndef SimpleATL_h
#define SimpleATL_h 1

//## begin module%396B2620019A.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%396B2620019A.additionalIncludes

//## begin module%396B2620019A.includes preserve=yes
#include <iostream>
#include <vector>
//## end module%396B2620019A.includes

// AcceleratorSupport
#include "AcceleratorModel/Supports/AcceleratorSupport.h"

class RandGenerator;

//## begin module%396B2620019A.additionalDeclarations preserve=yes
//## end module%396B2620019A.additionalDeclarations


//## Class: SimpleATL%396B2620019A
//	Represents a simple ATL model of ground motion. On each
//	time step dT, SimpleATL applies a random vertical (and
//	horizontal if included) displacement to a set of
//	AcceleratorSupports. The variance of the motion is
//
//	                 v = A.dT.L,
//
//	where A is the ATL constant, dT the time step and L the
//	distance between supports.
//
//	Note that at present only the arc distance between
//	successive supports  is used. For curved geometries this
//	may introduce an error.
//## Category: Merlin::GroundMotionModels%396B260C019B
//## Subsystem: Merlin::GroundMotionModels%396B6A3101D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class SimpleATL 
{
  public:
    //## Constructors (specified)
      //## Operation: SimpleATL%963324079; C++
      //	Constructor taking the A constant and the list of
      //	support structures.
      SimpleATL (double anA, const AcceleratorSupportList& supports, double vrms=0);

    //## Destructor (specified)
      //## Operation: ~SimpleATL%963324087; C++
      ~SimpleATL ();


    //## Other Operations (specified)
      //## Operation: Reset%963324080; C++
      //	Reset the ground motion to zero Note this resets the
      //	offset of all the AcceleratorSupports, and resets the
      //	internal clock to zero.
      void Reset ();

      //## Operation: DoStep%963324081; C++
      //	Perform a single step of dt seconds. Returns the current
      //	simulated time.
      double DoStep (double dt);

      //## Operation: RecordOffsets%963324082; C++
      //	Record the (x,y,z) offset of all the supports to the
      //	specified stream.
      void RecordOffsets (std::ostream& os) const;

      //## Operation: GetTime%963324083; C++
      //	Returns the current simulated time (in seconds).
      double GetTime () const;

      //## Operation: SetRandomSeed%963324084; C++
      //	Sets the random seed to nseed.
      void SetRandomSeed (unsigned int nseed);

      //## Operation: GetRandomSeed%963324085; C++
      //	Returns the current random seed
      unsigned int GetRandomSeed () const;

      //## Operation: ResetRandomSeed%963324086; C++
      //	Resets the random generator with the current random seed.
      void ResetRandomSeed ();

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: t%396B674A0000
      //## begin SimpleATL::t%396B674A0000.attr preserve=no  private: double {UA} 
      double t;
      //## end SimpleATL::t%396B674A0000.attr

      //## Attribute: A%396B674A0032
      //## begin SimpleATL::A%396B674A0032.attr preserve=no  private: double {UA} 
      double A;
      //## end SimpleATL::A%396B674A0032.attr

      //## Attribute: seed%396B674A0033
      //## begin SimpleATL::seed%396B674A0033.attr preserve=no  private: unsigned {UA} 
      unsigned seed;
      //## end SimpleATL::seed%396B674A0033.attr

	  // Uncorrelated white-noise vibration variance
	  double vv;

	  // vector to store ATL ground motion
	  std::vector<double> atlgm;

    // Data Members for Associations

      //## Association: Merlin::GroundMotionModels::<unnamed>%396B689E00D2
      //## Role: SimpleATL::theSupports%396B689E02BD
      //## begin SimpleATL::theSupports%396B689E02BD.role preserve=no  private: AcceleratorSupportList { -> 1VHAN}
      AcceleratorSupportList theSupports;
      //## end SimpleATL::theSupports%396B689E02BD.role

      //## Association: Merlin::GroundMotionModels::<unnamed>%396B68CD02D0
      //## Role: SimpleATL::rg%396B68CE00D3
      //## begin SimpleATL::rg%396B68CE00D3.role preserve=no  private: RandGenerator { -> 0..1VFHAN}
      RandGenerator* rg;
      //## end SimpleATL::rg%396B68CE00D3.role

  private:  //## implementation
};

// Class SimpleATL 

//## begin module%396B2620019A.epilog preserve=yes
//## end module%396B2620019A.epilog


#endif

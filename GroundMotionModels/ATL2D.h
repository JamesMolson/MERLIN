//## begin module%396B2620019A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\GroundMotionModels\ATL2D.h
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

//## Module: ATL2D%396B2620019A; Pseudo Package specification
//## Subsystem: Merlin::GroundMotionModels%396B6A3101D6
//## Source file: D:\dev\Merlin\GroundMotionModels\ATL2D.h

#ifndef ATL2D_h
#define ATL2D_h 1

//## begin module%396B2620019A.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%396B2620019A.additionalIncludes

//## begin module%396B2620019A.includes preserve=yes
#include <iostream>
#include <vector>
//## end module%396B2620019A.includes

// AcceleratorSupport
#include "AcceleratorModel/Supports/AcceleratorSupport.h"

// TLASimp
#include "TLAS/LinearAlgebra.h"

class RandGenerator;

//## begin module%396B2620019A.additionalDeclarations preserve=yes
//## end module%396B2620019A.additionalDeclarations


//## Class: ATL2D%396B2620019A
//	Represents a 2D ATL model of ground motion. On each
//	time step dT, ATL2D applies a random vertical (and
//	horizontal if included) displacement to a set of
//	AcceleratorSupports. The variance of the motion is
//
//	                 v = A.dT.L,
//
//	where A is the ATL constant, dT the time step and L the
//	distance between supports.
//
//  ATL2D calculates correctly the correlation between the support point
//  on a 2D plane, such that A.dT.L  holds for any two points, where L is 
//  the direct distance between those two points. 	
//
//
//## Category: Merlin::GroundMotionModels%396B260C019B
//## Subsystem: Merlin::GroundMotionModels%396B6A3101D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ATL2D 
{
  public:

	  enum ATLMode {increment, absolute};


    //## Constructors (specified)
      //## Operation: ATL2D%963324079; C++
      //	Constructor taking the A constant and the list of
      //	support structures.
      ATL2D (double anA, const AcceleratorSupportList& supports, const Point2D refPoint=Point2D(0,0), ifstream* evecTFile=0, ifstream* evalFile=0);

    //## Destructor (specified)
      //## Operation: ~ATL2D%963324087; C++
      ~ATL2D ();


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

	  bool SetATLMode (const ATLMode mode);

	  bool SetVibration (const double vrms);

	  void RecordEigenSystem (ofstream* evecTFile, ofstream* evalFile);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: t%396B674A0000
      //## begin ATL2D::t%396B674A0000.attr preserve=no  private: double {UA} 
      double t;
      //## end ATL2D::t%396B674A0000.attr

      //## Attribute: A%396B674A0032
      //## begin ATL2D::A%396B674A0032.attr preserve=no  private: double {UA} 
      double A;
      //## end ATL2D::A%396B674A0032.attr

      //## Attribute: seed%396B674A0033
      //## begin ATL2D::seed%396B674A0033.attr preserve=no  private: unsigned {UA} 
      unsigned seed;
      //## end ATL2D::seed%396B674A0033.attr

	  // Uncorrelated white-noise vibration variance
	  double vv;

    // Data Members for Associations

      //## Association: Merlin::GroundMotionModels::<unnamed>%396B689E00D2
      //## Role: ATL2D::theSupports%396B689E02BD
      //## begin ATL2D::theSupports%396B689E02BD.role preserve=no  private: AcceleratorSupportList { -> 1VHAN}
      AcceleratorSupportList theSupports;
      //## end ATL2D::theSupports%396B689E02BD.role

      //## Association: Merlin::GroundMotionModels::<unnamed>%396B68CD02D0
      //## Role: ATL2D::rg%396B68CE00D3
      //## begin ATL2D::rg%396B68CE00D3.role preserve=no  private: RandGenerator { -> 0..1VFHAN}
      RandGenerator* rg;
      //## end ATL2D::rg%396B68CE00D3.role

  private:  //## implementation

	  RealMatrix evecsT;

	  RealVector evals;

	  double Distance(const int n1, const int n2);

	  double Distance(const int n1, const Point2D x2);

	  ATLMode atlMode;
};

// Class ATL2D 

//## begin module%396B2620019A.epilog preserve=yes
//## end module%396B2620019A.epilog


#endif

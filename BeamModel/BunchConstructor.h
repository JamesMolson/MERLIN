//## begin module%3AE6BC9F03CA.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamModel\BunchConstructor.h
 * last modified 26/04/01 14:21:27
 */
//## end module%3AE6BC9F03CA.cm

//## begin module%3AE6BC9F03CA.cp preserve=no
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
//## end module%3AE6BC9F03CA.cp

//## Module: BunchConstructor%3AE6BC9F03CA; Package specification
//## Subsystem: Merlin::BeamModel%3ACB10800370
//## Source file: D:\dev\Merlin\BeamModel\BunchConstructor.h

#ifndef BunchConstructor_h
#define BunchConstructor_h 1

//## begin module%3AE6BC9F03CA.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE6BC9F03CA.additionalIncludes

//## begin module%3AE6BC9F03CA.includes preserve=yes
//## end module%3AE6BC9F03CA.includes


class Bunch;

//## begin module%3AE6BC9F03CA.declarations preserve=no
//## end module%3AE6BC9F03CA.declarations

//## begin module%3AE6BC9F03CA.additionalDeclarations preserve=yes
//## end module%3AE6BC9F03CA.additionalDeclarations


//## Class: BunchConstructor%3AE6BB98021C; Abstract
//	Abstract factory for constructing a Bunch.
//## Category: Merlin::BeamModel%3ACB0C800384
//## Subsystem: Merlin::BeamModel%3ACB10800370
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: constructs%3AE6BC240000;Bunch { -> F}

class BunchConstructor 
{
  public:
    //## Destructor (specified)
      //## Operation: ~BunchConstructor%988200625
      virtual ~BunchConstructor ();


    //## Other Operations (specified)
      //## Operation: ConstructBunch%988200626
      virtual Bunch* ConstructBunch () const = 0;

  protected:
  private:
  private:  //## implementation
};

//## Class: StaticBunchCtor%3AE6BD1700D2; Parameterized Class
//	Template class to generate a BunchConstructor which
//	constructs a Bunch of type B. The Construct() method
//	always returns a copy of the same (stored) bunch. Class
//	B must provide a copy constructor.
//## Category: Merlin::BeamModel%3ACB0C800384
//## Subsystem: Merlin::BeamModel%3ACB10800370
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class B>
class StaticBunchCtor : public BunchConstructor  //## Inherits: <unnamed>%3AE6BDBF033E
{
  public:
    //## Constructors (specified)
      //## Operation: StaticBunchCtor%988200627
      explicit StaticBunchCtor (B* source, bool del = false);

    //## Destructor (specified)
      //## Operation: ~StaticBunchCtor%988200628
      ~StaticBunchCtor ();


    //## Other Operations (specified)
      //## Operation: ConstructBunch%988200629
      //	Constructs and returns a copy of the source bunch.
      virtual Bunch* ConstructBunch () const;

      //## Operation: SetSourceBunch%988200630
      //	Sets the source bunch. Set del to true if the bunch is
      //	to be deleted when the destructor is called.
      void SetSourceBunch (B* bunch0, bool del = false);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: sourceBunch%3AE6BE080118
      //## begin StaticBunchCtor::sourceBunch%3AE6BE080118.attr preserve=no  private: B* {UA} 
      B* sourceBunch;
      //## end StaticBunchCtor::sourceBunch%3AE6BE080118.attr

      //## Attribute: owns%3AE8114E0384
      //	Set true if the ctor owns the source bunch.
      //## begin StaticBunchCtor::owns%3AE8114E0384.attr preserve=no  private: bool {UA} 
      bool owns;
      //## end StaticBunchCtor::owns%3AE8114E0384.attr

  private:  //## implementation
};

// Class BunchConstructor 

//## Operation: ~BunchConstructor%988200625
inline BunchConstructor::~BunchConstructor ()
{
  //## begin BunchConstructor::~BunchConstructor%988200625.body preserve=yes
  //## end BunchConstructor::~BunchConstructor%988200625.body
}


// Parameterized Class StaticBunchCtor 

//## Operation: StaticBunchCtor%988200627
template <class B>
inline StaticBunchCtor<B>::StaticBunchCtor (B* source, bool del)
  //## begin StaticBunchCtor::StaticBunchCtor%988200627.initialization preserve=yes
  : sourceBunch(source),owns(del)
  //## end StaticBunchCtor::StaticBunchCtor%988200627.initialization
{
  //## begin StaticBunchCtor::StaticBunchCtor%988200627.body preserve=yes
  //## end StaticBunchCtor::StaticBunchCtor%988200627.body
}


// Class BunchConstructor 


// Parameterized Class StaticBunchCtor 



//## Operation: ~StaticBunchCtor%988200628
template <class B>
StaticBunchCtor<B>::~StaticBunchCtor ()
{
  //## begin StaticBunchCtor::~StaticBunchCtor%988200628.body preserve=yes
	if(owns && sourceBunch!=0)
		delete sourceBunch;
  //## end StaticBunchCtor::~StaticBunchCtor%988200628.body
}



//## Other Operations (implementation)
//## Operation: ConstructBunch%988200629
template <class B>
Bunch* StaticBunchCtor<B>::ConstructBunch () const
{
  //## begin StaticBunchCtor::ConstructBunch%988200629.body preserve=yes
	return new B(*sourceBunch);
  //## end StaticBunchCtor::ConstructBunch%988200629.body
}

//## Operation: SetSourceBunch%988200630
template <class B>
void StaticBunchCtor<B>::SetSourceBunch (B* bunch0, bool del)
{
  //## begin StaticBunchCtor::SetSourceBunch%988200630.body preserve=yes
	if(owns && sourceBunch!=0)
		delete sourceBunch;
	sourceBunch = bunch0;
	owns = del;
  //## end StaticBunchCtor::SetSourceBunch%988200630.body
}

//## begin module%3AE6BC9F03CA.epilog preserve=yes
template<class B>
inline StaticBunchCtor<B>* MakeBunchCtor(B* bunch0, bool del = false)
{
	return new StaticBunchCtor<B>(bunch0,del);
}
//## end module%3AE6BC9F03CA.epilog


#endif

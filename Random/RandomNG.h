//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%35D2B1B1018C.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\Random\RandomNG.h
 * last modified 09/04/01 11:26:27 AM
 */
//## end module%35D2B1B1018C.cm

//## begin module%35D2B1B1018C.cp preserve=no
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
//## end module%35D2B1B1018C.cp

//## Module: RandomNG%35D2B1B1018C; Package specification
//## Subsystem: Merlin::Random%35D2B1A20307
//## Source file: C:\C++\Merlin\Random\RandomNG.h

#ifndef RandomNG_h
#define RandomNG_h 1

//## begin module%35D2B1B1018C.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%35D2B1B1018C.additionalIncludes

//## begin module%35D2B1B1018C.includes preserve=yes
#include <cassert>
//## end module%35D2B1B1018C.includes

//## begin module%35D2B1B1018C.additionalDeclarations preserve=yes
class ACG;
class Normal;
class Uniform;
class Poisson;
//## end module%35D2B1B1018C.additionalDeclarations


//## Class: RandGenerator%35D2B0C500D9
//	A class which represents a single random number
//	generator.
//## Category: Merlin::Random%34BC8A770040; Global
//## Subsystem: Merlin::Random%35D2B1A20307
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class RandGenerator 
{
  public:
    //## Constructors (specified)
      //## Operation: RandGenerator%35D2B3980038
      RandGenerator (unsigned  iseed = 0);

    //## Destructor (specified)
      //## Operation: ~RandGenerator%35D2B3C6003E
      ~RandGenerator ();


    //## Other Operations (specified)
      //## Operation: getSeed%35D4208000EA
      unsigned  getSeed () const;

      //## Operation: reset%35D2B0FE010D
      //	Resets the seed for the generators to the last supplied
      //	seed value.
      void reset ();

      //## Operation: reset%35D2B0FE0352
      //	Resets the initial seed for the generator.
      void reset (unsigned  iseed);

      //## Operation: normal%35D2B0FF01A5
      //	Generates a random number from a uniform (Gaussian)
      //	distribution with the specified mean and variance.
      double normal (double mean, double variance);

      //## Operation: normal%35D2B0FF03DF
      //	Generates a random number from a uniform (Gaussian)
      //	distribution with the specified mean and variance. The
      //	resulting distribution is truncated to +/-cutoff
      //	standard deviations.
      double normal (double mean, double variance, double cutoff);

      //## Operation: uniform%35D2B100023C
      //	Generates a uniform random number in the range
      //	|low,high> inclusive.
      double uniform (double low, double high);

      //## Operation: poisson%3B949DF70199
      //	Generates a poisson random number.
      double poisson (double u);

      //## Operation: init%35D2B101008F
      //	Initialised the generator. Should be called before any
      //	other generator function.
      void init (unsigned  iseed = 0);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: nseed%35D2B50A0225
      //## begin RandGenerator::nseed%35D2B50A0225.attr preserve=no  private: unsigned  {UA} 0
      unsigned  nseed;
      //## end RandGenerator::nseed%35D2B50A0225.attr

    // Additional Private Declarations
      //## begin RandGenerator%35D2B0C500D9.private preserve=yes
		ACG* gen;
		Normal* gaussGen;
		Uniform* uniformGen;
		Poisson* poissonGen;
      //## end RandGenerator%35D2B0C500D9.private
  private: //## implementation

    //## Other Operations (specified)
      //## Operation: ResetGenerators%35D2B3A0021A
      void ResetGenerators ();

};

//## Class: RandomNG%34BC8BEC0187; Class Utility
//	Singleton class for generating continuous floating point
//	numbers from specific distributions. Currently only the
//	normal (Gaussian) and uniform distributions are
//	supported.
//## Category: Merlin::Random%34BC8A770040; Global
//## Subsystem: Merlin::Random%35D2B1A20307
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class RandomNG 
{
  public:

    //## Other Operations (specified)
      //## Operation: reset%34BC8CCD0361
      //	Resets the seed for the generators to the last supplied
      //	seed value.
      static void reset ();

      //## Operation: reset%34BC8CFC034B
      //	Resets the initial seed for the generator.
      static void reset (unsigned  iseed);

      //## Operation: normal%34E0473302D9
      //	Generates a random number from a uniform (Gaussian)
      //	distribution with the specified mean and variance.
      static double normal (double mean, double variance);

      //## Operation: normal%34BC8D3403CD
      //	Generates a random number from a uniform (Gaussian)
      //	distribution with the specified mean and variance. The
      //	resulting distribution is truncated to +/-cutoff
      //	standard deviations.
      static double normal (double mean, double variance, double cutoff);

      //## Operation: uniform%34BC8D5F00B8
      //	Generates a uniform random number in the range
      //	|low,high> inclusive.
      static double uniform (double low, double high);

      //## Operation: poisson%3B949DA100E1
      //	Generates a uniform random number in the range
      //	|low,high> inclusive.
      static double poisson (double u);

      //## Operation: init%34BC9073022E
      //	Initialised the generator. Should be called before any
      //	other generator function.
      static void init (unsigned  iseed = 0);

  protected:
  private:
  private: //## implementation
    // Data Members for Associations

      //## Association: Merlin::Random::<unnamed>%35D2B11F0010
      //## Role: RandomNG::generator%35D2B11F02CD
      //## begin RandomNG::generator%35D2B11F02CD.role preserve=no  implementation: RandGenerator { -> RHgAN}
      static RandGenerator* generator;
      //## end RandomNG::generator%35D2B11F02CD.role

};

// Class RandGenerator 


//## Other Operations (inline)
//## Operation: getSeed%35D4208000EA
inline unsigned RandGenerator::getSeed () const
{
  //## begin RandGenerator::getSeed%35D4208000EA.body preserve=yes
	return nseed;
  //## end RandGenerator::getSeed%35D4208000EA.body
}

// Class Utility RandomNG 


//## Other Operations (inline)
//## Operation: reset%34BC8CCD0361
inline void RandomNG::reset ()
{
  //## begin RandomNG::reset%34BC8CCD0361.body preserve=yes
	assert(generator);
	generator->reset();
  //## end RandomNG::reset%34BC8CCD0361.body
}

//## Operation: reset%34BC8CFC034B
inline void RandomNG::reset (unsigned iseed)
{
  //## begin RandomNG::reset%34BC8CFC034B.body preserve=yes
	assert(generator);
	generator->reset(iseed);
  //## end RandomNG::reset%34BC8CFC034B.body
}

//## Operation: normal%34E0473302D9
inline double RandomNG::normal (double mean, double variance)
{
  //## begin RandomNG::normal%34E0473302D9.body preserve=yes
	assert(generator);
	return generator->normal(mean,variance);
  //## end RandomNG::normal%34E0473302D9.body
}

//## Operation: normal%34BC8D3403CD
inline double RandomNG::normal (double mean, double variance, double cutoff)
{
  //## begin RandomNG::normal%34BC8D3403CD.body preserve=yes
	assert(generator);
	return generator->normal(mean,variance,cutoff);
  //## end RandomNG::normal%34BC8D3403CD.body
}

//## Operation: uniform%34BC8D5F00B8
inline double RandomNG::uniform (double low, double high)
{
  //## begin RandomNG::uniform%34BC8D5F00B8.body preserve=yes
	assert(generator);
	return generator->uniform(low,high);
  //## end RandomNG::uniform%34BC8D5F00B8.body
}

//## Operation: poisson%3B949DA100E1
inline double RandomNG::poisson (double u)
{
  //## begin RandomNG::poisson%3B949DA100E1.body preserve=yes
	assert(generator);
	return generator->poisson(u);
  //## end RandomNG::poisson%3B949DA100E1.body
}

//## Operation: init%34BC9073022E
inline void RandomNG::init (unsigned iseed)
{
  //## begin RandomNG::init%34BC9073022E.body preserve=yes
	if(generator)
		delete generator;
	generator = new RandGenerator(iseed);
  //## end RandomNG::init%34BC9073022E.body
}

//## begin module%35D2B1B1018C.epilog preserve=yes
//## end module%35D2B1B1018C.epilog


#endif

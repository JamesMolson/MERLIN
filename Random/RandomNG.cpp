//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%35D2B1BF02B9.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\Random\RandomNG.cpp
 * last modified 09/04/01 11:26:28 AM
 */
//## end module%35D2B1BF02B9.cm

//## begin module%35D2B1BF02B9.cp preserve=no
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
//## end module%35D2B1BF02B9.cp

//## Module: RandomNG%35D2B1BF02B9; Package body
//## Subsystem: Merlin::Random%35D2B1A20307
//## Source file: C:\C++\Merlin\Random\RandomNG.cpp

//## begin module%35D2B1BF02B9.includes preserve=yes
#include "Random/ACG.h"
#include "Random/Normal.h"
#include "Random/Uniform.h"
#include "Random/Poisson.h"
#include <cassert>
//## end module%35D2B1BF02B9.includes

// RandomNG
#include "Random/RandomNG.h"
//## begin module%35D2B1BF02B9.additionalDeclarations preserve=yes

namespace {

	// table size for random number generator
	#define TABLE_SIZE 100

};

//## end module%35D2B1BF02B9.additionalDeclarations


// Class Utility RandomNG 

//## begin RandomNG::generator%35D2B11F02CD.role preserve=no  implementation: RandGenerator { -> RHgAN}
RandGenerator* RandomNG::generator;
//## end RandomNG::generator%35D2B11F02CD.role

// Class RandGenerator 



//## Operation: RandGenerator%35D2B3980038
RandGenerator::RandGenerator (unsigned iseed)
  //## begin RandGenerator::RandGenerator%35D2B3980038.hasinit preserve=no
      : nseed(iseed),
  //## end RandGenerator::RandGenerator%35D2B3980038.hasinit
  //## begin RandGenerator::RandGenerator%35D2B3980038.initialization preserve=yes
  gen(0),gaussGen(0),uniformGen(0),poissonGen(0)
  //## end RandGenerator::RandGenerator%35D2B3980038.initialization
{
  //## begin RandGenerator::RandGenerator%35D2B3980038.body preserve=yes
	reset(nseed);
  //## end RandGenerator::RandGenerator%35D2B3980038.body
}


//## Operation: ~RandGenerator%35D2B3C6003E
RandGenerator::~RandGenerator ()
{
  //## begin RandGenerator::~RandGenerator%35D2B3C6003E.body preserve=yes
	if(gen) 
		delete gen;
	if(gaussGen) 
		delete gaussGen;
	if(uniformGen) 
		delete uniformGen;
	if(poissonGen)
		delete poissonGen;
  //## end RandGenerator::~RandGenerator%35D2B3C6003E.body
}



//## Other Operations (implementation)
//## Operation: reset%35D2B0FE010D
void RandGenerator::reset ()
{
  //## begin RandGenerator::reset%35D2B0FE010D.body preserve=yes
	assert(gen);
	gen->reset();
	ResetGenerators();
  //## end RandGenerator::reset%35D2B0FE010D.body
}

//## Operation: reset%35D2B0FE0352
void RandGenerator::reset (unsigned iseed)
{
  //## begin RandGenerator::reset%35D2B0FE0352.body preserve=yes
	if(gen)
		delete gen;
	nseed = iseed;
	gen = new ACG(nseed,TABLE_SIZE);
	ResetGenerators();
  //## end RandGenerator::reset%35D2B0FE0352.body
}

//## Operation: normal%35D2B0FF01A5
double RandGenerator::normal (double mean, double variance)
{
  //## begin RandGenerator::normal%35D2B0FF01A5.body preserve=yes
	assert(gen && variance>=0);
	gaussGen->mean(mean);
	gaussGen->variance(variance);
	return (*gaussGen)();
  //## end RandGenerator::normal%35D2B0FF01A5.body
}

//## Operation: normal%35D2B0FF03DF
double RandGenerator::normal (double mean, double variance, double cutoff)
{
  //## begin RandGenerator::normal%35D2B0FF03DF.body preserve=yes
	assert(gen);
	if(cutoff==0)
		return normal(mean,variance);
	
	cutoff=fabs(cutoff)*sqrt(variance);

	gaussGen->mean(mean);
	gaussGen->variance(variance);
	double x=(*gaussGen)();
	while(fabs(x-mean)>cutoff)
		x=(*gaussGen)();
	return x;
  //## end RandGenerator::normal%35D2B0FF03DF.body
}

//## Operation: uniform%35D2B100023C
double RandGenerator::uniform (double low, double high)
{
  //## begin RandGenerator::uniform%35D2B100023C.body preserve=yes
	assert(gen);
	uniformGen->low(low);
	uniformGen->high(high);
	return (*uniformGen)();
  //## end RandGenerator::uniform%35D2B100023C.body
}

//## Operation: poisson%3B949DF70199
double RandGenerator::poisson (double u)
{
  //## begin RandGenerator::poisson%3B949DF70199.body preserve=yes
	assert(gen);
	poissonGen->mean(u);
	return (*poissonGen)();
  //## end RandGenerator::poisson%3B949DF70199.body
}

//## Operation: init%35D2B101008F
void RandGenerator::init (unsigned iseed)
{
  //## begin RandGenerator::init%35D2B101008F.body preserve=yes
	reset(iseed);
  //## end RandGenerator::init%35D2B101008F.body
}

//## Operation: ResetGenerators%35D2B3A0021A
void RandGenerator::ResetGenerators ()
{
  //## begin RandGenerator::ResetGenerators%35D2B3A0021A.body preserve=yes
	if(gaussGen)
		delete gaussGen;
	if(uniformGen)
		delete uniformGen;
	if(poissonGen)
		delete poissonGen;

	gaussGen = new Normal(0,1,gen);
	uniformGen = new Uniform(0,1,gen);
	poissonGen = new Poisson(1,gen);
  //## end RandGenerator::ResetGenerators%35D2B3A0021A.body
}

//## begin module%35D2B1BF02B9.epilog preserve=yes
//## end module%35D2B1BF02B9.epilog

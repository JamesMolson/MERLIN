//## begin module%37C533BD01A0.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunchConstructor.cpp
 * last modified 26/04/01 10:44:50
 */
//## end module%37C533BD01A0.cm

//## begin module%37C533BD01A0.cp preserve=no
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
//## end module%37C533BD01A0.cp

//## Module: ParticleBunchConstructor%37C533BD01A0; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: D:\dev\Merlin\BeamDynamics\ParticleTracking\ParticleBunchConstructor.cpp

//## begin module%37C533BD01A0.includes preserve=yes
#include "BasicTransport/NormalTransform.h"
#include <memory>
//## end module%37C533BD01A0.includes

// ParticleBunchConstructor
#include "BeamDynamics/ParticleTracking/ParticleBunchConstructor.h"
// RandomNG
#include "Random/RandomNG.h"
//## begin module%37C533BD01A0.declarations preserve=no
//## end module%37C533BD01A0.declarations

//## begin module%37C533BD01A0.additionalDeclarations preserve=yes
//## end module%37C533BD01A0.additionalDeclarations


// Class ParticleBunchConstructor 







//## Operation: ParticleBunchConstructor%925486244
ParticleBunchConstructor::ParticleBunchConstructor (const BeamData& beam, size_t npart, DistributionType dist)
  //## begin ParticleBunchConstructor::ParticleBunchConstructor%925486244.initialization preserve=yes
: np(npart),dtype(dist),cutOff(0),beamdat(beam),itsFilter(0),M(NormalTransform(beam))
  //## end ParticleBunchConstructor::ParticleBunchConstructor%925486244.initialization
{
  //## begin ParticleBunchConstructor::ParticleBunchConstructor%925486244.body preserve=yes
  //## end ParticleBunchConstructor::ParticleBunchConstructor%925486244.body
}


//## Operation: ~ParticleBunchConstructor%935667557
ParticleBunchConstructor::~ParticleBunchConstructor ()
{
  //## begin ParticleBunchConstructor::~ParticleBunchConstructor%935667557.body preserve=yes
	if(itsFilter)
		delete itsFilter;
  //## end ParticleBunchConstructor::~ParticleBunchConstructor%935667557.body
}



//## Other Operations (implementation)
//## Operation: SetBunchData%925486245
void ParticleBunchConstructor::SetBunchData (const BeamData& beam)
{
  //## begin ParticleBunchConstructor::SetBunchData%925486245.body preserve=yes
	beamdat = beam;
	M.R = NormalTransform(beam);
  //## end ParticleBunchConstructor::SetBunchData%925486245.body
}

//## Operation: SetNumParticles%925486246
void ParticleBunchConstructor::SetNumParticles (size_t npart)
{
  //## begin ParticleBunchConstructor::SetNumParticles%925486246.body preserve=yes
	assert(npart>0);
	np=npart;
  //## end ParticleBunchConstructor::SetNumParticles%925486246.body
}

//## Operation: SetDistributionCutoff%958127065
void ParticleBunchConstructor::SetDistributionCutoff (double cut)
{
  //## begin ParticleBunchConstructor::SetDistributionCutoff%958127065.body preserve=yes
	cutOff = fabs(cut);
  //## end ParticleBunchConstructor::SetDistributionCutoff%958127065.body
}

//## Operation: ConstructBunch%925486247
Bunch* ParticleBunchConstructor::ConstructBunch () const
{
  //## begin ParticleBunchConstructor::ConstructBunch%925486247.body preserve=yes
	PSvectorArray pbunch;
	PSvector p;
		
	// First we generate npart particles in "normalised" phase
	// space, after which we transform them to "real" phase
	// space using M.
	
	// The first particle is *always* the centroid particle
	
	double dp2 = pow(beamdat.sig_dp,2);
	double dz2 = pow(beamdat.sig_z,2);
	double rx,ry;
	
	p.x()=beamdat.x0;
	p.xp()=beamdat.xp0;
	p.y()=beamdat.y0;
	p.yp()=beamdat.yp0;
	p.dp()=0;
	p.ct()=0;
	pbunch.push_back(p);
	
	size_t i;
	
	switch(dtype) {
	case normalDistribution:
		
		for(i=1; i<np;) {
			if(cutOff!=0) {
				p.x()	= RandomNG::normal(0,beamdat.emit_x,cutOff);
				p.xp()	= RandomNG::normal(0,beamdat.emit_x,cutOff);
				p.y()	= RandomNG::normal(0,beamdat.emit_y,cutOff);
				p.yp()	= RandomNG::normal(0,beamdat.emit_y,cutOff);
				p.dp()	= RandomNG::normal(0,dp2,cutOff);
				p.ct()	= RandomNG::normal(0,dz2,cutOff);
			}
			else {
				p.x()	= RandomNG::normal(0,beamdat.emit_x);
				p.xp()	= RandomNG::normal(0,beamdat.emit_x);
				p.y()	= RandomNG::normal(0,beamdat.emit_y);
				p.yp()	= RandomNG::normal(0,beamdat.emit_y);
				p.dp()	= RandomNG::normal(0,dp2);
				p.ct()	= RandomNG::normal(0,dz2);
			}
			
			M.Apply(p);
			p+=pbunch.front(); // add centroid
			
			if(itsFilter==0 || itsFilter->Apply(p)) {
				pbunch.push_back(p);
				i++;
			}
		}
		break;
	case flatDistribution:
		rx = sqrt(beamdat.emit_x);
		ry = sqrt(beamdat.emit_y);
		for(i=1; i<np;) {
			p.x()	= RandomNG::uniform(-rx,rx);
			p.xp()	= RandomNG::uniform(-rx,rx);
			p.y()	= RandomNG::uniform(-ry,ry);
			p.yp()	= RandomNG::uniform(-ry,ry);
			p.dp()	= RandomNG::uniform(-beamdat.sig_dp,beamdat.sig_dp);
			p.ct()	= RandomNG::uniform(-beamdat.sig_z,beamdat.sig_z);
			M.Apply(p);
			p+=pbunch.front(); // add centroid
			
			if(itsFilter==0 || itsFilter->Apply(p)) {
				pbunch.push_back(p);
				i++;
			}
		}
		break;
	};
	
	return new ParticleBunch(beamdat.p0,beamdat.charge,pbunch);
  //## end ParticleBunchConstructor::ConstructBunch%925486247.body
}

// Class ParticleBunchFilter 


//## Operation: ~ParticleBunchFilter%935667559
ParticleBunchFilter::~ParticleBunchFilter ()
{
  //## begin ParticleBunchFilter::~ParticleBunchFilter%935667559.body preserve=yes
	// Nothing to do
  //## end ParticleBunchFilter::~ParticleBunchFilter%935667559.body
}


//## begin module%37C533BD01A0.epilog preserve=yes
//## end module%37C533BD01A0.epilog

//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%37C533BD01A0.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunchConstructor.cpp
 * last modified 14/10/02 11:01:55
 */
//## end module%37C533BD01A0.cm

//## begin module%37C533BD01A0.cp preserve=no
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
//## end module%37C533BD01A0.cp

//## Module: ParticleBunchConstructor%37C533BD01A0; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleBunchConstructor.cpp

//## begin module%37C533BD01A0.includes preserve=yes
#include "BasicTransport/NormalTransform.h"
#include <memory>
//## end module%37C533BD01A0.includes

// RandomNG
#include "Random/RandomNG.h"
// ParticleBunchConstructor
#include "BeamDynamics/ParticleTracking/ParticleBunchConstructor.h"
//## begin module%37C533BD01A0.additionalDeclarations preserve=yes

inline double RandomGauss(double variance, double cutoff)
{
	return cutoff==0 ? RandomNG::normal(0,variance) :  RandomNG::normal(0,variance,cutoff);
}

//## end module%37C533BD01A0.additionalDeclarations


// Class ParticleBunchConstructor 

//## Operation: ParticleBunchConstructor%3729D40C0000
ParticleBunchConstructor::ParticleBunchConstructor (const BeamData& beam, size_t npart, DistributionType dist)
  //## begin ParticleBunchConstructor::ParticleBunchConstructor%3729D40C0000.initialization preserve=yes
: np(npart),dtype(dist),cutoffs(0),beamdat(beam),itsFilter(0),M(NormalTransform(beam)),force_c(false)
  //## end ParticleBunchConstructor::ParticleBunchConstructor%3729D40C0000.initialization
{
  //## begin ParticleBunchConstructor::ParticleBunchConstructor%3729D40C0000.body preserve=yes
  //## end ParticleBunchConstructor::ParticleBunchConstructor%3729D40C0000.body
}


//## Operation: ~ParticleBunchConstructor%37C53614010B
ParticleBunchConstructor::~ParticleBunchConstructor ()
{
  //## begin ParticleBunchConstructor::~ParticleBunchConstructor%37C53614010B.body preserve=yes
	if(itsFilter)
		delete itsFilter;
  //## end ParticleBunchConstructor::~ParticleBunchConstructor%37C53614010B.body
}



//## Other Operations (implementation)
//## Operation: SetBunchData%3729D1110050
void ParticleBunchConstructor::SetBunchData (const BeamData& beam)
{
  //## begin ParticleBunchConstructor::SetBunchData%3729D1110050.body preserve=yes
	beamdat = beam;
	M.R = NormalTransform(beam);
  //## end ParticleBunchConstructor::SetBunchData%3729D1110050.body
}

//## Operation: SetNumParticles%3729D12201EA
void ParticleBunchConstructor::SetNumParticles (size_t npart)
{
  //## begin ParticleBunchConstructor::SetNumParticles%3729D12201EA.body preserve=yes
	assert(npart>0);
	np=npart;
  //## end ParticleBunchConstructor::SetNumParticles%3729D12201EA.body
}

//## Operation: SetDistributionCutoff%391BDB120320
void ParticleBunchConstructor::SetDistributionCutoff (double cut)
{
  //## begin ParticleBunchConstructor::SetDistributionCutoff%391BDB120320.body preserve=yes
	cutoffs = PSvector(fabs(cut));
  //## end ParticleBunchConstructor::SetDistributionCutoff%391BDB120320.body
}

//## Operation: SetDistributionCutoff%3DAA874F00C2
void ParticleBunchConstructor::SetDistributionCutoff (const PSvector& cut)
{
  //## begin ParticleBunchConstructor::SetDistributionCutoff%3DAA874F00C2.body preserve=yes
	cutoffs=cut;
  //## end ParticleBunchConstructor::SetDistributionCutoff%3DAA874F00C2.body
}

//## Operation: ConstructBunch%3729CF89015E
Bunch* ParticleBunchConstructor::ConstructBunch (int bunchIndex) const
{
  //## begin ParticleBunchConstructor::ConstructBunch%3729CF89015E.body preserve=yes
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
	p.ct()=beamdat.ct0;
	pbunch.push_back(p);
	
	size_t i;
	
	
	PSvector xm = p; // used for calculating mean
	
	switch(dtype) {
	case normalDistribution:	
		for(i=1; i<np;) {
			p.x()	= RandomGauss(beamdat.emit_x,cutoffs.x());
			p.xp()	= RandomGauss(beamdat.emit_x,cutoffs.xp());
			p.y()	= RandomGauss(beamdat.emit_y,cutoffs.y());
			p.yp()	= RandomGauss(beamdat.emit_y,cutoffs.yp());
			p.dp()	= RandomGauss(dp2,cutoffs.dp());
			p.ct()	= RandomGauss(dz2,cutoffs.ct());
			
			M.Apply(p);
			p+=pbunch.front(); // add centroid
			
			if(itsFilter==0 || itsFilter->Apply(p)) {
				pbunch.push_back(p);
				xm += p;
				i++;
			}
			
		}
		if(force_c) {
			xm/=np;
			xm-=pbunch.front();
			PSvectorArray::iterator pp=pbunch.begin();
			pp++;
			for(;pp!=pbunch.end(); pp++)
				(*pp)-=xm;
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
  //## end ParticleBunchConstructor::ConstructBunch%3729CF89015E.body
}

//## Operation: ForceCentroid%3C0B9C0700BC
void ParticleBunchConstructor::ForceCentroid (bool fc)
{
  //## begin ParticleBunchConstructor::ForceCentroid%3C0B9C0700BC.body preserve=yes
	force_c = fc;
  //## end ParticleBunchConstructor::ForceCentroid%3C0B9C0700BC.body
}

// Class ParticleBunchFilter 

//## Operation: ~ParticleBunchFilter%37C5331D02C2
ParticleBunchFilter::~ParticleBunchFilter ()
{
  //## begin ParticleBunchFilter::~ParticleBunchFilter%37C5331D02C2.body preserve=yes
	// Nothing to do
  //## end ParticleBunchFilter::~ParticleBunchFilter%37C5331D02C2.body
}


//## begin module%37C533BD01A0.epilog preserve=yes
//## end module%37C533BD01A0.epilog

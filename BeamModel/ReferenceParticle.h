//## begin module%37147AA0030C.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamModel\ReferenceParticle.h
 * last modified 19/04/01 16:56:16
 */
//## end module%37147AA0030C.cm

//## begin module%37147AA0030C.cp preserve=no
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
//## end module%37147AA0030C.cp

//## Module: ReferenceParticle%37147AA0030C; Package specification
//## Subsystem: Merlin::BeamModel%3ACB10800370
//## Source file: D:\dev\Merlin\BeamModel\ReferenceParticle.h

#ifndef ReferenceParticle_h
#define ReferenceParticle_h 1

//## begin module%37147AA0030C.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37147AA0030C.additionalIncludes

//## begin module%37147AA0030C.includes preserve=yes
#include <cassert>
//## end module%37147AA0030C.includes

//## begin module%37147AA0030C.declarations preserve=no
//## end module%37147AA0030C.declarations

//## begin module%37147AA0030C.additionalDeclarations preserve=yes
//## end module%37147AA0030C.additionalDeclarations


//## Class: ReferenceParticle%36A7619A0032
//	A ReferenceParticle represents that particle which sits
//	on the nominal orbit. It is responsible for maintaining
//	the reference momentum and time (ct) for the bunch or
//	map. ReferenceParticle cannot be instantiated, but is
//	designed as a mixin for bunch or map-like classes.
//## Category: Merlin::BeamModel%3ACB0C800384
//## Subsystem: Merlin::BeamModel%3ACB10800370
//## Persistence: Transient
//## Cardinality/Multiplicity: 0..0

class ReferenceParticle 
{
  public:

    //## Other Operations (specified)
      //## Operation: GetReferenceMomentum%924072846
      //	Returns the reference momentum in GeV/c.
      double GetReferenceMomentum () const;

      //## Operation: GetReferenceTime%924072847
      //	Returns the reference time in ct (meters).
      double GetReferenceTime () const;

      //## Operation: GetChargeSign%924072848
      //	Returns either +1, 0 or -1.
      double GetChargeSign () const;

      //## Operation: SetReferenceMomentum%924072849
      //	Sets the reference momentum to p GeV/c. p must be
      //	greater than zero.
      void SetReferenceMomentum (double p);

      //## Operation: IncrReferenceMomentum%924072850
      //	Increments the reference momentum by dp GeV/c, returning
      //	the new value.
      double IncrReferenceMomentum (double dp);

      //## Operation: SetReferenceTime%924072851
      //	Sets the reference time in ct (meters).
      void SetReferenceTime (double ct);

      //## Operation: IncrReferenceTime%924072852
      //	Increments the reference time by dct meters.
      double IncrReferenceTime (double dct);

  protected:
    //## Constructors (specified)
      //## Operation: ReferenceParticle%924072853
      ReferenceParticle (double p, double q = 1);


    //## Other Operations (specified)
      //## Operation: SetChargeSign%987686382
      //	Sets the charge sign.
      void SetChargeSign (double q);

    // Data Members for Class Attributes

      //## Attribute: p0%36A761AD03AC
      //	reference momentum in GeV/c
      //## begin ReferenceParticle::p0%36A761AD03AC.attr preserve=no  protected: double {UA} 
      double p0;
      //## end ReferenceParticle::p0%36A761AD03AC.attr

      //## Attribute: ct0%36A761C102C6
      //	reference time in ct (meters)
      //## begin ReferenceParticle::ct0%36A761C102C6.attr preserve=no  protected: double {UA} 
      double ct0;
      //## end ReferenceParticle::ct0%36A761C102C6.attr

      //## Attribute: qs%36A761CB010E
      //	The charge sign of the particles.
      //## begin ReferenceParticle::qs%36A761CB010E.attr preserve=no  protected: double {UA} 
      double qs;
      //## end ReferenceParticle::qs%36A761CB010E.attr

  private:
  private:  //## implementation
};

// Class ReferenceParticle 

//## Operation: ReferenceParticle%924072853
inline ReferenceParticle::ReferenceParticle (double p, double q)
  //## begin ReferenceParticle::ReferenceParticle%924072853.initialization preserve=yes
  : p0(p),ct0(0)
  //## end ReferenceParticle::ReferenceParticle%924072853.initialization
{
  //## begin ReferenceParticle::ReferenceParticle%924072853.body preserve=yes
	assert(p>0);
	SetChargeSign(q);
  //## end ReferenceParticle::ReferenceParticle%924072853.body
}



//## Other Operations (inline)
//## Operation: GetReferenceMomentum%924072846
inline double ReferenceParticle::GetReferenceMomentum () const
{
  //## begin ReferenceParticle::GetReferenceMomentum%924072846.body preserve=yes
	return p0;
  //## end ReferenceParticle::GetReferenceMomentum%924072846.body
}

//## Operation: GetReferenceTime%924072847
inline double ReferenceParticle::GetReferenceTime () const
{
  //## begin ReferenceParticle::GetReferenceTime%924072847.body preserve=yes
	return ct0;
  //## end ReferenceParticle::GetReferenceTime%924072847.body
}

//## Operation: GetChargeSign%924072848
inline double ReferenceParticle::GetChargeSign () const
{
  //## begin ReferenceParticle::GetChargeSign%924072848.body preserve=yes
	return qs;
  //## end ReferenceParticle::GetChargeSign%924072848.body
}

//## Operation: SetReferenceMomentum%924072849
inline void ReferenceParticle::SetReferenceMomentum (double p)
{
  //## begin ReferenceParticle::SetReferenceMomentum%924072849.body preserve=yes
	p0=p;
	assert(p0>0);
  //## end ReferenceParticle::SetReferenceMomentum%924072849.body
}

//## Operation: IncrReferenceMomentum%924072850
inline double ReferenceParticle::IncrReferenceMomentum (double dp)
{
  //## begin ReferenceParticle::IncrReferenceMomentum%924072850.body preserve=yes
	p0+=dp;
	assert(p0>0);
	return p0;
  //## end ReferenceParticle::IncrReferenceMomentum%924072850.body
}

//## Operation: SetReferenceTime%924072851
inline void ReferenceParticle::SetReferenceTime (double ct)
{
  //## begin ReferenceParticle::SetReferenceTime%924072851.body preserve=yes
	ct0=ct;
  //## end ReferenceParticle::SetReferenceTime%924072851.body
}

//## Operation: IncrReferenceTime%924072852
inline double ReferenceParticle::IncrReferenceTime (double dct)
{
  //## begin ReferenceParticle::IncrReferenceTime%924072852.body preserve=yes
	ct0+=dct;
	return ct0;
  //## end ReferenceParticle::IncrReferenceTime%924072852.body
}

//## Operation: SetChargeSign%987686382
inline void ReferenceParticle::SetChargeSign (double q)
{
  //## begin ReferenceParticle::SetChargeSign%987686382.body preserve=yes
	if(q<0)
		qs=-1;
	else if(q==0)
		qs=0;
	else
		qs=1;
  //## end ReferenceParticle::SetChargeSign%987686382.body
}

// Class ReferenceParticle 




//## begin module%37147AA0030C.epilog preserve=yes
//## end module%37147AA0030C.epilog


#endif

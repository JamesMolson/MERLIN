//## begin module%3AE0333C02EE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunchIntegrator.h
 * last modified 26/04/01 10:44:49
 */
//## end module%3AE0333C02EE.cm

//## begin module%3AE0333C02EE.cp preserve=no
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
//## end module%3AE0333C02EE.cp

//## Module: ParticleBunchIntegrator%3AE0333C02EE; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: D:\dev\Merlin\BeamDynamics\ParticleTracking\ParticleBunchIntegrator.h

#ifndef ParticleBunchIntegrator_h
#define ParticleBunchIntegrator_h 1

//## begin module%3AE0333C02EE.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE0333C02EE.additionalIncludes

//## begin module%3AE0333C02EE.includes preserve=yes
//## end module%3AE0333C02EE.includes

// ParticleBunch
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"
// ComponentIntegrator
#include "AcceleratorModel/TrackingInterface/ComponentIntegrator.h"
//## begin module%3AE0333C02EE.declarations preserve=no
//## end module%3AE0333C02EE.declarations

//## begin module%3AE0333C02EE.additionalDeclarations preserve=yes
//## end module%3AE0333C02EE.additionalDeclarations


//## Class: ParticleBunchIntegrator%36E7AF520232; Abstract
//	Responsible for tracking particles through accelerator
//	components.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ParticleBunchIntegrator : public ComponentIntegrator  //## Inherits: <unnamed>%3729F2A3003C
{
  public:

    //## Other Operations (specified)
      //## Operation: SetParticleBunch%925486252
      void SetParticleBunch (ParticleBunch* bunch);

      //## Operation: GetBunch%925994473
      ParticleBunch& GetBunch ();

  protected:

    //## Other Operations (specified)
      //## Operation: IncrStep%926157716
      double IncrStep (double ds);

  private:
    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::<unnamed>%36EE4B8602CE
      //## Role: ParticleBunchIntegrator::theBunch%36EE4B8602D0
      //## begin ParticleBunchIntegrator::theBunch%36EE4B8602D0.role preserve=no  private: ParticleBunch { -> 0..1RHAN}
      ParticleBunch* theBunch;
      //## end ParticleBunchIntegrator::theBunch%36EE4B8602D0.role

  private:  //## implementation
};

//## Class: TParticleI%36EE4C6E015F; Parameterized Class
//	Template class to automate downcasting of Accelerator
//	Component to correct (concrete) type. The template
//	argument must be a valid AcceleratorComponent class.
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class C>
class TParticleI : public ParticleBunchIntegrator  //## Inherits: <unnamed>%36EE4C7D03B9
{
  public:

    //## Other Operations (specified)
      //## Operation: Component%925486261
      C& Component ();

      //## Operation: GetComponentIndex%925486262
      virtual int GetComponentIndex () const;

  protected:
  private:
  private:  //## implementation
};

// Class ParticleBunchIntegrator 


//## Other Operations (inline)
//## Operation: SetParticleBunch%925486252
inline void ParticleBunchIntegrator::SetParticleBunch (ParticleBunch* bunch)
{
  //## begin ParticleBunchIntegrator::SetParticleBunch%925486252.body preserve=yes
	theBunch = bunch;
  //## end ParticleBunchIntegrator::SetParticleBunch%925486252.body
}

//## Operation: GetBunch%925994473
inline ParticleBunch& ParticleBunchIntegrator::GetBunch ()
{
  //## begin ParticleBunchIntegrator::GetBunch%925994473.body preserve=yes
	return *theBunch;
  //## end ParticleBunchIntegrator::GetBunch%925994473.body
}

//## Operation: IncrStep%926157716
inline double ParticleBunchIntegrator::IncrStep (double ds)
{
  //## begin ParticleBunchIntegrator::IncrStep%926157716.body preserve=yes
	theBunch->IncrReferenceTime(ds);
	return ComponentIntegrator::IncrStep(ds);
  //## end ParticleBunchIntegrator::IncrStep%926157716.body
}

// Parameterized Class TParticleI 


//## Other Operations (inline)
//## Operation: Component%925486261
template <class C>
inline C& TParticleI<C>::Component ()
{
  //## begin TParticleI::Component%925486261.body preserve=yes
	return static_cast<C&>(GetCurrentComponent());
  //## end TParticleI::Component%925486261.body
}

// Class ParticleBunchIntegrator 


// Parameterized Class TParticleI 


//## Other Operations (implementation)
//## Operation: GetComponentIndex%925486262
template <class C>
int TParticleI<C>::GetComponentIndex () const
{
  //## begin TParticleI::GetComponentIndex%925486262.body preserve=yes
	return C::ID;
  //## end TParticleI::GetComponentIndex%925486262.body
}

//## begin module%3AE0333C02EE.epilog preserve=yes
//## end module%3AE0333C02EE.epilog


#endif

//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3B73CEA0035D.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleMapComponent.h
 * last modified 26/09/02 15:18:13
 */
//## end module%3B73CEA0035D.cm

//## begin module%3B73CEA0035D.cp preserve=no
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
//## end module%3B73CEA0035D.cp

//## Module: ParticleMapComponent%3B73CEA0035D; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleMapComponent.h

#ifndef ParticleMapComponent_h
#define ParticleMapComponent_h 1

//## begin module%3B73CEA0035D.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3B73CEA0035D.additionalIncludes

//## begin module%3B73CEA0035D.includes preserve=yes
//## end module%3B73CEA0035D.includes

// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"
// ParticleMap
#include "BeamDynamics/ParticleTracking/ParticleMap.h"

class ParticleBunch;

//## begin module%3B73CEA0035D.additionalDeclarations preserve=yes
//## end module%3B73CEA0035D.additionalDeclarations


//## Class: ParticleMapComponent%3B73CB0902A7
//	A special AcceleratorComponent that allows an arbitrary
//	map (ParticleMap) to be placed into the accelerator
//	model.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3B73CE5C020B;ParticleBunch { -> F}
//## Uses: <unnamed>%3B73D1F50287;ComponentTracker { -> }

class ParticleMapComponent : public AcceleratorComponent  //## Inherits: <unnamed>%3B73CB22004A
{
  public:
    //## Constructors (specified)
      //## Operation: ParticleMapComponent%3B73CCE10115
      ParticleMapComponent (const std::string& id, ParticleMap* pmap, double intB2ds = 0);


    //## Other Operations (specified)
      //## Operation: GetType%3B73CD0E0297
      //	Return the type string for the element.
      virtual const string& GetType () const;

      //## Operation: Copy%3B73CD1503E1
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

      //## Operation: GetIndex%3B73CD710018
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: RotateY180%3B73CD7F03E4
      //	Rotates the component 180 degrees about its local Y axis.
      virtual void RotateY180 ();

      //## Operation: Apply%3B73CD9E006D
      ParticleBunch& Apply (ParticleBunch& bunch) const;

      //## Operation: PrepareTracker%3B73D1520124
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIntB2ds%3D93087C02A0
      //	Returns the integral of B^2 for synchrotron radiation
      //	applications
      double GetIntB2ds () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3B73CD3D00A0
      //	Unique index for an Accelerator component.
      //## begin ParticleMapComponent::ID%3B73CD3D00A0.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end ParticleMapComponent::ID%3B73CD3D00A0.attr

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: ib2%3D93086E02BE
      //## begin ParticleMapComponent::ib2%3D93086E02BE.attr preserve=no  private: double {UA} 
      double ib2;
      //## end ParticleMapComponent::ib2%3D93086E02BE.attr

    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::<unnamed>%3B73CB9202A4
      //## Role: ParticleMapComponent::itsMap%3B73CB930101
      //## begin ParticleMapComponent::itsMap%3B73CB930101.role preserve=no  private: ParticleMap { -> 0..1VHgAN}
      ParticleMap* itsMap;
      //## end ParticleMapComponent::itsMap%3B73CB930101.role

  private: //## implementation
};

// Class ParticleMapComponent 


//## Other Operations (inline)
//## Operation: Apply%3B73CD9E006D
inline ParticleBunch& ParticleMapComponent::Apply (ParticleBunch& bunch) const
{
  //## begin ParticleMapComponent::Apply%3B73CD9E006D.body preserve=yes
	return itsMap->Apply(bunch);
  //## end ParticleMapComponent::Apply%3B73CD9E006D.body
}

//## Operation: GetIntB2ds%3D93087C02A0
inline double ParticleMapComponent::GetIntB2ds () const
{
  //## begin ParticleMapComponent::GetIntB2ds%3D93087C02A0.body preserve=yes
    return ib2; 
  //## end ParticleMapComponent::GetIntB2ds%3D93087C02A0.body
}

//## begin module%3B73CEA0035D.epilog preserve=yes
//## end module%3B73CEA0035D.epilog


#endif

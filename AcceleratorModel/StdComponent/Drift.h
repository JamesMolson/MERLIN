//## begin module%373409030212.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\Drift.h
 * last modified 04/04/01 15:25:43
 */
//## end module%373409030212.cm

//## begin module%373409030212.cp preserve=no
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
//## end module%373409030212.cp

//## Module: Drift%373409030212; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\Drift.h

#ifndef Drift_h
#define Drift_h 1

//## begin module%373409030212.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%373409030212.additionalIncludes

//## begin module%373409030212.includes preserve=yes
//## end module%373409030212.includes

// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// SimpleDrift
#include "AcceleratorModel/StdComponent/SimpleDrift.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"

class ComponentTracker;

//## begin module%373409030212.declarations preserve=no
//## end module%373409030212.declarations

//## begin module%373409030212.additionalDeclarations preserve=yes
//## end module%373409030212.additionalDeclarations


//## Class: Drift%33CE04B2020A
//	A simple drift section.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%371EEB3C00A0;ComponentTracker { -> F}
//## Uses: <unnamed>%371F07D402E4;TAccCompG { -> }
//## Uses: <unnamed>%371EEB0D02BC;RectangularGeometry { -> }

class Drift : public SimpleDrift  //## Inherits: <unnamed>%371F074100A0
{
  public:
    //## Constructors (specified)
      //## Operation: Drift%924771612
      explicit Drift (const string& id, double len = 0);


    //## Other Operations (specified)
      //## Operation: GetType%924771613
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: GetIndex%924771614
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: PrepareTracker%924771615
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: RotateY180%924771616
      //	Rotates the component 180 degrees about its local Y axis.
      virtual void RotateY180 ();

      //## Operation: Copy%924771617
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%371EEB700046
      //	Unique index for an Accelerator component.
      //## begin Drift::ID%371EEB700046.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end Drift::ID%371EEB700046.attr

  protected:
  private:
  private:  //## implementation
};

// Class Drift 

//## begin module%373409030212.epilog preserve=yes
//## end module%373409030212.epilog


#endif

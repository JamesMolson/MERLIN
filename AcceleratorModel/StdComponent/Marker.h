//## begin module%356ACBD70358.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\Marker.h
 * last modified 03/04/01 15:01:20
 */
//## end module%356ACBD70358.cm

//## begin module%356ACBD70358.cp preserve=no
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
//## end module%356ACBD70358.cp

//## Module: Marker%356ACBD70358; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\Marker.h

#ifndef Marker_h
#define Marker_h 1

//## begin module%356ACBD70358.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%356ACBD70358.additionalIncludes

//## begin module%356ACBD70358.includes preserve=yes
//## end module%356ACBD70358.includes

// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"

class ComponentTracker;

//## begin module%356ACBD70358.additionalDeclarations preserve=yes
//## end module%356ACBD70358.additionalDeclarations


//## Class: Marker%356ACBD70358
//	Special Marker component. This does not represent a
//	physical component, and is provided for uses wishing to
//	"mark" specific locations in the lattice. It has no
//	field or geometry associated with it.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%371EE8A0017C;ComponentTracker { -> F}

class Marker : public AcceleratorComponent  //## Inherits: <unnamed>%37032D530149
{
  public:
    //## Constructors (specified)
      //## Operation: Marker%896185770; C++
      //	Constructor
      explicit Marker (const std::string& id);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%924771607
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%924771608
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetType%924771609
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: Copy%924771610
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

      //## Operation: RotateY180%924771611
      //	Rotates the component 180 degrees about its local Y axis.
      virtual void RotateY180 ();

    // Data Members for Class Attributes

      //## Attribute: ID%371EE4FB038E
      //	Unique index for an Accelerator component.
      //## begin Marker::ID%371EE4FB038E.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end Marker::ID%371EE4FB038E.attr

  protected:
  private:
  private:  //## implementation
};

// Class Marker 

//## Operation: Marker%896185770; C++
//## Qualification: explicit inlined
inline Marker::Marker (const std::string& id)
  //## begin Marker::Marker%896185770.initialization preserve=yes
  : AcceleratorComponent(id,0,0)
  //## end Marker::Marker%896185770.initialization
{
  //## begin Marker::Marker%896185770.body preserve=yes
  //## end Marker::Marker%896185770.body
}


//## begin module%356ACBD70358.epilog preserve=yes
//## end module%356ACBD70358.epilog


#endif

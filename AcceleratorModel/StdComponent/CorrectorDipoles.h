//## begin module%372485600348.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\CorrectorDipoles.h
 * last modified 03/04/01 14:21:37
 */
//## end module%372485600348.cm

//## begin module%372485600348.cp preserve=no
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
//## end module%372485600348.cp

//## Module: CorrectorDipoles%372485600348; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\CorrectorDipoles.h

#ifndef CorrectorDipoles_h
#define CorrectorDipoles_h 1

//## begin module%372485600348.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%372485600348.additionalIncludes

//## begin module%372485600348.includes preserve=yes
//## end module%372485600348.includes

// RectMultipole
#include "AcceleratorModel/StdComponent/RectMultipole.h"

class ComponentTracker;

//## begin module%372485600348.declarations preserve=no
//## end module%372485600348.declarations

//## begin module%372485600348.additionalDeclarations preserve=yes
//## end module%372485600348.additionalDeclarations


//## Class: XCor%3724839A000A
//	A horizontal corrector dipole.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%37248656035C;ComponentTracker { -> F}

class XCor : public RectMultipole  //## Inherits: <unnamed>%372484000302
{
  public:
    //## Constructors (specified)
      //## Operation: XCor%925120621
      //	Constructor taking the identifier for the corrector, the
      //	length and the field (in Tesla).
      XCor (const string& id, double len, double B = 0);


    //## Other Operations (specified)
      //## Operation: Copy%925120611
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

      //## Operation: GetIndex%925120613
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetType%925120614
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: PrepareTracker%925120615
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

    // Data Members for Class Attributes

      //## Attribute: ID%372486E20104
      //## begin XCor::ID%372486E20104.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end XCor::ID%372486E20104.attr

  protected:
  private:
  private:  //## implementation
};

//## Class: YCor%372483A00334
//	A vertical corrector dipole.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%372486580230;ComponentTracker { -> F}

class YCor : public RectMultipole  //## Inherits: <unnamed>%372484050118
{
  public:
    //## Constructors (specified)
      //## Operation: YCor%925120622
      //	Constructor taking the identifier for the corrector, the
      //	length and the field (in Tesla).
      YCor (const string& id, double len, double B = 0);


    //## Other Operations (specified)
      //## Operation: Copy%925120616
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

      //## Operation: GetIndex%925120618
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetType%925120619
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: PrepareTracker%925120620
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

    // Data Members for Class Attributes

      //## Attribute: ID%372486F602B2
      //## begin YCor::ID%372486F602B2.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end YCor::ID%372486F602B2.attr

  protected:
  private:
  private:  //## implementation
};

// Class XCor 

//## Operation: XCor%925120621
inline XCor::XCor (const string& id, double len, double B)
  //## begin XCor::XCor%925120621.initialization preserve=yes
  : RectMultipole(id,len,0,B)
  //## end XCor::XCor%925120621.initialization
{
  //## begin XCor::XCor%925120621.body preserve=yes
  //## end XCor::XCor%925120621.body
}


// Class YCor 

//## Operation: YCor%925120622
inline YCor::YCor (const string& id, double len, double B)
  //## begin YCor::YCor%925120622.initialization preserve=yes
  : RectMultipole(id,len,0,B,true)
  //## end YCor::YCor%925120622.initialization
{
  //## begin YCor::YCor%925120622.body preserve=yes
  //## end YCor::YCor%925120622.body
}


//## begin module%372485600348.epilog preserve=yes
//## end module%372485600348.epilog


#endif

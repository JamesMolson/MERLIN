//## begin module%3734080F0302.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\SWRFStructure.h
 * last modified 05/04/01 17:58:10
 */
//## end module%3734080F0302.cm

//## begin module%3734080F0302.cp preserve=no
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
//## end module%3734080F0302.cp

//## Module: SWRFStructure%3734080F0302; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\SWRFStructure.h

#ifndef SWRFStructure_h
#define SWRFStructure_h 1

//## begin module%3734080F0302.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3734080F0302.additionalIncludes

//## begin module%3734080F0302.includes preserve=yes
//## end module%3734080F0302.includes

// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// RectSWRF
#include "AcceleratorModel/StdComponent/RectSWRF.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"
// SWRFfield
#include "AcceleratorModel/StdField/SWRFfield.h"

class ComponentTracker;

//## begin module%3734080F0302.declarations preserve=no
//## end module%3734080F0302.declarations

//## begin module%3734080F0302.additionalDeclarations preserve=yes
//## end module%3734080F0302.additionalDeclarations


//## Class: SWRFStructure%3724548201CC
//	A standing wave accelerating structure.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3724555502F8;SWRFfield { -> }
//## Uses: <unnamed>%3724555B03CA;RectangularGeometry { -> }
//## Uses: <unnamed>%3724559E01AE;TAccCompGF { -> }
//## Uses: <unnamed>%37248022001E;ComponentTracker { -> F}

class SWRFStructure : public RectSWRF  //## Inherits: <unnamed>%372454BC0050
{
  public:
    //## Constructors (specified)
      //## Operation: SWRFStructure%925120605
      //	Constructor taking the name of the cavity, the number of
      //	cells, the frequency (f)  in MHz, and peak electric
      //	field (E0) in MV/m and the phase.
      SWRFStructure (const string& id, int ncells, double f, double E0, double phi = 0);


    //## Other Operations (specified)
      //## Operation: GetType%925120606
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: GetIndex%925120607
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: PrepareTracker%925120608
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: RotateY180%925120609
      //	Rotates the component 180 degrees about its local Y axis.
      virtual void RotateY180 ();

      //## Operation: Copy%925120610
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%372454B403AC
      //## begin SWRFStructure::ID%372454B403AC.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end SWRFStructure::ID%372454B403AC.attr

  protected:
  private:
  private:  //## implementation
};

// Class SWRFStructure 

//## begin module%3734080F0302.epilog preserve=yes
//## end module%3734080F0302.epilog


#endif

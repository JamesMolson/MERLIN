//## begin module%3734087702E4.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\TWRFStructure.h
 * last modified 05/04/01 17:58:10
 */
//## end module%3734087702E4.cm

//## begin module%3734087702E4.cp preserve=no
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
//## end module%3734087702E4.cp

//## Module: TWRFStructure%3734087702E4; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\TWRFStructure.h

#ifndef TWRFStructure_h
#define TWRFStructure_h 1

//## begin module%3734087702E4.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3734087702E4.additionalIncludes

//## begin module%3734087702E4.includes preserve=yes
//## end module%3734087702E4.includes

// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// RectTWRF
#include "AcceleratorModel/StdComponent/RectTWRF.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"
// TWRFfield
#include "AcceleratorModel/StdField/TWRFfield.h"

class ComponentTracker;

//## begin module%3734087702E4.declarations preserve=no
//## end module%3734087702E4.declarations

//## begin module%3734087702E4.additionalDeclarations preserve=yes
//## end module%3734087702E4.additionalDeclarations


//## Class: TWRFStructure%372451630208
//	A travelling wave accelerating structure.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%372452D30082;TWRFfield { -> }
//## Uses: <unnamed>%372452D602BC;RectangularGeometry { -> }
//## Uses: <unnamed>%3724558A0370;TAccCompGF { -> }
//## Uses: <unnamed>%372480200334;ComponentTracker { -> F}

class TWRFStructure : public RectTWRF  //## Inherits: <unnamed>%3724516E030C
{
  public:
    //## Constructors (specified)
      //## Operation: TWRFStructure%925120599
      //	Constructor taking the label for this cavity (id), the
      //	cavity length (len) in meters, the frequency (f) in MHz,
      //	and gradient (Epk) in MV/m and the phase (phi) in
      //	radians.
      TWRFStructure (const string& id, double len, double f, double Epk, double phi = 0);


    //## Other Operations (specified)
      //## Operation: GetType%925120600
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: GetIndex%925120601
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: PrepareTracker%925120602
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: RotateY180%925120603
      //	Rotates the component 180 degrees about its local Y axis.
      virtual void RotateY180 ();

      //## Operation: Copy%925120604
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%372452710096
      //## begin TWRFStructure::ID%372452710096.attr preserve=no  public: static const int {VA} UniqueIndex()
      static const int ID;
      //## end TWRFStructure::ID%372452710096.attr

  protected:
  private:
  private:  //## implementation
};

// Class TWRFStructure 

//## begin module%3734087702E4.epilog preserve=yes
//## end module%3734087702E4.epilog


#endif

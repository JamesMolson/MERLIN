//## begin module%371F50130280.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\RectMultipole.h
 * last modified 04/04/01 15:24:08
 */
//## end module%371F50130280.cm

//## begin module%371F50130280.cp preserve=no
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
//## end module%371F50130280.cp

//## Module: RectMultipole%371F50130280; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\RectMultipole.h

#ifndef RectMultipole_h
#define RectMultipole_h 1

//## begin module%371F50130280.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%371F50130280.additionalIncludes

//## begin module%371F50130280.includes preserve=yes
//## end module%371F50130280.includes

// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// MultipoleField
#include "AcceleratorModel/StdField/MultipoleField.h"
// RectMultipoleField
#include "AcceleratorModel/StdComponent/RectMultipoleField.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"

class ComponentTracker;

//## begin module%371F50130280.declarations preserve=no
//## end module%371F50130280.declarations

//## begin module%371F50130280.additionalDeclarations preserve=yes
//## end module%371F50130280.additionalDeclarations


//## Class: RectMultipole%331ED97A001E; Abstract
//	Abstract base class for all standard rectangular
//	rectangular multipole magnets that are typically found
//	in accelerator systems.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%37032EC601C5;RectangularGeometry { -> }
//## Uses: <unnamed>%371F36B40398;MultipoleField { -> }
//## Uses: <unnamed>%371F50E50046;TAccCompGF { -> }
//## Uses: <unnamed>%371F55A30320;ComponentTracker { -> F}

class RectMultipole : public RectMultipoleField  //## Inherits: <unnamed>%371F36900262
{
  public:

    //## Other Operations (specified)
      //## Operation: SetFieldStrength%924771662
      //	Sets the primary field strength for this multipole.
      //	Units are Tesla/meter^n, where n is the primary pole
      //	type.
      void SetFieldStrength (double b);

      //## Operation: GetFieldStrength%924771663
      //	Returns the primary field strength for this multipole.
      //	Units are Tesla/meter^n, where n is the primary pole
      //	type.
      double GetFieldStrength () const;

      //## Operation: GetPrimaryPoleNo%924771664
      //	Returns the primary pole number for this multipole.
      int GetPrimaryPoleNo () const;

      //## Operation: GetIndex%924771665
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: PrepareTracker%924771666
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: RotateY180%924771667
      //	Rotates the component 180 degrees about its local Y axis.
      virtual void RotateY180 ();

    // Data Members for Class Attributes

      //## Attribute: ID%371F374A0140
      //## begin RectMultipole::ID%371F374A0140.attr preserve=no  public: static const int {VA} UniqueIndex()
      static const int ID;
      //## end RectMultipole::ID%371F374A0140.attr

  protected:
    //## Constructors (specified)
      //## Operation: RectMultipole%868526148; C++
      //	Constructor taking the id and the length of the magnet,
      //	and the definition of a single multipole component. b is
      //	the field (in Tesla) at the specified radius r0. if
      //	skew==true, then a skew multipole is constructed
      //	(default=false).
      RectMultipole (const string& id, double length, int npole, double b, double r0, bool skew = false);

      //## Operation: RectMultipole%924771668
      //	Constructor taking the id and the length of the magnet,
      //	and the definition of a single multipole component.
      //	Here, b is the n-th field derivative  (in Tesla/meter^n,
      //	where n is the pole number), evaluated at r=0.  if
      //	skew==true, then a skew multipole is constructed
      //	(default=false).
      RectMultipole (const string& id, double len, int np, double b, bool skew = false);

  private:
    // Data Members for Class Attributes

      //## Attribute: np%371F38C60384
      //	The primary pole for this multipole.
      //## begin RectMultipole::np%371F38C60384.attr preserve=no  private: int {UA} 
      int np;
      //## end RectMultipole::np%371F38C60384.attr

  private:  //## implementation
};

// Class RectMultipole 


//## Other Operations (inline)
//## Operation: SetFieldStrength%924771662
inline void RectMultipole::SetFieldStrength (double b)
{
  //## begin RectMultipole::SetFieldStrength%924771662.body preserve=yes
	GetField().SetFieldScale(b);
  //## end RectMultipole::SetFieldStrength%924771662.body
}

//## Operation: GetFieldStrength%924771663
inline double RectMultipole::GetFieldStrength () const
{
  //## begin RectMultipole::GetFieldStrength%924771663.body preserve=yes
	return GetField().GetFieldScale();
  //## end RectMultipole::GetFieldStrength%924771663.body
}

//## Operation: GetPrimaryPoleNo%924771664
inline int RectMultipole::GetPrimaryPoleNo () const
{
  //## begin RectMultipole::GetPrimaryPoleNo%924771664.body preserve=yes
	return np;
  //## end RectMultipole::GetPrimaryPoleNo%924771664.body
}

//## begin module%371F50130280.epilog preserve=yes
//## end module%371F50130280.epilog


#endif

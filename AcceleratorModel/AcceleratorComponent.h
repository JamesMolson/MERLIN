//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%37135534037A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\AcceleratorComponent.h
 * last modified 04/04/02 12:05:58
 */
//## end module%37135534037A.cm

//## begin module%37135534037A.cp preserve=no
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
//## end module%37135534037A.cp

//## Module: AcceleratorComponent%37135534037A; Package specification
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: C:\C++\Merlin\AcceleratorModel\AcceleratorComponent.h

#ifndef AcceleratorComponent_h
#define AcceleratorComponent_h 1

//## begin module%37135534037A.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37135534037A.additionalIncludes

//## begin module%37135534037A.includes preserve=yes
#include <string>
//## end module%37135534037A.includes

// EMField
#include "AcceleratorModel/EMField.h"
// AcceleratorGeometry
#include "AcceleratorModel/AcceleratorGeometry.h"
// Aperture
#include "AcceleratorModel/Aperture.h"
// ModelElement
#include "AcceleratorModel/ModelElement.h"
// WakePotentials
#include "AcceleratorModel/WakePotentials.h"

class ComponentTracker;

//## begin module%37135534037A.additionalDeclarations preserve=yes
using std::string;
//## end module%37135534037A.additionalDeclarations


//## Class: AcceleratorComponent%36CD8CBE0280; Abstract
//	An AcceleratorComponent represents any component which
//	can be placed in an accelerator lattice. Typically, a
//	lattice model is constructed as an ordered sequence of
//	AcceleratorComponents. AcceleratorComponents can be
//	associated with a geometry (an AcceleratorGeometry
//	object) and a em field (an EMFieldRegion object), which
//	when taken together uniquely define the field properties
//	for the component. Component "tracking" is supported via
//	the funtion PrepareTracker(Tracker&), which sets up a
//	Tracker object to track the component.
//## Category: Merlin::AcceleratorModel%370B943B0384
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%36EE2EAC01C9;ComponentTracker { -> F}

class AcceleratorComponent : public ModelElement  //## Inherits: <unnamed>%3AC45C400212
{
  public:
    //## Destructor (specified)
      //## Operation: ~AcceleratorComponent%36EFCCA703BE
      virtual ~AcceleratorComponent ();


    //## Other Operations (specified)
      //## Operation: GetIndex%3714655B0352
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetLength%36E7C8E500C4
      //	Returns the geometry length of the component.
      double GetLength () const;

      //## Operation: GetGeometry%36EFBE41010B
      //	Returns a pointer to the this components geometry.
      //	Returns NULL if no geometry is associated with this
      //	component.
      const AcceleratorGeometry* GetGeometry () const;

      //## Operation: GetEMField%36EFBEBC00F3
      //	Returns a pointer to this components field. A NULL
      //	pointer is returned if the component has no field.
      const EMField* GetEMField () const;

      //## Operation: GetAperture%37C5242B00CC
      const Aperture* GetAperture () const;

      //## Operation: SetAperture%37C52443029D
      void SetAperture (Aperture* ap);

      //## Operation: GetWakePotentials%3CAC21930249
      //	Returns the wake potentials associated with this cavity.
      WakePotentials* GetWakePotentials () const;

      //## Operation: SetWakePotentials%3CAC2193025D
      //	Sets the wake potentials associated with this cavity.
      void SetWakePotentials (WakePotentials* wp);

      //## Operation: PrepareTracker%36EE2EB503DE
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: RotateY180%370215A6026A
      //	Rotates the component 180 degrees about its local Y axis.
      virtual void RotateY180 () = 0;

      //## Operation: TotalComponentNumber%3714647E0262
      //	Returns the total number of distinct component types in
      //	the system.
      static int TotalComponentNumber ();

    // Data Members for Class Attributes

      //## Attribute: ID%371463CE019A
      //	Unique index for an Accelerator component.
      //## begin AcceleratorComponent::ID%371463CE019A.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end AcceleratorComponent::ID%371463CE019A.attr

  protected:
    //## Constructors (specified)
      //## Operation: AcceleratorComponent%36EFC9DE0200
      //	Protected constructors used by derived classes.
      explicit AcceleratorComponent (const string& aName = string());

      //## Operation: AcceleratorComponent%371352AB000A
      AcceleratorComponent (const string& aName, AcceleratorGeometry* aGeom, EMField* aField);


    //## Other Operations (specified)
      //## Operation: UniqueIndex%3714646C01AE
      //	Used by derived classes to generate a unique index. All
      //	derived classes should have a static member ID of type
      //	IndexType which should be initialised as follows
      //
      //	IndexType component::ID = UniqueIndex();
      static int UniqueIndex ();

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::<unnamed>%36EFBD7902C6
      //## Role: AcceleratorComponent::itsField%36EFBD7902C8
      //## begin AcceleratorComponent::itsField%36EFBD7902C8.role preserve=no  protected: EMField { -> 0..1VFHgAN}
      EMField* itsField;
      //## end AcceleratorComponent::itsField%36EFBD7902C8.role

      //## Association: Merlin::AcceleratorModel::<unnamed>%36EFBDBA019D
      //## Role: AcceleratorComponent::itsGeometry%36EFBDBA0337
      //## begin AcceleratorComponent::itsGeometry%36EFBDBA0337.role preserve=no  protected: AcceleratorGeometry { -> 0..1VFHgAN}
      AcceleratorGeometry* itsGeometry;
      //## end AcceleratorComponent::itsGeometry%36EFBDBA0337.role

  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::<unnamed>%36CD8DFC00AA
      //## Role: AcceleratorComponent::itsAperture%36CD8DFC0262
      //## begin AcceleratorComponent::itsAperture%36CD8DFC0262.role preserve=no  private: Aperture { -> 0..1RFHgAN}
      Aperture* itsAperture;
      //## end AcceleratorComponent::itsAperture%36CD8DFC0262.role

      //## Association: Merlin::AcceleratorModel::<unnamed>%3CAC21D201AA
      //## Role: AcceleratorComponent::wakes%3CAC21D301D3
      //## begin AcceleratorComponent::wakes%3CAC21D301D3.role preserve=no  private: WakePotentials { -> 0..1RHAN}
      WakePotentials* wakes;
      //## end AcceleratorComponent::wakes%3CAC21D301D3.role

  private: //## implementation
};

// Class AcceleratorComponent 

//## Operation: AcceleratorComponent%36EFC9DE0200
inline AcceleratorComponent::AcceleratorComponent (const string& aName)
  //## begin AcceleratorComponent::AcceleratorComponent%36EFC9DE0200.initialization preserve=yes
  : ModelElement(aName),itsField(0),itsGeometry(0),itsAperture(0)
  //## end AcceleratorComponent::AcceleratorComponent%36EFC9DE0200.initialization
{
  //## begin AcceleratorComponent::AcceleratorComponent%36EFC9DE0200.body preserve=yes
  //## end AcceleratorComponent::AcceleratorComponent%36EFC9DE0200.body
}

//## Operation: AcceleratorComponent%371352AB000A
inline AcceleratorComponent::AcceleratorComponent (const string& aName, AcceleratorGeometry* aGeom, EMField* aField)
  //## begin AcceleratorComponent::AcceleratorComponent%371352AB000A.initialization preserve=yes
  : ModelElement(aName),itsField(aField),itsGeometry(aGeom),itsAperture(0)
  //## end AcceleratorComponent::AcceleratorComponent%371352AB000A.initialization
{
  //## begin AcceleratorComponent::AcceleratorComponent%371352AB000A.body preserve=yes
  //## end AcceleratorComponent::AcceleratorComponent%371352AB000A.body
}



//## Other Operations (inline)
//## Operation: GetGeometry%36EFBE41010B
inline const AcceleratorGeometry* AcceleratorComponent::GetGeometry () const
{
  //## begin AcceleratorComponent::GetGeometry%36EFBE41010B.body preserve=yes
	return itsGeometry;
  //## end AcceleratorComponent::GetGeometry%36EFBE41010B.body
}

//## Operation: GetEMField%36EFBEBC00F3
inline const EMField* AcceleratorComponent::GetEMField () const
{
  //## begin AcceleratorComponent::GetEMField%36EFBEBC00F3.body preserve=yes
	return itsField;
  //## end AcceleratorComponent::GetEMField%36EFBEBC00F3.body
}

//## Operation: GetAperture%37C5242B00CC
inline const Aperture* AcceleratorComponent::GetAperture () const
{
  //## begin AcceleratorComponent::GetAperture%37C5242B00CC.body preserve=yes
	return itsAperture;
  //## end AcceleratorComponent::GetAperture%37C5242B00CC.body
}

//## Operation: SetAperture%37C52443029D
inline void AcceleratorComponent::SetAperture (Aperture* ap)
{
  //## begin AcceleratorComponent::SetAperture%37C52443029D.body preserve=yes
	itsAperture = ap;
  //## end AcceleratorComponent::SetAperture%37C52443029D.body
}

//## Operation: GetWakePotentials%3CAC21930249
inline WakePotentials* AcceleratorComponent::GetWakePotentials () const
{
  //## begin AcceleratorComponent::GetWakePotentials%3CAC21930249.body preserve=yes
	return wakes;
  //## end AcceleratorComponent::GetWakePotentials%3CAC21930249.body
}

//## Operation: SetWakePotentials%3CAC2193025D
inline void AcceleratorComponent::SetWakePotentials (WakePotentials* wp)
{
  //## begin AcceleratorComponent::SetWakePotentials%3CAC2193025D.body preserve=yes
	wakes=wp;
  //## end AcceleratorComponent::SetWakePotentials%3CAC2193025D.body
}

//## Operation: TotalComponentNumber%3714647E0262
inline int AcceleratorComponent::TotalComponentNumber ()
{
  //## begin AcceleratorComponent::TotalComponentNumber%3714647E0262.body preserve=yes
	return 0;
  //## end AcceleratorComponent::TotalComponentNumber%3714647E0262.body
}

//## begin module%37135534037A.epilog preserve=yes
//## end module%37135534037A.epilog


#endif

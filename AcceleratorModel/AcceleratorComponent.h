//## begin module%37135534037A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\AcceleratorComponent.h
 * last modified 03/04/01 14:32:34
 */
//## end module%37135534037A.cm

//## begin module%37135534037A.cp preserve=no
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
//## end module%37135534037A.cp

//## Module: AcceleratorComponent%37135534037A; Package specification
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: D:\dev\Merlin\AcceleratorModel\AcceleratorComponent.h

#ifndef AcceleratorComponent_h
#define AcceleratorComponent_h 1

//## begin module%37135534037A.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37135534037A.additionalIncludes

//## begin module%37135534037A.includes preserve=yes
#include <string>
//## end module%37135534037A.includes

// ModelElement
#include "AcceleratorModel/ModelElement.h"
// Aperture
#include "AcceleratorModel/Aperture.h"
// AcceleratorGeometry
#include "AcceleratorModel/AcceleratorGeometry.h"
// EMField
#include "AcceleratorModel/EMField.h"

class ComponentTracker;

//## begin module%37135534037A.declarations preserve=no
//## end module%37135534037A.declarations

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
      //## Operation: ~AcceleratorComponent%924014182
      virtual ~AcceleratorComponent ();


    //## Other Operations (specified)
      //## Operation: GetIndex%924072843
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetLength%924014184
      //	Returns the geometry length of the component.
      double GetLength () const;

      //## Operation: GetGeometry%924014187
      //	Returns a pointer to the this components geometry.
      //	Returns NULL if no geometry is associated with this
      //	component.
      const AcceleratorGeometry* GetGeometry () const;

      //## Operation: GetEMField%924014188
      //	Returns a pointer to this components field. A NULL
      //	pointer is returned if the component has no field.
      const EMField* GetEMField () const;

      //## Operation: GetAperture%935667549
      const Aperture* GetAperture () const;

      //## Operation: SetAperture%935667550
      void SetAperture (Aperture* ap);

      //## Operation: PrepareTracker%924014185
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: RotateY180%924014191
      //	Rotates the component 180 degrees about its local Y axis.
      virtual void RotateY180 () = 0;

      //## Operation: TotalComponentNumber%924072844
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
      //## Operation: AcceleratorComponent%924014192
      //	Protected constructors used by derived classes.
      explicit AcceleratorComponent (const string& aName = string());

      //## Operation: AcceleratorComponent%924014193
      AcceleratorComponent (const string& aName, AcceleratorGeometry* aGeom, EMField* aField);


    //## Other Operations (specified)
      //## Operation: UniqueIndex%924072845
      //	Used by derived classes to generate a unique index. All
      //	derived classes should have a static member ID of type
      //	IndexType which should be initialised as follows
      //
      //	IndexType component::ID = UniqueIndex();
      static int UniqueIndex ();

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::<unnamed>%36EFBD7902C6
      //## Role: AcceleratorComponent::itsField%36EFBD7902C8
      //## begin AcceleratorComponent::itsField%36EFBD7902C8.role preserve=no  protected: EMField { -> 0..1VFHAN}
      EMField* itsField;
      //## end AcceleratorComponent::itsField%36EFBD7902C8.role

      //## Association: Merlin::AcceleratorModel::<unnamed>%36EFBDBA019D
      //## Role: AcceleratorComponent::itsGeometry%36EFBDBA0337
      //## begin AcceleratorComponent::itsGeometry%36EFBDBA0337.role preserve=no  protected: AcceleratorGeometry { -> 0..1VFHAN}
      AcceleratorGeometry* itsGeometry;
      //## end AcceleratorComponent::itsGeometry%36EFBDBA0337.role

  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::<unnamed>%36CD8DFC00AA
      //## Role: AcceleratorComponent::itsAperture%36CD8DFC0262
      //## begin AcceleratorComponent::itsAperture%36CD8DFC0262.role preserve=no  private: Aperture { -> 0..1RFHAN}
      Aperture* itsAperture;
      //## end AcceleratorComponent::itsAperture%36CD8DFC0262.role

  private:  //## implementation
};

// Class AcceleratorComponent 

//## Operation: AcceleratorComponent%924014192
inline AcceleratorComponent::AcceleratorComponent (const string& aName)
  //## begin AcceleratorComponent::AcceleratorComponent%924014192.initialization preserve=yes
  : ModelElement(aName),itsField(0),itsGeometry(0),itsAperture(0)
  //## end AcceleratorComponent::AcceleratorComponent%924014192.initialization
{
  //## begin AcceleratorComponent::AcceleratorComponent%924014192.body preserve=yes
  //## end AcceleratorComponent::AcceleratorComponent%924014192.body
}

//## Operation: AcceleratorComponent%924014193
inline AcceleratorComponent::AcceleratorComponent (const string& aName, AcceleratorGeometry* aGeom, EMField* aField)
  //## begin AcceleratorComponent::AcceleratorComponent%924014193.initialization preserve=yes
  : ModelElement(aName),itsField(aField),itsGeometry(aGeom),itsAperture(0)
  //## end AcceleratorComponent::AcceleratorComponent%924014193.initialization
{
  //## begin AcceleratorComponent::AcceleratorComponent%924014193.body preserve=yes
  //## end AcceleratorComponent::AcceleratorComponent%924014193.body
}



//## Other Operations (inline)
//## Operation: GetGeometry%924014187
inline const AcceleratorGeometry* AcceleratorComponent::GetGeometry () const
{
  //## begin AcceleratorComponent::GetGeometry%924014187.body preserve=yes
	return itsGeometry;
  //## end AcceleratorComponent::GetGeometry%924014187.body
}

//## Operation: GetEMField%924014188
inline const EMField* AcceleratorComponent::GetEMField () const
{
  //## begin AcceleratorComponent::GetEMField%924014188.body preserve=yes
	return itsField;
  //## end AcceleratorComponent::GetEMField%924014188.body
}

//## Operation: GetAperture%935667549
inline const Aperture* AcceleratorComponent::GetAperture () const
{
  //## begin AcceleratorComponent::GetAperture%935667549.body preserve=yes
	return itsAperture;
  //## end AcceleratorComponent::GetAperture%935667549.body
}

//## Operation: SetAperture%935667550
inline void AcceleratorComponent::SetAperture (Aperture* ap)
{
  //## begin AcceleratorComponent::SetAperture%935667550.body preserve=yes
	itsAperture = ap;
  //## end AcceleratorComponent::SetAperture%935667550.body
}

//## Operation: TotalComponentNumber%924072844
inline int AcceleratorComponent::TotalComponentNumber ()
{
  //## begin AcceleratorComponent::TotalComponentNumber%924072844.body preserve=yes
	return 0;
  //## end AcceleratorComponent::TotalComponentNumber%924072844.body
}

//## Operation: UniqueIndex%924072845
inline int AcceleratorComponent::UniqueIndex ()
{
  //## begin AcceleratorComponent::UniqueIndex%924072845.body preserve=yes
	static int ID_count = 0;
	return ID_count++;
  //## end AcceleratorComponent::UniqueIndex%924072845.body
}

//## begin module%37135534037A.epilog preserve=yes
//## end module%37135534037A.epilog


#endif

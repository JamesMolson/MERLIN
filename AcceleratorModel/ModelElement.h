//## begin module%3AC991010384.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\ModelElement.h
 * last modified 03/04/01 13:09:44
 */
//## end module%3AC991010384.cm

//## begin module%3AC991010384.cp preserve=no
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
//## end module%3AC991010384.cp

//## Module: ModelElement%3AC991010384; Package specification
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: D:\dev\Merlin\AcceleratorModel\ModelElement.h

#ifndef ModelElement_h
#define ModelElement_h 1

//## begin module%3AC991010384.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AC991010384.additionalIncludes

//## begin module%3AC991010384.includes preserve=yes
#include <string>
//## end module%3AC991010384.includes

//## begin module%3AC991010384.declarations preserve=no
//## end module%3AC991010384.declarations

//## begin module%3AC991010384.additionalDeclarations preserve=yes
using std::string;
//## end module%3AC991010384.additionalDeclarations


//## Class: ModelElement%3758276803A2; Abstract
//	Root class for all elements/components which are used to
//	construct an AcceleratorModel. All ModelElement objects
//	are characterised by a type string and an identifier
//	(name). The type string identifies the type of element
//	(class), while the name is specific to an instance of
//	that element type.
//## Category: Merlin::AcceleratorModel%370B943B0384
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ModelElement 
{
  public:
    //## Constructors (specified)
      //## Operation: ModelElement%928784544
      //	Constructor taking the name of the element.
      explicit ModelElement (const string& aName);

      //## Operation: ModelElement%929041264
      //	Constructor taking the name of the element.
      ModelElement ();

    //## Destructor (specified)
      //## Operation: ~ModelElement%928784545
      virtual ~ModelElement ();


    //## Other Operations (specified)
      //## Operation: GetName%928784546
      //	Return the name of the element.
      virtual const string& GetName () const;

      //## Operation: GetType%928784547
      //	Return the type string for the element.
      virtual const string& GetType () const = 0;

      //## Operation: GetQualifiedName%928784548
      //	Return the qualified name of the component. The
      //	qualified name has the form typestr.namestr.
      string GetQualifiedName () const;

      //## Operation: Copy%928784549
      //	Virtual constructor.
      virtual ModelElement* Copy () const = 0;

      //## Operation: SetName%928784550
      //	Set the name of the component.
      void SetName (const string& name);

  protected:

    //## Other Operations (specified)
      //## Operation: Init%929041263
      //	Initialise the ModelElement with the specified name.
      void Init (const string& aName);

    // Data Members for Class Attributes

      //## Attribute: id%3758277101F4
      //## begin ModelElement::id%3758277101F4.attr preserve=no  protected: string {UA} 
      string id;
      //## end ModelElement::id%3758277101F4.attr

  private:
  private:  //## implementation
};

// Class ModelElement 

//## Operation: ModelElement%928784544
inline ModelElement::ModelElement (const string& aName)
  //## begin ModelElement::ModelElement%928784544.initialization preserve=yes
  : id(aName)
  //## end ModelElement::ModelElement%928784544.initialization
{
  //## begin ModelElement::ModelElement%928784544.body preserve=yes
  //## end ModelElement::ModelElement%928784544.body
}

//## Operation: ModelElement%929041264
inline ModelElement::ModelElement ()
  //## begin ModelElement::ModelElement%929041264.initialization preserve=yes
  //## end ModelElement::ModelElement%929041264.initialization
{
  //## begin ModelElement::ModelElement%929041264.body preserve=yes
  //## end ModelElement::ModelElement%929041264.body
}


//## Operation: ~ModelElement%928784545
inline ModelElement::~ModelElement ()
{
  //## begin ModelElement::~ModelElement%928784545.body preserve=yes
	// nothing to do
  //## end ModelElement::~ModelElement%928784545.body
}



//## Other Operations (inline)
//## Operation: GetName%928784546
inline const string& ModelElement::GetName () const
{
  //## begin ModelElement::GetName%928784546.body preserve=yes
	return id;
  //## end ModelElement::GetName%928784546.body
}

//## Operation: GetQualifiedName%928784548
inline string ModelElement::GetQualifiedName () const
{
  //## begin ModelElement::GetQualifiedName%928784548.body preserve=yes
	return GetType()+'.'+GetName();
  //## end ModelElement::GetQualifiedName%928784548.body
}

//## Operation: SetName%928784550
inline void ModelElement::SetName (const string& name)
{
  //## begin ModelElement::SetName%928784550.body preserve=yes
	id=name;
  //## end ModelElement::SetName%928784550.body
}

//## Operation: Init%929041263
inline void ModelElement::Init (const string& aName)
{
  //## begin ModelElement::Init%929041263.body preserve=yes
	id=aName;
  //## end ModelElement::Init%929041263.body
}

// Class ModelElement 




//## begin module%3AC991010384.epilog preserve=yes
// utility macros:
// GetType() implementation
#define _TYPESTR(s) static const string typestr(#s); return typestr;
//## end module%3AC991010384.epilog


#endif

/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004-12-13 08:38:51 $
// $Revision: 1.2 $
// 
/////////////////////////////////////////////////////////////////////////

#ifndef ModelElement_h
#define ModelElement_h 1

#include "merlin_config.h"
#include <string>

using std::string;

//	Root class for all elements/components which are used to
//	construct an AcceleratorModel. All ModelElement objects
//	are characterised by a type string and an identifier
//	(name). The type string identifies the type of element
//	(class), while the name is specific to an instance of
//	that element type.

class ModelElement
{
public:
    //	Constructor taking the name of the element.
    explicit ModelElement (const string& aName ="<UNNAMED>");

    virtual ~ModelElement ();

    //	Return the name of the element.
    virtual const string& GetName () const;

    //	Return the type string for the element.
    virtual const string& GetType () const = 0;

    //	Return the qualified name of the component. The
    //	qualified name has the form typestr.namestr.
    string GetQualifiedName () const;

    //	Virtual constructor.
    virtual ModelElement* Copy () const = 0;

    //	Set the name of the component.
    void SetName (const string& name);

protected:

    //	Initialise the ModelElement with the specified name.
    void Init (const string& aName);

    string id;
};

// Class ModelElement

inline ModelElement::ModelElement (const string& aName)
        : id(aName)
{
}

inline ModelElement::~ModelElement ()
{
    // nothing to do
}

inline const string& ModelElement::GetName () const
{
    return id;
}

inline string ModelElement::GetQualifiedName () const
{
    return GetType()+'.'+GetName();
}

inline void ModelElement::SetName (const string& name)
{
    id=name;
}

inline void ModelElement::Init (const string& aName)
{
    id=aName;
}

// utility macros:
// GetType() implementation
#define _TYPESTR(s) static const string typestr(#s); return typestr;

#endif

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

#ifndef ComponentFrame_h
#define ComponentFrame_h 1

#include "merlin_config.h"
// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"
// LatticeFrame
#include "AcceleratorModel/Frames/LatticeFrame.h"

//	An atomic LatticeFrame object which represents a single
//	instance of an AcceleratorComponent in a beamline.

class ComponentFrame : public LatticeFrame
{
public:

    //	Constructor taking the associated AcceleratorComponent
    //	object.
    explicit ComponentFrame (AcceleratorComponent& ac, const string& id = "");

    //	Copy constructor.
    ComponentFrame (const ComponentFrame& rhs);

    virtual ~ComponentFrame ();

    AcceleratorComponent& GetComponent ();
    const AcceleratorComponent& GetComponent () const;

    //	Causes any cached state to be invalidated. The cached
    //	state should be re-calculated if and when required.
    virtual void Invalidate () const;

    //	Return the name of the element. Returns the name of the
    //	AcceleratorComponent if the label for this frame has not
    //	been explicitely set.
    virtual const string& GetName () const;

    //	Returns the type of the referenced AcceleratorComponent.
    virtual const string& GetType () const;

    //	Returns a copy of this ComponentFrame. Note that only
    //	the reference to the AcceleratorComponent is copied, not
    //	the AcceleratorComponent itself.
    virtual ModelElement* Copy () const;

protected:

    AcceleratorComponent* theComponent;

    //	Should  never be called.
    virtual bool IsBoundaryPlane (BoundaryPlane p, const LatticeFrame* aSubFrame) const;
};

inline ComponentFrame::ComponentFrame (AcceleratorComponent& ac, const string& id)
        : LatticeFrame(id.empty()?ac.GetName():id),theComponent(&ac)
{
    SetGeometry(theComponent->GetGeometry());
}

inline ComponentFrame::ComponentFrame (const ComponentFrame& rhs)
: LatticeFrame(rhs),theComponent(rhs.theComponent)
{}

inline AcceleratorComponent& ComponentFrame::GetComponent ()
{
    return *theComponent;
}

inline const AcceleratorComponent& ComponentFrame::GetComponent () const
{
    return *theComponent;
}

inline const string& ComponentFrame::GetName () const
{
    const string& id = LatticeFrame::GetName();
    return (id.length()!=0)? id : (theComponent->GetName());
}

#endif

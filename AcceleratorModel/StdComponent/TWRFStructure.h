/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004-12-13 08:38:52 $
// $Revision: 1.2 $
// 
/////////////////////////////////////////////////////////////////////////

#ifndef TWRFStructure_h
#define TWRFStructure_h 1

#include "merlin_config.h"
// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// RectTWRF
#include "AcceleratorModel/StdComponent/RectTWRF.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"
// TWRFfield
#include "AcceleratorModel/StdField/TWRFfield.h"

class ComponentTracker;

//	A travelling wave accelerating structure.

class TWRFStructure : public RectTWRF
{
public:

    //	Constructor taking the label for this cavity (id), the
    //	cavity length (len) in meters, the frequency (f) in MHz,
    //	and gradient (Epk) in MV/m and the phase (phi) in
    //	radians.
    TWRFStructure (const string& id, double len, double f, double Epk, double phi = 0);

    //	Returns the type string "TWRFStructure".
    virtual const string& GetType () const;

    //	Returns the unique index for this class of accelerator
    //	components.
    virtual int GetIndex () const;

    //	Primary tracking interface. Prepares the specified
    //	Tracker object for tracking this component.
    virtual void PrepareTracker (ComponentTracker& aTracker);

    //	Rotates the component 180 degrees about its local Y axis.
    virtual void RotateY180 ();

    //	Virtual constructor.
    virtual ModelElement* Copy () const;

    static const int ID;
};


#endif

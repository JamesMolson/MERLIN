/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\SWRFStructure.h
 * last modified 05/04/01 17:58:10
 */

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


#ifndef SWRFStructure_h
#define SWRFStructure_h 1

#include "merlin_config.h"


// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// RectSWRF
#include "AcceleratorModel/StdComponent/RectSWRF.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"
// SWRFfield
#include "AcceleratorModel/StdField/SWRFfield.h"

class ComponentTracker;




//	A standing wave accelerating structure.


class SWRFStructure : public RectSWRF
{
public:
    //	Constructor taking the name of the cavity, the number of
    //	cells, the frequency (f)  in MHz, and peak electric
    //	field (E0) in MV/m and the phase.
    SWRFStructure (const string& id, int ncells, double f, double E0, double phi = 0);


    //	Returns the type string for this component.
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

    // Data Members for Class Attributes

    static const int ID;

protected:
private:
private:
};

// Class SWRFStructure



#endif

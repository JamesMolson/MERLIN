/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\SWRFStructure.cpp
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


#include "NumericalUtils/PhysicalConstants.h"

// SWRFStructure
#include "AcceleratorModel/StdComponent/SWRFStructure.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"



namespace {
inline double Wavelength(double f) {
    using PhysicalConstants::SpeedOfLight;
    return SpeedOfLight/f;
}
};


// Class SWRFStructure

const int SWRFStructure::ID = UniqueIndex();

SWRFStructure::SWRFStructure (const string& id, int ncells, double f, double E0, double phi)
        : RectSWRF(id,Wavelength(f)*ncells/2,new SWRFfield(f,E0,phi))
{
}



const string& SWRFStructure::GetType () const
{
    _TYPESTR(SWRFStructure)
}

int SWRFStructure::GetIndex () const
{
    return ID;
}

void SWRFStructure::PrepareTracker (ComponentTracker& aTracker)
{
    _PREPTRACK(aTracker,AcceleratorComponent)
}

void SWRFStructure::RotateY180 ()
{
    double E = GetField().GetAmplitude();
    GetField().SetAmplitude(-E);
}

ModelElement* SWRFStructure::Copy () const
{
    return new SWRFStructure(*this);
}


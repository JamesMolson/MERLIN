/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\TWRFStructure.cpp
 * last modified 05/04/01 17:58:09
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



// TWRFStructure
#include "AcceleratorModel/StdComponent/TWRFStructure.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"





// Class TWRFStructure

const int TWRFStructure::ID = UniqueIndex();

TWRFStructure::TWRFStructure (const string& id, double len, double f, double Epk, double phi)
        : RectTWRF(id,len,new TWRFfield(f,Epk,phi))
{
}



const string& TWRFStructure::GetType () const
{
    _TYPESTR(TWRFStructure)
}

int TWRFStructure::GetIndex () const
{
    return ID;
}

void TWRFStructure::PrepareTracker (ComponentTracker& aTracker)
{
    _PREPTRACK(aTracker,AcceleratorComponent)
}

void TWRFStructure::RotateY180 ()
{
    double E = GetField().GetAmplitude();
    GetField().SetAmplitude(-E);
}

ModelElement* TWRFStructure::Copy () const
{
    return new TWRFStructure(*this);
}


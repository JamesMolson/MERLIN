/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2005-03-29 08:19:43 $
// $Revision: 1.1 $
// 
/////////////////////////////////////////////////////////////////////////

#ifndef TransverseRFStructure_h
#define TransverseRFStructure_h 1

#include "merlin_config.h"
// RFStructure
#include "AcceleratorModel/StdComponent/RFStructure.h"
// TransverseRFfield
#include "AcceleratorModel/StdField/TransRFfield.h"

class ComponentTracker;

//	A travelling wave transverse deflecting structure.

class TransverseRFStructure : public RFStructure< TransverseRFfield >
{
public:

    //	Constructor taking the label for this cavity (id), the
    //	cavity length (len) in meters, the frequency (f) in MHz,
    //	and gradient (Epk) in MV/m and the phase (phi) in
    //	radians.
    TransverseRFStructure (const string& id, double len, double f, double Epk, double phi=0, double theta=0);

    //  Orientation
    double GetFieldOrientation() const;
    void SetFieldOrientation(double);

    //	Returns the type string "TransverseRFStructure".
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

inline double TransverseRFStructure::GetFieldOrientation() const
{
    return static_cast<TransverseRFfield*>(itsField)->GetFieldOrientation();
}

inline void TransverseRFStructure::SetFieldOrientation(double t)
{
    static_cast<TransverseRFfield*>(itsField)->SetFieldOrientation(t);
}

#endif

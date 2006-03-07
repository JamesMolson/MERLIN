/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2006-03-07 09:14:12 $
// $Revision: 1.5 $
// 
/////////////////////////////////////////////////////////////////////////

#ifndef RFStructure_h
#define RFStructure_h 1

#include "merlin_config.h"
#include "NumericalUtils/PhysicalConstants.h"
// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"

#define _FIELD static_cast<F*>(this->itsField)


//	Takes a field which is derived from RFAcceleratingField.

template <class F>
class RFStructure : public TAccCompGF<RectangularGeometry,F>
{
public:

    //	Returns the frequency.
    double GetFrequency () const;

    //	Returns the phase.
    double GetPhase () const;

    //	Set the amplitude.
    void SetAmplitude (double Epk);

    //	Returns the amplitude.
    double GetAmplitude () const;

    //	Returns the wavelength of the RF (in meter).
    double GetWavelength () const;

    //	Returns the k value (=2pi/wavelength) for the field.
    double GetK () const;

    //	Set the frequency.
    void SetFrequency (double f);

    //	Set the phase.
    void SetPhase (double phase);

    void SetWavelength (double lambda);

    void SetK (double k);

    // Calculate the nominal energy gain
    double GetVoltage() const;

protected:

    RFStructure (const string& id, double len, F* aField);
};

template <class F>
inline double RFStructure<F>::GetFrequency () const
{
    return _FIELD->GetFrequency();
}

template <class F>
inline double RFStructure<F>::GetPhase () const
{
    return _FIELD->GetPhase();
}

template <class F>
inline void RFStructure<F>::SetAmplitude (double Epk)
{
    _FIELD->SetAmplitude(Epk);
}

template <class F>
inline double RFStructure<F>::GetAmplitude () const
{
    return _FIELD->GetAmplitude();
}

template <class F>
inline double RFStructure<F>::GetWavelength () const
{
    return _FIELD->GetWavelength();
}

template <class F>
inline double RFStructure<F>::GetK () const
{
    return _FIELD->GetK();
}

template <class F>
inline void RFStructure<F>::SetFrequency (double f)
{
    _FIELD->SetFrequency(f);
}

template <class F>
inline void RFStructure<F>::SetPhase (double phase)
{
    _FIELD->SetPhase(phase);
}

template <class F>
inline void RFStructure<F>::SetWavelength (double lambda)
{
    using PhysicalConstants::SpeedOfLight;
    _FIELD->SetFrequency(SpeedOfLight/lambda);
}

template <class F>
inline void RFStructure<F>::SetK (double k)
{
    using PhysicalConstants::SpeedOfLight;
    _FIELD->SetFrequency(SpeedOfLight*k/twoPi);
}

template <class F>
RFStructure<F>::RFStructure (const string& id, double len, F* aField)
        : TAccCompGF<RectangularGeometry,F>(id,new RectangularGeometry(len),aField)
{}

template <class F>
double RFStructure<F>::GetVoltage () const
{
    return GetAmplitude()*cos(GetPhase())*this->GetLength();
}

#endif

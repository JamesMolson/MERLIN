//## begin module%3ACC8D800320.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\RFStructure.h
 * last modified 05/04/01 17:57:33
 */
//## end module%3ACC8D800320.cm

//## begin module%3ACC8D800320.cp preserve=no
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
//## end module%3ACC8D800320.cp

//## Module: RFStructure%3ACC8D800320; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\RFStructure.h

#ifndef RFStructure_h
#define RFStructure_h 1

//## begin module%3ACC8D800320.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3ACC8D800320.additionalIncludes

//## begin module%3ACC8D800320.includes preserve=yes
#include "NumericalUtils/PhysicalConstants.h"
//## end module%3ACC8D800320.includes

// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"
//## begin module%3ACC8D800320.additionalDeclarations preserve=yes
#define _FIELD static_cast<F*>(itsField)
//## end module%3ACC8D800320.additionalDeclarations


//## Class: RFStructure%3ACC8D800320; Parameterized Class
//	Takes a field which is derived from RFAcceleratingField.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3ACC8F2400D2;RectangularGeometry { -> }

template <class F>
class RFStructure : public TAccCompGF<RectangularGeometry,F>  //## Inherits: <unnamed>%3ACC8DC00050
{
  public:

    //## Other Operations (specified)
      //## Operation: GetFrequency%986466257
      //	Returns the frequency.
      double GetFrequency () const;

      //## Operation: GetPhase%986466258
      //	Returns the phase.
      double GetPhase () const;

      //## Operation: SetAmplitude%986466259
      //	Set the amplitude.
      void SetAmplitude (double Epk);

      //## Operation: GetAmplitude%986466260
      //	Returns the amplitude.
      double GetAmplitude () const;

      //## Operation: GetWavelength%986466261
      //	Returns the wavelength of the RF (in meter).
      double GetWavelength () const;

      //## Operation: GetK%986466262
      //	Returns the k value (=2pi/wavelength) for the field.
      double GetK () const;

      //## Operation: SetFrequency%986466263
      //	Set the frequency.
      void SetFrequency (double f);

      //## Operation: SetPhase%986466264
      //	Set the phase.
      void SetPhase (double phase);

      //## Operation: SetWavelength%986466265
      void SetWavelength (double lambda);

      //## Operation: SetK%986466266
      void SetK (double k);

  protected:
    //## Constructors (specified)
      //## Operation: RFStructure%986466267
      RFStructure (const string& id, double len, F* aField);

  private:
  private:  //## implementation
};

// Parameterized Class RFStructure 


//## Other Operations (inline)
//## Operation: GetFrequency%986466257
template <class F>
inline double RFStructure<F>::GetFrequency () const
{
  //## begin RFStructure::GetFrequency%986466257.body preserve=yes
	return _FIELD->GetFrequency();
  //## end RFStructure::GetFrequency%986466257.body
}

//## Operation: GetPhase%986466258
template <class F>
inline double RFStructure<F>::GetPhase () const
{
  //## begin RFStructure::GetPhase%986466258.body preserve=yes
	return _FIELD->GetPhase();
  //## end RFStructure::GetPhase%986466258.body
}

//## Operation: SetAmplitude%986466259
template <class F>
inline void RFStructure<F>::SetAmplitude (double Epk)
{
  //## begin RFStructure::SetAmplitude%986466259.body preserve=yes
	_FIELD->SetAmplitude(Epk);
  //## end RFStructure::SetAmplitude%986466259.body
}

//## Operation: GetAmplitude%986466260
template <class F>
inline double RFStructure<F>::GetAmplitude () const
{
  //## begin RFStructure::GetAmplitude%986466260.body preserve=yes
	return _FIELD->GetAmplitude();
  //## end RFStructure::GetAmplitude%986466260.body
}

//## Operation: GetWavelength%986466261
template <class F>
inline double RFStructure<F>::GetWavelength () const
{
  //## begin RFStructure::GetWavelength%986466261.body preserve=yes
	return _FIELD->GetWavelength();
  //## end RFStructure::GetWavelength%986466261.body
}

//## Operation: GetK%986466262
template <class F>
inline double RFStructure<F>::GetK () const
{
  //## begin RFStructure::GetK%986466262.body preserve=yes
	return _FIELD->GetK();
  //## end RFStructure::GetK%986466262.body
}

//## Operation: SetFrequency%986466263
template <class F>
inline void RFStructure<F>::SetFrequency (double f)
{
  //## begin RFStructure::SetFrequency%986466263.body preserve=yes
	_FIELD->SetFrequency(f);
  //## end RFStructure::SetFrequency%986466263.body
}

//## Operation: SetPhase%986466264
template <class F>
inline void RFStructure<F>::SetPhase (double phase)
{
  //## begin RFStructure::SetPhase%986466264.body preserve=yes
	_FIELD->SetPhase(phase);
  //## end RFStructure::SetPhase%986466264.body
}

//## Operation: SetWavelength%986466265
template <class F>
inline void RFStructure<F>::SetWavelength (double lambda)
{
  //## begin RFStructure::SetWavelength%986466265.body preserve=yes
	using PhysicalConstants::SpeedOfLight;
	_FIELD->SetFrequency(SpeedOfLight/lambda);
  //## end RFStructure::SetWavelength%986466265.body
}

//## Operation: SetK%986466266
template <class F>
inline void RFStructure<F>::SetK (double k)
{
  //## begin RFStructure::SetK%986466266.body preserve=yes
	using PhysicalConstants::SpeedOfLight;
	_FIELD->SetFrequency(SpeedOfLight*k/twoPi);
  //## end RFStructure::SetK%986466266.body
}

// Parameterized Class RFStructure 

//## Operation: RFStructure%986466267
template <class F>
RFStructure<F>::RFStructure (const string& id, double len, F* aField)
  //## begin RFStructure::RFStructure%986466267.initialization preserve=yes
  : TAccCompGF<RectangularGeometry,F>(id,new RectangularGeometry(len),aField)
  //## end RFStructure::RFStructure%986466267.initialization
{
  //## begin RFStructure::RFStructure%986466267.body preserve=yes
  //## end RFStructure::RFStructure%986466267.body
}


//## begin module%3ACC8D800320.epilog preserve=yes
//## end module%3ACC8D800320.epilog


#endif

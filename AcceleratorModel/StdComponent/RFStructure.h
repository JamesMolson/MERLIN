//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3ACC8D800320.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdComponent\RFStructure.h
 * last modified 24/01/02 15:35:50
 */
//## end module%3ACC8D800320.cm

//## begin module%3ACC8D800320.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 2001 by The Merlin Collaboration.
 * - ALL RIGHTS RESERVED - 
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
//## Source file: C:\C++\Merlin\AcceleratorModel\StdComponent\RFStructure.h

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
// WakePotentials
#include "AcceleratorModel/StdField/WakePotentials.h"
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
      //## Operation: GetFrequency%3ACC8E3402E4
      //	Returns the frequency.
      double GetFrequency () const;

      //## Operation: GetPhase%3ACC8E340352
      //	Returns the phase.
      double GetPhase () const;

      //## Operation: SetAmplitude%3ACC8E340384
      //	Set the amplitude.
      void SetAmplitude (double Epk);

      //## Operation: GetAmplitude%3ACC8E3403C0
      //	Returns the amplitude.
      double GetAmplitude () const;

      //## Operation: GetWavelength%3ACC8E35000D
      //	Returns the wavelength of the RF (in meter).
      double GetWavelength () const;

      //## Operation: GetK%3ACC8E350046
      //	Returns the k value (=2pi/wavelength) for the field.
      double GetK () const;

      //## Operation: SetFrequency%3ACC8E3402A8
      //	Set the frequency.
      void SetFrequency (double f);

      //## Operation: SetPhase%3ACC8E340316
      //	Set the phase.
      void SetPhase (double phase);

      //## Operation: SetWavelength%3ACC8E8F01A4
      void SetWavelength (double lambda);

      //## Operation: SetK%3ACC8E9B037A
      void SetK (double k);

      //## Operation: GetWakePotentials%3C501B0D02AE
      //	Returns the wake potentials associated with this cavity.
      WakePotentials* GetWakePotentials () const;

      //## Operation: SetWakePotentials%3C501B41028A
      //	Sets the wake potentials associated with this cavity.
      void SetWakePotentials (WakePotentials* wp);

  protected:
    //## Constructors (specified)
      //## Operation: RFStructure%3ACC951E0032
      RFStructure (const string& id, double len, F* aField);

  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::StdComponent::class details::<unnamed>%3C501A73039C
      //## Role: RFStructure::wakes%3C501A74013B
      //## begin RFStructure::wakes%3C501A74013B.role preserve=no  private: WakePotentials { -> 0..1RHAN}
      WakePotentials* wakes;
      //## end RFStructure::wakes%3C501A74013B.role

  private: //## implementation
};

// Parameterized Class RFStructure 


//## Other Operations (inline)
//## Operation: GetFrequency%3ACC8E3402E4
template <class F>
inline double RFStructure<F>::GetFrequency () const
{
  //## begin RFStructure::GetFrequency%3ACC8E3402E4.body preserve=yes
	return _FIELD->GetFrequency();
  //## end RFStructure::GetFrequency%3ACC8E3402E4.body
}

//## Operation: GetPhase%3ACC8E340352
template <class F>
inline double RFStructure<F>::GetPhase () const
{
  //## begin RFStructure::GetPhase%3ACC8E340352.body preserve=yes
	return _FIELD->GetPhase();
  //## end RFStructure::GetPhase%3ACC8E340352.body
}

//## Operation: SetAmplitude%3ACC8E340384
template <class F>
inline void RFStructure<F>::SetAmplitude (double Epk)
{
  //## begin RFStructure::SetAmplitude%3ACC8E340384.body preserve=yes
	_FIELD->SetAmplitude(Epk);
  //## end RFStructure::SetAmplitude%3ACC8E340384.body
}

//## Operation: GetAmplitude%3ACC8E3403C0
template <class F>
inline double RFStructure<F>::GetAmplitude () const
{
  //## begin RFStructure::GetAmplitude%3ACC8E3403C0.body preserve=yes
	return _FIELD->GetAmplitude();
  //## end RFStructure::GetAmplitude%3ACC8E3403C0.body
}

//## Operation: GetWavelength%3ACC8E35000D
template <class F>
inline double RFStructure<F>::GetWavelength () const
{
  //## begin RFStructure::GetWavelength%3ACC8E35000D.body preserve=yes
	return _FIELD->GetWavelength();
  //## end RFStructure::GetWavelength%3ACC8E35000D.body
}

//## Operation: GetK%3ACC8E350046
template <class F>
inline double RFStructure<F>::GetK () const
{
  //## begin RFStructure::GetK%3ACC8E350046.body preserve=yes
	return _FIELD->GetK();
  //## end RFStructure::GetK%3ACC8E350046.body
}

//## Operation: SetFrequency%3ACC8E3402A8
template <class F>
inline void RFStructure<F>::SetFrequency (double f)
{
  //## begin RFStructure::SetFrequency%3ACC8E3402A8.body preserve=yes
	_FIELD->SetFrequency(f);
  //## end RFStructure::SetFrequency%3ACC8E3402A8.body
}

//## Operation: SetPhase%3ACC8E340316
template <class F>
inline void RFStructure<F>::SetPhase (double phase)
{
  //## begin RFStructure::SetPhase%3ACC8E340316.body preserve=yes
	_FIELD->SetPhase(phase);
  //## end RFStructure::SetPhase%3ACC8E340316.body
}

//## Operation: SetWavelength%3ACC8E8F01A4
template <class F>
inline void RFStructure<F>::SetWavelength (double lambda)
{
  //## begin RFStructure::SetWavelength%3ACC8E8F01A4.body preserve=yes
	using PhysicalConstants::SpeedOfLight;
	_FIELD->SetFrequency(SpeedOfLight/lambda);
  //## end RFStructure::SetWavelength%3ACC8E8F01A4.body
}

//## Operation: SetK%3ACC8E9B037A
template <class F>
inline void RFStructure<F>::SetK (double k)
{
  //## begin RFStructure::SetK%3ACC8E9B037A.body preserve=yes
	using PhysicalConstants::SpeedOfLight;
	_FIELD->SetFrequency(SpeedOfLight*k/twoPi);
  //## end RFStructure::SetK%3ACC8E9B037A.body
}

//## Operation: GetWakePotentials%3C501B0D02AE
template <class F>
inline WakePotentials* RFStructure<F>::GetWakePotentials () const
{
  //## begin RFStructure::GetWakePotentials%3C501B0D02AE.body preserve=yes
	return wakes;
  //## end RFStructure::GetWakePotentials%3C501B0D02AE.body
}

//## Operation: SetWakePotentials%3C501B41028A
template <class F>
inline void RFStructure<F>::SetWakePotentials (WakePotentials* wp)
{
  //## begin RFStructure::SetWakePotentials%3C501B41028A.body preserve=yes
	wakes = wp;
  //## end RFStructure::SetWakePotentials%3C501B41028A.body
}

// Parameterized Class RFStructure 

//## Operation: RFStructure%3ACC951E0032
template <class F>
RFStructure<F>::RFStructure (const string& id, double len, F* aField)
  //## begin RFStructure::RFStructure%3ACC951E0032.initialization preserve=yes
  : TAccCompGF<RectangularGeometry,F>(id,new RectangularGeometry(len),aField),wakes(0)
  //## end RFStructure::RFStructure%3ACC951E0032.initialization
{
  //## begin RFStructure::RFStructure%3ACC951E0032.body preserve=yes
  //## end RFStructure::RFStructure%3ACC951E0032.body
}


//## begin module%3ACC8D800320.epilog preserve=yes
//## end module%3ACC8D800320.epilog


#endif

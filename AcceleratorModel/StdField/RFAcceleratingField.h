//## begin module%37244252010E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdField\RFAcceleratingField.h
 * last modified 03/04/01 13:51:12
 */
//## end module%37244252010E.cm

//## begin module%37244252010E.cp preserve=no
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
//## end module%37244252010E.cp

//## Module: RFAcceleratingField%37244252010E; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Source file: D:\dev\Merlin\AcceleratorModel\StdField\RFAcceleratingField.h

#ifndef RFAcceleratingField_h
#define RFAcceleratingField_h 1

//## begin module%37244252010E.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37244252010E.additionalIncludes

//## begin module%37244252010E.includes preserve=yes
#include "NumericalUtils/NumericalConstants.h"
#include "NumericalUtils/PhysicalConstants.h"
//## end module%37244252010E.includes

// EMField
#include "AcceleratorModel/EMField.h"
//## begin module%37244252010E.additionalDeclarations preserve=yes
//## end module%37244252010E.additionalDeclarations


//## Class: RFAcceleratingField%37244252010E; Abstract
//	An RF accelerating field. An RF accelerating field is
//	characterised by a sinusoidal electric field (0,0,Ez),
//	which is completely defined by its frequency, amplitude
//	and phase. RFAcceleratingField implements the basic
//	defining attributes for two derived classes, TWRFfield
//	and  SWRFfield, which implement travelling wave and
//	standing wave fields respectively.
//## Category: Merlin::AcceleratorModel::StdField%371DC8870244
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class RFAcceleratingField : public EMField  //## Inherits: <unnamed>%3724427E0096
{
  public:
    //## Constructors (specified)
      //## Operation: RFAcceleratingField%925120598
      //	Constructor taking the amplitude (Epk), the frequency
      //	(f) and the phase of the field.
      RFAcceleratingField (double Epk, double f, double phase = 0);


    //## Other Operations (specified)
      //## Operation: SetFrequency%925120582
      //	Set the frequency.
      void SetFrequency (double f);

      //## Operation: GetFrequency%925120579
      //	Returns the frequency.
      double GetFrequency () const;

      //## Operation: SetPhase%925120584
      //	Set the phase.
      void SetPhase (double phase);

      //## Operation: GetPhase%925120581
      //	Returns the phase.
      double GetPhase () const;

      //## Operation: SetAmplitude%925120583
      //	Set the amplitude.
      void SetAmplitude (double Epk);

      //## Operation: GetAmplitude%925120580
      //	Returns the amplitude.
      double GetAmplitude () const;

      //## Operation: Ez%925120585
      //	Calculate the Ez component.
      virtual double Ez (double z, double t) const = 0;

      //## Operation: GetWavelength%986295710
      //	Returns the wavelength of the RF (in meter).
      double GetWavelength () const;

      //## Operation: GetK%986295711
      //	Returns the k value (=2pi/wavelength) for the field.
      double GetK () const;

  protected:
    // Data Members for Class Attributes

      //## Attribute: w%372429A6017C
      //	Frequency (2*pi*f) in radian/s.
      //## begin RFAcceleratingField::w%372429A6017C.attr preserve=no  protected: double {UA} 
      double w;
      //## end RFAcceleratingField::w%372429A6017C.attr

      //## Attribute: E0%372429AB006E
      //	Peak electric field.
      //## begin RFAcceleratingField::E0%372429AB006E.attr preserve=no  protected: double {UA} 
      double E0;
      //## end RFAcceleratingField::E0%372429AB006E.attr

      //## Attribute: phi%372429B0010E
      //	Arbitrary phase angle (radian)
      //## begin RFAcceleratingField::phi%372429B0010E.attr preserve=no  protected: double {UA} 
      double phi;
      //## end RFAcceleratingField::phi%372429B0010E.attr

  private:
  private:  //## implementation
};

// Class RFAcceleratingField 

//## Operation: RFAcceleratingField%925120598
inline RFAcceleratingField::RFAcceleratingField (double Epk, double f, double phase)
  //## begin RFAcceleratingField::RFAcceleratingField%925120598.initialization preserve=yes
  : w(twoPi*f),E0(Epk),phi(phase)
  //## end RFAcceleratingField::RFAcceleratingField%925120598.initialization
{
  //## begin RFAcceleratingField::RFAcceleratingField%925120598.body preserve=yes
  //## end RFAcceleratingField::RFAcceleratingField%925120598.body
}



//## Other Operations (inline)
//## Operation: SetFrequency%925120582
inline void RFAcceleratingField::SetFrequency (double f)
{
  //## begin RFAcceleratingField::SetFrequency%925120582.body preserve=yes
	w=twoPi*f;
  //## end RFAcceleratingField::SetFrequency%925120582.body
}

//## Operation: GetFrequency%925120579
inline double RFAcceleratingField::GetFrequency () const
{
  //## begin RFAcceleratingField::GetFrequency%925120579.body preserve=yes
	return w/twoPi;
  //## end RFAcceleratingField::GetFrequency%925120579.body
}

//## Operation: SetPhase%925120584
inline void RFAcceleratingField::SetPhase (double phase)
{
  //## begin RFAcceleratingField::SetPhase%925120584.body preserve=yes
	phi=phase;
  //## end RFAcceleratingField::SetPhase%925120584.body
}

//## Operation: GetPhase%925120581
inline double RFAcceleratingField::GetPhase () const
{
  //## begin RFAcceleratingField::GetPhase%925120581.body preserve=yes
	return phi;
  //## end RFAcceleratingField::GetPhase%925120581.body
}

//## Operation: SetAmplitude%925120583
inline void RFAcceleratingField::SetAmplitude (double Epk)
{
  //## begin RFAcceleratingField::SetAmplitude%925120583.body preserve=yes
	E0=Epk;
  //## end RFAcceleratingField::SetAmplitude%925120583.body
}

//## Operation: GetAmplitude%925120580
inline double RFAcceleratingField::GetAmplitude () const
{
  //## begin RFAcceleratingField::GetAmplitude%925120580.body preserve=yes
	return E0;
  //## end RFAcceleratingField::GetAmplitude%925120580.body
}

//## Operation: GetWavelength%986295710
inline double RFAcceleratingField::GetWavelength () const
{
  //## begin RFAcceleratingField::GetWavelength%986295710.body preserve=yes
	using PhysicalConstants::SpeedOfLight;
	return twoPi*SpeedOfLight/w;
  //## end RFAcceleratingField::GetWavelength%986295710.body
}

//## Operation: GetK%986295711
inline double RFAcceleratingField::GetK () const
{
  //## begin RFAcceleratingField::GetK%986295711.body preserve=yes
	using PhysicalConstants::SpeedOfLight;
	return w/SpeedOfLight;
  //## end RFAcceleratingField::GetK%986295711.body
}

// Class RFAcceleratingField 




//## begin module%37244252010E.epilog preserve=yes
//## end module%37244252010E.epilog


#endif

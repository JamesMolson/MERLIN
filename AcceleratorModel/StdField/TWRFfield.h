//## begin module%3724284E0258.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdField\TWRFfield.h
 * last modified 03/04/01 13:44:19
 */
//## end module%3724284E0258.cm

//## begin module%3724284E0258.cp preserve=no
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
//## end module%3724284E0258.cp

//## Module: TWRFfield%3724284E0258; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Source file: D:\dev\Merlin\AcceleratorModel\StdField\TWRFfield.h

#ifndef TWRFfield_h
#define TWRFfield_h 1

//## begin module%3724284E0258.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3724284E0258.additionalIncludes

//## begin module%3724284E0258.includes preserve=yes
#include <cmath>
//## end module%3724284E0258.includes

// RFAcceleratingField
#include "AcceleratorModel/StdField/RFAcceleratingField.h"
//## begin module%3724284E0258.additionalDeclarations preserve=yes
#include "NumericalUtils/PhysicalConstants.h"
//## end module%3724284E0258.additionalDeclarations


//## Class: TWRFfield%3724284E0258
//	A RF travelling wave  field as found in typical
//	accelerating structures. The field (0,0,Ez) is defined as
//
//	        Ez(z,t)=E0 cos(k*z-w*t+phi).
//## Category: Merlin::AcceleratorModel::StdField%371DC8870244
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class TWRFfield : public RFAcceleratingField  //## Inherits: <unnamed>%3724285D03A2
{
  public:
    //## Constructors (specified)
      //## Operation: TWRFfield%925120575
      //	Constructor taking the frequency, peak electric field
      //	and the phase of the RF.
      TWRFfield (double f, double Epk, double phase = 0);


    //## Other Operations (specified)
      //## Operation: GetBFieldAt%925120576
      //	Returns the magnetic field at the point x and time t.
      virtual Vector3D GetBFieldAt (const Point3D& x, double t = 0) const;

      //## Operation: GetEFieldAt%925120577
      //	Returns the electric field at the point x and time t
      virtual Vector3D GetEFieldAt (const Point3D& x, double t = 0) const;

      //## Operation: GetForceAt%925120578
      //	Returns the force due to this field on a particle of
      //	charge q with position x and velocity v at time t.
      virtual Vector3D GetForceAt (const Point3D& x, const Vector3D& v, double q, double t = 0) const;

      //## Operation: Ez%925120597
      //	Calculate the Ez component.
      virtual double Ez (double z, double t) const;

  protected:
  private:
  private:  //## implementation
};

// Class TWRFfield 

//## Operation: TWRFfield%925120575
inline TWRFfield::TWRFfield (double f, double Epk, double phase)
  //## begin TWRFfield::TWRFfield%925120575.initialization preserve=yes
  : RFAcceleratingField(Epk,f,phase)
  //## end TWRFfield::TWRFfield%925120575.initialization
{
  //## begin TWRFfield::TWRFfield%925120575.body preserve=yes
  //## end TWRFfield::TWRFfield%925120575.body
}



//## Other Operations (inline)
//## Operation: Ez%925120597
inline double TWRFfield::Ez (double z, double t) const
{
  //## begin TWRFfield::Ez%925120597.body preserve=yes
	using PhysicalConstants::SpeedOfLight;
	return E0*cos(w*(z/SpeedOfLight-t)+phi);
  //## end TWRFfield::Ez%925120597.body
}

//## begin module%3724284E0258.epilog preserve=yes
//## end module%3724284E0258.epilog


#endif

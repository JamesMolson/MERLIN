//## begin module%372440EC0366.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdField\SWRFfield.h
 * last modified 03/04/01 13:44:19
 */
//## end module%372440EC0366.cm

//## begin module%372440EC0366.cp preserve=no
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
//## end module%372440EC0366.cp

//## Module: SWRFfield%372440EC0366; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Source file: D:\dev\Merlin\AcceleratorModel\StdField\SWRFfield.h

#ifndef SWRFfield_h
#define SWRFfield_h 1

//## begin module%372440EC0366.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%372440EC0366.additionalIncludes

//## begin module%372440EC0366.includes preserve=yes
//## end module%372440EC0366.includes

// RFAcceleratingField
#include "AcceleratorModel/StdField/RFAcceleratingField.h"
//## begin module%372440EC0366.additionalDeclarations preserve=yes
#include <cmath>
#include "NumericalUtils/PhysicalConstants.h"
//## end module%372440EC0366.additionalDeclarations


//## Class: SWRFfield%372440EC0366
//	A RF standing wave  field as found in standing wave
//	accelerating structures. The field (0,0,Ez) is defined as
//
//	        Ez(z,t)=E0 cos(k*z)cos(w*t+phi)
//## Category: Merlin::AcceleratorModel::StdField%371DC8870244
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class SWRFfield : public RFAcceleratingField  //## Inherits: <unnamed>%372442760014
{
  public:
    //## Constructors (specified)
      //## Operation: SWRFfield%925120586
      //	Constructor taking the frequency, peak electric field
      //	and the phase of the RF.
      SWRFfield (double f, double Epk, double phase = 0);


    //## Other Operations (specified)
      //## Operation: GetBFieldAt%925120587
      //	Returns the magnetic field at the point x and time t.
      virtual Vector3D GetBFieldAt (const Point3D& x, double t = 0) const;

      //## Operation: GetEFieldAt%925120588
      //	Returns the electric field at the point x and time t
      virtual Vector3D GetEFieldAt (const Point3D& x, double t = 0) const;

      //## Operation: GetForceAt%925120589
      //	Returns the force due to this field on a particle of
      //	charge q with position x and velocity v at time t.
      virtual Vector3D GetForceAt (const Point3D& x, const Vector3D& v, double q, double t = 0) const;

      //## Operation: Ez%925120596
      //	Calculate the Ez component.
      virtual double Ez (double z, double t) const;

  protected:
  private:
  private:  //## implementation
};

// Class SWRFfield 

//## Operation: SWRFfield%925120586
inline SWRFfield::SWRFfield (double f, double Epk, double phase)
  //## begin SWRFfield::SWRFfield%925120586.initialization preserve=yes
  : RFAcceleratingField(Epk,f,phase)
  //## end SWRFfield::SWRFfield%925120586.initialization
{
  //## begin SWRFfield::SWRFfield%925120586.body preserve=yes
  //## end SWRFfield::SWRFfield%925120586.body
}



//## Other Operations (inline)
//## Operation: Ez%925120596
inline double SWRFfield::Ez (double z, double t) const
{
  //## begin SWRFfield::Ez%925120596.body preserve=yes
	using PhysicalConstants::SpeedOfLight;
	return E0*cos(w*z/SpeedOfLight)*cos(w*t+phi);
  //## end SWRFfield::Ez%925120596.body
}

//## begin module%372440EC0366.epilog preserve=yes
//## end module%372440EC0366.epilog


#endif

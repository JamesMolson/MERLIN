//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3C14B38C028B.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdField\BzField.h
 * last modified 10/12/01 14:24:58
 */
//## end module%3C14B38C028B.cm

//## begin module%3C14B38C028B.cp preserve=no
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
//## end module%3C14B38C028B.cp

//## Module: BzField%3C14B38C028B; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Source file: C:\C++\Merlin\AcceleratorModel\StdField\BzField.h

#ifndef BzField_h
#define BzField_h 1

//## begin module%3C14B38C028B.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3C14B38C028B.additionalIncludes

//## begin module%3C14B38C028B.includes preserve=yes
//## end module%3C14B38C028B.includes

// EMField
#include "AcceleratorModel/EMField.h"
//## begin module%3C14B38C028B.additionalDeclarations preserve=yes
//## end module%3C14B38C028B.additionalDeclarations


//## Class: BzField%3C14B38C028B
//	Represents a constant magnetic field in along the local
//	z-axis (a solenoidal field.)
//## Category: Merlin::AcceleratorModel::StdField%371DC8870244
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Persistence: Transient
//## Cardinality/Multiplicity: n



class BzField : public EMField  //## Inherits: <unnamed>%3C14B3AD01AC
{
  public:
    //## Constructors (specified)
      //## Operation: BzField%3C14B3F90364
      explicit BzField (double B);


    //## Other Operations (specified)
      //## Operation: GetStrength%3C14B4000219
      double GetStrength () const;

      //## Operation: GetBFieldAt%3C14B4280126
      //	Returns the magnetic field at the point x and time t.
      virtual Vector3D GetBFieldAt (const Point3D& x, double t = 0) const;

      //## Operation: GetEFieldAt%3C14B4280131
      //	Returns the electric field at the point x and time t
      virtual Vector3D GetEFieldAt (const Point3D& x, double t = 0) const;

      //## Operation: SetStrength%3C14B7840123
      //	Sets the strength of the field in Tesla.
      void SetStrength (double B);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: Bz%3C14B3EA01C8
      //## begin BzField::Bz%3C14B3EA01C8.attr preserve=no  private: double {UA} 
      double Bz;
      //## end BzField::Bz%3C14B3EA01C8.attr

  private: //## implementation
};

// Class BzField 

//## Operation: BzField%3C14B3F90364
inline BzField::BzField (double B)
  //## begin BzField::BzField%3C14B3F90364.initialization preserve=yes
  : Bz(B)
  //## end BzField::BzField%3C14B3F90364.initialization
{
  //## begin BzField::BzField%3C14B3F90364.body preserve=yes
  //## end BzField::BzField%3C14B3F90364.body
}



//## Other Operations (inline)
//## Operation: GetStrength%3C14B4000219
inline double BzField::GetStrength () const
{
  //## begin BzField::GetStrength%3C14B4000219.body preserve=yes
	return Bz;
  //## end BzField::GetStrength%3C14B4000219.body
}

//## Operation: SetStrength%3C14B7840123
inline void BzField::SetStrength (double B)
{
  //## begin BzField::SetStrength%3C14B7840123.body preserve=yes
	Bz=B;
  //## end BzField::SetStrength%3C14B7840123.body
}

//## begin module%3C14B38C028B.epilog preserve=yes
//## end module%3C14B38C028B.epilog


#endif

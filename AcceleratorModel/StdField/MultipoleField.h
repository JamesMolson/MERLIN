//## begin module%3714A07F030C.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdField\MultipoleField.h
 * last modified 03/04/01 13:44:18
 */
//## end module%3714A07F030C.cm

//## begin module%3714A07F030C.cp preserve=no
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
//## end module%3714A07F030C.cp

//## Module: MultipoleField%3714A07F030C; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Source file: D:\dev\Merlin\AcceleratorModel\StdField\MultipoleField.h

#ifndef MultipoleField_h
#define MultipoleField_h 1

//## begin module%3714A07F030C.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3714A07F030C.additionalIncludes

//## begin module%3714A07F030C.includes preserve=yes
#include <vector>
#include <utility>
#include <iostream>
#include "NumericalUtils/Complex.h"
//## end module%3714A07F030C.includes

// Space3D
#include "EuclideanGeometry/Space3D.h"
// EMField
#include "AcceleratorModel/EMField.h"
//## begin module%3714A07F030C.declarations preserve=no
//## end module%3714A07F030C.declarations

//## begin module%3714A07F030C.additionalDeclarations preserve=yes
//## end module%3714A07F030C.additionalDeclarations


//## Class: MultipoleField%331ED7260248
//	A representation of a multipole expansion of a magnetic
//	field having only a non-zero component of the magnetic
//	vector potential in the z-direction. The general
//	expression for the series is give as
//
//	                                                         
//	 n
//	     By+i Bx =  Sum  B0 (bn-i an) (z/r0)
//	                      n=0
//
//	where z=(x+iy). B0 is the overall scale (in Tesla), and
//	r0 is an aribitrary defining radius. For Multipole
//	expansions representing ideal single multipoles (e.g.
//	dipole, quadrupole etc), then B0 is set to the field
//	strength at r0, and consequently |bn+ i an|=1.
//## Category: Merlin::AcceleratorModel::StdField%371DC8870244
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%33C3DF910154;Point3D { -> }
//## Uses: <unnamed>%33C3DF9303D4;Vector3D { -> }

class MultipoleField : public EMField  //## Inherits: <unnamed>%3714851203DE
{
  public:
    //## Class: TermExpansion%371487E80370
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef std::vector<Complex> TermExpansion;

    //## Class: iterator%33C3EC60029E
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: <unnamed>%371488AF006E;TermExpansion { -> }

    typedef TermExpansion::iterator iterator;

    //## Class: const_iterator%33C3EC65029E
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: <unnamed>%371488AC0212;TermExpansion { -> }

    typedef TermExpansion::const_iterator const_iterator;

  public:
    //## Constructors (specified)
      //## Operation: MultipoleField%868352927
      //	Constructor forming a null (zero) field, but with a
      //	specified field scale factor (in Tesla).
      MultipoleField (double scale, size_t nt = 0);

      //## Operation: MultipoleField%868352928; C++
      //	Constructor forming a single multipole. The field
      //	components bn and an are in Tesla , and are normalised
      //	to the radius r`
      MultipoleField (int np, double bn, double an, double r0);

      //## Operation: MultipoleField%886155587; C++
      //	Constructor forming a single multipole. The field
      //	component bn is in Tesla , and are normalised to the
      //	radius r. If skew is true, creates a skew-field`
      MultipoleField (int np, double bn, double r0, bool skew = false);

      //## Operation: MultipoleField%924771675; C++
      //	Constructor forming a single multipole. The field
      //	component strength bn is in Tesla/meter^n , where n is
      //	the pole number). If skew is true, creates a skew-field.
      MultipoleField (int np, double bn, bool skew = false);


    //## Other Operations (specified)
      //## Operation: GetFieldScale%868352914; C++
      //	Returns the current normalising scale for the field (in
      //	Tesla)
      double GetFieldScale () const;

      //## Operation: SetFieldScale%868352919
      //	Set the (normalising) scale of the field (units are in
      //	Tesla).
      void SetFieldScale (double scale);

      //## Operation: IsNullField%868352929; C++
      //	Returns true if this field is a null field.
      bool IsNullField () const;

      //## Operation: GetKn%924687010
      //	Returns the normalised field component Kn for the
      //	specified magnetic rigidity brho. Kn is defined as
      //	Dn[By+iBx]/brho, where Dn is the n-th complex derivative
      //	wrt x+i y, evaluated at (x+iy)=0. If brho is in
      //	Tesla.meter, Kn has the units 1/meter^(n+1).
      Complex GetKn (int np, double rigidity) const;

      //## Operation: GetField2D%868454707
      //	Returns the 2-D magnetic field in Tesla as the complex
      //	number By+i Bx at the point (x,y) (in meters). The
      //	optional parameter exclude can be used to exclude terms
      //	lower than or equal to exclude Thus a value of exclude=1
      //	gives only that field due to the non-linear terms
      //	(sextupole and above). A Value of -1 (default) includes
      //	all multipole terms.
      Complex GetField2D (double x, double y, int exclude = -1) const;

      //## Operation: GetBFieldAt%924687022
      //	Returns the magnetic field at the point x. The time
      //	variable t is ignored.
      virtual Vector3D GetBFieldAt (const Point3D& x, double t = 0) const;

      //## Operation: GetEFieldAt%924687023
      //	Returns a null vector (pure magnetric field).
      virtual Vector3D GetEFieldAt (const Point3D& x, double t = 0) const;

      //## Operation: GetForceAt%924687024
      //	Return the force due to the magnetic field on a particle
      //	of charge q, with position x and velocity v. The time
      //	variable t is ignored (static magnetic field).
      virtual Vector3D GetForceAt (const Point3D& x, const Vector3D& v, double q, double t = 0) const;

      //## Operation: RotateY180%884089493
      //	Rotates this field 180 degrees about the local vertical
      //	access.
      void RotateY180 ();

      //## Operation: PrintField%888516979
      //	Prints an ascii representation (table) of the field to
      //	os.
      void PrintField (std::ostream& os) const;

      //## Operation: SetComponent%924687011; C++
      //	Add the specified component to the field. The field
      //	components bn and an are in Tesla , and are normalised
      //	to the radius r (default = 1 meter).
      void SetComponent (int np, double bn, double an = 0, double r0 = 1);

      //## Operation: GetComponent%951652581
      //	Returns the field (in Tesla) at the radius r0 due to the
      //	np-th multipole component
      Complex GetComponent (int np, double r0 = 1.0) const;

      //## Operation: GetCoefficient%925916140
      //	Returns the unitless complex coefficient for the np-th
      //	term (bn+i*an).The coefficient is relative to the
      //	specified pole radius r0 (default = 1meter).
      Complex GetCoefficient (int np, double r0 = 1.0) const;

      //## Operation: SetCoefficient%925916141
      //	Sets the unitless complex coefficient for the np-th term
      //	(bn+i*an).The coefficient is relative to the specified
      //	pole radius r0 (default = 1meter).
      void SetCoefficient (int np, const Complex& b, double r0 = 1.0);

      //## Operation: HighestMultipole%925916142
      int HighestMultipole () const;

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: B0%331FE75103C2
      //	The scale of the field in Tesla. The coefficients of the
      //	expansion terms are normalised so that they have no
      //	field unit.
      //## begin MultipoleField::B0%331FE75103C2.attr preserve=no  private: double {UA} 
      double B0;
      //## end MultipoleField::B0%331FE75103C2.attr

      //## Attribute: expansion%37305B1E0276
      //## begin MultipoleField::expansion%37305B1E0276.attr preserve=no  private: TermExpansion {UA} 
      TermExpansion expansion;
      //## end MultipoleField::expansion%37305B1E0276.attr

  private:  //## implementation
};

// Class MultipoleField 

//## Operation: MultipoleField%868352927
inline MultipoleField::MultipoleField (double scale, size_t nt)
  //## begin MultipoleField::MultipoleField%868352927.initialization preserve=yes
  : B0(scale),expansion(nt,Complex(0,0))
  //## end MultipoleField::MultipoleField%868352927.initialization
{
  //## begin MultipoleField::MultipoleField%868352927.body preserve=yes
  //## end MultipoleField::MultipoleField%868352927.body
}



//## Other Operations (inline)
//## Operation: IsNullField%868352929; C++
//## Qualification: inline const
inline bool MultipoleField::IsNullField () const
{
  //## begin MultipoleField::IsNullField%868352929.body preserve=yes
	return B0==0;
  //## end MultipoleField::IsNullField%868352929.body
}

//## Operation: HighestMultipole%925916142
inline int MultipoleField::HighestMultipole () const
{
  //## begin MultipoleField::HighestMultipole%925916142.body preserve=yes
	return expansion.size()-1;
  //## end MultipoleField::HighestMultipole%925916142.body
}

//## begin module%3714A07F030C.epilog preserve=yes
//## end module%3714A07F030C.epilog


#endif

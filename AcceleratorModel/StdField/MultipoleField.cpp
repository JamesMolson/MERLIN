//## begin module%3714A08003DE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdField\MultipoleField.cpp
 * last modified 03/04/01 13:44:18
 */
//## end module%3714A08003DE.cm

//## begin module%3714A08003DE.cp preserve=no
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
//## end module%3714A08003DE.cp

//## Module: MultipoleField%3714A08003DE; Package body
//## Subsystem: Merlin::AcceleratorModel::StdField%371DC93C0118
//## Source file: D:\dev\Merlin\AcceleratorModel\StdField\MultipoleField.cpp

//## begin module%3714A08003DE.includes preserve=yes
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <iterator>
//## end module%3714A08003DE.includes

// MultipoleField
#include "AcceleratorModel/StdField/MultipoleField.h"
//## begin module%3714A08003DE.declarations preserve=no
//## end module%3714A08003DE.declarations

//## begin module%3714A08003DE.additionalDeclarations preserve=yes
using namespace std;

namespace {
	
	double factorial(int n) 
	{
		double f=n--;
		while(n>1) f*=n--;
		return (f==0) ? 1 : f;  //Conditional added by A.Wolski 1/10/01
	}

};
//## end module%3714A08003DE.additionalDeclarations


// Class MultipoleField 



//## Operation: MultipoleField%868352928; C++
//## Qualification: inline
MultipoleField::MultipoleField (int np, double bn, double an, double r0)
  //## begin MultipoleField::MultipoleField%868352928.initialization preserve=yes
  :B0(),expansion(np+1,Complex(0,0))
  //## end MultipoleField::MultipoleField%868352928.initialization
{
  //## begin MultipoleField::MultipoleField%868352928.body preserve=yes
	Complex z(bn,an);
	B0=abs(z);
	expansion[np]=z/B0;
	B0/=pow(r0,np);
  //## end MultipoleField::MultipoleField%868352928.body
}

//## Operation: MultipoleField%886155587; C++
//## Qualification: inline
MultipoleField::MultipoleField (int np, double bn, double r0, bool skew)
  //## begin MultipoleField::MultipoleField%886155587.initialization preserve=yes
  : B0(),expansion(np+1,Complex(0,0))
  //## end MultipoleField::MultipoleField%886155587.initialization
{
  //## begin MultipoleField::MultipoleField%886155587.body preserve=yes
	expansion[np] = skew ? Complex(0,1) : Complex(1,0);
	B0=bn/pow(r0,np);
  //## end MultipoleField::MultipoleField%886155587.body
}

//## Operation: MultipoleField%924771675; C++
//## Qualification: inline
MultipoleField::MultipoleField (int np, double bn, bool skew)
  //## begin MultipoleField::MultipoleField%924771675.initialization preserve=yes
  :B0(bn/factorial(np)),expansion(np+1,Complex(0,0))
  //## end MultipoleField::MultipoleField%924771675.initialization
{
  //## begin MultipoleField::MultipoleField%924771675.body preserve=yes
	expansion[np] = skew ? Complex(0,1) : Complex(1,0);
  //## end MultipoleField::MultipoleField%924771675.body
}



//## Other Operations (implementation)
//## Operation: GetFieldScale%868352914; C++
//## Qualification: const
double MultipoleField::GetFieldScale () const
{
  //## begin MultipoleField::GetFieldScale%868352914.body preserve=yes
	return B0;
  //## end MultipoleField::GetFieldScale%868352914.body
}

//## Operation: SetFieldScale%868352919
void MultipoleField::SetFieldScale (double scale)
{
  //## begin MultipoleField::SetFieldScale%868352919.body preserve=yes
  B0=scale;
  //## end MultipoleField::SetFieldScale%868352919.body
}

//## Operation: GetKn%924687010
Complex MultipoleField::GetKn (int np, double rigidity) const
{
  //## begin MultipoleField::GetKn%924687010.body preserve=yes
	assert(rigidity!=0);
	return np<expansion.size() ? (B0/rigidity)*factorial(np)*expansion[np] : Complex(0);
  //## end MultipoleField::GetKn%924687010.body
}

//## Operation: GetField2D%868454707
Complex MultipoleField::GetField2D (double x, double y, int exclude) const
{
  //## begin MultipoleField::GetField2D%868454707.body preserve=yes
	if(IsNullField() || (++exclude)>expansion.size())
		return Complex(0);
	
	const Complex z0(x,y);

	Complex B(0,0);
	Complex z(1);

	for(int n=0; n<exclude; n++) z*=z0;
	
	for(const_iterator ti=expansion.begin()+exclude;ti!=expansion.end();ti++) {
		B+=(*ti)*z;
		z*=z0;
	}
	
	return B0*B;  
  //## end MultipoleField::GetField2D%868454707.body
}

//## Operation: GetBFieldAt%924687022
Vector3D MultipoleField::GetBFieldAt (const Point3D& x, double t) const
{
  //## begin MultipoleField::GetBFieldAt%924687022.body preserve=yes
	Complex B = GetField2D(x.x,x.y);
	return Vector3D(B.imag(),B.real(),0);
  //## end MultipoleField::GetBFieldAt%924687022.body
}

//## Operation: GetEFieldAt%924687023
Vector3D MultipoleField::GetEFieldAt (const Point3D& x, double t) const
{
  //## begin MultipoleField::GetEFieldAt%924687023.body preserve=yes
	return Vector3D(0,0,0);
  //## end MultipoleField::GetEFieldAt%924687023.body
}

//## Operation: GetForceAt%924687024
Vector3D MultipoleField::GetForceAt (const Point3D& x, const Vector3D& v, double q, double t) const
{
  //## begin MultipoleField::GetForceAt%924687024.body preserve=yes
	Complex B = GetField2D(x.x,x.y);
	double qBx=q*B.imag();
	double qBy=q*B.real();
	return Vector3D(-qBy*v.z,qBx*v.z,qBy*v.x-qBx*v.y);
  //## end MultipoleField::GetForceAt%924687024.body
}

//## Operation: RotateY180%884089493
void MultipoleField::RotateY180 ()
{
  //## begin MultipoleField::RotateY180%884089493.body preserve=yes
	// To rotate the field 180 degrees, we perform the following
	//			bn		an
	// n-odd	-		+
	// n-even	+		-
	bool even=false;
	for(int n=0; n<expansion.size(); n++, even=!even) {
		Complex& z = expansion[n];
		if(even)
			z.imag(-z.imag());
		else
			z.real(-z.real());
	}
  //## end MultipoleField::RotateY180%884089493.body
}

//## Operation: PrintField%888516979
void MultipoleField::PrintField (std::ostream& os) const
{
  //## begin MultipoleField::PrintField%888516979.body preserve=yes
	os<<"B0: "<<B0<<" Tesla\n";
	copy(expansion.begin(),expansion.end(),ostream_iterator<Complex>(os,"\n"));
	os<<endl;
  //## end MultipoleField::PrintField%888516979.body
}

//## Operation: SetComponent%924687011; C++
//## Qualification: inline
void MultipoleField::SetComponent (int np, double bn, double an, double r0)
{
  //## begin MultipoleField::SetComponent%924687011.body preserve=yes
	assert(B0!=0);

	if(np+1>expansion.size())
		expansion.resize(np+1,Complex(0,0));
	
	expansion[np]=Complex(bn,an)/(B0*pow(r0,np));
  //## end MultipoleField::SetComponent%924687011.body
}

//## Operation: GetComponent%951652581
Complex MultipoleField::GetComponent (int np, double r0) const
{
  //## begin MultipoleField::GetComponent%951652581.body preserve=yes
	return B0*GetCoefficient(np,r0);
  //## end MultipoleField::GetComponent%951652581.body
}

//## Operation: GetCoefficient%925916140
Complex MultipoleField::GetCoefficient (int np, double r0) const
{
  //## begin MultipoleField::GetCoefficient%925916140.body preserve=yes
	if(np+1>expansion.size())
		const_cast<MultipoleField&>(*this).expansion.resize(np+1,Complex(0,0));

	return expansion[np]*pow(r0,np);
  //## end MultipoleField::GetCoefficient%925916140.body
}

//## Operation: SetCoefficient%925916141
void MultipoleField::SetCoefficient (int np, const Complex& b, double r0)
{
  //## begin MultipoleField::SetCoefficient%925916141.body preserve=yes
	if(np+1>expansion.size())
		expansion.resize(np+1,Complex(0,0));
	expansion[np]=b/pow(r0,np);
  //## end MultipoleField::SetCoefficient%925916141.body
}

//## begin module%3714A08003DE.epilog preserve=yes
//## end module%3714A08003DE.epilog

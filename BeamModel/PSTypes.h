//## begin module%36BDEB610104.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BasicTransport\PSTypes.h
 * last modified 08/10/00 11:26:57
 */
//## end module%36BDEB610104.cm

//## begin module%36BDEB610104.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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
//## end module%36BDEB610104.cp

//## Module: PSTypes%36BDEB610104; Package specification
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Source file: C:\C++\Merlin\BasicTransport\PSTypes.h

#ifndef PSTypes_h
#define PSTypes_h 1

//## begin module%36BDEB610104.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%36BDEB610104.additionalIncludes

//## begin module%36BDEB610104.includes preserve=yes
#include <algorithm>
#include <iostream>
//## end module%36BDEB610104.includes

#include <list>
#include <vector>
// LinearAlgebra
#include "TLAS/LinearAlgebra.h"
// MVCMatrix
#include "NumericalUtils/MVCMatrix.h"
//## begin module%36BDEB610104.declarations preserve=no
//## end module%36BDEB610104.declarations

//## begin module%36BDEB610104.additionalDeclarations preserve=yes
#define ps_X 0
#define ps_XP 1
#define ps_Y 2
#define ps_YP 3
#define ps_CT 4
#define ps_DP 5
//## end module%36BDEB610104.additionalDeclarations


//## Class: PSmoments%34954EA20042; Instantiated Class
//	6D first- and second-order moments for a bunch.
//## Category: Merlin::BasicTransport%34797A9700F7; Global
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef MVCMatrix< double,6 > PSmoments;

//## Class: PSmoments2D%36A75FBB00A0; Instantiated Class
//	2D first- and second-order moments of a bunch. These
//	data generally represent a projection of the 6D bunch
//	phase space onto a single (2D) plane.
//## Category: Merlin::BasicTransport%34797A9700F7; Global
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef MVCMatrix< double,2 > PSmoments2D;

//## Class: PSmomentsArray%36BDD93D0172; Instantiated Class
//	A linear array of PSmoment objects.
//## Category: Merlin::BasicTransport%34797A9700F7; Global
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%36BDD9F800AA;PSmoments { -> }

typedef std::vector< PSmoments > PSmomentsArray;

//## Class: PScoord%3721DACA015E
//	Indecies for phase space coordinates.
//## Category: Merlin::BasicTransport%34797A9700F7; Global
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef int PScoord;

//## Class: PSvector%349500050206
//	A single 6-dimensional phase space vector.
//## Category: Merlin::BasicTransport%34797A9700F7; Global
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: can convert to%36A75F440316;RealVector { -> }
//## Uses: <unnamed>%3721DB41021C;PScoord { -> }

class PSvector 
{
  public:
    //## Constructors (specified)
      //## Operation: PSvector%884089495
      PSvector ()
        //## begin PSvector::PSvector%884089495.initialization preserve=yes
        //## end PSvector::PSvector%884089495.initialization
      {
        //## begin PSvector::PSvector%884089495.body preserve=yes
        //## end PSvector::PSvector%884089495.body
      }

      //## Operation: PSvector%935667555
      explicit PSvector (double x)
        //## begin PSvector::PSvector%935667555.initialization preserve=yes
        //## end PSvector::PSvector%935667555.initialization
      {
        //## begin PSvector::PSvector%935667555.body preserve=yes
			std::fill(v,v+6,x);
        //## end PSvector::PSvector%935667555.body
      }


    //## Other Operations (specified)
      //## Operation: x%882180671
      //	Component accessors.
      double x () const
      {
        //## begin PSvector::x%882180671.body preserve=yes
			return v[0];
        //## end PSvector::x%882180671.body
      }

      //## Operation: y%882180672
      double y () const
      {
        //## begin PSvector::y%882180672.body preserve=yes
			return v[2];
        //## end PSvector::y%882180672.body
      }

      //## Operation: ct%882180673
      double ct () const
      {
        //## begin PSvector::ct%882180673.body preserve=yes
			return v[4];
        //## end PSvector::ct%882180673.body
      }

      //## Operation: xp%882180674
      double xp () const
      {
        //## begin PSvector::xp%882180674.body preserve=yes
			return v[1];
        //## end PSvector::xp%882180674.body
      }

      //## Operation: yp%882180675
      double yp () const
      {
        //## begin PSvector::yp%882180675.body preserve=yes
			return v[3];
        //## end PSvector::yp%882180675.body
      }

      //## Operation: dp%882180676
      double dp () const
      {
        //## begin PSvector::dp%882180676.body preserve=yes
			return v[5];
        //## end PSvector::dp%882180676.body
      }

      //## Operation: operator[]%882180669
      //	Array access.
      double operator [] (PScoord coord) const
      {
        //## begin PSvector::operator[]%882180669.body preserve=yes
			return v[coord];
        //## end PSvector::operator[]%882180669.body
      }

      //## Operation: x%884089427
      //	Component mutators.
      double& x ()
      {
        //## begin PSvector::x%884089427.body preserve=yes
			return v[0];
        //## end PSvector::x%884089427.body
      }

      //## Operation: y%884089428
      double& y ()
      {
        //## begin PSvector::y%884089428.body preserve=yes
			return v[2];
        //## end PSvector::y%884089428.body
      }

      //## Operation: ct%884089429
      double& ct ()
      {
        //## begin PSvector::ct%884089429.body preserve=yes
			return v[4];
        //## end PSvector::ct%884089429.body
      }

      //## Operation: xp%884089430
      double& xp ()
      {
        //## begin PSvector::xp%884089430.body preserve=yes
			return v[1];
        //## end PSvector::xp%884089430.body
      }

      //## Operation: yp%884089431
      double& yp ()
      {
        //## begin PSvector::yp%884089431.body preserve=yes
			return v[3];
        //## end PSvector::yp%884089431.body
      }

      //## Operation: dp%884089432
      double& dp ()
      {
        //## begin PSvector::dp%884089432.body preserve=yes
			return v[5];
        //## end PSvector::dp%884089432.body
      }

      //## Operation: operator[]%882180670
      //	Array access.
      double& operator [] (PScoord coord)
      {
        //## begin PSvector::operator[]%882180670.body preserve=yes
			return v[coord];
        //## end PSvector::operator[]%882180670.body
      }

      //## Operation: operator RealVector%882199458
      //	Conversion to a RealVector.
      operator RealVector () const
      {
        //## begin PSvector::operator RealVector%882199458.body preserve=yes
			return RealVector(v,6);
        //## end PSvector::operator RealVector%882199458.body
      }

      //## Operation: operator==%884089496; C++
      bool operator == (const PSvector& psv) const
      {
        //## begin PSvector::operator==%884089496.body preserve=yes
			return memcmp(v,psv.v,6*sizeof(double))==0;
        //## end PSvector::operator==%884089496.body
      }

      //## Operation: operator!=%884089497; C++
      bool operator != (const PSvector& psv) const
      {
        //## begin PSvector::operator!=%884089497.body preserve=yes
          return memcmp(v,psv.v,6*sizeof(double))!=0;
        //## end PSvector::operator!=%884089497.body
      }

      //## Operation: zero%884688425
      //	Sets the vector to zero.
      void zero ()
      {
        //## begin PSvector::zero%884688425.body preserve=yes
			double *p=v;
			while(p!=(v+6)) *(p++)=0;
        //## end PSvector::zero%884688425.body
      }

      //## Operation: operator+=%884688446; C++
      //	Arithmetic assignment
      PSvector& operator += (const PSvector& p)
      {
        //## begin PSvector::operator+=%884688446.body preserve=yes
			double *q=v;
			const double *r=p.v;
			while(q!=(v+6)) *(q++) += *(r++);
			return *this;
        //## end PSvector::operator+=%884688446.body
      }

      //## Operation: operator-=%884688447; C++
      //	Arithmetic assignment
      PSvector& operator -= (const PSvector& p)
      {
        //## begin PSvector::operator-=%884688447.body preserve=yes
			double *q=v;
			const double *r=p.v;
			while(q!=(v+6)) *(q++) -= *(r++);
			return *this;
        //## end PSvector::operator-=%884688447.body
      }

      //## Operation: operator*=%935667553; C++
      //	Arithmetic assignment
      PSvector& operator *= (double x)
      {
        //## begin PSvector::operator*=%935667553.body preserve=yes
		  for(double *q = v; q!=v+6;q++)
			  (*q)*=x;
		  return *this;
        //## end PSvector::operator*=%935667553.body
      }

      //## Operation: operator/=%935667554; C++
      //	Arithmetic assignment
      PSvector& operator /= (double x)
      {
        //## begin PSvector::operator/=%935667554.body preserve=yes
		  for(double *q = v; q!=v+6;q++)
			  (*q)/=x;
		  return *this;
        //## end PSvector::operator/=%935667554.body
      }

      //## Operation: operator<<%935667551
      //	Reads the vector as six floating point numbers,
      //	separated by spaces and terminated by a newline.
      friend std::ostream& operator << (std::ostream& os, const PSvector& v);

      //## Operation: operator>>%935667552
      //	Outputs the vector in row form, space delimeted with a
      //	terminating newline.
      friend std::istream& operator >> (std::istream& is, PSvector& v);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: v%36A75F54029E
      //## begin PSvector::v%36A75F54029E.attr preserve=no  private: double[6] {UA} 
      double v[6];
      //## end PSvector::v%36A75F54029E.attr

  private:  //## implementation
};

//## Class: PSvectorArray%36BDD9350122; Instantiated Class
//	A linear array of PSvector objects.
//## Category: Merlin::BasicTransport%34797A9700F7; Global
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%36BDD9F30230;PSvector { -> }

typedef std::list< PSvector > PSvectorArray;

//## begin PSmoments.instantiation preserve=no
template class MVCMatrix< double,6 >;
//## end PSmoments.instantiation
//## begin PSmoments2D.instantiation preserve=no
template class MVCMatrix< double,2 >;
//## end PSmoments2D.instantiation
//## begin module%36BDEB610104.epilog preserve=yes
// VC++5.0 template bug requires the following
// operators
inline bool operator>(const PSvector& p1,const PSvector& p2)
{
	return p1.ct()>p2.ct();
}
inline bool operator<(const PSvector& p1,const PSvector& p2)
{
	return p1.ct()<p2.ct();
}

inline bool operator>(const PSmoments&,const PSmoments&)
{
	assert(false);
	return false;
}
inline bool operator<(const PSmoments&,const PSmoments&)
{
	assert(false);
	return false;
}

//## end module%36BDEB610104.epilog


#endif

//## begin module%3906B7C000DE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file NumericalUtils\Range.h
 * last modified 04/26/00  11:36:52
 */
//## end module%3906B7C000DE.cm

//## begin module%3906B7C000DE.cp preserve=no
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
//## end module%3906B7C000DE.cp

//## Module: Range%3906B7C000DE; Package specification
//## Subsystem: NumericalUtils%37C40272014A
//## Source file: C:\C++\Merlin\NumericalUtils\Range.h

#ifndef Range_h
#define Range_h 1

//## begin module%3906B7C000DE.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3906B7C000DE.additionalIncludes

//## begin module%3906B7C000DE.includes preserve=yes
#include <functional>
//## end module%3906B7C000DE.includes

//## begin module%3906B7C000DE.declarations preserve=no
//## end module%3906B7C000DE.declarations

//## begin module%3906B7C000DE.additionalDeclarations preserve=yes
//## end module%3906B7C000DE.additionalDeclarations


//## Class: RangeBase%3906B6A003B5
//## Category: NumericalUtils%33562A28020C; Global
//## Subsystem: NumericalUtils%37C40272014A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class RangeBase 
{
  public:
    //## Class: Result%3906B72D01E1
    //## Category: <Top Level>
    //## Subsystem: NumericalUtils%37C40272014A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef enum {ok,belowMin,aboveMax} Result;

  public:
  protected:
  private:
  private:  //## implementation
};

//## Class: Range%335628870356; Parameterized Class
//	Represents an allowed contiguous range of a floating
//	point number.
//## Category: NumericalUtils%33562A28020C; Global
//## Subsystem: NumericalUtils%37C40272014A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3906B755012B;RangeBase::Result { -> F}

template <class T, class C = std::less<T> >
class Range : public RangeBase  //## Inherits: <unnamed>%3906B6A801B8
{
  public:
    //## Constructors (specified)
      //## Operation: Range%879938568; C++
      //	Default constructor constructs an infinite range.
      Range ();

      //## Operation: Range%861287601
      //	Constructor taking the range (lo,hi>
      Range (const T& lo, const T& hi);


    //## Other Operations (specified)
      //## Operation: IsUnbounded%879938569; C++
      //	Returns true if this range is unbouned (i.e. represents
      //	+/-infinity).
      bool IsUnbounded () const;

      //## Operation: operator()%861287603
      //	Returns true if min<=x<=max.
      bool operator () (const T& x) const;

      //## Operation: operator==%861287604
      bool operator == (const Range& rhs) const;

      //## Operation: operator!=%861287605
      bool operator != (const Range& rhs) const;

      //## Operation: Check%861287606
      //	Checks id x is within the range. Returns belowMin, ok or
      //	aboveMax.
      RangeBase::Result Check (const T& x) const;

    // Data Members for Class Attributes

      //## Attribute: min%335629FA01AB
      //	The minimum value of the range.
      //## begin Range::min%335629FA01AB.attr preserve=no  public: T {UA} 
      T min;
      //## end Range::min%335629FA01AB.attr

      //## Attribute: max%335629FF02E9
      //	The maximum value of the range.
      //## begin Range::max%335629FF02E9.attr preserve=no  public: T {UA} 
      T max;
      //## end Range::max%335629FF02E9.attr

  protected:
  private:
  private:  //## implementation
};

// Class RangeBase 

// Parameterized Class Range 

//## Operation: Range%879938568; C++
//## Qualification: inlined
template <class T, class C>
inline Range<T,C>::Range ()
  //## begin Range::Range%879938568.initialization preserve=yes
  :min(0),max(0)
  //## end Range::Range%879938568.initialization
{
  //## begin Range::Range%879938568.body preserve=yes
  //## end Range::Range%879938568.body
}

//## Operation: Range%861287601
template <class T, class C>
inline Range<T,C>::Range (const T& lo, const T& hi)
  //## begin Range::Range%861287601.initialization preserve=yes
  : min(lo),max(hi)
  //## end Range::Range%861287601.initialization
{
  //## begin Range::Range%861287601.body preserve=yes
	if(C()(max,min)) 
		std::swap(min,max);
  //## end Range::Range%861287601.body
}



//## Other Operations (inline)
//## Operation: IsUnbounded%879938569; C++
//## Qualification: const inlined
template <class T, class C>
inline bool Range<T,C>::IsUnbounded () const
{
  //## begin Range::IsUnbounded%879938569.body preserve=yes
	return min==0 && max==0;
  //## end Range::IsUnbounded%879938569.body
}

//## Operation: operator()%861287603
template <class T, class C>
inline bool Range<T,C>::operator () (const T& x) const
{
  //## begin Range::operator()%861287603.body preserve=yes
	if(IsUnbounded())
		return true;
	else
		return x>=min && x<=max;
  //## end Range::operator()%861287603.body
}

//## Operation: operator==%861287604
template <class T, class C>
inline bool Range<T,C>::operator == (const Range& rhs) const
{
  //## begin Range::operator==%861287604.body preserve=yes
	return min==rhs.min && max==rhs.max;
  //## end Range::operator==%861287604.body
}

//## Operation: operator!=%861287605
template <class T, class C>
inline bool Range<T,C>::operator != (const Range& rhs) const
{
  //## begin Range::operator!=%861287605.body preserve=yes
	return min!=rhs.min || max!=rhs.max;
  //## end Range::operator!=%861287605.body
}

//## Operation: Check%861287606
template <class T, class C>
inline RangeBase::Result Range<T,C>::Check (const T& x) const
{
  //## begin Range::Check%861287606.body preserve=yes
	if(isUnbounded())
		return ok;
	else if(x<min)
		return belowMin;
	else if(x<=max)
		return ok;
	else
		return aboveMax;
  //## end Range::Check%861287606.body
}

// Class RangeBase 

// Parameterized Class Range 



//## begin module%3906B7C000DE.epilog preserve=yes
typedef Range< double > FloatRange;
//## end module%3906B7C000DE.epilog


#endif

//## begin module%37C52CB70208.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamModel\PSTypes.cpp
 * last modified 04/04/01 14:21:55
 */
//## end module%37C52CB70208.cm

//## begin module%37C52CB70208.cp preserve=no
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
//## end module%37C52CB70208.cp

//## Module: PSTypes%37C52CB70208; Package body
//## Subsystem: Merlin::BeamModel%3ACB10800370
//## Source file: D:\dev\Merlin\BeamModel\PSTypes.cpp

//## begin module%37C52CB70208.includes preserve=yes
#include <iomanip>
//## end module%37C52CB70208.includes

// PSTypes
#include "BeamModel/PSTypes.h"
//## begin module%37C52CB70208.declarations preserve=no
//## end module%37C52CB70208.declarations

//## begin module%37C52CB70208.additionalDeclarations preserve=yes
using namespace std;
//## end module%37C52CB70208.additionalDeclarations


// Class PSvector 



//## Other Operations (implementation)
//## Operation: operator<<%935667551
std::ostream& operator << (std::ostream& os, const PSvector& v)
{
  //## begin PSvector::operator<<%935667551.body preserve=yes
	int oldp=os.precision(6);
	ios_base::fmtflags oflg=os.setf(ios::scientific,ios::floatfield);

	for(const double *q = v.v; q!=v.v+6; q++)
		os<<std::setw(16)<<*q;
	os<<endl;

	os.precision(oldp);
	os.flags(oflg);

	return os;
  //## end PSvector::operator<<%935667551.body
}

//## Operation: operator>>%935667552
std::istream& operator >> (std::istream& is, PSvector& v)
{
  //## begin PSvector::operator>>%935667552.body preserve=yes
	for(double *q = v.v; (q!=v.v+6) && is; q++)
		is>>*q;
	return is;
  //## end PSvector::operator>>%935667552.body
}

//## begin PSvectorArray.instantiation preserve=no
template class std::list< PSvector >;
//## end PSvectorArray.instantiation
//## begin PSmomentsArray.instantiation preserve=no
template class std::vector< PSmoments >;
//## end PSmomentsArray.instantiation
//## begin module%37C52CB70208.epilog preserve=yes
//## end module%37C52CB70208.epilog

//## begin module%37C40288015E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file NumericalUtils\utils.h
 * last modified 25/08/99 16:49:53
 */
//## end module%37C40288015E.cm

//## begin module%37C40288015E.cp preserve=no
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
//## end module%37C40288015E.cp

//## Module: utils%37C40288015E; Package specification
//## Subsystem: NumericalUtils%37C40272014A
//## Source file: D:\Dev\Merlin\NumericalUtils\utils.h

#ifndef utils_h
#define utils_h 1

//## begin module%37C40288015E.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37C40288015E.additionalIncludes

//## begin module%37C40288015E.includes preserve=yes
#include <ctime>
#include <limits>
#include <cmath>
//## end module%37C40288015E.includes

//## begin module%37C40288015E.declarations preserve=no
//## end module%37C40288015E.declarations

//## begin module%37C40288015E.additionalDeclarations preserve=yes

inline bool fequal(double x, double y,
				   double tol=std::numeric_limits<double>::epsilon())
{
	return fabs(x-y)<=tol;
}

// TIMING macro. Used to output the real time used (in seconds)
// by a function call. The result is output to OS, which must
// be an ostream.
#define TIMING(FUNC,OS) \
{time_t start_t = time(0);FUNC;	\
OS<<"done: real time: "<<int(difftime(time(0),start_t))<<" seconds"<<endl;}

// special function definitions
// ----------------------------

// Error function
double erfc(double x);
inline double erf(double x) { return 1-erfc(x); }
double NormalBin(double x1, double x2);


//## end module%37C40288015E.additionalDeclarations


//## begin module%37C40288015E.epilog preserve=yes
//## end module%37C40288015E.epilog


#endif

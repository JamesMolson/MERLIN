/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file NumericalUtils\utils.h
 * last modified 25/08/99 16:49:53
 *
 *
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

#ifndef utils_h
#define utils_h 1

#include "merlin_config.h"
#include <ctime>
#include <limits>
#include <cmath>

inline bool fequal(double x, double y,
				   double tol=std::numeric_limits<double>::epsilon())
{
	return fabs(x-y)<=tol;
}

inline int Round(double x) { return static_cast<int>(x+0.5); }

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

// Modified Bessel function
double BesselI0(double x);
double BesselI1(double x);
double BesselIn(int n, double x);

// Gamma function
double LogGamma(double);
inline double Gamma(double x) { return exp(LogGamma(x)); }

#endif

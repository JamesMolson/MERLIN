/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2002)
 * 
 * file Merlin/NumericalUtils/Interpolation.h
 * last modified 01/24/02 12.05
 */

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

#ifndef Interpolation_h
#define Interpolation_h 1

#include "Exception/MerlinException.h"
#include "NumericalUtils/Range.h"

#include <vector>

// class Interpolation
//    An interpolation functor which interpolates values from a data table.
//    Currenly only linear interpolation is assumed.

class Interpolation {
public:

	struct Data {
		Data(double x1, double y1) : x(x1),y(y1) {}
		double x,y;
	};

	// exception
	class BadRange : public MerlinException {
	public:
		BadRange(double x, const FloatRange& r);
		double value;
		FloatRange valid_range;
	};

	Interpolation(const std::vector<Data>& data);

	double operator()(double x) const throw (BadRange);

private:

	size_t LocateSegment(double x) const;
	std::vector<Data> dat;
};



#endif


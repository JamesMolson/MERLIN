/*
* Merlin C++ Class Library for Charged Particle Accelerator Simulations
* 
* Class library version 2.0 (2002)
* 
* file Merlin/NumericalUtils/Interpolation.cpp
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

#include "NumericalUtils/Interpolation.h"
#include <algorithm>
#include <string>
#include <sstream>

namespace {
	
	typedef Interpolation::Data Data;
	using namespace std;

	inline bool sort_x(const Data& d1, const Data& d2)
	{
		return d1.x<d2.x;
	}
};

// exception
Interpolation::BadRange::BadRange(double x, const FloatRange& r)
: MerlinException(""),value(x),valid_range(r)
{
	ostringstream buf;
	buf<<value<<" not in interpolation range ("<<r.min<<","<<r.max<<')';
	SetMsg(buf.str());
}


Interpolation::Interpolation(const std::vector<Data>& data)
	:dat(data)
{
	// need to sort in ascending x values
	sort(dat.begin(),dat.end(),sort_x);
}

size_t Interpolation::LocateSegment(double x) const
{
	size_t ju=dat.size(),jl=0,jm;

	while((ju-jl)>1) {
		jm = (ju+jl)>>1;
		if(x>dat[jm].x)
			jl=jm;
		else
			ju=jm;
	}
	return jl;
}


double Interpolation::operator()(double x) const throw (Interpolation::BadRange)
{
	if(x<dat.front().x || x>dat.back().x)
		throw BadRange(x,FloatRange(dat.front().x,dat.back().x));

	size_t n = LocateSegment(x);
	return dat[n].y+(x-dat[n].x)*(dat[n+1].y-dat[n].y)/(dat[n+1].x-dat[n].x);
}

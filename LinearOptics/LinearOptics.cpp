/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\LinearOptics\LinearOptics.cpp
 * last modified 03/04/01 14:32:34
 */

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

#include "LinearOptics/LinearOptics.h"
#include "LinearOptics/LinearMatrixTracker.h"

namespace {

	using namespace std;

	template<class TT,class II>
	void PerformTracking(TT& trker, II first, II last)
	{
		do {
			trker(&((*first)->GetComponent()));
		} while(++first != last);
	}
};

RMtrx Rmatrix(AcceleratorModel::Beamline& bline, double p0)
{
	LinearMatrixTracker trker(p0);
	PerformTracking(trker,bline.begin(),bline.end());
	return trker.GetCurrentR1();
}

RMtrx Rmatrix(AcceleratorModel::RingIterator ringi, double p0)
{
	LinearMatrixTracker trker(p0);
	PerformTracking(trker,ringi,ringi);
	return trker.GetCurrentR1();
}


// RMtrx Rmatrix(AcceleratorModel::RingIterator ring, double p0);

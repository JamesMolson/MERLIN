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
#include "Utility/StringPattern.h"
#include <algorithm>
#include <iterator>

namespace {

	using namespace std;

	template<class TT,class II>
	void PerformTracking(TT& trker, II first, II last)
	{
		do {
			trker(&((*first)->GetComponent()));
		} while(++first != last);
	}

	struct OrPattern {
		vector<StringPattern> patterns;

		OrPattern(const vector<string>& p)
		{	
			patterns.reserve(p.size());
			copy(p.begin(),p.end(),back_inserter(patterns));
		}

		bool operator()(const string& s) const {
			for(size_t n=0; n<patterns.size(); n++) {
				if((patterns[n])(s))
					return true;
			}
			return false;
		}
	};
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

RMtrxTable* RmatrixTable(AcceleratorModel::Beamline& bline, double p0, bool centred)
{
	vector<string> patterns(1,"*");
	return RmatrixTable(bline,p0,patterns,centred);
}

RMtrxTable* RmatrixTable(AcceleratorModel::Beamline& bline, double p0, 
						const std::vector<std::string>& incTypes,
						bool centred)
{
	OrPattern opat(incTypes);
	
	RMtrxTable* rtable = new RMtrxTable();
	rtable->reserve(5);

	LinearMatrixTracker rtrack(p0);

	for(AcceleratorModel::BeamlineIterator ci = bline.begin(); ci!=bline.end(); ci++) {
		AcceleratorComponent& component = (*ci)->GetComponent();
		component.PrepareTracker(rtrack);
		double ds = component.GetLength();
		if(opat(component.GetQualifiedName())) {
			if(centred)
				rtrack.TrackStep(ds/2);
			else
				rtrack.Track();
			
			rtable->push_back(rtrack.GetCurrentR1());
		
			if(centred)
				rtrack.TrackStep(ds/2);
		}
		else
			rtrack.Track();
	}

	return rtable;
}

// RMtrx Rmatrix(AcceleratorModel::RingIterator ring, double p0);

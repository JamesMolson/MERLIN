/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunchUtilities.cpp
 * last modified 30/04/01 12:28:48
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

#include "merlin_config.h"
#include "BeamDynamics/ParticleTracking/ParticleBunchUtilities.h"

#include <vector>
#include <cmath>

using namespace std;

// Sort the bunch in ascending z (ct) order, and return
// a vector of iterators which point to the equal-spaced
// bin boundaries defines by zmin to zmax in steps of dz
//
// Returns the number of particles removed from tails
// i.e. z<zmin || z>=zmax
//
size_t ParticleBinList(ParticleBunch& bunch, double zmin, double zmax, double dz, 
					   vector<ParticleBunch::iterator>& pbins,
					   vector<double>& hd)
{
	size_t nbins=ceil((zmax-zmin)/dz);
	vector<ParticleBunch::iterator> bins;
	vector<double> hbins(nbins,0);
	bins.reserve(nbins+1);

	bunch.SortByCT();

	ParticleBunch::iterator p = bunch.begin();
	size_t lost=0;
	double z=zmin;

	// remove particles wth z<zmin
	while(p!=bunch.end() && p->ct()<zmin) {
		p=bunch.erase(p);
		lost++;
	}

	double total=0;
	for(size_t n=0; n<nbins; n++) {
		bins.push_back(p);
		z+=dz;
		while(p!=bunch.end() && p->ct()<z) {
			total++;
			hbins[n]++;
			p++;
		}
	}

	// remove remainder of bunch
	while(p!=bunch.end()) {
		p=bunch.erase(p);
		lost++;
	}

	// normalise distribution
	double a = 1/total/dz;
	for(n=0; n<nbins; n++)
		hbins[n]*=a;

	bins.push_back(p); // should be end()

	pbins.swap(bins);
	hd.swap(hbins);
	return lost;
}

// Return the distribution of particles for the coordinate u.
// The distribution is returned as a binned histogram, with
// bin boundaries defined by umin to umax in steps of du.
// If truncate is true, then particles outside the range (umin,umax)
// are removed from bunch. If normalise is true, the histogram
// values are scaled to give a probability distribution with the
// property Sum{h_i*du} = 1.
//
size_t ParticleBunchDistribution(ParticleBunch& bunch, PScoord u, 
								 double umin, double umax, double du, vector<double>& bins, 
								 bool normalise, bool truncate)
{
	size_t nb = (umax-umin)/du;
	bins = vector<double>(nb,0.0);
	size_t np0 = bunch.size();

	ParticleBunch::iterator p = bunch.begin();
	size_t lost=0;
	double total = 0;

	while(p!=bunch.end()) {
		double uval = (*p)[u];
		if((uval<umin)||(uval>umax)) {
			lost++;
			if(truncate) {
				p=bunch.erase(p);
				p--;
			}
		}
		else {
			size_t n = (uval-umin)/du;
			assert(n<nb);
			bins[n]++;
			total++;
		}
		p++;
	}
	if(normalise) {
		double factor = 1/total/du;
		for(size_t i=0; i<bins.size(); i++)
			bins[i] *= factor;
	}
	return lost;
}
/*
* Merlin C++ Class Library for Charged Particle Accelerator Simulations
* 
* Class library version 2.0 (2000)
* 
* file Merlin/BeamDynamics/SliceMPTracking/SliceMacroParticle.cpp
* last modified 10/01/03
*
* This file is derived from software bearing the following
* restrictions:
*
* MERLIN C++ class library for 
* Charge Particle Accelerator Simulations
*
* Copyright (c) 2003 by The Merlin Collaboration.  
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

#include "BeamDynamics/SMPTracking/SliceMacroParticle.h"
#include <algorithm> // for std::fill
#include <iostream>
#include <iomanip>

namespace SMPTracking {
	
	
	SliceMacroParticle::SliceMacroParticle(double q1)
		: PSmoments4D(),q(q1)
	{}

	SliceMacroParticle::SliceMacroParticle(const PSmoments& S, double z1, double dp1, double q1)
		: PSmoments4D(),q(q1)
	{
		for(int i=0; i<4; i++) {
			mean(i)=S[i];
			for(int j=0; j<=i; j++)
				sig(i,j) = S(i,j);
		}
		mean(ps_CT)=z1;
		mean(ps_DP)=dp1;
	}
	
	
	// IO routines use the following format:
	//      columns 1,3  : q[e] z[m] dp/p
	//      columns 4-7  : mean values for x x' y y' in [m] and [r]
	//      columns 8-11 : RMS values for  x x' y y' in [m] and [r]
	//      columns 12-17: correlations <xx'> <yx> <yx'> <y'x> <y'x'> <y'y>
	
#define WR_MP(v) os<<std::scientific<<std::setprecision(6)<<std::setw(15)<<(v);
#define RE_MP(v) {double x; is>>x; (v)=x;}
	
	void SliceMacroParticle::Write(std::ostream& os) const
	{
		PScoord i,j;
		
		WR_MP(q);
		WR_MP(ct());
		WR_MP(dp());
		for(i=0;i<4;i++)
			WR_MP(mean(i));
		for(i=0;i<4;i++)
			WR_MP(std(i));
		for(i=1;i<4;i++){
			for(j=0;j<i;j++) {
				WR_MP(sig(i,j));
			}
		}
		os<<'\n';
	}
	
	void SliceMacroParticle::Read(istream& is)
	{
		PScoord i,j;
		
		if(!is) {
			cout<<"bad stream state!"<<endl;
		}
		
		is>>q;
		is>>ct();
		is>>dp();
		
		for(i=0;i<4;i++) {
			double x;
			is>>x;
			mean(i)=x;
		}
		
		for(i=0;i<4;i++) {
			double x;
			is>>x;
			var(i)=x*x;
		}
		for(i=1;i<4;i++) {
			for(j=0;j<i;j++){
				double x;
				is>>x;
				sig(i,j)=x;
			}
		}
	}
	
};
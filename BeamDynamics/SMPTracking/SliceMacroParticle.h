/*
* Merlin C++ Class Library for Charged Particle Accelerator Simulations
* 
* Class library version 2.0 (2000)
* 
* file Merlin/BeamDynamics/SMPTracking/SliceMacroParticle.h
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

#ifndef _h_SliceMacroParticle
#define _h_SliceMacroParticle 1

#include "BeamModel/PStypes.h"
#include "EuclideanGeometry/Space2D.h"
#include <iostream>
#include <cmath>


namespace SMPTracking {
	
	typedef TPSMoments<2> PSmoments4D;
	
	class SliceMacroParticle : public PSmoments4D {
	public:
		
		explicit SliceMacroParticle(double q=0);
		SliceMacroParticle(const PSmoments& sigma, double ct, double dp, double q);
		
		// Macroparticle charge
		double Q() const { return q; }
		
		
		// weighted centroid values
		double GetChargeWeightedCentroid(PScoord i) const {
			return q*mean(i);
		}
		Point2D GetChargeWeightedCentroid(PScoord i, PScoord j) const { 
			return Point2D(q*mean(i),q*mean(j));
		}
		PSvector GetChargeWeightedCentroid() const {
			PSvector x(*this);
			x*=q;
			return x;
		}
		
		PSvector& GetCentroid() { return *this; }
		const PSvector& GetCentroid() const { return *this; }
		
		// IO methods
		void Read(std::istream&);
		void Write(std::ostream&) const;
		
		friend operator<(const SliceMacroParticle& p1, const SliceMacroParticle& p2) {
			return p1.ct()<p2.ct();
		}
		
	private:
		double q;
	};
	
	inline std::ostream& operator<<(std::ostream& os, const SliceMacroParticle& p)
	{
		p.Write(os); return os;
	}
	
	inline std::istream& operator>>(std::istream& is, SliceMacroParticle& p)
	{
		p.Read(is); return is;
	}
};

#endif
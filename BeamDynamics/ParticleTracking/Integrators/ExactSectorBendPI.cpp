//## begin module%3AE81A540122.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\Integrators\ExactSectorBendPI.cpp
 * last modified 26/04/01 15:10:31
 */
//## end module%3AE81A540122.cm

//## begin module%3AE81A540122.cp preserve=no
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
//## end module%3AE81A540122.cp

//## Module: ExactSectorBendPI%3AE81A540122; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Source file: D:\dev\Merlin\BeamDynamics\ParticleTracking\Integrators\ExactSectorBendPI.cpp

//## begin module%3AE81A540122.includes preserve=yes
#include <cmath>
#include "NumericalUtils/PhysicalConstants.h"
//## end module%3AE81A540122.includes

// ExactSectorBendPI
#include "BeamDynamics/ParticleTracking/Integrators/ExactSectorBendPI.h"
//## begin module%3AE81A540122.declarations preserve=no
//## end module%3AE81A540122.declarations

//## begin module%3AE81A540122.additionalDeclarations preserve=yes
namespace {

	using namespace std;
	using namespace PhysicalUnits;
	using namespace PhysicalConstants;

	// Functor which maps a sector bend exactly (no approximations)
	// Used by class ExactSectorBendPI.

	struct ExactSectorBend {

		double l;
		double rho;
		double sinTheta;
		double cosTheta;
		double pscale;
		double sinTheta2;
		double cosTheta2;
		double rho2;

		ExactSectorBend(double len, double h, double ps)
			: l(len),rho(1/h),sinTheta(sin(h*len)),cosTheta(cos(h*len)),pscale(ps)
		{
			rho2=rho*rho;
			sinTheta2=sinTheta*sinTheta;
			cosTheta2=cosTheta*cosTheta;
		}

		void operator()(PSvector& v) {
			double x = v.x();
			double phi=v.xp();
			double phi2=phi*phi;
			double d = pscale*(1+v.dp());
			double d2=d*d;
			
			double a = (x+rho*(1-d+0.5*d*phi2))*cosTheta+rho*(d*phi*sinTheta-1);
			double b = (cosTheta2*d2*pow(phi2-2.,2)*
				rho2)/4. + 
				cosTheta*d2*phi*phi2*rho2*sinTheta + 
				2*cosTheta*d*phi*rho*sinTheta*(rho - d*rho + x) - 
				sinTheta2*(rho2 - 2*d*rho2 + 
				d*phi2*rho2 - 
				d2*phi2*rho2 + 2*rho*x - 
				2*d*rho*x + d*phi2*rho*x + pow(x,2));

			x = a<0 ? a+sqrt(b) : a-sqrt(b);

			// angle
			double dxdz = (-2*cosTheta*d*phi*rho + 
				sinTheta*((2 - 2*d + d*phi2)*rho + 2*x))/
				(rho*(-2 + cosTheta*(2 - 2*d + d*phi2) + 
				2*d*phi*sinTheta) + 2*(-1 + cosTheta)*x);

			v.x()=x;
			v.xp()=dxdz;
			v.y()+=v.yp()*l;
			// TODO: v.ct() = ??
		}
	};

	struct MultipoleKick {
		const MultipoleField& field;
		double scale;

		MultipoleKick(const MultipoleField& f, double len, double P0, double q) 
			: field(f),scale(q*len*eV*SpeedOfLight/P0) {}

		void operator()(PSvector& v) {
			double x=v.x();
			double y=v.y();
			double dp=v.dp();
			Complex F = scale*field.GetField2D(x,y)*(1-dp);
			v.xp() += -F.real();
			v.yp() +=  F.imag();
		};
	};		

};
//## end module%3AE81A540122.additionalDeclarations


// Class ExactSectorBendPI 


//## Other Operations (implementation)
//## Operation: TrackStep%988274708
double ExactSectorBendPI::TrackStep (double ds)
{
  //## begin ExactSectorBendPI::TrackStep%988274708.body preserve=yes
	if(ds==0) 
		return GetRemainingLength();

	double h = Component().GetGeometry().GetCurvature();
	const SectorBend::PoleFaceInfo& pfi = Component().GetPoleFaceInfo();

	if(GetIntegratedLength()==0 && pfi.entrance!=0)
		ApplyPoleFaceRotation(h,*pfi.entrance);

	MultipoleField& field = Component().GetField();
	const double P0 = GetBunch().GetReferenceMomentum();
	const double q = GetBunch().GetChargeSign();
	const double Pref = Component().GetMatchedMomentum(q);
	
	int np = field.HighestMultipole();

	assert(Pref>0);
	
	const Complex b0 = field.GetCoefficient(0);

	// Unlike the SectorBendPI, we treat also treat a quadrupole component
	// as a thin lens kick.
	bool splitMagnet = b0.imag()!=0 || np>0;
	double len = splitMagnet ? ds/2.0 : ds; 

	ExactSectorBend bendTracker(len,h,P0/Pref);
	for_each(GetBunch().begin(),GetBunch().end(),bendTracker);

	// Now if we have split the magnet, we need to
	// apply the kick approximation, and then
	// re-apply the map M
	if(splitMagnet) {

		// First we set the real parts of the
		// dipole field to zero
		field.SetCoefficient(0,Complex(0,b0.imag()));

		// Apply the integrated kick, and then track
		// through the linear second half
		for_each(GetBunch().begin(),GetBunch().end(),MultipoleKick(field,ds,P0,q));
		for_each(GetBunch().begin(),GetBunch().end(),bendTracker);

		// Remember to set the dipole component back
		field.SetCoefficient(0,b0);
	}

	double Sr=IncrStep(ds);
	if(Sr==0 && pfi.exit!=0 )
		ApplyPoleFaceRotation(h,*pfi.exit);

	return Sr;
  //## end ExactSectorBendPI::TrackStep%988274708.body
}

//## begin module%3AE81A540122.epilog preserve=yes
//## end module%3AE81A540122.epilog

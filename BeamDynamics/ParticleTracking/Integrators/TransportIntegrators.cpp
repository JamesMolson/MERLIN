/*
* Merlin C++ Class Library for Charged Particle Accelerator Simulations
* 
* Class library version 2.0 (1999)
* 
* file Merlin\BeamDynamics\ParticleTracking\Integrators\TransportIntegrators.cpp
* last modified 11/12/01 15:32:02
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

#include "BeamDynamics/ParticleTracking/Integrators/TransportIntegrators.h"
#include "BasicTransport/BasicTransportMaps.h"
#include "BasicTransport/TransportMatrix.h"
#include "BasicTransport/MatrixMaps.h"
#include "NumericalUtils/PhysicalUnits.h"
#include "NumericalUtils/PhysicalConstants.h"

using namespace PhysicalConstants;
using namespace PhysicalUnits;

#define CHK_ZERO(s) if(s==0) return GetRemainingLength()

namespace {
	
	// tolerance for bend scaling
#define REL_ENGY_TOL 1.0-06

	struct MultipoleKick {
		const MultipoleField& field;
		Complex scale;
		
		MultipoleKick(const MultipoleField& f, double len, double P0, double q, double phi =0) 
			: field(f) 
		{
			scale = q*len*eV*SpeedOfLight/P0*Complex(cos(phi),sin(phi));
		}
		
		void operator()(PSvector& v) {
			double x=v.x();
			double y=v.y();
			double dp=v.dp();
			Complex F = scale*field.GetField2D(x,y)/(1+dp);
			v.xp() += -F.real();
			v.yp() +=  F.imag();
		};
	};		
	
	// Apply a map without dp/p scaling
	struct ApplyMap {
		RTMap* m;
		ApplyMap(RTMap* amap) : m(amap) {}
		void operator()(PSvector& p) {
			m->Apply(p);
		}
	};

	// Apply map with a dp/p scaling
	struct ApplyMap1 {
		RTMap* m;
		double Eratio;

		ApplyMap1(RTMap* amap, double Er) : m(amap), Eratio(Er) {}
		void operator()(PSvector& p) {
			double dp = p.dp();
			p.dp() = Eratio*(1+dp)-1;
			m->Apply(p);
			p.dp() = dp;
		}
	};


	struct ApplyDrift {
		const double s;
		ApplyDrift(double len) : s(len) {}
		void operator()(PSvector& p) {
			const double xp = p.xp();
			const double yp = p.yp();
			p.x()+=s*xp;
			p.y()+=s*yp;
			p.ct()-=s*(xp*xp+yp*yp)/2.0;
		}
	};
	
	// Functor ApplyRFdp (used for full acceleration)
	struct ApplyRFMap {

		double Vn,k,phi0,cosPhi0,d0;
		RTMap* m;
		bool fullacc;

		ApplyRFMap(double Vnorm, double f, double phase, RTMap* m1, bool full_acc)
			: Vn(Vnorm),k(twoPi*f/SpeedOfLight),phi0(phase),m(m1),fullacc(full_acc)
		{
			cosPhi0=cos(phi0);
			d0=1+Vn*cosPhi0;
		};

		void operator()(PSvector& p) const {
			m->Apply(p);
			if(fullacc)
				p.dp() = (p.dp()+Vn*(cos(phi0-k*p.ct())-cosPhi0))/d0;
			else
				p.dp() += Vn*cos(phi0-k*p.ct());
		}
	};


	inline void ApplyMapToBunch(ParticleBunch& bunch, RTMap* amap)
	{
		for_each(bunch.begin(),bunch.end(),ApplyMap(amap));
	}

	inline void ApplyMapToBunch(ParticleBunch& bunch, RTMap* amap, double Er)
	{
		for_each(bunch.begin(),bunch.end(),ApplyMap1(amap,Er));
	}

	inline void ApplyDriftToBunch(ParticleBunch& bunch, double len)
	{
		for_each(bunch.begin(),bunch.end(),ApplyDrift(len));
	}


	void RotateBunchAboutZ(ParticleBunch& bunch, double phi)
	{
		RMtrx M(2);
		TransportMatrix::Srot(phi,M.R);
		M.Apply(bunch.GetParticles());
	}

	inline bool operator==(const Complex& z, double x)
	{
		return z.imag()==0 && z.real()==x;
	}

	inline bool operator!=(const Complex& z, double x)
	{
		return !(z==x);
	}
};

namespace TRANSPORT {
	
	double DriftPI::TrackStep (double ds)
	{
		CHK_ZERO(ds);
		RTMap* m = DriftTM(ds);
		ApplyMapToBunch(GetBunch(),m);
		delete m;
		return IncrStep(ds);
	}
	
	
	double SectorBendPI::TrackStep(double ds)
	{
		CHK_ZERO(ds);
		
		double h = Component().GetGeometry().GetCurvature();
		const SectorBend::PoleFaceInfo& pfi = Component().GetPoleFaceInfo();
		
		double tilt = Component().GetGeometry().GetTilt();
		
		if(tilt!=0)
			RotateBunchAboutZ(GetBunch(),tilt);
		
		
		MultipoleField& field = Component().GetField();
		const double P0 = GetBunch().GetReferenceMomentum();
		const double q = GetBunch().GetChargeSign();
		const double Pref = Component().GetMatchedMomentum(q);
		const double brho = P0/eV/SpeedOfLight;
		int np = field.HighestMultipole();

		
		assert(Pref>0);
		
		const Complex b0 = field.GetCoefficient(0);
		const Complex K1 = (np>0)? q*field.GetKn(1,brho) : Complex(0);
		
		// we need to split the magnet for a kick if the
		// following is true
		bool splitMagnet = b0.imag()!=0 || K1.imag()!=0 || np>1;
		double len = splitMagnet ? ds/2.0 : ds; 
		
		// Construct the second-order map
		RTMap* M = (abs(K1)==0) ? SectorBendTM(len,h) : GenSectorBendTM(len,h,K1.real(),0);

		if(GetIntegratedLength()==0)
			ApplyPoleFaceRotation(h,K1.real(),pfi.entrance);

		if(fequal(P0,Pref,REL_ENGY_TOL))
			ApplyMapToBunch(GetBunch(),M);
		else 
			ApplyMapToBunch(GetBunch(),M,P0/Pref);	
		
		// Now if we have split the magnet, we need to
		// apply the kick approximation, and then
		// re-apply the map M
		if(splitMagnet) {
			
			// First we set the real parts of the
			// dipole and quad fields to zero, since these
			// components have been modeled in the matrix
			Complex b1=field.GetCoefficient(1);
			field.SetCoefficient(0,Complex(0,b0.imag()));
			field.SetCoefficient(1,Complex(0,b1.imag()));
			
			// Apply the integrated kick, and then track
			// through the linear second half
			for_each(GetBunch().begin(),GetBunch().end(),MultipoleKick(field,ds,P0,q));

			if(fequal(P0,Pref,REL_ENGY_TOL))
				ApplyMapToBunch(GetBunch(),M);
			else
				ApplyMapToBunch(GetBunch(),M,P0/Pref);
			
			// Remember to set the components back
			field.SetCoefficient(0,b0);
			field.SetCoefficient(1,b1);
		}
		
		// must delete the map
		delete M;
		
		double Sr=IncrStep(ds);
		if(Sr==0)
			ApplyPoleFaceRotation(h,K1.real(),pfi.exit);
		
		if(tilt!=0)
			RotateBunchAboutZ(GetBunch(),-tilt);
		
		return Sr;
		//## end SectorBendPI::TrackStep%3729F8340065.body
	}
	
	//## Operation: ApplyPoleFaceRotation%37317D1A02D0
	void SectorBendPI::ApplyPoleFaceRotation (double h, double k, const SectorBend::PoleFace* pf)
	{
		//## begin SectorBendPI::ApplyPoleFaceRotation%37317D1A02D0.body preserve=yes
        #define _PFV(p,v) !(p) ? 0 : p->v;
		double beta = _PFV(pf,rot);
		double c = 0; // currently not implemented
		double hg = _PFV(pf,fint);
		double fint = _PFV(pf,fint);
		RTMap* M = PoleFaceTM(h,k,beta,c,fint,hg);
		ApplyMapToBunch(GetBunch(),M);
		delete M;
		//## end SectorBendPI::ApplyPoleFaceRotation%37317D1A02D0.body
	}
	
	
	double RectMultipolePI::TrackStep (double ds)
	{
		// Here we use a matrix to represent the quadrupole term, and a
		// single kick at the centre of the element for the other multipoles,
		// including any dipole term.
		using namespace TLAS;
		
		CHK_ZERO(ds);
		
		double P0 = GetBunch().GetReferenceMomentum();
		double q = GetBunch().GetChargeSign();
		double brho = P0/eV/SpeedOfLight;
		
		MultipoleField& field = Component().GetField();
		
		const Complex ch  = q*field.GetKn(0,brho);
		const Complex cK1 = q*field.GetKn(1,brho);
		const Complex cK2 = q*field.GetKn(2,brho);
		int np = field.HighestMultipole();

		// We split the magnet for a multipole kick if:
		//  - there is a dipole field
		//  - there is a quad field with higher-order multipoles
		//  - there is a sextupole    "     "     "        "

		bool splitMagnet = abs(ch)!=0 || (cK1!=Complex(0) && np>1) || np>2;
		double len = splitMagnet ? ds/2 : ds;
		
		
		if(cK1!=0.0) { // quad R+T matrix with thin-lens kicks for other multipoles
			double K1,phi;

			if(imag(cK1)==0) {
				K1 = real(cK1);
				phi=0;
			}
			else {
				K1 = abs(cK1);
				phi = arg(cK1)/2.0;
			}

			if(!fequal(phi,0))
				RotateBunchAboutZ(GetBunch(),-phi);
			
			RTMap* M = QuadrupoleTM(len,K1);
			ApplyMapToBunch(GetBunch(),M);
			if(splitMagnet) {
				Complex b1 = field.GetCoefficient(1);
				field.SetCoefficient(1,Complex(0));
				for_each(GetBunch().begin(),GetBunch().end(),MultipoleKick(field,ds,P0,q,phi));
				// Apply second half of map
				ApplyMapToBunch(GetBunch(),M);
				field.SetCoefficient(1,b1);
			}
			delete M;
			if(!fequal(phi,0))
				RotateBunchAboutZ(GetBunch(),phi);
		}
		else if(cK2!=0.0) { // sextupole R+T matrix with thin-lens kicks for other multipoles

			double K2,phi;
			if(imag(cK2)==0) {
				K2 = real(cK2);
				phi=0;
			}
			else {
				K2 = abs(cK2);
				phi = arg(cK2)/3.0;
			}

			if(!fequal(phi,0))
				RotateBunchAboutZ(GetBunch(),-phi);
			
			RTMap* M = SextupoleTM(len,K2);
			ApplyMapToBunch(GetBunch(),M);
			if(splitMagnet) {
				Complex b2 = field.GetCoefficient(2);
				field.SetCoefficient(2,Complex(0));
				for_each(GetBunch().begin(),GetBunch().end(),MultipoleKick(field,ds,P0,q,phi));
				// Apply second half of map
				ApplyMapToBunch(GetBunch(),M);
				field.SetCoefficient(2,b2);
			}
			delete M;
			if(!fequal(phi,0))
				RotateBunchAboutZ(GetBunch(),phi);
		}
		else { // drift with a kick in the middle
			ApplyDriftToBunch(GetBunch(),len);
			if(splitMagnet) {
				for_each(GetBunch().begin(),GetBunch().end(),MultipoleKick(field,ds,P0,q));
				// Apply second half of map
				ApplyDriftToBunch(GetBunch(),len);
			}
		}
		
		return IncrStep(ds);
	}


	double SWRFStructurePI::TrackStep(double ds)
	{
		
		// Here we have a problem since the Chamber's matrix that we use
		// for the transport is only valid for n*(lambda/2), where n is 
		// an integer. For now, we simple force ds to be a fixed number
		// of wavelengths
		
		CHK_ZERO(ds);
		
		const SWRFfield& field = Component().GetField();
		double g = field.GetAmplitude();
		double f = field.GetFrequency();
		double phi = field.GetPhase();
		double E0 = GetBunch().GetReferenceMomentum();
		
		double lambdaOver2 = SpeedOfLight/f/2;
		int ncells = static_cast<int>(ds/lambdaOver2);
		assert(ncells*lambdaOver2 == ds);
		
		RealMatrix R(2,2);
		TransportMatrix::SWRFCavity(ncells,g,f,phi,E0,R);
		RTMap* M = new RTMap();

		(*M)(3,3)=(*M)(1,1)=R(0,0);
		(*M)(3,4)=(*M)(1,2)=R(0,1);
		(*M)(4,3)=(*M)(2,1)=R(1,0);
		(*M)(4,4)=(*M)(2,2)=R(1,1);
		(*M)(5,5)=(*M)(6,6)=1.0;
				
		for_each(GetBunch().begin(),GetBunch().end(),ApplyRFMap(g*ds/E0,f,phi,M,useFullAcc));
		
		if(useFullAcc)
			GetBunch().IncrReferenceMomentum(g*ds*cos(phi));
		
		return IncrStep(ds);
	}

	
}; // end of namespace TRANSPORT


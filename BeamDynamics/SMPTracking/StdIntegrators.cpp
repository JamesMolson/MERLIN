/*
* Merlin C++ Class Library for Charged Particle Accelerator Simulations
* 
* Class library version 2.0 (1999)
* 
* file Merlin\BeamDynamics\SliceMPTracking\Integrators\StdIntegrators.cpp
* last modified 11/12/01 15:32:02
*
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

#include "BeamDynamics/SMPTracking/StdIntegrators.h"
#include "BasicTransport/RMap.h"
#include "BasicTransport/TransportRMap.h"
#include "IO/MerlinIO.h"
#include "NumericalUtils/PhysicalConstants.h"
#include "NumericalUtils/NumericalConstants.h"
#include "NumericalUtils/PhysicalUnits.h"

namespace SMPTracking {

	using namespace std;
	using PhysicalConstants::SpeedOfLight;
	using namespace PhysicalUnits;

	/////////////////////////////////////////////////////////////////////////////////
	// Support routines and function object classes
	/////////////////////////////////////////////////////////////////////////////////
	
	struct ThickLens {
		
		ThickLens(double l, const Complex& k0, double K) 
			: len(l),k1(K),theta_x(0),theta_y(0),hasDipoleKick(false)
		{
			if(k0!=Complex(0)) {
				theta_x = k0.real()*len;
				theta_y = -k0.imag()*len;
				len/=2.0;
				hasDipoleKick=true;
			}
		}


		void Apply(SliceMacroParticle& p) const
		{
			double ct=p.ct();
			double dp=p.dp();
			RMap M;
			TransportRMap::Quadrupole(len,k1/(1+dp),M);
			M.Apply(p);
			
			if(hasDipoleKick) {
				p[ps_XP]+=theta_x/(1+dp);
				p[ps_YP]+=theta_y/(1+dp);
				M.Apply(p);
			}
			p.ct()=ct;
			p.dp()=dp;
		}
		
		// attributes
		double len;
		double k1;
		double theta_x;
		double theta_y;
		bool hasDipoleKick;
	};

	struct ThinLensKick {
		ThinLensKick(const Complex& kk0, double kk1)
			: k0(kk0),k1(kk1) {}

		void Apply(SliceMacroParticle& p) const {
			const double dpp=1/(1+p.dp());
			p[ps_XP]+=dpp*k0.real();
			p[ps_YP]-=dpp*k0.imag();
			if(k1!=0) {
				double k=dpp*k1;
				RMap M;
				MakeIdentity(M);
				M.AddTerm(2,1)=k;
				M.AddTerm(4,3)=-k;
				M.Apply(p);
			};
		};

		Complex k0;
		double k1;
	};

	struct ApplySolenoid {

		ApplySolenoid(double z, double kk) 
			:ds(z),k(kk) {}

		void Apply(SliceMacroParticle& p) const {
			RMap M;
			TransportRMap::Solenoid(ds,k/(1+p.dp()),0,true,true,M);
			M.Apply(p);
		}

		double ds;
		double k;
	};

	struct ApplyTWRF {

		double k;
		double f;
		double g;
		double phi0;
		double ds;
		double E0;
		double E1;
		bool inc_entr_f;
		bool inc_exit_f;

		ApplyTWRF(double p0, double ds1, double g1, double f1, 
			double phi, bool entr_f, bool exit_f)
			: k(twoPi*f1/SpeedOfLight),f(f1),g(g1),ds(ds1),
			phi0(phi),E0(p0),E1(p0+g*ds*cos(phi)),inc_entr_f(entr_f),inc_exit_f(exit_f)
		{}

		void Apply(SliceMacroParticle& p) const {

			double ct = p.ct();
			double Ein = E0*(1+p.dp());
			double phi = phi0-k*ct;
			double Eout = Ein+g*ds*cos(phi);

			RMap M;
			TransportRMap::TWRFCavity(ds,g,f,phi,Ein,inc_entr_f,inc_exit_f,M);
			M.Apply(p);
			p.ct()=ct;
			p.dp()=Eout/E1-1.0;
		}
	};

	struct ApplyTWRFEdgeField {
		
		double k;
		double Ez;
		double phi0;
		
		ApplyTWRFEdgeField(double p0, double g, double f, double phi) 
			: Ez(g/p0),k(twoPi*f/SpeedOfLight),phi0(phi) {}
		
		void Apply(SliceMacroParticle& x) const {
			double a = -0.5*Ez*cos(phi0-k*x.ct())/(1+x.dp());
			RMap M;
			MakeIdentity(M);
			M.AddTerm(2,1)=a;
			M.AddTerm(4,3)=a;
			M.Apply(x);
		}
		
	};			

	void RotateBunchAboutZ(SMPBunch& b, double phi)
	{
		RMap M;
		TransportRMap::Srot(phi,M);
		ApplyMap(M,b);
	}
/*
	void ApplyDrift(double s, SMPBunch& bunch)
	{
		RMap M;
		TransportRMap::Drift(s,M);
		ApplyMap(M,bunch);
	}
*/
	void ApplyDrift(double s, SMPBunch& bunch)
	{
		ApplyMap(ApplySimpleDrift(s),bunch);
	}

	// Error and Warning messages
	void WarnNonlinear(const string& id)
	{
		MerlinIO::warning()<<"Non-linear field ignored in "<<id<<endl;
	}

	/////////////////////////////////////////////////////////////////////////////////
	// Integrator methods
	/////////////////////////////////////////////////////////////////////////////////

	void DriftCI::TrackStep(double ds)
	{
		if(ds!=0)
			ApplyDrift(ds,*currentBunch);
		return;
	}

	void SectorBendCI::TrackStep(double ds)
	{
		if(ds==0) return;

		double h = (currentComponent->GetGeometry()).GetCurvature();
		double tilt = (currentComponent->GetGeometry()).GetTilt();

		if(tilt!=0)
			RotateBunchAboutZ(*currentBunch,tilt);

		MultipoleField& field = currentComponent->GetField();
		const double P0 = currentBunch->GetReferenceMomentum();
		const double q = currentBunch->GetChargeSign();
		const double Pref = currentComponent->GetMatchedMomentum(q);
		const double brho = P0/eV/SpeedOfLight;
		int np=field.HighestMultipole();
		
		if(np>1)
			WarnNonlinear(currentComponent->GetQualifiedName());

		assert(Pref>0);
	
		const Complex K1 = (np>0)? q*field.GetKn(1,brho) : Complex(0);

		RMap M;
		TransportRMap::SectorBend(ds,h,K1.real(),M);
		if(!fequal(Pref,P0,1.0e-6))
			ApplyMap(M,*currentBunch,P0,Pref);
		else
			ApplyMap(M,*currentBunch);
	
		if(tilt!=0)
			RotateBunchAboutZ(*currentBunch,-tilt);

		return;	
	}

	void SectorBendCI::TrackEntrance()
	{
		const SectorBend::PoleFaceInfo& pfi = currentComponent->GetPoleFaceInfo();
		if(pfi.entrance!=0) {
			double h = (currentComponent->GetGeometry()).GetCurvature();
			ApplyPoleFaceRotation(h,*pfi.entrance);
		}
	}

	void SectorBendCI::TrackExit()
	{
		const SectorBend::PoleFaceInfo& pfi = currentComponent->GetPoleFaceInfo();
		if(pfi.exit!=0) {
			double h = (currentComponent->GetGeometry()).GetCurvature();
			ApplyPoleFaceRotation(h,*pfi.exit);
		}
	}

	void SectorBendCI::ApplyPoleFaceRotation(double h, const SectorBend::PoleFace& pf)
	{
		RMap M;
		TransportRMap::PoleFaceRot(h,pf.rot,pf.fint,pf.hgap,M);
		ApplyMap(M,*currentBunch);	
	}

	void RectMultipoleCI::TrackStep(double ds)
	{
		MultipoleField& field = currentComponent->GetField();

		if(field.IsNullField()) {
			ApplyDrift(ds,*currentBunch);
			return;
		}

		const double P0 = currentBunch->GetReferenceMomentum();
		const double q = currentBunch->GetChargeSign();
		const double brho = P0/eV/SpeedOfLight;

		if(field.HighestMultipole()>1) {
			WarnNonlinear(currentComponent->GetQualifiedName());
			ApplyDrift(ds,*currentBunch);
		}

		// We allow a quadrupole with a thin dipole kick at its centre
		Complex cK0 = q*field.GetKn(0,brho);
		Complex cK1 = q*field.GetKn(1,brho);

		double K1;
		double phi;

		if(cK1.imag()==0) {
			K1= cK1.real();
			phi=0;
		}
		else {
			K1=abs(cK1);
			phi=arg(cK1)/2.0;
		}

		double tilt = /*Component().GetGeometry().GetTilt()*/-phi;

		if(tilt!=0)
			RotateBunchAboutZ(*currentBunch,tilt);
		if(phi!=0)
			cK0 *= -cK1/abs(cK1); // rotate dipole kick back


		if(currentComponent->GetLength()==0 && ds==0 && !field.IsNullField())
			ApplyMap(ThinLensKick(cK0,K1),*currentBunch);
		else
			ApplyMap(ThickLens(ds,cK0,K1),*currentBunch);

		if(tilt!=0)
			RotateBunchAboutZ(*currentBunch,-tilt);

		return;
	}

	void SolenoidCI::TrackStep(double ds)
	{
		double P0 = currentBunch->GetReferenceMomentum();
		double q = currentBunch->GetChargeSign();
		double brho = P0/eV/SpeedOfLight;
		
		double Bz = currentComponent->GetBz();
		
		if(fequal(Bz,0))
			ApplyDrift(ds,*currentBunch);
		else 
			ApplyMap(ApplySolenoid(ds,q*Bz/brho),*currentBunch);
		return;
	}

	void MonitorCI::TrackStep(double ds)
	{
		double len = currentComponent->GetLength();
		if(len==0) {
			assert(ds==0);
			currentComponent->MakeMeasurement(*currentBunch);
		}
		else {
			double mpt=currentComponent->GetMeasurementPt()+len/2;
			if(GetIntegratedLength()+ds>mpt) {
				double s1=mpt-GetIntegratedLength();
				ApplyDrift(s1,*currentBunch);
				currentComponent->MakeMeasurement(*currentBunch);
				ds-=s1;
			}
			ApplyDrift(ds,*currentBunch);
		}
		return;

	}

	void TWRFStructureCI::TrackStep(double ds)
	{
		if(ds==0)
			return;
				
		const TWRFfield& field = currentComponent->GetField();
		
		double g   = field.GetAmplitude();
		double f   = field.GetFrequency();
		double phi = field.GetPhase();
		
		if(g==0)
			// cavity is off!
			ApplyDrift(ds,*currentBunch);
		else {
			double p0=currentBunch->GetReferenceMomentum();
			ApplyTWRF cavmap(p0,ds,g,f,phi,AtEntrance(),AtExit(ds));
			ApplyMap(cavmap,*currentBunch);
			currentBunch->SetReferenceMomentum(cavmap.E1);
		}
		return;
	}

	void TWRFStructureCI::ApplyEndField(double gsgn)
	{
		const TWRFfield& field = currentComponent->GetField();	
		double g   = gsgn*field.GetAmplitude();
		double f   = field.GetFrequency();
		double phi = field.GetPhase();
		double p0  = currentBunch->GetReferenceMomentum();
		if(g!=0)
			ApplyMap(ApplyTWRFEdgeField(p0,g,f,phi),*currentBunch);
	}

	void TWRFStructureCI::TrackEntrance()
	{
//		ApplyEndField(1.0);
	}

	void TWRFStructureCI::TrackExit()
	{
//		ApplyEndField(-1.0);
	}

	void SWRFStructureCI::TrackStep(double ds)
	{
		// TO DO
		cout<<"SWRFStructure currently not supported"<<endl;
		ApplyDrift(ds,*currentBunch);
		return;
	}
};
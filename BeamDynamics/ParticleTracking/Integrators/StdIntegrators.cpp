//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3AE02F8B005A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\Integrators\StdIntegrators.cpp
 * last modified 11/12/01 15:32:03
 */
//## end module%3AE02F8B005A.cm

//## begin module%3AE02F8B005A.cp preserve=no
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
//## end module%3AE02F8B005A.cp

//## Module: StdIntegrators%3AE02F8B005A; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\Integrators\StdIntegrators.cpp

//## begin module%3AE02F8B005A.includes preserve=yes
#include <limits>
#include "NumericalUtils/PhysicalConstants.h"
#include "NumericalUtils/MatrixPrinter.h"
//## end module%3AE02F8B005A.includes

// TransportMatrix
#include "BasicTransport/TransportMatrix.h"
// StdIntegrators
#include "BeamDynamics/ParticleTracking/Integrators/StdIntegrators.h"
//## begin module%3AE02F8B005A.additionalDeclarations preserve=yes
using namespace std;
using namespace PhysicalConstants;
using namespace PhysicalUnits;

#define CHK_ZERO(s) if(s==0) return GetRemainingLength()

#undef USE_SBEND_T

namespace {

	// Functor which applies a drift
	struct psdrift {
		double z;
		psdrift(double len):z(len){}
		void operator()(PSvector& p) {
			p.x() += p.xp()*z;
			p.y() += p.yp()*z;
		}
	};
	
	inline void ApplyDrift(PSvectorArray& psv,double z)
	{
		if(z!=0)
			for_each(psv.begin(),psv.end(),psdrift(z));
	}

	struct MultipoleKick {
		const MultipoleField& field;
		double scale;

		MultipoleKick(const MultipoleField& f, double len, double P0, double q) 
			: field(f),scale(q*len*eV*SpeedOfLight/P0) {}

		void operator()(PSvector& v) {
			double x=v.x();
			double y=v.y();
			double dp=v.dp();
			Complex F = scale*field.GetField2D(x,y)/(1+dp);
			v.xp() += -F.real();
			v.yp() +=  F.imag();
		};
	};		


	// Functor ApplyRFdp (used for full acceleration)
	struct ApplyRFdp {

		double Vn,k,phi0,cosPhi0,d0;
		const RMtrx& R;
		bool fullacc;

		ApplyRFdp(double Vnorm, double f, double phase, const RMtrx& R1, bool full_acc)
			: Vn(Vnorm),k(twoPi*f/SpeedOfLight),phi0(phase),R(R1),fullacc(full_acc)
		{
			cosPhi0=cos(phi0);
			d0=1+Vn*cosPhi0;
		};

		void operator()(PSvector& p) const {
			R.Apply(p);
			if(fullacc)
				p.dp() = (p.dp()+Vn*(cos(phi0-k*p.ct())-cosPhi0))/d0;
			else
				p.dp() += Vn*cos(phi0-k*p.ct());
		}
	};

	// Functor to add second-order path length terms (T566)
	// to sector bend tracking.

	class SecondOrderPathLength {
	public:
		SecondOrderPathLength(double l, double h, double ps)
			: t566(0),pScale(ps)
		{
			double phi = h*l;
			t566 = (1-phi-cos(phi)+sin(phi))/h/3.0;
		}
		
		void operator()(PSvector& p) const {
			const double dp = pScale*(1+p.dp())-1.0;
			p.ct() += t566*dp*dp;
		}

	private:
		double t566,pScale;
	};
};
//## end module%3AE02F8B005A.additionalDeclarations


// Class DriftPI 


//## Other Operations (implementation)
//## Operation: TrackStep%3729F7BF00DD
double DriftPI::TrackStep (double ds)
{
  //## begin DriftPI::TrackStep%3729F7BF00DD.body preserve=yes
	CHK_ZERO(ds);
	ApplyDrift(GetBunch().GetParticles(),ds);
	return IncrStep(ds);
  //## end DriftPI::TrackStep%3729F7BF00DD.body
}

// Class TWRFStructurePI 


//## Other Operations (implementation)
//## Operation: TrackStep%3729F7F800E7
double TWRFStructurePI::TrackStep (double ds)
{
  //## begin TWRFStructurePI::TrackStep%3729F7F800E7.body preserve=yes
	CHK_ZERO(ds);

	// Note that for particle tracking we use a higher order
	// approximation for the momentum error, and a linear matrix
	// for the transverse planes.

	const TWRFfield& field = Component().GetField();

	double g   = field.GetAmplitude();
	double f   = field.GetFrequency();
	double phi = field.GetPhase();

	if(g==0) {
		// cavity is off!
		ApplyDrift(GetBunch().GetParticles(),ds);
		return IncrStep(ds);
	}

	assert(f!=0);

	RMtrx Rm(2);
	double E0  = GetBunch().GetReferenceMomentum();

	TransportMatrix::TWRFCavity(ds,g,f,phi,E0,Rm.R);

	for_each(GetBunch().begin(),GetBunch().end(),ApplyRFdp(g*ds/E0,f,phi,Rm,useFullAcc));
	
	if(useFullAcc)
		GetBunch().IncrReferenceMomentum(g*ds*cos(phi));

	return IncrStep(ds);
  //## end TWRFStructurePI::TrackStep%3729F7F800E7.body
}

// Class SectorBendPI 


//## Other Operations (implementation)
//## Operation: TrackStep%3729F8340065
double SectorBendPI::TrackStep (double ds)
{
  //## begin SectorBendPI::TrackStep%3729F8340065.body preserve=yes
    CHK_ZERO(ds);

	double h = Component().GetGeometry().GetCurvature();
	const SectorBend::PoleFaceInfo& pfi = Component().GetPoleFaceInfo();

	double tilt = Component().GetGeometry().GetTilt();

	if(tilt!=0) {
		RMtrx Rr;
		TransportMatrix::Srot(tilt,Rr.R);
		Rr.Apply(GetBunch().GetParticles());
	}

	if(GetIntegratedLength()==0 && pfi.entrance!=0)
		ApplyPoleFaceRotation(h,*pfi.entrance);

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

#ifdef USE_SBEND_T
	RdpMtrx M(3,Pref);
	TransportMatrix::SectorBend(len,h,K1.real(),M.R);
	TransportMatrix::SectorBendT(len,h,K1.real(),M.T);
#else
	RMtrx M(3,Pref);
	TransportMatrix::SectorBend(len,h,K1.real(),M.R);
#endif

	M.Apply(GetBunch().GetParticles(),P0);
	for_each(GetBunch().begin(),GetBunch().end(),SecondOrderPathLength(len,h,P0/Pref));

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
		M.Apply(GetBunch().GetParticles(),P0);
		for_each(GetBunch().begin(),GetBunch().end(),SecondOrderPathLength(len,h,P0/Pref));

		// Remember to set the components back
		field.SetCoefficient(0,b0);
		field.SetCoefficient(1,b1);
	}

	double Sr=IncrStep(ds);
	if(Sr==0 && pfi.exit!=0 )
		ApplyPoleFaceRotation(h,*pfi.exit);

	if(tilt!=0) {
		RMtrx Rr;
		TransportMatrix::Srot(-tilt,Rr.R);
		Rr.Apply(GetBunch().GetParticles());
	}

	return Sr;
  //## end SectorBendPI::TrackStep%3729F8340065.body
}

//## Operation: ApplyPoleFaceRotation%37317D1A02D0
void SectorBendPI::ApplyPoleFaceRotation (double h, const SectorBend::PoleFace& pf)
{
  //## begin SectorBendPI::ApplyPoleFaceRotation%37317D1A02D0.body preserve=yes
	RMtrx M(2);
	TransportMatrix::PoleFaceRot(h,pf.rot,pf.fint,pf.hgap,M.R);
	M.Apply(GetBunch().GetParticles());
  //## end SectorBendPI::ApplyPoleFaceRotation%37317D1A02D0.body
}

// Class RectMultipolePI 


//## Other Operations (implementation)
//## Operation: TrackStep%3729F82701CD
double RectMultipolePI::TrackStep (double ds)
{
  //## begin RectMultipolePI::TrackStep%3729F82701CD.body preserve=yes
	// Here we use a matrix to represent the quadrupole term, and a
	// single kick at the centre of the element for the other multipoles,
	// including any dipole term.
	using namespace TLAS;

	CHK_ZERO(ds);

	double P0 = GetBunch().GetReferenceMomentum();
	double q = GetBunch().GetChargeSign();
	double brho = P0/eV/SpeedOfLight;

	MultipoleField& field = Component().GetField();

	const Complex cK1 = q*field.GetKn(1,brho);
#ifndef NDEBUG
	bool splitMagnet;
	{
		Complex b0 = field.GetComponent(0);
		splitMagnet = b0!=0.0 || field.HighestMultipole()>1;
	}
#else
	bool splitMagnet = field.GetCoefficient(0)!=0.0 || field.HighestMultipole()>1;
#endif
	double len = splitMagnet ? ds/2 : ds;

	RdpMtrx M(2);

	if(cK1!=0.0) {
		double K1 = cK1.imag()==0 ? cK1.real() : abs(cK1);
		TransportMatrix::QuadrupoleR(len,K1,M.R);
		TransportMatrix::QuadrupoleT(len,K1,M.T);

		if(cK1.imag()!=0) {
			// Need to rotate the map
			double a = arg(cK1)/2;
			RealMatrix Rr(4,4);
			TransportMatrix::Srot(a,Rr);
			M.R = Rr*M.R*Transpose(Rr);
			M.T = Rr*M.T*Transpose(Rr);
		}

		M.Apply(GetBunch().GetParticles());
	}
	else 
		ApplyDrift(GetBunch().GetParticles(),len);

	if(splitMagnet) {
		Complex b1 = field.GetCoefficient(1);
		field.SetCoefficient(1,Complex(0));
		for_each(GetBunch().begin(),GetBunch().end(),MultipoleKick(field,ds,P0,q));
		if(b1!=0.0) 
			M.Apply(GetBunch().GetParticles());
		else
			ApplyDrift(GetBunch().GetParticles(),len);
		field.SetCoefficient(1,b1);
	}


	return IncrStep(ds);
  //## end RectMultipolePI::TrackStep%3729F82701CD.body
}

// Class MonitorPI 


//## Other Operations (implementation)
//## Operation: TrackStep%3729F84603DF
double MonitorPI::TrackStep (double ds)
{
  //## begin MonitorPI::TrackStep%3729F84603DF.body preserve=yes
	double len = Component().GetLength();
	if(len==0) {
		assert(ds==0);
		Component().MakeMeasurement(GetBunch());
	}
	else {
		double mpt=Component().GetMeasurementPt()+len/2;
		if(GetIntegratedLength()+ds>mpt) {
			double s1=mpt-GetIntegratedLength();
			ApplyDrift(GetBunch().GetParticles(),s1);
			IncrStep(s1); // need to increment bunch timing
			Component().MakeMeasurement(GetBunch());
			ds-=s1;
		}
		ApplyDrift(GetBunch().GetParticles(),ds);
	}
	return IncrStep(ds);
  //## end MonitorPI::TrackStep%3729F84603DF.body
}

// Class SWRFStructurePI 


//## Other Operations (implementation)
//## Operation: TrackStep%37318E3B02BC
double SWRFStructurePI::TrackStep (double ds)
{
  //## begin SWRFStructurePI::TrackStep%37318E3B02BC.body preserve=yes
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

	RMtrx Rm(2);
	TransportMatrix::SWRFCavity(ncells,g,f,phi,E0,Rm.R);


	for_each(GetBunch().begin(),GetBunch().end(),ApplyRFdp(g*ds/E0,f,phi,Rm,useFullAcc));
	
	if(useFullAcc)
		GetBunch().IncrReferenceMomentum(g*ds*cos(phi));
	
	return IncrStep(ds);
  //## end SWRFStructurePI::TrackStep%37318E3B02BC.body
}

// Class ExactRectMultipolePI 


//## Other Operations (implementation)
//## Operation: TrackStep%3969B9120285
double ExactRectMultipolePI::TrackStep (double ds)
{
  //## begin ExactRectMultipolePI::TrackStep%3969B9120285.body preserve=yes
	// Here we use a matrix to represent the quadrupole term, and a
	// single kick at the centre of the element for the other multipoles,
	// including any dipole term.
	using namespace TLAS;

	CHK_ZERO(ds);

	double P0 = GetBunch().GetReferenceMomentum();
	double q = GetBunch().GetChargeSign();
	double brho = P0/eV/SpeedOfLight;

	MultipoleField& field = Component().GetField();

	const Complex cK1 = q*field.GetKn(1,brho);

	bool splitMagnet = field.GetCoefficient(0)!=0.0 || field.HighestMultipole()>1;
	double len = splitMagnet ? ds/2 : ds;

	if(cK1!=0.0) {
		double K1 = cK1.imag()==0 ? cK1.real() : abs(cK1);	
		// Now we iterate over all the particles in the bunch,
		// and calculate the exact map for each
		for(PSvectorArray::iterator p = GetBunch().begin(); p!=GetBunch().end(); p++) {
			RMtrx M(2);
			TransportMatrix::QuadrupoleR(len,K1/(1+p->dp()),M.R);			
			if(cK1.imag()!=0) {
				// Need to rotate the map
				double a = arg(cK1);
				RealMatrix Rr(4,4);
				TransportMatrix::Srot(a,Rr);
				M.R = Rr*M.R*Transpose(Rr);
			}
			M.Apply(*p);
		}
	}
	else 
		ApplyDrift(GetBunch().GetParticles(),len);


	if(splitMagnet) {

		Complex b1 = field.GetCoefficient(1);
		field.SetCoefficient(1,Complex(0));
		for_each(GetBunch().begin(),GetBunch().end(),MultipoleKick(field,ds,P0,q));
		field.SetCoefficient(1,b1);
		
		// Now repeat linear tracking through second half
		if(cK1!=0.0) {
			double K1 = cK1.imag()==0 ? cK1.real() : abs(cK1);	
			for(PSvectorArray::iterator p = GetBunch().begin(); p!=GetBunch().end(); p++) {
				RMtrx M(2);
				TransportMatrix::QuadrupoleR(len,K1/(1+p->dp()),M.R);			
				if(cK1.imag()!=0) {
					// Need to rotate the map
					double a = arg(cK1);
					RealMatrix Rr(4,4);
					TransportMatrix::Srot(a,Rr);
					M.R = Rr*M.R*Transpose(Rr);
				}
				M.Apply(*p);
			}
		}
		else 
			ApplyDrift(GetBunch().GetParticles(),len);	
	}


	return IncrStep(ds);
  //## end ExactRectMultipolePI::TrackStep%3969B9120285.body
}

// Class SolenoidPI 


//## Other Operations (implementation)
//## Operation: TrackStep%3C16189C0173
double SolenoidPI::TrackStep (double ds)
{
  //## begin SolenoidPI::TrackStep%3C16189C0173.body preserve=yes
	CHK_ZERO(ds);
	double P0 = GetBunch().GetReferenceMomentum();
	double q = GetBunch().GetChargeSign();
	double brho = P0/eV/SpeedOfLight;

	double Bz = Component().GetBz();

	if(fequal(Bz,0))
		ApplyDrift(GetBunch().GetParticles(),ds);
	else {
		RMtrx M(2);
		TransportMatrix::Solenoid(ds,q*Bz/brho,0,true,true,M.R);
		M.Apply(GetBunch().GetParticles());
	}
	return IncrStep(ds);
  //## end SolenoidPI::TrackStep%3C16189C0173.body
}

//## begin module%3AE02F8B005A.epilog preserve=yes
//## end module%3AE02F8B005A.epilog

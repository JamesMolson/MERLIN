//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3992D0F201A8.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\LinearOptics\LinearMatrixTracker.cpp
 * last modified 08/29/00 04:26:39 PM
 */
//## end module%3992D0F201A8.cm

//## begin module%3992D0F201A8.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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
//## end module%3992D0F201A8.cp

//## Module: LinearMatrixTracker%3992D0F201A8; Package body
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Source file: C:\C++\Merlin\LinearOptics\LinearMatrixTracker.cpp

//## begin module%3992D0F201A8.includes preserve=yes
#include "NumericalUtils/utils.h"
//## end module%3992D0F201A8.includes

// Integrator
#include "AcceleratorModel/TrackingInterface/ComponentIntegrator.h"
// Components
#include "AcceleratorModel/Components.h"
// LinearAlgebra
#include "TLAS/LinearAlgebra.h"
// TransportMatrix
#include "BasicTransport/TransportMatrix.h"
// LinearMatrixTracker
#include "LinearOptics/LinearMatrixTracker.h"
// PhysicalConstants
#include "NumericalUtils/PhysicalConstants.h"
//## begin module%3992D0F201A8.additionalDeclarations preserve=yes
namespace {

	using namespace std;
	using namespace PhysicalConstants;
	using namespace PhysicalUnits;

	inline double sign_of(double x)
	{
		if(x<0)
			return -1;
		else if(x==0)
			return 0;
		else
			return 1;
	}

	void SBMatrix(double l, double h, double k1, RealMatrix& R1, RealMatrix& R2)
	{
		RealMatrix R(6,6);
		TransportMatrix::SectorBend(l,h,k1,R);
		R1=R*R1;
		R2=R*R2;
	}

	inline void ApplyDrift(double s, RealMatrix& R0)
	{
		RealVector r1 = R0.row(1);
		RealVector r3 = R0.row(3);
		r1*=s;
		r3*=s;

		R0.row(0) += r1;
		R0.row(2) += r3;
	}

	inline void ApplyDrift(double s, RealMatrix& R1, RealMatrix& R2)
	{
		ApplyDrift(s,R1);
		ApplyDrift(s,R2);
	}

}; // end of annonymous namespace

#define _CHECK_STEP(ds) if(fequal(ds,0)) return IncrStep(0);

//## end module%3992D0F201A8.additionalDeclarations


//## Class: RmtrxIntegrator%3992CBBF02BC
//	Base class for all linear R matrix integrators.
//## Category: Merlin::LinearOptics%3992C77E011C
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3993CC5102D6;PhysicalConstants { -> }

class RmtrxIntegrator : public ComponentIntegrator  //## Inherits: <unnamed>%3992CC0A0382
{
  public:

    //## Other Operations (specified)
      //## Operation: SetMomentum%3993C03700DD
      static void SetMomentum (double P0);

      //## Operation: GetMomentum%3993C05200A9
      static double GetMomentum ();

      //## Operation: SetChargeSign%3993C3DD034D
      static void SetChargeSign (double q);

      //## Operation: SetMatrices%3993C49B004D
      static void SetMatrices (RealMatrix& R1, RealMatrix& R2);

  protected:
    // Data Members for Class Attributes

      //## Attribute: brho%3992D4650125
      //## begin RmtrxIntegrator::brho%3992D4650125.attr preserve=no  protected: static double {UA} 
      static double brho;
      //## end RmtrxIntegrator::brho%3992D4650125.attr

      //## Attribute: p0%3993C08B00A1
      //## begin RmtrxIntegrator::p0%3993C08B00A1.attr preserve=no  protected: static double {UA} 
      static double p0;
      //## end RmtrxIntegrator::p0%3993C08B00A1.attr

    // Data Members for Associations

      //## Association: Merlin::LinearOptics::<unnamed>%3992CC290174
      //## Role: RmtrxIntegrator::R1%3992CC290319
      //## begin RmtrxIntegrator::R1%3992CC290319.role preserve=no  protected: static RealMatrix { -> 1RHAN}
      static RealMatrix* R1;
      //## end RmtrxIntegrator::R1%3992CC290319.role

      //## Association: Merlin::LinearOptics::<unnamed>%39ABC6B70251
      //## Role: RmtrxIntegrator::R2%39ABC6B800D5
      //## begin RmtrxIntegrator::R2%39ABC6B800D5.role preserve=no  protected: static RealMatrix { -> 1RHAN}
      static RealMatrix* R2;
      //## end RmtrxIntegrator::R2%39ABC6B800D5.role

  private:
    // Data Members for Class Attributes

      //## Attribute: qs%3993C4060157
      //## begin RmtrxIntegrator::qs%3993C4060157.attr preserve=no  private: static double {UA} 
      static double qs;
      //## end RmtrxIntegrator::qs%3993C4060157.attr

  private: //## implementation
};

//## Class: TRmtrxIntegrator%3992CB5A0018; Parameterized Class
//## Category: Merlin::LinearOptics%3992C77E011C
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class T>
class TRmtrxIntegrator : public RmtrxIntegrator  //## Inherits: <unnamed>%3992CBD50169
{
  public:

    //## Other Operations (specified)
      //## Operation: GetComponentIndex%3992CDF502CA
      //	Returns the component index for this integrator.
      virtual int GetComponentIndex () const;

      //## Operation: Component%3992CE0500D8
      T& Component ();

      //## Operation: Component%3992CE15035C
      const T& Component () const;

  protected:
  private:
  private: //## implementation
};

//## Class: RectMultipoleRmtrxI%3992C8590120
//## Category: Merlin::LinearOptics%3992C77E011C
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3993CBDD0225;TRmtrxIntegrator { -> }

class RectMultipoleRmtrxI : public TRmtrxIntegrator< RectMultipole  >  //## Inherits: <unnamed>%3992CD7F0180
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3992CFC103BC
      //	Tracks ds through the quadrupole component.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation
};

//## Class: SectorBendRmtrxI%3992C872022B
//## Category: Merlin::LinearOptics%3992C77E011C
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3993CBDE01D6;TRmtrxIntegrator { -> }

class SectorBendRmtrxI : public TRmtrxIntegrator< SectorBend  >  //## Inherits: <unnamed>%3992CD8902D9
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3992CFFD015F
      //	Tracks a single step ds through sector bend.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation

    //## Other Operations (specified)
      //## Operation: ApplyPoleFaceRotation%3993BE190083
      //	Used to apply a linear pole face rotation to the current
      //	bunch.
      void ApplyPoleFaceRotation (double h, const SectorBend::PoleFace& pf);

};

//## Class: SWRFStructureRmtrxI%3992C88A017B
//## Category: Merlin::LinearOptics%3992C77E011C
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3993CBE001E3;TRmtrxIntegrator { -> }

class SWRFStructureRmtrxI : public TRmtrxIntegrator< SWRFStructure  >  //## Inherits: <unnamed>%3992CD8C023D
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3992D00E0272
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation
};

//## Class: TWRFStructureRmtrxI%3992C89B0111
//## Category: Merlin::LinearOptics%3992C77E011C
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3993CBDF01CE;TRmtrxIntegrator { -> }

class TWRFStructureRmtrxI : public TRmtrxIntegrator< TWRFStructure  >  //## Inherits: <unnamed>%3992CD900198
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3992D019039A
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation
};

//## Class: DefaultRmtrxI%3992C91F03D8
//	The default AcceleratorComponent integrator treats
//	treats all components as drift spaces.
//## Category: Merlin::LinearOptics%3992C77E011C
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3993CBE10285;TRmtrxIntegrator { -> }

class DefaultRmtrxI : public TRmtrxIntegrator< AcceleratorComponent  >  //## Inherits: <unnamed>%3992CDAB0010
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3992D02A0055
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation
};

// Class RmtrxIntegrator 


//## Other Operations (inline)
//## Operation: SetMomentum%3993C03700DD
inline void RmtrxIntegrator::SetMomentum (double P0)
{
  //## begin RmtrxIntegrator::SetMomentum%3993C03700DD.body preserve=yes
	p0 = P0;
	brho = qs*P0/eV/SpeedOfLight;
  //## end RmtrxIntegrator::SetMomentum%3993C03700DD.body
}

//## Operation: GetMomentum%3993C05200A9
inline double RmtrxIntegrator::GetMomentum ()
{
  //## begin RmtrxIntegrator::GetMomentum%3993C05200A9.body preserve=yes
	return p0;
  //## end RmtrxIntegrator::GetMomentum%3993C05200A9.body
}

//## Operation: SetChargeSign%3993C3DD034D
inline void RmtrxIntegrator::SetChargeSign (double q)
{
  //## begin RmtrxIntegrator::SetChargeSign%3993C3DD034D.body preserve=yes
	qs=sign_of(q);
  //## end RmtrxIntegrator::SetChargeSign%3993C3DD034D.body
}

//## Operation: SetMatrices%3993C49B004D
inline void RmtrxIntegrator::SetMatrices (RealMatrix& R1, RealMatrix& R2)
{
  //## begin RmtrxIntegrator::SetMatrices%3993C49B004D.body preserve=yes
	RmtrxIntegrator::R1=&R1;
	RmtrxIntegrator::R2=&R2;
  //## end RmtrxIntegrator::SetMatrices%3993C49B004D.body
}

// Parameterized Class TRmtrxIntegrator 


//## Other Operations (inline)
//## Operation: GetComponentIndex%3992CDF502CA
template <class T>
inline int TRmtrxIntegrator<T>::GetComponentIndex () const
{
  //## begin TRmtrxIntegrator::GetComponentIndex%3992CDF502CA.body preserve=yes
	return T::ID;
  //## end TRmtrxIntegrator::GetComponentIndex%3992CDF502CA.body
}

//## Operation: Component%3992CE0500D8
template <class T>
inline T& TRmtrxIntegrator<T>::Component ()
{
  //## begin TRmtrxIntegrator::Component%3992CE0500D8.body preserve=yes
	return static_cast<T&>(GetCurrentComponent());
  //## end TRmtrxIntegrator::Component%3992CE0500D8.body
}

//## Operation: Component%3992CE15035C
template <class T>
inline const T& TRmtrxIntegrator<T>::Component () const
{
  //## begin TRmtrxIntegrator::Component%3992CE15035C.body preserve=yes
	return static_cast<const T&>(GetCurrentComponent());
  //## end TRmtrxIntegrator::Component%3992CE15035C.body
}

// Class RectMultipoleRmtrxI 

// Class SectorBendRmtrxI 

// Class SWRFStructureRmtrxI 

// Class TWRFStructureRmtrxI 

// Class DefaultRmtrxI 

// Class RmtrxIntegrator 

//## begin RmtrxIntegrator::brho%3992D4650125.attr preserve=no  protected: static double {UA} 
double RmtrxIntegrator::brho;
//## end RmtrxIntegrator::brho%3992D4650125.attr

//## begin RmtrxIntegrator::p0%3993C08B00A1.attr preserve=no  protected: static double {UA} 
double RmtrxIntegrator::p0;
//## end RmtrxIntegrator::p0%3993C08B00A1.attr

//## begin RmtrxIntegrator::qs%3993C4060157.attr preserve=no  private: static double {UA} 
double RmtrxIntegrator::qs;
//## end RmtrxIntegrator::qs%3993C4060157.attr

//## begin RmtrxIntegrator::R1%3992CC290319.role preserve=no  protected: static RealMatrix { -> 1RHAN}
RealMatrix* RmtrxIntegrator::R1;
//## end RmtrxIntegrator::R1%3992CC290319.role

//## begin RmtrxIntegrator::R2%39ABC6B800D5.role preserve=no  protected: static RealMatrix { -> 1RHAN}
RealMatrix* RmtrxIntegrator::R2;
//## end RmtrxIntegrator::R2%39ABC6B800D5.role

// Parameterized Class TRmtrxIntegrator 

// Class RectMultipoleRmtrxI 


//## Other Operations (implementation)
//## Operation: TrackStep%3992CFC103BC
double RectMultipoleRmtrxI::TrackStep (double ds)
{
  //## begin RectMultipoleRmtrxI::TrackStep%3992CFC103BC.body preserve=yes
	_CHECK_STEP(ds);
	const MultipoleField& field = Component().GetField();

	Complex ck1 = field.GetKn(1,brho);
	double k1 = ck1.imag()==0 ? ck1.real() : abs(ck1);
	double cosa,sina;

	if(fequal(k1,0)) {
		ApplyDrift(ds,*R1,*R2);
		return IncrStep(ds);
	}
	

	if(ck1.imag()!=0) {
		cosa = sqrt(0.5*(1+ck1.real()/k1));
		sina = ck1.imag()/k1/cosa/2;
		RealMatrix Rrot(IdentityMatrix(6));
		TransportMatrix::Srot(cosa,sina,Rrot);
		(*R1)=Rrot*(*R1);
		(*R2)=Rrot*(*R2);
	}

	SBMatrix(ds,0,k1,*R1,*R2);

	if(ck1.imag()!=0) {
		RealMatrix Rrot(IdentityMatrix(6));
		TransportMatrix::Srot(cosa,-sina,Rrot);
		(*R1)=Rrot*(*R1);
		(*R2)=Rrot*(*R2);
	}

	return IncrStep(ds);
  //## end RectMultipoleRmtrxI::TrackStep%3992CFC103BC.body
}

// Class SectorBendRmtrxI 


//## Other Operations (implementation)
//## Operation: TrackStep%3992CFFD015F
double SectorBendRmtrxI::TrackStep (double ds)
{
  //## begin SectorBendRmtrxI::TrackStep%3992CFFD015F.body preserve=yes
	_CHECK_STEP(ds);

	// Note that we assume that brho is matched to then bend geometry
	// here!!
	double h = Component().GetGeometry().GetCurvature();
	double k1 = Component().GetB1()/brho;
	double tilt = Component().GetGeometry().GetTilt();

	if(tilt!=0) {
		RealMatrix Rr(IdentityMatrix(6));
		TransportMatrix::Srot(tilt,Rr);
		(*R1)=Rr*(*R1);
		(*R2)=Rr*(*R2);
	}

	// check for non-zero pole face rotation
	const SectorBend::PoleFaceInfo& pfi = Component().GetPoleFaceInfo();
	if(GetIntegratedLength()==0 && pfi.entrance!=0)
		ApplyPoleFaceRotation(h,*pfi.entrance);

	SBMatrix(ds,h,k1,*R1,*R2);

	double Sr=IncrStep(ds);
	if(fequal(Sr,0) && pfi.exit!=0 )
		ApplyPoleFaceRotation(h,*pfi.exit);

	if(tilt!=0) {
		RealMatrix Rr(IdentityMatrix(6));
		TransportMatrix::Srot(-tilt,Rr);
		(*R1)=Rr*(*R1);
		(*R2)=Rr*(*R2);
	}

	return Sr;
  //## end SectorBendRmtrxI::TrackStep%3992CFFD015F.body
}

//## Operation: ApplyPoleFaceRotation%3993BE190083
void SectorBendRmtrxI::ApplyPoleFaceRotation (double h, const SectorBend::PoleFace& pf)
{
  //## begin SectorBendRmtrxI::ApplyPoleFaceRotation%3993BE190083.body preserve=yes
	RealMatrix R(IdentityMatrix(6));
	TransportMatrix::PoleFaceRot(h,pf.rot,pf.fint,pf.hgap,R);
	(*R1)=R*(*R1);
	(*R2)=R*(*R2);
  //## end SectorBendRmtrxI::ApplyPoleFaceRotation%3993BE190083.body
}

// Class SWRFStructureRmtrxI 


//## Other Operations (implementation)
//## Operation: TrackStep%3992D00E0272
double SWRFStructureRmtrxI::TrackStep (double ds)
{
  //## begin SWRFStructureRmtrxI::TrackStep%3992D00E0272.body preserve=yes
	_CHECK_STEP(ds);

	const RFAcceleratingField& field = Component().GetField();
	double E0 = field.GetAmplitude();
	double phi = field.GetPhase();
	double f = field.GetFrequency();

	if(E0==0) {
		ApplyDrift(ds,*R1,*R2);
		return IncrStep(ds);
	}
	
	double lambda = field.GetWavelength();
	int ncells = Round(2*ds/lambda);

	// We can only cope here with a integer number of cells
	assert(fequal(ds,ncells*lambda/2));

	RealMatrix R(6,6);
	TransportMatrix::SWRFCavity(ncells,E0,f,phi,p0,R);
	(*R1)=R*(*R1);
	(*R2)=R*(*R2);
	SetMomentum(p0+E0*ds*cos(phi));

	return IncrStep(ds);
  //## end SWRFStructureRmtrxI::TrackStep%3992D00E0272.body
}

// Class TWRFStructureRmtrxI 


//## Other Operations (implementation)
//## Operation: TrackStep%3992D019039A
double TWRFStructureRmtrxI::TrackStep (double ds)
{
  //## begin TWRFStructureRmtrxI::TrackStep%3992D019039A.body preserve=yes
	_CHECK_STEP(ds);

	const TWRFfield& field = Component().GetField();
	double g = field.GetAmplitude();
	double f = field.GetFrequency();
	double phi = field.GetPhase();

	if(fequal(g,0)) {
		ApplyDrift(ds,*R1,*R2);
		return IncrStep(ds);
	}

	RealMatrix R(6,6);
	TransportMatrix::TWRFCavity(ds,g,f,phi,p0,R);
	(*R1)=R*(*R1);
	(*R2)=R*(*R2);
	SetMomentum(p0+g*ds*cos(phi));

	return IncrStep(ds);
  //## end TWRFStructureRmtrxI::TrackStep%3992D019039A.body
}

// Class DefaultRmtrxI 


//## Other Operations (implementation)
//## Operation: TrackStep%3992D02A0055
double DefaultRmtrxI::TrackStep (double ds)
{
  //## begin DefaultRmtrxI::TrackStep%3992D02A0055.body preserve=yes
	_CHECK_STEP(ds);
	ApplyDrift(Component().GetLength(),*R1,*R2);
	return IncrStep(ds);
  //## end DefaultRmtrxI::TrackStep%3992D02A0055.body
}

// Class LinearMatrixTracker 



//## Operation: LinearMatrixTracker%3992CEEB03C8
LinearMatrixTracker::LinearMatrixTracker (double p0, double qsign, const RMtrx& R)
  //## begin LinearMatrixTracker::LinearMatrixTracker%3992CEEB03C8.initialization preserve=yes
  : R1(R),R2(R)
  //## end LinearMatrixTracker::LinearMatrixTracker%3992CEEB03C8.initialization
{
  //## begin LinearMatrixTracker::LinearMatrixTracker%3992CEEB03C8.body preserve=yes
	Register(new RectMultipoleRmtrxI());
	Register(new SectorBendRmtrxI());
	Register(new SWRFStructureRmtrxI());
	Register(new TWRFStructureRmtrxI());
	Register(new DefaultRmtrxI());

	RmtrxIntegrator::SetMatrices(R1.R,R2.R);
	RmtrxIntegrator::SetChargeSign(qsign);
	RmtrxIntegrator::SetMomentum(p0);
  //## end LinearMatrixTracker::LinearMatrixTracker%3992CEEB03C8.body
}



//## Other Operations (implementation)
//## Operation: ResetR2%39ABC63001E8
void LinearMatrixTracker::ResetR2 ()
{
  //## begin LinearMatrixTracker::ResetR2%39ABC63001E8.body preserve=yes
	R2.R=IdentityMatrix(6);
  //## end LinearMatrixTracker::ResetR2%39ABC63001E8.body
}

//## begin module%3992D0F201A8.epilog preserve=yes
//## end module%3992D0F201A8.epilog

//## begin module%36BDEB1E0136.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BasicTransport\MatrixMaps.h
 * last modified 04/04/01 14:41:33
 */
//## end module%36BDEB1E0136.cm

//## begin module%36BDEB1E0136.cp preserve=no
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
//## end module%36BDEB1E0136.cp

//## Module: MatrixMaps%36BDEB1E0136; Package specification
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Source file: D:\dev\Merlin\BasicTransport\MatrixMaps.h

#ifndef MatrixMaps_h
#define MatrixMaps_h 1

//## begin module%36BDEB1E0136.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%36BDEB1E0136.additionalIncludes

//## begin module%36BDEB1E0136.includes preserve=yes
#include <cassert>
//## end module%36BDEB1E0136.includes

// PSTypes
#include "BeamModel/PSTypes.h"
// LinearAlgebra
#include "TLAS/LinearAlgebra.h"


//## begin module%36BDEB1E0136.declarations preserve=no
//## end module%36BDEB1E0136.declarations

//## begin module%36BDEB1E0136.additionalDeclarations preserve=yes
//## end module%36BDEB1E0136.additionalDeclarations


//## Class: LinMtrxBase%36BDE6C9001E
//	Base class for linear matrix maps. LinMtrxMap is
//	intended only as a common base for class RMtrx and class
//	RdpMtrx. It cannot be instantiated.
//## Category: Merlin::BasicTransport%34797A9700F7; Global
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: 0

class LinMtrxBase 
{
  public:

    //## Other Operations (specified)
      //## Operation: GetNDF%918417790
      //	Return the number of degrees of freedom for this matrix
      //	(dimension/2).
      int GetNDF () const;

      //## Operation: GetRefMomentum%918417791
      //	Return the reference momentum in GeV/c (returns 0 if the
      //	map is energy independent).
      double GetRefMomentum () const;

      //## Operation: EnergyIndependent%924960084
      //	Returns true if this map is energy independent.
      bool EnergyIndependent () const;

    // Data Members for Associations

      //## Association: Merlin::BasicTransport::<unnamed>%36BDC31D0122
      //## Role: LinMtrxBase::R%36BDC31D0349
      //## begin LinMtrxBase::R%36BDC31D0349.role preserve=no  public: RealMatrix { -> 1VHAN}
      RealMatrix R;
      //## end LinMtrxBase::R%36BDC31D0349.role

  protected:
    //## Constructors (specified)
      //## Operation: LinMtrxBase%918417792
      LinMtrxBase (double P, int ndf);

      //## Operation: LinMtrxBase%924960085
      //	Construction directly from an arbitrary matrix.
      LinMtrxBase (const RealMatrix& RR, double P0);


    //## Other Operations (specified)
      //## Operation: scaledp%918417795
      //	Returns the momentum error re-scaled to the reference
      //	momentum.
      double scaledp (double P, double dp) const;

    // Data Members for Class Attributes

      //## Attribute: Pref%36BDE58902EE
      //## begin LinMtrxBase::Pref%36BDE58902EE.attr preserve=no  protected: double {UA} 
      double Pref;
      //## end LinMtrxBase::Pref%36BDE58902EE.attr

  private:
  private:  //## implementation
};

//## Class: RMtrx%36BDC2BE03D4
//	RMtrx represents a linear map which is implemented by a
//	matrix (R matrix). The map can act on single vectors or
//	first- and second-order moments, or arrays of the above.
//	The dimensionality of the map is specified in the number
//	of degrees of freedom (1,2 or 3).  In addition, RMtrx
//	objects are associated with a specific reference
//	momentum, about which the map (R) is calculated.
//	Functions are provided for mapping vectors or moments
//	whose reference momenta are different from the RMtrx
//	reference. RMtrx objects can be multiplied together and
//	inverted.
//## Category: Merlin::BasicTransport%34797A9700F7; Global
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: apply%36BDD68701EA;PSvector { -> F}
//## Uses: apply%36BDD68A0050;PSmoments { -> F}
//## Uses: <unnamed>%36BDDA420104;PSvectorArray { -> F}
//## Uses: <unnamed>%36BDDA440384;PSmomentsArray { -> F}

class RMtrx : public LinMtrxBase  //## Inherits: <unnamed>%36BDE6D901FE
{
  public:
    //## Constructors (specified)
      //## Operation: RMtrx%918417793
      //	Constructor taking the reference momentum and the number
      //	of degrees of freedom (ndf) for the matrix. The  matrix
      //	is dimensioned but not initialised.
      explicit RMtrx (int ndf = 3, double P = 0);

      //## Operation: RMtrx%924960086
      //	Construction from an aribrary matrix. The matrix should
      //	be square with dimension 2n, where n is 1,2 or 3.
      RMtrx (const RealMatrix& RR, double P0 = 0);


    //## Other Operations (specified)
      //## Operation: Apply%918417780
      //	Transforms the vector x by R such that x->R.x. The
      //	second form explicitly specifies the reference momentum
      //	(GeV/c) for the vector. Returns x.
      PSvector& Apply (PSvector& x) const;

      //## Operation: Apply%918417781
      PSvector& Apply (PSvector& x, double p0) const;

      //## Operation: Apply%918417782
      //	Transforms each vector in xa by R such that x->R.x. The
      //	second form explicitly specifies the reference momentum
      //	(GeV/c) for the vectors. Returns xa.
      PSvectorArray& Apply (PSvectorArray& xa) const;

      //## Operation: Apply%918417783
      PSvectorArray& Apply (PSvectorArray& xa, double p0) const;

      //## Operation: Apply%918417784
      //	Transform  sigma by R. If X,S represent the first- and
      //	second-order moments respectively, then X->R.X and
      //	S->R.S.R'. The second form explicitly specifies the
      //	reference momentum (GeV/c)  for the moments. Returns
      //	sigma.
      PSmoments& Apply (PSmoments& sigma) const;

      //## Operation: Apply%918417785
      PSmoments& Apply (PSmoments& sigma, double p0) const;

      //## Operation: Apply%918417786
      //	Transforms the moments in sigmaArray by R (see
      //	apply(PSmoments&) for details). The second form
      //	explicitly specifies the reference momentum (GeV/c) for
      //	the moments. Returns sigmaArray.
      PSmomentsArray& Apply (PSmomentsArray& sigmaArray) const;

      //## Operation: Apply%918417787
      PSmomentsArray& Apply (PSmomentsArray& sigmaArray, double p0) const;

      //## Operation: Invert%918417788
      //	Invert the matrix.
      RMtrx& Invert ();

      //## Operation: operator*=%918417789
      //	Dot operation. (*this)*=R represents (*this)->R.(*this).
      RMtrx& operator *= (const RMtrx& rhs);

	  double operator()(int i, int j) const { return R(i-1,j-1); }
  protected:
  private:
  private:  //## implementation
};

//## Class: RdpMtrx%36BDE159003C
//	An approximate linear map which contains a first-order
//	chromatic correction. The matrix used for tracking is
//	calculated as R0+R1*dp, where R0 is the matrix
//	calculated about the reference momentum, R1 is the first
//	order derivative wrt momentum and dp is the momentum
//	error. For more information see RMtrx.
//## Category: Merlin::BasicTransport%34797A9700F7; Global
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: apply%36BDE63B017C;PSvector { -> F}
//## Uses: apply%36BDE63E00B4;PSmoments { -> F}
//## Uses: <unnamed>%36BDE641024E;PSvectorArray { -> F}
//## Uses: <unnamed>%36BDE6440186;PSmomentsArray { -> F}

class RdpMtrx : public LinMtrxBase  //## Inherits: <unnamed>%36BDE6DC0280
{
  public:
    //## Constructors (specified)
      //## Operation: RdpMtrx%918417794
      //	Constructor taking the reference momentum and the number
      //	of degrees of freedom (ndf) for the matrix. The
      //	matrices are dimensioned but not initialised.
      explicit RdpMtrx (int ndf = 3, double P0 = 0);

      //## Operation: RdpMtrx%924960087
      //	Constructor from two arbitrary matrices. Both matrices
      //	should be square and of equal dimension, which should be
      //	2n where n=1,2, or 3.
      RdpMtrx (const RealMatrix& RR, const RealMatrix& TT, double P0 = 0);


    //## Other Operations (specified)
      //## Operation: Apply%918417772
      //	Transforms the vector x by R such that x->R.x. The
      //	second form explicitly specifies the reference momentum
      //	(GeV/c) for the vector. Returns x.
      PSvector& Apply (PSvector& x) const;

      //## Operation: Apply%918417773
      PSvector& Apply (PSvector& x, double p0) const;

      //## Operation: Apply%918417774
      //	Transforms each vector in xa by R such that x->R.x. The
      //	second form explicitly specifies the reference momentum
      //	(GeV/c) for the vectors. Returns xa.
      PSvectorArray& Apply (PSvectorArray& xa) const;

      //## Operation: Apply%918417775
      PSvectorArray& Apply (PSvectorArray& xa, double p0) const;

      //## Operation: Apply%918417776
      //	Transform  sigma by R. If X,S represent the first- and
      //	second-order moments respectively, then X->R.X and
      //	S->R.S.R'. The second form explicitly specifies the
      //	reference momentum (GeV/c)  for the moments. Returns
      //	sigma.
      PSmoments& Apply (PSmoments& sigma) const;

      //## Operation: Apply%918417777
      PSmoments& Apply (PSmoments& sigma, double p0) const;

      //## Operation: Apply%918417778
      //	Transforms the moments in sigmaArray by R (see
      //	apply(PSmoments&) for details). The second form
      //	explicitly specifies the reference momentum (GeV/c) for
      //	the moments. Returns sigmaArray.
      PSmomentsArray& Apply (PSmomentsArray& sigmaArray) const;

      //## Operation: Apply%918417779
      PSmomentsArray& Apply (PSmomentsArray& sigmaArray, double p0) const;

    // Data Members for Associations

      //## Association: Merlin::BasicTransport::<unnamed>%36BDE59B010E
      //## Role: RdpMtrx::T%36BDE59B0302
      //	Second-order momemtum derivative matrix (T matrix).
      //## begin RdpMtrx::T%36BDE59B0302.role preserve=no  public: RealMatrix { -> 1VHAN}
      RealMatrix T;
      //## end RdpMtrx::T%36BDE59B0302.role

  protected:
  private:
  private:  //## implementation
};

// Class LinMtrxBase 

//## Operation: LinMtrxBase%918417792
inline LinMtrxBase::LinMtrxBase (double P, int ndf)
  //## begin LinMtrxBase::LinMtrxBase%918417792.initialization preserve=yes
	: R(2*ndf,2*ndf),Pref(P)
  //## end LinMtrxBase::LinMtrxBase%918417792.initialization
{
  //## begin LinMtrxBase::LinMtrxBase%918417792.body preserve=yes
  //## end LinMtrxBase::LinMtrxBase%918417792.body
}



//## Other Operations (inline)
//## Operation: GetNDF%918417790
inline int LinMtrxBase::GetNDF () const
{
  //## begin LinMtrxBase::GetNDF%918417790.body preserve=yes
	  return R.nrows()/2;
  //## end LinMtrxBase::GetNDF%918417790.body
}

//## Operation: GetRefMomentum%918417791
inline double LinMtrxBase::GetRefMomentum () const
{
  //## begin LinMtrxBase::GetRefMomentum%918417791.body preserve=yes
	  return Pref;
  //## end LinMtrxBase::GetRefMomentum%918417791.body
}

//## Operation: EnergyIndependent%924960084
inline bool LinMtrxBase::EnergyIndependent () const
{
  //## begin LinMtrxBase::EnergyIndependent%924960084.body preserve=yes
	return Pref==0;
  //## end LinMtrxBase::EnergyIndependent%924960084.body
}

//## Operation: scaledp%918417795
inline double LinMtrxBase::scaledp (double P, double dp) const
{
  //## begin LinMtrxBase::scaledp%918417795.body preserve=yes
	  return P*(1+dp)/Pref-1.0;
  //## end LinMtrxBase::scaledp%918417795.body
}

// Class RMtrx 

//## Operation: RMtrx%918417793
inline RMtrx::RMtrx (int ndf, double P)
  //## begin RMtrx::RMtrx%918417793.initialization preserve=yes
	: LinMtrxBase(P,ndf)
  //## end RMtrx::RMtrx%918417793.initialization
{
  //## begin RMtrx::RMtrx%918417793.body preserve=yes
  //## end RMtrx::RMtrx%918417793.body
}

//## Operation: RMtrx%924960086
inline RMtrx::RMtrx (const RealMatrix& RR, double P0)
  //## begin RMtrx::RMtrx%924960086.initialization preserve=yes
  : LinMtrxBase(RR,P0)
  //## end RMtrx::RMtrx%924960086.initialization
{
  //## begin RMtrx::RMtrx%924960086.body preserve=yes
  //## end RMtrx::RMtrx%924960086.body
}


// Class RdpMtrx 

//## Operation: RdpMtrx%918417794
inline RdpMtrx::RdpMtrx (int ndf, double P0)
  //## begin RdpMtrx::RdpMtrx%918417794.initialization preserve=yes
	: LinMtrxBase(P0,ndf),T(2*ndf,2*ndf)
  //## end RdpMtrx::RdpMtrx%918417794.initialization
{
  //## begin RdpMtrx::RdpMtrx%918417794.body preserve=yes
  //## end RdpMtrx::RdpMtrx%918417794.body
}

//## Operation: RdpMtrx%924960087
inline RdpMtrx::RdpMtrx (const RealMatrix& RR, const RealMatrix& TT, double P0)
  //## begin RdpMtrx::RdpMtrx%924960087.initialization preserve=yes
  : LinMtrxBase(RR,P0),T(TT)
  //## end RdpMtrx::RdpMtrx%924960087.initialization
{
  //## begin RdpMtrx::RdpMtrx%924960087.body preserve=yes
	assert(TT.nrows()==RR.nrows() && TT.ncols()==RR.ncols());
  //## end RdpMtrx::RdpMtrx%924960087.body
}


//## begin module%36BDEB1E0136.epilog preserve=yes
//## end module%36BDEB1E0136.epilog


#endif

//## begin module%36BDEB2A0154.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BasicTransport\MatrixMaps.cpp
 * last modified 04/04/01 14:41:33
 */
//## end module%36BDEB2A0154.cm

//## begin module%36BDEB2A0154.cp preserve=no
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
//## end module%36BDEB2A0154.cp

//## Module: MatrixMaps%36BDEB2A0154; Package body
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Source file: D:\dev\Merlin\BasicTransport\MatrixMaps.cpp

//## begin module%36BDEB2A0154.includes preserve=yes
#include <cassert>
//## end module%36BDEB2A0154.includes

// PSTypes
#include "BeamModel/PSTypes.h"
// MatrixMaps
#include "BasicTransport/MatrixMaps.h"


//## begin module%36BDEB2A0154.declarations preserve=no
//## end module%36BDEB2A0154.declarations

//## begin module%36BDEB2A0154.additionalDeclarations preserve=yes
namespace {
	
	PSmoments& TransformMoments(PSmoments& S, const RealMatrix& R)
	{
		PSmoments result; // initialised to zero
		register int i,j,k,l;
		const int n=R.ncols();
		
		for(i=0; i<n; i++) {
			for(j=0; j<=i; j++) {
				double sij=0.0;
				for(k=0; k<n; k++) 
					for(l=0; l<n; l++)
						sij+=R(i,k)*R(j,l)*S(k,l);
					
					result(i,j)=sij;
			}
			for(j=0;j<n;j++)
				result[i]+=R(i,j)*S[j]; // centroid tracking
		}
		
//		for(i=0;i<n;i++)
//			for(j=0;j<=i;j++)
//				S(i,j)=result(i,j);
			
		return S=result;
	}
	
	void RescaleMoments(double P0, double P1, PSmoments& S)
	{
		// rescale the centroid
		double ratio = P0/P1;
		S[5]=ratio*(1+S[5])-1.0;
		
		// rescale momentum correlations
		for(int i=0; i<4; i++)
			S(i,5)*=ratio;
		
		// rescale energy spread
		S(5,5)*=(ratio*ratio);
	}
	
};
//## end module%36BDEB2A0154.additionalDeclarations


// Class RMtrx 


//## Other Operations (implementation)
//## Operation: Apply%918417780
PSvector& RMtrx::Apply (PSvector& x) const
{
  //## begin RMtrx::Apply%918417780.body preserve=yes
	PSvector x1(0);
	tblas2::tgemv(false,1.0,R,x,0.0,x1);
	for(Subscript i=0;i<R.nrows();i++) // only copy back that which changed
		x[i]=x1[i];
	return x;
  //## end RMtrx::Apply%918417780.body
}

//## Operation: Apply%918417781
PSvector& RMtrx::Apply (PSvector& x, double p0) const
{
  //## begin RMtrx::Apply%918417781.body preserve=yes
	if(EnergyIndependent())
		return Apply(x);
	
	double dp=x.dp();
	x.dp() = scaledp(p0,dp);
	Apply(x);
	x.dp()=dp;
	return x;
  //## end RMtrx::Apply%918417781.body
}

//## Operation: Apply%918417782
PSvectorArray& RMtrx::Apply (PSvectorArray& xa) const
{
  //## begin RMtrx::Apply%918417782.body preserve=yes
	for(PSvectorArray::iterator p=xa.begin(); p!=xa.end(); p++)
		Apply(*p);
	return xa;
  //## end RMtrx::Apply%918417782.body
}

//## Operation: Apply%918417783
PSvectorArray& RMtrx::Apply (PSvectorArray& xa, double p0) const
{
  //## begin RMtrx::Apply%918417783.body preserve=yes
	if(EnergyIndependent())
		return Apply(xa);
	
	for(PSvectorArray::iterator p=xa.begin(); p!=xa.end(); p++)
		Apply(*p,p0);
	return xa;
  //## end RMtrx::Apply%918417783.body
}

//## Operation: Apply%918417784
PSmoments& RMtrx::Apply (PSmoments& sigma) const
{
  //## begin RMtrx::Apply%918417784.body preserve=yes
	return TransformMoments(sigma,R);
  //## end RMtrx::Apply%918417784.body
}

//## Operation: Apply%918417785
PSmoments& RMtrx::Apply (PSmoments& sigma, double p0) const
{
  //## begin RMtrx::Apply%918417785.body preserve=yes
	if(EnergyIndependent())
		return Apply(sigma);

	RescaleMoments(p0,Pref,sigma);
	TransformMoments(sigma,R);
	RescaleMoments(Pref,p0,sigma);
	return sigma;
  //## end RMtrx::Apply%918417785.body
}

//## Operation: Apply%918417786
PSmomentsArray& RMtrx::Apply (PSmomentsArray& sigmaArray) const
{
  //## begin RMtrx::Apply%918417786.body preserve=yes
	for(PSmomentsArray::iterator p=sigmaArray.begin(); p!=sigmaArray.end(); p++)
		Apply(*p);
	return sigmaArray;
  //## end RMtrx::Apply%918417786.body
}

//## Operation: Apply%918417787
PSmomentsArray& RMtrx::Apply (PSmomentsArray& sigmaArray, double p0) const
{
  //## begin RMtrx::Apply%918417787.body preserve=yes
	if(EnergyIndependent())
		return Apply(sigmaArray);

	for(PSmomentsArray::iterator p=sigmaArray.begin(); p!=sigmaArray.end(); p++)
		Apply(*p,p0);
	return sigmaArray;
  //## end RMtrx::Apply%918417787.body
}

//## Operation: Invert%918417788
RMtrx& RMtrx::Invert ()
{
  //## begin RMtrx::Invert%918417788.body preserve=yes
	// TODO:
	assert(false);
	return *this;
  //## end RMtrx::Invert%918417788.body
}

//## Operation: operator*=%918417789
RMtrx& RMtrx::operator *= (const RMtrx& rhs)
{
  //## begin RMtrx::operator*=%918417789.body preserve=yes
	R = (rhs.R)*R;
	return *this;
  //## end RMtrx::operator*=%918417789.body
}

// Class RdpMtrx 



//## Other Operations (implementation)
//## Operation: Apply%918417772
PSvector& RdpMtrx::Apply (PSvector& x) const
{
  //## begin RdpMtrx::Apply%918417772.body preserve=yes
	PSvector x1(0.0);
	int n=R.nrows();
	register int i,j;
	
	for(i=0;i<n;i++) {
		x1[i]=0;
		for(j=0; j<n; j++)
			x1[i]+=(R(i,j)+T(i,j)*x.dp())*x[j];
	}
	for(i=0;i<n;i++)
		x[i]=x1[i];
	
	return x;
  //## end RdpMtrx::Apply%918417772.body
}

//## Operation: Apply%918417773
PSvector& RdpMtrx::Apply (PSvector& x, double p0) const
{
  //## begin RdpMtrx::Apply%918417773.body preserve=yes
	if(EnergyIndependent())
		return Apply(x);

	const double dp=x.dp();
	x.dp()=scaledp(p0,dp);
	Apply(x);
	x.dp()=dp;
	return x;
  //## end RdpMtrx::Apply%918417773.body
}

//## Operation: Apply%918417774
PSvectorArray& RdpMtrx::Apply (PSvectorArray& xa) const
{
  //## begin RdpMtrx::Apply%918417774.body preserve=yes
	for(PSvectorArray::iterator p=xa.begin(); p!=xa.end(); p++)
		Apply(*p);
	return xa;
  //## end RdpMtrx::Apply%918417774.body
}

//## Operation: Apply%918417775
PSvectorArray& RdpMtrx::Apply (PSvectorArray& xa, double p0) const
{
  //## begin RdpMtrx::Apply%918417775.body preserve=yes
	if(EnergyIndependent())
		return Apply(xa);

	for(PSvectorArray::iterator p=xa.begin(); p!=xa.end(); p++)
		Apply(*p,p0);
	return xa;
  //## end RdpMtrx::Apply%918417775.body
}

//## Operation: Apply%918417776
PSmoments& RdpMtrx::Apply (PSmoments& sigma) const
{
  //## begin RdpMtrx::Apply%918417776.body preserve=yes
	RealMatrix R1=R;
	R1+=T*sigma[5];
	return TransformMoments(sigma,R1);
  //## end RdpMtrx::Apply%918417776.body
}

//## Operation: Apply%918417777
PSmoments& RdpMtrx::Apply (PSmoments& sigma, double p0) const
{
  //## begin RdpMtrx::Apply%918417777.body preserve=yes
	if(EnergyIndependent())
		return Apply(sigma);

	RescaleMoments(p0,Pref,sigma);
	Apply(sigma);
	RescaleMoments(Pref,p0,sigma);
	return sigma;
  //## end RdpMtrx::Apply%918417777.body
}

//## Operation: Apply%918417778
PSmomentsArray& RdpMtrx::Apply (PSmomentsArray& sigmaArray) const
{
  //## begin RdpMtrx::Apply%918417778.body preserve=yes
	for(PSmomentsArray::iterator p=sigmaArray.begin(); p!=sigmaArray.end(); p++)
		Apply(*p);
	return sigmaArray;
  //## end RdpMtrx::Apply%918417778.body
}

//## Operation: Apply%918417779
PSmomentsArray& RdpMtrx::Apply (PSmomentsArray& sigmaArray, double p0) const
{
  //## begin RdpMtrx::Apply%918417779.body preserve=yes
	if(EnergyIndependent())
		return Apply(sigmaArray);

	for(PSmomentsArray::iterator p=sigmaArray.begin(); p!=sigmaArray.end(); p++)
		Apply(*p,p0);
	return sigmaArray;
  //## end RdpMtrx::Apply%918417779.body
}

// Class LinMtrxBase 



//## Operation: LinMtrxBase%924960085
LinMtrxBase::LinMtrxBase (const RealMatrix& RR, double P0)
  //## begin LinMtrxBase::LinMtrxBase%924960085.initialization preserve=yes
  : R(RR),Pref(P0)
  //## end LinMtrxBase::LinMtrxBase%924960085.initialization
{
  //## begin LinMtrxBase::LinMtrxBase%924960085.body preserve=yes
#ifndef NDEBUG
	int n=R.nrows()/2;
	assert((R.ncols()==2*n)&&(n==1||n==2||n==3));
#endif
  //## end LinMtrxBase::LinMtrxBase%924960085.body
}


//## begin module%36BDEB2A0154.epilog preserve=yes
//## end module%36BDEB2A0154.epilog

//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3981E4490352.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunch.cpp
 * last modified 03/12/01 16:41:27
 */
//## end module%3981E4490352.cm

//## begin module%3981E4490352.cp preserve=no
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
//## end module%3981E4490352.cp

//## Module: ParticleBunch%3981E4490352; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleBunch.cpp

//## begin module%3981E4490352.includes preserve=yes
#include <algorithm>
#include <fstream>
#include <list>
#include <iterator>
//## end module%3981E4490352.includes

// Transform3D
#include "EuclideanGeometry/Transform3D.h"
// PSvectorTransform3D
#include "BasicTransport/PSvectorTransform3D.h"
// ParticleBunch
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"


//## begin module%3981E4490352.additionalDeclarations preserve=yes
using namespace std;

namespace {

	template<class V>
	struct APSV1 {
		V& p;
		const double w;

		APSV1(V& p0, double n) : p(p0),w(1/n) {}
		void operator()(const PSvector& p1) {
			for(int i=0; i<6; i++) p[i]+=w*p1[i];
		}
	};

	struct APSV2 {
		const int u,v;
		Point2D X;
		const double w;

		APSV2(int i,int j,double n) : u(i),v(j),X(0,0),w(1/n){}
		void operator()(const PSvector& p) {
			X.x+=w*p[u];
			X.y+=w*p[v];
		}
	};

	struct PSVVAR1 {
		PSmoments& S;
		const double w;
		PSVVAR1(PSmoments& sig,double n):S(sig),w(1/n) {}
		void operator()(const PSvector& p) {
			for(int i=0; i<6; i++)
				for(int j=0; j<=i; j++)
					S(i,j)+=w*(p[i]-S[i])*(p[j]-S[j]);
		}
	};

	struct PSVVAR2 {
		PSmoments2D& S;
		const int u,v;
		const double w;

		PSVVAR2(int u1, int v1, double n, PSmoments2D& sig)
			:S(sig),u(u1),v(v1),w(1/n) {}

		void operator()(const PSvector& p) {
			double x=p[u]-S[0];
			double y=p[v]-S[1];
			S(0,0)+=w*x*x;
			S(0,1)+=w*x*y;
			S(1,1)+=w*y*y;
		}
	};

	template<class IT>
	double Mean(IT F, IT L,int i)
	{
		double s=0;
		double n=0;
		while(F!=L) {s+=(*F++)[i];n++;}
		return s/n;
	}

	inline bool operator>(const PSvector& p1, const PSvector& p2)
	{
		return p1.ct()>p2.ct();
	}
};
//## end module%3981E4490352.additionalDeclarations


// Class ParticleBunch 

//## Operation: ParticleBunch%3729CB29024E
ParticleBunch::ParticleBunch (double P0, double Q, PSvectorArray& particles)
  //## begin ParticleBunch::ParticleBunch%3729CB29024E.initialization preserve=yes
  : Bunch(P0,Q),qPerMP(Q/particles.size()),pArray()
  //## end ParticleBunch::ParticleBunch%3729CB29024E.initialization
{
  //## begin ParticleBunch::ParticleBunch%3729CB29024E.body preserve=yes
	pArray.swap(particles);
  //## end ParticleBunch::ParticleBunch%3729CB29024E.body
}

//## Operation: ParticleBunch%37C52E600015
ParticleBunch::ParticleBunch (double P0, double Q, std::istream& is)
  //## begin ParticleBunch::ParticleBunch%37C52E600015.initialization preserve=yes
  : Bunch(P0,Q)
  //## end ParticleBunch::ParticleBunch%37C52E600015.initialization
{
  //## begin ParticleBunch::ParticleBunch%37C52E600015.body preserve=yes
	PSvector p;
	while(is>>p)
		push_back(p);

	qPerMP = Q/size();
  //## end ParticleBunch::ParticleBunch%37C52E600015.body
}

//## Operation: ParticleBunch%3ADEFD450370
ParticleBunch::ParticleBunch (double P0, double Qm)
  //## begin ParticleBunch::ParticleBunch%3ADEFD450370.initialization preserve=yes
  : Bunch(P0,Qm),qPerMP(Qm)
  //## end ParticleBunch::ParticleBunch%3ADEFD450370.initialization
{
  //## begin ParticleBunch::ParticleBunch%3ADEFD450370.body preserve=yes
  //## end ParticleBunch::ParticleBunch%3ADEFD450370.body
}



//## Other Operations (implementation)
//## Operation: GetTotalCharge%3ADEEA5B0064
double ParticleBunch::GetTotalCharge () const
{
  //## begin ParticleBunch::GetTotalCharge%3ADEEA5B0064.body preserve=yes
	return qPerMP*size();
  //## end ParticleBunch::GetTotalCharge%3ADEEA5B0064.body
}

//## Operation: GetMoments%3729CB5000C8
PSmoments& ParticleBunch::GetMoments (PSmoments& sigma) const
{
  //## begin ParticleBunch::GetMoments%3729CB5000C8.body preserve=yes
	sigma.zero();
	for_each(begin(),end(),APSV1<PSmoments>(sigma,size()));	
	for_each(begin(),end(),PSVVAR1(sigma,size()));
	return sigma;
  //## end ParticleBunch::GetMoments%3729CB5000C8.body
}

//## Operation: GetProjectedMoments%3729CB500136
PSmoments2D& ParticleBunch::GetProjectedMoments (PScoord u, PScoord v, PSmoments2D& sigma) const
{
  //## begin ParticleBunch::GetProjectedMoments%3729CB500136.body preserve=yes
	sigma.zero();
	Point2D X = for_each(begin(),end(),APSV2(u,v,size())).X;
	sigma[0]=X.x;
	sigma[1]=X.y;
	for_each(begin(),end(),PSVVAR2(u,v,size(),sigma));
	return sigma;
  //## end ParticleBunch::GetProjectedMoments%3729CB500136.body
}

//## Operation: GetCentroid%3729CB500172
PSvector& ParticleBunch::GetCentroid (PSvector& p) const
{
  //## begin ParticleBunch::GetCentroid%3729CB500172.body preserve=yes
	p.zero();
	for_each(begin(),end(),APSV1<PSvector>(p,size()));
	return p;
  //## end ParticleBunch::GetCentroid%3729CB500172.body
}

std::pair<double,double> ParticleBunch::GetMoments(PScoord i) const
{
	double u = Mean(begin(),end(),i);
	double v=0;
	for(const_iterator p = begin(); p!=end(); p++) {
		double x = (*p)[i]-u;
		v+=x*x;
	}

	return make_pair(u,sqrt(v/size()));
}

//## Operation: GetProjectedCentroid%3729CB5001A4
Point2D ParticleBunch::GetProjectedCentroid (PScoord u, PScoord v) const
{
  //## begin ParticleBunch::GetProjectedCentroid%3729CB5001A4.body preserve=yes
	return for_each(begin(),end(),APSV2(u,v,size())).X;
  //## end ParticleBunch::GetProjectedCentroid%3729CB5001A4.body
}

//## Operation: AdjustRefMomentumToMean%3729CB500212
double ParticleBunch::AdjustRefMomentumToMean ()
{
  //## begin ParticleBunch::AdjustRefMomentumToMean%3729CB500212.body preserve=yes
	return AdjustRefMomentum( Mean(begin(),end(),ps_DP) );
  //## end ParticleBunch::AdjustRefMomentumToMean%3729CB500212.body
}

//## Operation: AdjustRefMomentum%3B94E5990346
double ParticleBunch::AdjustRefMomentum (double dpp)
{
  //## begin ParticleBunch::AdjustRefMomentum%3B94E5990346.body preserve=yes
	for(iterator p=begin(); p!=end(); p++){
		(*p).dp()-=dpp;
		(*p).dp()/=1+dpp;
	}
	double P0 = (1+dpp)*GetReferenceMomentum();
	SetReferenceMomentum(P0);
	return P0;
  //## end ParticleBunch::AdjustRefMomentum%3B94E5990346.body
}

//## Operation: AdjustRefTimeToMean%3729CB50024E
double ParticleBunch::AdjustRefTimeToMean ()
{
  //## begin ParticleBunch::AdjustRefTimeToMean%3729CB50024E.body preserve=yes
	double meanct = Mean(begin(),end(),ps_CT);
	for(iterator p=begin(); p!=end(); p++)
		(*p).ct()-=meanct;

	double CT = GetReferenceTime()-meanct;
	SetReferenceTime(CT);
	return CT;
  //## end ParticleBunch::AdjustRefTimeToMean%3729CB50024E.body
}

//## Operation: ProjectDistribution%3729CB5002BC
Histogram& ParticleBunch::ProjectDistribution (PScoord axis, Histogram& hist) const
{
  //## begin ParticleBunch::ProjectDistribution%3729CB5002BC.body preserve=yes
	// TODO:
	return hist;
  //## end ParticleBunch::ProjectDistribution%3729CB5002BC.body
}

//## Operation: ApplyTransformation%3729CB50032A
bool ParticleBunch::ApplyTransformation (const Transform3D& t)
{
  //## begin ParticleBunch::ApplyTransformation%3729CB50032A.body preserve=yes
	if(!t.isIdentity())
		PSvectorTransform3D(t).Apply(pArray);
	return true;
  //## end ParticleBunch::ApplyTransformation%3729CB50032A.body
}

//## Operation: SortByCT%3981E5C90154
void ParticleBunch::SortByCT ()
{
  //## begin ParticleBunch::SortByCT%3981E5C90154.body preserve=yes
	pArray.sort();
  //## end ParticleBunch::SortByCT%3981E5C90154.body
}

//## Operation: Output%3729CB500280
void ParticleBunch::Output (std::ostream& os) const
{
  //## begin ParticleBunch::Output%3729CB500280.body preserve=yes
//	std::copy(begin(),end(),ostream_iterator<PSvector>(os));
	int oldp=os.precision(10);
	ios_base::fmtflags oflg = os.setf(ios::scientific,ios::floatfield);
	for(PSvectorArray::const_iterator p = begin(); p!=end(); p++) {
		os<<std::setw(20)<<GetReferenceTime();
		os<<std::setw(20)<<GetReferenceMomentum();
		os<<(*p);
	}
	os.precision(oldp);
	os.flags(oflg);
  //## end ParticleBunch::Output%3729CB500280.body
}

//## Operation: SetCentroid%3C0B9CB50293
void ParticleBunch::SetCentroid (const Particle& x0)
{
  //## begin ParticleBunch::SetCentroid%3C0B9CB50293.body preserve=yes
	PSvector x;
	GetCentroid(x);
	x-=x0;
	for(PSvectorArray::iterator p = begin(); p!=end(); p++)
		*p-=x;
  //## end ParticleBunch::SetCentroid%3C0B9CB50293.body
}

//## begin module%3981E4490352.epilog preserve=yes
//## end module%3981E4490352.epilog

//## begin module%396B2620019A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\GroundMotionModels\SimpleATL.cpp
 * last modified 28/03/01 17:26:52
 */
//## end module%396B2620019A.cm

//## begin module%396B2620019A.cp preserve=no
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
//## end module%396B2620019A.cp

//## Module: SimpleATL%396B2620019A; Pseudo Package body
//## Subsystem: Merlin::GroundMotionModels%396B6A3101D6
//## Source file: D:\dev\Merlin\GroundMotionModels\SimpleATL.cpp

//## begin module%396B2620019A.includes preserve=yes
#include <algorithm>
#include <iomanip>
//## end module%396B2620019A.includes

// RandomNG
#include "Random/RandomNG.h"
// SimpleATL
#include "GroundMotionModels/SimpleATL.h"
//## begin module%396B2620019A.additionalDeclarations preserve=yes

#undef ATL_XY

namespace {

	using namespace std;

	inline void ResetSupport(AcceleratorSupport* s)
	{
		s->Reset();
	}

	// function used to sort supports in acending arc position 
	inline bool AsZ(const AcceleratorSupport* s1, const AcceleratorSupport* s2)
	{
		return s1->GetArcPosition() < s2->GetArcPosition();
	}

	struct ApplyATL {
		
		ApplyATL(double A, double dt, vector<double>& gmy, double vibv,RandGenerator* rg) 
			: AT(A*dt),y(0),z(0),yy(gmy.begin()),vv(vibv),rng(rg) {}

		void operator()(AcceleratorSupport* s)
		{
			// Perform the random walk
			double v = AT*(s->GetArcPosition()-z);
			y += rng->normal(0,v);
			*yy += y;

			// add random 'noise'
			double yv = vv!=0 ? rng->normal(0,vv) : 0.0;

			s->SetOffset(0,*yy+yv,0);
			z=s->GetArcPosition();

			yy++;
		}

		// data members
		double AT;
		double y;
		double z;
		vector<double>::iterator yy;
		double vv;
		RandGenerator* rng;
	};

	struct DumpOffset {

		DumpOffset(ostream& anOS):os(anOS) {}

		void operator()(const AcceleratorSupport* s) 
		{
			using std::setw;
			Vector3D offset=s->GetOffset();
			os<<setw(12)<<offset.x;
			os<<setw(12)<<offset.y;
			os<<setw(12)<<offset.z;
			os<<endl;
		}

		ostream& os;
	};

}; // end of annonymous namespace

//## end module%396B2620019A.additionalDeclarations


// Class SimpleATL 






//## Operation: SimpleATL%963324079; C++
SimpleATL::SimpleATL (double anA, const AcceleratorSupportList& supports, double vrms)
  //## begin SimpleATL::SimpleATL%963324079.initialization preserve=yes
  : t(0),A(anA),seed(0),vv(vrms*vrms),atlgm(supports.size(),0.0),theSupports(supports),
  rg(new RandGenerator())
  //## end SimpleATL::SimpleATL%963324079.initialization
{
  //## begin SimpleATL::SimpleATL%963324079.body preserve=yes
	sort(theSupports.begin(),theSupports.end(),AsZ);
  //## end SimpleATL::SimpleATL%963324079.body
}


//## Operation: ~SimpleATL%963324087; C++
SimpleATL::~SimpleATL ()
{
  //## begin SimpleATL::~SimpleATL%963324087.body preserve=yes
	delete rg;
  //## end SimpleATL::~SimpleATL%963324087.body
}



//## Other Operations (implementation)
//## Operation: Reset%963324080; C++
void SimpleATL::Reset ()
{
  //## begin SimpleATL::Reset%963324080.body preserve=yes
	for_each(theSupports.begin(),theSupports.end(),ResetSupport);
	fill(atlgm.begin(),atlgm.end(),0.0);
	t=0;
  //## end SimpleATL::Reset%963324080.body
}

//## Operation: DoStep%963324081; C++
double SimpleATL::DoStep (double dt)
{
  //## begin SimpleATL::DoStep%963324081.body preserve=yes
	for_each(theSupports.begin(),theSupports.end(),ApplyATL(A,dt,atlgm,vv,rg));
	return t+=dt;
  //## end SimpleATL::DoStep%963324081.body
}

//## Operation: RecordOffsets%963324082; C++
void SimpleATL::RecordOffsets (std::ostream& os) const
{
  //## begin SimpleATL::RecordOffsets%963324082.body preserve=yes
	ios_base::fmtflags oldFlags = os.flags();
	int prec = os.precision();

	os.setf(ios_base::scientific,ios_base::floatfield);
	os.precision(4);

	for_each(theSupports.begin(),theSupports.end(),DumpOffset(os));

	os.flags(oldFlags);
	os.precision(prec);
  //## end SimpleATL::RecordOffsets%963324082.body
}

//## Operation: GetTime%963324083; C++
double SimpleATL::GetTime () const
{
  //## begin SimpleATL::GetTime%963324083.body preserve=yes
	return t;
  //## end SimpleATL::GetTime%963324083.body
}

//## Operation: SetRandomSeed%963324084; C++
void SimpleATL::SetRandomSeed (unsigned int nseed)
{
  //## begin SimpleATL::SetRandomSeed%963324084.body preserve=yes
	rg->reset(nseed);
  //## end SimpleATL::SetRandomSeed%963324084.body
}

//## Operation: GetRandomSeed%963324085; C++
unsigned int SimpleATL::GetRandomSeed () const
{
  //## begin SimpleATL::GetRandomSeed%963324085.body preserve=yes
	return rg->getSeed();
  //## end SimpleATL::GetRandomSeed%963324085.body
}

//## Operation: ResetRandomSeed%963324086; C++
void SimpleATL::ResetRandomSeed ()
{
  //## begin SimpleATL::ResetRandomSeed%963324086.body preserve=yes
	rg->reset();
  //## end SimpleATL::ResetRandomSeed%963324086.body
}

//## begin module%396B2620019A.epilog preserve=yes
//## end module%396B2620019A.epilog

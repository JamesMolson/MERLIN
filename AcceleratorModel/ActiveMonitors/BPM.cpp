//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%372703BA01D6.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\ActiveMonitors\BPM.cpp
 * last modified 09/13/01 12:16:38 PM
 */
//## end module%372703BA01D6.cm

//## begin module%372703BA01D6.cp preserve=no
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
//## end module%372703BA01D6.cp

//## Module: BPM%372703BA01D6; Package body
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
//## Source file: C:\C++\Merlin\AcceleratorModel\ActiveMonitors\BPM.cpp

//## begin module%372703BA01D6.includes preserve=yes
#include "merlin_config.h"
//## end module%372703BA01D6.includes

// Bunch
#include "BeamModel/Bunch.h"
// BPM
#include "AcceleratorModel/ActiveMonitors/BPM.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"
// RandomNG
#include "Random/RandomNG.h"


//## begin module%372703BA01D6.additionalDeclarations preserve=yes
using namespace std;
//## end module%372703BA01D6.additionalDeclarations


// Class BPM::Data 




// Class BPM::Buffer 


// Class BPM 

bool BPM::generate_noise = true;


//## begin BPM::ID%3726FEF001E0.attr preserve=no  public: static const int {UA} UniqueIndex()
const int BPM::ID = UniqueIndex();
//## end BPM::ID%3726FEF001E0.attr






//## Other Operations (implementation)
//## Operation: SetScale%3BA086F8010F
void BPM::SetScale (double xs, double ys)
{
  //## begin BPM::SetScale%3BA086F8010F.body preserve=yes
	scale_x = xs;
	scale_y = ys;
  //## end BPM::SetScale%3BA086F8010F.body
}

//## Operation: MakeMeasurement%37258EEE03B6; C++
//## Qualification: abstract
void BPM::MakeMeasurement (const Bunch& aBunch)
{
  //## begin BPM::MakeMeasurement%37258EEE03B6.body preserve=yes
	if(TakeData()) {
		Point2D x0 = aBunch.GetProjectedCentroid(ps_X,ps_Y);
		
		if(generate_noise && res_x!=0)
			x0.x += RandomNG::normal(0.0,res_x*res_x);
		if(generate_noise && res_y!=0)
			x0.y += RandomNG::normal(0.0,res_y*res_y);
		
		x0.x *= scale_x;
		x0.y *= scale_y;

		Data mdat;
		mdat.x.value = x0.x;
		mdat.x.error = res_x;
		mdat.y.value = x0.y;
		mdat.y.error = res_y;
//		mdat.q.value = aBunch.GetTotalCharge();
//		mdat.q.error = res_q;
		mdat.ct = aBunch.GetReferenceTime();

		buffers.SendToBuffers(*this,mdat);
	}
  //## end BPM::MakeMeasurement%37258EEE03B6.body
}

//## Operation: GetIndex%37258EFC00BE
int BPM::GetIndex () const
{
  //## begin BPM::GetIndex%37258EFC00BE.body preserve=yes
	return ID;
  //## end BPM::GetIndex%37258EFC00BE.body
}

//## Operation: GetType%37258F0000C8
const string& BPM::GetType () const
{
  //## begin BPM::GetType%37258F0000C8.body preserve=yes
	_TYPESTR(BPM)
  //## end BPM::GetType%37258F0000C8.body
}

//## Operation: PrepareTracker%37258F0701C2
void BPM::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin BPM::PrepareTracker%37258F0701C2.body preserve=yes
	_PREPTRACK(aTracker,Monitor)
  //## end BPM::PrepareTracker%37258F0701C2.body
}

//## Operation: Copy%37258F0F03C0
ModelElement* BPM::Copy () const
{
  //## begin BPM::Copy%37258F0F03C0.body preserve=yes
	return new BPM(*this);
  //## end BPM::Copy%37258F0F03C0.body
}

//## begin module%372703BA01D6.epilog preserve=yes
//## end module%372703BA01D6.epilog

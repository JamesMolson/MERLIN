//## begin module%372703BB0190.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\ActiveMonitors\RMSProfileMonitor.cpp
 * last modified 04/04/01 17:42:51
 */
//## end module%372703BB0190.cm

//## begin module%372703BB0190.cp preserve=no
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
//## end module%372703BB0190.cp

//## Module: RMSProfileMonitor%372703BB0190; Package body
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
//## Source file: D:\dev\Merlin\AcceleratorModel\ActiveMonitors\RMSProfileMonitor.cpp

//## begin module%372703BB0190.includes preserve=yes
//## end module%372703BB0190.includes

// RandomNG
#include "Random/RandomNG.h"
// Bunch
#include "BeamModel/Bunch.h"
// RMSProfileMonitor
#include "AcceleratorModel/ActiveMonitors/RMSProfileMonitor.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"


//## begin module%372703BB0190.declarations preserve=no
//## end module%372703BB0190.declarations

//## begin module%372703BB0190.additionalDeclarations preserve=yes
#define _ADDNOISE(var) if((var).error!=0) (var).value+=RandomNG::normal(0.0,(var).error*(var).error)
//## end module%372703BB0190.additionalDeclarations


// Class RMSProfileMonitor::Data 







// Class RMSProfileMonitor::Buffer 

//## begin RMSProfileMonitor::BufferManager.instantiation preserve=no
//template class AMBufferManager< RMSProfileMonitor,Buffer,Data >;
//## end RMSProfileMonitor::BufferManager.instantiation
// Class RMSProfileMonitor 





//## begin RMSProfileMonitor::ID%37272868035C.attr preserve=no  public: static const int {UA} UniqueIndex()
const int RMSProfileMonitor::ID = UniqueIndex();
//## end RMSProfileMonitor::ID%37272868035C.attr



//## Other Operations (implementation)
//## Operation: GetIndex%925300221
int RMSProfileMonitor::GetIndex () const
{
  //## begin RMSProfileMonitor::GetIndex%925300221.body preserve=yes
	return ID;
  //## end RMSProfileMonitor::GetIndex%925300221.body
}

//## Operation: GetType%925300222
const string& RMSProfileMonitor::GetType () const
{
  //## begin RMSProfileMonitor::GetType%925300222.body preserve=yes
	_TYPESTR(RMSProfileMonitor)
  //## end RMSProfileMonitor::GetType%925300222.body
}

//## Operation: MakeMeasurement%925300240; C++
//## Qualification: abstract
void RMSProfileMonitor::MakeMeasurement (const Bunch& aBunch)
{
  //## begin RMSProfileMonitor::MakeMeasurement%925300240.body preserve=yes
	if(!buffers.empty() && IsActive()) {
		PSmoments2D profile;
		aBunch.GetProjectedMoments(ps_X,ps_Y,profile);

		Data mdat;

		mdat.x0.value = profile.mean(0);
		mdat.x0.error = res_x;
		mdat.y0.value = profile.mean(1);
		mdat.y0.error = res_y;
		mdat.xrms.value = profile.std(0);
		mdat.xrms.error = res_x;
		mdat.yrms.value = profile.std(1);
		mdat.yrms.error = res_y;

		// angled measurement
		if(uangle==0) {
			mdat.u0.value = mdat.x0.value;
			mdat.urms.value = mdat.xrms.value;
		}
		else if(uangle==pi/2) {
			mdat.u0.value = mdat.y0.value;
			mdat.urms.value = mdat.yrms.value;
		}
		else {
			double cosu = cos(uangle);
			double sinu = sin(uangle);
			mdat.u0.value = cosu*profile.mean(0)-sinu*profile.mean(1);
			mdat.urms.value = cosu*profile.std(0)-sinu*profile.std(1);
		}

		mdat.u0.error = res_u;
		mdat.urms.error = res_u;

		// Add noise

		_ADDNOISE(mdat.x0);
		_ADDNOISE(mdat.y0);
		_ADDNOISE(mdat.u0);
		_ADDNOISE(mdat.xrms);
		_ADDNOISE(mdat.yrms);
		_ADDNOISE(mdat.urms);

		buffers.SendToBuffers(*this,mdat);
	}
  //## end RMSProfileMonitor::MakeMeasurement%925300240.body
}

//## Operation: PrepareTracker%925300223
void RMSProfileMonitor::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin RMSProfileMonitor::PrepareTracker%925300223.body preserve=yes
	_PREPTRACK(aTracker,Monitor)
  //## end RMSProfileMonitor::PrepareTracker%925300223.body
}

//## Operation: Copy%925300224
ModelElement* RMSProfileMonitor::Copy () const
{
  //## begin RMSProfileMonitor::Copy%925300224.body preserve=yes
	return new RMSProfileMonitor(*this);
  //## end RMSProfileMonitor::Copy%925300224.body
}

//## begin module%372703BB0190.epilog preserve=yes
//## end module%372703BB0190.epilog

//## begin module%3AE821F3008C.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\Corrections\LinearFBSystem.cpp
 * last modified 26/04/01 16:24:16
 */
//## end module%3AE821F3008C.cm

//## begin module%3AE821F3008C.cp preserve=no
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
//## end module%3AE821F3008C.cp

//## Module: LinearFBSystem%3AE821F3008C; Pseudo Package body
//## Subsystem: Merlin::Corrections%3AE821D60352
//## Source file: D:\dev\Merlin\Corrections\LinearFBSystem.cpp

//## begin module%3AE821F3008C.includes preserve=yes
#include <cassert>
#include "TLAS/TLASimp.h"
//## end module%3AE821F3008C.includes

// LinearFBSystem
#include "Corrections/LinearFBSystem.h"
//## begin module%3AE821F3008C.additionalDeclarations preserve=yes
using namespace TLAS;

namespace {

	double ChannelRMS(const ROChannelArray& channels)
	{
		RealVector v(channels.Size());
		channels.ReadAll(v);
		return sqrt(v*v/v.size());
	}
};
//## end module%3AE821F3008C.additionalDeclarations


// Class LinearFBSystem 







//## Operation: LinearFBSystem%988274709
LinearFBSystem::LinearFBSystem (std::vector<ROChannel*>& sigs, std::vector<RWChannel*>& acts, const RealMatrix& M)
  //## begin LinearFBSystem::LinearFBSystem%988274709.initialization preserve=yes
  : gain(1.0),signals(sigs),actuators(acts),setpoints(0.0,sigs.size()),cached_actuators(0),Mi(0),
  actuatorQueue(0)
  //## end LinearFBSystem::LinearFBSystem%988274709.initialization
{
  //## begin LinearFBSystem::LinearFBSystem%988274709.body preserve=yes
	SetResponseMatrix(M);
  //## end LinearFBSystem::LinearFBSystem%988274709.body
}


//## Operation: ~LinearFBSystem%988274710
LinearFBSystem::~LinearFBSystem ()
{
  //## begin LinearFBSystem::~LinearFBSystem%988274710.body preserve=yes
	if(Mi!=0) delete Mi;
	if(actuatorQueue!=0) delete actuatorQueue;
	if(cached_actuators!=0) delete cached_actuators;
  //## end LinearFBSystem::~LinearFBSystem%988274710.body
}



//## Other Operations (implementation)
//## Operation: SignalsToSetpoints%988274711
void LinearFBSystem::SignalsToSetpoints ()
{
  //## begin LinearFBSystem::SignalsToSetpoints%988274711.body preserve=yes
	signals.ReadAll(setpoints);
  //## end LinearFBSystem::SignalsToSetpoints%988274711.body
}

//## Operation: StoreActuators%988274712
void LinearFBSystem::StoreActuators () const
{
  //## begin LinearFBSystem::StoreActuators%988274712.body preserve=yes
	// Note that this stores the current actuator setting, regardless
	// of the state of actuatorQueue.
	if(cached_actuators==0)
		cached_actuators = new RealVector(GetNumActuators());
	actuators.ReadAll(*cached_actuators);
  //## end LinearFBSystem::StoreActuators%988274712.body
}

//## Operation: RestoreActuators%988274713
void LinearFBSystem::RestoreActuators ()
{
  //## begin LinearFBSystem::RestoreActuators%988274713.body preserve=yes
	assert(cached_actuators!=0);
	actuators.WriteAll(*cached_actuators);
  //## end LinearFBSystem::RestoreActuators%988274713.body
}

//## Operation: SetResponseMatrix%988274714
void LinearFBSystem::SetResponseMatrix (const RealMatrix& M)
{
  //## begin LinearFBSystem::SetResponseMatrix%988274714.body preserve=yes
	assert(signals.Size()==M.nrows() && actuators.Size()==M.ncols());
	if(Mi!=0)
		delete Mi;
	Mi = new SVDMatrix<double>(M);
  //## end LinearFBSystem::SetResponseMatrix%988274714.body
}

//## Operation: SetGain%988274715
void LinearFBSystem::SetGain (double g)
{
  //## begin LinearFBSystem::SetGain%988274715.body preserve=yes
	gain=g;
  //## end LinearFBSystem::SetGain%988274715.body
}

//## Operation: GetGain%988274716
double LinearFBSystem::GetGain () const
{
  //## begin LinearFBSystem::GetGain%988274716.body preserve=yes
	return gain;
  //## end LinearFBSystem::GetGain%988274716.body
}

//## Operation: Apply%988274717
void LinearFBSystem::Apply ()
{
  //## begin LinearFBSystem::Apply%988274717.body preserve=yes
	RealVector S(signals.Size());
	signals.ReadAll(S);
	S-=setpoints;

	RealVector newActs(actuators.Size());
	actuators.ReadAll(newActs);
	newActs += -gain*(*Mi)(S);

	if(actuatorQueue) {
		actuatorQueue->push(newActs);
		actuators.WriteAll(actuatorQueue->front());
		actuatorQueue->pop();
	}
	else
		actuators.WriteAll(newActs);
  //## end LinearFBSystem::Apply%988274717.body
}

//## Operation: SetSetpoints%988274718
void LinearFBSystem::SetSetpoints (const RealVector& S0)
{
  //## begin LinearFBSystem::SetSetpoints%988274718.body preserve=yes
	assert(S0.size()==setpoints.size());
	setpoints=S0;
  //## end LinearFBSystem::SetSetpoints%988274718.body
}

//## Operation: GetActuatorRMS%988274719
double LinearFBSystem::GetActuatorRMS () const
{
  //## begin LinearFBSystem::GetActuatorRMS%988274719.body preserve=yes
	return ChannelRMS(actuators);
  //## end LinearFBSystem::GetActuatorRMS%988274719.body
}

//## Operation: GetSignalRMS%988274720
double LinearFBSystem::GetSignalRMS () const
{
  //## begin LinearFBSystem::GetSignalRMS%988274720.body preserve=yes
	RealVector S(signals.Size());
	signals.ReadAll(S);
	S-=setpoints;
	return sqrt(S*S/S.size());
  //## end LinearFBSystem::GetSignalRMS%988274720.body
}

//## Operation: GetNumSignals%988274721
int LinearFBSystem::GetNumSignals () const
{
  //## begin LinearFBSystem::GetNumSignals%988274721.body preserve=yes
	return signals.Size();
  //## end LinearFBSystem::GetNumSignals%988274721.body
}

//## Operation: GetNumActuators%988274722
int LinearFBSystem::GetNumActuators () const
{
  //## begin LinearFBSystem::GetNumActuators%988274722.body preserve=yes
	return actuators.Size();
  //## end LinearFBSystem::GetNumActuators%988274722.body
}

void LinearFBSystem::SetPulseDelay(int n)
{
	if(actuatorQueue!=0) {
		delete actuatorQueue;
		actuatorQueue = 0;
	}

	assert(n>0);

	if(n==1)
		return;

	actuatorQueue = new std::queue<RealVector>();

	RealVector zeros(0.0,actuators.Size());
	while((--n)>0)
		actuatorQueue->push(zeros);
}

//## begin module%3AE821F3008C.epilog preserve=yes
//## end module%3AE821F3008C.epilog

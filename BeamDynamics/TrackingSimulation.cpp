//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3AE6C1620366.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\TrackingSimulation.cpp
 * last modified 09/12/01 03:02:17 PM
 */
//## end module%3AE6C1620366.cm

//## begin module%3AE6C1620366.cp preserve=no
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
//## end module%3AE6C1620366.cp

//## Module: TrackingSimulation%3AE6C1620366; Package body
//## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
//## Source file: C:\C++\Merlin\BeamDynamics\TrackingSimulation.cpp

//## begin module%3AE6C1620366.includes preserve=yes
#include <algorithm>
#include <cassert>
#include "IO/MerlinIO.h"
//## end module%3AE6C1620366.includes

// TrackingSimulation
#include "BeamDynamics/TrackingSimulation.h"
//## begin module%3AE6C1620366.additionalDeclarations preserve=yes
namespace {

	using namespace std;

	template<class II>
		void PerformTracking(ProcessStepManager& aStepper, Bunch& aBunch, bool includeX,
			SimulationOutput* simop, II first, II last)
	{
		do {
			ComponentFrame* frame = *first;
			if(includeX)
				aBunch.ApplyTransformation(frame->GetEntrancePlaneTransform());
			aStepper.Track(frame->GetComponent());
			if(includeX)
				aBunch.ApplyTransformation(frame->GetExitPlaneTransform());
			if(simop)
				simop->Record(frame,&aBunch);
		} while(++first != last);
	}
};
//## end module%3AE6C1620366.additionalDeclarations


// Class TrackingSimulation::Stepper 



// Parameterized Class TrackingSimulation::TStepper 




//## Operation: TStepper%3B9F559702AD
template <class I>
TrackingSimulation::TStepper<I>::TStepper (I f, I l)
  //## begin TrackingSimulation::TStepper::TStepper%3B9F559702AD.initialization preserve=yes
  : first(f),last(l),curr(f)
  //## end TrackingSimulation::TStepper::TStepper%3B9F559702AD.initialization
{
  //## begin TrackingSimulation::TStepper::TStepper%3B9F559702AD.body preserve=yes
	cFrame = *curr;
  //## end TrackingSimulation::TStepper::TStepper%3B9F559702AD.body
}



//## Other Operations (implementation)
//## Operation: NextFrame%3B9F54F001B3
template <class I>
ComponentFrame* TrackingSimulation::TStepper<I>::NextFrame ()
{
  //## begin TrackingSimulation::TStepper::NextFrame%3B9F54F001B3.body preserve=yes
	curr++;
	return cFrame = curr==last ? 0 : *curr;
  //## end TrackingSimulation::TStepper::NextFrame%3B9F54F001B3.body
}

// Class TrackingSimulation 












//## Operation: TrackingSimulation%3AE6BAFC037A
TrackingSimulation::TrackingSimulation (const AcceleratorModel::Beamline& bline)
  //## begin TrackingSimulation::TrackingSimulation%3AE6BAFC037A.initialization preserve=yes
  : bunch(0),incX(true),log(0),handle_me(false),type(beamline),ibunchCtor(0),stepper(),theRing(),theBeamline(bline),cstepper(0),simOp(0)
  //## end TrackingSimulation::TrackingSimulation%3AE6BAFC037A.initialization
{
  //## begin TrackingSimulation::TrackingSimulation%3AE6BAFC037A.body preserve=yes
  //## end TrackingSimulation::TrackingSimulation%3AE6BAFC037A.body
}

//## Operation: TrackingSimulation%3B6697F001EF
TrackingSimulation::TrackingSimulation (const AcceleratorModel::RingIterator& aRing)
  //## begin TrackingSimulation::TrackingSimulation%3B6697F001EF.initialization preserve=yes
  : bunch(0),incX(true),log(0),handle_me(false),type(ring),ibunchCtor(0),stepper(),theRing(aRing),theBeamline(),cstepper(0),simOp(0)
  //## end TrackingSimulation::TrackingSimulation%3B6697F001EF.initialization
{
  //## begin TrackingSimulation::TrackingSimulation%3B6697F001EF.body preserve=yes
  //## end TrackingSimulation::TrackingSimulation%3B6697F001EF.body
}


//## Operation: ~TrackingSimulation%3AE6BFC002DA
TrackingSimulation::~TrackingSimulation ()
{
  //## begin TrackingSimulation::~TrackingSimulation%3AE6BFC002DA.body preserve=yes
	if(bunch)
		delete bunch;
	if(ibunchCtor)
		delete ibunchCtor;
  //## end TrackingSimulation::~TrackingSimulation%3AE6BFC002DA.body
}



//## Other Operations (implementation)
//## Operation: Run%396B6C450398
Bunch& TrackingSimulation::Run (bool genNewBunch)
{
  //## begin TrackingSimulation::Run%396B6C450398.body preserve=yes
	
	if(genNewBunch || bunch==0) {
		assert(ibunchCtor!=0);
		if(bunch!=0)
			delete bunch;
		bunch = ibunchCtor->ConstructBunch();
	}

	if(simOp)
		simOp->RecordInitialBunch(bunch);

	try {
		stepper.Initialise(*bunch);
		if(type==beamline)
			PerformTracking(stepper,*bunch,incX,simOp,theBeamline.begin(),theBeamline.end());
		else
			PerformTracking(stepper,*bunch,incX,simOp,theRing,theRing);
	} catch(MerlinException& me) {
		if(handle_me) {
			MERLIN_ERR<<endl<<me.Msg()<<endl;
		}
		else
			throw;
	}

	if(simOp)
		simOp->RecordFinalBunch(bunch);

	return *bunch;
  //## end TrackingSimulation::Run%396B6C450398.body
}

//## Operation: AddProcess%3AE6B4C901AE
void TrackingSimulation::AddProcess (BunchProcess* proc)
{
  //## begin TrackingSimulation::AddProcess%3AE6B4C901AE.body preserve=yes
	stepper.AddProcess(proc);
  //## end TrackingSimulation::AddProcess%3AE6B4C901AE.body
}

//## Operation: RemoveProcess%3AE6B4D500F0
bool TrackingSimulation::RemoveProcess (BunchProcess* proc)
{
  //## begin TrackingSimulation::RemoveProcess%3AE6B4D500F0.body preserve=yes
	return stepper.RemoveProcess(proc);
  //## end TrackingSimulation::RemoveProcess%3AE6B4D500F0.body
}

//## Operation: AssumeFlatLattice%3AE6B58F02C6
void TrackingSimulation::AssumeFlatLattice (bool flat)
{
  //## begin TrackingSimulation::AssumeFlatLattice%3AE6B58F02C6.body preserve=yes
	incX = !flat;
  //## end TrackingSimulation::AssumeFlatLattice%3AE6B58F02C6.body
}

//## Operation: SetInitialBunchCtor%3AE6B66D02D0
void TrackingSimulation::SetInitialBunchCtor (BunchConstructor* bctor)
{
  //## begin TrackingSimulation::SetInitialBunchCtor%3AE6B66D02D0.body preserve=yes
//	assert(bctor!=0);
	if(ibunchCtor!=0)
		delete ibunchCtor;
	ibunchCtor = bctor;
  //## end TrackingSimulation::SetInitialBunchCtor%3AE6B66D02D0.body
}

//## Operation: InitStepper%3B9F4FA4027B
void TrackingSimulation::InitStepper (bool genNewBunch)
{
  //## begin TrackingSimulation::InitStepper%3B9F4FA4027B.body preserve=yes
	assert(ibunchCtor!=0);
	
	if(genNewBunch || bunch==0) {
		if(bunch!=0)
			delete bunch;
		bunch = ibunchCtor->ConstructBunch();
	}

	stepper.Initialise(*bunch);

	if(cstepper!=0)
		delete cstepper;

	if(type==beamline)
		cstepper = new BeamlineStepper(theBeamline.begin(),theBeamline.end());
	else
//		cstepper = new RingStepper(theRing,theRing);
		cstepper = 0;
  //## end TrackingSimulation::InitStepper%3B9F4FA4027B.body
}

//## Operation: StepComponent%3B9F4F8D0369
bool TrackingSimulation::StepComponent ()
{
  //## begin TrackingSimulation::StepComponent%3B9F4F8D0369.body preserve=yes
	assert(cstepper && cstepper->cFrame);
	ComponentFrame* frame = cstepper->cFrame;
	if(incX)
		bunch->ApplyTransformation(frame->GetEntrancePlaneTransform());
		stepper.Track(frame->GetComponent());
	if(incX)
		bunch->ApplyTransformation(frame->GetExitPlaneTransform());

	if(simOp)
		simOp->Record(frame,bunch);

	return cstepper->NextFrame() != 0;
  //## end TrackingSimulation::StepComponent%3B9F4F8D0369.body
}

//## begin module%3AE6C1620366.epilog preserve=yes
//## end module%3AE6C1620366.epilog

void TrackingSimulation::SetOutput(SimulationOutput *simout)
{
	simOp = simout;
}

/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004-12-13 08:38:52 $
// $Revision: 1.4 $
// 
/////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cassert>
#include "IO/MerlinIO.h"
#include "BeamDynamics/TrackingSimulation.h"

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

}; // end of anonymous namespace

template <class I>
TrackingSimulation::TStepper<I>::TStepper (I f, I l)
        : first(f),last(l),curr(f)
{
    cFrame = *curr;
}

template <class I>
ComponentFrame* TrackingSimulation::TStepper<I>::NextFrame ()
{
    curr++;
    return cFrame = curr==last ? 0 : *curr;
}

TrackingSimulation::TrackingSimulation (const AcceleratorModel::Beamline& bline)
        : bunch(0),incX(true),log(0),handle_me(false),type(beamline),ibunchCtor(0),stepper(),theRing(),theBeamline(bline),cstepper(0),simOp(0)
{}

TrackingSimulation::TrackingSimulation (const AcceleratorModel::RingIterator& aRing)
        : bunch(0),incX(true),log(0),handle_me(false),type(ring),ibunchCtor(0),stepper(),theRing(aRing),theBeamline(),cstepper(0),simOp(0)
{}

TrackingSimulation::TrackingSimulation ()
        : bunch(0),incX(true),log(0),handle_me(false),type(undefined),ibunchCtor(0),stepper(),theRing(),theBeamline(),cstepper(0),simOp(0)
{}

void TrackingSimulation::SetBeamline (const AcceleratorModel::Beamline& bline)
{
    theBeamline = bline;
    type = beamline;
}

void TrackingSimulation::SetRing (const AcceleratorModel::RingIterator& aRing)
{
    theRing = aRing;
    type = ring;
}

TrackingSimulation::~TrackingSimulation ()
{
    if(bunch)
        delete bunch;
    if(ibunchCtor)
        delete ibunchCtor;
}

Bunch& TrackingSimulation::Run (bool genNewBunch)
{

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
}

void TrackingSimulation::AddProcess (BunchProcess* proc)
{
    stepper.AddProcess(proc);
}

bool TrackingSimulation::RemoveProcess (BunchProcess* proc)
{
    return stepper.RemoveProcess(proc);
}

void TrackingSimulation::AssumeFlatLattice (bool flat)
{
    incX = !flat;
}

void TrackingSimulation::SetInitialBunchCtor (BunchConstructor* bctor)
{
    //	assert(bctor!=0);
    if(ibunchCtor!=0)
        delete ibunchCtor;
    ibunchCtor = bctor;
}

void TrackingSimulation::InitStepper (bool genNewBunch)
{
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
}

void TrackingSimulation::InitStepper (Bunch* aBunch)
{
    if(bunch!=0)
        delete bunch;

    bunch = aBunch;
    stepper.Initialise(*bunch);

    if(cstepper!=0)
        delete cstepper;

    if(type==beamline)
        cstepper = new BeamlineStepper(theBeamline.begin(),theBeamline.end());
    else
        cstepper = 0;
}

bool TrackingSimulation::StepComponent ()
{
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
}


void TrackingSimulation::SetOutput(SimulationOutput *simout)
{
    simOp = simout;
}

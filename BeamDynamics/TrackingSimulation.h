//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3AE6C15A019A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\TrackingSimulation.h
 * last modified 09/12/01 03:01:48 PM
 */
//## end module%3AE6C15A019A.cm

//## begin module%3AE6C15A019A.cp preserve=no
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
//## end module%3AE6C15A019A.cp

//## Module: TrackingSimulation%3AE6C15A019A; Package specification
//## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
//## Source file: C:\C++\Merlin\BeamDynamics\TrackingSimulation.h

#ifndef TrackingSimulation_h
#define TrackingSimulation_h 1

//## begin module%3AE6C15A019A.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE6C15A019A.additionalIncludes

//## begin module%3AE6C15A019A.includes preserve=yes
//## end module%3AE6C15A019A.includes

// Bunch
#include "BeamModel/Bunch.h"
// BunchConstructor
#include "BeamModel/BunchConstructor.h"
// ProcessStepManager
#include "BeamDynamics/ProcessStepManager.h"
// BunchProcess
#include "BeamDynamics/BunchProcess.h"
// AcceleratorModel
#include "AcceleratorModel/AcceleratorModel.h"
// ComponentFrame
#include "AcceleratorModel/Frames/ComponentFrame.h"
// MerlinException
#include "Exception/MerlinException.h"
//## begin module%3AE6C15A019A.additionalDeclarations preserve=yes
//## end module%3AE6C15A019A.additionalDeclarations

// Abstract class used to record bunch and frame information
// after every component frame tracked

class SimulationOutput {
public:
	virtual ~SimulationOutput() {}
	virtual void Record(const ComponentFrame* frame, const Bunch* bunch) =0;
	virtual void RecordInitialBunch(const Bunch* bunch) =0;
	virtual void RecordFinalBunch(const Bunch* bunch) =0;
};

//## Class: TrackingSimulation%396B6B6A017C
//	A beam dynamics simulation. TrackingSimulation tracks a
//	Bunch object through a specified Beamline (single pass).
//	Tracking is performed by one or more BunchProcess
//	objects, one of which is generally a transport process
//	which is responsible for "tracking" the concrete Bunch
//	implementation through the Beamline components. The
//	initial Bunch is generated on each Run using the
//	supplied BunchConstructor.
//## Category: Merlin::BeamDynamics%3AE6C3A80398
//## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AE817E0003C;MerlinException { -> }

class TrackingSimulation 
{
  private: //## implementation
    //## Class: lattice_type%3B6698D30032; implementation
    //## Category: Merlin::BeamDynamics%3AE6C3A80398
    //## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef enum {beamline, ring} lattice_type;

    //## Class: Stepper%3B9F534C0231; implementation
    //	Base class for stepping (iterating) through a beamline
    //	or ring.
    //## Category: Merlin::BeamDynamics%3AE6C3A80398
    //## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class Stepper 
    {
      public:

        //## Other Operations (specified)
          //## Operation: NextFrame%3B9F542B0214
          virtual ComponentFrame* NextFrame () = 0;

        // Data Members for Associations

          //## Association: Merlin::BeamDynamics::<unnamed>%3B9F56400274
          //## Role: Stepper::cFrame%3B9F56410045
          //## begin TrackingSimulation::Stepper::cFrame%3B9F56410045.role preserve=no  public: ComponentFrame { -> 0..1RHAN}
          ComponentFrame* cFrame;
          //## end TrackingSimulation::Stepper::cFrame%3B9F56410045.role

      protected:
      private:
      private: //## implementation
    };

    //## Class: TStepper%3B9F53C8022F; implementation; Parameterized Class
    //	Stepper implementation to take either a ring or a
    //	beamline iterator.
    //## Category: Merlin::BeamDynamics%3AE6C3A80398
    //## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    template <class I>
    class TStepper : public Stepper  //## Inherits: <unnamed>%3B9F54900395
    {
      public:
        //## Constructors (specified)
          //## Operation: TStepper%3B9F559702AD
          TStepper (I f, I l);


        //## Other Operations (specified)
          //## Operation: NextFrame%3B9F54F001B3
          virtual ComponentFrame* NextFrame ();

      protected:
      private:
        // Data Members for Class Attributes

          //## Attribute: first%3B9F55700275
          //## begin TrackingSimulation::TStepper::first%3B9F55700275.attr preserve=no  private: I {UA} 
          I first;
          //## end TrackingSimulation::TStepper::first%3B9F55700275.attr

          //## Attribute: last%3B9F557702CF
          //## begin TrackingSimulation::TStepper::last%3B9F557702CF.attr preserve=no  private: I {UA} 
          I last;
          //## end TrackingSimulation::TStepper::last%3B9F557702CF.attr

          //## Attribute: curr%3B9F557B019F
          //## begin TrackingSimulation::TStepper::curr%3B9F557B019F.attr preserve=no  private: I {UA} 
          I curr;
          //## end TrackingSimulation::TStepper::curr%3B9F557B019F.attr

      private: //## implementation
    };

  public:
    //## Class: BeamlineStepper%3B9F5A220223; Instantiated Class
    //## Category: Merlin::BeamDynamics%3AE6C3A80398
    //## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef TStepper< AcceleratorModel::BeamlineIterator  > BeamlineStepper;

    //## Class: RingStepper%3B9F5A6D0326; Instantiated Class
    //## Category: Merlin::BeamDynamics%3AE6C3A80398
    //## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef TStepper< AcceleratorModel::RingIterator  > RingStepper;

    //## Constructors (specified)
      //## Operation: TrackingSimulation%3AE6BAFC037A
      TrackingSimulation (const AcceleratorModel::Beamline& bline);

      //## Operation: TrackingSimulation%3B6697F001EF
      TrackingSimulation (const AcceleratorModel::RingIterator& aRing);

    //## Destructor (specified)
      //## Operation: ~TrackingSimulation%3AE6BFC002DA
      virtual ~TrackingSimulation ();


    //## Other Operations (specified)
      //## Operation: Run%396B6C450398
      //	Run the simulation. If genNewBunch is true (default),
      //	then a new bunch is constructed to be tracked. If false,
      //	then the current bunch is tracked. The latter behaviour
      //	can be used to model multiple turns of a circular
      //	machine.
      virtual Bunch& Run (bool genNewBunch = true);

      //## Operation: AddProcess%3AE6B4C901AE
      //	Add a BunchProcess to the simulation.
      void AddProcess (BunchProcess* proc);

      //## Operation: RemoveProcess%3AE6B4D500F0
      //	Remove the specified BunchProcess from the simulation.
      //	Returns true if successful.
      bool RemoveProcess (BunchProcess* proc);

      //## Operation: AssumeFlatLattice%3AE6B58F02C6
      //	if flat is true, the simulation ignores all coordinate
      //	transformations between lattice components. If flat is
      //	false (default), the simulation applies all necessary
      //	in- and out-transformations for each component in the
      //	beamline.
      void AssumeFlatLattice (bool flat);

      //## Operation: SetInitialBunchCtor%3AE6B66D02D0
      //	Sets the initial bunch constructor.
      void SetInitialBunchCtor (BunchConstructor* bctor);

      //## Operation: SetLogStream%3AE6E489021C
      void SetLogStream (ostream& os)
      {
        //## begin TrackingSimulation::SetLogStream%3AE6E489021C.body preserve=yes
		  log = &os;
        //## end TrackingSimulation::SetLogStream%3AE6E489021C.body
      }

      //## Operation: SetLogginOn%3AE6E4A20244
      void SetLogginOn ()
      {
        //## begin TrackingSimulation::SetLogginOn%3AE6E4A20244.body preserve=yes
		  stepper.SetLogStream(log);
        //## end TrackingSimulation::SetLogginOn%3AE6E4A20244.body
      }

      //## Operation: SetLogginOff%3AE6E4C10078
      void SetLogginOff ()
      {
        //## begin TrackingSimulation::SetLogginOff%3AE6E4C10078.body preserve=yes
		  stepper.SetLogStream(0);
        //## end TrackingSimulation::SetLogginOff%3AE6E4C10078.body
      }

      //## Operation: HandleExceptions%3AE8163802B2
      //	If handle==true, then any MerlinException thrown while
      //	the simulation is running is handled locally, and Run()
      //	command exits normally. If false, any exception is
      //	re-thrown.
      void HandleExceptions (bool handle)
      {
        //## begin TrackingSimulation::HandleExceptions%3AE8163802B2.body preserve=yes
		  handle_me = handle;
        //## end TrackingSimulation::HandleExceptions%3AE8163802B2.body
      }

      //## Operation: InitStepper%3B9F4FA4027B
      //	The following methods are for use when stepping though
      //	the beamline.
      //
      //	Initialise a new bunch object for tracking, and resets
      //	the current frame to the first frame of the beamline.
      void InitStepper (bool genNewBunch = true);

      //## Operation: StepComponent%3B9F4F8D0369
      //	Track the bunch though the next ComponentFrame in the
      //	beamline. Returns false if that component is the last in
      //	the beamline.
      bool StepComponent ();

      //## Operation: GetCurrentFrame%3B9F4FBA0255
      //	Returns the current frame, i.e. that frame that is about
      //	to be tracked by a call to StepComponent().
      ComponentFrame& GetCurrentFrame ()
      {
        //## begin TrackingSimulation::GetCurrentFrame%3B9F4FBA0255.body preserve=yes
		  assert(cstepper);
		  return *(cstepper->cFrame);
        //## end TrackingSimulation::GetCurrentFrame%3B9F4FBA0255.body
      }

      //## Operation: GetCurrentComponent%3B9F50120342
      //	Returns the current component, i.e. that component that
      //	is about to be tracked by a call to StepComponent().
      AcceleratorComponent& GetCurrentComponent ()
      {
        //## begin TrackingSimulation::GetCurrentComponent%3B9F50120342.body preserve=yes
		  assert(cstepper);
		  return cstepper->cFrame->GetComponent();
        //## end TrackingSimulation::GetCurrentComponent%3B9F50120342.body
      }

	  void SetOutput(SimulationOutput* simout);

  protected:
    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::<unnamed>%3AE6D71900DC
      //## Role: TrackingSimulation::bunch%3AE6D71900DE
      //## begin TrackingSimulation::bunch%3AE6D71900DE.role preserve=no  protected: Bunch { -> 0..1VHgAN}
      Bunch* bunch;
      //## end TrackingSimulation::bunch%3AE6D71900DE.role

  private:
    // Data Members for Class Attributes

      //## Attribute: incX%3AE6DF7D00BE
      //## begin TrackingSimulation::incX%3AE6DF7D00BE.attr preserve=no  private: bool {UA} 
      bool incX;
      //## end TrackingSimulation::incX%3AE6DF7D00BE.attr

      //## Attribute: log%3AE6E549033E
      //## begin TrackingSimulation::log%3AE6E549033E.attr preserve=no  private: ostream* {UA} 
      ostream* log;
      //## end TrackingSimulation::log%3AE6E549033E.attr

      //## Attribute: handle_me%3AE816F60046
      //## begin TrackingSimulation::handle_me%3AE816F60046.attr preserve=no  private: bool {UA} 
      bool handle_me;
      //## end TrackingSimulation::handle_me%3AE816F60046.attr

      //## Attribute: type%3B6699B200B5
      //## begin TrackingSimulation::type%3B6699B200B5.attr preserve=no  private: lattice_type {UA} 
      lattice_type type;
      //## end TrackingSimulation::type%3B6699B200B5.attr

    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::<unnamed>%3AE6BF7D02D0
      //## Role: TrackingSimulation::ibunchCtor%3AE6BF7E021D
      //## begin TrackingSimulation::ibunchCtor%3AE6BF7E021D.role preserve=no  private: BunchConstructor { -> 0..1VHgAN}
      BunchConstructor* ibunchCtor;
      //## end TrackingSimulation::ibunchCtor%3AE6BF7E021D.role

      //## Association: Merlin::BeamDynamics::<unnamed>%396B6BAA0104
      //## Role: TrackingSimulation::stepper%396B6BAB012C
      //## begin TrackingSimulation::stepper%396B6BAB012C.role preserve=no  private: ProcessStepManager { -> 1VHgAN}
      ProcessStepManager stepper;
      //## end TrackingSimulation::stepper%396B6BAB012C.role

      //## Association: Merlin::BeamDynamics::<unnamed>%3AE6CF8402C6
      //## Role: TrackingSimulation::procs%3AE6CF850213
      //## begin TrackingSimulation::procs%3AE6CF850213.role preserve=no  private: BunchProcess { -> nVHgAN}
      //## end TrackingSimulation::procs%3AE6CF850213.role

  private: //## implementation
    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::<unnamed>%3B66A8B300AE
      //## Role: TrackingSimulation::theRing%3B66A8B30393
      //## begin TrackingSimulation::theRing%3B66A8B30393.role preserve=no  implementation: AcceleratorModel::RingIterator { -> 1VHgAN}
      AcceleratorModel::RingIterator theRing;
      //## end TrackingSimulation::theRing%3B66A8B30393.role

      //## Association: Merlin::BeamDynamics::<unnamed>%3B66A8C701ED
      //## Role: TrackingSimulation::theBeamline%3B66A8C70392
      //## begin TrackingSimulation::theBeamline%3B66A8C70392.role preserve=no  implementation: AcceleratorModel::Beamline { -> 1VHgAN}
      AcceleratorModel::Beamline theBeamline;
      //## end TrackingSimulation::theBeamline%3B66A8C70392.role

      //## Association: Merlin::BeamDynamics::<unnamed>%3B9F552101EF
      //## Role: TrackingSimulation::cstepper%3B9F55220179
      //## begin TrackingSimulation::cstepper%3B9F55220179.role preserve=no  implementation: TrackingSimulation::Stepper { -> 0..1VHgAN}
      Stepper* cstepper;
      //## end TrackingSimulation::cstepper%3B9F55220179.role

	  SimulationOutput* simOp;

};

//## Class: BunchTracker%3AE6D152015E; Parameterized Class
//	A template class which is used to implement a bunch
//	implementation specific TrackingSimulation. P must be a
//	bunch specific transport process which has only a
//	default constructor. It must also define P::bunch_type
//	which specifies the type of bunch implementation to be
//	tracked.
//## Category: Merlin::BeamDynamics%3AE6C3A80398
//## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AE6D503023A;BunchTracker< P >::bunch_type { -> F}
//## Uses: <unnamed>%3AE6D64601D6;StaticBunchCtor { -> }

template <class P>
class BunchTracker : public TrackingSimulation  //## Inherits: <unnamed>%3AE6D17B01EA
{
  public:
    //## Class: bunch_type%3AE6D23301EA
    //## Category: Merlin::BeamDynamics%3AE6C3A80398
    //## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef typename P::bunch_type bunch_type;

    //## Class: transport_process%3AE6D23C02D0
    //## Category: Merlin::BeamDynamics%3AE6C3A80398
    //## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef P transport_process;

    //## Constructors (specified)
      //## Operation: BunchTracker%3AE6D4850122
      //	Constructor taking the beamline to be tracked. The
      //	initial bunch must be specified by supplying a concrete
      //	BunchConstructor via SetInitialBunchCtor.
      explicit BunchTracker (const AcceleratorModel::Beamline& bline)
        //## begin BunchTracker::BunchTracker%3AE6D4850122.initialization preserve=yes
		: TrackingSimulation(bline)
        //## end BunchTracker::BunchTracker%3AE6D4850122.initialization
      {
        //## begin BunchTracker::BunchTracker%3AE6D4850122.body preserve=yes
		  AddProcess(new P());
        //## end BunchTracker::BunchTracker%3AE6D4850122.body
      }

      //## Operation: BunchTracker%3AE6D48F03B6
      //	Constructs a BunchTracker taking the beamline to be
      //	tracked and the initial bunch to be used.
      BunchTracker (const AcceleratorModel::Beamline& bline, bunch_type* bunch0)
        //## begin BunchTracker::BunchTracker%3AE6D48F03B6.initialization preserve=yes
		: TrackingSimulation(bline)
        //## end BunchTracker::BunchTracker%3AE6D48F03B6.initialization
      {
        //## begin BunchTracker::BunchTracker%3AE6D48F03B6.body preserve=yes
		  AddProcess(new P());
		  SetInitialBunchCtor(new StaticBunchCtor<bunch_type>(bunch0));
        //## end BunchTracker::BunchTracker%3AE6D48F03B6.body
      }


    //## Other Operations (specified)
      //## Operation: GetBunch%3AE6D4C3008C
      bunch_type& GetBunch ()
      {
        //## begin BunchTracker::GetBunch%3AE6D4C3008C.body preserve=yes
		  return static_cast<bunch_type&>(*bunch);
        //## end BunchTracker::GetBunch%3AE6D4C3008C.body
      }

      //## Operation: GetTransportProcess%3AE6D5F9012C
      transport_process& GetTransportProcess ()
      {
        //## begin BunchTracker::GetTransportProcess%3AE6D5F9012C.body preserve=yes
		  return *transport;
        //## end BunchTracker::GetTransportProcess%3AE6D5F9012C.body
      }

  public:
  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::<unnamed>%3AE6D29B01D6
      //## Role: BunchTracker::transport%3AE6D29E01AF
      //## begin BunchTracker::transport%3AE6D29E01AF.role preserve=no  private: BunchTracker< P >::transport_process { -> 0..1VHgAN}
      transport_process* transport;
      //## end BunchTracker::transport%3AE6D29E01AF.role

  private: //## implementation
};

// Parameterized Class BunchTracker 


//## begin module%3AE6C15A019A.epilog preserve=yes
//## end module%3AE6C15A019A.epilog


#endif

//## begin module%371450080280.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\TrackingInterface\ComponentTracker.h
 * last modified 03/04/01 14:44:11
 */
//## end module%371450080280.cm

//## begin module%371450080280.cp preserve=no
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
//## end module%371450080280.cp

//## Module: ComponentTracker%371450080280; Package specification
//## Subsystem: Merlin::AcceleratorModel::TrackingInterface%3AC484140014
//## Source file: D:\dev\Merlin\AcceleratorModel\TrackingInterface\ComponentTracker.h

#ifndef ComponentTracker_h
#define ComponentTracker_h 1

//## begin module%371450080280.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%371450080280.additionalIncludes

//## begin module%371450080280.includes preserve=yes
//## end module%371450080280.includes

// ComponentIntegrator
#include "AcceleratorModel/TrackingInterface/ComponentIntegrator.h"
// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"

class IntegratorTable;

//## begin module%371450080280.declarations preserve=no
//## end module%371450080280.declarations

//## begin module%371450080280.additionalDeclarations preserve=yes
//## end module%371450080280.additionalDeclarations


//## Class: ComponentTracker%36EE2EA200FC; Abstract
//	Tracker provides the primary interface for tracking
//	operations through an accelerator model. An object of
//	class Tracker can be thought of as a collection of
//	Integrator objects, each of which is responsible for
//	"tracking" some beam-like representation through a
//	specific component. Selection of the correct Integrator
//	is performed via the callback mechanism Select
//	Integrator, which is called directly by Accelerator
//	Component::PrepareTracker.  Concrete Tracker objects
//	should supply the (concrete) Integrators, which when
//	identified, are then passed back down to the concrete
//	class via a call the virtual function SetCurrent
//	Integrator.
//
//	The callback mechanism used by Tracker replaces the
//	canonical virtual function mechanism. It is a form of
//	the visitor pattern, but without the circular dependency
//	which is normally associated with that pattern.  Thus
//	the accelerator model representation can be easily
//	extended without the need to add new visitor functions.
//## Category: Merlin::AcceleratorModel::TrackingInterface%3AC4815503CA
//## Subsystem: Merlin::AcceleratorModel::TrackingInterface%3AC484140014
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%36EE2FAA0296;AcceleratorComponent { -> }
//## Uses: GetState%36EE3EB302A5;ComponentTracker::State { -> F}
//## Uses: <unnamed>%37CA72B000BE;DefaultMarkerIntegrator { -> }

class ComponentTracker 
{
  public:
    //## Class: State%36EE3E6A0368
    //	State of the Tracker.
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::TrackingInterface%3AC484140014
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef enum {undefined, initialised, tracking, finished} State;

    //## Class: UnknownComponent%371363F80028
    //	Exception thrown when no valid integrator is identified.
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::TrackingInterface%3AC484140014
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class UnknownComponent 
    {
      public:
      protected:
      private:
      private:  //## implementation
    };

  public:
    //## Destructor (specified)
      //## Operation: ~ComponentTracker%924021884
      //	Destructor
      virtual ~ComponentTracker ();


    //## Other Operations (specified)
      //## Operation: Track%924021885
      //	Track the entire current accelerator component. Initial
      //	tracker state must be initialised, and final state is
      //	finished.
      void Track ();

      //## Operation: TrackStep%924021886
      //	Track a step ds through the current component, and
      //	return the remaining distance to the exit boundary.
      //	Initial state must be either initialised or tracking.
      //	Final state is either tracking or finished. If ds tracks
      //	beyond the current AcceleratorComponent geometry, a
      //	BeyondExtent exception is thrown.
      double TrackStep (double ds);

      //## Operation: GetState%924021887
      //	Returns the current state of the Tracker.
      ComponentTracker::State GetState () const;

      //## Operation: Reset%924021888
      //	Reset the Tracker. The state is automatically set to
      //	undefined.
      void Reset ();

      //## Operation: GetRemainingTrackLength%924021889
      //	Returns the remaining tracking distance. Current state
      //	must be initialised, tracking or finished.
      double GetRemainingTrackLength () const;

      //## Operation: GetIntegratedLength%924021890
      //	Returns the total integrated length. State must be
      //	initialised, tracking or finished.
      double GetIntegratedLength () const;

      //## Operation: SelectIntegrator%924021891
      //	Function called by AcceleratorComponent objects to
      //	select the correct Integrator for component. Returns
      //	true if an Integrator object is found for index,
      //	otherwise false. This function is provided as part of
      //	the Tracker-AcceleratorComponent framework.
      bool SelectIntegrator (int index, AcceleratorComponent& component);

      //## Operation: operator()%963340561
      //	Function operator overload. Tracks the specified
      //	AcceleratorComponent in one step.
      void operator () (AcceleratorComponent* component);

  protected:
    //## Constructors (specified)
      //## Operation: ComponentTracker%924021883
      //	Constructor
      ComponentTracker ();


    //## Other Operations (specified)
      //## Operation: InitialiseIntegrator%924021892
      //	Protected virtual function called by SelectIntegrator()
      //	when it has successfully located a valid integrator.
      //	Concrete Tracker objects should override this function
      //	to perform any initialisation appropriate on the
      //	(concrete) integrator.
      virtual void InitialiseIntegrator ();

      //## Operation: Register%924021893
      //	Used to register an integrator. Returns true if this
      //	integrator overrides an existing one, otherwise false.
      //	Register() should be called by the constructors of
      //	concrete Tracker classes in order to setup the required
      //	integrators.
      bool Register (ComponentIntegrator* intg);

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::TrackingInterface::<unnamed>%371375EA00AA
      //## Role: ComponentTracker::integrator%371375EA02D0
      //	The current selected integrator.
      //## begin ComponentTracker::integrator%371375EA02D0.role preserve=no  protected: ComponentIntegrator { -> 0..1RFHAN}
      ComponentIntegrator* integrator;
      //## end ComponentTracker::integrator%371375EA02D0.role

  private:
    // Data Members for Class Attributes

      //## Attribute: itsState%37137660032A
      //## begin ComponentTracker::itsState%37137660032A.attr preserve=no  private: State {UA} 
      State itsState;
      //## end ComponentTracker::itsState%37137660032A.attr

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::TrackingInterface::<unnamed>%371379D802A8
      //## Role: ComponentTracker::itsTable%371379D900AA
      //## begin ComponentTracker::itsTable%371379D900AA.role preserve=no  private: IntegratorTable { -> 0..1VFHAN}
      IntegratorTable* itsTable;
      //## end ComponentTracker::itsTable%371379D900AA.role

  private:  //## implementation
};

// Class ComponentTracker::UnknownComponent 

// Class ComponentTracker 


//## Other Operations (inline)
//## Operation: GetState%924021887
inline ComponentTracker::State ComponentTracker::GetState () const
{
  //## begin ComponentTracker::GetState%924021887.body preserve=yes
	return itsState;
  //## end ComponentTracker::GetState%924021887.body
}

//## Operation: operator()%963340561
inline void ComponentTracker::operator () (AcceleratorComponent* component)
{
  //## begin ComponentTracker::operator()%963340561.body preserve=yes
	component->PrepareTracker(*this);
	Track();
  //## end ComponentTracker::operator()%963340561.body
}

//## begin module%371450080280.epilog preserve=yes
// Utility macros for tracker operations
#define _PREPTRACK(trk,S) if(!trk.SelectIntegrator(ID,*this))\
          S::PrepareTracker(trk); 
//## end module%371450080280.epilog


#endif

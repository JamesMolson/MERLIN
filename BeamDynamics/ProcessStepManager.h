//## begin module%3AE6C1310262.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ProcessStepManager.h
 * last modified 25/04/01 16:55:21
 */
//## end module%3AE6C1310262.cm

//## begin module%3AE6C1310262.cp preserve=no
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
//## end module%3AE6C1310262.cp

//## Module: ProcessStepManager%3AE6C1310262; Package specification
//## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
//## Source file: D:\dev\Merlin\BeamDynamics\ProcessStepManager.h

#ifndef ProcessStepManager_h
#define ProcessStepManager_h 1

//## begin module%3AE6C1310262.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE6C1310262.additionalIncludes

//## begin module%3AE6C1310262.includes preserve=yes
#include <list>
#include <ostream>
//## end module%3AE6C1310262.includes


class AcceleratorComponent;
class BunchProcess;
class Bunch;

//## begin module%3AE6C1310262.declarations preserve=no
//## end module%3AE6C1310262.declarations

//## begin module%3AE6C1310262.additionalDeclarations preserve=yes
//## end module%3AE6C1310262.additionalDeclarations


//## Class: ProcessStepManager%36EF75590171
//	Responsible for coordinating the tracking of a bunch
//	through a single AcceleratorComponent. Tracking occurs
//	by the application of a series of processes, which
//	effectively intergrate the bunch motion along the
//	beamline.
//## Category: Merlin::BeamDynamics%3AE6C3A80398
//## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: tracks%36EF88310326;AcceleratorComponent { -> F}
//## Uses: <unnamed>%37C3AC080028;deleter { -> }

class ProcessStepManager 
{
  public:
    //## Constructors (specified)
      //## Operation: ProcessStepManager%935569206
      //	Construction/destruction.
      ProcessStepManager ();

    //## Destructor (specified)
      //## Operation: ~ProcessStepManager%935569207
      ~ProcessStepManager ();


    //## Other Operations (specified)
      //## Operation: Initialise%935569208
      //	Initialise the step manager with the specified (initial)
      //	bunch.
      void Initialise (Bunch& bunch);

      //## Operation: Track%935569209
      //	Track the specified component. The current bunch object
      //	is updated accordingly.
      void Track (AcceleratorComponent& component);

      //## Operation: GetIntegratedLength%935569211
      //	Returns the total length integrated since the last call
      //	to Initialise(Bunch&).
      double GetIntegratedLength ();

      //## Operation: AddProcess%935569212
      //	Add a process.
      void AddProcess (BunchProcess* aProcess);

      //## Operation: RemoveProcess%935569213
      //	Remove aProcess from the current process table. Returns
      //	true if aProcess was present, otherwise false.
      bool RemoveProcess (BunchProcess* aProcess);

      //## Operation: ClearProcesses%935569214
      //	Remove and destroys all processes in the current process
      //	table.
      void ClearProcesses ();

      //## Operation: SetLogStream%988208175
      void SetLogStream (std::ostream* os);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: total_s%36EF838803C1
      //	The current intgrated length.
      //## begin ProcessStepManager::total_s%36EF838803C1.attr preserve=no  private: double {UA} 
      double total_s;
      //## end ProcessStepManager::total_s%36EF838803C1.attr

      //## Attribute: log%3AE6E47D0078
      //## begin ProcessStepManager::log%3AE6E47D0078.attr preserve=no  private: ostream* {UA} 
	  std::ostream* log;
      //## end ProcessStepManager::log%3AE6E47D0078.attr

    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::<unnamed>%36EF7566009E
      //## Role: ProcessStepManager::processTable%36EF75660257
      //	list of processes in order of priority.
      //## Constraints:
      //	ordered
      //## begin ProcessStepManager::processTable%36EF75660257.role preserve=no  private: BunchProcess { -> 0..nVFHOAN}
      std::list<BunchProcess*> processTable;
      //## end ProcessStepManager::processTable%36EF75660257.role

  private:  //## implementation
};

// Class ProcessStepManager 

//## begin module%3AE6C1310262.epilog preserve=yes
//## end module%3AE6C1310262.epilog


#endif

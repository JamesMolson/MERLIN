//## begin module%3AE6C1780046.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\BunchProcess.h
 * last modified 25/04/01 16:27:08
 */
//## end module%3AE6C1780046.cm

//## begin module%3AE6C1780046.cp preserve=no
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
//## end module%3AE6C1780046.cp

//## Module: BunchProcess%3AE6C1780046; Package specification
//## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
//## Source file: D:\dev\Merlin\BeamDynamics\BunchProcess.h

#ifndef BunchProcess_h
#define BunchProcess_h 1

//## begin module%3AE6C1780046.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE6C1780046.additionalIncludes

//## begin module%3AE6C1780046.includes preserve=yes
#include <string>
//## end module%3AE6C1780046.includes


class AcceleratorComponent;
class Bunch;

//## begin module%3AE6C1780046.declarations preserve=no
//## end module%3AE6C1780046.declarations

//## begin module%3AE6C1780046.additionalDeclarations preserve=yes
using namespace std;
//## end module%3AE6C1780046.additionalDeclarations


//## Class: BunchProcess%36EF6FBA0140; Abstract
//	A single process which is applied to a Bunch object
//	during tracking. A Process can represent any physical
//	(eg. particle transport) or abstract mechanism (eg.
//	output) which may be applied to a bunch at a specific
//	AcceleratorComponent. Concrete processes may be generic
//	to all Bunch model types , or may be specific to a
//	concrete bunch model (see for example ParticleBunch and
//	ParticleBunchTransortProcess).
//## Category: Merlin::BeamDynamics%3AE6C3A80398
//## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: acts on%37C3A9E9017C;Bunch { -> F}
//## Uses: <unnamed>%37C3A9EC02DA;AcceleratorComponent { -> F}

class BunchProcess 
{
  public:
    //## Constructors (specified)
      //## Operation: BunchProcess%935569219
      //	Constructing taking the process ID and its priority
      //	(default =0, high).
      explicit BunchProcess (const string& anID, int aPriority = 0);

    //## Destructor (specified)
      //## Operation: ~BunchProcess%935569220
      virtual ~BunchProcess ();


    //## Other Operations (specified)
      //## Operation: SetPriority%935569221
      //	Sets the priority. Highest priority is 0, followed by
      //	1,2,...etc.
      void SetPriority (int p);

      //## Operation: GetPriority%935569222
      //	Returns the priority. Highest priority is 0, followed by
      //	1,2,...etc.
      int GetPriority () const;

      //## Operation: InitialiseProcess%935569223
      //	Initialise this process with the specified Bunch.
      virtual void InitialiseProcess (Bunch& bunch) = 0;

      //## Operation: SetCurrentComponent%935569224
      //	Sets the current accelerator component. This function
      //	should be called just before tracking of the component
      //	begins. Concrete processes should override this function
      //	to perform component and preocess dependent
      //	initialisation.
      virtual void SetCurrentComponent (AcceleratorComponent& component) = 0;

      //## Operation: DoProcess%935569225
      //	Preform the process for the specified step ds.
      virtual void DoProcess (double ds) = 0;

      //## Operation: GetMaxAllowedStepSize%935569226
      //	Returns the current maximum step length for this process.
      virtual double GetMaxAllowedStepSize () const = 0;

      //## Operation: IsActive%935569227
      //	Returns true if this processes is active.
      bool IsActive () const;

      //## Operation: GetID%935569233
      const string& GetID () const;

  protected:
    // Data Members for Class Attributes

      //## Attribute: active%36EF75230368
      //## begin BunchProcess::active%36EF75230368.attr preserve=no  protected: bool {UA} 
      bool active;
      //## end BunchProcess::active%36EF75230368.attr

  private:
    // Data Members for Class Attributes

      //## Attribute: priority%36EF75230390
      //## begin BunchProcess::priority%36EF75230390.attr preserve=no  private: int {UA} 
      int priority;
      //## end BunchProcess::priority%36EF75230390.attr

      //## Attribute: ID%37C3A6B80276
      //## begin BunchProcess::ID%37C3A6B80276.attr preserve=no  private: string {UA} 
      string ID;
      //## end BunchProcess::ID%37C3A6B80276.attr

  private:  //## implementation
};

// Class BunchProcess 

//## Operation: BunchProcess%935569219
inline BunchProcess::BunchProcess (const string& anID, int aPriority)
  //## begin BunchProcess::BunchProcess%935569219.initialization preserve=yes
  : active(false),priority(aPriority),ID(anID)
  //## end BunchProcess::BunchProcess%935569219.initialization
{
  //## begin BunchProcess::BunchProcess%935569219.body preserve=yes
  //## end BunchProcess::BunchProcess%935569219.body
}


//## Operation: ~BunchProcess%935569220
inline BunchProcess::~BunchProcess ()
{
  //## begin BunchProcess::~BunchProcess%935569220.body preserve=yes
  //## end BunchProcess::~BunchProcess%935569220.body
}



//## Other Operations (inline)
//## Operation: SetPriority%935569221
inline void BunchProcess::SetPriority (int p)
{
  //## begin BunchProcess::SetPriority%935569221.body preserve=yes
	priority = p;
  //## end BunchProcess::SetPriority%935569221.body
}

//## Operation: GetPriority%935569222
inline int BunchProcess::GetPriority () const
{
  //## begin BunchProcess::GetPriority%935569222.body preserve=yes
	return priority;
  //## end BunchProcess::GetPriority%935569222.body
}

//## Operation: IsActive%935569227
inline bool BunchProcess::IsActive () const
{
  //## begin BunchProcess::IsActive%935569227.body preserve=yes
	return active;
  //## end BunchProcess::IsActive%935569227.body
}

//## Operation: GetID%935569233
inline const string& BunchProcess::GetID () const
{
  //## begin BunchProcess::GetID%935569233.body preserve=yes
	return ID;
  //## end BunchProcess::GetID%935569233.body
}

// Class BunchProcess 






//## begin module%3AE6C1780046.epilog preserve=yes
//## end module%3AE6C1780046.epilog


#endif

//## begin module%3AE821F3008C.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\Corrections\LinearFBSystem.h
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

//## Module: LinearFBSystem%3AE821F3008C; Pseudo Package specification
//## Subsystem: Merlin::Corrections%3AE821D60352
//## Source file: D:\dev\Merlin\Corrections\LinearFBSystem.h

#ifndef LinearFBSystem_h
#define LinearFBSystem_h 1

//## begin module%3AE821F3008C.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE821F3008C.additionalIncludes

//## begin module%3AE821F3008C.includes preserve=yes
#include "TLAS/TLAS.h"
#include <queue>
#include <list>
//## end module%3AE821F3008C.includes

// Channels
#include "Channels/Channels.h"
// LinearAlgebra
#include "TLAS/LinearAlgebra.h"

// SVDMatrix< double >

//## begin module%3AE821F3008C.additionalDeclarations preserve=yes
using namespace TLAS;
//## end module%3AE821F3008C.additionalDeclarations


//## Class: LinearFBSystem%3AE821F3008C
//	A simple linear feedback correction algorithm. On each
//	application, the actuator channels (A) are incremented
//	using the following linear equation:
//
//	A = A-g*(Mi*(S-S0))
//
//	where g is the gain, S are the current signal values and
//	S0 are the desired signal values (set points). Mi is a
//	speudo-inverse matrix of the response matrix M defined by
//
//	S=M*A
//
//	Mi is calculated using SVD.
//## Category: Merlin::Corrections%3AE821D60352
//## Subsystem: Merlin::Corrections%3AE821D60352
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class LinearFBSystem 
{
  public:
    //## Constructors (specified)
      //## Operation: LinearFBSystem%988274709
      LinearFBSystem (std::vector<ROChannel*>& sigs, std::vector<RWChannel*>& acts, const RealMatrix& M);
      LinearFBSystem (ROChannelArray& sigs, RWChannelArray& acts, const RealMatrix& M);

    //## Destructor (specified)
      //## Operation: ~LinearFBSystem%988274710
      ~LinearFBSystem ();


    //## Other Operations (specified)
      //## Operation: SignalsToSetpoints%988274711
      void SignalsToSetpoints ();

      //## Operation: StoreActuators%988274712
      void StoreActuators () const;

      //## Operation: RestoreActuators%988274713
      void RestoreActuators ();

      //## Operation: SetResponseMatrix%988274714
      void SetResponseMatrix (const RealMatrix& M);

      //## Operation: SetGain%988274715
      void SetGain (double g);

      //## Operation: GetGain%988274716
      double GetGain () const;

      //## Operation: Apply%988274717
      void Apply ();

      //## Operation: SetSetpoints%988274718
      void SetSetpoints (const RealVector& S0);

      //## Operation: GetActuatorRMS%988274719
      double GetActuatorRMS () const;

      //## Operation: GetSignalRMS%988274720
      double GetSignalRMS () const;

      //## Operation: GetNumSignals%988274721
      int GetNumSignals () const;

      //## Operation: GetNumActuators%988274722
      int GetNumActuators () const;

	  void SetPulseDelay(int n);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: gain%3AE822B4035C
      //## begin LinearFBSystem::gain%3AE822B4035C.attr preserve=no  private: double {UA} 
      double gain;
      //## end LinearFBSystem::gain%3AE822B4035C.attr

    // Data Members for Associations

      //## Association: Merlin::Corrections::<unnamed>%3AE8223801FE
      //## Role: LinearFBSystem::signals%3AE82239006F
      //## begin LinearFBSystem::signals%3AE82239006F.role preserve=no  private: ROChannelArray { -> VHAN}
      ROChannelArray signals;
      //## end LinearFBSystem::signals%3AE82239006F.role

      //## Association: Merlin::Corrections::<unnamed>%3AE8224F0352
      //## Role: LinearFBSystem::actuators%3AE8225001CD
      //## begin LinearFBSystem::actuators%3AE8225001CD.role preserve=no  private: RWChannelArray { -> VHAN}
      RWChannelArray actuators;
      //## end LinearFBSystem::actuators%3AE8225001CD.role

      //## Association: Merlin::Corrections::<unnamed>%3AE823AD01C2
      //## Role: LinearFBSystem::setpoints%3AE823AE006F
      //## begin LinearFBSystem::setpoints%3AE823AE006F.role preserve=no  private: RealVector { -> VHAN}
      RealVector setpoints;
      //## end LinearFBSystem::setpoints%3AE823AE006F.role

  private:  //## implementation
    //## Constructors (generated)
      LinearFBSystem(const LinearFBSystem &right);

    //## Assignment Operation (generated)
      const LinearFBSystem & operator=(const LinearFBSystem &right);

    // Data Members for Associations

      //## Association: Merlin::Corrections::<unnamed>%3AE828C90078
      //## Role: LinearFBSystem::cached_actuators%3AE828CA017C
      //## begin LinearFBSystem::cached_actuators%3AE828CA017C.role preserve=no  implementation: RealVector { -> 0..1VHANM}
      mutable RealVector* cached_actuators;
      //## end LinearFBSystem::cached_actuators%3AE828CA017C.role

	  // to allow for possible actuator pulse delays, we use a queue
	  mutable std::queue<RealVector>* actuatorQueue;

      //## Association: Merlin::Corrections::<unnamed>%3AE829BD0398
      //## Role: LinearFBSystem::Mi%3AE829BE01D7
      //## begin LinearFBSystem::Mi%3AE829BE01D7.role preserve=no  implementation: SVDMatrix< double > { -> 0..1VFHAN}
      SVDMatrix< double >* Mi;
      //## end LinearFBSystem::Mi%3AE829BE01D7.role

};

// Class LinearFBSystem 

//## begin module%3AE821F3008C.epilog preserve=yes
//## end module%3AE821F3008C.epilog


#endif

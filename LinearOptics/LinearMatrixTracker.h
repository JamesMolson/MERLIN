//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%3992D0F001EB.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\LinearOptics\LinearMatrixTracker.h
 * last modified 08/29/00 04:23:28 PM
 */
//## end module%3992D0F001EB.cm

//## begin module%3992D0F001EB.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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
//## end module%3992D0F001EB.cp

//## Module: LinearMatrixTracker%3992D0F001EB; Package specification
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Source file: C:\C++\Merlin\LinearOptics\LinearMatrixTracker.h

#ifndef LinearMatrixTracker_h
#define LinearMatrixTracker_h 1

//## begin module%3992D0F001EB.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3992D0F001EB.additionalIncludes

//## begin module%3992D0F001EB.includes preserve=yes
//## end module%3992D0F001EB.includes

// Tracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"
// MatrixMaps
#include "BasicTransport/MatrixMaps.h"
//## begin module%3992D0F001EB.additionalDeclarations preserve=yes
//## end module%3992D0F001EB.additionalDeclarations


//## Class: LinearMatrixTracker%3992C7B201B7
//	A tracker which updates the local liner R matrix as the
//	model is tracked. All non-linear elements are ignored.
//## Category: Merlin::LinearOptics%3992C77E011C
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3992C9650021;RectMultipoleRmtrxI { -> }
//## Uses: <unnamed>%3992C96601FA;SectorBendRmtrxI { -> }
//## Uses: <unnamed>%3992C967020F;DefaultRmtrxI { -> }
//## Uses: <unnamed>%3992C9680365;SWRFStructureRmtrxI { -> }
//## Uses: <unnamed>%3992C96A0065;TWRFStructureRmtrxI { -> }
//## Uses: <unnamed>%3992D15B018A;TransportMatrix { -> }

class LinearMatrixTracker : public ComponentTracker  //## Inherits: <unnamed>%3992C7BD009A
{
  public:
    //## Constructors (specified)
      //## Operation: LinearMatrixTracker%3992CEEB03C8
      explicit LinearMatrixTracker (double p0, double qsign = 1, const RMtrx& R = RMtrx(IdentityMatrix(6)));


    //## Other Operations (specified)
      //## Operation: GetCurrentR1%3992CF5A0396
      //	Returns the current accumulate R matrix (R1).
      const RMtrx& GetCurrentR1 () const;

      //## Operation: GetCurrentR2%39ABB6D400FE
      //	Returns the update matrix R2.
      const RMtrx& GetCurrentR2 () const;

      //## Operation: ResetR2%39ABC63001E8
      //	Resets the R2 matrix to the Identity.
      void ResetR2 ();

  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::LinearOptics::<unnamed>%3993B869015C
      //## Role: LinearMatrixTracker::R1%3993B8690348
      //## begin LinearMatrixTracker::R1%3993B8690348.role preserve=no  private: RMtrx { -> VHgAN}
      RMtrx R1;
      //## end LinearMatrixTracker::R1%3993B8690348.role

      //## Association: Merlin::LinearOptics::<unnamed>%39ABC71F03E1
      //## Role: LinearMatrixTracker::R2%39ABC7200193
      //## begin LinearMatrixTracker::R2%39ABC7200193.role preserve=no  private: RMtrx { -> 1VHgAN}
      RMtrx R2;
      //## end LinearMatrixTracker::R2%39ABC7200193.role

  private: //## implementation
};

// Class LinearMatrixTracker 


//## Other Operations (inline)
//## Operation: GetCurrentR1%3992CF5A0396
inline const RMtrx& LinearMatrixTracker::GetCurrentR1 () const
{
  //## begin LinearMatrixTracker::GetCurrentR1%3992CF5A0396.body preserve=yes
	return R1;
  //## end LinearMatrixTracker::GetCurrentR1%3992CF5A0396.body
}

//## Operation: GetCurrentR2%39ABB6D400FE
inline const RMtrx& LinearMatrixTracker::GetCurrentR2 () const
{
  //## begin LinearMatrixTracker::GetCurrentR2%39ABB6D400FE.body preserve=yes
	return R2;
  //## end LinearMatrixTracker::GetCurrentR2%39ABB6D400FE.body
}

//## begin module%3992D0F001EB.epilog preserve=yes
//## end module%3992D0F001EB.epilog


#endif

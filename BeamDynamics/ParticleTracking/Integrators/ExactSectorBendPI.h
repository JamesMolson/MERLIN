//## begin module%3AE81A52021C.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\Integrators\ExactSectorBendPI.h
 * last modified 26/04/01 15:10:31
 */
//## end module%3AE81A52021C.cm

//## begin module%3AE81A52021C.cp preserve=no
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
//## end module%3AE81A52021C.cp

//## Module: ExactSectorBendPI%3AE81A52021C; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Source file: D:\dev\Merlin\BeamDynamics\ParticleTracking\Integrators\ExactSectorBendPI.h

#ifndef ExactSectorBendPI_h
#define ExactSectorBendPI_h 1

//## begin module%3AE81A52021C.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE81A52021C.additionalIncludes

//## begin module%3AE81A52021C.includes preserve=yes
//## end module%3AE81A52021C.includes

// StdIntegrators
#include "BeamDynamics/ParticleTracking/Integrators/StdIntegrators.h"
//## begin module%3AE81A52021C.declarations preserve=no
//## end module%3AE81A52021C.declarations

//## begin module%3AE81A52021C.additionalDeclarations preserve=yes
//## end module%3AE81A52021C.additionalDeclarations


//## Class: ExactSectorBendPI%3AE819E20334
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ExactSectorBendPI : public SectorBendPI  //## Inherits: <unnamed>%3AE819F20320
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%988274708
      //	Tracks a single step ds through the sector bend.
      virtual double TrackStep (double ds);

  protected:
  private:
  private:  //## implementation
};

// Class ExactSectorBendPI 

//## begin module%3AE81A52021C.epilog preserve=yes
//## end module%3AE81A52021C.epilog


#endif

//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3AE02F8102BC.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\Integrators\StdIntegrators.h
 * last modified 11/12/01 15:32:02
 */
//## end module%3AE02F8102BC.cm

//## begin module%3AE02F8102BC.cp preserve=no
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
//## end module%3AE02F8102BC.cp

//## Module: StdIntegrators%3AE02F8102BC; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\Integrators\StdIntegrators.h

#ifndef StdIntegrators_h
#define StdIntegrators_h 1

//## begin module%3AE02F8102BC.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE02F8102BC.additionalIncludes

//## begin module%3AE02F8102BC.includes preserve=yes
//## end module%3AE02F8102BC.includes

// SectorBend
#include "AcceleratorModel/StdComponent/SectorBend.h"
// RectMultipole
#include "AcceleratorModel/StdComponent/RectMultipole.h"
// SWRFStructure
#include "AcceleratorModel/StdComponent/SWRFStructure.h"
// TWRFStructure
#include "AcceleratorModel/StdComponent/TWRFStructure.h"
// Drift
#include "AcceleratorModel/StdComponent/Drift.h"
// Marker
#include "AcceleratorModel/StdComponent/Marker.h"
// MatrixMaps
#include "BasicTransport/MatrixMaps.h"
// TransportMatrix
#include "BasicTransport/TransportMatrix.h"
// ParticleBunchIntegrator
#include "BeamDynamics/ParticleTracking/ParticleBunchIntegrator.h"
// Monitor
#include "AcceleratorModel/StdComponent/Monitor.h"
// Solenoid
#include "AcceleratorModel/StdComponent/Solenoid.h"
//## begin module%3AE02F8102BC.additionalDeclarations preserve=yes
//## end module%3AE02F8102BC.additionalDeclarations


//## Class: DriftPI%36E7BBDD004F
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3729FA770348;TParticleI { -> }

class DriftPI : public TParticleI< Drift  >  //## Inherits: <unnamed>%36EE4DE20005
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3729F7BF00DD
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation
};

//## Class: TWRFStructurePI%36E7BBF20258
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%36EE778F0287;implementation: RMtrx { -> }
//## Uses: <unnamed>%36EE78610044;implementation: TransportMatrix { -> }
//## Uses: <unnamed>%3729FA800014;TParticleI { -> }

class TWRFStructurePI : public TParticleI< TWRFStructure  >  //## Inherits: <unnamed>%3B976B2900D4
{
  public:
    //## Constructors (specified)
      //## Operation: TWRFStructurePI%3B976C1E02FD
      explicit TWRFStructurePI (bool full_acc = true);


    //## Other Operations (specified)
      //## Operation: TrackStep%3729F7F800E7
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: useFullAcc%3B976B8A00AB
      //## begin TWRFStructurePI::useFullAcc%3B976B8A00AB.attr preserve=no  private: bool {UA} 
      bool useFullAcc;
      //## end TWRFStructurePI::useFullAcc%3B976B8A00AB.attr

  private: //## implementation
};

//## Class: SectorBendPI%36E7BC1E0305
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%36EE778B037C;implementation: RMtrx { -> }
//## Uses: <unnamed>%36EE7860002F;implementation: TransportMatrix { -> }
//## Uses: <unnamed>%3729FAA00096;TParticleI { -> }

class SectorBendPI : public TParticleI< SectorBend  >  //## Inherits: <unnamed>%36EE4E6A02F0
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3729F8340065
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:

    //## Other Operations (specified)
      //## Operation: ApplyPoleFaceRotation%37317D1A02D0
      //	Used to apply a linear pole face rotation to the current
      //	bunch.
      void ApplyPoleFaceRotation (double h, const SectorBend::PoleFace& pf);

  private:
  private: //## implementation
};

//## Class: RectMultipolePI%36E7BC0B0127
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: linear transport%36EE778E000F;implementation: RdpMtrx { -> }
//## Uses: <unnamed>%36EE786200C8;implementation: TransportMatrix { -> }
//## Uses: <unnamed>%3729FA9D019A;TParticleI { -> }

class RectMultipolePI : public TParticleI< RectMultipole  >  //## Inherits: <unnamed>%36EE4E4601CC
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3729F82701CD
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation
};

//## Class: MonitorPI%3729F76B0348
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3729FAA9017C;TParticleI { -> }

class MonitorPI : public TParticleI< Monitor  >  //## Inherits: <unnamed>%3729F78602BC
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3729F84603DF
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation
};

//## Class: SWRFStructurePI%3729FC1503CA
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3729FC3C005A;TParticleI { -> }

class SWRFStructurePI : public TParticleI< SWRFStructure  >  //## Inherits: <unnamed>%3729FC330208
{
  public:
    //## Constructors (specified)
      //## Operation: SWRFStructurePI%3B976C500038
      explicit SWRFStructurePI (bool full_acc = true);


    //## Other Operations (specified)
      //## Operation: TrackStep%37318E3B02BC
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: useFullAcc%3B976C48034D
      //## begin SWRFStructurePI::useFullAcc%3B976C48034D.attr preserve=no  private: bool {UA} 
      bool useFullAcc;
      //## end SWRFStructurePI::useFullAcc%3B976C48034D.attr

  private: //## implementation
};

//## Class: ExactRectMultipolePI%3969B88F0381
//	A special integrator that calculate the R matrix for the
//	linear terms exactly for each momenta. Note that this
//	method is considerably slower that using the default
//	second-order map method.
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Persistence: Transient
//## Cardinality/Multiplicity: n



class ExactRectMultipolePI : public TParticleI< RectMultipole  >  //## Inherits: <unnamed>%3969B8B100EB
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3969B9120285
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation
};

//## Class: SolenoidPI%3C1618690184
//## Category: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE03092012C
//## Subsystem: Merlin::BeamDynamics::ParticleTracking::Integrators%3AE02F770032
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3C16188101C5;Solenoid { -> }

class SolenoidPI : public TParticleI< Solenoid  >  //## Inherits: <unnamed>%3C161874039D
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%3C16189C0173
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds);

  protected:
  private:
  private: //## implementation
};

// Class DriftPI 

// Class TWRFStructurePI 

//## Operation: TWRFStructurePI%3B976C1E02FD
inline TWRFStructurePI::TWRFStructurePI (bool full_acc)
  //## begin TWRFStructurePI::TWRFStructurePI%3B976C1E02FD.initialization preserve=yes
  : useFullAcc(full_acc)
  //## end TWRFStructurePI::TWRFStructurePI%3B976C1E02FD.initialization
{
  //## begin TWRFStructurePI::TWRFStructurePI%3B976C1E02FD.body preserve=yes
  //## end TWRFStructurePI::TWRFStructurePI%3B976C1E02FD.body
}


// Class SectorBendPI 

// Class RectMultipolePI 

// Class MonitorPI 

// Class SWRFStructurePI 

//## Operation: SWRFStructurePI%3B976C500038
inline SWRFStructurePI::SWRFStructurePI (bool full_acc)
  //## begin SWRFStructurePI::SWRFStructurePI%3B976C500038.initialization preserve=yes
  : useFullAcc(full_acc)
  //## end SWRFStructurePI::SWRFStructurePI%3B976C500038.initialization
{
  //## begin SWRFStructurePI::SWRFStructurePI%3B976C500038.body preserve=yes
  //## end SWRFStructurePI::SWRFStructurePI%3B976C500038.body
}


// Class ExactRectMultipolePI 

// Class SolenoidPI 

//## begin module%3AE02F8102BC.epilog preserve=yes
class MarkerPI : public TParticleI< Marker  > {
public:
	virtual double TrackStep (double ds) { return 0; }
};

//## end module%3AE02F8102BC.epilog


#endif

//## begin module%3AE7DE2600BE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\CollimateParticleProcess.h
 * last modified 30/04/01 12:28:48
 */
//## end module%3AE7DE2600BE.cm

//## begin module%3AE7DE2600BE.cp preserve=no
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
//## end module%3AE7DE2600BE.cp

//## Module: CollimateParticleProcess%3AE7DE2600BE; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: D:\dev\Merlin\BeamDynamics\ParticleTracking\CollimateParticleProcess.h

#ifndef CollimateParticleProcess_h
#define CollimateParticleProcess_h 1

//## begin module%3AE7DE2600BE.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE7DE2600BE.additionalIncludes

//## begin module%3AE7DE2600BE.includes preserve=yes
#include <map>
//## end module%3AE7DE2600BE.includes

// ParticleBunchProcess
#include "BeamDynamics/ParticleTracking/ParticleBunchProcess.h"
// PSTypes
#include "BeamModel/PSTypes.h"
// MerlinException
#include "Exception/MerlinException.h"
//## begin module%3AE7DE2600BE.declarations preserve=no
//## end module%3AE7DE2600BE.declarations

//## begin module%3AE7DE2600BE.additionalDeclarations preserve=yes
#define COLL_AT_ENTRANCE 1
#define COLL_AT_CENTER 2
#define COLL_AT_EXIT 4
//## end module%3AE7DE2600BE.additionalDeclarations


//## Class: ExcessiveParticleLoss%3AE7F6A301B8
//	Exception thrown by CollimateParticleProcess, when
//	particle loss threshold is exceeded.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ExcessiveParticleLoss : public MerlinException  //## Inherits: <unnamed>%3AE7F6F102F8
{
  public:
    //## Constructors (specified)
      //## Operation: ExcessiveParticleLoss%988274700
      ExcessiveParticleLoss (const string& c_id, double threshold, size_t nlost, size_t nstart);

  protected:
  private:
  private:  //## implementation
};

//## Class: CollimateParticleProcess%36EE695100EA
//	A process which effectively collimates the particle
//	beam, given the aperture of the current  component.
//	Collimation within a component can occur at one or more
//	positions:
//
//	COLL_AT_ENTRANCE,
//	COLL_AT_CENTER,
//	COLL_AT_EXIT
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3965DD550338;Aperture { -> }
//## Uses: <unnamed>%3965E23700E6;PSvectorArray { -> }
//## Uses: <unnamed>%3AE7F72F0000;ExcessiveParticleLoss { -> }

class CollimateParticleProcess : public ParticleBunchProcess  //## Inherits: <unnamed>%3AE7D89E02BC
{
  public:
    //## Class: IDTBL%38B3F5780300
    //	Used to generate unique filenames for particle loss data
    //	files.
    //## Category: <Top Level>
    //## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef map<string,int> IDTBL;

  public:
    //## Constructors (specified)
      //## Operation: CollimateParticleProcess%935667561
      //	Constructor taking the collimation mode, and the output
      //	stream pointer to which to print the results. mode can
      //	be a logical OR combination of the collimation modes. A
      //	null pointer for osp (default) suppresses output.
      CollimateParticleProcess (int priority, int mode, std::ostream* osp = 0);

    //## Destructor (specified)
      //## Operation: ~CollimateParticleProcess%988274693
      ~CollimateParticleProcess ();


    //## Other Operations (specified)
      //## Operation: InitialiseProcess%935667562
      //	Initialise this process with the specified Bunch. If
      //	bunch is not a ParticleBunch object, the process becomes
      //	inactive.
      virtual void InitialiseProcess (Bunch& bunch);

      //## Operation: SetCurrentComponent%935667563
      //	Sets the current accelerator component.
      virtual void SetCurrentComponent (AcceleratorComponent& component);

      //## Operation: DoProcess%935667564
      //	Preform the process for the specified step ds.
      virtual void DoProcess (double ds);

      //## Operation: GetMaxAllowedStepSize%935667565
      //	Returns the current maximum step length for this process.
      virtual double GetMaxAllowedStepSize () const;

      //## Operation: CreateParticleLossFiles%951318005
      //	If flg is true, then files are generated containing the
      //	lost (collimated) particles. The file names have the
      //	form {fprefix.}type.id.n.loss, where the string fprefix
      //	is optional, type.id is the qualified name of the
      //	element where the particle loss occurs, and n is an
      //	occurrence count for like-named elements (starting with
      //	n=1).
      void CreateParticleLossFiles (bool flg, string fprefix = "");

      //## Operation: IndexParticles%988274691
      //	If index is true, then the initial  particles are
      //	sequential indexed (1..n). These index values for each
      //	particle are then maintained, and output during any
      //	particle output operation (as the first column). The
      //	indexing allows particles to be traced back to the
      //	original cooridinates.
      void IndexParticles (bool index);

	  void IndexParticles (list<size_t>& anIndex);

	  const list<size_t>& GetIndecies() const;

      //## Operation: SetLossThreshold%988274692
      //	Sets the threshold for particle loss before the process
      //	throws ParticleLossThreshold exception. The value is in
      //	% of the initial particle number (default = 100%).
      void SetLossThreshold (double losspc);

	  // Set the log stream for the process. A NULL pointer
	  // turns logging off.
	  void SetLogStream(std::ostream* anOs);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: cmode%37C53FBD037E
      //## begin CollimateParticleProcess::cmode%37C53FBD037E.attr preserve=no  private: int {UA} 
      int cmode;
      //## end CollimateParticleProcess::cmode%37C53FBD037E.attr

      //## Attribute: os%37C53CCD0083
      //## begin CollimateParticleProcess::os%37C53CCD0083.attr preserve=no  private: std::ostream* {UA} 
      std::ostream* os;
      //## end CollimateParticleProcess::os%37C53CCD0083.attr

      //## Attribute: file_prefix%38B3F73B013C
      //## begin CollimateParticleProcess::file_prefix%38B3F73B013C.attr preserve=no  private: string {UA} 
      string file_prefix;
      //## end CollimateParticleProcess::file_prefix%38B3F73B013C.attr

      //## Attribute: createLossFiles%38B3F7450321
      //## begin CollimateParticleProcess::createLossFiles%38B3F7450321.attr preserve=no  private: bool {UA} 
      bool createLossFiles;
      //## end CollimateParticleProcess::createLossFiles%38B3F7450321.attr

      //## Attribute: lossThreshold%3AE7E4D6028A
      //## begin CollimateParticleProcess::lossThreshold%3AE7E4D6028A.attr preserve=no  private: double {UA} 
      double lossThreshold;
      //## end CollimateParticleProcess::lossThreshold%3AE7E4D6028A.attr

    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::class details::<unnamed>%3AE7EC3D001E
      //## Role: CollimateParticleProcess::idtbl%3AE7EC3D02B2
      //## begin CollimateParticleProcess::idtbl%3AE7EC3D02B2.role preserve=no  private: CollimateParticleProcess::IDTBL { -> 1VHAN}
      IDTBL idtbl;
      //## end CollimateParticleProcess::idtbl%3AE7EC3D02B2.role

  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: DoCollimation%935667566
      void DoCollimation ();

      //## Operation: SetNextS%935667567
      void SetNextS ();

      //## Operation: DoOutput%936004767
      void DoOutput (const PSvectorArray& lostb, const list<size_t>& lost_i);

    // Data Members for Class Attributes

      //## Attribute: s_total%37C53CF301C8
      //## begin CollimateParticleProcess::s_total%37C53CF301C8.attr preserve=no  implementation: double {UA} 
      double s_total;
      //## end CollimateParticleProcess::s_total%37C53CF301C8.attr

      //## Attribute: s%37C545F10196
      //## begin CollimateParticleProcess::s%37C545F10196.attr preserve=no  implementation: double {UA} 
      double s;
      //## end CollimateParticleProcess::s%37C545F10196.attr

      //## Attribute: next_s%37C545F603CE
      //## begin CollimateParticleProcess::next_s%37C545F603CE.attr preserve=no  implementation: double {UA} 
      double next_s;
      //## end CollimateParticleProcess::next_s%37C545F603CE.attr

      //## Attribute: at_entr%37C545FB029F
      //## begin CollimateParticleProcess::at_entr%37C545FB029F.attr preserve=no  implementation: bool {UA} 
      bool at_entr;
      //## end CollimateParticleProcess::at_entr%37C545FB029F.attr

      //## Attribute: at_cent%37C549350211
      //## begin CollimateParticleProcess::at_cent%37C549350211.attr preserve=no  implementation: bool {UA} 
      bool at_cent;
      //## end CollimateParticleProcess::at_cent%37C549350211.attr

      //## Attribute: at_exit%37C5493A0254
      //## begin CollimateParticleProcess::at_exit%37C5493A0254.attr preserve=no  implementation: bool {UA} 
      bool at_exit;
      //## end CollimateParticleProcess::at_exit%37C5493A0254.attr

      //## Attribute: nstart%3AE7E27C0046
      //## begin CollimateParticleProcess::nstart%3AE7E27C0046.attr preserve=no  implementation: size_t {UA} 
      size_t nstart;
      //## end CollimateParticleProcess::nstart%3AE7E27C0046.attr

      //## Attribute: nlost%3AE7E287014A
      //## begin CollimateParticleProcess::nlost%3AE7E287014A.attr preserve=no  implementation: size_t {UA} 
      size_t nlost;
      //## end CollimateParticleProcess::nlost%3AE7E287014A.attr

    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::class details::<unnamed>%3AE7E556012C
      //## Role: CollimateParticleProcess::pindex%3AE7E5570079
      //	Particle indecies.
      //## begin CollimateParticleProcess::pindex%3AE7E5570079.role preserve=no  implementation: std::list< size_t > { -> 0..1VHAN}
      std::list< size_t >* pindex;
      //## end CollimateParticleProcess::pindex%3AE7E5570079.role

};

// Class ExcessiveParticleLoss 

// Class CollimateParticleProcess 


//## Other Operations (inline)
//## Operation: CreateParticleLossFiles%951318005
inline void CollimateParticleProcess::CreateParticleLossFiles (bool flg, string fprefix)
{
  //## begin CollimateParticleProcess::CreateParticleLossFiles%951318005.body preserve=yes
	createLossFiles = flg;
	file_prefix = fprefix;
  //## end CollimateParticleProcess::CreateParticleLossFiles%951318005.body
}

inline void CollimateParticleProcess::SetLogStream(std::ostream* anOs)
{
	os=anOs;
}

inline const list<size_t>& CollimateParticleProcess::GetIndecies() const
{
	return *pindex;
}

//## begin module%3AE7DE2600BE.epilog preserve=yes
//## end module%3AE7DE2600BE.epilog


#endif

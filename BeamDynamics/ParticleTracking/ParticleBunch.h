//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3981E43F01CC.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunch.h
 * last modified 03/12/01 16:41:26
 */
//## end module%3981E43F01CC.cm

//## begin module%3981E43F01CC.cp preserve=no
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
//## end module%3981E43F01CC.cp

//## Module: ParticleBunch%3981E43F01CC; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: C:\C++\Merlin\BeamDynamics\ParticleTracking\ParticleBunch.h

#ifndef ParticleBunch_h
#define ParticleBunch_h 1

//## begin module%3981E43F01CC.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3981E43F01CC.additionalIncludes

//## begin module%3981E43F01CC.includes preserve=yes
//## end module%3981E43F01CC.includes

// PSTypes
#include "BeamModel/PSTypes.h"
// Bunch
#include "BeamModel/Bunch.h"

class Transform3D;

//## begin module%3981E43F01CC.additionalDeclarations preserve=yes
//## end module%3981E43F01CC.additionalDeclarations


//## Class: Particle%3981E3C5005A
//	Representation of a particle.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n



typedef PSvector Particle;

//## Class: ParticleBunch%36E7A9C400ED
//	A Bunch which is represented by an ensemble of
//	(macro-)particles.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%372AF35800C8;PSvectorTransform3D { -> }
//## Uses: <unnamed>%3981E3D00082;Particle { -> }
//## Uses: <unnamed>%3981E8540212;ParticleBunch::iterator { -> }
//## Uses: <unnamed>%3981E8560046;ParticleBunch::const_iterator { -> }
//## Uses: <unnamed>%3ADEFA880064;Transform3D { -> F}
//## Uses: <unnamed>%3ADEFBAF01B8;PSvectorTransform3D { -> }

class ParticleBunch : public Bunch  //## Inherits: <unnamed>%3729CEDF00FA
{
  public:
    //## Class: iterator%3981E8020320
    //## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
    //## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    typedef PSvectorArray::iterator iterator;

    //## Class: const_iterator%3981E8090118
    //## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
    //## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    typedef PSvectorArray::const_iterator const_iterator;

    //## Constructors (specified)
      //## Operation: ParticleBunch%3729CB29024E
      //	Constructs a ParticleBunch using the specified momentum,
      //	total charge and the particle array. Note that on exit,
      //	particles is empty.
      ParticleBunch (double P0, double Q, PSvectorArray& particles);

      //## Operation: ParticleBunch%37C52E600015
      //	Read phase space vectors from specified input stream.
      ParticleBunch (double P0, double Q, std::istream& is);

      //## Operation: ParticleBunch%3ADEFD450370
      //	Constructs an empty ParticleBunch with the specified
      //	momentum P0 and charge per macro particle Qm (default =
      //	+1).
      ParticleBunch (double P0, double Qm = 1);


    //## Other Operations (specified)
      //## Operation: GetTotalCharge%3ADEEA5B0064
      //	Returns the total charge (in units of e).
      virtual double GetTotalCharge () const;

      //## Operation: GetMoments%3729CB5000C8
      virtual PSmoments& GetMoments (PSmoments& sigma) const;

      //## Operation: GetProjectedMoments%3729CB500136
      virtual PSmoments2D& GetProjectedMoments (PScoord u, PScoord v, PSmoments2D& sigma) const;

      //## Operation: GetCentroid%3729CB500172
      virtual PSvector& GetCentroid (PSvector& p) const;

      //## Operation: GetProjectedCentroid%3729CB5001A4
      virtual Point2D GetProjectedCentroid (PScoord u, PScoord v) const;

      //## Operation: AdjustRefMomentumToMean%3729CB500212
      //	Set the reference momentum to the mean (centroid)
      //	momentum of the bunch. Returns the new value in GeV/c.
      virtual double AdjustRefMomentumToMean ();

      //## Operation: AdjustRefMomentum%3B94E5990346
      //	Adjusts the reference moment by the relative dpp.
      virtual double AdjustRefMomentum (double dpp);

      //## Operation: AdjustRefTimeToMean%3729CB50024E
      //	Set the reference time to the mean (centroid) time of
      //	the bunch. Returns the new value in ct (meters).
      virtual double AdjustRefTimeToMean ();

      //## Operation: ProjectDistribution%3729CB5002BC
      //	Used to generate a 1-D profile of the bunch projected
      //	onto the specified coordinate. The total area of the
      //	historgram is normalised to unity.
      virtual Histogram& ProjectDistribution (PScoord axis, Histogram& hist) const;

      //## Operation: ApplyTransformation%3729CB50032A
      //	Apply the specified 3D coordinate transformation to the
      //	bunch. Returns true if successful (note that it may not
      //	be possible to apply a general 3D transformation to some
      //	concrete bunch representations).
      virtual bool ApplyTransformation (const Transform3D& t);

      //## Operation: SortByCT%3981E5C90154
      //	Sorts the particles into ascending ct order.
      void SortByCT ();

      //## Operation: Output%3729CB500280
      //	Output a bunch-model dependent representation to the
      //	specified stream.
      virtual void Output (std::ostream& os) const;

      //## Operation: AddParticle%3ADEEB65006E
      //	Add a (macro-)particle to the bunch.
      size_t AddParticle (const Particle& p);

      //## Operation: SetMacroParticleCharge%3ADEEB830104
      //	Sets the particle charge per macro-particle.
      void SetMacroParticleCharge (double q);

      //## Operation: begin%3981E564014A
      ParticleBunch::iterator begin ();

      //## Operation: end%3981E5880352
      ParticleBunch::iterator end ();

      //## Operation: push_back%3981E59602EE
      void push_back (const Particle& p);

      //## Operation: begin%3981E6470262
      ParticleBunch::const_iterator begin () const;

      //## Operation: end%3981E6A202DA
      ParticleBunch::const_iterator end () const;

      //## Operation: size%3981E7E5038E
      size_t size () const;

      //## Operation: erase%3981E94201D6
      ParticleBunch::iterator erase (ParticleBunch::iterator p);

      //## Operation: GetParticles%3981EEBC0118
      PSvectorArray& GetParticles ();

      //## Operation: GetParticles%3981EECE026C
      const PSvectorArray& GetParticles () const;

      //## Operation: FirstParticle%3B94E7A400B6
      //	Returns the first particle in the bunch.
      const Particle& FirstParticle () const;

      //## Operation: FirstParticle%3B94E7E80154
      Particle& FirstParticle ();

      //## Operation: SetCentroid%3C0B9CB50293
      //	Sets the centroid of the particle bunch to be exactly x0.
      void SetCentroid (const Particle& x0);

  public:
  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: qPerMP%3981E6F202F8
      //	Charge per macro-particle
      //## begin ParticleBunch::qPerMP%3981E6F202F8.attr preserve=no  private: double {UA} 
      double qPerMP;
      //## end ParticleBunch::qPerMP%3981E6F202F8.attr

    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::<unnamed>%3981E5250032
      //## Role: ParticleBunch::pArray%3981E5250034
      //## begin ParticleBunch::pArray%3981E5250034.role preserve=no  private: PSvectorArray { -> 1VHgAN}
      PSvectorArray pArray;
      //## end ParticleBunch::pArray%3981E5250034.role

  private: //## implementation
};

// Class ParticleBunch 


//## Other Operations (inline)
//## Operation: AddParticle%3ADEEB65006E
inline size_t ParticleBunch::AddParticle (const Particle& p)
{
  //## begin ParticleBunch::AddParticle%3ADEEB65006E.body preserve=yes
	pArray.push_back(p);
	return size();
  //## end ParticleBunch::AddParticle%3ADEEB65006E.body
}

//## Operation: SetMacroParticleCharge%3ADEEB830104
inline void ParticleBunch::SetMacroParticleCharge (double q)
{
  //## begin ParticleBunch::SetMacroParticleCharge%3ADEEB830104.body preserve=yes
	qPerMP = q;
	SetChargeSign(q);
  //## end ParticleBunch::SetMacroParticleCharge%3ADEEB830104.body
}

//## Operation: begin%3981E564014A
inline ParticleBunch::iterator ParticleBunch::begin ()
{
  //## begin ParticleBunch::begin%3981E564014A.body preserve=yes
	return pArray.begin();
  //## end ParticleBunch::begin%3981E564014A.body
}

//## Operation: end%3981E5880352
inline ParticleBunch::iterator ParticleBunch::end ()
{
  //## begin ParticleBunch::end%3981E5880352.body preserve=yes
	return pArray.end();
  //## end ParticleBunch::end%3981E5880352.body
}

//## Operation: push_back%3981E59602EE
inline void ParticleBunch::push_back (const Particle& p)
{
  //## begin ParticleBunch::push_back%3981E59602EE.body preserve=yes
	AddParticle(p);
  //## end ParticleBunch::push_back%3981E59602EE.body
}

//## Operation: begin%3981E6470262
inline ParticleBunch::const_iterator ParticleBunch::begin () const
{
  //## begin ParticleBunch::begin%3981E6470262.body preserve=yes
	return pArray.begin();
  //## end ParticleBunch::begin%3981E6470262.body
}

//## Operation: end%3981E6A202DA
inline ParticleBunch::const_iterator ParticleBunch::end () const
{
  //## begin ParticleBunch::end%3981E6A202DA.body preserve=yes
	return pArray.end();
  //## end ParticleBunch::end%3981E6A202DA.body
}

//## Operation: size%3981E7E5038E
inline size_t ParticleBunch::size () const
{
  //## begin ParticleBunch::size%3981E7E5038E.body preserve=yes
	return pArray.size();
  //## end ParticleBunch::size%3981E7E5038E.body
}

//## Operation: erase%3981E94201D6
inline ParticleBunch::iterator ParticleBunch::erase (ParticleBunch::iterator p)
{
  //## begin ParticleBunch::erase%3981E94201D6.body preserve=yes
	return pArray.erase(p);
  //## end ParticleBunch::erase%3981E94201D6.body
}

//## Operation: GetParticles%3981EEBC0118
inline PSvectorArray& ParticleBunch::GetParticles ()
{
  //## begin ParticleBunch::GetParticles%3981EEBC0118.body preserve=yes
	return pArray;
  //## end ParticleBunch::GetParticles%3981EEBC0118.body
}

//## Operation: GetParticles%3981EECE026C
inline const PSvectorArray& ParticleBunch::GetParticles () const
{
  //## begin ParticleBunch::GetParticles%3981EECE026C.body preserve=yes
	return pArray;
  //## end ParticleBunch::GetParticles%3981EECE026C.body
}

//## Operation: FirstParticle%3B94E7A400B6
inline const Particle& ParticleBunch::FirstParticle () const
{
  //## begin ParticleBunch::FirstParticle%3B94E7A400B6.body preserve=yes
	return pArray.front();
  //## end ParticleBunch::FirstParticle%3B94E7A400B6.body
}

//## Operation: FirstParticle%3B94E7E80154
inline Particle& ParticleBunch::FirstParticle ()
{
  //## begin ParticleBunch::FirstParticle%3B94E7E80154.body preserve=yes
	return pArray.front();
  //## end ParticleBunch::FirstParticle%3B94E7E80154.body
}

//## begin module%3981E43F01CC.epilog preserve=yes
//## end module%3981E43F01CC.epilog


#endif

//## begin module%37147A940136.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamModel\Bunch.h
 * last modified 19/04/01 15:34:55
 */
//## end module%37147A940136.cm

//## begin module%37147A940136.cp preserve=no
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
//## end module%37147A940136.cp

//## Module: Bunch%37147A940136; Package specification
//## Subsystem: Merlin::BeamModel%3ACB10800370
//## Source file: D:\dev\Merlin\BeamModel\Bunch.h

#ifndef Bunch_h
#define Bunch_h 1

//## begin module%37147A940136.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37147A940136.additionalIncludes

//## begin module%37147A940136.includes preserve=yes
#include <iostream>
//## end module%37147A940136.includes

// ReferenceParticle
#include "BeamModel/ReferenceParticle.h"
// PSTypes
#include "BeamModel/PSTypes.h"
// Space2D
#include "EuclideanGeometry/Space2D.h"

class Transform3D;
class Histogram;

//## begin module%37147A940136.declarations preserve=no
//## end module%37147A940136.declarations

//## begin module%37147A940136.additionalDeclarations preserve=yes
//## end module%37147A940136.additionalDeclarations


//## Class: Bunch%3714721E02F8; Abstract
//	A charged particle bunch. Bunch fields a set of methods
//	for accessing certain macroscopic quantities of a single
//	bunch. An object of class Bunch represents an ensemble
//	of like particle only. Functions for accessing the full
//	six-dimensional phase space, as well as projection on a
//	single phase plane are provided. Concrete classes should
//	implement algorithm specific models of a bunch.
//## Category: Merlin::BeamModel%3ACB0C800384
//## Subsystem: Merlin::BeamModel%3ACB10800370
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%37147662012C;PSmoments2D { -> }
//## Uses: <unnamed>%371476630118;PSvector { -> }
//## Uses: <unnamed>%3714766400DC;PSmoments { -> }
//## Uses: <unnamed>%3714766500D2;Point2D { -> }
//## Uses: <unnamed>%3714766503D4;Transform3D { -> F}
//## Uses: <unnamed>%3727010B0384;Histogram { -> F}
//## Uses: <unnamed>%3727053202C6;PScoord { -> }

class Bunch : public ReferenceParticle  //## Inherits: <unnamed>%371472450366
{
  public:
    //## Constructors (specified)
      //## Operation: Bunch%924072854
      //	Constructor taking the initial reference momentum in Ge
      //	V/c, and the total charge/e of the bunch.
      Bunch (double p, double q);

    //## Destructor (specified)
      //## Operation: ~Bunch%924072855
      //	virtual destructor.
      virtual ~Bunch ();


    //## Other Operations (specified)
      //## Operation: GetTotalCharge%924072856
      //	Returns the total charge (in units of e).
      virtual double GetTotalCharge () const = 0;

      //## Operation: GetMoments%924072858
      virtual PSmoments& GetMoments (PSmoments& sigma) const = 0;

      //## Operation: GetProjectedMoments%924072859
      virtual PSmoments2D& GetProjectedMoments (PScoord u, PScoord v, PSmoments2D& sigma) const = 0;

      //## Operation: GetCentroid%924072860
      virtual PSvector& GetCentroid (PSvector& p) const = 0;

      //## Operation: GetProjectedCentroid%924072861
      virtual Point2D GetProjectedCentroid (PScoord u, PScoord v) const = 0;

      //## Operation: AdjustRefMomentumToMean%924072862
      //	Set the reference momentum to the mean (centroid)
      //	momentum of the bunch. Returns the new value in GeV/c.
      virtual double AdjustRefMomentumToMean () = 0;

      //## Operation: AdjustRefTimeToMean%924072863
      //	Set the reference time to the mean (centroid) time of
      //	the bunch. Returns the new value in ct (meters).
      virtual double AdjustRefTimeToMean () = 0;

      //## Operation: Output%924072864
      //	Output a bunch-model dependent representation to the
      //	specified stream.
      virtual void Output (std::ostream& os) const = 0;

      //## Operation: ProjectDistribution%924072865
      //	Used to generate a 1-D profile of the bunch projected
      //	onto the specified coordinate. The total area of the
      //	historgram is normalised to unity.
      virtual Histogram& ProjectDistribution (PScoord axis, Histogram& hist) const = 0;

      //## Operation: ApplyTransformation%924072866
      //	Apply the specified 3D coordinate transformation to the
      //	bunch. Returns true if successful (note that it may not
      //	be possible to apply a general 3D transformation to some
      //	concrete bunch representations).
      virtual bool ApplyTransformation (const Transform3D& t) = 0;

  protected:
  private:
  private:  //## implementation
};

// Class Bunch 

//## Operation: Bunch%924072854
inline Bunch::Bunch (double p, double q)
  //## begin Bunch::Bunch%924072854.initialization preserve=yes
  : ReferenceParticle(p,q)
  //## end Bunch::Bunch%924072854.initialization
{
  //## begin Bunch::Bunch%924072854.body preserve=yes
  //## end Bunch::Bunch%924072854.body
}


//## Operation: ~Bunch%924072855
inline Bunch::~Bunch ()
{
  //## begin Bunch::~Bunch%924072855.body preserve=yes
	// nothing to do.
  //## end Bunch::~Bunch%924072855.body
}


// Class Bunch 

//## begin module%37147A940136.epilog preserve=yes
//## end module%37147A940136.epilog


#endif


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin Bunch::GetTotalCharge%924072856.body preserve=no
	return 0;
//## end Bunch::GetTotalCharge%924072856.body

#endif

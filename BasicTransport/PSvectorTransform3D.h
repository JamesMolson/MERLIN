//## begin module%372ADFE502F8.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BasicTransport\PSvectorTransform3D.h
 * last modified 04/04/01 14:41:34
 */
//## end module%372ADFE502F8.cm

//## begin module%372ADFE502F8.cp preserve=no
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
//## end module%372ADFE502F8.cp

//## Module: PSvectorTransform3D%372ADFE502F8; Pseudo Package specification
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Source file: D:\dev\Merlin\BasicTransport\PSvectorTransform3D.h

#ifndef PSvectorTransform3D_h
#define PSvectorTransform3D_h 1

//## begin module%372ADFE502F8.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%372ADFE502F8.additionalIncludes

//## begin module%372ADFE502F8.includes preserve=yes
//## end module%372ADFE502F8.includes

// Transform3D
#include "EuclideanGeometry/Transform3D.h"
// PSTypes
#include "BeamModel/PSTypes.h"
//## begin module%372ADFE502F8.additionalDeclarations preserve=yes
//## end module%372ADFE502F8.additionalDeclarations


//## Class: PSvectorTransform3D%372ADFE502F8
//	Utility class for performing an arbitrary 3D coordinate
//	transformation on PSvector objects. The transformation
//	assumes that the particle(s) are fully relativistic.
//	Since small angle approximations are assumed, large
//	rotations about the x and y axis may lead to significant
//	errors.
//## Category: Merlin::BasicTransport%34797A9700F7; Global
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%372AE2810398;PSvector { -> }
//## Uses: <unnamed>%372AE2830352;PSvectorArray { -> }

class PSvectorTransform3D 
{
  public:
    //## Constructors (specified)
      //## Operation: PSvectorTransform3D%925557236
      PSvectorTransform3D (const Transform3D& tfrm);


    //## Other Operations (specified)
      //## Operation: Apply%925557237
      PSvector& Apply (PSvector& p) const;

      //## Operation: Apply%925557238
      PSvectorArray& Apply (PSvectorArray& pv) const;

      //## Operation: operator()%925557239
      PSvector& operator () (PSvector& p) const;

  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::BasicTransport::class details::<unnamed>%372AE13A0316
      //## Role: PSvectorTransform3D::T%372AE13B0154
      //## begin PSvectorTransform3D::T%372AE13B0154.role preserve=no  private: Transform3D { -> 1VHAN}
      Transform3D T;
      //## end PSvectorTransform3D::T%372AE13B0154.role

  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: bNoRot%372AE1C202DA
      //## begin PSvectorTransform3D::bNoRot%372AE1C202DA.attr preserve=no  implementation: bool {UA} 
      bool bNoRot;
      //## end PSvectorTransform3D::bNoRot%372AE1C202DA.attr

};

// Class PSvectorTransform3D 


//## Other Operations (inline)
//## Operation: operator()%925557239
inline PSvector& PSvectorTransform3D::operator () (PSvector& p) const
{
  //## begin PSvectorTransform3D::operator()%925557239.body preserve=yes
	return Apply(p);
  //## end PSvectorTransform3D::operator()%925557239.body
}

//## begin module%372ADFE502F8.epilog preserve=yes
//## end module%372ADFE502F8.epilog


#endif

//## begin module%371EFB710122.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\TemplateComponents.h
 * last modified 03/04/01 14:48:48
 */
//## end module%371EFB710122.cm

//## begin module%371EFB710122.cp preserve=no
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
//## end module%371EFB710122.cp

//## Module: TemplateComponents%371EFB710122; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\TemplateComponents.h

#ifndef TemplateComponents_h
#define TemplateComponents_h 1

//## begin module%371EFB710122.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%371EFB710122.additionalIncludes

//## begin module%371EFB710122.includes preserve=yes
//## end module%371EFB710122.includes

// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"
//## begin module%371EFB710122.declarations preserve=no
//## end module%371EFB710122.declarations

//## begin module%371EFB710122.additionalDeclarations preserve=yes
//## end module%371EFB710122.additionalDeclarations


//## Class: TAccCompG%371EF7EE03A2; Parameterized Class
//	Template class for generating general accelerator
//	components with geometry type G and no field.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class G>
class TAccCompG : public AcceleratorComponent  //## Inherits: <unnamed>%371EF9CE0398
{
  public:
    //## Class: geom_type%371EFAD600F0
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef G geom_type;

  public:
    //## Constructors (specified)
      //## Operation: TAccCompG%924771633
      TAccCompG (const string& id, G* geom, EMField* field = 0);

      //## Operation: TAccCompG%924771634
      TAccCompG (const TAccCompG<G>& rhs);


    //## Other Operations (specified)
      //## Operation: operator=%924771635
      TAccCompG<G>& operator = (const TAccCompG<G>& rhs);

      //## Operation: GetGeometry%924771636
      G& GetGeometry ();

      //## Operation: GetGeometry%924771637
      const G& GetGeometry () const;

  protected:
  private:
  private:  //## implementation
};

//## Class: TAccCompGF%371EEECE037A; Parameterized Class
//	Template class for generating general accelerator
//	components with geometry type G and field type F.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class G, class F>
class TAccCompGF : public TAccCompG<G>  //## Inherits: <unnamed>%371EF9D2010E
{
  public:
    //## Class: field_type%371EFB02030C
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef F field_type;

  public:
    //## Constructors (specified)
      //## Operation: TAccCompGF%924771620
      TAccCompGF (const string& id, G* geom, F* field);

      //## Operation: TAccCompGF%924771621
      TAccCompGF (const TAccCompGF<G,F>& rhs);


    //## Other Operations (specified)
      //## Operation: operator=%924771622
      TAccCompGF<G,F>& operator = (const TAccCompGF<G,F>& rhs);

      //## Operation: GetField%924771624
      F& GetField ();

      //## Operation: GetField%924771626
      const F& GetField () const;

  protected:
  private:
  private:  //## implementation
};

// Parameterized Class TAccCompG 

//## Operation: TAccCompG%924771633
template <class G>
inline TAccCompG<G>::TAccCompG (const string& id, G* geom, EMField* field)
  //## begin TAccCompG::TAccCompG%924771633.initialization preserve=yes
  : AcceleratorComponent(id,geom,field)
  //## end TAccCompG::TAccCompG%924771633.initialization
{
  //## begin TAccCompG::TAccCompG%924771633.body preserve=yes
  //## end TAccCompG::TAccCompG%924771633.body
}



//## Other Operations (inline)
//## Operation: GetGeometry%924771636
template <class G>
inline G& TAccCompG<G>::GetGeometry ()
{
  //## begin TAccCompG::GetGeometry%924771636.body preserve=yes
	return static_cast<G&>(*itsGeometry);
  //## end TAccCompG::GetGeometry%924771636.body
}

//## Operation: GetGeometry%924771637
template <class G>
inline const G& TAccCompG<G>::GetGeometry () const
{
  //## begin TAccCompG::GetGeometry%924771637.body preserve=yes
	return static_cast<const G&>(*itsGeometry);
  //## end TAccCompG::GetGeometry%924771637.body
}

// Parameterized Class TAccCompGF 

//## Operation: TAccCompGF%924771620
template <class G, class F>
inline TAccCompGF<G,F>::TAccCompGF (const string& id, G* geom, F* field)
  //## begin TAccCompGF::TAccCompGF%924771620.initialization preserve=yes
  : TAccCompG<G>(id,geom,field)
  //## end TAccCompGF::TAccCompGF%924771620.initialization
{
  //## begin TAccCompGF::TAccCompGF%924771620.body preserve=yes
  //## end TAccCompGF::TAccCompGF%924771620.body
}



//## Other Operations (inline)
//## Operation: GetField%924771624
template <class G, class F>
inline F& TAccCompGF<G,F>::GetField ()
{
  //## begin TAccCompGF::GetField%924771624.body preserve=yes
	return static_cast<F&>(*itsField);
  //## end TAccCompGF::GetField%924771624.body
}

//## Operation: GetField%924771626
template <class G, class F>
inline const F& TAccCompGF<G,F>::GetField () const
{
  //## begin TAccCompGF::GetField%924771626.body preserve=yes
	return static_cast<const F&>(*itsField);
  //## end TAccCompGF::GetField%924771626.body
}

// Parameterized Class TAccCompG 

//## Operation: TAccCompG%924771634
template <class G>
TAccCompG<G>::TAccCompG (const TAccCompG<G>& rhs)
  //## begin TAccCompG::TAccCompG%924771634.initialization preserve=yes
  : AcceleratorComponent(rhs.GetName(),new G(rhs.GetGeometry()),0)
  //## end TAccCompG::TAccCompG%924771634.initialization
{
  //## begin TAccCompG::TAccCompG%924771634.body preserve=yes
  //## end TAccCompG::TAccCompG%924771634.body
}



//## Other Operations (implementation)
//## Operation: operator=%924771635
template <class G>
TAccCompG<G>& TAccCompG<G>::operator = (const TAccCompG<G>& rhs)
{
  //## begin TAccCompG::operator=%924771635.body preserve=yes
	if(this!=&rhs) {
		SetName(rhs.GetName());
		GetGeometry() = rhs.GetGeometry();
	}
	return *this;
  //## end TAccCompG::operator=%924771635.body
}

// Parameterized Class TAccCompGF 

//## Operation: TAccCompGF%924771621
template <class G, class F>
TAccCompGF<G,F>::TAccCompGF (const TAccCompGF<G,F>& rhs)
  //## begin TAccCompGF::TAccCompGF%924771621.initialization preserve=yes
  : TAccCompG<G>(rhs.GetName(),new G(rhs.GetGeometry()), new F(rhs.GetField()))
  //## end TAccCompGF::TAccCompGF%924771621.initialization
{
  //## begin TAccCompGF::TAccCompGF%924771621.body preserve=yes
  //## end TAccCompGF::TAccCompGF%924771621.body
}



//## Other Operations (implementation)
//## Operation: operator=%924771622
template <class G, class F>
TAccCompGF<G,F>& TAccCompGF<G,F>::operator = (const TAccCompGF<G,F>& rhs)
{
  //## begin TAccCompGF::operator=%924771622.body preserve=yes
	if(this!=&rhs) {
		TAccCompG<G>::operator=(rhs);
		GetField() = rhs.GetField();
	}
	return *this;
  //## end TAccCompGF::operator=%924771622.body
}

//## begin module%371EFB710122.epilog preserve=yes
//## end module%371EFB710122.epilog


#endif

//## begin module%390811260231.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file AcceleratorModel\ComplexGeometry\TComponentFrame.h
 * last modified 04/27/00  12:17:25
 */
//## end module%390811260231.cm

//## begin module%390811260231.cp preserve=no
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
//## end module%390811260231.cp

//## Module: TComponentFrame%390811260231; Pseudo Package specification
//## Subsystem: AcceleratorModel::ComplexGeometry%3753E85E0078
//## Source file: C:\C++\Merlin\AcceleratorModel\ComplexGeometry\TComponentFrame.h

#ifndef TComponentFrame_h
#define TComponentFrame_h 1

//## begin module%390811260231.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%390811260231.additionalIncludes

//## begin module%390811260231.includes preserve=yes
#include <iostream>
//## end module%390811260231.includes

// ComponentFrame
#include "AcceleratorModel/Frames/ComponentFrame.h"
//## begin module%390811260231.additionalDeclarations preserve=yes
//## end module%390811260231.additionalDeclarations


//## Class: TComponentFrame%390811260231; Parameterized Class
//	A Typed ComponentFrame. Used to construct Accelerator
//	Component type specific ComponentFrame objects.
//## Category: AcceleratorModel::ComplexGeometry%3753E85E0078
//## Subsystem: AcceleratorModel::ComplexGeometry%3753E85E0078
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class T>
class TComponentFrame : public ComponentFrame  //## Inherits: <unnamed>%39081137002D
{
  public:
    //## Class: ComponentType%390811BA00A4
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef T ComponentType;

  public:
    //## Constructors (specified)
      //## Operation: TComponentFrame%956820769
      //	Constructor.
      explicit TComponentFrame (T& component);


    //## Other Operations (specified)
      //## Operation: GetComponent%956820770
      T& GetComponent ();

      //## Operation: GetComponent%956820771
      const T& GetComponent () const;

      //## Operation: operator->%956820772
      T* operator -> ();

      //## Operation: operator->%956820773
      const T* operator -> () const;

      //## Operation: Copy%956820774
      //	Returns a copy of this ComponentFrame. Note that only
      //	the reference to the AcceleratorComponent is copied, not
      //	the AcceleratorComponent itself.
      virtual ModelElement* Copy () const;

  protected:
  private:
  private:  //## implementation
};

// Parameterized Class TComponentFrame 

//## Operation: TComponentFrame%956820769
template <class T>
inline TComponentFrame<T>::TComponentFrame (T& component)
  //## begin TComponentFrame::TComponentFrame%956820769.initialization preserve=yes
  : ComponentFrame(component)
  //## end TComponentFrame::TComponentFrame%956820769.initialization
{
  //## begin TComponentFrame::TComponentFrame%956820769.body preserve=yes
  //## end TComponentFrame::TComponentFrame%956820769.body
}



//## Other Operations (inline)
//## Operation: GetComponent%956820770
template <class T>
inline T& TComponentFrame<T>::GetComponent ()
{
  //## begin TComponentFrame::GetComponent%956820770.body preserve=yes
	return *static_cast<T*>(theComponent);
  //## end TComponentFrame::GetComponent%956820770.body
}

//## Operation: GetComponent%956820771
template <class T>
inline const T& TComponentFrame<T>::GetComponent () const
{
  //## begin TComponentFrame::GetComponent%956820771.body preserve=yes
	return *static_cast<const T*>(theComponent);
  //## end TComponentFrame::GetComponent%956820771.body
}

//## Operation: operator->%956820772
template <class T>
inline T* TComponentFrame<T>::operator -> ()
{
  //## begin TComponentFrame::operator->%956820772.body preserve=yes
	return static_cast<T*>(theComponent);
  //## end TComponentFrame::operator->%956820772.body
}

//## Operation: operator->%956820773
template <class T>
inline const T* TComponentFrame<T>::operator -> () const
{
  //## begin TComponentFrame::operator->%956820773.body preserve=yes
	return static_cast<const T*>(theComponent);
  //## end TComponentFrame::operator->%956820773.body
}

//## Operation: Copy%956820774
template <class T>
inline ModelElement* TComponentFrame<T>::Copy () const
{
  //## begin TComponentFrame::Copy%956820774.body preserve=yes
	return new TComponentFrame<T>(*this);
  //## end TComponentFrame::Copy%956820774.body
}

// Parameterized Class TComponentFrame 

//## begin module%390811260231.epilog preserve=yes
//## end module%390811260231.epilog


#endif

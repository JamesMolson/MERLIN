//## begin module%3ACB27F7035C.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\ActiveMonitors\AMBufferManager.h
 * last modified 04/04/01 17:27:14
 */
//## end module%3ACB27F7035C.cm

//## begin module%3ACB27F7035C.cp preserve=no
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
//## end module%3ACB27F7035C.cp

//## Module: AMBufferManager%3ACB27F7035C; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
//## Source file: D:\dev\Merlin\AcceleratorModel\ActiveMonitors\AMBufferManager.h

#ifndef AMBufferManager_h
#define AMBufferManager_h 1

//## begin module%3ACB27F7035C.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3ACB27F7035C.additionalIncludes

//## begin module%3ACB27F7035C.includes preserve=yes
#include <set>
#include <algorithm>
#include <cassert>
//## end module%3ACB27F7035C.includes

//## begin module%3ACB27F7035C.additionalDeclarations preserve=yes
//## end module%3ACB27F7035C.additionalDeclarations


//## Class: AMBufferManager%3ACB27F7035C; Parameterized Class
//	Template class for managing active diagnotic buffers.
//	The template M should be a diagnostic type defining a
//	type M::Data and a type M::Buffer. M::Buffer should
//	supply the following method:
//
//	void M::Buffer::Record(const M&, const M::Data&)
//## Category: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class M, class B, class D>
class AMBufferManager 
{
  public:

    //## Other Operations (specified)
      //## Operation: AddBuffer%986385726
      //	Add the specified buffer.
      void AddBuffer (B* buf);

      //## Operation: RemoveBuffer%986385727
      //	Remove buf from the buffer list, if it exisits. Returns
      //	true if successful.
      bool RemoveBuffer (B* buf);

      //## Operation: ClearAllBuffers%986385728
      //	Remove all buffers (not including the default buffer).
      void ClearAllBuffers ();

      //## Operation: SetDefaultBuffer%986385729
      //	Sets the default buffer for all diagnostics of type M.
      static void SetDefaultBuffer (B* buf);

      //## Operation: SendToBuffers%986385730
      //	Sends the data to all the buffers.
      void SendToBuffers (const M& monitor, const D& data);

      //## Operation: empty%986385733
      //	Returns true if there are no buffers.
      bool empty () const;

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: buffers%3ACB2A3C01A4
      //## begin AMBufferManager::buffers%3ACB2A3C01A4.attr preserve=no  private: std::set<B*> {UA} 
      std::set<B*> buffers;
      //## end AMBufferManager::buffers%3ACB2A3C01A4.attr

      //## Attribute: defBuffer%3ACB2A4B035C
      //## begin AMBufferManager::defBuffer%3ACB2A4B035C.attr preserve=no  private: static B* {VA} 0
      static B* defBuffer;
      //## end AMBufferManager::defBuffer%3ACB2A4B035C.attr

  private:  //## implementation
};

// Parameterized Class AMBufferManager 


//## Other Operations (inline)
//## Operation: empty%986385733
template <class M, class B, class D>
inline bool AMBufferManager<M,B,D>::empty () const
{
  //## begin AMBufferManager::empty%986385733.body preserve=yes
	return defBuffer==0 && buffers.empty();
  //## end AMBufferManager::empty%986385733.body
}

// Parameterized Class AMBufferManager 


//## begin AMBufferManager::defBuffer%3ACB2A4B035C.attr preserve=no  private: static B* {VA} 0
template <class M, class B, class D>
B* AMBufferManager<M,B,D>::defBuffer = 0;
//## end AMBufferManager::defBuffer%3ACB2A4B035C.attr


//## Other Operations (implementation)
//## Operation: AddBuffer%986385726
template <class M, class B, class D>
void AMBufferManager<M,B,D>::AddBuffer (B* buf)
{
  //## begin AMBufferManager::AddBuffer%986385726.body preserve=yes
	buffers.insert(buf);
  //## end AMBufferManager::AddBuffer%986385726.body
}

//## Operation: RemoveBuffer%986385727
template <class M, class B, class D>
bool AMBufferManager<M,B,D>::RemoveBuffer (B* buf)
{
  //## begin AMBufferManager::RemoveBuffer%986385727.body preserve=yes
#ifndef NDEBUG
	int n = buffers.erase(buf);
	assert(n==0||n==1);
	return n==1;
#else
	return buffers.erase(buf)!=0;
#endif
  //## end AMBufferManager::RemoveBuffer%986385727.body
}

//## Operation: ClearAllBuffers%986385728
template <class M, class B, class D>
void AMBufferManager<M,B,D>::ClearAllBuffers ()
{
  //## begin AMBufferManager::ClearAllBuffers%986385728.body preserve=yes
	buffers.clear();
  //## end AMBufferManager::ClearAllBuffers%986385728.body
}

//## Operation: SetDefaultBuffer%986385729
template <class M, class B, class D>
void AMBufferManager<M,B,D>::SetDefaultBuffer (B* buf)
{
  //## begin AMBufferManager::SetDefaultBuffer%986385729.body preserve=yes
	defBuffer = buf;
  //## end AMBufferManager::SetDefaultBuffer%986385729.body
}

//## Operation: SendToBuffers%986385730
template <class M, class B, class D>
void AMBufferManager<M,B,D>::SendToBuffers (const M& monitor, const D& data)
{
  //## begin AMBufferManager::SendToBuffers%986385730.body preserve=yes
	if(defBuffer!=0)
		defBuffer->Record(monitor,data);
	for(std::set<B*>::iterator b=buffers.begin(); b!=buffers.end(); b++)
		(*b)->Record(monitor,data);
  //## end AMBufferManager::SendToBuffers%986385730.body
}

//## begin module%3ACB27F7035C.epilog preserve=yes
//## end module%3ACB27F7035C.epilog


#endif

//## begin module%3A9BCEC202C6.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\IndirectChannels.h
 * last modified 05/04/01 16:59:44
 */
//## end module%3A9BCEC202C6.cm

//## begin module%3A9BCEC202C6.cp preserve=no
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
//## end module%3A9BCEC202C6.cp

//## Module: IndirectChannels%3A9BCEC202C6; Package specification
//## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\IndirectChannels.h

#ifndef IndirectChannels_h
#define IndirectChannels_h 1

//## begin module%3A9BCEC202C6.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3A9BCEC202C6.additionalIncludes

//## begin module%3A9BCEC202C6.includes preserve=yes
//## end module%3A9BCEC202C6.includes

// ChannelServer
#include "AcceleratorModel/Implementation/ChannelServer.h"
// Channels
#include "Channels/Channels.h"

template <class E> class TIRWChannel;

//## begin module%3A9BCEC202C6.declarations preserve=no
//## end module%3A9BCEC202C6.declarations

//## begin module%3A9BCEC202C6.additionalDeclarations preserve=yes
//## end module%3A9BCEC202C6.additionalDeclarations


//## Class: TIC_ctor%3A98F2BB0014; Parameterized Class
//	Template class for constructing TIRWChannel objects for
//	specific ModelElement types.
//## Category: Merlin::AcceleratorModel::Implementation%39059A9B0090
//## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: constructs%3A98F4B4003C;TIRWChannel { -> F}

template <class E>
class TIC_ctor : public ChannelServer::ChannelCtor  //## Inherits: <unnamed>%3A98F2D301D6
{
  public:
    //## Class: element_type%3A9BFD3602E4
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef E element_type;

    //## Class: read_f%3A9BFD3E01EA
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef double (E::* read_f)() const;

    //## Class: write_f%3A9BFD470000
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef void (E::* write_f)(double);

  public:
    //## Constructors (specified)
      //## Operation: TIC_ctor%983275430
      TIC_ctor (const string& aType, const string& aKey, read_f rmf, write_f wmf = 0);


    //## Other Operations (specified)
      //## Operation: ConstructRO%986466255
      //	Constructs a channel for the specified ModelElement.
      virtual ROChannel* ConstructRO (ModelElement* anElement);

      //## Operation: ConstructRW%983275428
      //	Constructs a channel for the specified ModelElement.
      virtual RWChannel* ConstructRW (ModelElement* anElement);

      //## Operation: ReadFrom%983275426
      double ReadFrom (const E* elmnt);

      //## Operation: WriteTo%983275427
      void WriteTo (E* elmnt, double value);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: r_f%3A9BFE390262
      //## begin TIC_ctor::r_f%3A9BFE390262.attr preserve=no  private: read_f {UA} 
      read_f r_f;
      //## end TIC_ctor::r_f%3A9BFE390262.attr

      //## Attribute: w_f%3A9BFE4301B8
      //## begin TIC_ctor::w_f%3A9BFE4301B8.attr preserve=no  private: write_f {UA} 
      write_f w_f;
      //## end TIC_ctor::w_f%3A9BFE4301B8.attr

  private:  //## implementation
};

//## Class: TIRWChannel%3A98EBDF0226; Parameterized Class
//	Template class for constructing a concrete Indirect
//	RWChannel object. E can be any concrete ModelElement
//	type, which has set- and get-like member functions to
//	the associated parameter. The functions must have the
//	following signiture:
//
//	get: double (E::*)() const
//	set: void (E::*)(double)
//## Category: Merlin::AcceleratorModel::Implementation%39059A9B0090
//## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class E>
class TIRWChannel : public RWChannel  //## Inherits: <unnamed>%3A98EBF4005A
{
  public:
    //## Class: ch_ctor%3A9C03520168; Instantiated Class
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef TIC_ctor< E > ch_ctor;

  public:
    //## Constructors (specified)
      //## Operation: TIRWChannel%983275429
      TIRWChannel (E* element, TIC_ctor<E>* proto_f);


    //## Other Operations (specified)
      //## Operation: GetID%983275421
      //	Returns the ID of the channel (parameter).
      virtual string GetID () const;

      //## Operation: Read%983275422
      //	Returns the current value of the parameter/attribute
      //	associated with the channel.
      virtual double Read () const;

      //## Operation: Write%983275423
      //	Sets the current value of the parameter/attribute
      //	associated with the channel.
      virtual void Write (double value);

      //## Operation: Increment%983275424
      //	Increments the current value of the parameter/attribute
      //	associated with the channel. Returns the final
      //	(incremented) value.
      virtual double Increment (double delta);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: theElement%3A9BD24F0014
      //## begin TIRWChannel::theElement%3A9BD24F0014.attr preserve=no  private: E* {UA} 
      E* theElement;
      //## end TIRWChannel::theElement%3A9BD24F0014.attr

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Implementation::<unnamed>%3A9BFE870000
      //## Role: TIRWChannel::fp%3A9BFE870334
      //## begin TIRWChannel::fp%3A9BFE870334.role preserve=no  private: TIRWChannel< E >::ch_ctor { -> 1RHAN}
      ch_ctor* fp;
      //## end TIRWChannel::fp%3A9BFE870334.role

  private:  //## implementation
};

// Parameterized Class TIC_ctor 

// Parameterized Class TIRWChannel 

// Parameterized Class TIC_ctor 



//## Operation: TIC_ctor%983275430
template <class E>
TIC_ctor<E>::TIC_ctor (const string& aType, const string& aKey, read_f rmf, write_f wmf)
  //## begin TIC_ctor::TIC_ctor%983275430.initialization preserve=yes
  : ChannelServer::ChannelCtor(aType,aKey),r_f(rmf),w_f(wmf)
  //## end TIC_ctor::TIC_ctor%983275430.initialization
{
  //## begin TIC_ctor::TIC_ctor%983275430.body preserve=yes
  //## end TIC_ctor::TIC_ctor%983275430.body
}



//## Other Operations (implementation)
//## Operation: ConstructRO%986466255
template <class E>
ROChannel* TIC_ctor<E>::ConstructRO (ModelElement* anElement)
{
  //## begin TIC_ctor::ConstructRO%986466255.body preserve=yes
	return ConstructRW(anElement);
  //## end TIC_ctor::ConstructRO%986466255.body
}

//## Operation: ConstructRW%983275428
template <class E>
RWChannel* TIC_ctor<E>::ConstructRW (ModelElement* anElement)
{
  //## begin TIC_ctor::ConstructRW%983275428.body preserve=yes
#ifndef NDEBUG
	E* eptr = dynamic_cast<E*>(anElement);
	assert(eptr); // bad cast!
	return new TIRWChannel<E>(static_cast<E*>(eptr),this);
#else
	return new TIRWChannel<E>(static_cast<E*>(anElement),this);
#endif
  //## end TIC_ctor::ConstructRW%983275428.body
}

//## Operation: ReadFrom%983275426
template <class E>
double TIC_ctor<E>::ReadFrom (const E* elmnt)
{
  //## begin TIC_ctor::ReadFrom%983275426.body preserve=yes
	return (elmnt->*r_f)();
  //## end TIC_ctor::ReadFrom%983275426.body
}

//## Operation: WriteTo%983275427
template <class E>
void TIC_ctor<E>::WriteTo (E* elmnt, double value)
{
  //## begin TIC_ctor::WriteTo%983275427.body preserve=yes
	(elmnt->*w_f)(value);
  //## end TIC_ctor::WriteTo%983275427.body
}

// Parameterized Class TIRWChannel 



//## Operation: TIRWChannel%983275429
template <class E>
TIRWChannel<E>::TIRWChannel (E* element, TIC_ctor<E>* proto_f)
  //## begin TIRWChannel::TIRWChannel%983275429.initialization preserve=yes
  : theElement(element),fp(proto_f)
  //## end TIRWChannel::TIRWChannel%983275429.initialization
{
  //## begin TIRWChannel::TIRWChannel%983275429.body preserve=yes
  //## end TIRWChannel::TIRWChannel%983275429.body
}



//## Other Operations (implementation)
//## Operation: GetID%983275421
template <class E>
string TIRWChannel<E>::GetID () const
{
  //## begin TIRWChannel::GetID%983275421.body preserve=yes
	return theElement->GetQualifiedName()+'.'+fp->GetKey();
  //## end TIRWChannel::GetID%983275421.body
}

//## Operation: Read%983275422
template <class E>
double TIRWChannel<E>::Read () const
{
  //## begin TIRWChannel::Read%983275422.body preserve=yes
	return fp->ReadFrom(theElement);
  //## end TIRWChannel::Read%983275422.body
}

//## Operation: Write%983275423
template <class E>
void TIRWChannel<E>::Write (double value)
{
  //## begin TIRWChannel::Write%983275423.body preserve=yes
	fp->WriteTo(theElement,value);
  //## end TIRWChannel::Write%983275423.body
}

//## Operation: Increment%983275424
template <class E>
double TIRWChannel<E>::Increment (double delta)
{
  //## begin TIRWChannel::Increment%983275424.body preserve=yes
	double v=fp->ReadFrom(theElement)+delta;
	fp->WriteTo(theElement,v);
	return v;
  //## end TIRWChannel::Increment%983275424.body
}

//## begin module%3A9BCEC202C6.epilog preserve=yes
//## end module%3A9BCEC202C6.epilog


#endif

//## begin module%3A9A403F03DE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\Channels\Channels.h
 * last modified 26/02/01 15:15:03
 */
//## end module%3A9A403F03DE.cm

//## begin module%3A9A403F03DE.cp preserve=no
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
//## end module%3A9A403F03DE.cp

//## Module: Channels%3A9A403F03DE; Package specification
//## Subsystem: Merlin::Channels%3A9A40300186
//## Source file: D:\dev\Merlin\Channels\Channels.h

#ifndef Channels_h
#define Channels_h 1

//## begin module%3A9A403F03DE.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3A9A403F03DE.additionalIncludes

//## begin module%3A9A403F03DE.includes preserve=yes
#include <vector>
#include <string>
#include <iostream>
//## end module%3A9A403F03DE.includes

// LinearAlgebra
#include "TLAS/LinearAlgebra.h"
//## begin module%3A9A403F03DE.declarations preserve=no
//## end module%3A9A403F03DE.declarations

//## begin module%3A9A403F03DE.additionalDeclarations preserve=yes
//## end module%3A9A403F03DE.additionalDeclarations


//## Class: ROChannel%3A97D82802D0; Abstract
//	A Read-Only Channel representing a constant floating
//	point attribute or parameter.
//## Category: Merlin::Channels%3A97D7D800FA
//## Subsystem: Merlin::Channels%3A9A40300186
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ROChannel 
{
  public:
    //## Destructor (specified)
      //## Operation: ~ROChannel%983187826
      virtual ~ROChannel ();


    //## Other Operations (specified)
      //## Operation: GetID%983187827
      //	Returns the ID of the channel (parameter).
      virtual std::string GetID () const = 0;

      //## Operation: Read%983187828
      //	Returns the current value of the parameter/attribute
      //	associated with the channel.
      virtual double Read () const = 0;

  protected:
  private:
  private:  //## implementation
};

//## Class: RWChannel%3A97D8320262; Abstract
//	A Read-Write Channel,  representing a single
//	floating-point attribute or parameter that can be
//	accessed (Read) or modified (Write).
//## Category: Merlin::Channels%3A97D7D800FA
//## Subsystem: Merlin::Channels%3A9A40300186
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class RWChannel : public ROChannel  //## Inherits: <unnamed>%3A97D8400230
{
  public:

    //## Other Operations (specified)
      //## Operation: Write%983187829
      //	Sets the current value of the parameter/attribute
      //	associated with the channel.
      virtual void Write (double value) = 0;

      //## Operation: Increment%983187830
      //	Increments the current value of the parameter/attribute
      //	associated with the channel. Returns the final
      //	(incremented) value.
      virtual double Increment (double delta);

  protected:
  private:
  private:  //## implementation
};

//## Class: ROChannelArray%3A97DB7201C2
//	A linear array (vector) of ROChannels. On destruction,
//	an ROChannelArray object will destroy its associated
//	channels.
//## Category: Merlin::Channels%3A97D7D800FA
//## Subsystem: Merlin::Channels%3A9A40300186
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: converts to%3A97DC46001E;RealVector { -> }
//## Uses: <unnamed>%3A9A44950366;deleter { -> }

class ROChannelArray 
{
  public:
    //## Constructors (specified)
      //## Operation: ROChannelArray%983187831
      //	Constructor taking a vector of ROChannel objects.
      explicit ROChannelArray (const std::vector<ROChannel*>& chnls);
	  ROChannelArray(ROChannelArray& rhs);
	  ROChannelArray ();
	
    //## Destructor (specified)
      //## Operation: ~ROChannelArray%983187832
      ~ROChannelArray ();


    //## Other Operations (specified)
      //## Operation: Read%983187833
      //	Reads the n-th channel.
      double Read (size_t n) const;

      //## Operation: ReadAll%983187834
      //	Reads all the channels and returns the results in vec.
      void ReadAll (RealVector& vec) const;

      //## Operation: operator RealVector%983187835
      //	Convertion to a RealVector (containing the current
      //	values of the channels).
      operator RealVector () const;

      //## Operation: Print%983187836
      //	Prints the vector as a two column table. Column 1
      //	contains the ID's of the channels; column 2 contains the
      //	current values.
      void Print (std::ostream& os) const;

      //## Operation: Size%983187845
      //	Returns the size of the array.
      size_t Size () const;

	  // Initialisation
	  size_t SetChannels(const std::vector<ROChannel*>& chnls);

  protected:
    //## Constructors (specified)
      //## Operation: ROChannelArray%983187837
      //	Protected constructing taking the size of the array.
      explicit ROChannelArray (size_t n);

	  void DestroyChannels();

    // Data Members for Associations

      //## Association: Merlin::Channels::<unnamed>%3A97DB8802EE
      //## Role: ROChannelArray::channels%3A97DB8901D7
      //## Constraints:
      //	ordered
      //## begin ROChannelArray::channels%3A97DB8901D7.role preserve=no  protected: ROChannel { -> 1..nVHOAN}
      std::vector<ROChannel*> channels;
      //## end ROChannelArray::channels%3A97DB8901D7.role

  private:
  private:  //## implementation
};

//## Class: RWChannelArray%3A97DB7C03AC
//	A linear array (vector) of RWChannels.
//## Category: Merlin::Channels%3A97D7D800FA
//## Subsystem: Merlin::Channels%3A9A40300186
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: converts to%3A97DC4803AC;RealVector { -> }

class RWChannelArray : public ROChannelArray  //## Inherits: <unnamed>%3A9909C301F4
{
  public:
    //## Constructors (specified)
      //## Operation: RWChannelArray%983187838
      //	Constructor taking a vector of RWChannels.
      explicit RWChannelArray (const std::vector<RWChannel*>& chnls);
	  RWChannelArray (RWChannelArray& rhs);
	  RWChannelArray ();

	  size_t SetChannels (const std::vector<RWChannel*>& chnls);


    //## Other Operations (specified)
      //## Operation: Write%983187839
      //	Write a value to the n-th channel.
      void Write (size_t n, double value);

      //## Operation: WriteAll%983187840
      //	Write the same value to all the channels.
      void WriteAll (double value);

      //## Operation: WriteAll%983187841
      //	Copy the vector to the channels.
      void WriteAll (const RealVector& values);

      //## Operation: Increment%983187848
      //	Increments the value of the n-th channel.
      void Increment (size_t n, double value);

      //## Operation: IncrementAll%983187846
      //	Increments  all the channels by the same value.
      void IncrementAll (double value);

      //## Operation: IncrementAll%983187847
      //	Increments the channels by the corresponding values in
      //	the supplied vector.
      void IncrementAll (const RealVector& values);

      //## Operation: operator=%983187842
      //	Copy assignment from a RealVector.
      void operator = (const RealVector& v);

  protected:
    // Data Members for Associations

      //## Association: Merlin::Channels::<unnamed>%3A9A3E2B00A0
      //## Role: RWChannelArray::channels%3A9A3E2B03D5
      //## Constraints:
      //	ordered
      //## begin RWChannelArray::channels%3A9A3E2B03D5.role preserve=no  protected: RWChannel { -> 1..nVHOADPN}
      //## end RWChannelArray::channels%3A9A3E2B03D5.role

  private:
  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: RWCh%983187843
      RWChannel* RWCh (size_t n);

      //## Operation: RWCh%983187844
      const RWChannel* RWCh (size_t n) const;

};

// Class ROChannel 

//## Operation: ~ROChannel%983187826
inline ROChannel::~ROChannel ()
{
  //## begin ROChannel::~ROChannel%983187826.body preserve=yes
  //## end ROChannel::~ROChannel%983187826.body
}


// Class RWChannel 


//## Other Operations (inline)
//## Operation: Increment%983187830
inline double RWChannel::Increment (double delta)
{
  //## begin RWChannel::Increment%983187830.body preserve=yes
	double v=Read()+delta;
	Write(v);
	return v;
  //## end RWChannel::Increment%983187830.body
}

// Class ROChannelArray 

//## Operation: ROChannelArray%983187831
inline ROChannelArray::ROChannelArray (const std::vector<ROChannel*>& chnls)
  //## begin ROChannelArray::ROChannelArray%983187831.initialization preserve=yes
  : channels(chnls)
  //## end ROChannelArray::ROChannelArray%983187831.initialization
{
  //## begin ROChannelArray::ROChannelArray%983187831.body preserve=yes
  //## end ROChannelArray::ROChannelArray%983187831.body
}

inline ROChannelArray::ROChannelArray(ROChannelArray& rhs)
: channels()
{
	channels.swap(rhs.channels);
}

//## Operation: ROChannelArray%983187837
inline ROChannelArray::ROChannelArray (size_t n)
  //## begin ROChannelArray::ROChannelArray%983187837.initialization preserve=yes
  : channels(n)
  //## end ROChannelArray::ROChannelArray%983187837.initialization
{
  //## begin ROChannelArray::ROChannelArray%983187837.body preserve=yes
  //## end ROChannelArray::ROChannelArray%983187837.body
}

inline ROChannelArray::ROChannelArray ()
{}

inline size_t ROChannelArray::SetChannels(const std::vector<ROChannel*>& chnls)
{
	DestroyChannels();
	channels = chnls;
	return channels.size();
}

//## Other Operations (inline)
//## Operation: Read%983187833
inline double ROChannelArray::Read (size_t n) const
{
  //## begin ROChannelArray::Read%983187833.body preserve=yes
	return channels[n]->Read();
  //## end ROChannelArray::Read%983187833.body
}

//## Operation: Size%983187845
inline size_t ROChannelArray::Size () const
{
  //## begin ROChannelArray::Size%983187845.body preserve=yes
	return channels.size();
  //## end ROChannelArray::Size%983187845.body
}

// Class RWChannelArray 


//## Other Operations (inline)
//## Operation: Write%983187839
inline void RWChannelArray::Write (size_t n, double value)
{
  //## begin RWChannelArray::Write%983187839.body preserve=yes
	RWCh(n)->Write(value);
  //## end RWChannelArray::Write%983187839.body
}

//## Operation: Increment%983187848
inline void RWChannelArray::Increment (size_t n, double value)
{
  //## begin RWChannelArray::Increment%983187848.body preserve=yes
	RWCh(n)->Increment(value);
  //## end RWChannelArray::Increment%983187848.body
}

//## Operation: operator=%983187842
inline void RWChannelArray::operator = (const RealVector& v)
{
  //## begin RWChannelArray::operator=%983187842.body preserve=yes
	WriteAll(v);
  //## end RWChannelArray::operator=%983187842.body
}

//## Operation: RWCh%983187843
inline RWChannel* RWChannelArray::RWCh (size_t n)
{
  //## begin RWChannelArray::RWCh%983187843.body preserve=yes
	return static_cast<RWChannel*>(channels[n]);
  //## end RWChannelArray::RWCh%983187843.body
}

//## Operation: RWCh%983187844
inline const RWChannel* RWChannelArray::RWCh (size_t n) const
{
  //## begin RWChannelArray::RWCh%983187844.body preserve=yes
	return static_cast<const RWChannel*>(channels[n]);
  //## end RWChannelArray::RWCh%983187844.body
}

// Class ROChannel 


// Class RWChannel 


//## begin module%3A9A403F03DE.epilog preserve=yes
//## end module%3A9A403F03DE.epilog


#endif

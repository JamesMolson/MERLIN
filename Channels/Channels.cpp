//## begin module%3A9A404202E4.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\Channels\Channels.cpp
 * last modified 26/02/01 15:15:02
 */
//## end module%3A9A404202E4.cm

//## begin module%3A9A404202E4.cp preserve=no
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
//## end module%3A9A404202E4.cp

//## Module: Channels%3A9A404202E4; Package body
//## Subsystem: Merlin::Channels%3A9A40300186
//## Source file: D:\dev\Merlin\Channels\Channels.cpp

//## begin module%3A9A404202E4.includes preserve=yes
#include <algorithm>
#include <iomanip>
//## end module%3A9A404202E4.includes

// deleters
#include "stdext/deleters.h"
// Channels
#include "Channels/Channels.h"
//## begin module%3A9A404202E4.declarations preserve=no
//## end module%3A9A404202E4.declarations

//## begin module%3A9A404202E4.additionalDeclarations preserve=yes
#include <algorithm>
//## end module%3A9A404202E4.additionalDeclarations


// Class ROChannelArray 


//## Operation: ~ROChannelArray%983187832
ROChannelArray::~ROChannelArray ()
{
  //## begin ROChannelArray::~ROChannelArray%983187832.body preserve=yes
	DestroyChannels();
  //## end ROChannelArray::~ROChannelArray%983187832.body
}

void ROChannelArray::DestroyChannels()
{
	for_each(channels.begin(),channels.end(),deleter<ROChannel>());
}

//## Other Operations (implementation)
//## Operation: ReadAll%983187834
void ROChannelArray::ReadAll (RealVector& vec) const
{
  //## begin ROChannelArray::ReadAll%983187834.body preserve=yes
	assert(vec.size()==Size());
	for(size_t i=0; i<Size(); i++)
		vec[i]=channels[i]->Read();
  //## end ROChannelArray::ReadAll%983187834.body
}

//## Operation: operator RealVector%983187835
ROChannelArray::operator RealVector () const
{
  //## begin ROChannelArray::operator RealVector%983187835.body preserve=yes
	RealVector v(Size());
	ReadAll(v);
	return v;
  //## end ROChannelArray::operator RealVector%983187835.body
}

//## Operation: Print%983187836
void ROChannelArray::Print (std::ostream& os) const
{
  //## begin ROChannelArray::Print%983187836.body preserve=yes
	vector<string> idlist(Size());
	vector<double> vallist(Size());
	int n=0;
	size_t i;
	
	for(i=0; i<Size(); i++) {
		idlist[i]=channels[i]->GetID();
		vallist[i]=channels[i]->Read();
		if(n<idlist[i].length())
			n=idlist[i].length();
	}
	
	for(i=0; i<Size(); i++) {
		os<<std::setw(n)<<left<<idlist[i].c_str()<<" = ";
		os<<vallist[i]<<endl;
	}
  //## end ROChannelArray::Print%983187836.body
}

// Class RWChannelArray 


//## Operation: RWChannelArray%983187838
RWChannelArray::RWChannelArray (const std::vector<RWChannel*>& chnls)
  //## begin RWChannelArray::RWChannelArray%983187838.initialization preserve=yes
  : ROChannelArray(chnls.size())
  //## end RWChannelArray::RWChannelArray%983187838.initialization
{
  //## begin RWChannelArray::RWChannelArray%983187838.body preserve=yes
	std::copy(chnls.begin(),chnls.end(),channels.begin());
  //## end RWChannelArray::RWChannelArray%983187838.body
}

RWChannelArray::RWChannelArray(RWChannelArray& rhs)
: ROChannelArray(rhs.Size())
{
	std::copy(rhs.channels.begin(),rhs.channels.end(),channels.begin());
	rhs.channels.clear();
}
	
RWChannelArray::RWChannelArray ()
{}

size_t RWChannelArray::SetChannels (const std::vector<RWChannel*>& chnls)
{
	DestroyChannels();
	channels.resize(chnls.size());
	std::copy(chnls.begin(),chnls.end(),channels.begin());
	return channels.size();
}

//## Other Operations (implementation)
//## Operation: WriteAll%983187840
void RWChannelArray::WriteAll (double value)
{
  //## begin RWChannelArray::WriteAll%983187840.body preserve=yes
	for(size_t i=0; i<Size(); i++)
		RWCh(i)->Write(value);
  //## end RWChannelArray::WriteAll%983187840.body
}

//## Operation: WriteAll%983187841
void RWChannelArray::WriteAll (const RealVector& values)
{
  //## begin RWChannelArray::WriteAll%983187841.body preserve=yes
	assert(values.size()==Size());
	for(size_t i=0; i<Size(); i++)
		RWCh(i)->Write(values[i]);
  //## end RWChannelArray::WriteAll%983187841.body
}

//## Operation: IncrementAll%983187846
void RWChannelArray::IncrementAll (double value)
{
  //## begin RWChannelArray::IncrementAll%983187846.body preserve=yes
	for(size_t i=0; i<Size(); i++)
		RWCh(i)->Increment(value);
  //## end RWChannelArray::IncrementAll%983187846.body
}

//## Operation: IncrementAll%983187847
void RWChannelArray::IncrementAll (const RealVector& values)
{
  //## begin RWChannelArray::IncrementAll%983187847.body preserve=yes
	assert(values.size()==Size());
	for(size_t i=0; i<Size(); i++)
		RWCh(i)->Increment(values[i]);
  //## end RWChannelArray::IncrementAll%983187847.body
}

//## begin module%3A9A404202E4.epilog preserve=yes
//## end module%3A9A404202E4.epilog

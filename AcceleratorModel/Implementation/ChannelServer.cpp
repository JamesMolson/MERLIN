//## begin module%3AC877460082.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\ChannelServer.cpp
 * last modified 05/04/01 17:05:02
 */
//## end module%3AC877460082.cm

//## begin module%3AC877460082.cp preserve=no
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
//## end module%3AC877460082.cp

//## Module: ChannelServer%3AC877460082; Package body
//## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\ChannelServer.cpp

//## begin module%3AC877460082.includes preserve=yes
#include <cassert>
//## end module%3AC877460082.includes

// ModelElement
#include "AcceleratorModel/ModelElement.h"
// ChannelServer
#include "AcceleratorModel/Implementation/ChannelServer.h"
// Channels
#include "Channels/Channels.h"
// StringPattern
#include "utility/StringPattern.h"


//## begin module%3AC877460082.declarations preserve=no
//## end module%3AC877460082.declarations

//## begin module%3AC877460082.additionalDeclarations preserve=yes
namespace {

	struct CHPath {

		string type;
		string id;
		string key;

		CHPath(const string& id);

		string typekey() const { 
			return type+'.'+key;
		}
		string eid() const {
			return type+'.'+id;
		}
	};

	CHPath::CHPath(const string& cid)
	{
		int n1=cid.find('.');
		type=cid.substr(0,n1);

		int n2=cid.find('.',n1+1);
		id=cid.substr(n1+1,n2-n1-1);

		key=cid.substr(n2+1);
	}


	struct TYPE_CMP {
		bool operator()(const ModelElement* e1, const ModelElement* e2) {
			return (*e1).GetType() < (*e2).GetType();
		}
	};

	struct FindType {
		string type;
		bool neg;

		FindType(const string& aType, bool negate=false)
			: type(aType),neg(negate) {}

		bool operator()(const ChannelServer::CtorTable::value_type& ctor) {
			bool ok = (ctor.second)->GetType() == type;
			return neg ? !ok : ok;
		}
	};
};
//## end module%3AC877460082.additionalDeclarations


// Class ChannelServer::ChannelCtor 





//## Other Operations (implementation)
//## Operation: GetID%983187850
std::string ChannelServer::ChannelCtor::GetID ()
{
  //## begin ChannelServer::ChannelCtor::GetID%983187850.body preserve=yes
	return type+'.'+key;
  //## end ChannelServer::ChannelCtor::GetID%983187850.body
}

// Class ChannelServer 






//## Other Operations (implementation)
//## Operation: GetROChannels%983187851
size_t ChannelServer::GetROChannels (const string& chID, std::vector<ROChannel*>& channels)
{
  //## begin ChannelServer::GetROChannels%983187851.body preserve=yes
	CHPath chpath(chID);
	vector<ModelElement*> elements;
	elements.reserve(8);
	
	FindElements(chpath.eid(),elements);
	if(elements.empty())
		return 0;

	set<ChannelCtor*> ctors;
	string etype="";
	int count=0;
	for(vector<ModelElement*>::iterator ei = elements.begin(); ei!=elements.end(); ei++) {
		
		// If we have a new type, get the corresponding constructors
		if(etype!=(*ei)->GetType()) {
			etype=(*ei)->GetType();
			FindCtors(etype,chpath.key,ctors);
			if(ctors.empty())
				break;
		}
		
		// Now construct the channels
		for(set<ChannelCtor*>::iterator ci = ctors.begin(); ci!=ctors.end(); ci++) {
			channels.push_back((*ci)->ConstructRO(*ei));
			count++;
		}
	}

	return count;
  //## end ChannelServer::GetROChannels%983187851.body
}

//## Operation: GetRWChannels%983275415
size_t ChannelServer::GetRWChannels (const string& chID, std::vector<RWChannel*>& channels)
{
  //## begin ChannelServer::GetRWChannels%983275415.body preserve=yes
	CHPath chpath(chID);
	vector<ModelElement*> elements;
	elements.reserve(8);
	
	FindElements(chpath.eid(),elements);
	if(elements.empty())
		return 0;

	set<ChannelCtor*> ctors;
	string etype="";
	int count=0;
	for(vector<ModelElement*>::iterator ei = elements.begin(); ei!=elements.end(); ei++) {
		
		// If we have a new type, get the corresponding constructors
		if(etype!=(*ei)->GetType()) {
			etype=(*ei)->GetType();
			FindCtors(etype,chpath.key,ctors);
			if(ctors.empty())
				break;
		}
		
		// Now construct the channels
		for(set<ChannelCtor*>::iterator ci = ctors.begin(); ci!=ctors.end(); ci++) {
			RWChannel* ch = (*ci)->ConstructRW(*ei);
			assert(ch!=0); // if(ch==0) throw ChannelIsRO(ch->GetID());
			channels.push_back(ch);
			count++;
		}
	}

	return count;
  //## end ChannelServer::GetRWChannels%983275415.body
}

//## Operation: RegisterCtor%983187853
void ChannelServer::RegisterCtor (ChannelCtor* chctor)
{
  //## begin ChannelServer::RegisterCtor%983187853.body preserve=yes
	pair<CtorTable::iterator,bool> rv = chCtors.insert(
		CtorTable::value_type(chctor->GetID(),chctor));
	assert(rv.second);
  //## end ChannelServer::RegisterCtor%983187853.body
}

//## Operation: SetRepository%983187854
void ChannelServer::SetRepository (ElementRepository* me_repo)
{
  //## begin ChannelServer::SetRepository%983187854.body preserve=yes
	theElements = me_repo;
  //## end ChannelServer::SetRepository%983187854.body
}

//## Operation: FindCtors%983275418
void ChannelServer::FindCtors (const string& type, const string& keypat, std::set<ChannelCtor*>& ctors)
{
  //## begin ChannelServer::FindCtors%983275418.body preserve=yes
	ctors.clear();

	CtorTable::iterator c1 = find_if(chCtors.begin(),chCtors.end(),FindType(type));

	if(c1==chCtors.end())
		return;

	CtorTable::iterator c2 = find_if(c1,chCtors.end(),FindType(type,true));

	// Now find those ctors that match the key pattern
	StringPattern keyp(keypat);
	for(CtorTable::iterator ci = c1; ci!=c2; ci++) {
		if(keyp((ci->second)->GetKey()))
			ctors.insert(ci->second);
	}
  //## end ChannelServer::FindCtors%983275418.body
}

//## Operation: FindElements%986466256
void ChannelServer::FindElements (const std::string& id_pat, std::vector<ModelElement*>& elements)
{
  //## begin ChannelServer::FindElements%986466256.body preserve=yes
	theElements->Find(id_pat,elements);
	sort(elements.begin(),elements.end(),TYPE_CMP());
  //## end ChannelServer::FindElements%986466256.body
}

//## begin module%3AC877460082.epilog preserve=yes
//## end module%3AC877460082.epilog

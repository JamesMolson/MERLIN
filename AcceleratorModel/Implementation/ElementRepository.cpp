//## begin module%3AC877B402BC.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\ElementRepository.cpp
 * last modified 03/04/01 14:35:01
 */
//## end module%3AC877B402BC.cm

//## begin module%3AC877B402BC.cp preserve=no
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
//## end module%3AC877B402BC.cp

//## Module: ElementRepository%3AC877B402BC; Package body
//## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\ElementRepository.cpp

//## begin module%3AC877B402BC.includes preserve=yes
#include "merlin_config.h"
#include <algorithm>
//## end module%3AC877B402BC.includes

// ElementRepository
#include "AcceleratorModel/Implementation/ElementRepository.h"
// deleters
#include "stdext/deleters.h"
// StringPattern
#include "utility/StringPattern.h"


//## begin module%3AC877B402BC.declarations preserve=no
//## end module%3AC877B402BC.declarations

//## begin module%3AC877B402BC.additionalDeclarations preserve=yes
using namespace std;

namespace {

	struct MatchID {
	public:

		MatchID(const string& idpat,bool negate=false) : pattern(idpat) {}
		bool operator()(const ModelElement* elmnt) const {
			bool rv = pattern(elmnt->GetQualifiedName());
			return neg ? !rv : rv;
		}
	private:
		bool neg;
		StringPattern pattern;
	};

};
//## end module%3AC877B402BC.additionalDeclarations


//## begin ElementRepository::ElementSet.instantiation preserve=no
template class std::set< ModelElement* >;
//## end ElementRepository::ElementSet.instantiation
// Class ElementRepository 





//## Operation: ~ElementRepository%983275406
ElementRepository::~ElementRepository ()
{
  //## begin ElementRepository::~ElementRepository%983275406.body preserve=yes
	for_each(theElements.begin(),theElements.end(),deleter<ModelElement>());
  //## end ElementRepository::~ElementRepository%983275406.body
}



//## Other Operations (implementation)
//## Operation: Add%983275407
bool ElementRepository::Add (ModelElement* anElement)
{
  //## begin ElementRepository::Add%983275407.body preserve=yes
	pair<iterator,bool> rv = theElements.insert(anElement);
	return rv.second;
  //## end ElementRepository::Add%983275407.body
}

//## Operation: Count%983275408
size_t ElementRepository::Count (const std::string& id) const
{
  //## begin ElementRepository::Count%983275408.body preserve=yes
	return count_if(theElements.begin(),theElements.end(),MatchID(id));
  //## end ElementRepository::Count%983275408.body
}

//## Operation: Find%983275409
size_t ElementRepository::Find (const std::string& id, std::vector<ModelElement*>& elements)
{
  //## begin ElementRepository::Find%983275409.body preserve=yes
	remove_copy_if(theElements.begin(),theElements.end(),
		back_inserter(elements),MatchID(id,true));
	return elements.size();
  //## end ElementRepository::Find%983275409.body
}

//## begin module%3AC877B402BC.epilog preserve=yes
//## end module%3AC877B402BC.epilog

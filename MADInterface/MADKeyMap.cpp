//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3BFA3CF402D3.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\MADInterface\MADKeyMap.cpp
 * last modified 20/11/01 12:46:22
 */
//## end module%3BFA3CF402D3.cm

//## begin module%3BFA3CF402D3.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 2001 by The Merlin Collaboration.
 * - ALL RIGHTS RESERVED - 
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
//## end module%3BFA3CF402D3.cp

//## Module: MADKeyMap%3BFA3CF402D3; Pseudo Package body
//## Source file: C:\C++\Merlin\MADInterface\MADKeyMap.cpp

//## begin module%3BFA3CF402D3.includes preserve=yes
#include <sstream>
#include "IO/MerlinIO.h"
//## end module%3BFA3CF402D3.includes

// MADKeyMap
#include "MADInterface/MADKeyMap.h"
//## begin module%3BFA3CF402D3.additionalDeclarations preserve=yes
using namespace std;
//## end module%3BFA3CF402D3.additionalDeclarations


// Class MADKeyMap::bad_key 

// Class MADKeyMap 

//## Operation: MADKeyMap%3BFA3DB302B0
MADKeyMap::MADKeyMap (const std::string& hstr)
  //## begin MADKeyMap::MADKeyMap%3BFA3DB302B0.initialization preserve=yes
  : has_type(false)
  //## end MADKeyMap::MADKeyMap%3BFA3DB302B0.initialization
{
  //## begin MADKeyMap::MADKeyMap%3BFA3DB302B0.body preserve=yes
	istringstream is(hstr);
	size_t n=0;
	string s;
	while(is>>s) {
		if(s=="TYPE") {
			has_type=true;
		}
		else
			kmap[s]=n++;
	}

#ifndef NDEBUG
	cout<<n<<" column headings identified"<<endl;
#endif

	vals = vector<double>(n,0.0);
  //## end MADKeyMap::MADKeyMap%3BFA3DB302B0.body
}



//## Other Operations (implementation)
//## Operation: GetParameter%3BFA3DCC032E
double MADKeyMap::GetParameter (const std::string& key, bool warn)
{
  //## begin MADKeyMap::GetParameter%3BFA3DCC032E.body preserve=yes
	key_map::iterator p = kmap.find(key);
	if(p!=kmap.end())
		return vals[p->second];
	else {
		if(warn)
			MerlinIO::warning()<<key<<" not in optics listing. Defaulted to zero"<<endl;
		return 0;
	}
  //## end MADKeyMap::GetParameter%3BFA3DCC032E.body
}

//## Operation: ReadRow%3BFA3ED70274
void MADKeyMap::ReadRow (std::istream& is)
{
  //## begin MADKeyMap::ReadRow%3BFA3ED70274.body preserve=yes
	for(size_t i=0; i<vals.size(); i++)
		is>>vals[i];
  //## end MADKeyMap::ReadRow%3BFA3ED70274.body
}

//## begin module%3BFA3CF402D3.epilog preserve=yes
//## end module%3BFA3CF402D3.epilog

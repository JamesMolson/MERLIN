//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%375C202C0276.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\AcceleratorModel.cpp
 * last modified 03/06/02 12:34:27
 */
//## end module%375C202C0276.cm

//## begin module%375C202C0276.cp preserve=no
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
//## end module%375C202C0276.cp

//## Module: AcceleratorModel%375C202C0276; Package body
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: C:\C++\Merlin\AcceleratorModel\AcceleratorModel.cpp

//## begin module%375C202C0276.includes preserve=yes
#include <iomanip>
#include <iterator>
#include <cassert>
#include "stdext/algorithm.h"
//## end module%375C202C0276.includes

// ComponentFrame
#include "AcceleratorModel/Frames/ComponentFrame.h"
// TComponentFrame
#include "AcceleratorModel/Frames/TComponentFrame.h"
// Channels
#include "Channels/Channels.h"
// ring_iterator
#include "stdext/ring_iterator.h"
// ChannelServer
#include "AcceleratorModel/Implementation/ChannelServer.h"
// deleters
#include "stdext/deleters.h"
// AcceleratorModel
#include "AcceleratorModel/AcceleratorModel.h"


//## begin module%375C202C0276.additionalDeclarations preserve=yes
using namespace std;

namespace {

	struct MatchName {
		StringPattern pattern;
		MatchName(const string& pat) : pattern(pat) {}
		bool operator()(const ModelElement* frm) {
			return pattern(frm->GetQualifiedName());
		}
	};

	struct ModelStats {
		map<string,int>& s;
		ModelStats(map<string,int>& stats) :s(stats) {}
		void operator()(const ModelElement* element) {
			s[element->GetType()]++;
		}
	};

}

extern ChannelServer* ConstructChannelServer();

//## end module%375C202C0276.additionalDeclarations


// Parameterized Class AcceleratorModel::Beamline::TRK 

// Class AcceleratorModel::Beamline 

// Class AcceleratorModel::BadRange 

// Class AcceleratorModel 

//## Operation: AcceleratorModel%39081B120388
AcceleratorModel::AcceleratorModel ()
  //## begin AcceleratorModel::AcceleratorModel%39081B120388.initialization preserve=yes
  : globalFrame(0)
  //## end AcceleratorModel::AcceleratorModel%39081B120388.initialization
{
  //## begin AcceleratorModel::AcceleratorModel%39081B120388.body preserve=yes
	theElements = new ElementRepository();
	chServer = ConstructChannelServer();
	chServer->SetRepository(theElements);
  //## end AcceleratorModel::AcceleratorModel%39081B120388.body
}


//## Operation: ~AcceleratorModel%3908161802FA
AcceleratorModel::~AcceleratorModel ()
{
  //## begin AcceleratorModel::~AcceleratorModel%3908161802FA.body preserve=yes
	if(chServer)
		delete chServer;
	if(theElements)
		delete theElements;
  //## end AcceleratorModel::~AcceleratorModel%3908161802FA.body
}



//## Other Operations (implementation)
//## Operation: GetBeamline%390807AE0222
AcceleratorModel::Beamline AcceleratorModel::GetBeamline ()
{
  //## begin AcceleratorModel::GetBeamline%390807AE0222.body preserve=yes
	BeamlineIterator i = lattice.end();
	advance(i,-1);
	return Beamline(lattice.begin(),i);
  //## end AcceleratorModel::GetBeamline%390807AE0222.body
}

//## Operation: GetBeamline%3908076E00CB
//## Exceptions: BadRange
AcceleratorModel::Beamline AcceleratorModel::GetBeamline (AcceleratorModel::Index n1, AcceleratorModel::Index n2) throw (BadRange)
{
  //## begin AcceleratorModel::GetBeamline%3908076E00CB.body preserve=yes
	if(n1<0 || n2>=lattice.size())
		throw BadRange();

	BeamlineIterator i1 = lattice.begin();
	BeamlineIterator i2 = lattice.begin();
	advance(i1,n1);
	advance(i2,n2);
	return Beamline(i1,i2);
  //## end AcceleratorModel::GetBeamline%3908076E00CB.body
}

//## Operation: GetBeamline%3908081B039B
//## Exceptions: BadRange
AcceleratorModel::Beamline AcceleratorModel::GetBeamline (const string& pat1, const string& pat2, int n1, int n2) throw (BadRange)
{
  //## begin AcceleratorModel::GetBeamline%3908081B039B.body preserve=yes
	assert(n1>=1 && n2>=1);
		
	StringPattern p1(pat1),p2(pat2);
	BeamlineIterator i1=lattice.end();
	BeamlineIterator i2=lattice.end();
	int nn1(0),nn2(0);

	for(BeamlineIterator i = lattice.begin(); i!=lattice.end() && (nn1!=n1 || nn2!=n2); i++) {
		string id = ((*i)->GetComponent()).GetQualifiedName();
		if(nn1<n1 && p1(id) && ++nn1 == n1)
			i1=i;
		if(nn2<n2 && p2(id) && ++nn2 == n2)
			i2=i;
	}

	if(i1==lattice.end() || i2==lattice.end())
		throw BadRange();

	return Beamline(i1,i2);
  //## end AcceleratorModel::GetBeamline%3908081B039B.body
}

//## Operation: GetRing%3B66952A00B7
AcceleratorModel::RingIterator AcceleratorModel::GetRing (int n)
{
  //## begin AcceleratorModel::GetRing%3B66952A00B7.body preserve=yes
	BeamlineIterator i = lattice.begin();
	advance(i,n);
	return RingIterator(lattice,i);
  //## end AcceleratorModel::GetRing%3B66952A00B7.body
}

//## Operation: GetReversedBeamline%39080C26012C
AcceleratorModel::Beamline AcceleratorModel::GetReversedBeamline ()
{
  //## begin AcceleratorModel::GetReversedBeamline%39080C26012C.body preserve=yes
	BeamlineIterator i = lattice.end();
	advance(i,-1);
	return Beamline(i,lattice.begin());
  //## end AcceleratorModel::GetReversedBeamline%39080C26012C.body
}

//## Operation: ExtractComponents%39080C8A00CC
int AcceleratorModel::ExtractComponents (const string& pat, vector<ComponentFrame*>& results)
{
  //## begin AcceleratorModel::ExtractComponents%39080C8A00CC.body preserve=yes
	if(pat=="*") // copy everything!
		copy(lattice.begin(),lattice.end(),back_inserter(results));
	else
		copy_if(lattice.begin(),lattice.end(),back_inserter(results),MatchName(pat));

	return results.size();
  //## end AcceleratorModel::ExtractComponents%39080C8A00CC.body
}

//## Operation: ExtractModelElements%39080D560274
int AcceleratorModel::ExtractModelElements (const string& pat, vector<ModelElement*>& results)
{
  //## begin AcceleratorModel::ExtractModelElements%39080D560274.body preserve=yes
	return theElements->Find(pat,results);
  //## end AcceleratorModel::ExtractModelElements%39080D560274.body
}

//## Operation: GetROChannels%3A9BCC60006E
size_t AcceleratorModel::GetROChannels (const string& chID, std::vector<ROChannel*>& channels)
{
  //## begin AcceleratorModel::GetROChannels%3A9BCC60006E.body preserve=yes
	return chServer->GetROChannels(chID,channels);
  //## end AcceleratorModel::GetROChannels%3A9BCC60006E.body
}

//## Operation: GetRWChannels%3A9BCC6000DC
size_t AcceleratorModel::GetRWChannels (const string& chID, std::vector<RWChannel*>& channels)
{
  //## begin AcceleratorModel::GetRWChannels%3A9BCC6000DC.body preserve=yes
	return chServer->GetRWChannels(chID,channels);
  //## end AcceleratorModel::GetRWChannels%3A9BCC6000DC.body
}

//## Operation: GetROChannels%3CFB412C014E
size_t AcceleratorModel::GetROChannels (AcceleratorModel::Beamline& aBeamline, const std::string& chid, std::vector<ROChannel*>& channels)
{
  //## begin AcceleratorModel::GetROChannels%3CFB412C014E.body preserve=yes
	return chServer->GetROChannels(aBeamline,chid,channels);
  //## end AcceleratorModel::GetROChannels%3CFB412C014E.body
}

//## Operation: GetRWChannels%3CFB40D000C9
size_t AcceleratorModel::GetRWChannels (AcceleratorModel::Beamline& aBeamline, const std::string& chid, std::vector<RWChannel*>& channels)
{
  //## begin AcceleratorModel::GetRWChannels%3CFB40D000C9.body preserve=yes
	return chServer->GetRWChannels(aBeamline,chid,channels);
  //## end AcceleratorModel::GetRWChannels%3CFB40D000C9.body
}

//## Operation: AddModelElement%3AE843E400BE
void AcceleratorModel::AddModelElement (ModelElement* element)
{
  //## begin AcceleratorModel::AddModelElement%3AE843E400BE.body preserve=yes
	if(element!=0)
		theElements->Add(element);
  //## end AcceleratorModel::AddModelElement%3AE843E400BE.body
}

//## Operation: ReportModelStatistics%3CAC27C9039A
void AcceleratorModel::ReportModelStatistics (std::ostream& os) const
{
  //## begin AcceleratorModel::ReportModelStatistics%3CAC27C9039A.body preserve=yes
	using std::map;

	os<<"Arc length of beamline:     "<<globalFrame->GetGeometryLength()<<" meter"<<endl;
	os<<"Total number of components: "<<lattice.size()<<endl;
	os<<"Total numner of elements:   "<<theElements->Size()<<endl;
	os<<endl;
	os<<"Model Element statistics\n";
	os<<"------------------------\n\n";

	map<string,int> stats;
	for_each(theElements->begin(),theElements->end(),ModelStats(stats));
	for(map<string,int>::iterator si=stats.begin(); si!=stats.end(); si++) {
		string atype = (*si).first;
		int count = (*si).second;
		os<<std::setw(20)<<left<<atype.c_str();
		os<<std::setw(4)<<count<<endl;
	}
	os<<endl;
  //## end AcceleratorModel::ReportModelStatistics%3CAC27C9039A.body
}

//## begin module%375C202C0276.epilog preserve=yes
//## end module%375C202C0276.epilog

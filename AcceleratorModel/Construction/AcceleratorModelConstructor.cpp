//## begin module%39084BAE02EB.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Construction\AcceleratorModelConstructor.cpp
 * last modified 03/04/01 14:50:56
 */
//## end module%39084BAE02EB.cm

//## begin module%39084BAE02EB.cp preserve=no
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
//## end module%39084BAE02EB.cp

//## Module: AcceleratorModelConstructor%39084BAE02EB; Package body
//## Subsystem: Merlin::AcceleratorModel::Construction%3AC8765A000A
//## Source file: D:\dev\Merlin\AcceleratorModel\Construction\AcceleratorModelConstructor.cpp

//## begin module%39084BAE02EB.includes preserve=yes
#include "merlin_config.h"
#include <cassert>
#include <map>
#include <iomanip>
//## end module%39084BAE02EB.includes

// Drift
#include "AcceleratorModel/StdComponent/Drift.h"
// SequenceFrame
#include "AcceleratorModel/Frames/SequenceFrame.h"
// AcceleratorModelConstructor
#include "AcceleratorModel/Construction/AcceleratorModelConstructor.h"


//## begin module%39084BAE02EB.declarations preserve=no
//## end module%39084BAE02EB.declarations

//## begin module%39084BAE02EB.additionalDeclarations preserve=yes
namespace {

	struct ModelStats {

		map<string,int>& s;

		ModelStats(map<string,int>& stats) :s(stats) {}

		void operator()(const ModelElement* element)
		{
			s[element->GetType()]++;
		}
	};


	// class MEExtractor
	// FrameTraverser implementation used by AppendFrame(SequenceFrame*)
	// to add the specified frame to the accelerator model.
	class MEExtractor : public FrameTraverser {
	public:

		MEExtractor(ElementRepository* erp, AcceleratorModel::FlatLattice* lp)
			: erepo(erp),lattice(lp)
		{}

		virtual void ActOn(LatticeFrame* frame) {
			erepo->Add(frame);
			try {
				ComponentFrame* cf = dynamic_cast<ComponentFrame*>(frame);
				if(cf) {
					erepo->Add(&(cf->GetComponent()));
					lattice->push_back(cf);
				}
			}
			catch(bad_cast&) {
				cerr<<"bad cast cought here!"<<endl;
			}
			catch(...) {
				cerr<<"something weird here"<<endl;
			}
		};

	private:
		ElementRepository* erepo;
		AcceleratorModel::FlatLattice* lattice;
	};


};
//## end module%39084BAE02EB.additionalDeclarations


//## begin AcceleratorModelConstructor::FrameStack.instantiation preserve=no
template class std::stack< SequenceFrame* >;
//## end AcceleratorModelConstructor::FrameStack.instantiation
// Class AcceleratorModelConstructor 



//## Operation: AcceleratorModelConstructor%956820806
AcceleratorModelConstructor::AcceleratorModelConstructor ()
  //## begin AcceleratorModelConstructor::AcceleratorModelConstructor%956820806.initialization preserve=yes
  : currentModel(0)
  //## end AcceleratorModelConstructor::AcceleratorModelConstructor%956820806.initialization
{
  //## begin AcceleratorModelConstructor::AcceleratorModelConstructor%956820806.body preserve=yes
  //## end AcceleratorModelConstructor::AcceleratorModelConstructor%956820806.body
}


//## Operation: ~AcceleratorModelConstructor%956820807
AcceleratorModelConstructor::~AcceleratorModelConstructor ()
{
  //## begin AcceleratorModelConstructor::~AcceleratorModelConstructor%956820807.body preserve=yes
	if(currentModel) 
		delete currentModel;
  //## end AcceleratorModelConstructor::~AcceleratorModelConstructor%956820807.body
}



//## Other Operations (implementation)
//## Operation: NewModel%956820796
void AcceleratorModelConstructor::NewModel ()
{
  //## begin AcceleratorModelConstructor::NewModel%956820796.body preserve=yes
	if(currentModel) {
		delete currentModel;
		while(!frameStack.empty())
			frameStack.pop();
	}
	
	currentModel = new AcceleratorModel();
	SequenceFrame *globalFrame = new SequenceFrame("GLOBAL",SequenceFrame::originAtEntrance);
	currentModel->globalFrame = globalFrame;
	frameStack.push(globalFrame);
  //## end AcceleratorModelConstructor::NewModel%956820796.body
}

//## Operation: GetModel%956820797
AcceleratorModel* AcceleratorModelConstructor::GetModel ()
{
  //## begin AcceleratorModelConstructor::GetModel%956820797.body preserve=yes
	frameStack.pop();
	assert(currentModel && frameStack.empty());

	currentModel->globalFrame->ConsolidateConstruction();

	AcceleratorModel* t=currentModel;
	currentModel=0;
	return t;
  //## end AcceleratorModelConstructor::GetModel%956820797.body
}

//## Operation: NewFrame%956820798
void AcceleratorModelConstructor::NewFrame (SequenceFrame* aFrame)
{
  //## begin AcceleratorModelConstructor::NewFrame%956820798.body preserve=yes
	assert(currentModel && aFrame);
	currentModel->theElements->Add(aFrame);
	frameStack.push(aFrame);
  //## end AcceleratorModelConstructor::NewFrame%956820798.body
}

//## Operation: EndFrame%956820799
void AcceleratorModelConstructor::EndFrame ()
{
  //## begin AcceleratorModelConstructor::EndFrame%956820799.body preserve=yes
	SequenceFrame* cf = frameStack.top();
	frameStack.pop();
	(frameStack.top())->AppendFrame(*cf);
  //## end AcceleratorModelConstructor::EndFrame%956820799.body
}

//## Operation: AppendDrift%956820803
void AcceleratorModelConstructor::AppendDrift (double d)
{
  //## begin AcceleratorModelConstructor::AppendDrift%956820803.body preserve=yes
	Drift* newd = new Drift("UNNAMED",d);
	AppendComponentFrame(new TComponentFrame<Drift>(*newd));
  //## end AcceleratorModelConstructor::AppendDrift%956820803.body
}

//## Operation: AddModelElement%985183006
void AcceleratorModelConstructor::AddModelElement (ModelElement* element)
{
  //## begin AcceleratorModelConstructor::AddModelElement%985183006.body preserve=yes
	currentModel->theElements->Add(element);
  //## end AcceleratorModelConstructor::AddModelElement%985183006.body
}

//## Operation: ReportStatistics%956820805
void AcceleratorModelConstructor::ReportStatistics (std::ostream& os) const
{
  //## begin AcceleratorModelConstructor::ReportStatistics%956820805.body preserve=yes
	using std::map;

	os<<"Arc length of beamline:     "<<currentModel->globalFrame->GetGeometryLength()<<" meter"<<endl;
	os<<"Total number of components: "<<(*currentModel).lattice.size()<<endl;
	os<<"Total numner of elements:   "<<currentModel->theElements->Size()<<endl;
	os<<endl;
	os<<"Model Element statistics\n";
	os<<"------------------------\n\n";

	map<string,int> stats;
	for_each(currentModel->theElements->begin(),currentModel->theElements->end(),ModelStats(stats));
	for(map<string,int>::iterator si=stats.begin(); si!=stats.end(); si++) {
		string atype = (*si).first;
		int count = (*si).second;
		os<<setw(20)<<left<<atype.c_str();
		os<<setw(4)<<count<<endl;
	}
	os<<endl;
  //## end AcceleratorModelConstructor::ReportStatistics%956820805.body
}

void AcceleratorModelConstructor::AppendFrame(SequenceFrame* aFrame)
{
	assert(currentModel);

	// We extract all the model elements from aFrame
	// and add them to the repository. In addition, we
	// extract (in order) all the ComponentFrame objects
	// and append them to the lattice.

	MEExtractor mextr(currentModel->theElements,&(currentModel->lattice));
	aFrame->Traverse(mextr);

	(frameStack.top())->AppendFrame(*aFrame);
}

//## Operation: AppendComponentFrame%956820804
void AcceleratorModelConstructor::AppendComponentFrame (ComponentFrame* cf)
{
  //## begin AcceleratorModelConstructor::AppendComponentFrame%956820804.body preserve=yes
	assert(currentModel);
	currentModel->theElements->Add(cf);
	currentModel->theElements->Add(&(cf->GetComponent()));
	(*currentModel).lattice.push_back(cf);
	(frameStack.top())->AppendFrame(*cf);
  //## end AcceleratorModelConstructor::AppendComponentFrame%956820804.body
}

//## begin module%39084BAE02EB.epilog preserve=yes
//## end module%39084BAE02EB.epilog

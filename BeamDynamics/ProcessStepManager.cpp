//## begin module%3AE6C13803CA.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ProcessStepManager.cpp
 * last modified 25/04/01 16:55:21
 */
//## end module%3AE6C13803CA.cm

//## begin module%3AE6C13803CA.cp preserve=no
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
//## end module%3AE6C13803CA.cp

//## Module: ProcessStepManager%3AE6C13803CA; Package body
//## Subsystem: Merlin::BeamDynamics%3AE6C9AC02F8
//## Source file: D:\dev\Merlin\BeamDynamics\ProcessStepManager.cpp

//## begin module%3AE6C13803CA.includes preserve=yes
#include <algorithm>
#include <iomanip>
#include "NumericalUtils/utils.h"
//## end module%3AE6C13803CA.includes

// BunchProcess
#include "BeamDynamics/BunchProcess.h"
// ProcessStepManager
#include "BeamDynamics/ProcessStepManager.h"
// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"
// deleters
#include "stdext/deleters.h"


//## begin module%3AE6C13803CA.declarations preserve=no
//## end module%3AE6C13803CA.declarations

//## begin module%3AE6C13803CA.additionalDeclarations preserve=yes
namespace {
        #ifndef  _MSC_VER
        #define _MIN(a,b) std::min(a,b)
        #define _MAX(a,b) std::max(a,b)
        #endif

	using namespace std;
	using std::setw;
	typedef list<BunchProcess*>::iterator proc_itor;
	typedef list<BunchProcess*>::const_iterator const_proc_itor;
	typedef list<BunchProcess*>::reverse_iterator rev_proc_itor;
	typedef list<BunchProcess*>::const_reverse_iterator const_rev_proc_itor;

	struct InitProc {
		Bunch& ibunch;
		InitProc(Bunch& b) : ibunch(b) {}
		void operator()(BunchProcess* proc) {proc->InitialiseProcess(ibunch);}
	};

	struct SetCmpnt {
		AcceleratorComponent& cmp;
		SetCmpnt(AcceleratorComponent& ac) : cmp(ac) {}
		void operator()(BunchProcess* proc) {
			proc->SetCurrentComponent(cmp);
		}
	};

	struct CalcStepSize {
		double ds;
		CalcStepSize(double s_max) : ds(s_max) {}
		void operator()(BunchProcess* proc) {
			if(proc->IsActive())
				ds = _MIN(ds,proc->GetMaxAllowedStepSize());
		}
	};

	struct DoProc {
		double s0;
		double ds;
		const string& cid;
		ostream* vos;
		
		DoProc(double s, double ds1, const string& id, ostream* os) 
			: s0(s), ds(ds1), cid(id), vos(os) {}

		void operator()(BunchProcess* proc) { 
			if(proc->IsActive()) {
				if(vos!=0) Trace(proc);
				proc->DoProcess(ds);
			}
		}

		void Trace(BunchProcess*);
	};

	void DoProc::Trace(BunchProcess* proc)
	{
		(*vos)<<setw(24)<<left<<cid.c_str();
		(*vos)<<setw(24)<<left<<(*proc).GetID().c_str();
		(*vos)<<"from: "<<right<<s0<<" to: "<<s0+ds<<" (step = "<<ds<<")"<<endl;
	}

}; // end of anonymous namespace
//## end module%3AE6C13803CA.additionalDeclarations


// Class ProcessStepManager 





//## Operation: ProcessStepManager%935569206
ProcessStepManager::ProcessStepManager ()
  //## begin ProcessStepManager::ProcessStepManager%935569206.initialization preserve=yes
  : total_s(0),log(0),processTable()
  //## end ProcessStepManager::ProcessStepManager%935569206.initialization
{
  //## begin ProcessStepManager::ProcessStepManager%935569206.body preserve=yes
  //## end ProcessStepManager::ProcessStepManager%935569206.body
}


//## Operation: ~ProcessStepManager%935569207
ProcessStepManager::~ProcessStepManager ()
{
  //## begin ProcessStepManager::~ProcessStepManager%935569207.body preserve=yes
  for_each(processTable.begin(),processTable.end(),deleter<BunchProcess>());
  //## end ProcessStepManager::~ProcessStepManager%935569207.body
}



//## Other Operations (implementation)
//## Operation: Initialise%935569208
void ProcessStepManager::Initialise (Bunch& bunch)
{
  //## begin ProcessStepManager::Initialise%935569208.body preserve=yes
	for_each(processTable.begin(),processTable.end(),InitProc(bunch));
	total_s=0;
  //## end ProcessStepManager::Initialise%935569208.body
}

//## Operation: Track%935569209
void ProcessStepManager::Track (AcceleratorComponent& component)
{
  //## begin ProcessStepManager::Track%935569209.body preserve=yes
	const string id = component.GetQualifiedName();
	
	for_each(processTable.begin(),processTable.end(),SetCmpnt(component));
	
	const double sc = component.GetLength();
	double s=0;
	
	do{
		double ds = for_each(processTable.begin(),processTable.end(),CalcStepSize(sc-s)).ds;
		for_each(processTable.begin(),processTable.end(),DoProc(s,ds,id,log));
		s+=ds;
	} while(!fequal(sc,s));
	
	total_s += sc;
  //## end ProcessStepManager::Track%935569209.body
}

//## Operation: GetIntegratedLength%935569211
double ProcessStepManager::GetIntegratedLength ()
{
  //## begin ProcessStepManager::GetIntegratedLength%935569211.body preserve=yes
	return total_s;
  //## end ProcessStepManager::GetIntegratedLength%935569211.body
}

//## Operation: AddProcess%935569212
void ProcessStepManager::AddProcess (BunchProcess* aProcess)
{
  //## begin ProcessStepManager::AddProcess%935569212.body preserve=yes
	if(aProcess->GetPriority()<0)
		processTable.push_back(aProcess);
	else {
	        proc_itor p;
		for(p = processTable.begin(); 
		p!=processTable.end() && (*p)->GetPriority() <= aProcess->GetPriority();
		p++);
		processTable.insert(p,aProcess);
	}
  //## end ProcessStepManager::AddProcess%935569212.body
}

//## Operation: RemoveProcess%935569213
bool ProcessStepManager::RemoveProcess (BunchProcess* aProcess)
{
  //## begin ProcessStepManager::RemoveProcess%935569213.body preserve=yes
	proc_itor p = find(processTable.begin(),processTable.end(),aProcess);
	processTable.erase(p);
	return p!=processTable.end();
  //## end ProcessStepManager::RemoveProcess%935569213.body
}

//## Operation: ClearProcesses%935569214
void ProcessStepManager::ClearProcesses ()
{
  //## begin ProcessStepManager::ClearProcesses%935569214.body preserve=yes
  for_each(processTable.begin(),processTable.end(),deleter<BunchProcess>());
  processTable.clear();
  //## end ProcessStepManager::ClearProcesses%935569214.body
}

//## Operation: SetLogStream%988208175
void ProcessStepManager::SetLogStream (ostream* os)
{
  //## begin ProcessStepManager::SetLogStream%988208175.body preserve=yes
	log=os;
  //## end ProcessStepManager::SetLogStream%988208175.body
}

//## begin module%3AE6C13803CA.epilog preserve=yes
//## end module%3AE6C13803CA.epilog

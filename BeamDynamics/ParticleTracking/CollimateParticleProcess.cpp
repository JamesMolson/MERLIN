//## begin module%3AE7DE350082.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\CollimateParticleProcess.cpp
 * last modified 30/04/01 12:28:48
 */
//## end module%3AE7DE350082.cm

//## begin module%3AE7DE350082.cp preserve=no
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
//## end module%3AE7DE350082.cp

//## Module: CollimateParticleProcess%3AE7DE350082; Package body
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: D:\dev\Merlin\BeamDynamics\ParticleTracking\CollimateParticleProcess.cpp

//## begin module%3AE7DE350082.includes preserve=yes
#include "merlin_config.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include "NumericalUtils/utils.h"
//## end module%3AE7DE350082.includes

// CollimateParticleProcess
#include "BeamDynamics/ParticleTracking/CollimateParticleProcess.h"
// Aperture
#include "AcceleratorModel/Aperture.h"
//## begin module%3AE7DE350082.declarations preserve=no
//## end module%3AE7DE350082.declarations

//## begin module%3AE7DE350082.additionalDeclarations preserve=yes
using namespace std;
namespace {

	void OutputIndexParticles(const PSvectorArray lost_p, const list<size_t>& lost_i, ostream& os)
	{
		PSvectorArray::const_iterator p = lost_p.begin();
		list<size_t>::const_iterator ip = lost_i.begin();

		while(p!=lost_p.end()) {
			os<<std::setw(8)<<right<<*ip;
			os<<*p;
			++p;
			++ip;
		}
	}
};
//## end module%3AE7DE350082.additionalDeclarations


// Class CollimateParticleProcess 
















//## Operation: CollimateParticleProcess%935667561
CollimateParticleProcess::CollimateParticleProcess (int priority, int mode, std::ostream* osp)
  //## begin CollimateParticleProcess::CollimateParticleProcess%935667561.initialization preserve=yes
  : ParticleBunchProcess("PARTICLE COLLIMATION",priority),cmode(mode),os(osp),
  createLossFiles(false),file_prefix(""),nstart(0),pindex(0),lossThreshold(1)
  //## end CollimateParticleProcess::CollimateParticleProcess%935667561.initialization
{
  //## begin CollimateParticleProcess::CollimateParticleProcess%935667561.body preserve=yes
  //## end CollimateParticleProcess::CollimateParticleProcess%935667561.body
}


//## Operation: ~CollimateParticleProcess%988274693
CollimateParticleProcess::~CollimateParticleProcess ()
{
  //## begin CollimateParticleProcess::~CollimateParticleProcess%988274693.body preserve=yes
	if(pindex!=0)
		delete pindex;
  //## end CollimateParticleProcess::~CollimateParticleProcess%988274693.body
}



//## Other Operations (implementation)
//## Operation: InitialiseProcess%935667562
void CollimateParticleProcess::InitialiseProcess (Bunch& bunch)
{
  //## begin CollimateParticleProcess::InitialiseProcess%935667562.body preserve=yes
	ParticleBunchProcess::InitialiseProcess(bunch);
	idtbl.clear();
	if(currentBunch) {
		nstart = currentBunch->size();
		nlost = 0;
		if(pindex!=0) {
			pindex->clear();
			for(size_t n=0; n<nstart; n++)
				pindex->push_back(n);
		}
	}
  //## end CollimateParticleProcess::InitialiseProcess%935667562.body
}

//## Operation: SetCurrentComponent%935667563
void CollimateParticleProcess::SetCurrentComponent (AcceleratorComponent& component)
{
  //## begin CollimateParticleProcess::SetCurrentComponent%935667563.body preserve=yes
	active = (currentBunch!=0) && (component.GetAperture()!=0);

	if(active) {
		currentComponent = &component;
		s=0;
		at_entr = (COLL_AT_ENTRANCE & cmode)!=0;
		at_cent = (COLL_AT_CENTER & cmode)!=0;
		at_exit = (COLL_AT_EXIT & cmode)!=0;
		SetNextS();
	}
	else {
		s_total += component.GetLength();
		currentComponent = 0;
	}
  //## end CollimateParticleProcess::SetCurrentComponent%935667563.body
}

//## Operation: DoProcess%935667564
void CollimateParticleProcess::DoProcess (double ds)
{
  //## begin CollimateParticleProcess::DoProcess%935667564.body preserve=yes
	s+=ds;
	if(fequal(s,next_s)) {
		DoCollimation();
		SetNextS();
	}

	// If we are finished, GetNextS() will have set the process inactive.
	// In that case we can update s_total with the component length.
	if(!active)
		s_total += currentComponent->GetLength();
  //## end CollimateParticleProcess::DoProcess%935667564.body
}

//## Operation: GetMaxAllowedStepSize%935667565
double CollimateParticleProcess::GetMaxAllowedStepSize () const
{
  //## begin CollimateParticleProcess::GetMaxAllowedStepSize%935667565.body preserve=yes
	return next_s-s;
  //## end CollimateParticleProcess::GetMaxAllowedStepSize%935667565.body
}

//## Operation: IndexParticles%988274691
void CollimateParticleProcess::IndexParticles (bool index)
{
  //## begin CollimateParticleProcess::IndexParticles%988274691.body preserve=yes
	if(index && pindex==0)
		pindex = new list<size_t>;
	else if(!index && pindex!=0) {
		delete pindex;
		pindex=0;
	}
  //## end CollimateParticleProcess::IndexParticles%988274691.body
}

//## Operation: SetLossThreshold%988274692
void CollimateParticleProcess::SetLossThreshold (double losspc)
{
  //## begin CollimateParticleProcess::SetLossThreshold%988274692.body preserve=yes
	lossThreshold = losspc/100.0;
  //## end CollimateParticleProcess::SetLossThreshold%988274692.body
}

//## Operation: DoCollimation%935667566
void CollimateParticleProcess::DoCollimation ()
{
  //## begin CollimateParticleProcess::DoCollimation%935667566.body preserve=yes
	const Aperture *ap = currentComponent->GetAperture();

	PSvectorArray lost;
	list<size_t>  lost_i;
		
	list<size_t>::iterator ip;
	if(pindex!=0)
		ip=pindex->begin();

	for(PSvectorArray::iterator p = currentBunch->begin(); p!=currentBunch->end(); p++) {
		if(!ap->PointInside((*p).x(),(*p).y(),s)) {
			lost.push_back(*p);
			p=currentBunch->erase(p);
			--p;
			if(pindex!=0) {
				lost_i.push_back(*ip);
				ip = pindex->erase(ip);
				--ip;
			}
		}
		if(pindex!=0)
			++ip;
	}

	nlost+=lost.size();
	if(double(nlost)/double(nstart)>=lossThreshold)
		throw ExcessiveParticleLoss(currentComponent->GetQualifiedName(),lossThreshold,nlost,nstart);

	DoOutput(lost,lost_i);
  //## end CollimateParticleProcess::DoCollimation%935667566.body
}

//## Operation: SetNextS%935667567
void CollimateParticleProcess::SetNextS ()
{
  //## begin CollimateParticleProcess::SetNextS%935667567.body preserve=yes
	if(at_entr) {
		next_s=0;
		at_entr=false;
	}
	else if(at_cent) {
		next_s=currentComponent->GetLength()/2;
		at_cent=false;
	}
	else if(at_exit) {
		next_s=currentComponent->GetLength();
		at_exit = false;
	}
	else
		active=false;
  //## end CollimateParticleProcess::SetNextS%935667567.body
}

//## Operation: DoOutput%936004767
void CollimateParticleProcess::DoOutput (const PSvectorArray& lostb, const list<size_t>& lost_i)
{
  //## begin CollimateParticleProcess::DoOutput%936004767.body preserve=yes
	// Create a file and dump the lost particles
	// (if there are any)
	if(!lostb.empty()) {
		if(os!=0) {
			(*os)<<std::setw(24)<<left<<(*currentComponent).GetQualifiedName().c_str();
			(*os)<<std::setw(12)<<right<<currentComponent->GetLength();
			(*os)<<std::setw(12)<<right<<currentBunch->GetReferenceTime();
			(*os)<<std::setw(8)<<right<<lostb.size()<<endl;
		}
		if(createLossFiles) {
			string id = (*currentComponent).GetQualifiedName();
			pair<IDTBL::iterator,bool> result = idtbl.insert(IDTBL::value_type(id,0));
			int n = ++(*(result.first)).second;
			ostringstream fname;
			if(!file_prefix.empty())
				fname<<file_prefix;
			fname<<id<<'.'<<n<<".loss";
			ofstream file(fname.str().c_str());
			if(pindex==0)
				copy(lostb.begin(),lostb.end(),ostream_iterator<PSvector>(file));
			else
				OutputIndexParticles(lostb,lost_i,file);
		}
	}
  //## end CollimateParticleProcess::DoOutput%936004767.body
}

// Class ExcessiveParticleLoss 

//## Operation: ExcessiveParticleLoss%988274700
ExcessiveParticleLoss::ExcessiveParticleLoss (const string& c_id, double threshold, size_t nlost, size_t nstart)
  //## begin ExcessiveParticleLoss::ExcessiveParticleLoss%988274700.initialization preserve=yes
  : MerlinException()
  //## end ExcessiveParticleLoss::ExcessiveParticleLoss%988274700.initialization
{
  //## begin ExcessiveParticleLoss::ExcessiveParticleLoss%988274700.body preserve=yes
	ostringstream buffer;
	buffer<<"CollimateParticleProcess Exception\n";
	buffer<<"particle loss threshold of "<<100*threshold<<"% exceeded ";
	buffer<<'('<<nlost<<'/'<<nstart<<") at "<<c_id;
	SetMsg(buffer.str());
  //## end ExcessiveParticleLoss::ExcessiveParticleLoss%988274700.body
}


//## begin module%3AE7DE350082.epilog preserve=yes
//## end module%3AE7DE350082.epilog

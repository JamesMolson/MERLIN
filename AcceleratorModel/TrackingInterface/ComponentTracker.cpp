//## begin module%371450090316.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\TrackingInterface\ComponentTracker.cpp
 * last modified 03/04/01 15:06:01
 */
//## end module%371450090316.cm

//## begin module%371450090316.cp preserve=no
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
//## end module%371450090316.cp

//## Module: ComponentTracker%371450090316; Package body
//## Subsystem: Merlin::AcceleratorModel::TrackingInterface%3AC484140014
//## Source file: D:\dev\Merlin\AcceleratorModel\TrackingInterface\ComponentTracker.cpp

//## begin module%371450090316.includes preserve=yes
#include "merlin_config.h"
#include <cassert>
#include <algorithm>
#include <map>
#include <limits>
#include <iostream>
#include "stdext/deleters.h"
#include "NumericalUtils/utils.h"
//## end module%371450090316.includes

// ComponentIntegrator
#include "AcceleratorModel/TrackingInterface/ComponentIntegrator.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"
// Marker
#include "AcceleratorModel/StdComponent/Marker.h"

class IntegratorTable;

//## begin module%371450090316.declarations preserve=no
//## end module%371450090316.declarations

//## begin module%371450090316.additionalDeclarations preserve=yes
namespace {
};
//## end module%371450090316.additionalDeclarations


//## Class: DefaultMarkerIntegrator%37CA71C7013B; implementation
//	The onlt default integrator supplied is that for a
//	Marker element, which are zero-length pseudo-components.
//	The default integrator does nothing.
//## Category: Merlin::AcceleratorModel::TrackingInterface%3AC4815503CA
//## Subsystem: Merlin::AcceleratorModel::TrackingInterface%3AC484140014
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%37CA720A028C;Marker { -> }

class DefaultMarkerIntegrator : public ComponentIntegrator  //## Inherits: <unnamed>%37CA720E02F5
{
  public:

    //## Other Operations (specified)
      //## Operation: TrackStep%936004769
      //	Performs no action.
      virtual double TrackStep (double ds);

      //## Operation: GetComponentIndex%936004770
      //	Returns the component index for this integrator.
      virtual int GetComponentIndex () const;

  protected:
  private:
  private:  //## implementation
};

//## Class: IntegratorTable%371378DF0104; implementation
//## Category: Merlin::AcceleratorModel::TrackingInterface%3AC4815503CA
//## Subsystem: Merlin::AcceleratorModel::TrackingInterface%3AC484140014
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%37144F43023A;ComponentIntegrator { -> F}

class IntegratorTable 
{
  public:
    //## Class: IMap%37144F570186; Instantiated Class
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::TrackingInterface%3AC484140014
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef std::map< int,ComponentIntegrator* > IMap;

  public:
    //## Destructor (specified)
      //## Operation: ~IntegratorTable%924072839
      ~IntegratorTable ();


    //## Other Operations (specified)
      //## Operation: Add%924072840
      bool Add (ComponentIntegrator* intg);

      //## Operation: GetIntegrator%924072841
      ComponentIntegrator* GetIntegrator (int n);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: itsMap%371451BC038E
      //## begin IntegratorTable::itsMap%371451BC038E.attr preserve=no  private: IMap {UA} 
      IMap itsMap;
      //## end IntegratorTable::itsMap%371451BC038E.attr

  private:  //## implementation
};

// Class DefaultMarkerIntegrator 

// Class IntegratorTable 

//## Operation: ~IntegratorTable%924072839
inline IntegratorTable::~IntegratorTable ()
{
  //## begin IntegratorTable::~IntegratorTable%924072839.body preserve=yes
//	std::for_each(itsMap.begin(),itsMap.end(),map_deleter<IndexType,Integrator>());
	for(IMap::iterator i=itsMap.begin();i!=itsMap.end();i++) {
		delete (*i).second;
	}
  //## end IntegratorTable::~IntegratorTable%924072839.body
}



//## Other Operations (inline)
//## Operation: Add%924072840
inline bool IntegratorTable::Add (ComponentIntegrator* intg)
{
  //## begin IntegratorTable::Add%924072840.body preserve=yes
	using namespace std;

	pair<IMap::iterator,bool> rt=itsMap.insert(
		IMap::value_type(intg->GetComponentIndex(),intg));

	if(!rt.second) { // override
		delete (*rt.first).second;
		(*rt.first).second = intg;
	}
	
	return !rt.second;  
  //## end IntegratorTable::Add%924072840.body
}

//## Operation: GetIntegrator%924072841
inline ComponentIntegrator* IntegratorTable::GetIntegrator (int n)
{
  //## begin IntegratorTable::GetIntegrator%924072841.body preserve=yes
	IMap::iterator i = itsMap.find(n);
	return i==itsMap.end() ? 0 : (*i).second;
  //## end IntegratorTable::GetIntegrator%924072841.body
}

// Class DefaultMarkerIntegrator 


//## Other Operations (implementation)
//## Operation: TrackStep%936004769
double DefaultMarkerIntegrator::TrackStep (double ds)
{
  //## begin DefaultMarkerIntegrator::TrackStep%936004769.body preserve=yes
	assert(ds==0);
	return 0;
  //## end DefaultMarkerIntegrator::TrackStep%936004769.body
}

//## Operation: GetComponentIndex%936004770
int DefaultMarkerIntegrator::GetComponentIndex () const
{
  //## begin DefaultMarkerIntegrator::GetComponentIndex%936004770.body preserve=yes
	return Marker::ID;
  //## end DefaultMarkerIntegrator::GetComponentIndex%936004770.body
}

// Class ComponentTracker::UnknownComponent 

// Class ComponentTracker 




//## Operation: ComponentTracker%924021883
ComponentTracker::ComponentTracker ()
  //## begin ComponentTracker::ComponentTracker%924021883.initialization preserve=yes
  : itsState(undefined),itsTable(new IntegratorTable)
  //## end ComponentTracker::ComponentTracker%924021883.initialization
{
  //## begin ComponentTracker::ComponentTracker%924021883.body preserve=yes
	// Register(new DefaultMarkerIntegrator());
  //## end ComponentTracker::ComponentTracker%924021883.body
}


//## Operation: ~ComponentTracker%924021884
ComponentTracker::~ComponentTracker ()
{
  //## begin ComponentTracker::~ComponentTracker%924021884.body preserve=yes
	delete itsTable;
  //## end ComponentTracker::~ComponentTracker%924021884.body
}



//## Other Operations (implementation)
//## Operation: Track%924021885
void ComponentTracker::Track ()
{
  //## begin ComponentTracker::Track%924021885.body preserve=yes
	assert(itsState==initialised);
	integrator->TrackAll();
	itsState=finished;
  //## end ComponentTracker::Track%924021885.body
}

//## Operation: TrackStep%924021886
double ComponentTracker::TrackStep (double ds)
{
  //## begin ComponentTracker::TrackStep%924021886.body preserve=yes
	assert(itsState==initialised || itsState==tracking);
	assert(integrator->IsValidStep(ds));

	double sToExit=integrator->TrackStep(ds);
	itsState = fequal(sToExit,0) ? finished : tracking;
	return itsState;
  //## end ComponentTracker::TrackStep%924021886.body
}

//## Operation: Reset%924021888
void ComponentTracker::Reset ()
{
  //## begin ComponentTracker::Reset%924021888.body preserve=yes
	integrator = 0;
	itsState = undefined;
  //## end ComponentTracker::Reset%924021888.body
}

//## Operation: GetRemainingTrackLength%924021889
double ComponentTracker::GetRemainingTrackLength () const
{
  //## begin ComponentTracker::GetRemainingTrackLength%924021889.body preserve=yes
	assert(itsState!=undefined);
	return integrator->GetRemainingLength();
  //## end ComponentTracker::GetRemainingTrackLength%924021889.body
}

//## Operation: GetIntegratedLength%924021890
double ComponentTracker::GetIntegratedLength () const
{
  //## begin ComponentTracker::GetIntegratedLength%924021890.body preserve=yes
	assert(itsState!=undefined);
	return integrator->GetIntegratedLength();
  //## end ComponentTracker::GetIntegratedLength%924021890.body
}

//## Operation: SelectIntegrator%924021891
bool ComponentTracker::SelectIntegrator (int index, AcceleratorComponent& component)
{
  //## begin ComponentTracker::SelectIntegrator%924021891.body preserve=yes
	assert((itsState==undefined)||(itsState==finished));

	integrator = itsTable->GetIntegrator(index);
	
	if(!integrator)
		return false;
	
	integrator->SetCurrentComponent(component);
	InitialiseIntegrator();

	return true;
  //## end ComponentTracker::SelectIntegrator%924021891.body
}

//## Operation: InitialiseIntegrator%924021892
void ComponentTracker::InitialiseIntegrator ()
{
  //## begin ComponentTracker::InitialiseIntegrator%924021892.body preserve=yes
	itsState = initialised;
  //## end ComponentTracker::InitialiseIntegrator%924021892.body
}

//## Operation: Register%924021893
bool ComponentTracker::Register (ComponentIntegrator* intg)
{
  //## begin ComponentTracker::Register%924021893.body preserve=yes
	return itsTable->Add(intg);
  //## end ComponentTracker::Register%924021893.body
}

//## begin IntegratorTable::IMap.instantiation preserve=no
template class std::map< int,ComponentIntegrator* >;
//## end IntegratorTable::IMap.instantiation
// Class IntegratorTable 



//## begin module%371450090316.epilog preserve=yes
//## end module%371450090316.epilog

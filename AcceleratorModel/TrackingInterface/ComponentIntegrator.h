//## begin module%37146AE90096.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\TrackingInterface\ComponentIntegrator.h
 * last modified 03/04/01 14:19:27
 */
//## end module%37146AE90096.cm

//## begin module%37146AE90096.cp preserve=no
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
//## end module%37146AE90096.cp

//## Module: ComponentIntegrator%37146AE90096; Package specification
//## Subsystem: Merlin::AcceleratorModel::TrackingInterface%3AC484140014
//## Source file: D:\dev\Merlin\AcceleratorModel\TrackingInterface\ComponentIntegrator.h

#ifndef ComponentIntegrator_h
#define ComponentIntegrator_h 1

//## begin module%37146AE90096.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37146AE90096.additionalIncludes

//## begin module%37146AE90096.includes preserve=yes
#include "NumericalUtils/utils.h"
#include "NumericalUtils/Range.h"
//## end module%37146AE90096.includes

// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"
//## begin module%37146AE90096.declarations preserve=no
//## end module%37146AE90096.declarations

//## begin module%37146AE90096.additionalDeclarations preserve=yes
//## end module%37146AE90096.additionalDeclarations


//## Class: ComponentIntegrator%371372B70230; Abstract
//	An integrator is used by Tracker to track through an
//	AcceleratorComponent. Integrators encapsulate the
//	various algorithms used for tracking.
//## Category: Merlin::AcceleratorModel::TrackingInterface%3AC4815503CA
//## Subsystem: Merlin::AcceleratorModel::TrackingInterface%3AC484140014
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ComponentIntegrator 
{
  public:
    //## Constructors (specified)
      //## Operation: ComponentIntegrator%924021903
      ComponentIntegrator ();

    //## Destructor (specified)
      //## Operation: ~ComponentIntegrator%924021904
      virtual ~ComponentIntegrator ();


    //## Other Operations (specified)
      //## Operation: TrackAll%924021894
      //	Track the entire component.
      void TrackAll ();

      //## Operation: TrackStep%924021895
      //	Tracks a single step ds through the current component.
      virtual double TrackStep (double ds) = 0;

      //## Operation: SetCurrentComponent%924021896
      void SetCurrentComponent (AcceleratorComponent& aComponent);

      //## Operation: GetCurrentComponent%924021897
      AcceleratorComponent& GetCurrentComponent ();

      //## Operation: GetComponentIndex%924021898
      //	Returns the component index for this integrator.
      virtual int GetComponentIndex () const = 0;

      //## Operation: GetIntegratedLength%924021899
      //	Returns the total integrated length through the current
      //	component.
      double GetIntegratedLength () const;

      //## Operation: GetRemainingLength%924021902
      //	Returns the remaining length to integrate.
      double GetRemainingLength () const;

      //## Operation: IsValidStep%925486265
      //	Returns true if the step ds is still within the geometry
      //	extents of the current component being tracked.
      bool IsValidStep (double ds) const;

	  // Returns the range of allowed step sizes for this integrator.
	  // Default returns [0,GetRemainingLength()]
	  virtual FloatRange GetStepRange() const;

	  bool AtEntrance() const {
		  return S_int==0;
	  }
	  bool AtExit() const {
		  return GetRemainingLength()==0;
	  }

  protected:

    //## Other Operations (specified)
      //## Operation: IncrStep%925486266
      double IncrStep (double ds);

    // Data Members for Class Attributes

      //## Attribute: S_int%371373840366
      //	The current total integrated length.
      //## begin ComponentIntegrator::S_int%371373840366.attr preserve=no  protected: double {UA} 
      double S_int;
      //## end ComponentIntegrator::S_int%371373840366.attr

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::TrackingInterface::<unnamed>%371373140118
      //## Role: ComponentIntegrator::component%37137316001E
      //	The current component being tracked.
      //## begin ComponentIntegrator::component%37137316001E.role preserve=no  protected: AcceleratorComponent { -> 0..1RHAN}
      AcceleratorComponent* component;
      //## end ComponentIntegrator::component%37137316001E.role

  private:
  private:  //## implementation
};

// Class ComponentIntegrator 

//## Operation: ComponentIntegrator%924021903
inline ComponentIntegrator::ComponentIntegrator ()
  //## begin ComponentIntegrator::ComponentIntegrator%924021903.initialization preserve=yes
  : S_int(0),component(0)
  //## end ComponentIntegrator::ComponentIntegrator%924021903.initialization
{
  //## begin ComponentIntegrator::ComponentIntegrator%924021903.body preserve=yes
  //## end ComponentIntegrator::ComponentIntegrator%924021903.body
}


//## Operation: ~ComponentIntegrator%924021904
inline ComponentIntegrator::~ComponentIntegrator ()
{
  //## begin ComponentIntegrator::~ComponentIntegrator%924021904.body preserve=yes
	// Nothing to do
  //## end ComponentIntegrator::~ComponentIntegrator%924021904.body
}



//## Other Operations (inline)
//## Operation: TrackAll%924021894
inline void ComponentIntegrator::TrackAll ()
{
  //## begin ComponentIntegrator::TrackAll%924021894.body preserve=yes
	TrackStep(component->GetLength());
  //## end ComponentIntegrator::TrackAll%924021894.body
}

//## Operation: SetCurrentComponent%924021896
inline void ComponentIntegrator::SetCurrentComponent (AcceleratorComponent& aComponent)
{
  //## begin ComponentIntegrator::SetCurrentComponent%924021896.body preserve=yes
	component = &aComponent;
	S_int=0;
  //## end ComponentIntegrator::SetCurrentComponent%924021896.body
}

//## Operation: GetCurrentComponent%924021897
inline AcceleratorComponent& ComponentIntegrator::GetCurrentComponent ()
{
  //## begin ComponentIntegrator::GetCurrentComponent%924021897.body preserve=yes
	return *component;
  //## end ComponentIntegrator::GetCurrentComponent%924021897.body
}

//## Operation: GetIntegratedLength%924021899
inline double ComponentIntegrator::GetIntegratedLength () const
{
  //## begin ComponentIntegrator::GetIntegratedLength%924021899.body preserve=yes
	return S_int;
  //## end ComponentIntegrator::GetIntegratedLength%924021899.body
}

//## Operation: GetRemainingLength%924021902
inline double ComponentIntegrator::GetRemainingLength () const
{
  //## begin ComponentIntegrator::GetRemainingLength%924021902.body preserve=yes
	using namespace std;
	const double z=(*component).GetLength()-S_int;
	return fequal(z,0.0) ? 0 : z;
  //## end ComponentIntegrator::GetRemainingLength%924021902.body
}

//## Operation: IsValidStep%925486265
inline bool ComponentIntegrator::IsValidStep (double ds) const
{
  //## begin ComponentIntegrator::IsValidStep%925486265.body preserve=yes
	return !((S_int+ds)>(*component).GetLength());
  //## end ComponentIntegrator::IsValidStep%925486265.body
}

//## Operation: IncrStep%925486266
inline double ComponentIntegrator::IncrStep (double ds)
{
  //## begin ComponentIntegrator::IncrStep%925486266.body preserve=yes
	S_int+=ds;
	return GetRemainingLength();
  //## end ComponentIntegrator::IncrStep%925486266.body
}

inline FloatRange ComponentIntegrator::GetStepRange() const
{
	return FloatRange(0,GetRemainingLength());
}
// Class ComponentIntegrator 




//## begin module%37146AE90096.epilog preserve=yes
//## end module%37146AE90096.epilog


#endif

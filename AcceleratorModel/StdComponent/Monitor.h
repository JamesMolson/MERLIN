//## begin module%331FFA130074.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\Monitor.h
 * last modified 04/04/01 15:25:44
 */
//## end module%331FFA130074.cm

//## begin module%331FFA130074.cp preserve=no
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
//## end module%331FFA130074.cp

//## Module: Monitor%331FFA130074; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\Monitor.h

#ifndef Monitor_h
#define Monitor_h 1

//## begin module%331FFA130074.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%331FFA130074.additionalIncludes

//## begin module%331FFA130074.includes preserve=yes
//## end module%331FFA130074.includes

// SimpleDrift
#include "AcceleratorModel/StdComponent/SimpleDrift.h"

class Bunch;
class ComponentTracker;

//## begin module%331FFA130074.additionalDeclarations preserve=yes
//## end module%331FFA130074.additionalDeclarations


//## Class: Monitor%331FFA130074
//	An arbitrary monitor. A monitor can represent any
//	diagnostic which is typically found in an accelerator.
//	Although objects of class Monitor can be instantiated to
//	represent generic monitors, a virtual function Make
//	Measurement() is provided which can be overridden by
//	derived Monitor classes which represent more specific
//	diagnotic types.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: measures%3724A7090118;Bunch { -> F}
//## Uses: <unnamed>%3725DB4B0064;ComponentTracker { -> F}

class Monitor : public SimpleDrift  //## Inherits: <unnamed>%3AC8808203B6
{
  public:
    //## Constructors (specified)
      //## Operation: Monitor%857738670
      //	Constructor taking the identifier for the diagnostic,
      //	together with its length (default=0) and measurement
      //	point (default = 0, mid-point).
      Monitor (const string& id, double len = 0, double mpt = 0);

    //## Destructor (specified)
      //## Operation: ~Monitor%880624262
      virtual ~Monitor ();


    //## Other Operations (specified)
      //## Operation: MakeMeasurement%857738671; C++
      //	Pure virtual function. Makes a measurement on the
      //	supplied Beam object. Concrete diagnostics must supply
      //	this function.
      virtual void MakeMeasurement (const Bunch& );

      //## Operation: SetMeasurementPt%857738673; C++
      //	Sets the position of the measurement point on the local
      //	geometry. Must be in the range -length/2 to +length/2.
      void SetMeasurementPt (double mpt) throw (AcceleratorGeometry::BeyondExtent);

      //## Operation: GetMeasurementPt%868960724
      //	Return the current measurement point.
      double GetMeasurementPt () const;

      //## Operation: IsActive%868960725
      //	Returns true if this diagnostic's state is active.
      bool IsActive () const;

      //## Operation: RotateY180%884089489; C++
      //	Rotate the diagnostic 180 degrees about the local Y axis.
      virtual void RotateY180 ();

      //## Operation: IsReflected%884089494
      //	Returns true if the diagnostic is rotated (i.e. the x
      //	measurement axis is reflected).
      bool IsReflected () const;

      //## Operation: SetReflected%884688449
      //	Sets the rotated status for this diagnositic to rflg.
      //	Returns the previous state.
      bool SetReflected (bool rflg);

      //## Operation: SetActive%925300212
      //	Sets the local  active state of this monitor. Returns
      //	the previous state. Note that this method only modifies
      //	the state of this monitor, and has no affect on the all_
      //	inactive flag.
      bool SetActive (bool b);

      //## Operation: GetIndex%925300213
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetType%925300214
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: PrepareTracker%925300215
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: Copy%925300216
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: all_inactive%3725876E00D2
      //	Used to turn all monitors off.
      //## begin Monitor::all_inactive%3725876E00D2.attr preserve=no  public: static bool {UA} false
      static bool all_inactive;
      //## end Monitor::all_inactive%3725876E00D2.attr

      //## Attribute: ID%3724B06D0212
      //## begin Monitor::ID%3724B06D0212.attr preserve=no  public: static const int {VA} UniqueIndex()
      static const int ID;
      //## end Monitor::ID%3724B06D0212.attr

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: mp%331FF11E02C6
      //	The measurement point of the monitor. Refers to the
      //	exact point at which the data is to be recorded.
      //## begin Monitor::mp%331FF11E02C6.attr preserve=no  private: double {UA} 
      double mp;
      //## end Monitor::mp%331FF11E02C6.attr

      //## Attribute: reflected%34B6118001A3
      //	True if the x measurement axis is reflected.
      //## begin Monitor::reflected%34B6118001A3.attr preserve=no  private: bool {UA} 
      bool reflected;
      //## end Monitor::reflected%34B6118001A3.attr

      //## Attribute: active%372587AF0050
      //## begin Monitor::active%372587AF0050.attr preserve=no  private: bool {UA} 
      bool active;
      //## end Monitor::active%372587AF0050.attr

  private:  //## implementation
};

// Class Monitor 


//## Other Operations (inline)
//## Operation: IsActive%868960725
inline bool Monitor::IsActive () const
{
  //## begin Monitor::IsActive%868960725.body preserve=yes
	return active && !all_inactive;
  //## end Monitor::IsActive%868960725.body
}

//## Operation: IsReflected%884089494
inline bool Monitor::IsReflected () const
{
  //## begin Monitor::IsReflected%884089494.body preserve=yes
	return reflected;
  //## end Monitor::IsReflected%884089494.body
}

//## Operation: SetReflected%884688449
inline bool Monitor::SetReflected (bool rflg)
{
  //## begin Monitor::SetReflected%884688449.body preserve=yes
	bool tmp = reflected;
	reflected = rflg;
	return tmp;
  //## end Monitor::SetReflected%884688449.body
}

//## Operation: SetActive%925300212
inline bool Monitor::SetActive (bool b)
{
  //## begin Monitor::SetActive%925300212.body preserve=yes
	bool tmp = active;
	active = b;
	return tmp;
  //## end Monitor::SetActive%925300212.body
}

//## begin module%331FFA130074.epilog preserve=yes
//## end module%331FFA130074.epilog


#endif

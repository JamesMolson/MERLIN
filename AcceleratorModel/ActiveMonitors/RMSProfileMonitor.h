//## begin module%372703980168.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\ActiveMonitors\RMSProfileMonitor.h
 * last modified 04/04/01 17:42:52
 */
//## end module%372703980168.cm

//## begin module%372703980168.cp preserve=no
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
//## end module%372703980168.cp

//## Module: RMSProfileMonitor%372703980168; Package specification
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
//## Source file: D:\dev\Merlin\AcceleratorModel\ActiveMonitors\RMSProfileMonitor.h

#ifndef RMSProfileMonitor_h
#define RMSProfileMonitor_h 1

//## begin module%372703980168.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%372703980168.additionalIncludes

//## begin module%372703980168.includes preserve=yes
#include "NumericalUtils/NumericalConstants.h"
#include <set>
//## end module%372703980168.includes

// AMBufferManager
#include "AcceleratorModel/ActiveMonitors/AMBufferManager.h"
// Monitor
#include "AcceleratorModel/StdComponent/Monitor.h"
// Measurement
#include "NumericalUtils/Measurement.h"

class Bunch;
class ComponentTracker;

//## begin module%372703980168.declarations preserve=no
//## end module%372703980168.declarations

//## begin module%372703980168.additionalDeclarations preserve=yes
#include "NumericalUtils/NumericalConstants.h"
//## end module%372703980168.additionalDeclarations


//## Class: RMSProfileMonitor%3724A7E200B4
//	An RMS profile monitor. A profile monitor which mimicks
//	the action of a "wire scanner". A profile monitor can
//	measure the rms beam projection onto three planes:
//	horizontal (x), vertical (y) and a third so-called
//	u-wire, which is at a specifid angle to the x plane.
//## Category: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: creates%3724AB73024E;RMSProfileMonitor::Data { -> F}
//## Uses: <unnamed>%37258B700334;RandomNG { -> }
//## Uses: <unnamed>%3725D693026C;ComponentTracker { -> F}
//## Uses: <unnamed>%372706FB01D6;Bunch { -> F}
//## Uses: <unnamed>%3ACB3F0700C8;RMSProfileMonitor::Buffer { -> F}

class RMSProfileMonitor : public Monitor  //## Inherits: <unnamed>%3AC4E8FE00AA
{
  public:
    //## Class: Data%3724AB1C0172
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: <unnamed>%3724ABA203AC;Measurement { -> }

    class Data 
    {
      public:
        // Data Members for Class Attributes

          //## Attribute: x0%3724AB2D01FE
          //## begin RMSProfileMonitor::Data::x0%3724AB2D01FE.attr preserve=no  public: Measurement {UA} 
          Measurement x0;
          //## end RMSProfileMonitor::Data::x0%3724AB2D01FE.attr

          //## Attribute: y0%3724AB370078
          //## begin RMSProfileMonitor::Data::y0%3724AB370078.attr preserve=no  public: Measurement {UA} 
          Measurement y0;
          //## end RMSProfileMonitor::Data::y0%3724AB370078.attr

          //## Attribute: u0%3724AB3E024E
          //## begin RMSProfileMonitor::Data::u0%3724AB3E024E.attr preserve=no  public: Measurement {UA} 
          Measurement u0;
          //## end RMSProfileMonitor::Data::u0%3724AB3E024E.attr

          //## Attribute: xrms%3724AB4803CA
          //## begin RMSProfileMonitor::Data::xrms%3724AB4803CA.attr preserve=no  public: Measurement {UA} 
          Measurement xrms;
          //## end RMSProfileMonitor::Data::xrms%3724AB4803CA.attr

          //## Attribute: yrms%3724AB5B0028
          //## begin RMSProfileMonitor::Data::yrms%3724AB5B0028.attr preserve=no  public: Measurement {UA} 
          Measurement yrms;
          //## end RMSProfileMonitor::Data::yrms%3724AB5B0028.attr

          //## Attribute: urms%3724AB610320
          //## begin RMSProfileMonitor::Data::urms%3724AB610320.attr preserve=no  public: Measurement {UA} 
          Measurement urms;
          //## end RMSProfileMonitor::Data::urms%3724AB610320.attr

      protected:
      private:
      private:  //## implementation
    };

    //## Class: Buffer%3ACB3E610366
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class Buffer 
    {
      public:
        //## Destructor (specified)
          //## Operation: ~Buffer%986385737
          virtual ~Buffer ()
          {
            //## begin RMSProfileMonitor::Buffer::~Buffer%986385737.body preserve=yes
            //## end RMSProfileMonitor::Buffer::~Buffer%986385737.body
          }


        //## Other Operations (specified)
          //## Operation: Record%986385738
          virtual void Record (const RMSProfileMonitor& mon, const Data& dat) = 0;

      protected:
      private:
      private:  //## implementation
    };

    //## Class: BufferManager%3ACB3E6601AE; Instantiated Class
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef AMBufferManager< RMSProfileMonitor,Buffer,Data > BufferManager;

  public:
    //## Constructors (specified)
      //## Operation: RMSProfileMonitor%925300217
      RMSProfileMonitor (const string& id, double uphi = pi/4, double len = 0, double mpt = 0)
        //## begin RMSProfileMonitor::RMSProfileMonitor%925300217.initialization preserve=yes
		: Monitor(id,len),res_x(0),res_y(0),res_u(0),uangle(uphi)
        //## end RMSProfileMonitor::RMSProfileMonitor%925300217.initialization
      {
        //## begin RMSProfileMonitor::RMSProfileMonitor%925300217.body preserve=yes
        //## end RMSProfileMonitor::RMSProfileMonitor%925300217.body
      }


    //## Other Operations (specified)
      //## Operation: SetResolution%925300218
      void SetResolution (double rx, double ry, double ru)
      {
        //## begin RMSProfileMonitor::SetResolution%925300218.body preserve=yes
		res_x = rx;
		res_y = ry;
		res_u = ru;
        //## end RMSProfileMonitor::SetResolution%925300218.body
      }

      //## Operation: AddBuffer%925300219
      void AddBuffer (Buffer* buffer)
      {
        //## begin RMSProfileMonitor::AddBuffer%925300219.body preserve=yes
		buffers.AddBuffer(buffer);
        //## end RMSProfileMonitor::AddBuffer%925300219.body
      }

      //## Operation: RemoveBuffer%986295712
      bool RemoveBuffer (Buffer* aBuffer)
      {
        //## begin RMSProfileMonitor::RemoveBuffer%986295712.body preserve=yes
		  return buffers.RemoveBuffer(aBuffer);
        //## end RMSProfileMonitor::RemoveBuffer%986295712.body
      }

      //## Operation: RemoveAllBuffers%986385739
      void RemoveAllBuffers ()
      {
        //## begin RMSProfileMonitor::RemoveAllBuffers%986385739.body preserve=yes
		  buffers.ClearAllBuffers();
        //## end RMSProfileMonitor::RemoveAllBuffers%986385739.body
      }

      //## Operation: SetDefaultBuffer%925300220
      static void SetDefaultBuffer (Buffer* buffer)
      {
        //## begin RMSProfileMonitor::SetDefaultBuffer%925300220.body preserve=yes
		  BufferManager::SetDefaultBuffer(buffer);
        //## end RMSProfileMonitor::SetDefaultBuffer%925300220.body
      }

      //## Operation: GetIndex%925300221
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetType%925300222
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: MakeMeasurement%925300240; C++
      //	Pure virtual function. Makes a measurement on the
      //	supplied Beam object. Concrete diagnostics must supply
      //	this function.
      virtual void MakeMeasurement (const Bunch& aBunch);

      //## Operation: PrepareTracker%925300223
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: Copy%925300224
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%37272868035C
      //## begin RMSProfileMonitor::ID%37272868035C.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end RMSProfileMonitor::ID%37272868035C.attr

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: res_x%3724A7FD0104
      //## begin RMSProfileMonitor::res_x%3724A7FD0104.attr preserve=no  private: double {UA} 
      double res_x;
      //## end RMSProfileMonitor::res_x%3724A7FD0104.attr

      //## Attribute: res_y%3724A8080208
      //## begin RMSProfileMonitor::res_y%3724A8080208.attr preserve=no  private: double {UA} 
      double res_y;
      //## end RMSProfileMonitor::res_y%3724A8080208.attr

      //## Attribute: res_u%3724A80D0050
      //## begin RMSProfileMonitor::res_u%3724A80D0050.attr preserve=no  private: double {UA} 
      double res_u;
      //## end RMSProfileMonitor::res_u%3724A80D0050.attr

      //## Attribute: uangle%3724A860026C
      //## begin RMSProfileMonitor::uangle%3724A860026C.attr preserve=no  private: double {UA} 
      double uangle;
      //## end RMSProfileMonitor::uangle%3724A860026C.attr

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::ActiveMonitors::<unnamed>%3ACB3EB903CA
      //## Role: RMSProfileMonitor::buffers%3ACB3EBA019B
      //## begin RMSProfileMonitor::buffers%3ACB3EBA019B.role preserve=no  private: RMSProfileMonitor::BufferManager { -> 1VHAN}
      BufferManager buffers;
      //## end RMSProfileMonitor::buffers%3ACB3EBA019B.role

  private:  //## implementation
};

//## begin module%372703980168.epilog preserve=yes
//## end module%372703980168.epilog


#endif

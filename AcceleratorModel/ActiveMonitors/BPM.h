//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%372703970096.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\ActiveMonitors\BPM.h
 * last modified 09/13/01 12:16:37 PM
 */
//## end module%372703970096.cm

//## begin module%372703970096.cp preserve=no
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
//## end module%372703970096.cp

//## Module: BPM%372703970096; Package specification
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
//## Source file: C:\C++\Merlin\AcceleratorModel\ActiveMonitors\BPM.h

#ifndef BPM_h
#define BPM_h 1

//## begin module%372703970096.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%372703970096.additionalIncludes

//## begin module%372703970096.includes preserve=yes
#include <set>
//## end module%372703970096.includes

// Monitor
#include "AcceleratorModel/StdComponent/Monitor.h"
// AMBufferManager
#include "AcceleratorModel/ActiveMonitors/AMBufferManager.h"
// Measurement
#include "NumericalUtils/Measurement.h"

class Bunch;
class BPM;
class ComponentTracker;

//## begin module%372703970096.additionalDeclarations preserve=yes
//## end module%372703970096.additionalDeclarations


//## Class: BPM%3724A78703DE
//	A Beam Position Monitor
//## Category: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: creates%3724AAD900FA;BPM::Data { -> F}
//## Uses: <unnamed>%372597410348;RandomNG { -> }
//## Uses: <unnamed>%3725DA6D024E;ComponentTracker { -> F}
//## Uses: <unnamed>%3725908C010E;Bunch { -> F}

class BPM : public Monitor  //## Inherits: <unnamed>%3AC4E8FB0398
{
  public:
    //## Class: Data%3724AACB02E4
    //## Category: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
    //## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: <unnamed>%3724AB9D0370;Measurement { -> }

    class Data 
    {
      public:
        // Data Members for Class Attributes

          //## Attribute: ct%37341DC90244
          //## begin BPM::Data::ct%37341DC90244.attr preserve=no  public: double {UA} 
          double ct;
          //## end BPM::Data::ct%37341DC90244.attr

          //## Attribute: x%3724AAE10294
          //## begin BPM::Data::x%3724AAE10294.attr preserve=no  public: Measurement {UA} 
          Measurement x;
          //## end BPM::Data::x%3724AAE10294.attr

          //## Attribute: y%3724AAE701E0
          //## begin BPM::Data::y%3724AAE701E0.attr preserve=no  public: Measurement {UA} 
          Measurement y;
          //## end BPM::Data::y%3724AAE701E0.attr

      protected:
      private:
      private: //## implementation
    };

    //## Class: Buffer%3ACB2C5C0014; Abstract
    //	Buffer used by  BPM objects to record the results of a
    //	measurement. A single buffer can be associated with many
    //	BPM objects. When a BPM makes a measurement, it sends
    //	the results to its associated buffer using a BPM::Data
    //	struct via the Record() method.
    //## Category: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
    //## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: <unnamed>%3ACC58790280;Data { -> F}

    class Buffer 
    {
      public:
        //## Destructor (specified)
          //## Operation: ~Buffer%3ACB2C9D0258
          virtual ~Buffer ();


        //## Other Operations (specified)
          //## Operation: Record%3ACB2C9D0294
          virtual void Record (const BPM& aBPM, const Data& data) = 0;

      protected:
      private:
      private: //## implementation
    };

    //## Class: BufferManager%3ACB2C6003C0; Instantiated Class
    //## Category: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
    //## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%37270360029E
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: <unnamed>%3ACB2CF6001E;BPM { -> F}
    //## Uses: <unnamed>%3ACB38250316;Buffer { -> }
    //## Uses: <unnamed>%3ACB3E1C003C;Data { -> }

    typedef AMBufferManager< BPM , Buffer , Data  > BufferManager;

    //## Constructors (specified)
      //## Operation: BPM%37258E0200AA
      //	BPM constructing taking the id, the length and
      //	measurement point of the device.
      explicit BPM (const string& id, double len = 0, double mpos = 0);


    //## Other Operations (specified)
      //## Operation: SetResolution%37258E1901FE
      //	Set the resolution (rms noise levels) for the BPM.
      void SetResolution (double xr, double yr);
      double SetRes (double r) {
		  SetResolution(r,r); return r;
	  }
      //## Operation: SetScale%3BA086F8010F
      //	Sets the scale factor for x and y planes (default scale
      //	=1).
      void SetScale (double xs, double ys);

      //## Operation: MakeMeasurement%37258EEE03B6; C++
      //	Measure the beam centroid of bunch.
      virtual void MakeMeasurement (const Bunch& aBunch);

      //## Operation: GetIndex%37258EFC00BE
      //	Returns the index for a BPM.
      virtual int GetIndex () const;

      //## Operation: GetType%37258F0000C8
      //	Returns the type string "BPM".
      virtual const string& GetType () const;

      //## Operation: PrepareTracker%37258F0701C2
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: Copy%37258F0F03C0
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

      //## Operation: AddBuffer%37258F3B02A8
      //	Sets the buffer to aBuffer. If a null pointer is passed,
      //	then no specific buffer is associated with this BPM, and
      //	the default buffer will be used (if not null).
      void AddBuffer (Buffer* abuffer);

      //## Operation: RemoveBuffer%3AC4EA2E015E
      bool RemoveBuffer (Buffer* aBuffer);

      //## Operation: ClearAllBuffers%3ACB324603D4
      //	Removes all buffers associated with this BPM.
      void ClearAllBuffers ();

      //## Operation: SetDefaultBuffer%372596950140
      //	Set the default buffer to be used by all BPMs, unless
      //	they are associated with a specific buffer.
      static void SetDefaultBuffer (Buffer* buffer);

    // Data Members for Class Attributes

      //## Attribute: ID%3726FEF001E0
      //## begin BPM::ID%3726FEF001E0.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end BPM::ID%3726FEF001E0.attr

	  static bool generate_noise;

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::ActiveMonitors::<unnamed>%3ACC4E060000
      //## Role: BPM::buffers%3ACC4E060002
      //## begin BPM::buffers%3ACC4E060002.role preserve=no  public: BPM::Buffer { -> 0..nRHADN}
      //## end BPM::buffers%3ACC4E060002.role

  public:
  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: res_x%3724A7A001EA
      //	x resolution (rms noise) in meters.
      //## begin BPM::res_x%3724A7A001EA.attr preserve=no  private: double {UA} 
      double res_x;
      //## end BPM::res_x%3724A7A001EA.attr

      //## Attribute: res_y%3724A7A902D0
      //	y resolution (rms noise) in meters.
      //## begin BPM::res_y%3724A7A902D0.attr preserve=no  private: double {UA} 
      double res_y;
      //## end BPM::res_y%3724A7A902D0.attr

      //## Attribute: scale_x%3BA086DE013A
      //## begin BPM::scale_x%3BA086DE013A.attr preserve=no  private: double {UA} 
      double scale_x;
      //## end BPM::scale_x%3BA086DE013A.attr

      //## Attribute: scale_y%3BA086E501C6
      //## begin BPM::scale_y%3BA086E501C6.attr preserve=no  private: double {UA} 
      double scale_y;
      //## end BPM::scale_y%3BA086E501C6.attr

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::ActiveMonitors::<unnamed>%3ACB2D120398
      //## Role: BPM::buffers%3ACB2D14023A
      //## begin BPM::buffers%3ACB2D14023A.role preserve=no  private: BPM::BufferManager { -> 1VHgAN}
      BufferManager buffers;
      //## end BPM::buffers%3ACB2D14023A.role

  private: //## implementation

    //## Other Operations (specified)
      //## Operation: TakeData%3ACB24190118
      //	Returns true if data is to be taken.
      bool TakeData () const;

};

// Class BPM::Data 

// Class BPM::Buffer 

//## Operation: ~Buffer%3ACB2C9D0258
inline BPM::Buffer::~Buffer ()
{
  //## begin BPM::Buffer::~Buffer%3ACB2C9D0258.body preserve=yes
  //## end BPM::Buffer::~Buffer%3ACB2C9D0258.body
}


// Class BPM 

//## Operation: BPM%37258E0200AA
inline BPM::BPM (const string& id, double len, double mpos)
  //## begin BPM::BPM%37258E0200AA.initialization preserve=yes
  : Monitor(id,len,mpos),res_x(0),res_y(0),
    scale_x(1),scale_y(1),buffers()
  //## end BPM::BPM%37258E0200AA.initialization
{
  //## begin BPM::BPM%37258E0200AA.body preserve=yes
  //## end BPM::BPM%37258E0200AA.body
}



//## Other Operations (inline)
//## Operation: SetResolution%37258E1901FE
inline void BPM::SetResolution (double xr, double yr)
{
  //## begin BPM::SetResolution%37258E1901FE.body preserve=yes
	res_x=xr;
	res_y=yr;
//	res_q=qr;
  //## end BPM::SetResolution%37258E1901FE.body
}

//## Operation: AddBuffer%37258F3B02A8
inline void BPM::AddBuffer (BPM::Buffer* abuffer)
{
  //## begin BPM::AddBuffer%37258F3B02A8.body preserve=yes
	buffers.AddBuffer(abuffer);
  //## end BPM::AddBuffer%37258F3B02A8.body
}

//## Operation: RemoveBuffer%3AC4EA2E015E
inline bool BPM::RemoveBuffer (BPM::Buffer* aBuffer)
{
  //## begin BPM::RemoveBuffer%3AC4EA2E015E.body preserve=yes
	return buffers.RemoveBuffer(aBuffer);
  //## end BPM::RemoveBuffer%3AC4EA2E015E.body
}

//## Operation: ClearAllBuffers%3ACB324603D4
inline void BPM::ClearAllBuffers ()
{
  //## begin BPM::ClearAllBuffers%3ACB324603D4.body preserve=yes
	buffers.ClearAllBuffers();
  //## end BPM::ClearAllBuffers%3ACB324603D4.body
}

//## Operation: SetDefaultBuffer%372596950140
inline void BPM::SetDefaultBuffer (BPM::Buffer* buffer)
{
  //## begin BPM::SetDefaultBuffer%372596950140.body preserve=yes
	BufferManager::SetDefaultBuffer(buffer);
  //## end BPM::SetDefaultBuffer%372596950140.body
}

//## Operation: TakeData%3ACB24190118
inline bool BPM::TakeData () const
{
  //## begin BPM::TakeData%3ACB24190118.body preserve=yes
	return IsActive() && !buffers.empty();
  //## end BPM::TakeData%3ACB24190118.body
}

//## begin module%372703970096.epilog preserve=yes
//## end module%372703970096.epilog


#endif

//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3C14B28B02D1.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdComponent\Solenoid.h
 * last modified 10/12/01 16:41:41
 */
//## end module%3C14B28B02D1.cm

//## begin module%3C14B28B02D1.cp preserve=no
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
//## end module%3C14B28B02D1.cp

//## Module: Solenoid%3C14B28B02D1; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: C:\C++\Merlin\AcceleratorModel\StdComponent\Solenoid.h

#ifndef Solenoid_h
#define Solenoid_h 1

//## begin module%3C14B28B02D1.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3C14B28B02D1.additionalIncludes

//## begin module%3C14B28B02D1.includes preserve=yes
//## end module%3C14B28B02D1.includes

// SimpleSolenoid
#include "AcceleratorModel/StdComponent/SimpleSolenoid.h"
//## begin module%3C14B28B02D1.additionalDeclarations preserve=yes
//## end module%3C14B28B02D1.additionalDeclarations


//## Class: Solenoid%3C14B28B02D1
//	A simple solenoid with field Bz.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n



class Solenoid : public SimpleSolenoid  //## Inherits: <unnamed>%3C14B297013E
{
  public:
    //## Constructors (specified)
      //## Operation: Solenoid%3C14B2C20104
      Solenoid (const std::string& id, double len, double Bz);


    //## Other Operations (specified)
      //## Operation: GetBz%3C14B5F40240
      //	Returns the value of the field in Tesla.
      double GetBz () const;

      //## Operation: SetBz%3C14B60E0388
      //	Sets the value of the field in Tesla.
      void SetBz (double B);

      //## Operation: RotateY180%3C14B5870009
      //	Rotates the component 180 degrees about its local Y axis.
      virtual void RotateY180 ();

      //## Operation: GetType%3C14B5630332
      //	Return the type string for the element.
      virtual const string& GetType () const;

      //## Operation: Copy%3C14B572013F
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

      //## Operation: GetIndex%3C14D4E300D5
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: PrepareTracker%3C14D7A20130
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

    // Data Members for Class Attributes

      //## Attribute: ID%3C14B5CD005A
      //## begin Solenoid::ID%3C14B5CD005A.attr preserve=no  public: static int {UAC} UniqueIndex()
      static const int ID;
      //## end Solenoid::ID%3C14B5CD005A.attr

  protected:
  private:
  private: //## implementation
};

// Class Solenoid 


//## Other Operations (inline)
//## Operation: GetBz%3C14B5F40240
inline double Solenoid::GetBz () const
{
  //## begin Solenoid::GetBz%3C14B5F40240.body preserve=yes
	return GetField().GetStrength();
  //## end Solenoid::GetBz%3C14B5F40240.body
}

//## Operation: SetBz%3C14B60E0388
inline void Solenoid::SetBz (double B)
{
  //## begin Solenoid::SetBz%3C14B60E0388.body preserve=yes
	GetField().SetStrength(B);
  //## end Solenoid::SetBz%3C14B60E0388.body
}

//## begin module%3C14B28B02D1.epilog preserve=yes
//## end module%3C14B28B02D1.epilog


#endif

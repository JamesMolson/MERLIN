//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%371F5B6700D2.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdComponent\StandardMultipoles.h
 * last modified 16/05/02 11:10:34
 */
//## end module%371F5B6700D2.cm

//## begin module%371F5B6700D2.cp preserve=no
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
//## end module%371F5B6700D2.cp

//## Module: StandardMultipoles%371F5B6700D2; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: C:\C++\Merlin\AcceleratorModel\StdComponent\StandardMultipoles.h

#ifndef StandardMultipoles_h
#define StandardMultipoles_h 1

//## begin module%371F5B6700D2.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%371F5B6700D2.additionalIncludes

//## begin module%371F5B6700D2.includes preserve=yes
//## end module%371F5B6700D2.includes

// RectMultipole
#include "AcceleratorModel/StdComponent/RectMultipole.h"

class ComponentTracker;

//## begin module%371F5B6700D2.additionalDeclarations preserve=yes
// type strings for template parameter instantiation
//## end module%371F5B6700D2.additionalDeclarations


//## Class: Quadrupole%371F39E4026C
//	A standard quadrupole magnet.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3720B7240212;ComponentTracker { -> F}

class Quadrupole : public RectMultipole  //## Inherits: <unnamed>%371F39F602E4
{
  public:
    //## Constructors (specified)
      //## Operation: Quadrupole%371F4EFE0258
      //	Constructor. The primary field component is specified as
      //	a the quadrupole gradient. Units are Tesla/meter.
      Quadrupole (const string& id, double len, double dnB);

      //## Operation: Quadrupole%371F4E9F03C0
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      Quadrupole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%371F4D64001E
      //	Initialise aTracker with *this.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%371F4D6E0014
      //	Returns the unique index for a Quadrupole
      virtual int GetIndex () const;

      //## Operation: GetType%3720408F0032
      //	Returns the type string "Quadrupole"
      virtual const string& GetType () const;

      //## Operation: Copy%372040950244
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3720BE2A023A
      //## begin Quadrupole::ID%3720BE2A023A.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end Quadrupole::ID%3720BE2A023A.attr

  protected:
  private:
  private: //## implementation
};

//## Class: Sextupole%3721C272033E
//	A standard sextupole magnet.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3721C6310154;ComponentTracker { -> F}

class Sextupole : public RectMultipole  //## Inherits: <unnamed>%3721C273000D
{
  public:
    //## Constructors (specified)
      //## Operation: Sextupole%3721C27203AD
      //	Constructor. The primary field component is specified as
      //	a the sextupole gradient. Units are Tesla/meter^2.
      Sextupole (const string& id, double len, double dnB);

      //## Operation: Sextupole%3721C2730003
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      Sextupole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%3721C2730008
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%3721C273000A
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetType%3721C273000B
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: Copy%3721C273000C
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3721C27203AC
      //## begin Sextupole::ID%3721C27203AC.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end Sextupole::ID%3721C27203AC.attr

  protected:
  private:
  private: //## implementation
};

//## Class: SkewQuadrupole%3721C2EB037A
//	 A standard skew-quadrupole magnet.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3721C62C0262;ComponentTracker { -> F}

class SkewQuadrupole : public RectMultipole  //## Inherits: <unnamed>%3721C2F7032A
{
  public:
    //## Constructors (specified)
      //## Operation: SkewQuadrupole%3721C3190172
      //	Constructor. The primary field component is specified as
      //	a the quadrupole gradient. Units are Tesla/meter.
      SkewQuadrupole (const string& id, double len, double dnB);

      //## Operation: SkewQuadrupole%3721C31901E0
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      SkewQuadrupole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%3721C3190212
      //	Initialise aTracker to track *this.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%3721C319024E
      //	Return the index for a SkewQuadrupole.
      virtual int GetIndex () const;

      //## Operation: GetType%3721C3190280
      //	Returns the type string "SkewQuadrupole".
      virtual const string& GetType () const;

      //## Operation: Copy%3721C31902BC
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3721C45302F8
      //## begin SkewQuadrupole::ID%3721C45302F8.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end SkewQuadrupole::ID%3721C45302F8.attr

  protected:
  private:
  private: //## implementation
};

//## Class: Octupole%3721C335021C
//	A standard Octupole magnet.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3721C63301A4;ComponentTracker { -> F}

class Octupole : public RectMultipole  //## Inherits: <unnamed>%3721C35B03AC
{
  public:
    //## Constructors (specified)
      //## Operation: Octupole%3721C34B0014
      //	Constructor. The primary field component is specified as
      //	a the octupole gradient. Units are Tesla/meter^3.
      Octupole (const string& id, double len, double dnB);

      //## Operation: Octupole%3721C34B0046
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      Octupole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%3721C34B0082
      //	Initialise aTracker to track *this.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%3721C34B0084
      //	Returns the index for an Octupole.
      virtual int GetIndex () const;

      //## Operation: GetType%3721C34B00B4
      //	Returns the type string "Octupole".
      virtual const string& GetType () const;

      //## Operation: Copy%3721C34B00F0
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3721C4AF017C
      //## begin Octupole::ID%3721C4AF017C.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end Octupole::ID%3721C4AF017C.attr

  protected:
  private:
  private: //## implementation
};

//## Class: SkewSextupole%3AC87F1301F4
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n



class SkewSextupole : public RectMultipole  //## Inherits: <unnamed>%3AC87F2B03AC
{
  public:
    //## Constructors (specified)
      //## Operation: SkewSextupole%3AC87F460352
      //	Constructor. The primary field component is specified as
      //	a the sextupole gradient. Units are Tesla/meter^2.
      SkewSextupole (const string& id, double len, double dnB);

      //## Operation: SkewSextupole%3AC87F46038E
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      SkewSextupole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%3AC87F4603C0
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%3AC87F470014
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetType%3AC87F470046
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: Copy%3AC87F470082
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3AC87F9402E4
      //## begin SkewSextupole::ID%3AC87F9402E4.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end SkewSextupole::ID%3AC87F9402E4.attr

  protected:
  private:
  private: //## implementation
};

//## Class: Decapole%3CE376C90380
//	A standard (normal) decapole magnet.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n



class Decapole : public RectMultipole  //## Inherits: <unnamed>%3CE3771000D9
{
  public:
    //## Constructors (specified)
      //## Operation: Decapole%3CE3773A00BB
      //	Constructor. The primary field component is specified as
      //	a the octupole gradient. Units are Tesla/meter^4.
      Decapole (const string& id, double len, double dnB);

      //## Operation: Decapole%3CE3773A00C5
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      Decapole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%3CE3773A00CF
      //	Initialise aTracker to track *this.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%3CE3773A00D9
      //	Returns the index for an Octupole.
      virtual int GetIndex () const;

      //## Operation: GetType%3CE3773A00DA
      //	Returns the type string "Octupole".
      virtual const string& GetType () const;

      //## Operation: Copy%3CE3773A00E3
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

      static const int ID;

  protected:
  private:
  private: //## implementation
};

// Class Quadrupole 

// Class Sextupole 

// Class SkewQuadrupole 

// Class Octupole 

// Class SkewSextupole 

// Class Decapole 

//## begin module%371F5B6700D2.epilog preserve=yes
//## end module%371F5B6700D2.epilog


#endif

//## begin module%371F5B6700D2.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\StandardMultipoles.h
 * last modified 03/04/01 14:21:39
 */
//## end module%371F5B6700D2.cm

//## begin module%371F5B6700D2.cp preserve=no
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
//## end module%371F5B6700D2.cp

//## Module: StandardMultipoles%371F5B6700D2; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\StandardMultipoles.h

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

//## begin module%371F5B6700D2.declarations preserve=no
//## end module%371F5B6700D2.declarations

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
      //## Operation: Quadrupole%924771670
      //	Constructor. The primary field component is specified as
      //	a the quadrupole gradient. Units are Tesla/meter.
      Quadrupole (const string& id, double len, double dnB);

      //## Operation: Quadrupole%924771669
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      Quadrupole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%924771671
      //	Initialise aTracker with *this.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%924771672
      //	Returns the unique index for a Quadrupole
      virtual int GetIndex () const;

      //## Operation: GetType%924860387
      //	Returns the type string "Quadrupole"
      virtual const string& GetType () const;

      //## Operation: Copy%924860388
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3720BE2A023A
      //## begin Quadrupole::ID%3720BE2A023A.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end Quadrupole::ID%3720BE2A023A.attr

  protected:
  private:
  private:  //## implementation
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
      //## Operation: Sextupole%924960066
      //	Constructor. The primary field component is specified as
      //	a the sextupole gradient. Units are Tesla/meter^2.
      Sextupole (const string& id, double len, double dnB);

      //## Operation: Sextupole%924960067
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      Sextupole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%924960068
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%924960069
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetType%924960070
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: Copy%924960071
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3721C27203AC
      //## begin Sextupole::ID%3721C27203AC.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end Sextupole::ID%3721C27203AC.attr

  protected:
  private:
  private:  //## implementation
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
      //## Operation: SkewQuadrupole%924960072
      //	Constructor. The primary field component is specified as
      //	a the quadrupole gradient. Units are Tesla/meter.
      SkewQuadrupole (const string& id, double len, double dnB);

      //## Operation: SkewQuadrupole%924960073
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      SkewQuadrupole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%924960074
      //	Initialise aTracker to track *this.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%924960075
      //	Return the index for a SkewQuadrupole.
      virtual int GetIndex () const;

      //## Operation: GetType%924960076
      //	Returns the type string "SkewQuadrupole".
      virtual const string& GetType () const;

      //## Operation: Copy%924960077
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3721C45302F8
      //## begin SkewQuadrupole::ID%3721C45302F8.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end SkewQuadrupole::ID%3721C45302F8.attr

  protected:
  private:
  private:  //## implementation
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
      //## Operation: Octupole%924960078
      //	Constructor. The primary field component is specified as
      //	a the octupole gradient. Units are Tesla/meter^3.
      Octupole (const string& id, double len, double dnB);

      //## Operation: Octupole%924960079
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      Octupole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%924960080
      //	Initialise aTracker to track *this.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%924960081
      //	Returns the index for an Octupole.
      virtual int GetIndex () const;

      //## Operation: GetType%924960082
      //	Returns the type string "Octupole".
      virtual const string& GetType () const;

      //## Operation: Copy%924960083
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3721C4AF017C
      //## begin Octupole::ID%3721C4AF017C.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end Octupole::ID%3721C4AF017C.attr

  protected:
  private:
  private:  //## implementation
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
      //## Operation: SkewSextupole%986295714
      //	Constructor. The primary field component is specified as
      //	a the sextupole gradient. Units are Tesla/meter^2.
      SkewSextupole (const string& id, double len, double dnB);

      //## Operation: SkewSextupole%986295715
      //	Constructor. The primary field component is specified as
      //	a field B (in Tesla) at a speciific radius r0 (in meter).
      SkewSextupole (const string& id, double len, double B, double r0);


    //## Other Operations (specified)
      //## Operation: PrepareTracker%986295716
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: GetIndex%986295717
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetType%986295718
      //	Returns the type string for this component.
      virtual const string& GetType () const;

      //## Operation: Copy%986295719
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

    // Data Members for Class Attributes

      //## Attribute: ID%3AC87F9402E4
      //## begin SkewSextupole::ID%3AC87F9402E4.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end SkewSextupole::ID%3AC87F9402E4.attr

  protected:
  private:
  private:  //## implementation
};

// Class Quadrupole 

// Class Sextupole 

// Class SkewQuadrupole 

// Class Octupole 

// Class SkewSextupole 

//## begin module%371F5B6700D2.epilog preserve=yes
//## end module%371F5B6700D2.epilog


#endif

//## begin module%371F5B690316.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\StandardMultipoles.cpp
 * last modified 03/04/01 14:21:38
 */
//## end module%371F5B690316.cm

//## begin module%371F5B690316.cp preserve=no
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
//## end module%371F5B690316.cp

//## Module: StandardMultipoles%371F5B690316; Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\StandardMultipoles.cpp

//## begin module%371F5B690316.includes preserve=yes
//## end module%371F5B690316.includes

// StandardMultipoles
#include "AcceleratorModel/StdComponent/StandardMultipoles.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"


//## begin module%371F5B690316.declarations preserve=no
//## end module%371F5B690316.declarations

//## begin module%371F5B690316.additionalDeclarations preserve=yes
#define _RMC1(n)  RectMultipole(id,len,n,dnB)
#define _RMC2(n)  RectMultipole(id,len,n,B,r0)
#define _RMSC1(n)  RectMultipole(id,len,n,dnB,true)
#define _RMSC2(n)  RectMultipole(id,len,n,B,r0,true)
#define _MPT _PREPTRACK(aTracker,RectMultipole);
#define _RID return ID;
#define _CP(type) return new type (*this);
//## end module%371F5B690316.additionalDeclarations


// Class Quadrupole 

//## begin Quadrupole::ID%3720BE2A023A.attr preserve=no  public: static const int {UA} UniqueIndex()
const int Quadrupole::ID = UniqueIndex();
//## end Quadrupole::ID%3720BE2A023A.attr

//## Operation: Quadrupole%924771670
Quadrupole::Quadrupole (const string& id, double len, double dnB)
  //## begin Quadrupole::Quadrupole%924771670.initialization preserve=yes
  : _RMC1(1)
  //## end Quadrupole::Quadrupole%924771670.initialization
{
  //## begin Quadrupole::Quadrupole%924771670.body preserve=yes
  //## end Quadrupole::Quadrupole%924771670.body
}

//## Operation: Quadrupole%924771669
Quadrupole::Quadrupole (const string& id, double len, double B, double r0)
  //## begin Quadrupole::Quadrupole%924771669.initialization preserve=yes
  : _RMC2(1)
  //## end Quadrupole::Quadrupole%924771669.initialization
{
  //## begin Quadrupole::Quadrupole%924771669.body preserve=yes
  //## end Quadrupole::Quadrupole%924771669.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%924771671
void Quadrupole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Quadrupole::PrepareTracker%924771671.body preserve=yes
	_MPT
  //## end Quadrupole::PrepareTracker%924771671.body
}

//## Operation: GetIndex%924771672
int Quadrupole::GetIndex () const
{
  //## begin Quadrupole::GetIndex%924771672.body preserve=yes
	_RID
  //## end Quadrupole::GetIndex%924771672.body
}

//## Operation: GetType%924860387
const string& Quadrupole::GetType () const
{
  //## begin Quadrupole::GetType%924860387.body preserve=yes
	_TYPESTR(Quadrupole)
  //## end Quadrupole::GetType%924860387.body
}

//## Operation: Copy%924860388
ModelElement* Quadrupole::Copy () const
{
  //## begin Quadrupole::Copy%924860388.body preserve=yes
	_CP(Quadrupole)
  //## end Quadrupole::Copy%924860388.body
}

// Class Sextupole 

//## begin Sextupole::ID%3721C27203AC.attr preserve=no  public: static const int {UA} UniqueIndex()
const int Sextupole::ID = UniqueIndex();
//## end Sextupole::ID%3721C27203AC.attr

//## Operation: Sextupole%924960066
Sextupole::Sextupole (const string& id, double len, double dnB)
  //## begin Sextupole::Sextupole%924960066.initialization preserve=yes
  : _RMC1(2)
  //## end Sextupole::Sextupole%924960066.initialization
{
  //## begin Sextupole::Sextupole%924960066.body preserve=yes
  //## end Sextupole::Sextupole%924960066.body
}

//## Operation: Sextupole%924960067
Sextupole::Sextupole (const string& id, double len, double B, double r0)
  //## begin Sextupole::Sextupole%924960067.initialization preserve=yes
  : _RMC2(2)
  //## end Sextupole::Sextupole%924960067.initialization
{
  //## begin Sextupole::Sextupole%924960067.body preserve=yes
  //## end Sextupole::Sextupole%924960067.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%924960068
void Sextupole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Sextupole::PrepareTracker%924960068.body preserve=yes
	_MPT
  //## end Sextupole::PrepareTracker%924960068.body
}

//## Operation: GetIndex%924960069
int Sextupole::GetIndex () const
{
  //## begin Sextupole::GetIndex%924960069.body preserve=yes
	_RID
  //## end Sextupole::GetIndex%924960069.body
}

//## Operation: GetType%924960070
const string& Sextupole::GetType () const
{
  //## begin Sextupole::GetType%924960070.body preserve=yes
	_TYPESTR(Sextupole);
  //## end Sextupole::GetType%924960070.body
}

//## Operation: Copy%924960071
ModelElement* Sextupole::Copy () const
{
  //## begin Sextupole::Copy%924960071.body preserve=yes
	_CP(Sextupole)
  //## end Sextupole::Copy%924960071.body
}

// Class SkewQuadrupole 

//## begin SkewQuadrupole::ID%3721C45302F8.attr preserve=no  public: static const int {UA} UniqueIndex()
const int SkewQuadrupole::ID = UniqueIndex();
//## end SkewQuadrupole::ID%3721C45302F8.attr

//## Operation: SkewQuadrupole%924960072
SkewQuadrupole::SkewQuadrupole (const string& id, double len, double dnB)
  //## begin SkewQuadrupole::SkewQuadrupole%924960072.initialization preserve=yes
  : _RMSC1(1)
  //## end SkewQuadrupole::SkewQuadrupole%924960072.initialization
{
  //## begin SkewQuadrupole::SkewQuadrupole%924960072.body preserve=yes
  //## end SkewQuadrupole::SkewQuadrupole%924960072.body
}

//## Operation: SkewQuadrupole%924960073
SkewQuadrupole::SkewQuadrupole (const string& id, double len, double B, double r0)
  //## begin SkewQuadrupole::SkewQuadrupole%924960073.initialization preserve=yes
  : _RMSC2(1)
  //## end SkewQuadrupole::SkewQuadrupole%924960073.initialization
{
  //## begin SkewQuadrupole::SkewQuadrupole%924960073.body preserve=yes
  //## end SkewQuadrupole::SkewQuadrupole%924960073.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%924960074
void SkewQuadrupole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin SkewQuadrupole::PrepareTracker%924960074.body preserve=yes
	_MPT
  //## end SkewQuadrupole::PrepareTracker%924960074.body
}

//## Operation: GetIndex%924960075
int SkewQuadrupole::GetIndex () const
{
  //## begin SkewQuadrupole::GetIndex%924960075.body preserve=yes
	_RID
  //## end SkewQuadrupole::GetIndex%924960075.body
}

//## Operation: GetType%924960076
const string& SkewQuadrupole::GetType () const
{
  //## begin SkewQuadrupole::GetType%924960076.body preserve=yes
	_TYPESTR(SkewQuadrupole)
  //## end SkewQuadrupole::GetType%924960076.body
}

//## Operation: Copy%924960077
ModelElement* SkewQuadrupole::Copy () const
{
  //## begin SkewQuadrupole::Copy%924960077.body preserve=yes
	_CP(SkewQuadrupole)
  //## end SkewQuadrupole::Copy%924960077.body
}

// Class Octupole 

//## begin Octupole::ID%3721C4AF017C.attr preserve=no  public: static const int {UA} UniqueIndex()
const int Octupole::ID = UniqueIndex();
//## end Octupole::ID%3721C4AF017C.attr

//## Operation: Octupole%924960078
Octupole::Octupole (const string& id, double len, double dnB)
  //## begin Octupole::Octupole%924960078.initialization preserve=yes
  : _RMC1(3)
  //## end Octupole::Octupole%924960078.initialization
{
  //## begin Octupole::Octupole%924960078.body preserve=yes
  //## end Octupole::Octupole%924960078.body
}

//## Operation: Octupole%924960079
Octupole::Octupole (const string& id, double len, double B, double r0)
  //## begin Octupole::Octupole%924960079.initialization preserve=yes
  : _RMC2(3)
  //## end Octupole::Octupole%924960079.initialization
{
  //## begin Octupole::Octupole%924960079.body preserve=yes
  //## end Octupole::Octupole%924960079.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%924960080
void Octupole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Octupole::PrepareTracker%924960080.body preserve=yes
	_MPT
  //## end Octupole::PrepareTracker%924960080.body
}

//## Operation: GetIndex%924960081
int Octupole::GetIndex () const
{
  //## begin Octupole::GetIndex%924960081.body preserve=yes
	_RID
  //## end Octupole::GetIndex%924960081.body
}

//## Operation: GetType%924960082
const string& Octupole::GetType () const
{
  //## begin Octupole::GetType%924960082.body preserve=yes
	_TYPESTR(Octupole)
  //## end Octupole::GetType%924960082.body
}

//## Operation: Copy%924960083
ModelElement* Octupole::Copy () const
{
  //## begin Octupole::Copy%924960083.body preserve=yes
	_CP(Octupole)
  //## end Octupole::Copy%924960083.body
}

// Class SkewSextupole 

//## begin SkewSextupole::ID%3AC87F9402E4.attr preserve=no  public: static const int {UA} UniqueIndex()
const int SkewSextupole::ID = UniqueIndex();
//## end SkewSextupole::ID%3AC87F9402E4.attr

//## Operation: SkewSextupole%986295714
SkewSextupole::SkewSextupole (const string& id, double len, double dnB)
  //## begin SkewSextupole::SkewSextupole%986295714.initialization preserve=yes
  : _RMSC1(2)
  //## end SkewSextupole::SkewSextupole%986295714.initialization
{
  //## begin SkewSextupole::SkewSextupole%986295714.body preserve=yes
  //## end SkewSextupole::SkewSextupole%986295714.body
}

//## Operation: SkewSextupole%986295715
SkewSextupole::SkewSextupole (const string& id, double len, double B, double r0)
  //## begin SkewSextupole::SkewSextupole%986295715.initialization preserve=yes
  : _RMSC2(2)
  //## end SkewSextupole::SkewSextupole%986295715.initialization
{
  //## begin SkewSextupole::SkewSextupole%986295715.body preserve=yes
  //## end SkewSextupole::SkewSextupole%986295715.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%986295716
void SkewSextupole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin SkewSextupole::PrepareTracker%986295716.body preserve=yes
	_MPT
  //## end SkewSextupole::PrepareTracker%986295716.body
}

//## Operation: GetIndex%986295717
int SkewSextupole::GetIndex () const
{
  //## begin SkewSextupole::GetIndex%986295717.body preserve=yes
	_RID
  //## end SkewSextupole::GetIndex%986295717.body
}

//## Operation: GetType%986295718
const string& SkewSextupole::GetType () const
{
  //## begin SkewSextupole::GetType%986295718.body preserve=yes
	_TYPESTR(SkewSextupole)
  //## end SkewSextupole::GetType%986295718.body
}

//## Operation: Copy%986295719
ModelElement* SkewSextupole::Copy () const
{
  //## begin SkewSextupole::Copy%986295719.body preserve=yes
	_CP(SkewSextupole)
  //## end SkewSextupole::Copy%986295719.body
}

//## begin module%371F5B690316.epilog preserve=yes
//## end module%371F5B690316.epilog

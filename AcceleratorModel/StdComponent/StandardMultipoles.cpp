//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%371F5B690316.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdComponent\StandardMultipoles.cpp
 * last modified 16/05/02 11:10:34
 */
//## end module%371F5B690316.cm

//## begin module%371F5B690316.cp preserve=no
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
//## end module%371F5B690316.cp

//## Module: StandardMultipoles%371F5B690316; Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: C:\C++\Merlin\AcceleratorModel\StdComponent\StandardMultipoles.cpp

//## begin module%371F5B690316.includes preserve=yes
//## end module%371F5B690316.includes

// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"
// StandardMultipoles
#include "AcceleratorModel/StdComponent/StandardMultipoles.h"


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

//## Operation: Quadrupole%371F4EFE0258
Quadrupole::Quadrupole (const string& id, double len, double dnB)
  //## begin Quadrupole::Quadrupole%371F4EFE0258.initialization preserve=yes
  : _RMC1(1)
  //## end Quadrupole::Quadrupole%371F4EFE0258.initialization
{
  //## begin Quadrupole::Quadrupole%371F4EFE0258.body preserve=yes
  //## end Quadrupole::Quadrupole%371F4EFE0258.body
}

//## Operation: Quadrupole%371F4E9F03C0
Quadrupole::Quadrupole (const string& id, double len, double B, double r0)
  //## begin Quadrupole::Quadrupole%371F4E9F03C0.initialization preserve=yes
  : _RMC2(1)
  //## end Quadrupole::Quadrupole%371F4E9F03C0.initialization
{
  //## begin Quadrupole::Quadrupole%371F4E9F03C0.body preserve=yes
  //## end Quadrupole::Quadrupole%371F4E9F03C0.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%371F4D64001E
void Quadrupole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Quadrupole::PrepareTracker%371F4D64001E.body preserve=yes
	_MPT
  //## end Quadrupole::PrepareTracker%371F4D64001E.body
}

//## Operation: GetIndex%371F4D6E0014
int Quadrupole::GetIndex () const
{
  //## begin Quadrupole::GetIndex%371F4D6E0014.body preserve=yes
	_RID
  //## end Quadrupole::GetIndex%371F4D6E0014.body
}

//## Operation: GetType%3720408F0032
const string& Quadrupole::GetType () const
{
  //## begin Quadrupole::GetType%3720408F0032.body preserve=yes
	_TYPESTR(Quadrupole)
  //## end Quadrupole::GetType%3720408F0032.body
}

//## Operation: Copy%372040950244
ModelElement* Quadrupole::Copy () const
{
  //## begin Quadrupole::Copy%372040950244.body preserve=yes
	_CP(Quadrupole)
  //## end Quadrupole::Copy%372040950244.body
}

// Class Sextupole 

//## begin Sextupole::ID%3721C27203AC.attr preserve=no  public: static const int {UA} UniqueIndex()
const int Sextupole::ID = UniqueIndex();
//## end Sextupole::ID%3721C27203AC.attr

//## Operation: Sextupole%3721C27203AD
Sextupole::Sextupole (const string& id, double len, double dnB)
  //## begin Sextupole::Sextupole%3721C27203AD.initialization preserve=yes
  : _RMC1(2)
  //## end Sextupole::Sextupole%3721C27203AD.initialization
{
  //## begin Sextupole::Sextupole%3721C27203AD.body preserve=yes
  //## end Sextupole::Sextupole%3721C27203AD.body
}

//## Operation: Sextupole%3721C2730003
Sextupole::Sextupole (const string& id, double len, double B, double r0)
  //## begin Sextupole::Sextupole%3721C2730003.initialization preserve=yes
  : _RMC2(2)
  //## end Sextupole::Sextupole%3721C2730003.initialization
{
  //## begin Sextupole::Sextupole%3721C2730003.body preserve=yes
  //## end Sextupole::Sextupole%3721C2730003.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%3721C2730008
void Sextupole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Sextupole::PrepareTracker%3721C2730008.body preserve=yes
	_MPT
  //## end Sextupole::PrepareTracker%3721C2730008.body
}

//## Operation: GetIndex%3721C273000A
int Sextupole::GetIndex () const
{
  //## begin Sextupole::GetIndex%3721C273000A.body preserve=yes
	_RID
  //## end Sextupole::GetIndex%3721C273000A.body
}

//## Operation: GetType%3721C273000B
const string& Sextupole::GetType () const
{
  //## begin Sextupole::GetType%3721C273000B.body preserve=yes
	_TYPESTR(Sextupole);
  //## end Sextupole::GetType%3721C273000B.body
}

//## Operation: Copy%3721C273000C
ModelElement* Sextupole::Copy () const
{
  //## begin Sextupole::Copy%3721C273000C.body preserve=yes
	_CP(Sextupole)
  //## end Sextupole::Copy%3721C273000C.body
}

// Class SkewQuadrupole 

//## begin SkewQuadrupole::ID%3721C45302F8.attr preserve=no  public: static const int {UA} UniqueIndex()
const int SkewQuadrupole::ID = UniqueIndex();
//## end SkewQuadrupole::ID%3721C45302F8.attr

//## Operation: SkewQuadrupole%3721C3190172
SkewQuadrupole::SkewQuadrupole (const string& id, double len, double dnB)
  //## begin SkewQuadrupole::SkewQuadrupole%3721C3190172.initialization preserve=yes
  : _RMSC1(1)
  //## end SkewQuadrupole::SkewQuadrupole%3721C3190172.initialization
{
  //## begin SkewQuadrupole::SkewQuadrupole%3721C3190172.body preserve=yes
  //## end SkewQuadrupole::SkewQuadrupole%3721C3190172.body
}

//## Operation: SkewQuadrupole%3721C31901E0
SkewQuadrupole::SkewQuadrupole (const string& id, double len, double B, double r0)
  //## begin SkewQuadrupole::SkewQuadrupole%3721C31901E0.initialization preserve=yes
  : _RMSC2(1)
  //## end SkewQuadrupole::SkewQuadrupole%3721C31901E0.initialization
{
  //## begin SkewQuadrupole::SkewQuadrupole%3721C31901E0.body preserve=yes
  //## end SkewQuadrupole::SkewQuadrupole%3721C31901E0.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%3721C3190212
void SkewQuadrupole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin SkewQuadrupole::PrepareTracker%3721C3190212.body preserve=yes
	_MPT
  //## end SkewQuadrupole::PrepareTracker%3721C3190212.body
}

//## Operation: GetIndex%3721C319024E
int SkewQuadrupole::GetIndex () const
{
  //## begin SkewQuadrupole::GetIndex%3721C319024E.body preserve=yes
	_RID
  //## end SkewQuadrupole::GetIndex%3721C319024E.body
}

//## Operation: GetType%3721C3190280
const string& SkewQuadrupole::GetType () const
{
  //## begin SkewQuadrupole::GetType%3721C3190280.body preserve=yes
	_TYPESTR(SkewQuadrupole)
  //## end SkewQuadrupole::GetType%3721C3190280.body
}

//## Operation: Copy%3721C31902BC
ModelElement* SkewQuadrupole::Copy () const
{
  //## begin SkewQuadrupole::Copy%3721C31902BC.body preserve=yes
	_CP(SkewQuadrupole)
  //## end SkewQuadrupole::Copy%3721C31902BC.body
}

// Class Octupole 

//## begin Octupole::ID%3721C4AF017C.attr preserve=no  public: static const int {UA} UniqueIndex()
const int Octupole::ID = UniqueIndex();
//## end Octupole::ID%3721C4AF017C.attr

//## Operation: Octupole%3721C34B0014
Octupole::Octupole (const string& id, double len, double dnB)
  //## begin Octupole::Octupole%3721C34B0014.initialization preserve=yes
  : _RMC1(3)
  //## end Octupole::Octupole%3721C34B0014.initialization
{
  //## begin Octupole::Octupole%3721C34B0014.body preserve=yes
  //## end Octupole::Octupole%3721C34B0014.body
}

//## Operation: Octupole%3721C34B0046
Octupole::Octupole (const string& id, double len, double B, double r0)
  //## begin Octupole::Octupole%3721C34B0046.initialization preserve=yes
  : _RMC2(3)
  //## end Octupole::Octupole%3721C34B0046.initialization
{
  //## begin Octupole::Octupole%3721C34B0046.body preserve=yes
  //## end Octupole::Octupole%3721C34B0046.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%3721C34B0082
void Octupole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Octupole::PrepareTracker%3721C34B0082.body preserve=yes
	_MPT
  //## end Octupole::PrepareTracker%3721C34B0082.body
}

//## Operation: GetIndex%3721C34B0084
int Octupole::GetIndex () const
{
  //## begin Octupole::GetIndex%3721C34B0084.body preserve=yes
	_RID
  //## end Octupole::GetIndex%3721C34B0084.body
}

//## Operation: GetType%3721C34B00B4
const string& Octupole::GetType () const
{
  //## begin Octupole::GetType%3721C34B00B4.body preserve=yes
	_TYPESTR(Octupole)
  //## end Octupole::GetType%3721C34B00B4.body
}

//## Operation: Copy%3721C34B00F0
ModelElement* Octupole::Copy () const
{
  //## begin Octupole::Copy%3721C34B00F0.body preserve=yes
	_CP(Octupole)
  //## end Octupole::Copy%3721C34B00F0.body
}

// Class SkewSextupole 

//## begin SkewSextupole::ID%3AC87F9402E4.attr preserve=no  public: static const int {UA} UniqueIndex()
const int SkewSextupole::ID = UniqueIndex();
//## end SkewSextupole::ID%3AC87F9402E4.attr

//## Operation: SkewSextupole%3AC87F460352
SkewSextupole::SkewSextupole (const string& id, double len, double dnB)
  //## begin SkewSextupole::SkewSextupole%3AC87F460352.initialization preserve=yes
  : _RMSC1(2)
  //## end SkewSextupole::SkewSextupole%3AC87F460352.initialization
{
  //## begin SkewSextupole::SkewSextupole%3AC87F460352.body preserve=yes
  //## end SkewSextupole::SkewSextupole%3AC87F460352.body
}

//## Operation: SkewSextupole%3AC87F46038E
SkewSextupole::SkewSextupole (const string& id, double len, double B, double r0)
  //## begin SkewSextupole::SkewSextupole%3AC87F46038E.initialization preserve=yes
  : _RMSC2(2)
  //## end SkewSextupole::SkewSextupole%3AC87F46038E.initialization
{
  //## begin SkewSextupole::SkewSextupole%3AC87F46038E.body preserve=yes
  //## end SkewSextupole::SkewSextupole%3AC87F46038E.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%3AC87F4603C0
void SkewSextupole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin SkewSextupole::PrepareTracker%3AC87F4603C0.body preserve=yes
	_MPT
  //## end SkewSextupole::PrepareTracker%3AC87F4603C0.body
}

//## Operation: GetIndex%3AC87F470014
int SkewSextupole::GetIndex () const
{
  //## begin SkewSextupole::GetIndex%3AC87F470014.body preserve=yes
	_RID
  //## end SkewSextupole::GetIndex%3AC87F470014.body
}

//## Operation: GetType%3AC87F470046
const string& SkewSextupole::GetType () const
{
  //## begin SkewSextupole::GetType%3AC87F470046.body preserve=yes
	_TYPESTR(SkewSextupole)
  //## end SkewSextupole::GetType%3AC87F470046.body
}

//## Operation: Copy%3AC87F470082
ModelElement* SkewSextupole::Copy () const
{
  //## begin SkewSextupole::Copy%3AC87F470082.body preserve=yes
	_CP(SkewSextupole)
  //## end SkewSextupole::Copy%3AC87F470082.body
}

// Class Decapole 
const int Decapole::ID = UniqueIndex();

//## Operation: Decapole%3CE3773A00BB
Decapole::Decapole (const string& id, double len, double dnB)
  //## begin Decapole::Decapole%3CE3773A00BB.initialization preserve=yes
  : _RMC1(4)
  //## end Decapole::Decapole%3CE3773A00BB.initialization
{
  //## begin Decapole::Decapole%3CE3773A00BB.body preserve=yes
  //## end Decapole::Decapole%3CE3773A00BB.body
}

//## Operation: Decapole%3CE3773A00C5
Decapole::Decapole (const string& id, double len, double B, double r0)
  //## begin Decapole::Decapole%3CE3773A00C5.initialization preserve=yes
  : _RMC2(4)
  //## end Decapole::Decapole%3CE3773A00C5.initialization
{
  //## begin Decapole::Decapole%3CE3773A00C5.body preserve=yes
  //## end Decapole::Decapole%3CE3773A00C5.body
}



//## Other Operations (implementation)
//## Operation: PrepareTracker%3CE3773A00CF
void Decapole::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin Decapole::PrepareTracker%3CE3773A00CF.body preserve=yes
	_MPT
  //## end Decapole::PrepareTracker%3CE3773A00CF.body
}

//## Operation: GetIndex%3CE3773A00D9
int Decapole::GetIndex () const
{
  //## begin Decapole::GetIndex%3CE3773A00D9.body preserve=yes
	_RID
  //## end Decapole::GetIndex%3CE3773A00D9.body
}

//## Operation: GetType%3CE3773A00DA
const string& Decapole::GetType () const
{
  //## begin Decapole::GetType%3CE3773A00DA.body preserve=yes
	_TYPESTR(Decapole)
  //## end Decapole::GetType%3CE3773A00DA.body
}

//## Operation: Copy%3CE3773A00E3
ModelElement* Decapole::Copy () const
{
  //## begin Decapole::Copy%3CE3773A00E3.body preserve=yes
	_CP(Decapole)
  //## end Decapole::Copy%3CE3773A00E3.body
}

//## begin module%371F5B690316.epilog preserve=yes
//## end module%371F5B690316.epilog

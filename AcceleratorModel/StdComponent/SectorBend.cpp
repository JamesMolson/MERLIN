//## begin module%371F12F2010E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\SectorBend.cpp
 * last modified 04/04/01 15:24:08
 */
//## end module%371F12F2010E.cm

//## begin module%371F12F2010E.cp preserve=no
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
//## end module%371F12F2010E.cp

//## Module: SectorBend%371F12F2010E; Package body
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\SectorBend.cpp

//## begin module%371F12F2010E.includes preserve=yes
//## end module%371F12F2010E.includes

// SectorBend
#include "AcceleratorModel/StdComponent/SectorBend.h"
// ComponentTracker
#include "AcceleratorModel/TrackingInterface/ComponentTracker.h"


//## begin module%371F12F2010E.declarations preserve=no
//## end module%371F12F2010E.declarations

//## begin module%371F12F2010E.additionalDeclarations preserve=yes
#include "NumericalUtils/PhysicalConstants.h"
#include <utility>
//## end module%371F12F2010E.additionalDeclarations


// Class SectorBend::PoleFace 




//## Operation: PoleFace%924771638
SectorBend::PoleFace::PoleFace (double angle, double f_int, double hg)
  //## begin SectorBend::PoleFace::PoleFace%924771638.initialization preserve=yes
  : rot(angle),fint(f_int),hgap(hg)
  //## end SectorBend::PoleFace::PoleFace%924771638.initialization
{
  //## begin SectorBend::PoleFace::PoleFace%924771638.body preserve=yes
  //## end SectorBend::PoleFace::PoleFace%924771638.body
}


// Class SectorBend::PoleFaceInfo 





//## Other Operations (implementation)
//## Operation: Copy%924771653
void SectorBend::PoleFaceInfo::Copy (const PoleFaceInfo& rhs)
{
  //## begin SectorBend::PoleFaceInfo::Copy%924771653.body preserve=yes
	entrance = rhs.entrance ? new PoleFace(*(rhs.entrance)) : 0;
	if(rhs.entrance==rhs.exit)
		exit = entrance;
	else
		exit = rhs.exit ? new PoleFace(*(rhs.exit)) : 0;
  //## end SectorBend::PoleFaceInfo::Copy%924771653.body
}

// Class SectorBend 

//## begin SectorBend::ID%371F13FC01B8.attr preserve=no  public: static const int {UA} UniqueIndex()
const int SectorBend::ID = UniqueIndex();
//## end SectorBend::ID%371F13FC01B8.attr


//## Operation: SectorBend%868873063
SectorBend::SectorBend (const string& id, double len, double h, double b0)
  //## begin SectorBend::SectorBend%868873063.initialization preserve=yes
  : TAccCompGF<ArcGeometry,MultipoleField>(id,new ArcGeometry(len,h),new MultipoleField(0,b0,1.0,false))
  //## end SectorBend::SectorBend%868873063.initialization
{
  //## begin SectorBend::SectorBend%868873063.body preserve=yes
  //## end SectorBend::SectorBend%868873063.body
}



//## Other Operations (implementation)
//## Operation: GetIndex%924771650
int SectorBend::GetIndex () const
{
  //## begin SectorBend::GetIndex%924771650.body preserve=yes
	return ID;
  //## end SectorBend::GetIndex%924771650.body
}

//## Operation: GetType%924771643
const string& SectorBend::GetType () const
{
  //## begin SectorBend::GetType%924771643.body preserve=yes
	_TYPESTR(SectorBend);
  //## end SectorBend::GetType%924771643.body
}

//## Operation: RotateY180%884089487; C++
//## Qualification: virtual
void SectorBend::RotateY180 ()
{
  //## begin SectorBend::RotateY180%884089487.body preserve=yes
	GetField().RotateY180();
	double h = GetGeometry().GetCurvature();
	GetGeometry().SetCurvature(-h);
	std::swap(pfInfo.entrance,pfInfo.exit);
  //## end SectorBend::RotateY180%884089487.body
}

//## Operation: PrepareTracker%924771642
void SectorBend::PrepareTracker (ComponentTracker& aTracker)
{
  //## begin SectorBend::PrepareTracker%924771642.body preserve=yes
	_PREPTRACK(aTracker,AcceleratorComponent);
  //## end SectorBend::PrepareTracker%924771642.body
}

//## Operation: Copy%924771644
ModelElement* SectorBend::Copy () const
{
  //## begin SectorBend::Copy%924771644.body preserve=yes
	return new SectorBend(*this);
  //## end SectorBend::Copy%924771644.body
}

//## Operation: SetPoleFaceInfo%924771646
void SectorBend::SetPoleFaceInfo (PoleFace* entr, PoleFace* exit)
{
  //## begin SectorBend::SetPoleFaceInfo%924771646.body preserve=yes
	pfInfo.SetInfo(entr,exit);
  //## end SectorBend::SetPoleFaceInfo%924771646.body
}

//## Operation: SetPoleFaceInfo%924771658
void SectorBend::SetPoleFaceInfo (PoleFace* pf)
{
  //## begin SectorBend::SetPoleFaceInfo%924771658.body preserve=yes
	pfInfo.SetInfo(pf);
  //## end SectorBend::SetPoleFaceInfo%924771658.body
}

//## Operation: GetMatchedMomentum%924771659
double SectorBend::GetMatchedMomentum (double q) const
{
  //## begin SectorBend::GetMatchedMomentum%924771659.body preserve=yes
	using namespace PhysicalConstants;
	double h = GetGeometry().GetCurvature();
	double By = GetField().GetCoefficient(0).real();
	By*=GetField().GetFieldScale();
	return 1.0e-09*SpeedOfLight*By/h/q;
  //## end SectorBend::GetMatchedMomentum%924771659.body
}

//## Operation: GetB1%951652580
double SectorBend::GetB1 () const
{
  //## begin SectorBend::GetB1%951652580.body preserve=yes
	return GetField().GetComponent(1).real();
  //## end SectorBend::GetB1%951652580.body
}

//## Operation: SetB1%951652579
void SectorBend::SetB1 (double b1)
{
  //## begin SectorBend::SetB1%951652579.body preserve=yes
	GetField().SetComponent(1,b1);
  //## end SectorBend::SetB1%951652579.body
}

//## begin module%371F12F2010E.epilog preserve=yes
//## end module%371F12F2010E.epilog

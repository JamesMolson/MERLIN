//## begin module%37341CC80168.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\ActiveMonitors\OStreamBPMBuffer.cpp
 * last modified 08/10/00 04:09:27
 */
//## end module%37341CC80168.cm

//## begin module%37341CC80168.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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
//## end module%37341CC80168.cp

//## Module: OStreamBPMBuffer%37341CC80168; Pseudo Package body
//## Subsystem: Merlin::AcceleratorModel::ActiveMonitors%3724AF2C0000
//## Source file: C:\C++\Merlin\AcceleratorModel\ActiveMonitors\OStreamBPMBuffer.cpp

//## begin module%37341CC80168.includes preserve=yes
#include <iomanip>
#include <string>
//## end module%37341CC80168.includes

// OStreamBPMBuffer
#include "AcceleratorModel/ActiveMonitors/OStreamBPMBuffer.h"
//## begin module%37341CC80168.additionalDeclarations preserve=yes
//## end module%37341CC80168.additionalDeclarations


// Class OStreamBPMBuffer 





//## Operation: OStreamBPMBuffer%926157717
OStreamBPMBuffer::OStreamBPMBuffer ()
  //## begin OStreamBPMBuffer::OStreamBPMBuffer%926157717.initialization preserve=yes
  : os(0),ctu(1),xyu(1),qu(1.0e+10)
  //## end OStreamBPMBuffer::OStreamBPMBuffer%926157717.initialization
{
  //## begin OStreamBPMBuffer::OStreamBPMBuffer%926157717.body preserve=yes
  //## end OStreamBPMBuffer::OStreamBPMBuffer%926157717.body
}



//## Other Operations (implementation)
//## Operation: Record%926157718
void OStreamBPMBuffer::Record (const BPM& aBPM, const BPM::Data& data)
{
  //## begin OStreamBPMBuffer::Record%926157718.body preserve=yes
	using namespace std;
	(*os)<<setw(12)<<left<<aBPM.GetName().c_str();
	(*os)<<setw(12)<<right<<data.ct/ctu;

	(*os)<<setw(12)<<right<<data.x.value/xyu;
	(*os)<<setw(12)<<right<<data.y.value/xyu;
	(*os)<<setw(12)<<right<<data.q.value/qu;

	(*os)<<setw(12)<<right<<data.x.error/xyu;
	(*os)<<setw(12)<<right<<data.y.error/xyu;
	(*os)<<setw(12)<<right<<data.q.value/qu;

	(*os)<<endl;
  //## end OStreamBPMBuffer::Record%926157718.body
}

//## Operation: SetStream%926157719
void OStreamBPMBuffer::SetStream (std::ostream& os1)
{
  //## begin OStreamBPMBuffer::SetStream%926157719.body preserve=yes
	os = &os1;
  //## end OStreamBPMBuffer::SetStream%926157719.body
}

//## Operation: SetUnits%926157720
void OStreamBPMBuffer::SetUnits (double ct_unit, double xy_unit, double q_unit)
{
  //## begin OStreamBPMBuffer::SetUnits%926157720.body preserve=yes
	assert(ct_unit!=0 && xy_unit!=0);
	ctu=ct_unit;
	xyu=xy_unit;
	qu=q_unit;
  //## end OStreamBPMBuffer::SetUnits%926157720.body
}

//## begin module%37341CC80168.epilog preserve=yes
//## end module%37341CC80168.epilog

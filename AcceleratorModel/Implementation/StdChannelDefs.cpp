//## begin module%3A9BD642038E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\ModelAccess\StdChannelDefs.cpp
 * last modified 27/02/01 17:32:37
 */
//## end module%3A9BD642038E.cm

//## begin module%3A9BD642038E.cp preserve=no
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
//## end module%3A9BD642038E.cp

//## Module: StdChannelDefs%3A9BD642038E; Package body
//## Subsystem: Merlin::AcceleratorModel::ModelAccess%3A9BCEAB032A
//## Source file: D:\dev\Merlin\AcceleratorModel\ModelAccess\StdChannelDefs.cpp

//## begin module%3A9BD642038E.includes preserve=yes
#include "AcceleratorModel/Frames/LatticeFrame.h"
#include "AcceleratorModel/Supports/MagnetMover.h"
#include "AcceleratorModel/Implementation/BPMChannels/BPMChannelCtor.h"
#include "AcceleratorModel/Miscellaneous/CorrectorWinding.h"
//## end module%3A9BD642038E.includes

// Components
#include "AcceleratorModel/Components.h"
// IndirectChannel
#include "AcceleratorModel/Implementation/IndirectChannels.h"
//## begin module%3A9BD642038E.declarations preserve=no
//## end module%3A9BD642038E.declarations

//## begin module%3A9BD642038E.additionalDeclarations preserve=yes

#define DEF_RW_CHANNEL(type,key,getf,setf) \
server->RegisterCtor(new TIC_ctor<type>(#type,#key,getf,setf))


ChannelServer* ConstructChannelServer()
{
	ChannelServer* server = new ChannelServer();

	DEF_RW_CHANNEL(Quadrupole,B1,&Quadrupole::GetFieldStrength,&Quadrupole::SetFieldStrength);
	DEF_RW_CHANNEL(Sextupole,B2,&Sextupole::GetFieldStrength,&Sextupole::SetFieldStrength);
	DEF_RW_CHANNEL(Octupole,B3,&Octupole::GetFieldStrength,&Octupole::SetFieldStrength);

	DEF_RW_CHANNEL(SkewQuadrupole,B1,&SkewQuadrupole::GetFieldStrength,&SkewQuadrupole::SetFieldStrength);
	DEF_RW_CHANNEL(SkewSextupole,B2,&SkewSextupole::GetFieldStrength,&SkewSextupole::SetFieldStrength);

	DEF_RW_CHANNEL(XCor,B0,&XCor::GetFieldStrength,&XCor::SetFieldStrength);
	DEF_RW_CHANNEL(YCor,B0,&YCor::GetFieldStrength,&YCor::SetFieldStrength);

	DEF_RW_CHANNEL(SectorBend,B0,&SectorBend::GetB0,&SectorBend::SetB0);
	DEF_RW_CHANNEL(SectorBend,B1,&SectorBend::GetB1,&SectorBend::SetB1);

	DEF_RW_CHANNEL(MagnetMover,X,&MagnetMover::GetX,&MagnetMover::SetX);
	DEF_RW_CHANNEL(MagnetMover,Y,&MagnetMover::GetY,&MagnetMover::SetY);
	DEF_RW_CHANNEL(MagnetMover,Roll,&MagnetMover::GetRoll,&MagnetMover::SetRoll);

	DEF_RW_CHANNEL(TWRFStructure,E,&TWRFStructure::GetAmplitude,&TWRFStructure::SetAmplitude);
	DEF_RW_CHANNEL(TWRFStructure,Phi,&TWRFStructure::GetPhase,&TWRFStructure::SetPhase);
	DEF_RW_CHANNEL(TWRFStructure,Lambda,&TWRFStructure::GetWavelength,&TWRFStructure::SetWavelength);
	DEF_RW_CHANNEL(TWRFStructure,K,&TWRFStructure::GetK,&TWRFStructure::SetK);

	DEF_RW_CHANNEL(SWRFStructure,E,&SWRFStructure::GetAmplitude,&SWRFStructure::SetAmplitude);
	DEF_RW_CHANNEL(SWRFStructure,Phi,&SWRFStructure::GetPhase,&SWRFStructure::SetPhase);
	DEF_RW_CHANNEL(SWRFStructure,Lambda,&SWRFStructure::GetWavelength,&SWRFStructure::SetWavelength);
	DEF_RW_CHANNEL(SWRFStructure,K,&SWRFStructure::GetK,&SWRFStructure::SetK);

	DEF_RW_CHANNEL(CorrectorWinding,X,&CorrectorWinding::GetBy,&CorrectorWinding::SetBy);
	DEF_RW_CHANNEL(CorrectorWinding,Y,&CorrectorWinding::GetBx,&CorrectorWinding::SetBx);

	// Special BPM channels
	server->RegisterCtor(new BPMChannelCtor('X'));
	server->RegisterCtor(new BPMChannelCtor('Y'));

	return server;
}








//## end module%3A9BD642038E.additionalDeclarations


//## begin module%3A9BD642038E.epilog preserve=yes
//## end module%3A9BD642038E.epilog

/*
* Merlin C++ Class Library for Charged Particle Accelerator Simulations
* 
* Class library version 2.0 (1999)
* 
* file Merlin\BeamDynamics\SliceMPTracking\Integrators\StdIntegrators.cpp
* last modified 11/12/01 15:32:02
*
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

#include "BeamDynamics/SMPTracking/SMPComponentTracker.h"
#include "BeamDynamics/SMPTracking/StdIntegrators.h"

namespace SMPTracking {

	DEF_INTG_SET(SMPComponentTracker,StdISet)
		ADD_INTG(DriftCI)
		ADD_INTG(SectorBendCI)
		ADD_INTG(RectMultipoleCI)
		ADD_INTG(TWRFStructureCI)
		ADD_INTG(MonitorCI)
		ADD_INTG(SolenoidCI)
		ADD_INTG(MarkerCI)
	END_INTG_SET

};

MAKE_DEF_INTG_SET(SMPTracking::SMPComponentTracker,StdISet)



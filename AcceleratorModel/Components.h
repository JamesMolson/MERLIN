/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004-12-13 08:38:51 $
// $Revision: 1.4 $
// 
/////////////////////////////////////////////////////////////////////////

//	A single include file which includes all the header
//	files for the standard accelerator model components.

#ifndef Components_h
#define Components_h 1

#include "merlin_config.h"

// StandardMultipoles
#include "AcceleratorModel/StdComponent/StandardMultipoles.h"
// SectorBend
#include "AcceleratorModel/StdComponent/SectorBend.h"
// Drift
#include "AcceleratorModel/StdComponent/Drift.h"
// Marker
#include "AcceleratorModel/StdComponent/Marker.h"
// TWRFStructure
#include "AcceleratorModel/StdComponent/TWRFStructure.h"
// SWRFStructure
#include "AcceleratorModel/StdComponent/SWRFStructure.h"
// CorrectorDipoles
#include "AcceleratorModel/StdComponent/CorrectorDipoles.h"
// RMSProfileMonitor
#include "AcceleratorModel/ActiveMonitors/RMSProfileMonitor.h"
// BPM
#include "AcceleratorModel/ActiveMonitors/BPM.h"
// Marker
#include "AcceleratorModel/StdComponent/Marker.h"
// Solenoid
#include "AcceleratorModel/StdComponent/Solenoid.h"

#endif

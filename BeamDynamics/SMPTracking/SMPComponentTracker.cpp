/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004-12-13 08:38:53 $
// $Revision: 1.2 $
// 
/////////////////////////////////////////////////////////////////////////

#include "BeamDynamics/SMPTracking/SMPComponentTracker.h"
#include "BeamDynamics/SMPTracking/SMPStdIntegrators.h"

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

}; //end namespace SMPTracking

MAKE_DEF_INTG_SET(SMPTracking::SMPComponentTracker,SMPTracking::StdISet);




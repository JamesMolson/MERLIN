/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2005-04-01 15:21:48 $
// $Revision: 1.2 $
// 
/////////////////////////////////////////////////////////////////////////


#include "MADInterface/ConstructSrot.h"
#include "AcceleratorModel/Frames/PatchFrame.h"

ComponentFrame* ConstructSrot(double angle, const std::string& name)
{
    GeometryPatch* gp = new GeometryPatch;
    gp->RotateZ(angle);
    return new PatchFrame(gp,name);
}

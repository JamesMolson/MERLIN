/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2005-03-29 08:17:37 $
// $Revision: 1.1 $
// 
/////////////////////////////////////////////////////////////////////////

#ifndef _h_ConstructSrot
#define _h_ConstructSrot 1

#include <string>
#include "AcceleratorModel/Frames/ComponentFrame.h"

ComponentFrame* ConstructSrot(double angle, const std::string& name);

#endif
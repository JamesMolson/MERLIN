//## begin module%3724547000AA.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\RectSWRF.h
 * last modified 05/04/01 17:31:06
 */
//## end module%3724547000AA.cm

//## begin module%3724547000AA.cp preserve=no
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
//## end module%3724547000AA.cp

//## Module: RectSWRF%3724547000AA; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\RectSWRF.h

#ifndef RectSWRF_h
#define RectSWRF_h 1

//## begin module%3724547000AA.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3724547000AA.additionalIncludes

//## begin module%3724547000AA.includes preserve=yes
//## end module%3724547000AA.includes

// SWRFfield
#include "AcceleratorModel/StdField/SWRFfield.h"
// RFStructure
#include "AcceleratorModel/StdComponent/RFStructure.h"
//## begin module%3724547000AA.additionalDeclarations preserve=yes
//## end module%3724547000AA.additionalDeclarations


//## Class: RectSWRF%3724547000AA; Instantiated Class
//	A standing-wave RF accelerating field referenced to a
//	rectangular geometry.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3ACB1E9901AE;SWRFfield { -> }

typedef RFStructure< SWRFfield > RectSWRF;

//## begin RectSWRF.instantiation preserve=no
template class RFStructure< SWRFfield >;
//## end RectSWRF.instantiation
//## begin module%3724547000AA.epilog preserve=yes
//## end module%3724547000AA.epilog


#endif

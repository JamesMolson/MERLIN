//## begin module%3724510002C6.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\RectTWRF.h
 * last modified 05/04/01 17:31:07
 */
//## end module%3724510002C6.cm

//## begin module%3724510002C6.cp preserve=no
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
//## end module%3724510002C6.cp

//## Module: RectTWRF%3724510002C6; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\RectTWRF.h

#ifndef RectTWRF_h
#define RectTWRF_h 1

//## begin module%3724510002C6.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3724510002C6.additionalIncludes

//## begin module%3724510002C6.includes preserve=yes
//## end module%3724510002C6.includes

// TWRFfield
#include "AcceleratorModel/StdField/TWRFfield.h"
// RFStructure
#include "AcceleratorModel/StdComponent/RFStructure.h"
//## begin module%3724510002C6.additionalDeclarations preserve=yes
//## end module%3724510002C6.additionalDeclarations


//## Class: RectTWRF%3724510002C6; Instantiated Class
//	A travelling-wave RF accelerating field referenced to a
//	rectangular geometry.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3ACB1EDE03C0;TWRFfield { -> }

typedef RFStructure< TWRFfield > RectTWRF;

//## begin RectTWRF.instantiation preserve=no
template class RFStructure< TWRFfield >;
//## end RectTWRF.instantiation
//## begin module%3724510002C6.epilog preserve=yes
//## end module%3724510002C6.epilog


#endif

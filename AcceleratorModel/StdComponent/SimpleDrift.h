//## begin module%371F0719029E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\SimpleDrift.h
 * last modified 04/04/01 15:24:40
 */
//## end module%371F0719029E.cm

//## begin module%371F0719029E.cp preserve=no
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
//## end module%371F0719029E.cp

//## Module: SimpleDrift%371F0719029E; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\SimpleDrift.h

#ifndef SimpleDrift_h
#define SimpleDrift_h 1

//## begin module%371F0719029E.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%371F0719029E.additionalIncludes

//## begin module%371F0719029E.includes preserve=yes
//## end module%371F0719029E.includes

// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"
//## begin module%371F0719029E.additionalDeclarations preserve=yes
//## end module%371F0719029E.additionalDeclarations


//## Class: SimpleDrift%371F0719029E; Instantiated Class
//	A rectangular geometry with no field.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3ACB1D6802BC;RectangularGeometry { -> }

typedef TAccCompG< RectangularGeometry > SimpleDrift;

//## begin SimpleDrift.instantiation preserve=no
template class TAccCompG< RectangularGeometry >;
//## end SimpleDrift.instantiation
//## begin module%371F0719029E.epilog preserve=yes
//## end module%371F0719029E.epilog


#endif

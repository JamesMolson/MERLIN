//## begin module%371F363F02F8.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\RectMultipoleField.h
 * last modified 04/04/01 15:24:40
 */
//## end module%371F363F02F8.cm

//## begin module%371F363F02F8.cp preserve=no
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
//## end module%371F363F02F8.cp

//## Module: RectMultipoleField%371F363F02F8; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\RectMultipoleField.h

#ifndef RectMultipoleField_h
#define RectMultipoleField_h 1

//## begin module%371F363F02F8.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%371F363F02F8.additionalIncludes

//## begin module%371F363F02F8.includes preserve=yes
//## end module%371F363F02F8.includes

// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// MultipoleField
#include "AcceleratorModel/StdField/MultipoleField.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"
//## begin module%371F363F02F8.additionalDeclarations preserve=yes
//## end module%371F363F02F8.additionalDeclarations


//## Class: RectMultipoleField%371F363F02F8; Instantiated Class
//	A magnetic multipole field referenced to a rectangular
//	geometry.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3ACB1DC6012C;RectangularGeometry { -> }
//## Uses: <unnamed>%3ACB1DC80226;MultipoleField { -> }

typedef TAccCompGF< RectangularGeometry,MultipoleField > RectMultipoleField;

//## begin RectMultipoleField.instantiation preserve=no
template class TAccCompGF< RectangularGeometry,MultipoleField >;
//## end RectMultipoleField.instantiation
//## begin module%371F363F02F8.epilog preserve=yes
//## end module%371F363F02F8.epilog


#endif

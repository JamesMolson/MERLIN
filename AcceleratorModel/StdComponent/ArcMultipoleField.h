//## begin module%371F0C7F01AE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\ArcMultipoleField.h
 * last modified 04/04/01 15:24:40
 */
//## end module%371F0C7F01AE.cm

//## begin module%371F0C7F01AE.cp preserve=no
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
//## end module%371F0C7F01AE.cp

//## Module: ArcMultipoleField%371F0C7F01AE; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\ArcMultipoleField.h

#ifndef ArcMultipoleField_h
#define ArcMultipoleField_h 1

//## begin module%371F0C7F01AE.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%371F0C7F01AE.additionalIncludes

//## begin module%371F0C7F01AE.includes preserve=yes
//## end module%371F0C7F01AE.includes

// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// MultipoleField
#include "AcceleratorModel/StdField/MultipoleField.h"
// ArcGeometry
#include "AcceleratorModel/StdGeometry/ArcGeometry.h"
//## begin module%371F0C7F01AE.additionalDeclarations preserve=yes
//## end module%371F0C7F01AE.additionalDeclarations


//## Class: ArcMultipoleField%371F0C7F01AE; Instantiated Class
//	A magnetic multipole field referenced to an arc geometry.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3ACB1D2A038E;ArcGeometry { -> }
//## Uses: <unnamed>%3ACB1D2E0028;MultipoleField { -> }

typedef TAccCompGF< ArcGeometry,MultipoleField > ArcMultipoleField;

//## begin ArcMultipoleField.instantiation preserve=no
template class TAccCompGF< ArcGeometry,MultipoleField >;
//## end ArcMultipoleField.instantiation
//## begin module%371F0C7F01AE.epilog preserve=yes
//## end module%371F0C7F01AE.epilog


#endif

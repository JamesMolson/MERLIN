//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3C14B1E80150.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\StdComponent\SimpleSolenoid.h
 * last modified 10/12/01 14:23:49
 */
//## end module%3C14B1E80150.cm

//## begin module%3C14B1E80150.cp preserve=no
/*
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
//## end module%3C14B1E80150.cp

//## Module: SimpleSolenoid%3C14B1E80150; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: C:\C++\Merlin\AcceleratorModel\StdComponent\SimpleSolenoid.h

#ifndef SimpleSolenoid_h
#define SimpleSolenoid_h 1

//## begin module%3C14B1E80150.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3C14B1E80150.additionalIncludes

//## begin module%3C14B1E80150.includes preserve=yes
//## end module%3C14B1E80150.includes

// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// RectangularGeometry
#include "AcceleratorModel/StdGeometry/RectangularGeometry.h"
// BzField
#include "AcceleratorModel/StdField/BzField.h"
//## begin module%3C14B1E80150.additionalDeclarations preserve=yes
//## end module%3C14B1E80150.additionalDeclarations


//## Class: SimpleSolenoid%3C14B1E80150; Instantiated Class
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%3C14B3660132;RectangularGeometry { -> }
//## Uses: <unnamed>%3C14B46D00C2;BzField { -> }

typedef TAccCompGF< RectangularGeometry , BzField  > SimpleSolenoid;

//## begin module%3C14B1E80150.epilog preserve=yes
//## end module%3C14B1E80150.epilog


#endif

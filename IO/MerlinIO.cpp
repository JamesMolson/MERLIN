//## begin module%3AED363602EE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\IO\MerlinIO.cpp
 * last modified 30/04/01 12:06:58
 */
//## end module%3AED363602EE.cm

//## begin module%3AED363602EE.cp preserve=no
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
//## end module%3AED363602EE.cp

//## Module: MerlinIO%3AED363602EE; Pseudo Package body
//## Subsystem: Merlin::IO%3AED3619035C
//## Source file: D:\dev\Merlin\IO\MerlinIO.cpp

//## begin module%3AED363602EE.includes preserve=yes
//## end module%3AED363602EE.includes

// MerlinIO
#include "IO/MerlinIO.h"
//## begin module%3AED363602EE.additionalDeclarations preserve=yes
//## end module%3AED363602EE.additionalDeclarations


// Class Utility MerlinIO 

//## begin MerlinIO::std_in%3AED36AC0348.attr preserve=no  public: static std::istream* {UA} &std::cin
std::istream* MerlinIO::std_in = &std::cin;
//## end MerlinIO::std_in%3AED36AC0348.attr

//## begin MerlinIO::std_out%3AED36D3000A.attr preserve=no  public: static std::ostream* {UA} &std::cout
std::ostream* MerlinIO::std_out = &std::cout;
//## end MerlinIO::std_out%3AED36D3000A.attr

//## begin MerlinIO::std_err%3AED36E50320.attr preserve=no  public: static std::ostream* {UA} &std::cerr
std::ostream* MerlinIO::std_err = &std::cerr;
//## end MerlinIO::std_err%3AED36E50320.attr

//## begin MerlinIO::std_warn%3AED36F90082.attr preserve=no  public: static std::ostream* {UA} &std::cerr
std::ostream* MerlinIO::std_warn = &std::cerr;
//## end MerlinIO::std_warn%3AED36F90082.attr

//## begin module%3AED363602EE.epilog preserve=yes
//## end module%3AED363602EE.epilog

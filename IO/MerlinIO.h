//## begin module%3AED363602EE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\IO\MerlinIO.h
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

//## Module: MerlinIO%3AED363602EE; Pseudo Package specification
//## Subsystem: Merlin::IO%3AED3619035C
//## Source file: D:\dev\Merlin\IO\MerlinIO.h

#ifndef MerlinIO_h
#define MerlinIO_h 1

//## begin module%3AED363602EE.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AED363602EE.additionalIncludes

//## begin module%3AED363602EE.includes preserve=yes
#include <iostream>
//## end module%3AED363602EE.includes

//## begin module%3AED363602EE.additionalDeclarations preserve=yes
//## end module%3AED363602EE.additionalDeclarations


//## Class: MerlinIO%3AED363602EE; Class Utility
//	Interface for the standard Merlin IO streams.
//## Category: Merlin::IO%3AED3619035C; Global
//## Subsystem: Merlin::IO%3AED3619035C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class MerlinIO 
{
  public:

    //## Other Operations (specified)
      //## Operation: in%988624762
      static std::istream& in ();

      //## Operation: out%988624763
      static std::ostream& out ();

      //## Operation: error%988624764
      static std::ostream& error ();

      //## Operation: warning%988624765
      static std::ostream& warning ();

    // Data Members for Class Attributes

      //## Attribute: std_in%3AED36AC0348
      //## begin MerlinIO::std_in%3AED36AC0348.attr preserve=no  public: static std::istream* {UA} &std::cin
      static std::istream* std_in;
      //## end MerlinIO::std_in%3AED36AC0348.attr

      //## Attribute: std_out%3AED36D3000A
      //## begin MerlinIO::std_out%3AED36D3000A.attr preserve=no  public: static std::ostream* {UA} &std::cout
      static std::ostream* std_out;
      //## end MerlinIO::std_out%3AED36D3000A.attr

      //## Attribute: std_err%3AED36E50320
      //## begin MerlinIO::std_err%3AED36E50320.attr preserve=no  public: static std::ostream* {UA} &std::cerr
      static std::ostream* std_err;
      //## end MerlinIO::std_err%3AED36E50320.attr

      //## Attribute: std_warn%3AED36F90082
      //## begin MerlinIO::std_warn%3AED36F90082.attr preserve=no  public: static std::ostream* {UA} &std::cerr
      static std::ostream* std_warn;
      //## end MerlinIO::std_warn%3AED36F90082.attr

  protected:
  private:
  private:  //## implementation
};

// Class Utility MerlinIO 


//## Other Operations (inline)
//## Operation: in%988624762
inline std::istream& MerlinIO::in ()
{
  //## begin MerlinIO::in%988624762.body preserve=yes
	return *std_in;
  //## end MerlinIO::in%988624762.body
}

//## Operation: out%988624763
inline std::ostream& MerlinIO::out ()
{
  //## begin MerlinIO::out%988624763.body preserve=yes
 	return *std_out;
  //## end MerlinIO::out%988624763.body
}

//## Operation: error%988624764
inline std::ostream& MerlinIO::error ()
{
  //## begin MerlinIO::error%988624764.body preserve=yes
	return *std_err;
  //## end MerlinIO::error%988624764.body
}

//## Operation: warning%988624765
inline std::ostream& MerlinIO::warning ()
{
  //## begin MerlinIO::warning%988624765.body preserve=yes
	return *std_warn;
  //## end MerlinIO::warning%988624765.body
}

//## begin module%3AED363602EE.epilog preserve=yes
// MACRO interface
#define MERLIN_OUT  MerlinIO::out()
#define MERLIN_IN   MerlinIO::in()
#define MERLIN_ERR  MerlinIO::error()
#define MERLIN_WARN MerlinIO::warning()
//## end module%3AED363602EE.epilog


#endif

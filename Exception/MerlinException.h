//## begin module%3AE7F42C01FE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\Exception\MerlinException.h
 * last modified 26/04/01 12:19:04
 */
//## end module%3AE7F42C01FE.cm

//## begin module%3AE7F42C01FE.cp preserve=no
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
//## end module%3AE7F42C01FE.cp

//## Module: MerlinException%3AE7F42C01FE; Pseudo Package specification
//## Subsystem: Merlin::Exception%3AE7F41D01CC
//## Source file: D:\dev\Merlin\Exception\MerlinException.h

#ifndef MerlinException_h
#define MerlinException_h 1

//## begin module%3AE7F42C01FE.additionalIncludes preserve=no
//#include "merlin_config.h"
//## end module%3AE7F42C01FE.additionalIncludes

//## begin module%3AE7F42C01FE.includes preserve=yes
#include <string>
//## end module%3AE7F42C01FE.includes

//## begin module%3AE7F42C01FE.additionalDeclarations preserve=yes
//## end module%3AE7F42C01FE.additionalDeclarations


//## Class: MerlinException%3AE7F42C01FE
//	Root class for all Merlin exceptions.
//## Category: Merlin::Exception%3AE7F41D01CC
//## Subsystem: Merlin::Exception%3AE7F41D01CC
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class MerlinException 
{
  public:
    //## Constructors (specified)
      //## Operation: MerlinException%988274695
      explicit MerlinException (const std::string& s);

      //## Operation: MerlinException%988274696
      MerlinException ();


    //## Other Operations (specified)
      //## Operation: Msg%988274697
      const char* Msg () const;

  protected:

    //## Other Operations (specified)
      //## Operation: SetMsg%988274698
      void SetMsg (const std::string& s);

      //## Operation: AppendMsg%988274699
      void AppendMsg (const std::string& s);

  private:
    // Data Members for Class Attributes

      //## Attribute: msg%3AE7F48E0302
      //## begin MerlinException::msg%3AE7F48E0302.attr preserve=no  private: std::string {UA} 
      std::string msg;
      //## end MerlinException::msg%3AE7F48E0302.attr

  private:  //## implementation
};

// Class MerlinException 

//## Operation: MerlinException%988274695
inline MerlinException::MerlinException (const std::string& s)
  //## begin MerlinException::MerlinException%988274695.initialization preserve=yes
  : msg(s)
  //## end MerlinException::MerlinException%988274695.initialization
{
  //## begin MerlinException::MerlinException%988274695.body preserve=yes
  //## end MerlinException::MerlinException%988274695.body
}

//## Operation: MerlinException%988274696
inline MerlinException::MerlinException ()
  //## begin MerlinException::MerlinException%988274696.initialization preserve=yes
  //## end MerlinException::MerlinException%988274696.initialization
{
  //## begin MerlinException::MerlinException%988274696.body preserve=yes
  //## end MerlinException::MerlinException%988274696.body
}



//## Other Operations (inline)
//## Operation: Msg%988274697
inline const char* MerlinException::Msg () const
{
  //## begin MerlinException::Msg%988274697.body preserve=yes
	return msg.c_str();
  //## end MerlinException::Msg%988274697.body
}

//## Operation: SetMsg%988274698
inline void MerlinException::SetMsg (const std::string& s)
{
  //## begin MerlinException::SetMsg%988274698.body preserve=yes
	msg=s;
  //## end MerlinException::SetMsg%988274698.body
}

//## Operation: AppendMsg%988274699
inline void MerlinException::AppendMsg (const std::string& s)
{
  //## begin MerlinException::AppendMsg%988274699.body preserve=yes
	msg+=s;
  //## end MerlinException::AppendMsg%988274699.body
}

// Class MerlinException 


//## begin module%3AE7F42C01FE.epilog preserve=yes
//## end module%3AE7F42C01FE.epilog


#endif

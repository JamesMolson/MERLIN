//## begin module.cm preserve=no
// Specification for OPFormat
// last modified: 03/25/98 at 16:05:43
// This file is part of the MERLIN class library
// version 1.0beta
// ---------------------------------------------
//## end module.cm

//## begin module.cp preserve=no
// (c) 1997 Nicholas J. Walker (DESY) -- All Rights Reserved --
// ------------------------------------------------------------
//## end module.cp

//## Module: OPFormat; Package specification
//## Subsystem: utility
//## Source file: c:\C++\Merlin\utility\OPFormat.h

#ifndef OPFormat_h
#define OPFormat_h 1

//## begin module.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <iostream>
#include <string>
//## end module.includes

//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
using std::string;
using std::ios_base;
using std::ostream;
//## end module.additionalDeclarations


//## Class: OPFormat
//	Floating Point Format. Utility class for formatting and
//	outputting floating point numbers to an ostream, without
//	modifying the state of the ostream.
//## Category: utility; Global
//## Subsystem: utility
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class OPFormat 
{
  public:
	  
    //## Constructors (specified)
      //## Operation: OPFormat%889857363
      explicit OPFormat (int p = 6)
        //## begin OPFormat::OPFormat%889857363.initialization preserve=yes
		:prc(p),wdt(0),fmt(),adjust(ios_base::right),allowovf(true)
        //## end OPFormat::OPFormat%889857363.initialization
      {
        //## begin OPFormat::OPFormat%889857363.body preserve=yes
        //## end OPFormat::OPFormat%889857363.body
      }


    //## Other Operations (specified)
      //## Operation: scientific%889857365
      OPFormat& scientific ()
      {
        //## begin OPFormat::scientific%889857365.body preserve=yes
		  fmt=ios_base::scientific;
		  return *this;
        //## end OPFormat::scientific%889857365.body
      }

      //## Operation: fixed%889857366
      OPFormat& fixed ()
      {
        //## begin OPFormat::fixed%889857366.body preserve=yes
		  fmt=ios_base::fixed;
		  return *this;
        //## end OPFormat::fixed%889857366.body
      }

      //## Operation: general%889857367
      OPFormat& general ()
      {
        //## begin OPFormat::general%889857367.body preserve=yes
		  fmt &= ~(ios_base::scientific & ios_base::fixed);
		  return *this;
        //## end OPFormat::general%889857367.body
      }

      //## Operation: precision%889857368
      OPFormat& precision (int p)
      {
        //## begin OPFormat::precision%889857368.body preserve=yes
		  prc=p;
		  return *this;
        //## end OPFormat::precision%889857368.body
      }

      //## Operation: width%889857369
      OPFormat& width (int w)
      {
        //## begin OPFormat::width%889857369.body preserve=yes
		  wdt=w;
		  return *this;
        //## end OPFormat::width%889857369.body
      }

      //## Operation: left%890835255
      OPFormat& left ()
      {
        //## begin OPFormat::left%890835255.body preserve=yes
		  adjust=ios_base::left;
		  return *this;
        //## end OPFormat::left%890835255.body
      }

      //## Operation: right%890835256
      OPFormat& right ()
      {
        //## begin OPFormat::right%890835256.body preserve=yes
		  adjust=ios_base::right;
		  return *this;
        //## end OPFormat::right%890835256.body
      }

      //## Operation: internal%890835257
      OPFormat& internal ()
      {
        //## begin OPFormat::internal%890835257.body preserve=yes
 		  adjust=ios_base::internal;
		  return *this;
        //## end OPFormat::internal%890835257.body
      }

      //## Operation: overflow%890835258
      OPFormat& overflow (bool flg)
      {
        //## begin OPFormat::overflow%890835258.body preserve=yes
 		  allowovf=flg;
		  return *this;
        //## end OPFormat::overflow%890835258.body
      }

      //## Operation: operator()%889857364
      string operator () (double val) const;

      //## Operation: operator()%890835260
      string operator () (int val) const;

      //## Operation: operator()%890835262
      string operator () (const string& val) const;

      //## Operation: operator<<%890835263
      friend ostream& operator << (ostream& os, const OPFormat& fmt);

    // Data Members for Class Attributes

      //## Attribute: prc
      //## begin OPFormat::prc.attr preserve=no  public: int {UA} 
      int prc;
      //## end OPFormat::prc.attr

      //## Attribute: wdt
      //## begin OPFormat::wdt.attr preserve=no  public: int {UA} 
      int wdt;
      //## end OPFormat::wdt.attr

      //## Attribute: fmt
      //## begin OPFormat::fmt.attr preserve=no  public: int {UA} 
      ios_base::fmtflags fmt;
      //## end OPFormat::fmt.attr

      //## Attribute: adjust
      //## begin OPFormat::adjust.attr preserve=no  public: int {UA} 
      ios_base::fmtflags adjust;
      //## end OPFormat::adjust.attr

      //## Attribute: allowovf
      //## begin OPFormat::allowovf.attr preserve=no  public: bool {UA} 
      bool allowovf;
      //## end OPFormat::allowovf.attr

    // Data Members for Associations

      //## Association: SBCTracking::<unnamed>%350A29EA02DA
      //## Role: OPFormat::<the_TwissFormatter>
      //## begin OPFormat::<the_TwissFormatter>.role preserve=no  public: TwissFormatter { -> RHGA}
      //## end OPFormat::<the_TwissFormatter>.role

  protected:
  private:
  private:  //## implementation
};



//## begin module.epilog preserve=yes
//## end module.epilog
#endif

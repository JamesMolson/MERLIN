//## begin module%34586D5803C9.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file utility\StringPattern.h
 * last modified 05/09/00  12:30:39
 */
//## end module%34586D5803C9.cm

//## begin module%34586D5803C9.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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
//## end module%34586D5803C9.cp

//## Module: StringPattern%34586D5803C9; Pseudo Package specification
//## Subsystem: utility%350A244000C8
//## Source file: C:\C++\Merlin\utility\StringPattern.h

#ifndef StringPattern_h
#define StringPattern_h 1

//## begin module%34586D5803C9.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%34586D5803C9.additionalIncludes

//## begin module%34586D5803C9.includes preserve=yes
#include <string>
#include <vector>
#include <utility>
#include <iostream>
//## end module%34586D5803C9.includes

//## begin module%34586D5803C9.additionalDeclarations preserve=yes
using std::string;
using std::ostream;
//## end module%34586D5803C9.additionalDeclarations


//## Class: StringPattern%34586D5803C9
//	A simple string pattern which represents a reduced set
//	of the standard UNIX regular expression syntax.
//	Currently supported is the single wild-card '*', which
//	matches any number (including zero) of any character.
//## Category: utility%345885E70117; Global
//## Subsystem: utility%350A244000C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class StringPattern 
{
  public:
    //## Constructors (specified)
      //## Operation: StringPattern%888997595; C++
      //	Constructor taking the string pattern.
      StringPattern (const std::string& s);


    //## Other Operations (specified)
      //## Operation: Match%888997596; C++
      //	Match operation. Returns true if the pattern matched the
      //	string.
      bool Match (const std::string& s) const;

      //## Operation: operator()%888997597; C++
      //	Operator form of match().
      bool operator () (const std::string& s) const;

      //## Operation: operator<<%888997598; C++
      //	Outputs to os the original pattern.
      friend ostream& operator << (ostream& os, const StringPattern& pattern);

      //## Operation: operator string%957866738
      operator string () const;

      //## Operation: operator<%957866739
      bool operator < (const StringPattern& rhs) const;

      //## Operation: operator==%957866740
      bool operator == (const StringPattern& rhs) const;

    // Data Members for Class Attributes

      //## Attribute: wcchar%34FD19110208
      //	The wildcard character (default ='*').
      //## begin StringPattern::wcchar%34FD19110208.attr preserve=no  public: static char {UA} '*'
      static char wcchar;
      //## end StringPattern::wcchar%34FD19110208.attr

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: patterns%34FD182A03AC
      //	A vector of literal strings. The pattern is split into
      //	literals by the presence of a '*' character.
      //## begin StringPattern::patterns%34FD182A03AC.attr preserve=no  private: std::vector<string> {UA} 
      std::vector<string> patterns;
      //## end StringPattern::patterns%34FD182A03AC.attr

      //## Attribute: wcterm%34FD186E0186
      //	Used to indicate if the first/last character of the
      //	string pattern were wildcards.
      //## begin StringPattern::wcterm%34FD186E0186.attr preserve=no  private: std::pair<bool,bool> {UA} 
      std::pair<bool,bool> wcterm;
      //## end StringPattern::wcterm%34FD186E0186.attr

      //## Attribute: isLiteral%34FD260A032A
      //	Set to true if this pattern is a simple literal string
      //	(no wild cards).
      //## begin StringPattern::isLiteral%34FD260A032A.attr preserve=no  private: bool {UA} 
      bool isLiteral;
      //## end StringPattern::isLiteral%34FD260A032A.attr

      //## Attribute: str%3917E7D200D2
      //## begin StringPattern::str%3917E7D200D2.attr preserve=no  private: std::string {UA} 
      std::string str;
      //## end StringPattern::str%3917E7D200D2.attr

  private:  //## implementation
};

// Class StringPattern 


//## Other Operations (inline)
//## Operation: operator()%888997597; C++
//## Qualification: const inlined
inline bool StringPattern::operator () (const std::string& s) const
{
  //## begin StringPattern::operator()%888997597.body preserve=yes
	return Match(s);
  //## end StringPattern::operator()%888997597.body
}

//## Operation: operator string%957866738
inline StringPattern::operator string () const
{
  //## begin StringPattern::operator string%957866738.body preserve=yes
	return str;
  //## end StringPattern::operator string%957866738.body
}

//## Operation: operator<%957866739
inline bool StringPattern::operator < (const StringPattern& rhs) const
{
  //## begin StringPattern::operator<%957866739.body preserve=yes
	return str<rhs.str;
  //## end StringPattern::operator<%957866739.body
}

//## Operation: operator==%957866740
inline bool StringPattern::operator == (const StringPattern& rhs) const
{
  //## begin StringPattern::operator==%957866740.body preserve=yes
	return str==rhs.str;
  //## end StringPattern::operator==%957866740.body
}

//## begin module%34586D5803C9.epilog preserve=yes
// Utility function for splitting a single string into a list of delimited strings.
// The return pair indicates if the first and last characters of str are dchar.
std::pair<bool,bool> DelimitString(const string& str, char dchar, std::vector<string>& result);
//## end module%34586D5803C9.epilog


#endif

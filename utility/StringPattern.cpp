//## begin module%34586D5803C9.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file utility\StringPattern.cpp
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

//## Module: StringPattern%34586D5803C9; Pseudo Package body
//## Subsystem: utility%350A244000C8
//## Source file: C:\C++\Merlin\utility\StringPattern.cpp

//## begin module%34586D5803C9.includes preserve=yes
#include <iterator>
#include <algorithm>
#include <list>
//## end module%34586D5803C9.includes

// StringPattern
#include "utility/StringPattern.h"
//## begin module%34586D5803C9.additionalDeclarations preserve=yes
//## end module%34586D5803C9.additionalDeclarations


// Class StringPattern 




//## begin StringPattern::wcchar%34FD19110208.attr preserve=no  public: static char {UA} '*'
char StringPattern::wcchar = '*';
//## end StringPattern::wcchar%34FD19110208.attr




//## Operation: StringPattern%888997595; C++
//## Qualification: explicit inlined
StringPattern::StringPattern (const std::string& s)
  //## begin StringPattern::StringPattern%888997595.initialization preserve=yes
  : str(s)
  //## end StringPattern::StringPattern%888997595.initialization
{
  //## begin StringPattern::StringPattern%888997595.body preserve=yes
	wcterm = DelimitString(s,wcchar,patterns);
	isLiteral = !wcterm.first && !wcterm.second && patterns.size()==1;
  //## end StringPattern::StringPattern%888997595.body
}



//## Other Operations (implementation)
//## Operation: Match%888997596; C++
//## Qualification: const
bool StringPattern::Match (const std::string& s) const
{
  //## begin StringPattern::Match%888997596.body preserve=yes
	// deal with trivial cases first
	using namespace std;

	if(isLiteral)
		return patterns[0]==s;

	if(patterns.empty()) {
		if(wcterm.first || s.length()==0)
			return true;
		else
			return false;
	}


	// complex pattern
	
	bool allowFloat = wcterm.first;
	string::size_type n=0;
	for(vector<string>::const_iterator i = patterns.begin();i!=patterns.end();i++) {
		
		if(n==s.length())
			return false;

		if(allowFloat) {
			n = s.find(*i,n);
			if(n==string::npos)
				return false;
			else
				n+=(*i).length();
		}
		else {
			if(s.compare(n,(*i).length(),*i)!=0)
				return false;
			else
				n+=(*i).length();
			allowFloat=true;
		}
	}
	// If we get this far we have exhausted the patterns. Now we need
	// to check if we are at the end of s, or if the last character
	// of the original pattern was a wild card.

	return n == s.length() || wcterm.second;
  //## end StringPattern::Match%888997596.body
}

//## Operation: operator<<%888997598; C++
//## Qualification: friend
ostream& operator << (ostream& os, const StringPattern& pattern)
{
  //## begin StringPattern::operator<<%888997598.body preserve=yes
	if(pattern.wcterm.first)
		os<<StringPattern::wcchar;
	for(int n=0; n<pattern.patterns.size(); n++) {
		if(n!=0)
			os<<StringPattern::wcchar;
		os<<pattern.patterns[n];
	}
	if(pattern.wcterm.second)
		os<<StringPattern::wcchar;

	return os;
  //## end StringPattern::operator<<%888997598.body
}

//## begin module%34586D5803C9.epilog preserve=yes
inline string::const_iterator 
SkipWC(string::const_iterator first, string::const_iterator last, char dchar)
{
	while(first!=last && *first==dchar) ++first;
	return first;
}

std::pair<bool,bool> DelimitString(const string& str, char dchar, std::vector<string>& result)
{
	using namespace std;

	result.clear();
	pair<bool,bool> wcterm(false,false);
	
	if(str.length()==0)
		return wcterm;

	list<string> patterns;
	string::const_iterator i = str.begin();

	if((*i)==dchar) {
		wcterm.first=true;
		i=SkipWC(i,str.end(),dchar);
		if(i==str.end()) {
			wcterm.second=true;
			return wcterm;
		}
	}
	
	while(i!=str.end()) {
		patterns.push_back(string());
		while(i!=str.end() && *i!=dchar) {
			patterns.back()+= *i;
			++i;
		}
		if(i!=str.end()) // must be a wild card
			i=SkipWC(i,str.end(),dchar);
	}

	// check if last character is a dchar
	if(*(--i)==dchar)
		wcterm.second=true;

	// copy patterns into result and return
	result.reserve(patterns.size());
	copy(patterns.begin(),patterns.end(),back_inserter(result));
	return wcterm;
}
//## end module%34586D5803C9.epilog

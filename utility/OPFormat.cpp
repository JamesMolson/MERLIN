//## begin module.cm preserve=no
// Body for OPFormat
// last modified: 03/25/98 at 16:05:43
// This file is part of the MERLIN class library
// version 1.0beta
// ---------------------------------------------
//## end module.cm

//## begin module.cp preserve=no
// (c) 1997 Nicholas J. Walker (DESY) -- All Rights Reserved --
// ------------------------------------------------------------
//## end module.cp

//## Module: OPFormat; Package body
//## Subsystem: utility
//## Source file: c:\C++\Merlin\utility\OPFormat.cpp

//## begin module.includes preserve=yes
#include <sstream>
//## end module.includes

// OPFormat
#include "utility/OPFormat.h"
//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
namespace {
	using namespace std;

	template<class T>
	ostream& output_value(ostream& os, const T& value)
	{
		return os<<value;
	}

	// specialization for strings
	template<>
	ostream& output_value(ostream& os, const string& value)
	{
		return os<<value.c_str();
	}

	template<class T> 
	inline string truncate_str(const string&, const T&, int n)
	{
		// generic truncate fills the field with stars (a la FORTRAN)
		string rv;
		while((n--)>0)
			rv+='*';
		return rv;
	}

	// specialisation for strings
	template<> 
	inline string truncate_str(const string& s, const string&, int n)
	{
		// for strings, we add ellipses
		string rv(s,0,n-2);
		return rv+="..";
	}

	template<class T>
	string to_string(const OPFormat& fmt, const T& val)
	{
		ostringstream os;
		output_value(os<<fmt,val);
		string s = os.str();
		if(!fmt.allowovf && static_cast<int>(s.length())>fmt.wdt)
			return truncate_str(s,val,fmt.wdt);
		else
			return s;
	}
}
//## end module.additionalDeclarations


// Class OPFormat 








//## Other Operations (implementation)
//## Operation: operator()%889857364
string OPFormat::operator () (double val) const
{
  //## begin OPFormat::operator()%889857364.body preserve=yes
	return to_string(*this,val);
  //## end OPFormat::operator()%889857364.body
}

//## Operation: operator()%890835260
string OPFormat::operator () (int val) const
{
  //## begin OPFormat::operator()%890835260.body preserve=yes
	return to_string(*this,val);
  //## end OPFormat::operator()%890835260.body
}

//## Operation: operator()%890835262
string OPFormat::operator () (const string& val) const
{
  //## begin OPFormat::operator()%890835262.body preserve=yes
	return to_string(*this,val);
  //## end OPFormat::operator()%890835262.body
}

//## Operation: operator<<%890835263
ostream& operator << (ostream& os, const OPFormat& fmt)
{
  //## begin OPFormat::operator<<%890835263.body preserve=yes
	os.setf(fmt.fmt,ios_base::floatfield);
	os.setf(fmt.adjust,ios_base::adjustfield);
	os.width(fmt.wdt);
	os.precision(fmt.prc);
	return os;
  //## end OPFormat::operator<<%890835263.body
}



//## begin module.epilog preserve=yes
//## end module.epilog

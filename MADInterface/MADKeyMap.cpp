//   Read the documentation to learn more about C++ code generator
//   versioning.

/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 3.0 (2003)
 * 
 * file Merlin\MADInterface\MADKeyMap.cpp
 * last modified 20/11/01 12:46:22
 */

/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 2003 by The Merlin Collaboration.
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

#include <sstream>
#include "IO/MerlinIO.h"

// MADKeyMap
#include "MADInterface/MADKeyMap.h"
using namespace std;

// Class MADKeyMap::bad_key

// Class MADKeyMap

MADKeyMap::MADKeyMap (const std::string& hstr)
        : has_type(false)
{
    istringstream is(hstr);
    size_t n=0;
    string s;
    while(is>>s) {
        if(s=="TYPE") {
            has_type=true;
        }
        else
            kmap[s]=n++;
    }

#ifndef NDEBUG
    cout<<n<<" column headings identified"<<endl;
#endif

    vals = vector<double>(n,0.0);
}

double MADKeyMap::GetParameter (const std::string& key, bool warn)
{
    key_map::iterator p = kmap.find(key);
    if(p!=kmap.end())
        return vals[p->second];
    else {
        if(warn)
            MerlinIO::warning()<<key<<" not in optics listing. Defaulted to zero"<<endl;
        return 0;
    }
}

void MADKeyMap::ReadRow (std::istream& is)
{
    for(size_t i=0; i<vals.size(); i++)
        is>>vals[i];
}


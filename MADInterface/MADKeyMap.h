//   Read the documentation to learn more about C++ code generator
//   versioning.

/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 3.0 (2003)
 * 
 * file Merlin\MADInterface\MADKeyMap.h
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

#ifndef MADKeyMap_h
#define MADKeyMap_h 1

#include "merlin_config.h"

#include <string>
#include <vector>
#include <iostream>

#include <map>

//      Implementation class for mapping column keys in optics
//      listing to element types during construction.

class MADKeyMap
{
public:

    typedef std::map< std::string , size_t  > key_map;

    class bad_key
    {
    public:
    protected:
    private:
    private:
    };

    //        Constructs a key map from the optics listing line
    //        containing the column headings.
    MADKeyMap (const std::string& hstr);

    //        Returns the value of the parameter for a specificed key.
    //        Throws BAD_KEY if not present.
    virtual double GetParameter (const std::string& key, bool warn=true);

    //        Reads in the values for the next row.
    virtual void ReadRow (std::istream& is);

    bool has_type;
public:
protected:
private:
    // Data Members for Class Attributes

    std::vector<double> vals;

    // Data Members for Associations
    std::string type_str;

    key_map kmap;

private:
};

// Class MADKeyMap::bad_key

// Class MADKeyMap

#endif

//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3BFA3CF402D3.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\MADInterface\MADKeyMap.h
 * last modified 20/11/01 12:46:22
 */
//## end module%3BFA3CF402D3.cm

//## begin module%3BFA3CF402D3.cp preserve=no
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
//## end module%3BFA3CF402D3.cp

//## Module: MADKeyMap%3BFA3CF402D3; Pseudo Package specification
//## Source file: C:\C++\Merlin\MADInterface\MADKeyMap.h

#ifndef MADKeyMap_h
#define MADKeyMap_h 1

//## begin module%3BFA3CF402D3.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3BFA3CF402D3.additionalIncludes

//## begin module%3BFA3CF402D3.includes preserve=yes
#include <string>
#include <vector>
#include <iostream>
//## end module%3BFA3CF402D3.includes

#include <map>
//## begin module%3BFA3CF402D3.additionalDeclarations preserve=yes
//## end module%3BFA3CF402D3.additionalDeclarations


//## Class: MADKeyMap%3BFA3CF402D3
//	Implementation class for mapping column keys in optics
//	listing to element types during construction.
//## Category: Merlin::MADInterface%39576D3C0226
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: throws%3BFA3FFB009D;MADKeyMap::bad_key { -> }

class MADKeyMap 
{
  public:
    //## Class: key_map%3BFA3F2B02CF; Instantiated Class
    //## Category: Merlin::MADInterface%39576D3C0226
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    typedef std::map< std::string , size_t  > key_map;

    //## Class: bad_key%3BFA3FF101CF
    //## Category: Merlin::MADInterface%39576D3C0226
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    class bad_key 
    {
      public:
      protected:
      private:
      private: //## implementation
    };

    //## Constructors (specified)
      //## Operation: MADKeyMap%3BFA3DB302B0
      //	Constructs a key map from the optics listing line
      //	containing the column headings.
      MADKeyMap (const std::string& hstr);


    //## Other Operations (specified)
      //## Operation: GetParameter%3BFA3DCC032E
      //	Returns the value of the parameter for a specificed key.
      //	Throws BAD_KEY if not present.
      virtual double GetParameter (const std::string& key, bool warn=true);

      //## Operation: ReadRow%3BFA3ED70274
      //	Reads in the values for the next row.
      virtual void ReadRow (std::istream& is);

	  bool has_type;
  public:
  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: vals%3BFA403B0225
      //## begin MADKeyMap::vals%3BFA403B0225.attr preserve=no  private: std::vector<double> {UA} 
      std::vector<double> vals;
      //## end MADKeyMap::vals%3BFA403B0225.attr

    // Data Members for Associations
	  std::string type_str;

      //## Association: Merlin::MADInterface::<unnamed>%3BFA3FA90320
      //## Role: MADKeyMap::kmap%3BFA3FAA0096
      //## begin MADKeyMap::kmap%3BFA3FAA0096.role preserve=no  private: MADKeyMap::key_map { -> 1VHgAN}
      key_map kmap;
      //## end MADKeyMap::kmap%3BFA3FAA0096.role

  private: //## implementation
};

// Class MADKeyMap::bad_key 

// Class MADKeyMap 

//## begin module%3BFA3CF402D3.epilog preserve=yes
//## end module%3BFA3CF402D3.epilog


#endif

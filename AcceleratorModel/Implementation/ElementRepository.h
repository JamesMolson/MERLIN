//## begin module%3AC877AA0096.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\ElementRepository.h
 * last modified 03/04/01 14:35:02
 */
//## end module%3AC877AA0096.cm

//## begin module%3AC877AA0096.cp preserve=no
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
//## end module%3AC877AA0096.cp

//## Module: ElementRepository%3AC877AA0096; Package specification
//## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\ElementRepository.h

#ifndef ElementRepository_h
#define ElementRepository_h 1

//## begin module%3AC877AA0096.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AC877AA0096.additionalIncludes

//## begin module%3AC877AA0096.includes preserve=yes
#include <vector>
#include <string>
//## end module%3AC877AA0096.includes

// ModelElement
#include "AcceleratorModel/ModelElement.h"
#include <set>


//## begin module%3AC877AA0096.declarations preserve=no
//## end module%3AC877AA0096.declarations

//## begin module%3AC877AA0096.additionalDeclarations preserve=yes
//## end module%3AC877AA0096.additionalDeclarations


//## Class: ElementRepository%3A97DF040050
//	Used to store and access all the ModelElement objects
//	associated (contained) by an AcceleratorModel. Primary
//	functions are fast keyed access to ModelElements, and
//	memory management.
//## Category: Merlin::AcceleratorModel::Implementation%39059A9B0090
//## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3A9B975900DC;StringPattern { -> }
//## Uses: <unnamed>%3A9B98690140;map_deleter { -> }

class ElementRepository 
{
  public:
    //## Class: ElementSet%3A9B958302C6; Instantiated Class
    //	Used to map the element ID's to ModelElement objects in
    //	the repository.
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: <unnamed>%3A9B96C100F0;ModelElement { -> F}

    typedef std::set< ModelElement* > ElementSet;

    //## Class: iterator%3A9BA730005A
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef ElementSet::iterator iterator;

    //## Class: const_iterator%3A9BA737029E
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef ElementSet::const_iterator const_iterator;

  public:
    //## Destructor (specified)
      //## Operation: ~ElementRepository%983275406
      ~ElementRepository ();


    //## Other Operations (specified)
      //## Operation: Add%983275407
      //	Adds the element to the repository. Returns true if
      //	successful, or false if the element already exists in
      //	the repository.
      bool Add (ModelElement* anElement);

      //## Operation: Count%983275408
      //	Counts the number of elements in the repository with
      //	identifiers which match id. id takes the form
      //	"type.name", where type, name or both can be patterns.
      size_t Count (const std::string& id) const;

      //## Operation: Find%983275409
      //	Finds and returns in elements all ModelElement objects
      //	whose identifiers match id (see Count() for details of
      //	id).
      size_t Find (const std::string& id, std::vector<ModelElement*>& elements);

      //## Operation: Size%983275410
      //	Returns the number of ModelElement objects in the
      //	repository.
      size_t Size () const;

      //## Operation: begin%983275411
      ElementRepository::iterator begin ();

      //## Operation: end%983275412
      ElementRepository::iterator end ();

      //## Operation: begin%983275413
      ElementRepository::const_iterator begin () const;

      //## Operation: end%983275414
      ElementRepository::const_iterator end () const;

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Implementation::<unnamed>%3AC4E205035C
      //## Role: ElementRepository::theElements%3AC4E2060320
      //## begin ElementRepository::theElements%3AC4E2060320.role preserve=no  public: ElementRepository::ElementSet { -> 1VHAN}
      ElementSet theElements;
      //## end ElementRepository::theElements%3AC4E2060320.role

      //## Association: Merlin::AcceleratorModel::Implementation::<unnamed>%3AC45D0603D4
      //## Role: ElementRepository::<the_ModelElement>%3AC45D0702EE
      //## begin ElementRepository::<the_ModelElement>%3AC45D0702EE.role preserve=no  public: ModelElement { -> nVHAN}
      //## end ElementRepository::<the_ModelElement>%3AC45D0702EE.role

  protected:
  private:
  private:  //## implementation
};

// Class ElementRepository 


//## Other Operations (inline)
//## Operation: Size%983275410
inline size_t ElementRepository::Size () const
{
  //## begin ElementRepository::Size%983275410.body preserve=yes
	return theElements.size();
  //## end ElementRepository::Size%983275410.body
}

//## Operation: begin%983275411
inline ElementRepository::iterator ElementRepository::begin ()
{
  //## begin ElementRepository::begin%983275411.body preserve=yes
	return theElements.begin();
  //## end ElementRepository::begin%983275411.body
}

//## Operation: end%983275412
inline ElementRepository::iterator ElementRepository::end ()
{
  //## begin ElementRepository::end%983275412.body preserve=yes
	return theElements.end();
  //## end ElementRepository::end%983275412.body
}

//## Operation: begin%983275413
inline ElementRepository::const_iterator ElementRepository::begin () const
{
  //## begin ElementRepository::begin%983275413.body preserve=yes
	return theElements.begin();
  //## end ElementRepository::begin%983275413.body
}

//## Operation: end%983275414
inline ElementRepository::const_iterator ElementRepository::end () const
{
  //## begin ElementRepository::end%983275414.body preserve=yes
	return theElements.end();
  //## end ElementRepository::end%983275414.body
}

//## begin module%3AC877AA0096.epilog preserve=yes
//## end module%3AC877AA0096.epilog


#endif

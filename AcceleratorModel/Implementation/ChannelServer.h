//## begin module%3AC8773E0370.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Implementation\ChannelServer.h
 * last modified 05/04/01 17:05:02
 */
//## end module%3AC8773E0370.cm

//## begin module%3AC8773E0370.cp preserve=no
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
//## end module%3AC8773E0370.cp

//## Module: ChannelServer%3AC8773E0370; Package specification
//## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
//## Source file: D:\dev\Merlin\AcceleratorModel\Implementation\ChannelServer.h

#ifndef ChannelServer_h
#define ChannelServer_h 1

//## begin module%3AC8773E0370.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AC8773E0370.additionalIncludes

//## begin module%3AC8773E0370.includes preserve=yes
#include <string>
#include <map>
//## end module%3AC8773E0370.includes

// ElementRepository
#include "AcceleratorModel/Implementation/ElementRepository.h"

class ModelElement;
class RWChannel;
class ROChannel;
class StringPattern;

//## begin module%3AC8773E0370.declarations preserve=no
//## end module%3AC8773E0370.declarations

//## begin module%3AC8773E0370.additionalDeclarations preserve=yes
//## end module%3AC8773E0370.additionalDeclarations


//## Class: ChannelServer%3A97DD890096
//	Responsible for providing an interface to ROChannel and
//	RWChannel for the ModelElements in the AcceleratorModel.
//## Category: Merlin::AcceleratorModel::Implementation%39059A9B0090
//## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3A97E2BB03AC;RWChannel { -> F}
//## Uses: <unnamed>%3A97E2BD024E;ROChannel { -> F}
//## Uses: <unnamed>%3A97E2F0000A;StringPattern { -> F}

class ChannelServer 
{
  public:
    //## Class: ChannelCtor%3A97E3E000C8; Abstract
    //	Abstract factory class for RWChannel objects.
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: creates%3A97E44E03DE;RWChannel { -> F}
    //## Uses: <unnamed>%3A97E47B03CA;ModelElement { -> F}

    class ChannelCtor 
    {
      public:

          virtual ~ChannelCtor() {}

        //## Other Operations (specified)
          //## Operation: ConstructRO%986466253
          //	Constructs a channel for the specified ModelElement.
          virtual ROChannel* ConstructRO (ModelElement* anElement) = 0;

          //## Operation: ConstructRW%983187849
          //	Constructs a channel for the specified ModelElement.
          virtual RWChannel* ConstructRW (ModelElement* anElement) = 0;

          //## Operation: GetID%983187850
          //	Returns the ID of the channel (i.e. type.key).
          std::string GetID ();

          //## Operation: GetType%983275416
          //	Returns the ModelElement type.
          const string& GetType () const;

          //## Operation: GetKey%983275417
          //	Returns the channel key.
          const string& GetKey () const;

      protected:
        //## Constructors (specified)
          //## Operation: ChannelCtor%983187855
          ChannelCtor (const string& aType, const string& aKey);

        // Data Members for Class Attributes

          //## Attribute: type%3A97E5490118
          //## begin ChannelServer::ChannelCtor::type%3A97E5490118.attr preserve=no  protected: std::string {UA} 
          std::string type;
          //## end ChannelServer::ChannelCtor::type%3A97E5490118.attr

          //## Attribute: key%3A97E54E03DE
          //## begin ChannelServer::ChannelCtor::key%3A97E54E03DE.attr preserve=no  protected: std::string {UA} 
          std::string key;
          //## end ChannelServer::ChannelCtor::key%3A97E54E03DE.attr

      private:
      private:  //## implementation
    };

    //## Class: CtorTable%3A9A6A65030C
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: <unnamed>%3A9A6AEA038E;ChannelCtor { -> }

    typedef std::map<std::string,ChannelCtor*> CtorTable;

  public:

    //## Other Operations (specified)
      //## Operation: GetROChannels%983187851
      //	Returns in channels all ROChannels matching chID.
      //	Returns the number of channels found.
      size_t GetROChannels (const string& chID, std::vector<ROChannel*>& channels);

      //## Operation: GetRWChannels%983275415
      //	Returns in channels all RWChannels matching chID.
      //	Returns the number of channels found.
      size_t GetRWChannels (const string& chID, std::vector<RWChannel*>& channels);

      //## Operation: RegisterCtor%983187853
      //	Adds a ChannelCtor object to the server.
      void RegisterCtor (ChannelCtor* chctor);

      //## Operation: SetRepository%983187854
      void SetRepository (ElementRepository* me_repo);

  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Implementation::<unnamed>%3A97E22802B2
      //## Role: ChannelServer::theElements%3A97E22A0078
      //## begin ChannelServer::theElements%3A97E22A0078.role preserve=no  private: ElementRepository { -> 1RHAN}
      ElementRepository* theElements;
      //## end ChannelServer::theElements%3A97E22A0078.role

      //## Association: Merlin::AcceleratorModel::Implementation::<unnamed>%3A9A6AB7029E
      //## Role: ChannelServer::chCtors%3A9A6AB80258
      //## begin ChannelServer::chCtors%3A9A6AB80258.role preserve=no  private: ChannelServer::CtorTable { -> 1VHAN}
      CtorTable chCtors;
      //## end ChannelServer::chCtors%3A9A6AB80258.role

      //## Association: Merlin::AcceleratorModel::Implementation::channel ctors%3ACC50310122
      //## Role: ChannelServer::<the_ChannelCtor>%3ACC5032000B
      //## begin ChannelServer::<the_ChannelCtor>%3ACC5032000B.role preserve=no  private: ChannelServer::ChannelCtor { -> nVHADN}
      //## end ChannelServer::<the_ChannelCtor>%3ACC5032000B.role

  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: FindCtors%983275418
      void FindCtors (const string& type, const string& keypat, std::set<ChannelCtor*>& ctors);

      //## Operation: FindElements%986466256
      //	Returns in elements the ModelElements that match
      //	pattern. elements is sorted by TYPE.
      void FindElements (const std::string& id_pat, std::vector<ModelElement*>& elements);

};

// Class ChannelServer::ChannelCtor 

//## Operation: ChannelCtor%983187855
inline ChannelServer::ChannelCtor::ChannelCtor (const string& aType, const string& aKey)
  //## begin ChannelServer::ChannelCtor::ChannelCtor%983187855.initialization preserve=yes
  : type(aType),key(aKey)
  //## end ChannelServer::ChannelCtor::ChannelCtor%983187855.initialization
{
  //## begin ChannelServer::ChannelCtor::ChannelCtor%983187855.body preserve=yes
  //## end ChannelServer::ChannelCtor::ChannelCtor%983187855.body
}



//## Other Operations (inline)
//## Operation: GetType%983275416
inline const string& ChannelServer::ChannelCtor::GetType () const
{
  //## begin ChannelServer::ChannelCtor::GetType%983275416.body preserve=yes
	return type;
  //## end ChannelServer::ChannelCtor::GetType%983275416.body
}

//## Operation: GetKey%983275417
inline const string& ChannelServer::ChannelCtor::GetKey () const
{
  //## begin ChannelServer::ChannelCtor::GetKey%983275417.body preserve=yes
	return key;
  //## end ChannelServer::ChannelCtor::GetKey%983275417.body
}

// Class ChannelServer 

//## begin module%3AC8773E0370.epilog preserve=yes
//## end module%3AC8773E0370.epilog


#endif

//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3AC8773E0370.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\Implementation\ChannelServer.h
 * last modified 03/06/02 12:16:39
 */
//## end module%3AC8773E0370.cm

//## begin module%3AC8773E0370.cp preserve=no
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
//## end module%3AC8773E0370.cp

//## Module: ChannelServer%3AC8773E0370; Package specification
//## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
//## Source file: C:\C++\Merlin\AcceleratorModel\Implementation\ChannelServer.h

#ifndef ChannelServer_h
#define ChannelServer_h 1

//## begin module%3AC8773E0370.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AC8773E0370.additionalIncludes

//## begin module%3AC8773E0370.includes preserve=yes
#include <string>
#include <map>
#include "AcceleratorModel/AcceleratorModel.h"
//## end module%3AC8773E0370.includes

// ElementRepository
#include "AcceleratorModel/Implementation/ElementRepository.h"

class ModelElement;
class StringPattern;
class RWChannel;
class ROChannel;

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
    //## Category: Merlin::AcceleratorModel::Implementation%39059A9B0090
    //## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    //## Uses: creates%3A97E44E03DE;RWChannel { -> F}
    //## Uses: <unnamed>%3A97E47B03CA;ModelElement { -> F}

    class ChannelCtor 
    {
      public:

      // destructor
      virtual ~ChannelCtor() {}

        //## Other Operations (specified)
          //## Operation: ConstructRO%3ACC6C9203B6
          //	Constructs a channel for the specified ModelElement.
          virtual ROChannel* ConstructRO (ModelElement* anElement) = 0;

          //## Operation: ConstructRW%3A97E4D70136
          //	Constructs a channel for the specified ModelElement.
          virtual RWChannel* ConstructRW (ModelElement* anElement) = 0;

          //## Operation: GetID%3A98F7210032
          //	Returns the ID of the channel (i.e. type.key).
          std::string GetID ();

          //## Operation: GetType%3A9BB84E00D2
          //	Returns the ModelElement type.
          const string& GetType () const;

          //## Operation: GetKey%3A9BB8580064
          //	Returns the channel key.
          const string& GetKey () const;

      protected:
        //## Constructors (specified)
          //## Operation: ChannelCtor%3A9A67BB0000
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
      private: //## implementation
    };

    //## Class: CtorTable%3A9A6A65030C
    //## Category: Merlin::AcceleratorModel::Implementation%39059A9B0090
    //## Subsystem: Merlin::AcceleratorModel::Implementation%390819010048
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    //## Uses: <unnamed>%3A9A6AEA038E;ChannelCtor { -> }

    typedef std::map<std::string,ChannelCtor*> CtorTable;


    //## Other Operations (specified)
      //## Operation: GetROChannels%3A97E2FD019A
      //	Returns in channels all ROChannels matching chID.
      //	Returns the number of channels found.
      size_t GetROChannels (const string& chID, std::vector<ROChannel*>& channels);

      //## Operation: GetRWChannels%3A9BB463014A
      //	Returns in channels all RWChannels matching chID.
      //	Returns the number of channels found.
      size_t GetRWChannels (const string& chID, std::vector<RWChannel*>& channels);

      //## Operation: GetROChannels%3CFB41FB02F0
      //	Returns read-only channels matching chid for all
      //	matching components in aBeamline. Note that only
      //	channels associated with AcceleratorComponents can be
      //	extracted using this method.
      size_t GetROChannels (AcceleratorModel::Beamline& aBeamline, const std::string& chid, std::vector<ROChannel*>& channels);

      //## Operation: GetRWChannels%3CFB41FB0304
      //	Returns read-write channels matching chid for all
      //	matching components in aBeamline. Note that only
      //	channels associated with AcceleratorComponents can be
      //	extracted using this method.
      size_t GetRWChannels (AcceleratorModel::Beamline& aBeamline, const std::string& chid, std::vector<RWChannel*>& channels);

      //## Operation: RegisterCtor%3A98F66E00D2
      //	Adds a ChannelCtor object to the server.
      void RegisterCtor (ChannelCtor* chctor);

      //## Operation: SetRepository%3A9900C002E4
      void SetRepository (ElementRepository* me_repo);

  public:
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
      //## begin ChannelServer::chCtors%3A9A6AB80258.role preserve=no  private: ChannelServer::CtorTable { -> 1VHgAN}
      CtorTable chCtors;
      //## end ChannelServer::chCtors%3A9A6AB80258.role

  private: //## implementation

    //## Other Operations (specified)
      //## Operation: FindCtors%3A9BC624001E
      void FindCtors (const string& type, const string& keypat, std::set<ChannelCtor*>& ctors);

      //## Operation: FindElements%3ACC82C002C6
      //	Returns in elements the ModelElements that match
      //	pattern. elements is sorted by TYPE.
      void FindElements (const std::string& id_pat, std::vector<ModelElement*>& elements);

};

// Class ChannelServer::ChannelCtor 

//## Operation: ChannelCtor%3A9A67BB0000
inline ChannelServer::ChannelCtor::ChannelCtor (const string& aType, const string& aKey)
  //## begin ChannelServer::ChannelCtor::ChannelCtor%3A9A67BB0000.initialization preserve=yes
  : type(aType),key(aKey)
  //## end ChannelServer::ChannelCtor::ChannelCtor%3A9A67BB0000.initialization
{
  //## begin ChannelServer::ChannelCtor::ChannelCtor%3A9A67BB0000.body preserve=yes
  //## end ChannelServer::ChannelCtor::ChannelCtor%3A9A67BB0000.body
}



//## Other Operations (inline)
//## Operation: GetType%3A9BB84E00D2
inline const string& ChannelServer::ChannelCtor::GetType () const
{
  //## begin ChannelServer::ChannelCtor::GetType%3A9BB84E00D2.body preserve=yes
	return type;
  //## end ChannelServer::ChannelCtor::GetType%3A9BB84E00D2.body
}

//## Operation: GetKey%3A9BB8580064
inline const string& ChannelServer::ChannelCtor::GetKey () const
{
  //## begin ChannelServer::ChannelCtor::GetKey%3A9BB8580064.body preserve=yes
	return key;
  //## end ChannelServer::ChannelCtor::GetKey%3A9BB8580064.body
}

// Class ChannelServer 

//## begin module%3AC8773E0370.epilog preserve=yes
//## end module%3AC8773E0370.epilog


#endif

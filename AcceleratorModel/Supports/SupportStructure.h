//## begin module%395B700C00C8.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Supports\SupportStructure.h
 * last modified 28/03/01 17:23:15
 */
//## end module%395B700C00C8.cm

//## begin module%395B700C00C8.cp preserve=no
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
//## end module%395B700C00C8.cp

//## Module: SupportStructure%395B700C00C8; Package specification
//## Subsystem: Merlin::AcceleratorModel::Supports%395B6FFB0186
//## Source file: D:\dev\Merlin\AcceleratorModel\Supports\SupportStructure.h

#ifndef SupportStructure_h
#define SupportStructure_h 1

//## begin module%395B700C00C8.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%395B700C00C8.additionalIncludes

//## begin module%395B700C00C8.includes preserve=yes
//## end module%395B700C00C8.includes

// AcceleratorSupport
#include "AcceleratorModel/Supports/AcceleratorSupport.h"
// SequenceFrame
#include "AcceleratorModel/Frames/SequenceFrame.h"
// Transform3D
#include "EuclideanGeometry/Transform3D.h"
// Rotation3D
#include "EuclideanGeometry/Rotation3D.h"
//## begin module%395B700C00C8.declarations preserve=no
//## end module%395B700C00C8.declarations

//## begin module%395B700C00C8.additionalDeclarations preserve=yes
//## end module%395B700C00C8.additionalDeclarations


//## Class: SupportStructure%3957AC5E014A
//	A SupportStructure represents a mechanical support
//	system, on which accelerator components can be mounted.
//	A SupportStructure is mounted to the ground by either
//	one Support placed at the centre of enclosed geometry,
//	or by two supports at the exit and entrance points.
//
//	SupportStructure and its associated Support class are
//	primarilly intended for application of ground motion and
//	vibration.
//## Category: Merlin::AcceleratorModel::Supports%3AB8BC620154
//## Subsystem: Merlin::AcceleratorModel::Supports%395B6FFB0186
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%395B61460276;SupportStructure::Type { -> }
//## Uses: <unnamed>%395B63140302;AcceleratorSupportList { -> }

class SupportStructure : public SequenceFrame  //## Inherits: <unnamed>%3957AC720028
{
  public:
    //## Class: Type%3AC0E4EC0262
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef enum {simple,girder} Type;

  public:
    //## Constructors (specified)
      //## Operation: SupportStructure%962293952
      //	Copy constructor.
      SupportStructure (const SupportStructure& rhs);

    //## Destructor (specified)
      //## Operation: ~SupportStructure%962293953
      //	Destructor.
      ~SupportStructure ();


    //## Other Operations (specified)
      //## Operation: ExportSupports%962293956
      //	Appends this structures support(s) to the SupportList.
      //	Returns the number of supports appended.
      int ExportSupports (AcceleratorSupportList& supports);

      //## Operation: GetLocalFrameTransform%985682914
      //	Returns the local frame transformation. The result
      //	includes results of effects of the support offsets, as
      //	well as local transformations of the girder.
      virtual Transform3D GetLocalFrameTransform () const;

      //## Operation: ConsolidateConstruction%962293960
      //	When called, SupportStructure sets up is Accelerator
      //	Structure objects. This function should only be called
      //	after the AcceleratorModel is complete.
      virtual void ConsolidateConstruction ();

  protected:
    //## Constructors (specified)
      //## Operation: SupportStructure%962293951
      SupportStructure (const string& id, Type type);

  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Supports::<unnamed>%3AC0E10901D6
      //## Role: SupportStructure::sup1%3AC0E10A01CD
      //## begin SupportStructure::sup1%3AC0E10A01CD.role preserve=no  private: AcceleratorSupport { -> 0..1VHAN}
      AcceleratorSupport* sup1;
      //## end SupportStructure::sup1%3AC0E10A01CD.role

      //## Association: Merlin::AcceleratorModel::Supports::<unnamed>%3AC0E6320032
      //## Role: SupportStructure::sup2%3AC0E633005A
      //## begin SupportStructure::sup2%3AC0E633005A.role preserve=no  private: AcceleratorSupport { -> 0..1VHAN}
      AcceleratorSupport* sup2;
      //## end SupportStructure::sup2%3AC0E633005A.role

  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: UpdateSupportTransform%985600394
      //	Updates (if necessary) the local frame transformation
      //	due to the support offsets.
      void UpdateSupportTransform () const;

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Supports::<unnamed>%3AC0A9570096
      //## Role: SupportStructure::Rg%3AC0A958015E
      //	Rotation used to convert the support motion into the
      //	local entrance plane reference frame.
      //## begin SupportStructure::Rg%3AC0A958015E.role preserve=no  implementation: Rotation3D { -> 1VHAN}
      Rotation3D Rg;
      //## end SupportStructure::Rg%3AC0A958015E.role

      //## Association: Merlin::AcceleratorModel::Supports::<unnamed>%3AC0AA07023A
      //## Role: SupportStructure::Ts%3AC0AA09017C
      //	Cached transformation state. Used to calculate the local
      //	frame transformation. Is recalculated if an offset of an
      //	accelerator support has changed.
      //## begin SupportStructure::Ts%3AC0AA09017C.role preserve=no  implementation: Transform3D { -> 1VHANM}
      mutable Transform3D Ts;
      //## end SupportStructure::Ts%3AC0AA09017C.role

};

//## Class: GirderMount%3AC0DF420136
//	Represents a long mount structure (girder) which has two
//	supports at either end. A girder can tilt under the
//	action of the two supports.
//## Category: Merlin::AcceleratorModel::Supports%3AB8BC620154
//## Subsystem: Merlin::AcceleratorModel::Supports%395B6FFB0186
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class GirderMount : public SupportStructure  //## Inherits: <unnamed>%3AC0E3590352
{
  public:
    //## Constructors (specified)
      //## Operation: GirderMount%985720233
      explicit GirderMount (const std::string& id);


    //## Other Operations (specified)
      //## Operation: GetType%962293958
      //	Returns "SupportStructure".
      virtual const string& GetType () const;

      //## Operation: Copy%962293959
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

  protected:
  private:
  private:  //## implementation
};

//## Class: SimpleMount%3AC0DF51012C
//	An accelerator mount which has a single support located
//	at the centre of the geometry (local origin).
//## Category: Merlin::AcceleratorModel::Supports%3AB8BC620154
//## Subsystem: Merlin::AcceleratorModel::Supports%395B6FFB0186
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class SimpleMount : public SupportStructure  //## Inherits: <unnamed>%3AC0E35702F8
{
  public:
    //## Constructors (specified)
      //## Operation: SimpleMount%985720234
      explicit SimpleMount (const std::string& id);


    //## Other Operations (specified)
      //## Operation: GetType%985792507
      //	Returns "SupportStructure".
      virtual const string& GetType () const;

      //## Operation: Copy%985792508
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

  protected:
  private:
  private:  //## implementation
};

// Class SupportStructure 

// Class GirderMount 

//## Operation: GirderMount%985720233
inline GirderMount::GirderMount (const std::string& id)
  //## begin GirderMount::GirderMount%985720233.initialization preserve=yes
  : SupportStructure(id,girder)
  //## end GirderMount::GirderMount%985720233.initialization
{
  //## begin GirderMount::GirderMount%985720233.body preserve=yes
  //## end GirderMount::GirderMount%985720233.body
}


// Class SimpleMount 

//## Operation: SimpleMount%985720234
inline SimpleMount::SimpleMount (const std::string& id)
  //## begin SimpleMount::SimpleMount%985720234.initialization preserve=yes
  : SupportStructure(id,simple)
  //## end SimpleMount::SimpleMount%985720234.initialization
{
  //## begin SimpleMount::SimpleMount%985720234.body preserve=yes
  //## end SimpleMount::SimpleMount%985720234.body
}


//## begin module%395B700C00C8.epilog preserve=yes
//## end module%395B700C00C8.epilog


#endif

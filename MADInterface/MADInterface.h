//## begin module%3ADEDE2E0320.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\MADInterface\MADInterface.h
 * last modified 19/04/01 14:50:33
 */
//## end module%3ADEDE2E0320.cm

//## begin module%3ADEDE2E0320.cp preserve=no
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
//## end module%3ADEDE2E0320.cp

//## Module: MADInterface%3ADEDE2E0320; Package specification
//## Subsystem: Merlin::MADInterface%3ADEDE110316
//## Source file: D:\dev\Merlin\MADInterface\MADInterface.h

#ifndef MADInterface_h
#define MADInterface_h 1

//## begin module%3ADEDE2E0320.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3ADEDE2E0320.additionalIncludes

//## begin module%3ADEDE2E0320.includes preserve=yes
#include <fstream>
#include <string>
#include <set>
//## end module%3ADEDE2E0320.includes

// AcceleratorModel
#include "AcceleratorModel/AcceleratorModel.h"

class AcceleratorModelConstructor;

//## begin module%3ADEDE2E0320.declarations preserve=no
//## end module%3ADEDE2E0320.declarations

//## begin module%3ADEDE2E0320.additionalDeclarations preserve=yes
using std::ifstream;
using std::ostream;
//## end module%3ADEDE2E0320.additionalDeclarations


//## Class: MADInterface%39576D6500C8
//	Class used to construct a MERLIN model from a MAD optics
//	output listing. The file should be generated using the
//	following MAD commands:
//
//	OPTICS, NAME, KEYWORD ,S, L ,K0L , K1L, K2L,&
//	               K3L,TILT,TYPE
//## Category: Merlin::MADInterface%39576D3C0226
//## Subsystem: Merlin::MADInterface%3ADEDE110316
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: constructs%39576DBF006E;AcceleratorModel { -> }
//## Uses: <unnamed>%39576DEE00F0;PhysicalConstants { -> }
//## Uses: <unnamed>%39576FCA00AA;SequenceFrame { -> }
//## Uses: <unnamed>%3957B7BD0334;MagnetMover { -> }
//## Uses: <unnamed>%3965D71E007D;RectangularAperture { -> }
//## Uses: <unnamed>%3965D7200333;CircularAperture { -> }
//## Uses: <unnamed>%3AC2034F03DE;GirderMount { -> }
//## Uses: <unnamed>%3AC203540032;SimpleMount { -> }

class MADInterface 
{
  public:
    //## Constructors (specified)
      //## Operation: MADInterface%962031285
      //	Constructor taking the name of the MAD optics file, and
      //	the momentum in GeV/c.
      MADInterface (const std::string& madFileName, double P0);


    //## Other Operations (specified)
      //## Operation: ConstructModel%962031286
      //	Causes the construction of an AcceleratorModel object
      //	based on the MAD optics file.
      AcceleratorModel* ConstructModel ();

      //## Operation: SetLogFile%962031287
      //	Sets the log file stream to os.
      void SetLogFile (ostream& os);

      //## Operation: SetLoggingOn%962031288
      //	Turns logging on.
      void SetLoggingOn ();

      //## Operation: SetLoggingOff%962031289
      //	Turns logging off.
      void SetLoggingOff ();

      //## Operation: HonourMadStructure%962967902
      //	If true, all LINE constructs in the MAD optics output
      //	are constructed in the model. If false, only those
      //	prefixed X_, where X is M, S, or G are constructed.
      void HonourMadStructure (bool flg);

      //## Operation: ConstructFlatLattice%962967903
      //	If true, a flat lattice model in constructed, with no
      //	nested frames.
      void ConstructFlatLattice (bool flg);

      //## Operation: ConstructApertures%962967924
      void ConstructApertures (bool flg);

      //## Operation: IgnoreZeroLengthType%962967925
      //	Components of type madType are ignored during
      //	construction if their length is zero.
      void IgnoreZeroLengthType (const string& madType);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: brho%39576D72010E
      //## begin MADInterface::brho%39576D72010E.attr preserve=no  private: double {UA} 
      double brho;
      //## end MADInterface::brho%39576D72010E.attr

      //## Attribute: ifs%39576D79038E
      //## begin MADInterface::ifs%39576D79038E.attr preserve=no  private: ifstream {UA} 
      ifstream ifs;
      //## end MADInterface::ifs%39576D79038E.attr

      //## Attribute: log%39577AB001EA
      //## begin MADInterface::log%39577AB001EA.attr preserve=no  private: ostream* {UA} 
      ostream* log;
      //## end MADInterface::log%39577AB001EA.attr

      //## Attribute: logFlag%3957820702C6
      //## begin MADInterface::logFlag%3957820702C6.attr preserve=no  private: bool {UA} 
      bool logFlag;
      //## end MADInterface::logFlag%3957820702C6.attr

      //## Attribute: flatLattice%3965B92A03C0
      //## begin MADInterface::flatLattice%3965B92A03C0.attr preserve=no  private: bool {UA} 
      bool flatLattice;
      //## end MADInterface::flatLattice%3965B92A03C0.attr

      //## Attribute: honMadStructs%3965B94002BD
      //## begin MADInterface::honMadStructs%3965B94002BD.attr preserve=no  private: bool {UA} 
      bool honMadStructs;
      //## end MADInterface::honMadStructs%3965B94002BD.attr

      //## Attribute: incApertures%3965D79F0082
      //## begin MADInterface::incApertures%3965D79F0082.attr preserve=no  private: bool {UA} 
      bool incApertures;
      //## end MADInterface::incApertures%3965D79F0082.attr

      //## Attribute: zeroLengths%3965E74000AE
      //## begin MADInterface::zeroLengths%3965E74000AE.attr preserve=no  private: std::set<string> {UA} 
      std::set<string> zeroLengths;
      //## end MADInterface::zeroLengths%3965E74000AE.attr

  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: ConstructNewFrame%962967904
      void ConstructNewFrame (const string& name);

      //## Operation: EndFrame%962967905
      void EndFrame (const string& name);

      //## Operation: ReadComponent%962967906
      double ReadComponent ();

    // Data Members for Associations

      //## Association: Merlin::MADInterface::<unnamed>%3965BB26024E
      //## Role: MADInterface::ctor%3965BB260250
      //## begin MADInterface::ctor%3965BB260250.role preserve=no  implementation: AcceleratorModelConstructor { -> 0..1VFHAN}
      AcceleratorModelConstructor* ctor;
      //## end MADInterface::ctor%3965BB260250.role

};

// Class MADInterface 


//## Other Operations (inline)
//## Operation: SetLogFile%962031287
inline void MADInterface::SetLogFile (ostream& os)
{
  //## begin MADInterface::SetLogFile%962031287.body preserve=yes
	log=&os;
  //## end MADInterface::SetLogFile%962031287.body
}

//## Operation: SetLoggingOn%962031288
inline void MADInterface::SetLoggingOn ()
{
  //## begin MADInterface::SetLoggingOn%962031288.body preserve=yes
	logFlag=true;
  //## end MADInterface::SetLoggingOn%962031288.body
}

//## Operation: SetLoggingOff%962031289
inline void MADInterface::SetLoggingOff ()
{
  //## begin MADInterface::SetLoggingOff%962031289.body preserve=yes
	logFlag=false;
  //## end MADInterface::SetLoggingOff%962031289.body
}

//## Operation: HonourMadStructure%962967902
inline void MADInterface::HonourMadStructure (bool flg)
{
  //## begin MADInterface::HonourMadStructure%962967902.body preserve=yes
	honMadStructs=flg; 
  //## end MADInterface::HonourMadStructure%962967902.body
}

//## Operation: ConstructFlatLattice%962967903
inline void MADInterface::ConstructFlatLattice (bool flg)
{
  //## begin MADInterface::ConstructFlatLattice%962967903.body preserve=yes
	flatLattice=flg;
  //## end MADInterface::ConstructFlatLattice%962967903.body
}

//## Operation: ConstructApertures%962967924
inline void MADInterface::ConstructApertures (bool flg)
{
  //## begin MADInterface::ConstructApertures%962967924.body preserve=yes
	incApertures = flg;
  //## end MADInterface::ConstructApertures%962967924.body
}

//## begin module%3ADEDE2E0320.epilog preserve=yes
//## end module%3ADEDE2E0320.epilog


#endif

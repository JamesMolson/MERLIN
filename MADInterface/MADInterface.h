//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%39576D6500C8.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\MADInterface\MADInterface.h
 * last modified 04/12/01 10:41:00
 */
//## end module%39576D6500C8.cm

//## begin module%39576D6500C8.cp preserve=no
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
//## end module%39576D6500C8.cp

//## Module: MADInterface%39576D6500C8; Pseudo Package specification
//## Source file: C:\C++\Merlin\MADInterface\MADInterface.h

#ifndef MADInterface_h
#define MADInterface_h 1

//## begin module%39576D6500C8.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%39576D6500C8.additionalIncludes

//## begin module%39576D6500C8.includes preserve=yes
#include <fstream>
#include <string>
#include <set>
//## end module%39576D6500C8.includes

// AcceleratorModel
#include "AcceleratorModel/AcceleratorModel.h"

class AcceleratorModelConstructor;
class MADKeyMap;

//## begin module%39576D6500C8.additionalDeclarations preserve=yes
using std::ifstream;
using std::ostream;
//## end module%39576D6500C8.additionalDeclarations


//## Class: MADInterface%39576D6500C8
//	Class used to construct a MERLIN model from a MAD optics
//	output listing. The class now automatically  identifies
//	the column parameters, and associates them with the
//	constructed element types. If an element type is defined
//	for which a required parameter is not present in the
//	column headings, the parameter is set to zero and a
//	warning is issued.
//## Category: Merlin::MADInterface%39576D3C0226
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
      //## Operation: MADInterface%39576D8603D4
      //	Constructor taking the name of the MAD optics file, and
      //	the momentum in GeV/c.
      MADInterface (const std::string& madFileName="", double P0=0);


    //## Other Operations (specified)
      //## Operation: ConstructModel%39576D9D0226
      //	Causes the construction of an AcceleratorModel object
      //	based on the MAD optics file.
      AcceleratorModel* ConstructModel ();

      //## Operation: SetLogFile%39577A4903B6
      //	Sets the log file stream to os.
      void SetLogFile (ostream& os);

      //## Operation: SetLoggingOn%395782190122
      //	Turns logging on.
      void SetLoggingOn ();

      //## Operation: SetLoggingOff%395782210244
      //	Turns logging off.
      void SetLoggingOff ();

      //## Operation: HonourMadStructure%3965B8320279
      //	If true, all LINE constructs in the MAD optics output
      //	are constructed in the model. If false, only those
      //	prefixed X_, where X is M, S, or G are constructed.
      void HonourMadStructure (bool flg);

      //## Operation: ConstructFlatLattice%3965B8C0031D
      //	If true, a flat lattice model in constructed, with no
      //	nested frames.
      void ConstructFlatLattice (bool flg);

      //## Operation: ConstructApertures%3965D74002DF
      void ConstructApertures (bool flg);

      //## Operation: IgnoreZeroLengthType%3965E6CE03D5
      //	Components of type madType are ignored during
      //	construction if their length is zero.
      void IgnoreZeroLengthType (const string& madType);

      //## Operation: ScaleForSynchRad%3C076A7D0344
      //	If scaleSR == true, then the magnetic fields of the
      //	magnets are scaled to compensate beam energy losses due
      //	to synchrotron radiation (default = false.) Note that in
      //	this case, the beam energy is the initial energy.
      void ScaleForSynchRad (bool scaleSR);

      //## Operation: TreatTypeAsDrift%3C0C99F103E2
      //	Treats the mad type typestr as a drift.
      void TreatTypeAsDrift (const std::string& typestr);

	  // Functions for constructing a model from several files.
	  // Repeated calls to AppendModel(fname,p) constructs a single
	  // model (beamline) from the respective files. The final
	  // model is returned using GetModel().
	  void AppendModel(const std::string& fname, double pref);
	  AcceleratorModel* GetModel();

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: energy%39576D72010E
      //## begin MADInterface::energy%39576D72010E.attr preserve=no  private: double {UA} 
      double energy;
      //## end MADInterface::energy%39576D72010E.attr

      //## Attribute: ifs%39576D79038E
      //## begin MADInterface::ifs%39576D79038E.attr preserve=no  private: ifstream {UA} 
      ifstream *ifs;
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
      //## begin MADInterface::zeroLengths%3965E74000AE.attr preserve=no  private: std::set<std::string> {UA} 
      std::set<std::string> zeroLengths;
      //## end MADInterface::zeroLengths%3965E74000AE.attr

      //## Attribute: inc_sr%3C076B3F00AE
      //## begin MADInterface::inc_sr%3C076B3F00AE.attr preserve=no  private: bool {UA} 
      bool inc_sr;
      //## end MADInterface::inc_sr%3C076B3F00AE.attr

      //## Attribute: driftTypes%3C0C99C701B1
      //## begin MADInterface::driftTypes%3C0C99C701B1.attr preserve=no  private: std::set<std::string> {UA} 
      std::set<std::string> driftTypes;
      //## end MADInterface::driftTypes%3C0C99C701B1.attr

  private: //## implementation

    //## Other Operations (specified)
      //## Operation: ConstructNewFrame%3965BAAA0119
      void ConstructNewFrame (const string& name);

      //## Operation: EndFrame%3965BAC1020D
      void EndFrame (const string& name);

      //## Operation: ReadComponent%3965BACD01F6
      double ReadComponent ();

	  void Initialise();

    // Data Members for Associations

      //## Association: Merlin::MADInterface::<unnamed>%3965BB26024E
      //## Role: MADInterface::ctor%3965BB260250
      //## begin MADInterface::ctor%3965BB260250.role preserve=no  implementation: AcceleratorModelConstructor { -> 0..1VFHgAN}
      AcceleratorModelConstructor* ctor;
      //## end MADInterface::ctor%3965BB260250.role

      //## Association: Merlin::MADInterface::<unnamed>%3BFA3D2D018B
      //## Role: MADInterface::prmMap%3BFA3D2D03A8
      //## begin MADInterface::prmMap%3BFA3D2D03A8.role preserve=no  implementation: MADKeyMap { -> 0..1VFHgAN}
      MADKeyMap* prmMap;
      //## end MADInterface::prmMap%3BFA3D2D03A8.role

};

// Class MADInterface 


//## Other Operations (inline)
//## Operation: SetLogFile%39577A4903B6
inline void MADInterface::SetLogFile (ostream& os)
{
  //## begin MADInterface::SetLogFile%39577A4903B6.body preserve=yes
	log=&os;
  //## end MADInterface::SetLogFile%39577A4903B6.body
}

//## Operation: SetLoggingOn%395782190122
inline void MADInterface::SetLoggingOn ()
{
  //## begin MADInterface::SetLoggingOn%395782190122.body preserve=yes
	logFlag=true;
  //## end MADInterface::SetLoggingOn%395782190122.body
}

//## Operation: SetLoggingOff%395782210244
inline void MADInterface::SetLoggingOff ()
{
  //## begin MADInterface::SetLoggingOff%395782210244.body preserve=yes
	logFlag=false;
  //## end MADInterface::SetLoggingOff%395782210244.body
}

//## Operation: HonourMadStructure%3965B8320279
inline void MADInterface::HonourMadStructure (bool flg)
{
  //## begin MADInterface::HonourMadStructure%3965B8320279.body preserve=yes
	honMadStructs=flg; 
  //## end MADInterface::HonourMadStructure%3965B8320279.body
}

//## Operation: ConstructFlatLattice%3965B8C0031D
inline void MADInterface::ConstructFlatLattice (bool flg)
{
  //## begin MADInterface::ConstructFlatLattice%3965B8C0031D.body preserve=yes
	flatLattice=flg;
  //## end MADInterface::ConstructFlatLattice%3965B8C0031D.body
}

//## Operation: ConstructApertures%3965D74002DF
inline void MADInterface::ConstructApertures (bool flg)
{
  //## begin MADInterface::ConstructApertures%3965D74002DF.body preserve=yes
	incApertures = flg;
  //## end MADInterface::ConstructApertures%3965D74002DF.body
}

//## Operation: ScaleForSynchRad%3C076A7D0344
inline void MADInterface::ScaleForSynchRad (bool scaleSR)
{
  //## begin MADInterface::ScaleForSynchRad%3C076A7D0344.body preserve=yes
	inc_sr = scaleSR;
  //## end MADInterface::ScaleForSynchRad%3C076A7D0344.body
}

//## begin module%39576D6500C8.epilog preserve=yes
//## end module%39576D6500C8.epilog


#endif

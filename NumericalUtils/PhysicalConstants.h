//## begin module.cm preserve=no
// Specification for PhysicalConstants
// last modified: 01/30/98 at 15:26:26
// This file is part of the MERLIN class library
// version 1.0beta
// ---------------------------------------------
//## end module.cm

//## begin module.cp preserve=no
// (c) 1997 Nicholas J. Walker (DESY) -- All Rights Reserved --
// ------------------------------------------------------------
//## end module.cp

//## Module: PhysicalConstants; Pseudo Package specification
//## Subsystem: NumericalUtils
//## Source file: c:\C++\Merlin\NumericalUtils\PhysicalConstants.h

#ifndef PhysicalConstants_h
#define PhysicalConstants_h 1

//## begin module.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include "NumericalUtils/PhysicalUnits.h"
#include "NumericalUtils/NumericalConstants.h"
//## end module.includes

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: PhysicalConstants; Class Utility
//## Category: NumericalUtils; Global
//## Subsystem: NumericalUtils
//## Persistence: Transient
//## Cardinality/Multiplicity: n

namespace PhysicalConstants 
{
	// Data Members for Class Attributes
	
	//## Attribute: SpeedOfLight
	//## begin PhysicalConstants::SpeedOfLight.attr preserve=no  public: double {UA} 
	extern const double SpeedOfLight;
	//## end PhysicalConstants::SpeedOfLight.attr
	
	//## Attribute: ElectronMass
	//## begin PhysicalConstants::ElectronMass.attr preserve=no  public: double {UA} 
	extern const double ElectronMass;
	//## end PhysicalConstants::ElectronMass.attr
	
	//## Attribute: ProtonMass
	//## begin PhysicalConstants::ProtonMass.attr preserve=no  public: double {UA} 
	extern const double ProtonMass;
	//## end PhysicalConstants::ProtonMass.attr
	
	//## Attribute: PlankConstant
	//## begin PhysicalConstants::PlankConstant.attr preserve=no  public: double {UA} 
	extern const double PlankConstant;
	//## end PhysicalConstants::PlankConstant.attr
	
	//## Attribute: ElectronCharge
	//## begin PhysicalConstants::ElectronCharge.attr preserve=no  public: double {UA} 
	extern const double ElectronCharge;
	//## end PhysicalConstants::ElectronCharge.attr
	
	//## Attribute: ElectronMassMeV
	//## begin PhysicalConstants::ElectronMassMeV.attr preserve=no  public: double {UA} 
	extern const double ElectronMassMeV;
	//## end PhysicalConstants::ElectronMassMeV.attr
	
	//## Attribute: ProtonMassMeV
	//## begin PhysicalConstants::ProtonMassMeV.attr preserve=no  public: double {UA} 
	extern const double ProtonMassMeV;
	//## end PhysicalConstants::ProtonMassMeV.attr
};

// Class Utility PhysicalConstants 



//## begin module.epilog preserve=yes
//## end module.epilog


#endif

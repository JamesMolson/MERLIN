//## begin module.cm preserve=no
// Body for PhysicalConstants
// last modified: 01/30/98 at 15:26:27
// This file is part of the MERLIN class library
// version 1.0beta
// ---------------------------------------------
//## end module.cm

//## begin module.cp preserve=no
// (c) 1997 Nicholas J. Walker (DESY) -- All Rights Reserved --
// ------------------------------------------------------------
//## end module.cp

//## Module: PhysicalConstants; Pseudo Package body
//## Subsystem: NumericalUtils
//## Source file: c:\C++\Merlin\NumericalUtils\PhysicalConstants.cpp

//## begin module.includes preserve=yes
#include "NumericalUtils/PhysicalUnits.h"
//## end module.includes

// PhysicalConstants
#include "NumericalUtils/PhysicalConstants.h"
//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class Utility PhysicalConstants 
namespace PhysicalConstants {
	using namespace PhysicalUnits;

	//## begin SpeedOfLight.attr preserve=no  public: double {UA} 
	const double SpeedOfLight = 2.997925e+08*meter/second;
	//## end SpeedOfLight.attr
	
	//## begin ElectronMass.attr preserve=no  public: double {UA} 
	const double ElectronMass = 9.10956e-31; // kilogram
	//## end ElectronMass.attr
	
	//## begin ProtonMass.attr preserve=no  public: double {UA} 
	const double ProtonMass = 1.67261e-27; // kilogram
	//## end ProtonMass.attr
	
	//## begin PlankConstant.attr preserve=no  public: double {UA} 
	const double PlankConstant = 6.62620e-34; // Joule second
	//## end PlankConstant.attr
	
	//## begin ElectronCharge.attr preserve=no  public: double {UA} 
	const double ElectronCharge = 1.60219e-19; // Coulomb
	//## end ElectronCharge.attr
	
	//## begin ElectronMassMeV.attr preserve=no  public: double {UA} 
	const double ElectronMassMeV = 0.511005; // MeV
	//## end ElectronMassMeV.attr
	
	//## begin ProtonMassMeV.attr preserve=no  public: double {UA} 
	const double ProtonMassMeV = 938.2578; // MeV
	//## end ProtonMassMeV.attr
};

//## begin module.epilog preserve=yes
//## end module.epilog

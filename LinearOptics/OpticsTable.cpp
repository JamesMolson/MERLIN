//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%399BE04101FE.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\LinearOptics\OpticsTable.cpp
 * last modified 08/31/00 10:36:23 AM
 */
//## end module%399BE04101FE.cm

//## begin module%399BE04101FE.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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
//## end module%399BE04101FE.cp

//## Module: OpticsTable%399BE04101FE; Package body
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Source file: C:\C++\Merlin\LinearOptics\OpticsTable.cpp

//## begin module%399BE04101FE.includes preserve=yes
#include "merlin_config.h"
#include "BasicTransport/NormalTransform.h"
#include "NumericalUtils/NumericalConstants.h"
#include "NumericalUtils/PhysicalConstants.h"
#include <cmath>
//## end module%399BE04101FE.includes

// MatrixMaps
#include "BasicTransport/MatrixMaps.h"
// PSTypes
#include "BeamModel/PSTypes.h"
// LinearMatrixTracker
#include "LinearOptics/LinearMatrixTracker.h"
// OpticsTable
#include "LinearOptics/OpticsTable.h"


//## begin module%399BE04101FE.additionalDeclarations preserve=yes
using namespace std;
using namespace PhysicalConstants;
//## end module%399BE04101FE.additionalDeclarations


// Class OpticsTable::ColumnSpec 



//## Operation: ColumnSpec%399BEFA602A5
OpticsTable::ColumnSpec::ColumnSpec (Key aKey, const OPFormat& aFmt)
  //## begin OpticsTable::ColumnSpec::ColumnSpec%399BEFA602A5.initialization preserve=yes
  : cKey(aKey),fmt(aFmt)
  //## end OpticsTable::ColumnSpec::ColumnSpec%399BEFA602A5.initialization
{
  //## begin OpticsTable::ColumnSpec::ColumnSpec%399BEFA602A5.body preserve=yes
  //## end OpticsTable::ColumnSpec::ColumnSpec%399BEFA602A5.body
}


// Class OpticsTable::OutputSpec 



//## Operation: OutputSpec%39AA8BC5015F
OpticsTable::OutputSpec::OutputSpec ()
  //## begin OpticsTable::OutputSpec::OutputSpec%39AA8BC5015F.initialization preserve=yes
  : id("*"),loc(atExit)
  //## end OpticsTable::OutputSpec::OutputSpec%39AA8BC5015F.initialization
{
  //## begin OpticsTable::OutputSpec::OutputSpec%39AA8BC5015F.body preserve=yes
  //## end OpticsTable::OutputSpec::OutputSpec%39AA8BC5015F.body
}

//## Operation: OutputSpec%39AA8BCB010E
OpticsTable::OutputSpec::OutputSpec (const string& anID, Location aPos)
  //## begin OpticsTable::OutputSpec::OutputSpec%39AA8BCB010E.initialization preserve=yes
  : id(anID),loc(aPos)
  //## end OpticsTable::OutputSpec::OutputSpec%39AA8BCB010E.initialization
{
  //## begin OpticsTable::OutputSpec::OutputSpec%39AA8BCB010E.body preserve=yes
  //## end OpticsTable::OutputSpec::OutputSpec%39AA8BCB010E.body
}


// Class OpticsTable::Twiss 




// Class OpticsTable 








//## Operation: OpticsTable%399BE9000276
OpticsTable::OpticsTable (const AcceleratorModel::Beamline bl, const BeamData& ibeam, ostream& anOs)
  //## begin OpticsTable::OpticsTable%399BE9000276.initialization preserve=yes
  : defaultFmtSpec(),iBeam(ibeam),os(&anOs),theBeamline(bl),theColumns()
  //## end OpticsTable::OpticsTable%399BE9000276.initialization
{
  //## begin OpticsTable::OpticsTable%399BE9000276.body preserve=yes
	Init();
  //## end OpticsTable::OpticsTable%399BE9000276.body
}

//## Operation: OpticsTable%399BE92B01D7
OpticsTable::OpticsTable ()
  //## begin OpticsTable::OpticsTable%399BE92B01D7.initialization preserve=yes
  : defaultFmtSpec(),iBeam(),os(0),theBeamline(),theColumns()
  //## end OpticsTable::OpticsTable%399BE92B01D7.initialization
{
  //## begin OpticsTable::OpticsTable%399BE92B01D7.body preserve=yes
	Init();
  //## end OpticsTable::OpticsTable%399BE92B01D7.body
}



//## Other Operations (implementation)
//## Operation: SetBeamline%399BE257006B
void OpticsTable::SetBeamline (const AcceleratorModel::Beamline& bl)
{
  //## begin OpticsTable::SetBeamline%399BE257006B.body preserve=yes
	theBeamline=bl;
  //## end OpticsTable::SetBeamline%399BE257006B.body
}

//## Operation: SetInitialConditions%399BE2720223
void OpticsTable::SetInitialConditions (const BeamData& beam0)
{
  //## begin OpticsTable::SetInitialConditions%399BE2720223.body preserve=yes
	iBeam = beam0;
  //## end OpticsTable::SetInitialConditions%399BE2720223.body
}

//## Operation: AddOutputSpecifier%399BE29503D2
void OpticsTable::AddOutputSpecifier (const string& pat, OpticsTable::Location pos)
{
  //## begin OpticsTable::AddOutputSpecifier%399BE29503D2.body preserve=yes
	itsOutputSpecs.insert(OutputSpec(pat,pos));
  //## end OpticsTable::AddOutputSpecifier%399BE29503D2.body
}

//## Operation: ClearOutputSpecifiers%399BE86701AE
void OpticsTable::ClearOutputSpecifiers ()
{
  //## begin OpticsTable::ClearOutputSpecifiers%399BE86701AE.body preserve=yes
	itsOutputSpecs.clear();
  //## end OpticsTable::ClearOutputSpecifiers%399BE86701AE.body
}

//## Operation: ClearColumns%399BE3600211
void OpticsTable::ClearColumns ()
{
  //## begin OpticsTable::ClearColumns%399BE3600211.body preserve=yes
	theColumns.clear();
  //## end OpticsTable::ClearColumns%399BE3600211.body
}

//## Operation: AddColumn%399BE3BF0177
void OpticsTable::AddColumn (OpticsTable::Key key)
{
  //## begin OpticsTable::AddColumn%399BE3BF0177.body preserve=yes
	theColumns.push_back(ColumnSpec(key,defaultFmtSpec));
  //## end OpticsTable::AddColumn%399BE3BF0177.body
}

//## Operation: AddColumn%399BE4A8003C
void OpticsTable::AddColumn (OpticsTable::Key key, const OPFormat& fmtSpec)
{
  //## begin OpticsTable::AddColumn%399BE4A8003C.body preserve=yes
	theColumns.push_back(ColumnSpec(key,fmtSpec));
  //## end OpticsTable::AddColumn%399BE4A8003C.body
}

//## Operation: SetStream%399BE5FB0347
void OpticsTable::SetStream (ostream& anOs)
{
  //## begin OpticsTable::SetStream%399BE5FB0347.body preserve=yes
	os = &anOs;
  //## end OpticsTable::SetStream%399BE5FB0347.body
}

//## Operation: Calculate%399BE61202BD
void OpticsTable::Calculate ()
{
  //## begin OpticsTable::Calculate%399BE61202BD.body preserve=yes
	PSmoments S;
	LinearMatrixTracker tracker(iBeam.p0,iBeam.charge);
	lastTwiss = iBeam;

	double z=0;

	BeamDataToSigmaMtrx(iBeam,S);
	
	OutputRow("MARKER.BEGIN",0,0);

	for(AcceleratorModel::BeamlineIterator ci = theBeamline.begin(); ci!=theBeamline.end(); ci++) {

		AcceleratorComponent& cmpnt = (**ci).GetComponent();
		
		cmpnt.PrepareTracker(tracker);
		tracker.ResetR2();

		double l = cmpnt.GetLength();
		const string label = cmpnt.GetQualifiedName();

		Location loc = GetOutputSpec(label);

		if(loc==atEntrance) // output straight away
			OutputRow(label,z,l);

		if(loc==atCentre)
			tracker.TrackStep(l/2);
		else
			tracker.Track();

		const RMtrx& R = tracker.GetCurrentR2();
		UpdateTwiss(R.Apply(S),R);
		z+= loc==atCentre ? l/2 : l;

		if(loc==atCentre || loc==atExit) // takes care of both atCentre and atExit
			OutputRow(label,z,l);

		if(loc==atCentre) { // if atCentre, need to track the second half
			tracker.ResetR2();
			tracker.TrackStep(l/2);
			const RMtrx& R = tracker.GetCurrentR2();
			UpdateTwiss(R.Apply(S),R);
			z+=l/2;
		}
	}
  //## end OpticsTable::Calculate%399BE61202BD.body
}

//## Operation: SetDefaultColumns%399BE62200A4
void OpticsTable::SetDefaultColumns ()
{
  //## begin OpticsTable::SetDefaultColumns%399BE62200A4.body preserve=yes
	// TYPE Z BX AX PHIX BY AY PHIY DX DXP
	theColumns.clear();
	theColumns.push_back(ColumnSpec(L,defaultFmtSpec));
	theColumns.push_back(ColumnSpec(Z,defaultFmtSpec));
	theColumns.push_back(ColumnSpec(BX,defaultFmtSpec));
	theColumns.push_back(ColumnSpec(AX,defaultFmtSpec));
	theColumns.push_back(ColumnSpec(PHIX,defaultFmtSpec));
	theColumns.push_back(ColumnSpec(BY,defaultFmtSpec));
	theColumns.push_back(ColumnSpec(AY,defaultFmtSpec));
	theColumns.push_back(ColumnSpec(PHIY,defaultFmtSpec));
	theColumns.push_back(ColumnSpec(DX,defaultFmtSpec));
	theColumns.push_back(ColumnSpec(DXP,defaultFmtSpec));
  //## end OpticsTable::SetDefaultColumns%399BE62200A4.body
}

//## Operation: SetDefaultFormatSpecifier%399BE99E009C
void OpticsTable::SetDefaultFormatSpecifier (const OPFormat& fmtSpec)
{
  //## begin OpticsTable::SetDefaultFormatSpecifier%399BE99E009C.body preserve=yes
	defaultFmtSpec = fmtSpec;
  //## end OpticsTable::SetDefaultFormatSpecifier%399BE99E009C.body
}

//## Operation: GetOutputSpec%399BEEC10115
OpticsTable::Location OpticsTable::GetOutputSpec (const string& id)
{
  //## begin OpticsTable::GetOutputSpec%399BEEC10115.body preserve=yes
	if(itsOutputSpecs.empty())
		return atExit;
	set<OutputSpec>::const_iterator opi = itsOutputSpecs.begin(); 
	for(;opi!=itsOutputSpecs.end() && !(*opi).id.Match(id); ++opi){};
	
	return opi!=itsOutputSpecs.end() ? (*opi).loc : noOutput;
  //## end OpticsTable::GetOutputSpec%399BEEC10115.body
}

//## Operation: UpdateTwiss%39ABB343006F
void OpticsTable::UpdateTwiss (const PSmoments& S0, const RMtrx& R)
{
  //## begin OpticsTable::UpdateTwiss%39ABB343006F.body preserve=yes
	PSmoments S=S0;

	//S.printFormatted(cout);
	//{char c; cin.get(c);}

	// Correct for dispersion, if dp/p != 0
	Twiss t;

	if(S(5,5)!=0) {
		t.Dx = S(0,5)/S(5,5);
		t.Dxp = S(1,5)/S(5,5);
		t.Dy = S(2,5)/S(5,5);
		t.Dyp = S(3,5)/S(5,5);
	
		RMtrx Rd(DispersionMatrix(-t.Dx,-t.Dxp,-t.Dy,-t.Dyp));
		Rd.Apply(S);
	}

	// Note that no attempt is made to de-couple the bunch.
	// The emittances calculated are "projected" emittances
	// in the presence of x-y coupling

	t.emit_x = sqrt(S(0,0)*S(1,1)-pow(S(0,1),2));
	t.emit_y = sqrt(S(2,2)*S(3,3)-pow(S(2,3),2));
	t.beta_x = S(0,0)/t.emit_x;
	t.beta_y = S(2,2)/t.emit_y;
	t.alpha_x = -S(0,1)/t.emit_x;
	t.alpha_y = -S(2,3)/t.emit_y;

	// phase advances
	double dphix = atan(R(1,2)/(R(1,1)*lastTwiss.beta_x-R(1,2)*lastTwiss.alpha_x));
	double dphiy = atan(R(3,4)/(R(3,3)*lastTwiss.beta_y-R(3,4)*lastTwiss.alpha_y));
	
	t.phi_x = lastTwiss.phi_x + dphix;
	t.phi_y = lastTwiss.phi_y + dphiy;

	if(dphix<0)
		t.phi_x+=pi;
	if(dphiy<0)
		t.phi_y+=pi;

	lastTwiss = t;
  //## end OpticsTable::UpdateTwiss%39ABB343006F.body
}

//## Operation: OutputRow%39AD2A4900E6
void OpticsTable::OutputRow (const string& label, double z, double l)
{
  //## begin OpticsTable::OutputRow%39AD2A4900E6.body preserve=yes
	string::size_type n = label.find('.');
	const string type = label.substr(0,n);
	const string name = label.substr(n+1);
	
	(*os)<<std::setw(16)<<left<<name.c_str();
	(*os)<<std::setw(16)<<left<<type.c_str();

	for(list<ColumnSpec>::const_iterator i=theColumns.begin(); i!=theColumns.end(); i++) {
		double value;
		switch(i->cKey) {
		case BX:	value = lastTwiss.beta_x; break;
		case BY:	value = lastTwiss.beta_y; break;
		case AX:	value = lastTwiss.alpha_x; break;
		case AY:	value = lastTwiss.alpha_y; break;
		case PHIX:	value = lastTwiss.phi_x; break;
		case PHIY:	value = lastTwiss.phi_y; break;
		case DX:	value = lastTwiss.Dx; break;
		case DXP:	value = lastTwiss.Dxp; break;
		case DY:	value = lastTwiss.Dy; break;
		case DYP:	value = lastTwiss.Dyp; break;
		case Z:		value = z; break;
		case L:		value = l; break;
		case EX:	value = lastTwiss.emit_x; break;
		case EY:	value = lastTwiss.emit_y; break;
		case GEX:	value = lastTwiss.emit_x*iBeam.p0/ElectronMassMeV; break;
		case GEY:	value = lastTwiss.emit_y*iBeam.p0/ElectronMassMeV; break;
		}

		(*os)<<(*i).fmt(value);
	}
	(*os)<<endl;
  //## end OpticsTable::OutputRow%39AD2A4900E6.body
}

//## Operation: Init%39AE13B70351
void OpticsTable::Init ()
{
  //## begin OpticsTable::Init%39AE13B70351.body preserve=yes
	defaultFmtSpec.scientific();
	defaultFmtSpec.width(16);
	defaultFmtSpec.right();
	SetDefaultColumns();

	// Set the emittances to 1 if they are not already defined
	if(iBeam.emit_x==0)
		iBeam.emit_x=1.0;
	if(iBeam.emit_y==0)
		iBeam.emit_y=1.0;
//	if(iBeam.sig_dp==0)
//		iBeam.sig_dp=1.0;
	if(iBeam.sig_z==0)
		iBeam.sig_z=1.0;
  //## end OpticsTable::Init%39AE13B70351.body
}

//## begin module%399BE04101FE.epilog preserve=yes
//## end module%399BE04101FE.epilog

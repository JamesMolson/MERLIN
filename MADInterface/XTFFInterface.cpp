/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2002)
 * 
 * file Merlin/MADInterface/XTFFInterface.cpp
 * last modified 01/23/02 10.35
 */

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

#include "MADInterface/XTFFInterface.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>

#include "AcceleratorModel/Components.h"
#include "AcceleratorModel/Construction/AcceleratorModelConstructor.h"

#include "NumericalUtils/PhysicalConstants.h"

using namespace PhysicalConstants;
using namespace PhysicalUnits;
using namespace std;

// data structure for XTFF data
struct XTFFInterface::XTFF_Data {
	std::string keywrd;
	std::string label;
	std::string type;
	std::string fdn;
	double realdat[11];		
	double operator[](size_t n) const { return realdat[n];}
};


namespace {
	
	using XTFFInterface::XTFF_Data;
	
	double energy;      // current energy
	double beamload;	// energy loss due to beamloading

	double z_total; // current total length
	double Qt;      // charge for beamloading

	// skip n input lines
	void SkipLines(istream& is, int n)
	{
		string dummy;
		while(is && n--)
			getline(is,dummy);
	}
	
	// return real value in columnds c1-c2
	double RealValue(const string& dat, int c1, int c2)
	{
		return atof(dat.substr(c1-1,c2-c1+1).c_str());
	}
	
	// return string value in cols c1-c2
	string StringValue(const string& dat, int c1, int c2)
	{
		string rv = dat.substr(c1-1,c2-c1+1);
		int n = rv.find_first_of(' ');
		return n==string::npos ? rv : rv.substr(0,n);
	}
	
	
	// Parse single element record 
	void ParseXTFF(istream& is, XTFF_Data& data)
	{
		string ipline;
		
		// first line
		getline(is,ipline);
		data.keywrd = StringValue(ipline,1,4);
		data.label = StringValue(ipline,5,20);
		data.type = StringValue(ipline,98,113);
		
		data.realdat[0] = RealValue(ipline,21,32);
		data.realdat[1] = RealValue(ipline,33,48);
		data.realdat[2] = RealValue(ipline,49,64);
		data.realdat[3] = RealValue(ipline,65,80);
		data.realdat[4] = RealValue(ipline,81,96);
		data.realdat[5] = RealValue(ipline,115,130);
		
		// second line
		getline(is,ipline);
		
		data.realdat[6] = RealValue(ipline,1,16);
		data.realdat[7] = RealValue(ipline,17,32);
		data.realdat[8] = RealValue(ipline,33,48);
		data.realdat[9] = RealValue(ipline,49,64);
		data.realdat[10] = RealValue(ipline,65,80);
		
		if(ipline.length()>82)
			data.fdn = StringValue(ipline,82,105);
	}
	
	// parameter keyword array locations
	
#define L      0
#define ANGLE  1
#define K1     2
#define K2     3
#define K3     7
#define ENERGY 5
#define APER   4
#define HGAP   4
#define TILT   6
#define FREQ   7
#define VOLT   8
#define LAG    9
#define ELOSS 10
#define KS     7
#define E1     7
#define E2     8
#define H1     9
#define H2    10
#define HKICK  6
#define VKICK  7
	
	
	Drift* ConstructDrift(const XTFF_Data& data)
	{
		return new Drift(data.label,data[L]);
	}
	
	SectorBend* ConstructSectorBend(const XTFF_Data& data)
	{
		double len   = data[L];
		double angle = data[ANGLE];
		double k1    = data[K1];
		double k2    = data[K2];
		double e1    = data[E1];
		double e2    = data[E2];
		double tilt  = data[TILT];
		double brho  = energy/eV/SpeedOfLight;
		double hg    = data[HGAP];
		double h = angle/len;
		
		SectorBend* bend = new SectorBend(data.label,len,h,brho*h);
		
		if(k1!=0)  // mixed function dipole
			bend->SetB1(brho*k1);
		
		if(tilt!=0)
			(*bend).GetGeometry().SetTilt(tilt);
		
		// add pole-face rotation information
		SectorBend::PoleFace* entrPF = (e1!=0)? new SectorBend::PoleFace(e1,0,hg) : 0;
		SectorBend::PoleFace* exitPF = (e2!=0)? new SectorBend::PoleFace(e2,0,hg) : 0;
		bend->SetPoleFaceInfo(entrPF,exitPF);
		
		return bend;
	}
	
	Quadrupole* ConstructQuadrupole(const XTFF_Data& data)
	{
		double len   = data[L];
		double k1    = data[K1];
		double tilt  = data[TILT];
		assert(tilt==0);
		double brho  = energy/eV/SpeedOfLight;
		return new Quadrupole(data.label,len,brho*k1);
	}
	
	SkewQuadrupole* ConstructSkewQuadrupole(const XTFF_Data& data)
	{
		double len   = data[L];
		double k1    = data[K1];
		double tilt  = data[TILT];
		double brho  = energy/eV/SpeedOfLight;
		return new SkewQuadrupole(data.label,len,brho*k1);
	}
	
	Sextupole* ConstructSextupole(const XTFF_Data& data)
	{
		double len   = data[L];
		double k2    = data[K2];
		double tilt  = data[TILT];
		assert(tilt==0);
		double brho  = energy/eV/SpeedOfLight;
		return new Sextupole(data.label,len,brho*k2);
	}
	
	SkewSextupole* ConstructSkewSextupole(const XTFF_Data& data)
	{
		double len   = data[L];
		double k2    = data[K2];
		double tilt  = data[TILT];
		double brho  = energy/eV/SpeedOfLight;
		return new SkewSextupole(data.label,len,brho*k2);
	}
	
	Octupole* ConstructOctupole(const XTFF_Data& data)
	{
		double len   = data[L];
		double k3    = data[K3];
		double tilt  = data[TILT];
		assert(tilt==0);
		double brho  = energy/eV/SpeedOfLight;
		return new Octupole(data.label,len,brho*k3);
	}
	
	XCor* ConstructXCor(const XTFF_Data& data)
	{
		return new XCor(data.label,data[L]);
	}
	
	YCor* ConstructYCor(const XTFF_Data& data)
	{
		return new YCor(data.label,data[L]);
	}
	
	TWRFStructure* ConstructCavity(const XTFF_Data& data)
	{
		double len = data[L];
		double volt = data[VOLT]*MV;
		double phase = twoPi*data[LAG];
		double freq = data[FREQ]*MHz;
		double eloss = data[ELOSS]*Volt;
		
		// update energy
		double bloading = eloss*Qt;
		double dE = volt*cos(phase);
/*
		using std::setw;
		cout<<setw(12)<<data.label.c_str();
		cout<<setw(10)<<fixed<<setprecision(3)<<dE/MV;
		cout<<setw(10)<<fixed<<setprecision(3)<<bloading/MV<<endl;
*/
		energy += (dE-bloading)/GeV;
		beamload += bloading/GeV;
		return new TWRFStructure(data.label,len,freq,volt/len,phase);
	}
	
	BPM* ConstructBPM(const XTFF_Data& data)
	{
		return new BPM(data.label,data[L]);
	}
	
	RMSProfileMonitor* ConstructProfileMonitor(const XTFF_Data& data)
	{
		return new RMSProfileMonitor(data.label,data[L]);
	}
	
	Solenoid* ConstructSolenoid(const XTFF_Data& data)
	{
		double brho = energy/eV/SpeedOfLight;
		return new Solenoid(data.label,data[L],brho*data[KS]);
	}

	Marker* ConstructMarker(const XTFF_Data& data)
	{
		return new Marker(data.label);
	}
	
#define SKQ_TILT 0.78539816
#define SKS_TILT 0.52359878
	
	inline bool is_skewquad(double tilt) { return fabs(tilt/SKQ_TILT-1.0)<1e-03;}
	inline bool is_skewsext(double tilt) { return fabs(tilt/SKS_TILT-1.0)<1e-03;}
	
	
#define TYPEIS(kw) (dat.keywrd == #kw)
	
}; // end namespace

void XTFFInterface::ConstructComponent(XTFF_Data& dat)
{
	if(TYPEIS(HMON)||TYPEIS(VMON))
		dat.keywrd = "MONI";
//	else if(TYPEIS(MARK))
//		dat.keywrd = "DRIF";

	AcceleratorComponent* c;

	if(dat.keywrd=="DRIF")
		c = mc->AppendComponent(ConstructDrift(dat));
	else if(dat.keywrd=="QUAD") {
		if(is_skewquad(dat[TILT]))
			c = mc->AppendComponent(ConstructSkewQuadrupole(dat));
		else
			c = mc->AppendComponent(ConstructQuadrupole(dat));
	}
	else if(dat.keywrd=="SBEN")
		c = mc->AppendComponent(ConstructSectorBend(dat));
	else if(dat.keywrd=="SEXT") {
		if(is_skewsext(dat[TILT]))
			c = mc->AppendComponent(ConstructSkewSextupole(dat));
		else
			c = mc->AppendComponent(ConstructSextupole(dat));
	}
	else if(dat.keywrd=="OCTU")
		c = mc->AppendComponent(ConstructOctupole(dat));
	else if(dat.keywrd=="LCAV")
		c = mc->AppendComponent(ConstructCavity(dat));
	else if(dat.keywrd=="SOLE")
		c = mc->AppendComponent(ConstructSolenoid(dat));
	else if(dat.keywrd=="HKIC")
		c = mc->AppendComponent(ConstructXCor(dat));
	else if(dat.keywrd=="VKIC")
		c = mc->AppendComponent(ConstructYCor(dat));
	else if(dat.keywrd=="MONI")
		c = mc->AppendComponent(ConstructBPM(dat));
	else if(dat.keywrd=="WIRE")
		c = mc->AppendComponent(ConstructProfileMonitor(dat));
	else if(dat.keywrd=="MARK")
		c = mc->AppendComponent(ConstructMarker(dat));
	else {
		cerr<<"WARNING: treating "<<dat.keywrd<<" as DRIFT"<<endl;
		c = mc->AppendComponent(ConstructDrift(dat));
	}

	z_total += c->GetLength();
	if(logos) {
		(*logos)<<setw(10)<<left<<(*c).GetName().c_str();
		(*logos)<<setw(16)<<left<<(*c).GetType().c_str();
		(*logos)<<setw(10)<<right<<fixed<<setprecision(3)<<z_total;
		(*logos)<<setw(10)<<right<<fixed<<setprecision(3)<<energy;
		(*logos)<<setw(10)<<right<<fixed<<setprecision(3)<<beamload;
		(*logos)<<setw(10)<<right<<fixed<<setprecision(3)<<dat[ENERGY];
		(*logos)<<endl;
	}
}

XTFFInterface::XTFFInterface(const string& fname, double Nb, ostream* logstream)
: ifs(fname.c_str()),mc(0),beam0(0),nb(Nb),logos(logstream)
{
	if(!ifs) {
		cerr<<"Error opening input file "<<fname<<endl;
		exit(1);
	}
}

XTFFInterface::~XTFFInterface()
{
	if(mc!=0) delete mc;
	if(beam0!=0) delete beam0;
}

pair<AcceleratorModel*,BeamData*> XTFFInterface::Parse()
{
	if(mc!=0)
		delete mc;
	
	mc = new AcceleratorModelConstructor();	
	
	if(beam0!=0)
		delete beam0;

	beam0 = new BeamData();

	int nelm = ParseHeader();
	
	if(logos)
		(*logos)<<"Initial beam energy: "<<energy<<" GeV"<<endl;

	mc->NewModel();
	z_total=0;
	beamload=0;

	while(ifs && nelm--) {
		XTFF_Data dat;
		ParseXTFF(ifs,dat);
		ConstructComponent(dat);
		SkipLines(ifs,3);
	}
	
	if(logos) {
		(*logos)<<endl;
		mc->ReportStatistics(*logos);
		(*logos)<<"\nFinal ";
		if(Qt!=0)
			(*logos)<<"(loaded) ";
		(*logos)<<"beam energy: "<<energy<<" GeV"<<endl;
	}
	
	BeamData* beam = beam0;
	beam0=0;

	return make_pair(mc->GetModel(),beam);
}


int XTFFInterface::ParseHeader()
{
	string ipline;

	// extract number of elements from first line
	getline(ifs,ipline);
	int n = RealValue(ipline,57,65);

	// Skip next header line
	getline(ifs,ipline);

	XTFF_Data dat;
	ParseXTFF(ifs,dat); // initial element
	energy = beam0->p0 = dat[ENERGY];
	beam0->charge = nb;
	Qt = (beam0->charge)*ElectronCharge;

	// Now extract initial beam conditions from
	// next three records

	double dummy; // used for mux,muy

#define _RB(v) ifs>>(beam0->##v)

	_RB(alpha_x);
	_RB(beta_x);
	ifs>>dummy; // mux
	_RB(Dx);
	_RB(Dxp);

	_RB(alpha_y);
	_RB(beta_y);
	ifs>>dummy; // muy
	_RB(Dy);
	_RB(Dyp);

	_RB(x0);
	_RB(xp0);
	_RB(y0);
	_RB(yp0);

	// remove remainder of this line (suml)
	getline(ifs,ipline);
	
	return n-1;
}

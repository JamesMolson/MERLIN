//## begin module%3ADEDE3600A0.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\MADInterface\MADInterface.cpp
 * last modified 19/04/01 14:50:33
 */
//## end module%3ADEDE3600A0.cm

//## begin module%3ADEDE3600A0.cp preserve=no
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
//## end module%3ADEDE3600A0.cp

//## Module: MADInterface%3ADEDE3600A0; Package body
//## Subsystem: Merlin::MADInterface%3ADEDE110316
//## Source file: D:\dev\Merlin\MADInterface\MADInterface.cpp

//## begin module%3ADEDE3600A0.includes preserve=yes
#include <cstdlib>
#include "AcceleratorModel/Components.h"
#include "IO/MerlinIO.h"
//## end module%3ADEDE3600A0.includes

// MagnetMover
#include "AcceleratorModel/Supports/MagnetMover.h"
// SupportStructure
#include "AcceleratorModel/Supports/SupportStructure.h"
// SequenceFrame
#include "AcceleratorModel/Frames/SequenceFrame.h"
// AcceleratorModelConstructor
#include "AcceleratorModel/Construction/AcceleratorModelConstructor.h"
// SimpleApertures
#include "AcceleratorModel/Apertures/SimpleApertures.h"
// MADInterface
#include "MADInterface/MADInterface.h"
// PhysicalConstants
#include "NumericalUtils/PhysicalConstants.h"


//## begin module%3ADEDE3600A0.declarations preserve=no
//## end module%3ADEDE3600A0.declarations

//## begin module%3ADEDE3600A0.additionalDeclarations preserve=yes
using namespace std;
using namespace PhysicalConstants;
using namespace PhysicalUnits;

namespace {

	// stack used to match MAD LINE pairs
	// Note: we need this because we no longer preserve the complete MAD beamline
	// structure.
	stack<string> frameStack;

	// utility routines for reading in MAD optics file
	
	void Log(const string& tag, int depth, ostream& os)
	{
		static const char* tab = "----|";
		while(depth--) os<<tab;
		os<<' '<<tag<<endl;
	}

	void StripHeader(istream& is)
	{
		// Need to read the first 13 lines from the optics file
		char buffer[256];
		for(int i=0; i<13; i++)
			is.getline(buffer,256);
	}

	inline string StripQuotes(const string& text)
	{
		return text.substr(1,text.length()-2);
	}

	Aperture* ConstructAperture(const string& apstr)
	{
		Aperture* ap;
		double w,h,d;
		string::size_type n;

		switch(apstr[0]) {
		case 'D':
			d = atof(apstr.substr(1).c_str())*millimeter;
			ap = new CircularAperture(d/2);
			break;
		case 'X':
			n = apstr.find_first_of('Y',1);
			assert(n!=string::npos);
			w = atof(apstr.substr(1,n-1).c_str())*millimeter;
			h = atof(apstr.substr(n+1).c_str())*millimeter;
			ap = new RectangularAperture(w,h);
			break;
		case '~':
			ap = 0;
			break;
		default:
			MERLIN_ERR<<"ERROR: bad aperture definition: "<<apstr<<endl;
			abort();
		};

		return ap;
	}
};
//## end module%3ADEDE3600A0.additionalDeclarations


// Class MADInterface 










//## Operation: MADInterface%962031285
MADInterface::MADInterface (const std::string& madFileName, double P0)
  //## begin MADInterface::MADInterface%962031285.initialization preserve=yes
  : brho(P0/eV/SpeedOfLight),ifs(madFileName.c_str()),log(MerlinIO::std_out),
  logFlag(false),flatLattice(false),honMadStructs(false),incApertures(false)
  //## end MADInterface::MADInterface%962031285.initialization
{
  //## begin MADInterface::MADInterface%962031285.body preserve=yes
	if(!ifs) {
		MERLIN_ERR<<"ERROR openning file "<<madFileName<<endl;
		abort();
	}
  //## end MADInterface::MADInterface%962031285.body
}



//## Other Operations (implementation)
//## Operation: ConstructModel%962031286
AcceleratorModel* MADInterface::ConstructModel ()
{
  //## begin MADInterface::ConstructModel%962031286.body preserve=yes
	ctor = new AcceleratorModelConstructor();
	double z=0.0;

	ctor->NewModel();

	// reset the stream pointer
	ifs.seekg(0);
	StripHeader(ifs);

	while(ifs)
		z+=ReadComponent();

	if(logFlag && log) {
		*log<<endl;
		ctor->ReportStatistics(*log);
		*log<<"\nARC distance from MAD file: "<<z<<endl;
	}

	AcceleratorModel* theModel = ctor->GetModel();
	delete ctor;
	ctor=0;
	return theModel;
  //## end MADInterface::ConstructModel%962031286.body
}

//## Operation: IgnoreZeroLengthType%962967925
void MADInterface::IgnoreZeroLengthType (const string& madType)
{
  //## begin MADInterface::IgnoreZeroLengthType%962967925.body preserve=yes
	zeroLengths.insert(madType);
  //## end MADInterface::IgnoreZeroLengthType%962967925.body
}

//## Operation: ConstructNewFrame%962967904
void MADInterface::ConstructNewFrame (const string& name)
{
  //## begin MADInterface::ConstructNewFrame%962967904.body preserve=yes
	SequenceFrame* newFrame;
	
	if(name[1]!='_') {
		if(honMadStructs)
			newFrame = new SequenceFrame(name);
		else
			return;
	}
	else {	
		switch( name[0] ) {
		case 'F':
			newFrame = new SequenceFrame(name.substr(2));
			break;
		case 'S':
			newFrame = new SimpleMount(name.substr(2));
			break;
		case 'G':
//			newFrame = new SimpleMount(name.substr(2));
			newFrame = new GirderMount(name.substr(2));
			break;
		case 'M':
			newFrame = new MagnetMover(name.substr(2));
			break;
		default:
			MERLIN_ERR<<"Unknown frame character: "<<name<<endl;
			abort();
			break;
		}
	}
	ctor->NewFrame(newFrame);
	if(log)
		Log(newFrame->GetName()+" BEGIN",ctor->GetCurrentFrameDepth(),*log);
  //## end MADInterface::ConstructNewFrame%962967904.body
}

//## Operation: EndFrame%962967905
void MADInterface::EndFrame (const string& name)
{
  //## begin MADInterface::EndFrame%962967905.body preserve=yes
	if((!honMadStructs) && name[1]!='_')
		return;
	
	SequenceFrame& currentFrame = ctor->GetCurrentFrame();

#ifndef NDEBUG
	if(honMadStructs)
		assert(name==currentFrame.GetName());
	else
		assert(name.substr(2)==currentFrame.GetName());
#endif

	if(log)
		Log(currentFrame.GetName()+" END",ctor->GetCurrentFrameDepth(),*log);
	
	ctor->EndFrame();
  //## end MADInterface::EndFrame%962967905.body
}

//## Operation: ReadComponent%962967906
double MADInterface::ReadComponent ()
{
  //## begin MADInterface::ReadComponent%962967906.body preserve=yes
	#define  _READ(value) if(!(ifs>>value)) return 0;

	string name,type,aptype;
	double len,s,angle,k1,k2,k3,h,tilt;
	
	_READ(name);
	_READ(type);
	_READ(s);
	_READ(len);
	_READ(angle);
	_READ(k1);
	_READ(k2);
	_READ(k3);
	_READ(tilt);
	_READ(aptype);
	
	name=StripQuotes(name);
	type=StripQuotes(type);
	aptype=StripQuotes(aptype);
	
	if(len==0 && zeroLengths.find(type)!=zeroLengths.end())
		return 0;


	// MERLIN-II bug: doesn't like Markers!
	if(type=="MARKER") type="DRIFT";
	
	if(type=="SKEWSEXT" || type=="OCTUPOLE")
		type="DRIFT";

	AcceleratorComponent *component;
	
	if(type=="DRIFT") {
		Drift* aDrift = new Drift(name,len);
		ctor->AppendComponent(*aDrift);
		component=aDrift;
	}
	else if(type=="QUADRUPOLE") {
		Quadrupole* quad = new Quadrupole(name,len,brho*k1/len);
		ctor->AppendComponent(*quad);
		component=quad;
	}
	else if(type=="SKEWQUAD") {
		SkewQuadrupole* quad = new SkewQuadrupole(name,len,brho*k1/len);
		ctor->AppendComponent(*quad);
		component=quad;
	}
	
	else if(type=="SBEND") {
		h = angle/len;
		SectorBend* bend = new SectorBend(name,len,h,brho*h);
		if(k1!=0)  // mixed function dipole
			bend->SetB1(brho*k1/len);
		ctor->AppendComponent(*bend);
		component=bend;
	}
	else if(type=="SEXTUPOLE") {
		Sextupole* sx = new Sextupole(name,len,brho*k2/len);
		ctor->AppendComponent(*sx);
		component=sx;
	}
	else if(type=="OCTUPOLE") {
		Octupole* oct = new Octupole(name,len,brho*k3/len);
		ctor->AppendComponent(*oct);
		component=oct;
	}
	else if(type=="SKEWSEXT") {
		SkewSextupole* sx = new SkewSextupole(name,len,brho*k2/len);
		ctor->AppendComponent(*sx);
		component=sx;
	}
	else if(type=="YCOR") {
		YCor* yc = new YCor(name,len);
		ctor->AppendComponent(*yc);
		component=yc;
	}	
	else if(type=="XCOR") {
		XCor* xc = new XCor(name,len);
		ctor->AppendComponent(*xc);
		component=xc;
	}
	else if(type=="MONITOR") {
		if(name.substr(0,4)=="BPM_") {
			BPM* bpm = new BPM("BPM"+name.substr(4));
			ctor->AppendComponent(*bpm);
			component=bpm;
		}
		else if(name.substr(0,3)=="WS_") {
			RMSProfileMonitor* ws = new RMSProfileMonitor("WS"+name.substr(3));
			ctor->AppendComponent(*ws);
			component=ws;
		}
		else {
			MERLIN_ERR<<"ERROR: unknown monitor type: "<<name<<endl;
			abort();
		}
	}
	else if(type=="LINE") {
		if(!flatLattice) {
			if(!frameStack.empty() && name == frameStack.top()) {
				frameStack.pop();
				EndFrame(name);
			}
			else {
				frameStack.push(name);
				ConstructNewFrame(name);
			}			
		}
		component=0;
	}
	else if(type=="MATRIX") // just ignore for now.
		component=0;
	else {
		MERLIN_ERR<<"ERROR: undefined type: "<<type<<endl;
		abort();
	}
	
	if(component && log)
		Log(component->GetQualifiedName(),ctor->GetCurrentFrameDepth(),*log);
	
	if(component && incApertures)
		component->SetAperture(ConstructAperture(aptype));

	return component ? component->GetLength() : 0.0;
  //## end MADInterface::ReadComponent%962967906.body
}

//## begin module%3ADEDE3600A0.epilog preserve=yes
//## end module%3ADEDE3600A0.epilog

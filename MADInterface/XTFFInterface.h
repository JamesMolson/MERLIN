/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2002)
 * 
 * file Merlin/MADInterface/XTFFInterface.h
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

#ifndef XTFFInterface_h
#define XTFFInterface_h 1

#include "merlin_config.h"

#include <fstream>
#include <string>
#include <set>

// AcceleratorModel
#include "AcceleratorModel/AcceleratorModel.h"

// BeamData
#include "BeamModel/BeamData.h"


class AcceleratorModelConstructor;

//  class XTFFInterface
//	Class used to construct a MERLIN model from a MAD TWISS TAPE
//	output listing. XTFF (eXtended Tape File Format) contains
//  SLAC extentions for cavities and acceleration.

class XTFFInterface {
public:

	// Constructer taking the name of the .xtff file, the total bunch
	// charge (particle per bunch) and an option log file. When a non-zero 
	// bunch charge is specified, the constructor uses the ELOSS information
	// for the cavities to calculate the reference (matched) energy for the
	// magnet strengths.
	XTFFInterface(const std::string& fname, double nb=0, ostream* log =0);
	~XTFFInterface();

	pair<AcceleratorModel*,BeamData*> Parse();
	
	// Construct apertures if flag is true (default)
	void IncludeApertures(bool flag) { incApertures = flag; }

	// Treat MAD type as DRIFT
	void TreatTypeAsDrift(const string&);

	// Construct girders
	void ConstructGirders(bool flg) { girders = flg; }

	// data structure for XTFF data
	struct XTFF_Data;
	
private:	

	void ConstructComponent(XTFF_Data&);
	int ParseHeader();

	std::set<string> driftTypes;

	std::ifstream ifs;
	AcceleratorModelConstructor* mc;
	BeamData* beam0;
	double nb;
	ostream* logos;
	bool incApertures;

	// used for girder construction
	bool girders;
	bool in_g;
};


#endif


//   Read the documentation to learn more about C++ code generator
//   versioning.

/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 3.0 (2003)
 * 
 * file Merlin\MADInterface\MADInterface.h
 * last modified 04/12/01 10:41:00
 */

/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 2003 by The Merlin Collaboration.
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

#ifndef MADInterface_h
#define MADInterface_h 1

#include "merlin_config.h"

#include <fstream>
#include <string>
#include <set>

// AcceleratorModel
#include "AcceleratorModel/AcceleratorModel.h"

class AcceleratorModelConstructor;
class MADKeyMap;

using std::ifstream;
using std::ostream;

//      Class used to construct a MERLIN model from a MAD optics
//      output listing. The class now automatically  identifies
//      the column parameters, and associates them with the
//      constructed element types. If an element type is defined
//      for which a required parameter is not present in the
//      column headings, the parameter is set to zero and a
//      warning is issued.

class MADInterface
{
public:
    //        Constructor taking the name of the MAD optics file, and
    //        the momentum in GeV/c.
    MADInterface (const std::string& madFileName="", double P0=0);

    //        Causes the construction of an AcceleratorModel object
    //        based on the MAD optics file.
    AcceleratorModel* ConstructModel ();

    //        Sets the log file stream to os.
    void SetLogFile (ostream& os);

    //        Turns logging on.
    void SetLoggingOn ();

    //        Turns logging off.
    void SetLoggingOff ();

    //        If true, all LINE constructs in the MAD optics output
    //        are constructed in the model. If false, only those
    //        prefixed X_, where X is M, S, or G are constructed.
    void HonourMadStructure (bool flg);

    //        If true, a flat lattice model in constructed, with no
    //        nested frames.
    void ConstructFlatLattice (bool flg);

    void ConstructApertures (bool flg);

    //        Components of type madType are ignored during
    //        construction if their length is zero.
    void IgnoreZeroLengthType (const string& madType);

    //        If scaleSR == true, then the magnetic fields of the
    //        magnets are scaled to compensate beam energy losses due
    //        to synchrotron radiation (default = false.) Note that in
    //        this case, the beam energy is the initial energy.
    void ScaleForSynchRad (bool scaleSR);

    //        Treats the mad type typestr as a drift.
    void TreatTypeAsDrift (const std::string& typestr);

    // Functions for constructing a model from several files.
    // Repeated calls to AppendModel(fname,p) constructs a single
    // model (beamline) from the respective files. The final
    // model is returned using GetModel().
    void AppendModel(const std::string& fname, double pref);
    AcceleratorModel* GetModel();

protected:
// private: hmmm... seriously hacked by A. Wolski
    // Data Members for Class Attributes

    double energy;

    bool logFlag;
    bool flatLattice;
    bool honMadStructs;
    bool incApertures;
    bool inc_sr;

    ifstream *ifs;
    ostream* log;

    std::set<std::string> zeroLengths;
    std::set<std::string> driftTypes;

    AcceleratorModelConstructor* ctor;
    MADKeyMap* prmMap;

    void EndFrame (const string& name);
    void ConstructNewFrame (const string& name);

private:



    double ReadComponent ();

    void Initialise();

    // Data Members for Associations
};

// Class MADInterface

inline void MADInterface::SetLogFile (ostream& os)
{
    log=&os;
}

inline void MADInterface::SetLoggingOn ()
{
    logFlag=true;
}

inline void MADInterface::SetLoggingOff ()
{
    logFlag=false;
}

inline void MADInterface::HonourMadStructure (bool flg)
{
    honMadStructs=flg;
}

inline void MADInterface::ConstructFlatLattice (bool flg)
{
    flatLattice=flg;
}

inline void MADInterface::ConstructApertures (bool flg)
{
    incApertures = flg;
}

inline void MADInterface::ScaleForSynchRad (bool scaleSR)
{
    inc_sr = scaleSR;
}

#endif

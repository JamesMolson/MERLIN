/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004-12-13 08:38:51 $
// $Revision: 1.3 $
// 
/////////////////////////////////////////////////////////////////////////

#ifndef WakePotentials_h
#define WakePotentials_h 1

#include "merlin_config.h"

//	Abstract class for calculating the longitudinal and
//	transverse single-bunch wakefield potentials (Greens
//	functions).

class WakePotentials
{
public:

    WakePotentials() : csr(false) {}
    virtual ~WakePotentials () {};

    virtual double Wlong (double z) const = 0;
    virtual double Wtrans (double z) const = 0;
    bool Is_CSR () const {
        return csr;
    }

protected:
    bool csr;
};

#endif

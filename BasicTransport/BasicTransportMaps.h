// BasicTransportMaps.h
//
// Contains declarations of global functions for constructing 
// first- and second-order transport matrices. Both order maps
// are constructed and returned in a RTMap object.

#ifndef _H_BasicTransportMaps
#define _H_BasicTransportMaps 1

#include "BasicTransport/RTMap.h"

RTMap* DriftTM(double s);
RTMap* SectorBendTM(double s, double h);
RTMap* SextupoleTM(double s, double K2);
RTMap* QuadrupoleTM(double s, double K1);
RTMap* GenSectorBendTM(double s, double h, double K1, double K2);


#endif
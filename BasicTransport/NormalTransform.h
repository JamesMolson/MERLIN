/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004-12-13 08:38:52 $
// $Revision: 1.2 $
// 
/////////////////////////////////////////////////////////////////////////


#ifndef _h_NormalTransform
#define _h_NormalTransform

#include "TLAS/LinearAlgebra.h"
#include "BeamModel/BeamData.h"
#include "BeamModel/PSTypes.h"

// utility global functions for generating beam phase space
// normalisations

RealMatrix CouplingMatrix(double a, double b, double c, double d);
RealMatrix AlphaMatrix(double ax, double ay);
RealMatrix BetaMatrix(double bx, double by);
RealMatrix DispersionMatrix(double Dx, double Dxp, double Dy, double Dyp);
RealMatrix NormalTransform(const BeamData& t);

PSmoments& BeamDataToSigmaMtrx(const BeamData& t, PSmoments& S);
inline PSmoments BeamDataToSigmaMtrx(const BeamData& t) {
    PSmoments S;
    return BeamDataToSigmaMtrx(t,S);
}

BeamData& SigmaMatrixToBeamData(const PSmoments& S0, BeamData& t);

double ProjectedEmittance(const PSmoments& s, PScoord x1, PScoord x2);

#endif

// NormalTransform.h
// utility global functions for generating beam phase space
// normalisations

#ifndef _h_NormalTransform
#define _h_NormalTransform

#include "TLAS/LinearAlgebra.h"
#include "BeamModel/BeamData.h"
#include "BeamModel/PSTypes.h"


RealMatrix CouplingMatrix(double a, double b, double c, double d);
RealMatrix AlphaMatrix(double ax, double ay);
RealMatrix BetaMatrix(double bx, double by);
RealMatrix DispersionMatrix(double Dx, double Dxp, double Dy, double Dyp);
RealMatrix NormalTransform(const BeamData& t);
PSmoments& BeamDataToSigmaMtrx(const BeamData& t, PSmoments& S);
BeamData& SigmaMatrixToBeamData(const PSmoments& S0, BeamData& t);
double ProjectedEmittance(const PSmoments& s, PScoord x1, PScoord x2);

#endif

#ifndef _h_BeamBeamLuminosity
#define _h_BeamBeamLuminosity

#include "BasicTransport/PSTypes.h"

// CalculateLumi
// Calculates luminosity of two colliding beams with 6D gaussian distributions,
// represented by their first and second order moments (beam1 and beam2)
// This calculation does not include any beam-beam effects

double CalculateLuminosity(const PSmoments& beam1, const PSmoments& beam2);

#endif

#ifndef _h_Complex
#define _h_Complex 1

#ifndef NO_STD_COMPLEX
#include <complex>
typedef std::complex<double> Complex;
#else
#include "NumericalUtils/ComplexDef.h"
#endif

#endif

#ifndef _h_Complex
#define _h_Complex 1

#ifndef USE_STD_COMPLEX
#include "NumericalUtils/ComplexDef.h"
#else
#include <complex>
typedef std::complex<double> Complex;
#endif

#endif

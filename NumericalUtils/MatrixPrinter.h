#ifndef _h_MatrixPrinter
#define _h_MatrixPrinter

#include "merlin_config.h"
#include <iostream>
#include "TLAS/LinearAlgebra.h"
#include "utility/OPFormat.h"


void MatrixForm(const RealMatrix&, std::ostream&, const OPFormat& =OPFormat());


#endif

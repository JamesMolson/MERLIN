// timing.h

#ifndef _h_Timing
#define _h_Timing 1

#include <ctime>
#include <iostream>

#define BEGIN_TIMING { time_t start_t = time(0)
#define END_TIMING(os,txt) os<<txt<<difftime(time(0),start_t)<<" seconds"; }

#endif
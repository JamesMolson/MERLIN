/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file stdext/algorithms.h
 * last modified 08/27/00 13:10
 */

/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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

#ifndef stdext_algorithm_h
#define stdext_algorithm_h 1

#include "merlin_config.h"

template<class InIt, class OutIt, class Pred>
OutIt copy_if(InIt first, InIt last, OutIt x, Pred test)
{
	while(first++ != last) 
		if(test(*first)) *x++ = *first;
	return x;
}

#endif

// merlin_config.h
// configuration and platform/compiler dependent information
// Currently only needed for MSVC++

#ifndef _h_merlin_config
#define _h_merlin_config
#include <string>
#include <cstring>

//Include for x86 vector functions
#ifdef __x86_64__
#include <immintrin.h>
#endif

//#if _MSC_VER >= 1400
//#define __TYPENAME__ typename
//#endif

#ifdef _MSC_VER
#pragma warning(disable: 4786)
#pragma warning(disable: 4660)
#pragma warning(disable: 4290)
#pragma warning(disable: 4018)
#pragma warning(disable: 4244)
#pragma warning(disable: 4267)

#if _MSC_VER>=1400
#define __TYPENAME__ typename
#else
#define __TYPENAME__
#endif

#else
#define __TYPENAME__ typename
#define _MAX(a,b) std::max(a,b)
#define _MIN(a,b) std::min(a,b)
#endif /* _MSC_VER */
//dk must be defined somewhere
#define _MAX(a,b) std::max(a,b)
#define _MIN(a,b) std::min(a,b)

/**
* Floating point and vector definitions
* Do not mix global single precision floats with vectors that are expecting doubles.
* Define the floating point type, and the vector type used in Merlin
*/

/**
* Single precision variables (32-bit math)
*/

/** Use floats (32-bit) */
//typedef float Mfloat_t;

/** Use 128bit (SSE2) length vectors - aka 4 singles */
//typedef __m128 Mvector_t;

/** Use 256bit (AVX) length vectors - aka 8 singles */
//typedef __m256 Mvector_t;

/** Use 512bit (AVX-512) length vectors - aka 16 singles */
//typedef __m512 Mvector_t;

/**
* Double precision variables (64-bit math)
*/

/** Use doubles (64-bit) */
typedef double Mfloat_t;

/** Use 128bit (SSE2) length vectors - aka 2 doubles */
//typedef __m128d Mvector_t;

/** Use 256bit (AVX) length vectors - aka 4 doubles */
typedef __m256d Mvector_t;

/** Use 512bit (AVX-512) length vectors - aka 8 doubles */
//typedef __m512d Mvector_t;

/** Fixed global variable to define the number of float types in a vector type. */
static const unsigned int MvectorLength = sizeof(Mvector_t)/sizeof(Mfloat_t);

#endif /* _h_merlin_config */

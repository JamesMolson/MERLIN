// merlin_config.h
// configuration and platform/compiler dependent information
// Currently only needed for MSVC++

#ifndef _h_merlin_config
#define _h_merlin_config

#ifdef  _MSC_VER
#pragma warning(disable: 4786)
#pragma warning(disable: 4660)
#define __TYPENAME__
#else
#define __TYPENAME__ typename
#define _MAX std::max
#define _MIN std::min
#endif  /* _MSC_VER */

#endif /* _h_merlin_config */

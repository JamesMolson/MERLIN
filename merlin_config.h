// merlin_config.h
// configuration and platform/compiler dependent information
// Currently only needed for MSVC++
// Need to update this file for GCC 3.1

#ifndef _h_merlin_config
#define _h_merlin_config

#ifdef  _MSC_VER
#pragma warning(disable: 4786)
#pragma warning(disable: 4660)
#endif  /* _MSC_VER */


#endif /* _h_merlin_config */

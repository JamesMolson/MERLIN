//## begin module%347AA25D01C2.cm preserve=no
//## end module%347AA25D01C2.cm

//## begin module%347AA25D01C2.cp preserve=no
//## end module%347AA25D01C2.cp

//## Module: RotationType%347AA25D01C2; Package specification
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\RotationType.h

#ifndef RotationType_h
#define RotationType_h 1

//## begin module%347AA25D01C2.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%347AA25D01C2.additionalIncludes

//## begin module%347AA25D01C2.includes preserve=yes
//## end module%347AA25D01C2.includes

//## begin module%347AA25D01C2.declarations preserve=no
//## end module%347AA25D01C2.declarations

//## begin module%347AA25D01C2.additionalDeclarations preserve=yes
//## end module%347AA25D01C2.additionalDeclarations


//## Class: RotationType%3398129900D1; implementation
//	Type of rotation. Can be ident, xrot, yrot, zrot or
//	mixed.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {ident, xrot, yrot, zrot, mixed} RotationType;

//## begin module%347AA25D01C2.epilog preserve=yes
//## end module%347AA25D01C2.epilog


#endif

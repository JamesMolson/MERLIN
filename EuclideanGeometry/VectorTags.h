//## begin module.cm preserve=no
// Specification for VectorTags
// last modified: 11/28/97 at 18:52:07
// This file is part of the MERLIN class library
// version 1.0beta
// ---------------------------------------------
//## end module.cm

//## begin module.cp preserve=no
// (c) 1997 Nicholas J. Walker (DESY) -- All Rights Reserved --
// ------------------------------------------------------------
//## end module.cp

//## Module: VectorTags; Package specification
//## Subsystem: Geometry2D
//## Source file: c:\C++\Merlin\Geometry2D\VectorTags.h

#ifndef VectorTags_h
#define VectorTags_h 1

//## begin module.includes preserve=yes
//## end module.includes

//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: PointTag
//	Tag class for TVec3D specifying that the instantiated
//	three vector transforms as a point.
//## Category: Geometry2D
//## Subsystem: Geometry2D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class PointTag 
{
  public:
  protected:
  private:
  private:  //## implementation
};



//## Class: VectorTag
//	Tag class for TVec3D specifying that the instantiated
//	three vector transforms as a vector.
//## Category: Geometry2D
//## Subsystem: Geometry2D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class VectorTag 
{
  public:
  protected:
  private:
  private:  //## implementation
};



// Class PointTag 



// Class VectorTag 



//## begin module.epilog preserve=yes
//## end module.epilog
#endif

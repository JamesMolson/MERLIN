//## begin module%347AA15E03A2.cm preserve=no
//## end module%347AA15E03A2.cm

//## begin module%347AA15E03A2.cp preserve=no
//## end module%347AA15E03A2.cp

//## Module: Rot3Drep%347AA15E03A2; Package specification
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\Rot3Drep.h

#ifndef Rot3Drep_h
#define Rot3Drep_h 1

//## begin module%347AA15E03A2.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%347AA15E03A2.additionalIncludes

//## begin module%347AA15E03A2.includes preserve=yes
#include "TLAS/LinearAlgebra.h"
//## end module%347AA15E03A2.includes

// Space3D
#include "EuclideanGeometry/Space3D.h"
// RotationType
#include "EuclideanGeometry/RotationType.h"

class IdentityRotation;
class GeneralRotation;
class RotationZ;
class RotationY;
class RotationX;

//## begin module%347AA15E03A2.declarations preserve=no
//## end module%347AA15E03A2.declarations

//## begin module%347AA15E03A2.additionalDeclarations preserve=yes
//## end module%347AA15E03A2.additionalDeclarations


//## Class: Rot3Drep%337B4082028A; Abstract; implementation
//	The abstract representation (letter class) for
//	Rotation3D.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3398129B03B2;IdentityRotation { -> F}
//## Uses: <unnamed>%3398129B03B3;RotationX { -> F}
//## Uses: <unnamed>%3398129B03B4;RotationY { -> F}
//## Uses: <unnamed>%3398129B03B9;RotationZ { -> F}
//## Uses: <unnamed>%3398129B03BA;GeneralRotation { -> F}
//## Uses: <unnamed>%3398129B03BB;RotationType { -> }
//## Uses: <unnamed>%3398129B03C3;Point3D { -> }
//## Uses: <unnamed>%3398129B03D7;Vector3D { -> }
//## Uses: <unnamed>%3398129C0021; { -> }

class Rot3Drep 
{
  public:
    //## Destructor (specified)
      //## Operation: ~Rot3Drep%863777756; C++
      //	Virtual destructor.
      virtual ~Rot3Drep ();


    //## Other Operations (specified)
      //## Operation: rotate%863777765; C++
      //	Rotate the specified point and return the result.
      virtual Point3D rotate (const Point3D& x) const = 0;

      //## Operation: rotate%863777766; C++
      //	Rotate the specified vector and return the result.
      virtual Vector3D rotate (const Vector3D& v) const = 0;

      //## Operation: dot%863777767; C++
      //	Dot this rotation with r.
      virtual Rot3Drep* dot (const Rot3Drep& r) const = 0;

      //## Operation: dotBy%863777768; C++
      //	Dot this rotation by a pure x rotation.
      virtual Rot3Drep* dotBy (const RotationX& rx) const = 0;

      //## Operation: dotBy%863777769; C++
      //	Dot this rotation by a pure y rotation.
      virtual Rot3Drep* dotBy (const RotationY& ry) const = 0;

      //## Operation: dotBy%863777770; C++
      //	Dot this rotation by a pure z rotation.
      virtual Rot3Drep* dotBy (const RotationZ& rz) const = 0;

      //## Operation: dotBy%863777771; C++
      //	Dot this rotation by a general rotation.
      virtual Rot3Drep* dotBy (const GeneralRotation& r) const = 0;

      //## Operation: inv%863777772; C++
      //	Return an inverted rotation.
      virtual Rot3Drep* inv () const = 0;

      //## Operation: type%863777773; C++
      //	Return the type of rotation. Can be identity, xrot,
      //	yrot, zrot or general.
      virtual RotationType type () const = 0;

      //## Operation: isIdentity%863777757; C++
      //	Returns true if this is a null rotation.
      virtual bool isIdentity () const;

      //## Operation: isXrot%863777758; C++
      //	Returns true if a pure rotation about the x-axis.
      virtual bool isXrot () const;

      //## Operation: isYrot%863777759; C++
      //	Returns true if a pure rotation about the y-axis.
      virtual bool isYrot () const;

      //## Operation: isZrot%863777760; C++
      //	Returns true if a pure rotation about the z-axis.
      virtual bool isZrot () const;

      //## Operation: identity%863777761; C++
      //	Static factory method. Constructs an identity (null)
      //	rotation.
      static Rot3Drep* identity ();

      //## Operation: rotationX%863777762; C++
      //	Static factory method. Constructs a pure x rotation of
      //	angle radians.
      static Rot3Drep* rotationX (double angle);

      //## Operation: rotationY%863777763; C++
      //	Static factory method. Constructs a pure y rotation of
      //	angle radians.
      static Rot3Drep* rotationY (double angle);

      //## Operation: rotationZ%863777764; C++
      //	Static factory method. Constructs a pure z rotation of
      //	angle radians.
      static Rot3Drep* rotationZ (double angle);

      //## Operation: rotXbyPI%885461003
      //	Rotation by 180 degrees about the X-axis.
      virtual Rot3Drep* rotXbyPI () const = 0;

      //## Operation: rotYbyPI%885461004
      //	Rotation by 180 degrees about the Y-axis.
      virtual Rot3Drep* rotYbyPI () const = 0;

      //## Operation: rotZbyPI%885461005
      //	Rotation by 180 degrees about the Z-axis.
      virtual Rot3Drep* rotZbyPI () const = 0;

      //## Operation: getMatrix%903600356
      //	Returns in m the 3x3 rotation matrix.
      virtual RealMatrix& getMatrix (RealMatrix& m) const = 0;

  protected:
    //## Constructors (specified)
      //## Operation: Rot3Drep%863777755; C++
      //	Protected default constructor.
      Rot3Drep ();

  private:
    // Data Members for Class Attributes

      //## Attribute: refc%3398129B03B1
      //	Reference count for memory management.
      //## begin Rot3Drep::refc%3398129B03B1.attr preserve=no  private: int {UA} 0
      int refc;
      //## end Rot3Drep::refc%3398129B03B1.attr

  private:  //## implementation
    friend class Rotation3D;
};

// Class Rot3Drep 

//## begin module%347AA15E03A2.epilog preserve=yes
//## end module%347AA15E03A2.epilog


#endif

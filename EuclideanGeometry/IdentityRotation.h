//## begin module%347AA2BD0050.cm preserve=no
//## end module%347AA2BD0050.cm

//## begin module%347AA2BD0050.cp preserve=no
//## end module%347AA2BD0050.cp

//## Module: IdentityRotation%347AA2BD0050; Package specification
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\IdentityRotation.h

#ifndef IdentityRotation_h
#define IdentityRotation_h 1

//## begin module%347AA2BD0050.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%347AA2BD0050.additionalIncludes

//## begin module%347AA2BD0050.includes preserve=yes
//## end module%347AA2BD0050.includes

// Space3D
#include "EuclideanGeometry/Space3D.h"
// RotationType
#include "EuclideanGeometry/RotationType.h"
// Rot3Drep
#include "EuclideanGeometry/Rot3Drep.h"

class GeneralRotation;
class RotationZ;
class RotationY;
class RotationX;

//## begin module%347AA2BD0050.declarations preserve=no
//## end module%347AA2BD0050.declarations

//## begin module%347AA2BD0050.additionalDeclarations preserve=yes
//## end module%347AA2BD0050.additionalDeclarations


//## Class: IdentityRotation%337B54BE023A; implementation
//	A null or identity rotation.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3398129B020A;RotationX { -> F}
//## Uses: <unnamed>%3398129B020B;RotationY { -> F}
//## Uses: <unnamed>%3398129B020C;RotationZ { -> F}
//## Uses: <unnamed>%3398129B020D;GeneralRotation { -> F}
//## Uses: <unnamed>%3398129B020E;Rot3Drep { -> }
//## Uses: <unnamed>%3398129B021E;Point3D { -> }
//## Uses: <unnamed>%3398129B0228;Vector3D { -> }
//## Uses: <unnamed>%3398129B0232; { -> }
//## Uses: <unnamed>%3398129B0253;RotationType { -> }

class IdentityRotation : public Rot3Drep  //## Inherits: <unnamed>%3398129B025B
{
  public:

    //## Other Operations (specified)
      //## Operation: inv%863777842; C++
      //	Return an inverted rotation.
      virtual Rot3Drep* inv () const;

      //## Operation: rotate%863777843; C++
      //	Rotate the specified point and return the result.
      virtual Point3D rotate (const Point3D& p) const;

      //## Operation: rotate%863777844; C++
      //	Rotate the specified vector and return the result.
      virtual Vector3D rotate (const Vector3D& v) const;

      //## Operation: isIdentity%863777845; C++
      //	Returns true.
      virtual bool isIdentity () const;

      //## Operation: dot%863777846; C++
      //	Dot this rotation with r.
      virtual Rot3Drep* dot (const Rot3Drep& r) const;

      //## Operation: dotBy%863777847; C++
      //	Dot this rotation by a pure x rotation.
      virtual Rot3Drep* dotBy (const RotationX& rx) const;

      //## Operation: dotBy%863777848; C++
      //	Dot this rotation by a pure y rotation.
      virtual Rot3Drep* dotBy (const RotationY& ry) const;

      //## Operation: dotBy%863777849; C++
      //	Dot this rotation by a pure z rotation.
      virtual Rot3Drep* dotBy (const RotationZ& rz) const;

      //## Operation: dotBy%863777850; C++
      //	Dot this rotation by a general rotation.
      virtual Rot3Drep* dotBy (const GeneralRotation& r) const;

      //## Operation: type%863777851; C++
      //	Return the type of rotation. Can be identity, xrot,
      //	yrot, zrot or general.
      virtual RotationType type () const;

      //## Operation: rotXbyPI%885461006
      //	Rotation by 180 degrees about the X-axis.
      virtual Rot3Drep* rotXbyPI () const;

      //## Operation: rotYbyPI%885461007
      //	Rotation by 180 degrees about the Y-axis.
      virtual Rot3Drep* rotYbyPI () const;

      //## Operation: rotZbyPI%885461008
      //	Rotation by 180 degrees about the Z-axis.
      virtual Rot3Drep* rotZbyPI () const;

      //## Operation: getMatrix%903600351
      //	Returns in m the 3x3 rotation matrix.
      virtual RealMatrix& getMatrix (RealMatrix& m) const;

  protected:
  private:
  private:  //## implementation
};

// Class IdentityRotation 

//## begin module%347AA2BD0050.epilog preserve=yes
//## end module%347AA2BD0050.epilog


#endif

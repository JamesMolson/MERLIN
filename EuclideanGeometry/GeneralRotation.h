//## begin module%347AA293006E.cm preserve=no
//## end module%347AA293006E.cm

//## begin module%347AA293006E.cp preserve=no
//## end module%347AA293006E.cp

//## Module: GeneralRotation%347AA293006E; Package specification
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\GeneralRotation.h

#ifndef GeneralRotation_h
#define GeneralRotation_h 1

//## begin module%347AA293006E.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%347AA293006E.additionalIncludes

//## begin module%347AA293006E.includes preserve=yes
#include "TLAS/LinearAlgebra.h"
//## end module%347AA293006E.includes

// LinearAlgebra
#include "TLAS/LinearAlgebra.h"
// Space3D
#include "EuclideanGeometry/Space3D.h"
// RotationType
#include "EuclideanGeometry/RotationType.h"
// Rot3Drep
#include "EuclideanGeometry/Rot3Drep.h"
// AxisRotations
#include "EuclideanGeometry/AxisRotations.h"
//## begin module%347AA293006E.declarations preserve=no
//## end module%347AA293006E.declarations

//## begin module%347AA293006E.additionalDeclarations preserve=yes
//## end module%347AA293006E.additionalDeclarations


//## Class: GeneralRotation%337B53CD0186; implementation
//	A general (arbirary) 3-D rotation. Note that a general
//	rotation can represent a pure axis rotation.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3398129A037C;RotationX { -> }
//## Uses: <unnamed>%3398129A037D;RotationY { -> }
//## Uses: <unnamed>%3398129A0381;RotationZ { -> }
//## Uses: <unnamed>%3398129A03B8;Rot3Drep { -> }
//## Uses: <unnamed>%3398129B0002;Point3D { -> }
//## Uses: <unnamed>%3398129B000C;Vector3D { -> }
//## Uses: <unnamed>%3398129B0052;RotationType { -> }
//## Uses: <unnamed>%3398129B0054; { -> }

class GeneralRotation : public Rot3Drep  //## Inherits: <unnamed>%3398129B0067
{
  public:
    //## Constructors (specified)
      //## Operation: GeneralRotation%863777831; C++
      //	Copy constructor.
      GeneralRotation (const GeneralRotation& gr);

      //## Operation: GeneralRotation%885461012; C++
      //	Contruction from a rotation matrix
      explicit GeneralRotation (const RealMatrix& r);


    //## Other Operations (specified)
      //## Operation: inv%863777832; C++
      //	Return an inverted rotation.
      virtual Rot3Drep* inv () const;

      //## Operation: rotate%863777833; C++
      //	Rotate the specified point and return the result.
      virtual Point3D rotate (const Point3D& p) const;

      //## Operation: rotate%863777834; C++
      //	Rotate the specified vector and return the result.
      virtual Vector3D rotate (const Vector3D& v) const;

      //## Operation: dot%863777835; C++
      //	Dot this rotation with r.
      virtual Rot3Drep* dot (const Rot3Drep& r) const;

      //## Operation: dotBy%863777836; C++
      //	Dot this rotation by a pure x rotation.
      virtual Rot3Drep* dotBy (const RotationX& rx) const;

      //## Operation: dotBy%863777837; C++
      //	Dot this rotation by a pure y rotation.
      virtual Rot3Drep* dotBy (const RotationY& ry) const;

      //## Operation: dotBy%863777838; C++
      //	Dot this rotation by a pure z rotation.
      virtual Rot3Drep* dotBy (const RotationZ& rz) const;

      //## Operation: dotBy%863777839; C++
      //	Dot this rotation by a general rotation.
      virtual Rot3Drep* dotBy (const GeneralRotation& r) const;

      //## Operation: type%863777840; C++
      //	Return the type of rotation. Can be identity, xrot,
      //	yrot, zrot or general.
      virtual RotationType type () const;

      //## Operation: isIdentity%864204481; C++
      //	Returns true if this is a null rotation.
      virtual bool isIdentity () const;

      //## Operation: isXrot%864204482; C++
      //	Returns true if a pure rotation about the x-axis.
      virtual bool isXrot () const;

      //## Operation: isYrot%864204483; C++
      //	Returns true if a pure rotation about the y-axis.
      virtual bool isYrot () const;

      //## Operation: isZrot%864204484; C++
      //	Returns true if a pure rotation about the z-axis.
      virtual bool isZrot () const;

      //## Operation: rotXbyPI%885461009
      //	Rotation by 180 degrees about the X-axis.
      virtual Rot3Drep* rotXbyPI () const;

      //## Operation: rotYbyPI%885461010
      //	Rotation by 180 degrees about the Y-axis.
      virtual Rot3Drep* rotYbyPI () const;

      //## Operation: rotZbyPI%885461011
      //	Rotation by 180 degrees about the Z-axis.
      virtual Rot3Drep* rotZbyPI () const;

      //## Operation: getMatrix%903600352
      //	Returns in m the 3x3 rotation matrix.
      virtual RealMatrix& getMatrix (RealMatrix& m) const;

  protected:
  private:
    //## Constructors (specified)
      //## Operation: GeneralRotation%863777853; C++
      //	Special constructors from two succesive axis rotations.
      GeneralRotation (const RotationX& rx, const RotationY& ry);

      //## Operation: GeneralRotation%863777854; C++
      GeneralRotation (const RotationX& rx, const RotationZ& rz);

      //## Operation: GeneralRotation%863777855; C++
      GeneralRotation (const RotationY& ry, const RotationX& rx);

      //## Operation: GeneralRotation%863777856; C++
      GeneralRotation (const RotationY& ry, const RotationZ& rz);

      //## Operation: GeneralRotation%863777857; C++
      GeneralRotation (const RotationZ& rz, const RotationX& rx);

      //## Operation: GeneralRotation%863777858; C++
      GeneralRotation (const RotationZ& rz, const RotationY& ry);

      //## Operation: GeneralRotation%863777859; C++
      //	Special constructors formed by the dot product of a
      //	general rotation with a pure axis rotation.
      GeneralRotation (const GeneralRotation& r, const RotationX& rx);

      //## Operation: GeneralRotation%863777860; C++
      GeneralRotation (const GeneralRotation& r, const RotationY& ry);

      //## Operation: GeneralRotation%863777861; C++
      GeneralRotation (const GeneralRotation& r, const RotationZ& rz);

      //## Operation: GeneralRotation%864136518; C++
      //	Default constructor.
      GeneralRotation ();

    // Data Members for Associations

      //## Association: EuclideanGeometry::<unnamed>%362613F2024B
      //## Role: GeneralRotation::m%362613F30148
      //## begin GeneralRotation::m%362613F30148.role preserve=no  private: RealMatrix { -> VHAN}
      RealMatrix m;
      //## end GeneralRotation::m%362613F30148.role

  private:  //## implementation
  //## begin GeneralRotation%337B53CD0186.friends preserve=no
    friend class RotationX;
    friend class RotationY;
    friend class RotationZ;
  //## end GeneralRotation%337B53CD0186.friends
};

// Class GeneralRotation 

//## Operation: GeneralRotation%864136518; C++
inline GeneralRotation::GeneralRotation ()
  //## begin GeneralRotation::GeneralRotation%864136518.initialization preserve=yes
  : m(IdentityMatrix(3))
  //## end GeneralRotation::GeneralRotation%864136518.initialization
{
  //## begin GeneralRotation::GeneralRotation%864136518.body preserve=yes
  //## end GeneralRotation::GeneralRotation%864136518.body
}

//## Operation: GeneralRotation%885461012; C++
//## Qualification: inlined
inline GeneralRotation::GeneralRotation (const RealMatrix& r)
  //## begin GeneralRotation::GeneralRotation%885461012.initialization preserve=yes
  : m(r)
  //## end GeneralRotation::GeneralRotation%885461012.initialization
{
  //## begin GeneralRotation::GeneralRotation%885461012.body preserve=yes
  //## end GeneralRotation::GeneralRotation%885461012.body
}


//## begin module%347AA293006E.epilog preserve=yes
//## end module%347AA293006E.epilog


#endif

//## begin module%347AA2100262.cm preserve=no
//## end module%347AA2100262.cm

//## begin module%347AA2100262.cp preserve=no
//## end module%347AA2100262.cp

//## Module: AxisRotations%347AA2100262; Package specification
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\AxisRotations.h

#ifndef AxisRotations_h
#define AxisRotations_h 1

//## begin module%347AA2100262.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%347AA2100262.additionalIncludes

//## begin module%347AA2100262.includes preserve=yes
#include <math.h>
//## end module%347AA2100262.includes

// Space3D
#include "EuclideanGeometry/Space3D.h"
// RotationType
#include "EuclideanGeometry/RotationType.h"
// Rot3Drep
#include "EuclideanGeometry/Rot3Drep.h"

class GeneralRotation;

//## begin module%347AA2100262.declarations preserve=no
//## end module%347AA2100262.declarations

//## begin module%347AA2100262.additionalDeclarations preserve=yes
//## end module%347AA2100262.additionalDeclarations


//## Class: PureAxisRotation%337B53B90186; Abstract; implementation
//	Base class for pure rotations about a specific axis.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class PureAxisRotation : public Rot3Drep  //## Inherits: <unnamed>%3398129803D4
{
  public:
    //## Constructors (specified)
      //## Operation: PureAxisRotation%863777824; C++
      //	Constructor taking the axis rotation angle in radians.
      PureAxisRotation (double phi);


    //## Other Operations (specified)
      //## Operation: angle%863777790; C++
      //	Return the angle of rotation in radians.
      double angle () const;

      //## Operation: sine%863777825; C++
      //	Return the sine of the rotation angle.
      double sine () const;

      //## Operation: cosine%863777826; C++
      //	Return the cosine of the rotation angle.
      double cosine () const;

  protected:
    //## Constructors (specified)
      //## Operation: PureAxisRotation%863777827; C++
      //	Protected constructor taking the sine and cosine of the
      //	rotation angle
      PureAxisRotation (double cosa, double sina);

  private:
    // Data Members for Class Attributes

      //## Attribute: cosphi%3398129803A1
      //	The cosine of the rotation angle.
      //## begin PureAxisRotation::cosphi%3398129803A1.attr preserve=no  private: double {UA} 
      double cosphi;
      //## end PureAxisRotation::cosphi%3398129803A1.attr

      //## Attribute: sinphi%3398129803A2
      //	The sine of the rotation angle. The single angle is
      //	stored as sine and cosine for efficiency reasons when
      //	performing rotations.
      //## begin PureAxisRotation::sinphi%3398129803A2.attr preserve=no  private: double {UA} 
      double sinphi;
      //## end PureAxisRotation::sinphi%3398129803A2.attr

  private:  //## implementation
};

//## Class: RotationX%337B54D8014A; implementation
//	A pure rotation about the x-axis.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%339812990045;friend GeneralRotation { -> F}
//## Uses: <unnamed>%33981299004F;Rot3Drep { -> }
//## Uses: <unnamed>%339812990078;Point3D { -> }
//## Uses: <unnamed>%33981299008C;Vector3D { -> }
//## Uses: <unnamed>%3398129900AA;RotationY { -> }
//## Uses: <unnamed>%3398129900B4;RotationZ { -> }
//## Uses: <unnamed>%3398129900E5;RotationType { -> }
//## Uses: <unnamed>%3398129900FA; { -> }

class RotationX : public PureAxisRotation  //## Inherits: <unnamed>%339812990103
{
  public:
    //## Constructors (specified)
      //## Operation: RotationX%863777828; C++
      //	Contructor taking the rotation angle in radians.
      RotationX (double phi);


    //## Other Operations (specified)
      //## Operation: inv%863777792; C++
      //	Return an inverted rotation.
      virtual Rot3Drep* inv () const;

      //## Operation: rotate%863777793; C++
      //	Rotate the specified point and return the result.
      virtual Point3D rotate (const Point3D& p) const;

      //## Operation: rotate%863777794; C++
      //	Rotate the specified vector and return the result.
      virtual Vector3D rotate (const Vector3D& v) const;

      //## Operation: dot%863777795; C++
      //	Dot this rotation with r.
      virtual Rot3Drep* dot (const Rot3Drep& r) const;

      //## Operation: dotBy%863777796; C++
      //	Dot this rotation by a pure x rotation.
      virtual Rot3Drep* dotBy (const RotationX& rx) const;

      //## Operation: dotBy%863777797; C++
      //	Dot this rotation by a pure y rotation.
      virtual Rot3Drep* dotBy (const RotationY& ry) const;

      //## Operation: dotBy%863777798; C++
      //	Dot this rotation by a pure z rotation.
      virtual Rot3Drep* dotBy (const RotationZ& rz) const;

      //## Operation: dotBy%863777799; C++
      //	Dot this rotation by a general rotation.
      virtual Rot3Drep* dotBy (const GeneralRotation& r) const;

      //## Operation: type%863777800; C++
      //	Return the type of rotation. Can be identity, xrot,
      //	yrot, zrot or general.
      virtual RotationType type () const;

      //## Operation: isXrot%863777801; C++
      //	Returns true.
      virtual bool isXrot () const;

      //## Operation: rotXbyPI%885461013
      //	Rotation by 180 degrees about the X-axis.
      virtual Rot3Drep* rotXbyPI () const;

      //## Operation: rotYbyPI%885461014
      //	Rotation by 180 degrees about the Y-axis.
      virtual Rot3Drep* rotYbyPI () const;

      //## Operation: rotZbyPI%885461015
      //	Rotation by 180 degrees about the Z-axis.
      virtual Rot3Drep* rotZbyPI () const;

      //## Operation: getMatrix%903600353
      //	Returns in m the 3x3 rotation matrix.
      virtual RealMatrix& getMatrix (RealMatrix& m) const;

  protected:
  private:
    //## Constructors (specified)
      //## Operation: RotationX%863777791; C++
      //	Private constructor taking the sine and cosine of the
      //	rotation angle.
      RotationX (double cosa, double sina);

  private:  //## implementation
};

//## Class: RotationY%337B54E2017C; implementation
//	A pure rotation about the y-axis.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%339812990153;friend GeneralRotation { -> F}
//## Uses: <unnamed>%339812990160;Rot3Drep { -> }
//## Uses: <unnamed>%339812990167;Point3D { -> }
//## Uses: <unnamed>%339812990171;Vector3D { -> }
//## Uses: <unnamed>%33981299018F;RotationX { -> }
//## Uses: <unnamed>%339812990199;RotationZ { -> }
//## Uses: <unnamed>%3398129901AD;RotationType { -> }
//## Uses: <unnamed>%3398129901B7; { -> }

class RotationY : public PureAxisRotation  //## Inherits: <unnamed>%3398129901B9
{
  public:
    //## Constructors (specified)
      //## Operation: RotationY%863777829; C++
      //	Contructor taking the rotation angle in radians.
      RotationY (double phi);


    //## Other Operations (specified)
      //## Operation: inv%863777803; C++
      //	Return an inverted rotation.
      virtual Rot3Drep* inv () const;

      //## Operation: rotate%863777804; C++
      //	Rotate the specified point and return the result.
      virtual Point3D rotate (const Point3D& p) const;

      //## Operation: rotate%863777805; C++
      //	Rotate the specified vector and return the result.
      virtual Vector3D rotate (const Vector3D& v) const;

      //## Operation: dot%863777806; C++
      //	Dot this rotation with r.
      virtual Rot3Drep* dot (const Rot3Drep& r) const;

      //## Operation: dotBy%863777807; C++
      //	Dot this rotation by a pure x rotation.
      virtual Rot3Drep* dotBy (const RotationX& rx) const;

      //## Operation: dotBy%863777808; C++
      //	Dot this rotation by a pure y rotation.
      virtual Rot3Drep* dotBy (const RotationY& ry) const;

      //## Operation: dotBy%863777809; C++
      //	Dot this rotation by a pure z rotation.
      virtual Rot3Drep* dotBy (const RotationZ& rz) const;

      //## Operation: dotBy%863777810; C++
      //	Dot this rotation by a general rotation.
      virtual Rot3Drep* dotBy (const GeneralRotation& r) const;

      //## Operation: type%863777811; C++
      //	Return the type of rotation. Can be identity, xrot,
      //	yrot, zrot or general.
      virtual RotationType type () const;

      //## Operation: isYrot%863777812; C++
      //	Returns true.
      virtual bool isYrot () const;

      //## Operation: rotXbyPI%885461016
      //	Rotation by 180 degrees about the X-axis.
      virtual Rot3Drep* rotXbyPI () const;

      //## Operation: rotYbyPI%885461017
      //	Rotation by 180 degrees about the Y-axis.
      virtual Rot3Drep* rotYbyPI () const;

      //## Operation: rotZbyPI%885461018
      //	Rotation by 180 degrees about the Z-axis.
      virtual Rot3Drep* rotZbyPI () const;

      //## Operation: getMatrix%903600354
      //	Returns in m the 3x3 rotation matrix.
      virtual RealMatrix& getMatrix (RealMatrix& m) const;

  protected:
  private:
    //## Constructors (specified)
      //## Operation: RotationY%863777802; C++
      //	Private constructor taking the sine and cosine of the
      //	rotation angle.
      RotationY (double cosa, double sina);

  private:  //## implementation
};

//## Class: RotationZ%337B54EB01EA; implementation
//	A pure rotation about the z-axis.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3398129901FE;friend GeneralRotation { -> F}
//## Uses: <unnamed>%339812990212;Rot3Drep { -> }
//## Uses: <unnamed>%339812990214;Point3D { -> }
//## Uses: <unnamed>%339812990226;Vector3D { -> }
//## Uses: <unnamed>%33981299023C;RotationX { -> }
//## Uses: <unnamed>%339812990244;RotationY { -> }
//## Uses: <unnamed>%33981299025A;RotationType { -> }
//## Uses: <unnamed>%339812990263; { -> }

class RotationZ : public PureAxisRotation  //## Inherits: <unnamed>%33981299026C
{
  public:
    //## Constructors (specified)
      //## Operation: RotationZ%863777830; C++
      //	Contructor taking the rotation angle in radians.
      RotationZ (double phi);


    //## Other Operations (specified)
      //## Operation: inv%863777814; C++
      //	Return an inverted rotation.
      virtual Rot3Drep* inv () const;

      //## Operation: rotate%863777815; C++
      //	Rotate the specified point and return the result.
      virtual Point3D rotate (const Point3D& p) const;

      //## Operation: rotate%863777816; C++
      //	Rotate the specified vector and return the result.
      virtual Vector3D rotate (const Vector3D& v) const;

      //## Operation: dot%863777817; C++
      //	Dot this rotation with r.
      virtual Rot3Drep* dot (const Rot3Drep& r) const;

      //## Operation: dotBy%863777818; C++
      //	Dot this rotation by a pure x rotation.
      virtual Rot3Drep* dotBy (const RotationX& rx) const;

      //## Operation: dotBy%863777819; C++
      //	Dot this rotation by a pure y rotation.
      virtual Rot3Drep* dotBy (const RotationY& ry) const;

      //## Operation: dotBy%863777820; C++
      //	Dot this rotation by a pure z rotation.
      virtual Rot3Drep* dotBy (const RotationZ& rz) const;

      //## Operation: dotBy%863777821; C++
      //	Dot this rotation by a general rotation.
      virtual Rot3Drep* dotBy (const GeneralRotation& r) const;

      //## Operation: type%863777822; C++
      //	Return the type of rotation. Can be identity, xrot,
      //	yrot, zrot or general.
      virtual RotationType type () const;

      //## Operation: isZrot%863777823; C++
      //	Returns true.
      virtual bool isZrot () const;

      //## Operation: rotXbyPI%885461019
      //	Rotation by 180 degrees about the X-axis.
      virtual Rot3Drep* rotXbyPI () const;

      //## Operation: rotYbyPI%885461020
      //	Rotation by 180 degrees about the Y-axis.
      virtual Rot3Drep* rotYbyPI () const;

      //## Operation: rotZbyPI%885461021
      //	Rotation by 180 degrees about the Z-axis.
      virtual Rot3Drep* rotZbyPI () const;

      //## Operation: getMatrix%903600355
      //	Returns in m the 3x3 rotation matrix.
      virtual RealMatrix& getMatrix (RealMatrix& m) const;

  protected:
  private:
    //## Constructors (specified)
      //## Operation: RotationZ%863777813; C++
      //	Private constructor taking the sine and cosine of the
      //	rotation angle.
      RotationZ (double cosa, double sina);

  private:  //## implementation
};

// Class PureAxisRotation 

//## Operation: PureAxisRotation%863777824; C++
inline PureAxisRotation::PureAxisRotation (double phi)
  //## begin PureAxisRotation::PureAxisRotation%863777824.initialization preserve=yes
  : cosphi(cos(phi)),sinphi(sin(phi))
  //## end PureAxisRotation::PureAxisRotation%863777824.initialization
{
  //## begin PureAxisRotation::PureAxisRotation%863777824.body preserve=yes
  //## end PureAxisRotation::PureAxisRotation%863777824.body
}

//## Operation: PureAxisRotation%863777827; C++
inline PureAxisRotation::PureAxisRotation (double cosa, double sina)
  //## begin PureAxisRotation::PureAxisRotation%863777827.initialization preserve=yes
  : cosphi(cosa),sinphi(sina)
  //## end PureAxisRotation::PureAxisRotation%863777827.initialization
{
  //## begin PureAxisRotation::PureAxisRotation%863777827.body preserve=yes
  //## end PureAxisRotation::PureAxisRotation%863777827.body
}



//## Other Operations (inline)
//## Operation: sine%863777825; C++
inline double PureAxisRotation::sine () const
{
  //## begin PureAxisRotation::sine%863777825.body preserve=yes
  return sinphi;
  //## end PureAxisRotation::sine%863777825.body
}

//## Operation: cosine%863777826; C++
inline double PureAxisRotation::cosine () const
{
  //## begin PureAxisRotation::cosine%863777826.body preserve=yes
  return cosphi;
  //## end PureAxisRotation::cosine%863777826.body
}

// Class RotationX 

//## Operation: RotationX%863777828; C++
inline RotationX::RotationX (double phi)
  //## begin RotationX::RotationX%863777828.initialization preserve=yes
  : PureAxisRotation(phi)
  //## end RotationX::RotationX%863777828.initialization
{
  //## begin RotationX::RotationX%863777828.body preserve=yes
  //## end RotationX::RotationX%863777828.body
}

//## Operation: RotationX%863777791; C++
inline RotationX::RotationX (double cosa, double sina)
  //## begin RotationX::RotationX%863777791.initialization preserve=yes
  : PureAxisRotation(cosa,sina)
  //## end RotationX::RotationX%863777791.initialization
{
  //## begin RotationX::RotationX%863777791.body preserve=yes
  //## end RotationX::RotationX%863777791.body
}


// Class RotationY 

//## Operation: RotationY%863777829; C++
inline RotationY::RotationY (double phi)
  //## begin RotationY::RotationY%863777829.initialization preserve=yes
  : PureAxisRotation(phi)
  //## end RotationY::RotationY%863777829.initialization
{
  //## begin RotationY::RotationY%863777829.body preserve=yes
  //## end RotationY::RotationY%863777829.body
}

//## Operation: RotationY%863777802; C++
inline RotationY::RotationY (double cosa, double sina)
  //## begin RotationY::RotationY%863777802.initialization preserve=yes
  : PureAxisRotation(cosa,sina)
  //## end RotationY::RotationY%863777802.initialization
{
  //## begin RotationY::RotationY%863777802.body preserve=yes
  //## end RotationY::RotationY%863777802.body
}


// Class RotationZ 

//## Operation: RotationZ%863777830; C++
inline RotationZ::RotationZ (double phi)
  //## begin RotationZ::RotationZ%863777830.initialization preserve=yes
  : PureAxisRotation(phi)
  //## end RotationZ::RotationZ%863777830.initialization
{
  //## begin RotationZ::RotationZ%863777830.body preserve=yes
  //## end RotationZ::RotationZ%863777830.body
}

//## Operation: RotationZ%863777813; C++
inline RotationZ::RotationZ (double cosa, double sina)
  //## begin RotationZ::RotationZ%863777813.initialization preserve=yes
  : PureAxisRotation(cosa,sina)
  //## end RotationZ::RotationZ%863777813.initialization
{
  //## begin RotationZ::RotationZ%863777813.body preserve=yes
  //## end RotationZ::RotationZ%863777813.body
}


//## begin module%347AA2100262.epilog preserve=yes
//## end module%347AA2100262.epilog


#endif

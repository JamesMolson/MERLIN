//## begin module%347AA31A01C2.cm preserve=no
//## end module%347AA31A01C2.cm

//## begin module%347AA31A01C2.cp preserve=no
//## end module%347AA31A01C2.cp

//## Module: IdentityRotation%347AA31A01C2; Package body
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\IdentityRotation.cpp

//## begin module%347AA31A01C2.includes preserve=yes
//## end module%347AA31A01C2.includes

// IdentityRotation
#include "EuclideanGeometry/IdentityRotation.h"
// GeneralRotation
#include "EuclideanGeometry/GeneralRotation.h"
// AxisRotations
#include "EuclideanGeometry/AxisRotations.h"


//## begin module%347AA31A01C2.declarations preserve=no
//## end module%347AA31A01C2.declarations

//## begin module%347AA31A01C2.additionalDeclarations preserve=yes
//## end module%347AA31A01C2.additionalDeclarations


// Class IdentityRotation 


//## Other Operations (implementation)
//## Operation: inv%863777842; C++
Rot3Drep* IdentityRotation::inv () const
{
  //## begin IdentityRotation::inv%863777842.body preserve=yes
  return const_cast<IdentityRotation*>(this);
  //## end IdentityRotation::inv%863777842.body
}

//## Operation: rotate%863777843; C++
Point3D IdentityRotation::rotate (const Point3D& p) const
{
  //## begin IdentityRotation::rotate%863777843.body preserve=yes
  return p;
  //## end IdentityRotation::rotate%863777843.body
}

//## Operation: rotate%863777844; C++
Vector3D IdentityRotation::rotate (const Vector3D& v) const
{
  //## begin IdentityRotation::rotate%863777844.body preserve=yes
  return v;
  //## end IdentityRotation::rotate%863777844.body
}

//## Operation: isIdentity%863777845; C++
bool IdentityRotation::isIdentity () const
{
  //## begin IdentityRotation::isIdentity%863777845.body preserve=yes
  return true;
  //## end IdentityRotation::isIdentity%863777845.body
}

//## Operation: dot%863777846; C++
Rot3Drep* IdentityRotation::dot (const Rot3Drep& r) const
{
  //## begin IdentityRotation::dot%863777846.body preserve=yes
  return const_cast<Rot3Drep*>(&r);
  //## end IdentityRotation::dot%863777846.body
}

//## Operation: dotBy%863777847; C++
Rot3Drep* IdentityRotation::dotBy (const RotationX& rx) const
{
  //## begin IdentityRotation::dotBy%863777847.body preserve=yes
  return const_cast<RotationX*>(&rx);
  //## end IdentityRotation::dotBy%863777847.body
}

//## Operation: dotBy%863777848; C++
Rot3Drep* IdentityRotation::dotBy (const RotationY& ry) const
{
  //## begin IdentityRotation::dotBy%863777848.body preserve=yes
  return const_cast<RotationY*>(&ry);
  //## end IdentityRotation::dotBy%863777848.body
}

//## Operation: dotBy%863777849; C++
Rot3Drep* IdentityRotation::dotBy (const RotationZ& rz) const
{
  //## begin IdentityRotation::dotBy%863777849.body preserve=yes
  return const_cast<RotationZ*>(&rz);
  //## end IdentityRotation::dotBy%863777849.body
}

//## Operation: dotBy%863777850; C++
Rot3Drep* IdentityRotation::dotBy (const GeneralRotation& r) const
{
  //## begin IdentityRotation::dotBy%863777850.body preserve=yes
  return const_cast<GeneralRotation*>(&r);
  //## end IdentityRotation::dotBy%863777850.body
}

//## Operation: type%863777851; C++
RotationType IdentityRotation::type () const
{
  //## begin IdentityRotation::type%863777851.body preserve=yes
  return ident;
  //## end IdentityRotation::type%863777851.body
}

//## Operation: rotXbyPI%885461006
Rot3Drep* IdentityRotation::rotXbyPI () const
{
  //## begin IdentityRotation::rotXbyPI%885461006.body preserve=yes
	return const_cast<IdentityRotation*>(this);
  //## end IdentityRotation::rotXbyPI%885461006.body
}

//## Operation: rotYbyPI%885461007
Rot3Drep* IdentityRotation::rotYbyPI () const
{
  //## begin IdentityRotation::rotYbyPI%885461007.body preserve=yes
	return const_cast<IdentityRotation*>(this);
  //## end IdentityRotation::rotYbyPI%885461007.body
}

//## Operation: rotZbyPI%885461008
Rot3Drep* IdentityRotation::rotZbyPI () const
{
  //## begin IdentityRotation::rotZbyPI%885461008.body preserve=yes
	return const_cast<IdentityRotation*>(this);
  //## end IdentityRotation::rotZbyPI%885461008.body
}

//## Operation: getMatrix%903600351
RealMatrix& IdentityRotation::getMatrix (RealMatrix& m) const
{
  //## begin IdentityRotation::getMatrix%903600351.body preserve=yes
	return m.copy(IdentityMatrix(3));
  //## end IdentityRotation::getMatrix%903600351.body
}

//## begin module%347AA31A01C2.epilog preserve=yes
//## end module%347AA31A01C2.epilog

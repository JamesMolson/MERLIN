//## begin module%347AA247024E.cm preserve=no
//## end module%347AA247024E.cm

//## begin module%347AA247024E.cp preserve=no
//## end module%347AA247024E.cp

//## Module: AxisRotations%347AA247024E; Package body
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\AxisRotations.cpp

//## begin module%347AA247024E.includes preserve=yes
#include "EuclideanGeometry/IdentityRotation.h"
#include "EuclideanGeometry/RotationMatrix.h"
//## end module%347AA247024E.includes

// GeneralRotation
#include "EuclideanGeometry/GeneralRotation.h"
// AxisRotations
#include "EuclideanGeometry/AxisRotations.h"


//## begin module%347AA247024E.declarations preserve=no
//## end module%347AA247024E.declarations

//## begin module%347AA247024E.additionalDeclarations preserve=yes
//## end module%347AA247024E.additionalDeclarations


// Class PureAxisRotation 




//## Other Operations (implementation)
//## Operation: angle%863777790; C++
double PureAxisRotation::angle () const
{
  //## begin PureAxisRotation::angle%863777790.body preserve=yes
  return atan2(sinphi,cosphi);
  //## end PureAxisRotation::angle%863777790.body
}

// Class RotationX 


//## Other Operations (implementation)
//## Operation: inv%863777792; C++
Rot3Drep* RotationX::inv () const
{
  //## begin RotationX::inv%863777792.body preserve=yes
  return new RotationX(cosine(),-sine());
  //## end RotationX::inv%863777792.body
}

//## Operation: rotate%863777793; C++
Point3D RotationX::rotate (const Point3D& p) const
{
  //## begin RotationX::rotate%863777793.body preserve=yes
  return Point3D(p.x,p.y*cosine()+p.z*sine(),-p.y*sine()+p.z*cosine());
  //## end RotationX::rotate%863777793.body
}

//## Operation: rotate%863777794; C++
Vector3D RotationX::rotate (const Vector3D& v) const
{
  //## begin RotationX::rotate%863777794.body preserve=yes
  return Vector3D(v.x,v.y*cosine()+v.z*sine(),-v.y*sine()+v.z*cosine());
  //## end RotationX::rotate%863777794.body
}

//## Operation: dot%863777795; C++
Rot3Drep* RotationX::dot (const Rot3Drep& r) const
{
  //## begin RotationX::dot%863777795.body preserve=yes
  return r.dotBy(*this);
  //## end RotationX::dot%863777795.body
}

//## Operation: dotBy%863777796; C++
Rot3Drep* RotationX::dotBy (const RotationX& rx) const
{
  //## begin RotationX::dotBy%863777796.body preserve=yes
  double ncos = cosine()*rx.cosine()-sine()*rx.sine();
  if(ncos==1)
  	return new IdentityRotation();
  else {
		double nsin = sine()*rx.cosine()+cosine()*rx.sine();
  	return new RotationX(ncos,nsin);
  }
  //## end RotationX::dotBy%863777796.body
}

//## Operation: dotBy%863777797; C++
Rot3Drep* RotationX::dotBy (const RotationY& ry) const
{
  //## begin RotationX::dotBy%863777797.body preserve=yes
  return new GeneralRotation(ry,*this);
  //## end RotationX::dotBy%863777797.body
}

//## Operation: dotBy%863777798; C++
Rot3Drep* RotationX::dotBy (const RotationZ& rz) const
{
  //## begin RotationX::dotBy%863777798.body preserve=yes
  return new GeneralRotation(rz,*this);
  //## end RotationX::dotBy%863777798.body
}

//## Operation: dotBy%863777799; C++
Rot3Drep* RotationX::dotBy (const GeneralRotation& r) const
{
  //## begin RotationX::dotBy%863777799.body preserve=yes
  return new GeneralRotation(r,*this);
  //## end RotationX::dotBy%863777799.body
}

//## Operation: type%863777800; C++
RotationType RotationX::type () const
{
  //## begin RotationX::type%863777800.body preserve=yes
  return xrot;
  //## end RotationX::type%863777800.body
}

//## Operation: isXrot%863777801; C++
bool RotationX::isXrot () const
{
  //## begin RotationX::isXrot%863777801.body preserve=yes
  return true;
  //## end RotationX::isXrot%863777801.body
}

//## Operation: rotXbyPI%885461013
Rot3Drep* RotationX::rotXbyPI () const
{
  //## begin RotationX::rotXbyPI%885461013.body preserve=yes
	return const_cast<RotationX*>(this);
  //## end RotationX::rotXbyPI%885461013.body
}

//## Operation: rotYbyPI%885461014
Rot3Drep* RotationX::rotYbyPI () const
{
  //## begin RotationX::rotYbyPI%885461014.body preserve=yes
	return new RotationX(cosine(),-sine());
  //## end RotationX::rotYbyPI%885461014.body
}

//## Operation: rotZbyPI%885461015
Rot3Drep* RotationX::rotZbyPI () const
{
  //## begin RotationX::rotZbyPI%885461015.body preserve=yes
	return new RotationX(cosine(),-sine());
  //## end RotationX::rotZbyPI%885461015.body
}

//## Operation: getMatrix%903600353
RealMatrix& RotationX::getMatrix (RealMatrix& m) const
{
  //## begin RotationX::getMatrix%903600353.body preserve=yes
	return m.copy(DECL_XROT(cosine(),sine()));
  //## end RotationX::getMatrix%903600353.body
}

// Class RotationY 


//## Other Operations (implementation)
//## Operation: inv%863777803; C++
Rot3Drep* RotationY::inv () const
{
  //## begin RotationY::inv%863777803.body preserve=yes
  return new RotationY(cosine(),-sine());
  //## end RotationY::inv%863777803.body
}

//## Operation: rotate%863777804; C++
Point3D RotationY::rotate (const Point3D& p) const
{
  //## begin RotationY::rotate%863777804.body preserve=yes
  return Point3D(p.x*cosine()-p.z*sine(),p.y,p.z*cosine()+p.x*sine());
  //## end RotationY::rotate%863777804.body
}

//## Operation: rotate%863777805; C++
Vector3D RotationY::rotate (const Vector3D& v) const
{
  //## begin RotationY::rotate%863777805.body preserve=yes
  return Vector3D(v.x*cosine()-v.z*sine(),v.y,v.z*cosine()+v.x*sine());
  //## end RotationY::rotate%863777805.body
}

//## Operation: dot%863777806; C++
Rot3Drep* RotationY::dot (const Rot3Drep& r) const
{
  //## begin RotationY::dot%863777806.body preserve=yes
  return r.dotBy(*this);
  //## end RotationY::dot%863777806.body
}

//## Operation: dotBy%863777807; C++
Rot3Drep* RotationY::dotBy (const RotationX& rx) const
{
  //## begin RotationY::dotBy%863777807.body preserve=yes
  return new GeneralRotation(rx,*this);
  //## end RotationY::dotBy%863777807.body
}

//## Operation: dotBy%863777808; C++
Rot3Drep* RotationY::dotBy (const RotationY& ry) const
{
  //## begin RotationY::dotBy%863777808.body preserve=yes
  double ncos = cosine()*ry.cosine()-sine()*ry.sine();
  if(ncos==1)
  	return new IdentityRotation();
  else {
		double nsin = sine()*ry.cosine()+cosine()*ry.sine();
  	return new RotationY(ncos,nsin);
  }
  //## end RotationY::dotBy%863777808.body
}

//## Operation: dotBy%863777809; C++
Rot3Drep* RotationY::dotBy (const RotationZ& rz) const
{
  //## begin RotationY::dotBy%863777809.body preserve=yes
  return new GeneralRotation(rz,*this);
  //## end RotationY::dotBy%863777809.body
}

//## Operation: dotBy%863777810; C++
Rot3Drep* RotationY::dotBy (const GeneralRotation& r) const
{
  //## begin RotationY::dotBy%863777810.body preserve=yes
  return new GeneralRotation(r,*this);
  //## end RotationY::dotBy%863777810.body
}

//## Operation: type%863777811; C++
RotationType RotationY::type () const
{
  //## begin RotationY::type%863777811.body preserve=yes
  return yrot;
  //## end RotationY::type%863777811.body
}

//## Operation: isYrot%863777812; C++
bool RotationY::isYrot () const
{
  //## begin RotationY::isYrot%863777812.body preserve=yes
  return true;
  //## end RotationY::isYrot%863777812.body
}

//## Operation: rotXbyPI%885461016
Rot3Drep* RotationY::rotXbyPI () const
{
  //## begin RotationY::rotXbyPI%885461016.body preserve=yes
	return new RotationY(cosine(),-sine());
  //## end RotationY::rotXbyPI%885461016.body
}

//## Operation: rotYbyPI%885461017
Rot3Drep* RotationY::rotYbyPI () const
{
  //## begin RotationY::rotYbyPI%885461017.body preserve=yes
	return const_cast<RotationY*>(this);
  //## end RotationY::rotYbyPI%885461017.body
}

//## Operation: rotZbyPI%885461018
Rot3Drep* RotationY::rotZbyPI () const
{
  //## begin RotationY::rotZbyPI%885461018.body preserve=yes
	return new RotationY(cosine(),-sine());
  //## end RotationY::rotZbyPI%885461018.body
}

//## Operation: getMatrix%903600354
RealMatrix& RotationY::getMatrix (RealMatrix& m) const
{
  //## begin RotationY::getMatrix%903600354.body preserve=yes
	return m.copy(DECL_YROT(cosine(),sine()));
  //## end RotationY::getMatrix%903600354.body
}

// Class RotationZ 


//## Other Operations (implementation)
//## Operation: inv%863777814; C++
Rot3Drep* RotationZ::inv () const
{
  //## begin RotationZ::inv%863777814.body preserve=yes
  return new RotationZ(cosine(),-sine());
  //## end RotationZ::inv%863777814.body
}

//## Operation: rotate%863777815; C++
Point3D RotationZ::rotate (const Point3D& p) const
{
  //## begin RotationZ::rotate%863777815.body preserve=yes
  return Point3D(p.x*cosine()+p.y*sine(),p.y*cosine()-p.x*sine(),p.z);
  //## end RotationZ::rotate%863777815.body
}

//## Operation: rotate%863777816; C++
Vector3D RotationZ::rotate (const Vector3D& v) const
{
  //## begin RotationZ::rotate%863777816.body preserve=yes
  return Vector3D(v.x*cosine()+v.y*sine(),v.y*cosine()-v.x*sine(),v.z);
  //## end RotationZ::rotate%863777816.body
}

//## Operation: dot%863777817; C++
Rot3Drep* RotationZ::dot (const Rot3Drep& r) const
{
  //## begin RotationZ::dot%863777817.body preserve=yes
  return r.dotBy(*this);
  //## end RotationZ::dot%863777817.body
}

//## Operation: dotBy%863777818; C++
Rot3Drep* RotationZ::dotBy (const RotationX& rx) const
{
  //## begin RotationZ::dotBy%863777818.body preserve=yes
  return new GeneralRotation(rx,*this);
  //## end RotationZ::dotBy%863777818.body
}

//## Operation: dotBy%863777819; C++
Rot3Drep* RotationZ::dotBy (const RotationY& ry) const
{
  //## begin RotationZ::dotBy%863777819.body preserve=yes
  return new GeneralRotation(ry,*this);
  //## end RotationZ::dotBy%863777819.body
}

//## Operation: dotBy%863777820; C++
Rot3Drep* RotationZ::dotBy (const RotationZ& rz) const
{
  //## begin RotationZ::dotBy%863777820.body preserve=yes
  double ncos = cosine()*rz.cosine()-sine()*rz.sine();
  if(ncos==1)
  	return new IdentityRotation();
  else {
		double nsin = sine()*rz.cosine()+cosine()*rz.sine();
  	return new RotationZ(ncos,nsin);
  }
  //## end RotationZ::dotBy%863777820.body
}

//## Operation: dotBy%863777821; C++
Rot3Drep* RotationZ::dotBy (const GeneralRotation& r) const
{
  //## begin RotationZ::dotBy%863777821.body preserve=yes
  return new GeneralRotation(r,*this);
  //## end RotationZ::dotBy%863777821.body
}

//## Operation: type%863777822; C++
RotationType RotationZ::type () const
{
  //## begin RotationZ::type%863777822.body preserve=yes
  return zrot;
  //## end RotationZ::type%863777822.body
}

//## Operation: isZrot%863777823; C++
bool RotationZ::isZrot () const
{
  //## begin RotationZ::isZrot%863777823.body preserve=yes
  return true;
  //## end RotationZ::isZrot%863777823.body
}

//## Operation: rotXbyPI%885461019
Rot3Drep* RotationZ::rotXbyPI () const
{
  //## begin RotationZ::rotXbyPI%885461019.body preserve=yes
	return new RotationZ(cosine(),-sine());
  //## end RotationZ::rotXbyPI%885461019.body
}

//## Operation: rotYbyPI%885461020
Rot3Drep* RotationZ::rotYbyPI () const
{
  //## begin RotationZ::rotYbyPI%885461020.body preserve=yes
	return new RotationZ(cosine(),-sine());
  //## end RotationZ::rotYbyPI%885461020.body
}

//## Operation: rotZbyPI%885461021
Rot3Drep* RotationZ::rotZbyPI () const
{
  //## begin RotationZ::rotZbyPI%885461021.body preserve=yes
	return const_cast<RotationZ*>(this);
  //## end RotationZ::rotZbyPI%885461021.body
}

//## Operation: getMatrix%903600355
RealMatrix& RotationZ::getMatrix (RealMatrix& m) const
{
  //## begin RotationZ::getMatrix%903600355.body preserve=yes
	return m.copy(DECL_ZROT(cosine(),sine()));
  //## end RotationZ::getMatrix%903600355.body
}

//## begin module%347AA247024E.epilog preserve=yes
//## end module%347AA247024E.epilog

//## begin module%347AA2A10186.cm preserve=no
//## end module%347AA2A10186.cm

//## begin module%347AA2A10186.cp preserve=no
//## end module%347AA2A10186.cp

//## Module: GeneralRotation%347AA2A10186; Package body
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\GeneralRotation.cpp

//## begin module%347AA2A10186.includes preserve=yes
// memcpy
#include <cstring>
// blas template routines
#include "TLAS/LinearAlgebra.h"
// rotation matrix construction
#include "EuclideanGeometry/RotationMatrix.h"
//## end module%347AA2A10186.includes

// GeneralRotation
#include "EuclideanGeometry/GeneralRotation.h"
//## begin module%347AA2A10186.declarations preserve=no
//## end module%347AA2A10186.declarations

//## begin module%347AA2A10186.additionalDeclarations preserve=yes
//## end module%347AA2A10186.additionalDeclarations


// Class GeneralRotation 


//## Operation: GeneralRotation%863777831; C++
GeneralRotation::GeneralRotation (const GeneralRotation& gr)
  //## begin GeneralRotation::GeneralRotation%863777831.initialization preserve=yes
:m(gr.m)
  //## end GeneralRotation::GeneralRotation%863777831.initialization
{
  //## begin GeneralRotation::GeneralRotation%863777831.body preserve=yes
  //## end GeneralRotation::GeneralRotation%863777831.body
}

//## Operation: GeneralRotation%863777853; C++
GeneralRotation::GeneralRotation (const RotationX& rx, const RotationY& ry)
  //## begin GeneralRotation::GeneralRotation%863777853.initialization preserve=yes
:m(3,3)
  //## end GeneralRotation::GeneralRotation%863777853.initialization
{
  //## begin GeneralRotation::GeneralRotation%863777853.body preserve=yes
	
	m(0,0) = ry.cosine();
	m(0,1) = 0;
	m(0,2) = -ry.sine();
	
	m(1,0) = rx.sine()*ry.sine();
	m(1,1) = rx.cosine();
	m(1,2) = rx.sine()*ry.cosine();
	
	m(2,0) = rx.cosine()*ry.sine();
	m(2,1) = -rx.sine();
	m(2,2) = rx.cosine()*ry.cosine();
	
  //## end GeneralRotation::GeneralRotation%863777853.body
}

//## Operation: GeneralRotation%863777854; C++
GeneralRotation::GeneralRotation (const RotationX& rx, const RotationZ& rz)
  //## begin GeneralRotation::GeneralRotation%863777854.initialization preserve=yes
:m(3,3)
  //## end GeneralRotation::GeneralRotation%863777854.initialization
{
  //## begin GeneralRotation::GeneralRotation%863777854.body preserve=yes
	
	m(0,0) = rz.cosine();
	m(0,1) = rz.sine();
	m(0,2) = 0;
	
	m(1,0) = -rx.cosine()*rz.sine();
	m(1,1) = rx.cosine()*rz.cosine();
	m(1,2) = rx.sine();
	
	m(2,0) = rx.sine()*rz.sine();
	m(2,1) = -rz.cosine()*rx.sine();
	m(2,2) = rx.cosine();
	
  //## end GeneralRotation::GeneralRotation%863777854.body
}

//## Operation: GeneralRotation%863777855; C++
GeneralRotation::GeneralRotation (const RotationY& ry, const RotationX& rx)
  //## begin GeneralRotation::GeneralRotation%863777855.initialization preserve=yes
:m(3,3)
  //## end GeneralRotation::GeneralRotation%863777855.initialization
{
  //## begin GeneralRotation::GeneralRotation%863777855.body preserve=yes
	
	m(0,0) = ry.cosine();
	m(0,1) = rx.sine()*ry.sine();
	m(0,2) = -rx.cosine()*ry.sine();
	
	m(1,0) = 0;
	m(1,1) = rx.cosine();
	m(1,2) = rx.sine();
	
	m(2,0) = ry.sine();
	m(2,1) = -ry.cosine()*rx.sine();
	m(2,2) = rx.cosine()*ry.cosine();
	
  //## end GeneralRotation::GeneralRotation%863777855.body
}

//## Operation: GeneralRotation%863777856; C++
GeneralRotation::GeneralRotation (const RotationY& ry, const RotationZ& rz)
  //## begin GeneralRotation::GeneralRotation%863777856.initialization preserve=yes
:m(3,3)
  //## end GeneralRotation::GeneralRotation%863777856.initialization
{
  //## begin GeneralRotation::GeneralRotation%863777856.body preserve=yes
	
	m(0,0) = ry.cosine()*rz.cosine();
	m(0,1) = ry.cosine()*rz.sine();
	m(0,2) = -ry.sine();
	
	m(1,0) = -rz.sine();
	m(1,1) = rz.cosine();
	m(1,2) = 0;
	
	m(2,0) = rz.cosine()*ry.sine();
	m(2,1) = ry.sine()*rz.sine();
	m(2,2) = ry.cosine();
	
  //## end GeneralRotation::GeneralRotation%863777856.body
}

//## Operation: GeneralRotation%863777857; C++
GeneralRotation::GeneralRotation (const RotationZ& rz, const RotationX& rx)
  //## begin GeneralRotation::GeneralRotation%863777857.initialization preserve=yes
:m(3,3)
  //## end GeneralRotation::GeneralRotation%863777857.initialization
{
  //## begin GeneralRotation::GeneralRotation%863777857.body preserve=yes
	
	m(0,0) = rz.cosine();
	m(0,1) = rx.cosine()*rz.sine();
	m(0,2) = rx.sine()*rz.sine();
	
	m(1,0) = -rz.sine();
	m(1,1) = rx.cosine()*rz.cosine();
	m(1,2) = rz.cosine()*rx.sine();
	
	m(2,0) = 0;
	m(2,1) = -rx.sine();
	m(2,2) = rx.cosine();
	
  //## end GeneralRotation::GeneralRotation%863777857.body
}

//## Operation: GeneralRotation%863777858; C++
GeneralRotation::GeneralRotation (const RotationZ& rz, const RotationY& ry)
  //## begin GeneralRotation::GeneralRotation%863777858.initialization preserve=yes
:m(3,3)
  //## end GeneralRotation::GeneralRotation%863777858.initialization
{
  //## begin GeneralRotation::GeneralRotation%863777858.body preserve=yes
	
	m(0,0) = ry.cosine()*rz.cosine();
	m(0,1) = rz.sine();
	m(0,2) = -rz.cosine()*ry.sine();
	
	m(1,0) = -ry.cosine()*rz.sine();
	m(1,1) = rz.cosine();
	m(1,2) = ry.sine()*rz.sine();
	
	m(2,0) = ry.sine();
	m(2,1) = 0;
	m(2,2) = ry.cosine();
	
  //## end GeneralRotation::GeneralRotation%863777858.body
}

//## Operation: GeneralRotation%863777859; C++
GeneralRotation::GeneralRotation (const GeneralRotation& r, const RotationX& rx)
  //## begin GeneralRotation::GeneralRotation%863777859.initialization preserve=yes
: m(r.m*DECL_XROT(rx.cosine(),rx.sine()))
  //## end GeneralRotation::GeneralRotation%863777859.initialization
{
  //## begin GeneralRotation::GeneralRotation%863777859.body preserve=yes
  //## end GeneralRotation::GeneralRotation%863777859.body
}

//## Operation: GeneralRotation%863777860; C++
GeneralRotation::GeneralRotation (const GeneralRotation& r, const RotationY& ry)
  //## begin GeneralRotation::GeneralRotation%863777860.initialization preserve=yes
: m(r.m*DECL_YROT(ry.cosine(),ry.sine()))
  //## end GeneralRotation::GeneralRotation%863777860.initialization
{
  //## begin GeneralRotation::GeneralRotation%863777860.body preserve=yes
  //## end GeneralRotation::GeneralRotation%863777860.body
}

//## Operation: GeneralRotation%863777861; C++
GeneralRotation::GeneralRotation (const GeneralRotation& r, const RotationZ& rz)
  //## begin GeneralRotation::GeneralRotation%863777861.initialization preserve=yes
: m(r.m*DECL_ZROT(rz.cosine(),rz.sine()))
  //## end GeneralRotation::GeneralRotation%863777861.initialization
{
  //## begin GeneralRotation::GeneralRotation%863777861.body preserve=yes
  //## end GeneralRotation::GeneralRotation%863777861.body
}



//## Other Operations (implementation)
//## Operation: inv%863777832; C++
Rot3Drep* GeneralRotation::inv () const
{
  //## begin GeneralRotation::inv%863777832.body preserve=yes
	GeneralRotation *newrot = new GeneralRotation;
	for(int i=0; i<3; i++)
		for(int j=0; j<=i; j++) {
			if(i==j)
				newrot->m(i,i) = m(i,i);
			else {
				newrot->m(i,j) = m(j,i);
				newrot->m(j,i) = m(i,j);
			}
		}
		return newrot;
  //## end GeneralRotation::inv%863777832.body
}

//## Operation: rotate%863777833; C++
Point3D GeneralRotation::rotate (const Point3D& p) const
{
  //## begin GeneralRotation::rotate%863777833.body preserve=yes
	double x = m(0,0)*p.x+m(0,1)*p.y+m(0,2)*p.z;
	double y = m(1,0)*p.x+m(1,1)*p.y+m(1,2)*p.z;
	double z = m(2,0)*p.x+m(2,1)*p.y+m(2,2)*p.z;
	return Point3D(x,y,z);
  //## end GeneralRotation::rotate%863777833.body
}

//## Operation: rotate%863777834; C++
Vector3D GeneralRotation::rotate (const Vector3D& v) const
{
  //## begin GeneralRotation::rotate%863777834.body preserve=yes
	double x = m(0,0)*v.x+m(0,1)*v.y+m(0,2)*v.z;
	double y = m(1,0)*v.x+m(1,1)*v.y+m(1,2)*v.z;
	double z = m(2,0)*v.x+m(2,1)*v.y+m(2,2)*v.z;
	return Vector3D(x,y,z);
  //## end GeneralRotation::rotate%863777834.body
}

//## Operation: dot%863777835; C++
Rot3Drep* GeneralRotation::dot (const Rot3Drep& r) const
{
  //## begin GeneralRotation::dot%863777835.body preserve=yes
	return r.dotBy(*this);
  //## end GeneralRotation::dot%863777835.body
}

//## Operation: dotBy%863777836; C++
Rot3Drep* GeneralRotation::dotBy (const RotationX& rx) const
{
  //## begin GeneralRotation::dotBy%863777836.body preserve=yes
	return new GeneralRotation(DECL_XROT(rx.cosine(),rx.sine())*m);
  //## end GeneralRotation::dotBy%863777836.body
}

//## Operation: dotBy%863777837; C++
Rot3Drep* GeneralRotation::dotBy (const RotationY& ry) const
{
  //## begin GeneralRotation::dotBy%863777837.body preserve=yes
	return new GeneralRotation(DECL_YROT(ry.cosine(),ry.sine())*m);
  //## end GeneralRotation::dotBy%863777837.body
}

//## Operation: dotBy%863777838; C++
Rot3Drep* GeneralRotation::dotBy (const RotationZ& rz) const
{
  //## begin GeneralRotation::dotBy%863777838.body preserve=yes
	return new GeneralRotation(DECL_ZROT(rz.cosine(),rz.sine())*m);
  //## end GeneralRotation::dotBy%863777838.body
}

//## Operation: dotBy%863777839; C++
Rot3Drep* GeneralRotation::dotBy (const GeneralRotation& r) const
{
  //## begin GeneralRotation::dotBy%863777839.body preserve=yes
	return new GeneralRotation((r.m)*m);
  //## end GeneralRotation::dotBy%863777839.body
}

//## Operation: type%863777840; C++
RotationType GeneralRotation::type () const
{
  //## begin GeneralRotation::type%863777840.body preserve=yes
	return mixed;
  //## end GeneralRotation::type%863777840.body
}

//## Operation: isIdentity%864204481; C++
bool GeneralRotation::isIdentity () const
{
  //## begin GeneralRotation::isIdentity%864204481.body preserve=yes
	return m(0,0)==1.0 && m(1,1)==1.0 && m(2,2)==1.0;
  //## end GeneralRotation::isIdentity%864204481.body
}

//## Operation: isXrot%864204482; C++
bool GeneralRotation::isXrot () const
{
  //## begin GeneralRotation::isXrot%864204482.body preserve=yes
	return m(0,0)==1.0 && m(0,1)==0.0 && m(0,2)==0.0;
  //## end GeneralRotation::isXrot%864204482.body
}

//## Operation: isYrot%864204483; C++
bool GeneralRotation::isYrot () const
{
  //## begin GeneralRotation::isYrot%864204483.body preserve=yes
	return m(1,0)==0.0 && m(1,1)==1.0 && m(1,2)==0.0;
  //## end GeneralRotation::isYrot%864204483.body
}

//## Operation: isZrot%864204484; C++
bool GeneralRotation::isZrot () const
{
  //## begin GeneralRotation::isZrot%864204484.body preserve=yes
	return m(2,0)==0.0 && m(2,1)==0.0 && m(2,2)==1.0;
  //## end GeneralRotation::isZrot%864204484.body
}

//## Operation: rotXbyPI%885461009
Rot3Drep* GeneralRotation::rotXbyPI () const
{
  //## begin GeneralRotation::rotXbyPI%885461009.body preserve=yes
	RealMatrix R(m);
	R(0,1)*=-1;
	R(0,2)*=-1;
	R(1,0)*=-1;
	R(2,0)*=-1;
	return new GeneralRotation(R);
  //## end GeneralRotation::rotXbyPI%885461009.body
}

//## Operation: rotYbyPI%885461010
Rot3Drep* GeneralRotation::rotYbyPI () const
{
  //## begin GeneralRotation::rotYbyPI%885461010.body preserve=yes
	RealMatrix R(m);
	R(0,1)*=-1;
	R(1,0)*=-1;
	R(1,2)*=-1;
	R(2,1)*=-1;
	return new GeneralRotation(R);
  //## end GeneralRotation::rotYbyPI%885461010.body
}

//## Operation: rotZbyPI%885461011
Rot3Drep* GeneralRotation::rotZbyPI () const
{
  //## begin GeneralRotation::rotZbyPI%885461011.body preserve=yes
	RealMatrix R(m);
	R(0,2)*=-1;
	R(1,2)*=-1;
	R(2,0)*=-1;
	R(2,1)*=-1;
	return new GeneralRotation(R);
  //## end GeneralRotation::rotZbyPI%885461011.body
}

//## Operation: getMatrix%903600352
RealMatrix& GeneralRotation::getMatrix (RealMatrix& m) const
{
  //## begin GeneralRotation::getMatrix%903600352.body preserve=yes
	return m.copy(this->m);
  //## end GeneralRotation::getMatrix%903600352.body
}

//## begin module%347AA2A10186.epilog preserve=yes
//## end module%347AA2A10186.epilog

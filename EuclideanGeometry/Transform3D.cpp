//## begin module%3379733901EE.cm preserve=no
//## end module%3379733901EE.cm

//## begin module%3379733901EE.cp preserve=no
//## end module%3379733901EE.cp

//## Module: Transform3D%3379733901EE; Package body
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\Transform3D.cpp

//## begin module%3379733901EE.includes preserve=yes
//## end module%3379733901EE.includes

// Transform3D
#include "EuclideanGeometry/Transform3D.h"
//## begin module%3379733901EE.declarations preserve=no
//## end module%3379733901EE.declarations

//## begin module%3379733901EE.additionalDeclarations preserve=yes
//## end module%3379733901EE.additionalDeclarations


// Class Transform3D 





//## Other Operations (implementation)
//## Operation: operator*=%864215968; C++
//## Qualification: inline
const Transform3D& Transform3D::operator *= (const Transform3D& t)
{
  //## begin Transform3D::operator*=%864215968.body preserve=yes
  // this operation represents t*this
  x0+=r.inv()*t.x0;
  r = t.r*r;
  return *this;
  //## end Transform3D::operator*=%864215968.body
}

//## Operation: inv%864215969; C++
//## Qualification: const inline
Transform3D Transform3D::inv () const
{
  //## begin Transform3D::inv%864215969.body preserve=yes
  return Transform3D(-(r*x0),r.inv());
  //## end Transform3D::inv%864215969.body
}

//## Operation: invert%864215970; C++
const Transform3D& Transform3D::invert ()
{
  //## begin Transform3D::invert%864215970.body preserve=yes
  x0 = -(r*x0);
  r = r.inv();
  return *this;
  //## end Transform3D::invert%864215970.body
}

//## Operation: rotationX%864215971; C++
//## Qualification: static
Transform3D Transform3D::rotationX (double angle)
{
  //## begin Transform3D::rotationX%864215971.body preserve=yes
  return Transform3D(Point3D(0,0,0),Rotation3D::rotationX(angle));
  //## end Transform3D::rotationX%864215971.body
}

//## Operation: rotationY%864215972; C++
//## Qualification: static
Transform3D Transform3D::rotationY (double angle)
{
  //## begin Transform3D::rotationY%864215972.body preserve=yes
  return Transform3D(Point3D(0,0,0),Rotation3D::rotationY(angle));
  //## end Transform3D::rotationY%864215972.body
}

//## Operation: rotationZ%864215973; C++
//## Qualification: static
Transform3D Transform3D::rotationZ (double angle)
{
  //## begin Transform3D::rotationZ%864215973.body preserve=yes
  return Transform3D(Point3D(0,0,0),Rotation3D::rotationZ(angle));
  //## end Transform3D::rotationZ%864215973.body
}

//## Operation: translation%864215974; C++
//## Qualification: static
Transform3D Transform3D::translation (double dx, double dy, double dz)
{
  //## begin Transform3D::translation%864215974.body preserve=yes
  return Transform3D(Point3D(dx,dy,dz),Rotation3D::identity());
  //## end Transform3D::translation%864215974.body
}

//## begin module%3379733901EE.epilog preserve=yes
//## end module%3379733901EE.epilog

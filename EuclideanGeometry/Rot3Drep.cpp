//## begin module%347AA1E502C6.cm preserve=no
//## end module%347AA1E502C6.cm

//## begin module%347AA1E502C6.cp preserve=no
//## end module%347AA1E502C6.cp

//## Module: Rot3Drep%347AA1E502C6; Package body
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\Rot3Drep.cpp

//## begin module%347AA1E502C6.includes preserve=yes
//## end module%347AA1E502C6.includes

// Rot3Drep
#include "EuclideanGeometry/Rot3Drep.h"
// IdentityRotation
#include "EuclideanGeometry/IdentityRotation.h"
// GeneralRotation
#include "EuclideanGeometry/GeneralRotation.h"
// AxisRotations
#include "EuclideanGeometry/AxisRotations.h"


//## begin module%347AA1E502C6.declarations preserve=no
//## end module%347AA1E502C6.declarations

//## begin module%347AA1E502C6.additionalDeclarations preserve=yes
//## end module%347AA1E502C6.additionalDeclarations


// Class Rot3Drep 



//## Operation: Rot3Drep%863777755; C++
Rot3Drep::Rot3Drep ()
  //## begin Rot3Drep::Rot3Drep%863777755.hasinit preserve=no
      : refc(0)
  //## end Rot3Drep::Rot3Drep%863777755.hasinit
  //## begin Rot3Drep::Rot3Drep%863777755.initialization preserve=yes
  //## end Rot3Drep::Rot3Drep%863777755.initialization
{
  //## begin Rot3Drep::Rot3Drep%863777755.body preserve=yes
  //## end Rot3Drep::Rot3Drep%863777755.body
}


//## Operation: ~Rot3Drep%863777756; C++
Rot3Drep::~Rot3Drep ()
{
  //## begin Rot3Drep::~Rot3Drep%863777756.body preserve=yes
  //## end Rot3Drep::~Rot3Drep%863777756.body
}



//## Other Operations (implementation)
//## Operation: isIdentity%863777757; C++
bool Rot3Drep::isIdentity () const
{
  //## begin Rot3Drep::isIdentity%863777757.body preserve=yes
  return false;
  //## end Rot3Drep::isIdentity%863777757.body
}

//## Operation: isXrot%863777758; C++
bool Rot3Drep::isXrot () const
{
  //## begin Rot3Drep::isXrot%863777758.body preserve=yes
  return false;
  //## end Rot3Drep::isXrot%863777758.body
}

//## Operation: isYrot%863777759; C++
bool Rot3Drep::isYrot () const
{
  //## begin Rot3Drep::isYrot%863777759.body preserve=yes
  return false;
  //## end Rot3Drep::isYrot%863777759.body
}

//## Operation: isZrot%863777760; C++
bool Rot3Drep::isZrot () const
{
  //## begin Rot3Drep::isZrot%863777760.body preserve=yes
  return false;
  //## end Rot3Drep::isZrot%863777760.body
}

//## Operation: identity%863777761; C++
Rot3Drep* Rot3Drep::identity ()
{
  //## begin Rot3Drep::identity%863777761.body preserve=yes
  return new IdentityRotation;
  //## end Rot3Drep::identity%863777761.body
}

//## Operation: rotationX%863777762; C++
Rot3Drep* Rot3Drep::rotationX (double angle)
{
  //## begin Rot3Drep::rotationX%863777762.body preserve=yes
  if(angle==0)
  	return new IdentityRotation;
  else
  	return new RotationX(angle);
  //## end Rot3Drep::rotationX%863777762.body
}

//## Operation: rotationY%863777763; C++
Rot3Drep* Rot3Drep::rotationY (double angle)
{
  //## begin Rot3Drep::rotationY%863777763.body preserve=yes
  if(angle==0)
  	return new IdentityRotation;
  else
  	return new RotationY(angle);
  //## end Rot3Drep::rotationY%863777763.body
}

//## Operation: rotationZ%863777764; C++
Rot3Drep* Rot3Drep::rotationZ (double angle)
{
  //## begin Rot3Drep::rotationZ%863777764.body preserve=yes
  if(angle==0)
  	return new IdentityRotation;
  else
  	return new RotationZ(angle);
  //## end Rot3Drep::rotationZ%863777764.body
}

//## begin module%347AA1E502C6.epilog preserve=yes
//## end module%347AA1E502C6.epilog

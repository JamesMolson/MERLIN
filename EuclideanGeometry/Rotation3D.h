//## begin module%337972F3025C.cm preserve=no
//## end module%337972F3025C.cm

//## begin module%337972F3025C.cp preserve=no
//## end module%337972F3025C.cp

//## Module: Rotation3D%337972F3025C; Package specification
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\Rotation3D.h

#ifndef Rotation3D_h
#define Rotation3D_h 1

//## begin module%337972F3025C.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%337972F3025C.additionalIncludes

//## begin module%337972F3025C.includes preserve=yes
//## end module%337972F3025C.includes

// LinearAlgebra
#include "TLAS/LinearAlgebra.h"
// Space3D
#include "EuclideanGeometry/Space3D.h"
// RotationType
#include "EuclideanGeometry/RotationType.h"
// Rot3Drep
#include "EuclideanGeometry/Rot3Drep.h"
//## begin module%337972F3025C.declarations preserve=no
//## end module%337972F3025C.declarations

//## begin module%337972F3025C.additionalDeclarations preserve=yes
//## end module%337972F3025C.additionalDeclarations


//## Class: Rotation3D%337B3DB9003C
//	A general 3 dimensional rotation. Rotation3D objects can
//	be multiplied together, and can also act on points or
//	vectors in space.  The rotations can be thought of as a
//	rotation of a set of right-handed coodinate axes.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3398129C01B2;RotationType { -> }
//## Uses: operates on%3398129C01D0;Point3D { -> }
//## Uses: operates on%3398129C01DC;Vector3D { -> }
//## Uses: <unnamed>%3398129C0203; { -> }
//## Uses: <unnamed>%35DBD77500A5;RealMatrix { -> }

class Rotation3D 
{
  public:
    //## Constructors (specified)
      //## Operation: Rotation3D%863777774; C++
      //	Default constructor. Creates an identity (null) rotation.
      Rotation3D ();

      //## Operation: Rotation3D%863777775; C++
      //	Copy constructor.
      Rotation3D (const Rotation3D& R);

    //## Destructor (specified)
      //## Operation: ~Rotation3D%863777776; C++
      //	Destructor.
      ~Rotation3D ();


    //## Other Operations (specified)
      //## Operation: operator=%863777777; C++
      //	Copy assignment.
      const Rotation3D& operator = (const Rotation3D& right);

      //## Operation: operator()%863777778; C++
      //	Rotate the specified point and return the result.
      Point3D operator () (const Point3D& x) const;

      //## Operation: operator()%863777779; C++
      //	Rotate the specified vector and return the result.
      Vector3D operator () (const Vector3D& v) const;

      //## Operation: operator*%863777780; C++
      //	Concatenate this rotation with the argument, returning
      //	the result.
      Rotation3D operator * (const Rotation3D& R) const;

      //## Operation: operator*%864204479; C++
      //	Multiplication form of Point3D rotation.
      Point3D operator * (const Point3D& p) const;

      //## Operation: operator*%864204480; C++
      //	Multiplication form (dot) of Vector3D rotation.
      Vector3D operator * (const Vector3D& v) const;

      //## Operation: inv%864204478; C++
      //	Return the inverse of this rotation.
      Rotation3D inv () const;

      //## Operation: type%863777781; C++
      //	Return the type of rotation. Can be identity, xrot,
      //	yrot, zrot or general.
      RotationType type () const;

      //## Operation: isIdentity%863777852; C++
      //	Returns true if this is a null rotation.
      bool isIdentity () const;

      //## Operation: isXrot%863777782; C++
      //	Returns true if a pure rotation about the x-axis.
      bool isXrot () const;

      //## Operation: isYrot%863777783; C++
      //	Returns true if a pure rotation about the y-axis.
      bool isYrot () const;

      //## Operation: isZrot%863777784; C++
      //	Returns true if a pure rotation about the z-axis.
      bool isZrot () const;

      //## Operation: identity%863777785; C++
      //	Static factory method. Constructs an identity (null)
      //	rotation.
      static Rotation3D identity ();

      //## Operation: rotationX%863777786; C++
      //	Static factory method. Constructs a pure x rotation of
      //	angle radians.
      static Rotation3D rotationX (double angle);

      //## Operation: rotationY%863777787; C++
      //	Static factory method. Constructs a pure y rotation of
      //	angle radians.
      static Rotation3D rotationY (double angle);

      //## Operation: rotationZ%863777788; C++
      //	Static factory method. Constructs a pure z rotation of
      //	angle radians.
      static Rotation3D rotationZ (double angle);

      //## Operation: rotXbyPI%885461022
      //	Special functions which rotate this transformation by
      //	180 degrees about the specified axis. If R is the 180
      //	degree rotation, and *this is T, then T <- R.T.R. These
      //	functions are supplied for efficiency reasons.
      Rotation3D rotXbyPI () const;

      //## Operation: rotYbyPI%885461023
      Rotation3D rotYbyPI () const;

      //## Operation: rotZbyPI%885461024
      Rotation3D rotZbyPI () const;

      //## Operation: getMatrix%903600357
      //	Returns in m the 3x3 rotation matrix.
      RealMatrix& getMatrix (RealMatrix& m) const;

  protected:
  private:
    // Data Members for Associations

      //## Association: EuclideanGeometry::delegates to%337B443202C6
      //## Role: Rotation3D::rep%3398129C01B0
      //## begin Rotation3D::rep%3398129C01B0.role preserve=no  private: Rot3Drep { -> 0..1RHAPN}
      Rot3Drep* rep;
      //## end Rotation3D::rep%3398129C01B0.role

  private:  //## implementation
    //## Constructors (specified)
      //## Operation: Rotation3D%863777789; C++
      //	Special implementation constructor taking a newly
      //	constructed Rot3Drep object.
      Rotation3D (Rot3Drep* nrep);

};

// Class Rotation3D 

//## Operation: Rotation3D%863777774; C++
inline Rotation3D::Rotation3D ()
  //## begin Rotation3D::Rotation3D%863777774.initialization preserve=yes
  : rep(Rot3Drep::identity())
  //## end Rotation3D::Rotation3D%863777774.initialization
{
  //## begin Rotation3D::Rotation3D%863777774.body preserve=yes
  rep->refc++;
  //## end Rotation3D::Rotation3D%863777774.body
}

//## Operation: Rotation3D%863777775; C++
inline Rotation3D::Rotation3D (const Rotation3D& R)
  //## begin Rotation3D::Rotation3D%863777775.initialization preserve=yes
  //## end Rotation3D::Rotation3D%863777775.initialization
{
  //## begin Rotation3D::Rotation3D%863777775.body preserve=yes
  (rep=R.rep)->refc++;
  //## end Rotation3D::Rotation3D%863777775.body
}

//## Operation: Rotation3D%863777789; C++
inline Rotation3D::Rotation3D (Rot3Drep* nrep)
  //## begin Rotation3D::Rotation3D%863777789.initialization preserve=yes
  //## end Rotation3D::Rotation3D%863777789.initialization
{
  //## begin Rotation3D::Rotation3D%863777789.body preserve=yes
  (rep=nrep)->refc++;
  //## end Rotation3D::Rotation3D%863777789.body
}


//## Operation: ~Rotation3D%863777776; C++
inline Rotation3D::~Rotation3D ()
{
  //## begin Rotation3D::~Rotation3D%863777776.body preserve=yes
  if(--rep->refc==0) delete rep;
  //## end Rotation3D::~Rotation3D%863777776.body
}



//## Other Operations (inline)
//## Operation: operator=%863777777; C++
//## Qualification: inline
inline const Rotation3D& Rotation3D::operator = (const Rotation3D& right)
{
  //## begin Rotation3D::operator=%863777777.body preserve=yes
  if(rep!=right.rep) {
  	if(--rep->refc==0) delete rep;
    (rep=right.rep)->refc++;
  }
  return *this;
  //## end Rotation3D::operator=%863777777.body
}

//## Operation: operator()%863777778; C++
inline Point3D Rotation3D::operator () (const Point3D& x) const
{
  //## begin Rotation3D::operator()%863777778.body preserve=yes
  return rep->rotate(x);
  //## end Rotation3D::operator()%863777778.body
}

//## Operation: operator()%863777779; C++
inline Vector3D Rotation3D::operator () (const Vector3D& v) const
{
  //## begin Rotation3D::operator()%863777779.body preserve=yes
  return rep->rotate(v);
  //## end Rotation3D::operator()%863777779.body
}

//## Operation: operator*%863777780; C++
inline Rotation3D Rotation3D::operator * (const Rotation3D& R) const
{
  //## begin Rotation3D::operator*%863777780.body preserve=yes
  return Rotation3D(rep->dot(*R.rep));
  //## end Rotation3D::operator*%863777780.body
}

//## Operation: operator*%864204479; C++
//## Qualification: const inline
inline Point3D Rotation3D::operator * (const Point3D& p) const
{
  //## begin Rotation3D::operator*%864204479.body preserve=yes
  return rep->rotate(p);
  //## end Rotation3D::operator*%864204479.body
}

//## Operation: operator*%864204480; C++
//## Qualification: const inline
inline Vector3D Rotation3D::operator * (const Vector3D& v) const
{
  //## begin Rotation3D::operator*%864204480.body preserve=yes
  return rep->rotate(v);
  //## end Rotation3D::operator*%864204480.body
}

//## Operation: inv%864204478; C++
inline Rotation3D Rotation3D::inv () const
{
  //## begin Rotation3D::inv%864204478.body preserve=yes
  return Rotation3D(rep->inv());
  //## end Rotation3D::inv%864204478.body
}

//## Operation: type%863777781; C++
inline RotationType Rotation3D::type () const
{
  //## begin Rotation3D::type%863777781.body preserve=yes
  return rep->type();
  //## end Rotation3D::type%863777781.body
}

//## Operation: isIdentity%863777852; C++
inline bool Rotation3D::isIdentity () const
{
  //## begin Rotation3D::isIdentity%863777852.body preserve=yes
  return rep->isIdentity();
  //## end Rotation3D::isIdentity%863777852.body
}

//## Operation: isXrot%863777782; C++
inline bool Rotation3D::isXrot () const
{
  //## begin Rotation3D::isXrot%863777782.body preserve=yes
  return rep->isXrot();
  //## end Rotation3D::isXrot%863777782.body
}

//## Operation: isYrot%863777783; C++
inline bool Rotation3D::isYrot () const
{
  //## begin Rotation3D::isYrot%863777783.body preserve=yes
  return rep->isYrot();
  //## end Rotation3D::isYrot%863777783.body
}

//## Operation: isZrot%863777784; C++
inline bool Rotation3D::isZrot () const
{
  //## begin Rotation3D::isZrot%863777784.body preserve=yes
  return rep->isZrot();
  //## end Rotation3D::isZrot%863777784.body
}

//## Operation: identity%863777785; C++
inline Rotation3D Rotation3D::identity ()
{
  //## begin Rotation3D::identity%863777785.body preserve=yes
	return Rotation3D();
  //## end Rotation3D::identity%863777785.body
}

//## Operation: rotationX%863777786; C++
inline Rotation3D Rotation3D::rotationX (double angle)
{
  //## begin Rotation3D::rotationX%863777786.body preserve=yes
	return Rotation3D(Rot3Drep::rotationX(angle));
  //## end Rotation3D::rotationX%863777786.body
}

//## Operation: rotationY%863777787; C++
inline Rotation3D Rotation3D::rotationY (double angle)
{
  //## begin Rotation3D::rotationY%863777787.body preserve=yes
	return Rotation3D(Rot3Drep::rotationY(angle));
  //## end Rotation3D::rotationY%863777787.body
}

//## Operation: rotationZ%863777788; C++
inline Rotation3D Rotation3D::rotationZ (double angle)
{
  //## begin Rotation3D::rotationZ%863777788.body preserve=yes
	return Rotation3D(Rot3Drep::rotationZ(angle));
  //## end Rotation3D::rotationZ%863777788.body
}

//## Operation: rotXbyPI%885461022
inline Rotation3D Rotation3D::rotXbyPI () const
{
  //## begin Rotation3D::rotXbyPI%885461022.body preserve=yes
	return Rotation3D(rep->rotXbyPI());
  //## end Rotation3D::rotXbyPI%885461022.body
}

//## Operation: rotYbyPI%885461023
inline Rotation3D Rotation3D::rotYbyPI () const
{
  //## begin Rotation3D::rotYbyPI%885461023.body preserve=yes
	return Rotation3D(rep->rotYbyPI());
  //## end Rotation3D::rotYbyPI%885461023.body
}

//## Operation: rotZbyPI%885461024
inline Rotation3D Rotation3D::rotZbyPI () const
{
  //## begin Rotation3D::rotZbyPI%885461024.body preserve=yes
	return Rotation3D(rep->rotZbyPI());
  //## end Rotation3D::rotZbyPI%885461024.body
}

//## Operation: getMatrix%903600357
inline RealMatrix& Rotation3D::getMatrix (RealMatrix& m) const
{
  //## begin Rotation3D::getMatrix%903600357.body preserve=yes
	return rep->getMatrix(m);
  //## end Rotation3D::getMatrix%903600357.body
}

//## begin module%337972F3025C.epilog preserve=yes
//## end module%337972F3025C.epilog


#endif

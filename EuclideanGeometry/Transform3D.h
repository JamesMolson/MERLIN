//## begin module%3379730500D1.cm preserve=no
//## end module%3379730500D1.cm

//## begin module%3379730500D1.cp preserve=no
//## end module%3379730500D1.cp

//## Module: Transform3D%3379730500D1; Package specification
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\Transform3D.h

#ifndef Transform3D_h
#define Transform3D_h 1

//## begin module%3379730500D1.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3379730500D1.additionalIncludes

//## begin module%3379730500D1.includes preserve=yes
//## end module%3379730500D1.includes

// Transform2D
#include "EuclideanGeometry/Transform2D.h"
// Space3D
#include "EuclideanGeometry/Space3D.h"
// Rotation3D
#include "EuclideanGeometry/Rotation3D.h"
//## begin module%3379730500D1.declarations preserve=no
//## end module%3379730500D1.declarations

//## begin module%3379730500D1.additionalDeclarations preserve=yes
//## end module%3379730500D1.additionalDeclarations


//## Class: Transform3D%3398129A00A0
//	Represents a 3-dimensional Euclidean transformation. A
//	Euclidean transformation is characterised by a
//	translation followed by a rotation. The translation
//	vector and rotation can be thought of as the origin and
//	orientation respectively of a set of mutually
//	perpendicular axes. EuclideanTransform objects can act
//	on Point3D and Vector3D objects, effectively
//	transforming them into a new reference frame.
//	EuclideanTransforms can also be composed using the
//	multiplication operator *, i.e. T3 = T1*T2 (note that
//	multiplication is not commutitive).
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: operates on%3398129A0155;Vector3D { -> }
//## Uses: constructs from%341FA83A00DB;Transform2D { -> }
//## Uses: operates on%362600670392;Point3D { -> }

class Transform3D 
{
  public:
    //## Constructors (specified)
      //## Operation: Transform3D%864215960; C++
      //	Default constructor. Creates an indentity (null)
      //	transformation.
      Transform3D ();

      //## Operation: Transform3D%864215975; C++
      //	Constructor taking explicitely a translation and a
      //	rotation.
      Transform3D (const Point3D& X, const Rotation3D& R);

      //## Operation: Transform3D%874490606; C++
      //	Construct a general 3D transformation from a Transform2D
      //	object.
      explicit Transform3D (const Transform2D& t2d);


    //## Other Operations (specified)
      //## Operation: X%864215961; C++
      //	Returns the translation associated with this
      //	transformation.
      const Point3D& X () const;

      //## Operation: R%864215962; C++
      //	Returns the rotation associated with this transformation.
      const Rotation3D& R () const;

      //## Operation: operator()%864215963; C++
      //	Transform the supplied Point3D and return the result.
      //	Points are translated and rotated.
      Point3D operator () (const Point3D& p) const;

      //## Operation: operator()%864215964; C++
      //	Transform the supplied Vector3D and return the result.
      //	Vectors are rotated only.
      Vector3D operator () (const Vector3D& v) const;

      //## Operation: operator*%864215965; C++
      //	Multiplication operator form of transformation
      //	operationon a Point3D.
      Point3D operator * (const Point3D& p) const;

      //## Operation: operator*%864215966; C++
      //	Multiplication operator form of transformation operation
      //	on a Vector3D.
      Vector3D operator * (const Vector3D& v) const;

      //## Operation: operator*%864215967; C++
      //	Composition (non-commutative multiplication) operator.
      Transform3D operator * (const Transform3D& t) const;

      //## Operation: operator*=%864215968; C++
      //	Composes this transformation with t. If this
      //	transformation is t0, then t0*=t is mathematically
      //	equivalent to t0<-t*t0.
      const Transform3D& operator *= (const Transform3D& t);

      //## Operation: inv%864215969; C++
      //	Return the inverse of this transformation.
      Transform3D inv () const;

      //## Operation: invert%864215970; C++
      //	Invert this transformation.
      const Transform3D& invert ();

      //## Operation: rotXbyPI%885461000
      //	Special functions which rotate this transformation by
      //	180 degrees about the specified axis. If R is the 180
      //	degree rotation, and *this is T, then T <- R.T.R. These
      //	functions are supplied for efficiency reasons.
      void rotXbyPI ();

      //## Operation: rotYbyPI%885461001
      void rotYbyPI ();

      //## Operation: rotZbyPI%885461002
      void rotZbyPI ();

      //## Operation: isIdentity%885461025
      //	Returns true if this is the identity transformation.
      bool isIdentity () const;

      //## Operation: rotationX%864215971; C++
      //	Static (factory) method for construcing a pure
      //	x-rotation transformation.
      static Transform3D rotationX (double angle);

      //## Operation: rotationY%864215972; C++
      //	Static (factory) method for construcing a pure
      //	y-rotation transformation.
      static Transform3D rotationY (double angle);

      //## Operation: rotationZ%864215973; C++
      //	Static (factory) method for construcing a pure
      //	z-rotation transformation.
      static Transform3D rotationZ (double angle);

      //## Operation: translation%864215974; C++
      //	Static (factory) method for construcing a pure
      //	translation transformation.
      static Transform3D translation (double dx, double dy, double dz);

  protected:
  private:
    // Data Members for Associations

      //## Association: EuclideanGeometry::<unnamed>%3382DE3502B5
      //## Role: Transform3D::x0%3398129A0105
      //	The translation associated with this transformation.
      //## begin Transform3D::x0%3398129A0105.role preserve=no  private: Point3D { -> VHAN}
      Point3D x0;
      //## end Transform3D::x0%3398129A0105.role

      //## Association: EuclideanGeometry::<unnamed>%3382DE3F01DD
      //## Role: Transform3D::r%3398129A0131
      //	The rotation associated with this transformation.
      //## begin Transform3D::r%3398129A0131.role preserve=no  private: Rotation3D { -> VHAN}
      Rotation3D r;
      //## end Transform3D::r%3398129A0131.role

  private:  //## implementation
};

// Class Transform3D 

//## Operation: Transform3D%864215960; C++
//## Qualification: inline
inline Transform3D::Transform3D ()
  //## begin Transform3D::Transform3D%864215960.initialization preserve=yes
  :x0(0,0,0),r(Rotation3D::identity())
  //## end Transform3D::Transform3D%864215960.initialization
{
  //## begin Transform3D::Transform3D%864215960.body preserve=yes
  //## end Transform3D::Transform3D%864215960.body
}

//## Operation: Transform3D%864215975; C++
//## Qualification: inline
inline Transform3D::Transform3D (const Point3D& X, const Rotation3D& R)
  //## begin Transform3D::Transform3D%864215975.initialization preserve=yes
  :x0(X),r(R)
  //## end Transform3D::Transform3D%864215975.initialization
{
  //## begin Transform3D::Transform3D%864215975.body preserve=yes
  //## end Transform3D::Transform3D%864215975.body
}


//## Operation: Transform3D%874490606; C++
inline Transform3D::Transform3D (const Transform2D& t2d)
  //## begin Transform3D::Transform3D%874490606.initialization preserve=yes
  :x0(t2d.translation().x,t2d.translation().y,0),r(Rotation3D::rotationZ(t2d.rotationAngle()))
  //## end Transform3D::Transform3D%874490606.initialization
{
  //## begin Transform3D::Transform3D%874490606.body preserve=yes
  //## end Transform3D::Transform3D%874490606.body
}



//## Other Operations (inline)
//## Operation: X%864215961; C++
//## Qualification: inline const
inline const Point3D& Transform3D::X () const
{
  //## begin Transform3D::X%864215961.body preserve=yes
  return x0;
  //## end Transform3D::X%864215961.body
}

//## Operation: R%864215962; C++
//## Qualification: inlined const
inline const Rotation3D& Transform3D::R () const
{
  //## begin Transform3D::R%864215962.body preserve=yes
  return r;
  //## end Transform3D::R%864215962.body
}

//## Operation: operator()%864215963; C++
//## Qualification: const inline
inline Point3D Transform3D::operator () (const Point3D& p) const
{
  //## begin Transform3D::operator()%864215963.body preserve=yes
  return r(p-x0);
  //## end Transform3D::operator()%864215963.body
}

//## Operation: operator()%864215964; C++
//## Qualification: const inline
inline Vector3D Transform3D::operator () (const Vector3D& v) const
{
  //## begin Transform3D::operator()%864215964.body preserve=yes
  return r(v);
  //## end Transform3D::operator()%864215964.body
}

//## Operation: operator*%864215965; C++
//## Qualification: const
inline Point3D Transform3D::operator * (const Point3D& p) const
{
  //## begin Transform3D::operator*%864215965.body preserve=yes
  return r(p-x0);
  //## end Transform3D::operator*%864215965.body
}

//## Operation: operator*%864215966; C++
//## Qualification: const
inline Vector3D Transform3D::operator * (const Vector3D& v) const
{
  //## begin Transform3D::operator*%864215966.body preserve=yes
  return r(v);
  //## end Transform3D::operator*%864215966.body
}

//## Operation: operator*%864215967; C++
//## Qualification: const
inline Transform3D Transform3D::operator * (const Transform3D& t) const
{
  //## begin Transform3D::operator*%864215967.body preserve=yes
  Transform3D ret(t);
  return ret*=(*this);
  //## end Transform3D::operator*%864215967.body
}

//## Operation: rotXbyPI%885461000
inline void Transform3D::rotXbyPI ()
{
  //## begin Transform3D::rotXbyPI%885461000.body preserve=yes
	x0.y*=-1;
	x0.z*=-1;
	r = r.rotXbyPI();
  //## end Transform3D::rotXbyPI%885461000.body
}

//## Operation: rotYbyPI%885461001
inline void Transform3D::rotYbyPI ()
{
  //## begin Transform3D::rotYbyPI%885461001.body preserve=yes
	x0.x*=-1;
	x0.z*=-1;
	r = r.rotYbyPI();
  //## end Transform3D::rotYbyPI%885461001.body
}

//## Operation: rotZbyPI%885461002
inline void Transform3D::rotZbyPI ()
{
  //## begin Transform3D::rotZbyPI%885461002.body preserve=yes
	x0.x*=-1;
	x0.y*=-1;
	r=r.rotZbyPI();
  //## end Transform3D::rotZbyPI%885461002.body
}

//## Operation: isIdentity%885461025
inline bool Transform3D::isIdentity () const
{
  //## begin Transform3D::isIdentity%885461025.body preserve=yes
	return x0.isZero() && r.isIdentity();
  //## end Transform3D::isIdentity%885461025.body
}

//## begin module%3379730500D1.epilog preserve=yes
//## end module%3379730500D1.epilog


#endif

//## begin module%341FAA24028E.cm preserve=no
//## end module%341FAA24028E.cm

//## begin module%341FAA24028E.cp preserve=no
//## end module%341FAA24028E.cp

//## Module: Transform2D%341FAA24028E; Package specification
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\Transform2D.h

#ifndef Transform2D_h
#define Transform2D_h 1

//## begin module%341FAA24028E.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%341FAA24028E.additionalIncludes

//## begin module%341FAA24028E.includes preserve=yes
#include <cmath>
#include <iostream>
//## end module%341FAA24028E.includes

// Space2D
#include "EuclideanGeometry/Space2D.h"
//## begin module%341FAA24028E.declarations preserve=no
//## end module%341FAA24028E.declarations

//## begin module%341FAA24028E.additionalDeclarations preserve=yes
using std::ostream;
using std::istream;
//## end module%341FAA24028E.additionalDeclarations


//## Class: Rotation2D%347F3AD100D2
//	Represents a simpy X-Y rotoation.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: operates on%36260046034E;Point2D { -> }
//## Uses: operates on%362600540109;Vector2D { -> }

class Rotation2D 
{
  public:
    //## Constructors (specified)
      //## Operation: Rotation2D%880739322; C++
      //	Constructor taking the rotation angle (in radians).
      explicit Rotation2D (double angle = 0)
        //## begin Rotation2D::Rotation2D%880739322.initialization preserve=yes
		: cosa(cos(angle)),sina(sin(angle))
        //## end Rotation2D::Rotation2D%880739322.initialization
      {
        //## begin Rotation2D::Rotation2D%880739322.body preserve=yes
        //## end Rotation2D::Rotation2D%880739322.body
      }


    //## Other Operations (specified)
      //## Operation: rotation%880739297
      //	Returns the rotation angle in radian.
      double rotation () const
      {
        //## begin Rotation2D::rotation%880739297.body preserve=yes
		  return atan2(sina,cosa);
        //## end Rotation2D::rotation%880739297.body
      }

      //## Operation: setRotation%881574133; C++
      //	Set the rotation angle.
      void setRotation (double phi)
      {
        //## begin Rotation2D::setRotation%881574133.body preserve=yes
		  cosa=cos(phi);
		  sina=sin(phi);
        //## end Rotation2D::setRotation%881574133.body
      }

      //## Operation: sinphi%880739295
      //	Returns sin(rotation).
      double sinphi () const
      {
        //## begin Rotation2D::sinphi%880739295.body preserve=yes
		  return sina;
        //## end Rotation2D::sinphi%880739295.body
      }

      //## Operation: cosphi%880739296
      //	Returns cos(rotation).
      double cosphi () const
      {
        //## begin Rotation2D::cosphi%880739296.body preserve=yes
		  return cosa;
        //## end Rotation2D::cosphi%880739296.body
      }

      //## Operation: isIdentity%874490607; C++
      //	Returns true if the rotation angle is zero.
      bool isIdentity () const
      {
        //## begin Rotation2D::isIdentity%874490607.body preserve=yes
		  return sina == 0;
        //## end Rotation2D::isIdentity%874490607.body
      }

      //## Operation: operator*=%880739323; C++
      //	Premultipliy *this by R.
      const Rotation2D& operator *= (const Rotation2D& R)
      {
        //## begin Rotation2D::operator*=%880739323.body preserve=yes
			const double c = R.cosa*cosa-R.sina*sina;
			const double s = R.sina*cosa+R.cosa*sina;
			cosa=c;
			sina=s;
			return *this;
        //## end Rotation2D::operator*=%880739323.body
      }

      //## Operation: operator*%880739324; C++
      //	Rotation multiplication.
      friend Rotation2D operator * (const Rotation2D& R2, const Rotation2D& R1)
      {
        //## begin Rotation2D::operator*%880739324.body preserve=yes
		  return Rotation2D(R2.cosa*R1.cosa-R2.sina*R1.sina,
			  R2.sina*R1.cosa+R2.cosa*R1.sina);
        //## end Rotation2D::operator*%880739324.body
      }

      //## Operation: inv%880739325; C++
      //	Return the inverse of *this.
      Rotation2D inv () const
      {
        //## begin Rotation2D::inv%880739325.body preserve=yes
		  return Rotation2D(cosa,-sina);
        //## end Rotation2D::inv%880739325.body
      }

      //## Operation: invert%880739326; C++
      //	Invert (in-place) *this.
      const Rotation2D& invert ()
      {
        //## begin Rotation2D::invert%880739326.body preserve=yes
		  sina=-sina;
		  return *this;
        //## end Rotation2D::invert%880739326.body
      }

      //## Operation: operator()%880739327; C++
      //	Transformation operations.
      Point2D operator () (const Point2D& p) const
      {
        //## begin Rotation2D::operator()%880739327.body preserve=yes
		  return Point2D(cosa*p.x-sina*p.y,sina*p.x+cosa*p.y);
        //## end Rotation2D::operator()%880739327.body
      }

      //## Operation: operator()%880739328; C++
      Vector2D operator () (const Vector2D& v) const
      {
        //## begin Rotation2D::operator()%880739328.body preserve=yes
 		  return Vector2D(cosa*v.x-sina*v.y,sina*v.x+cosa*v.y);
        //## end Rotation2D::operator()%880739328.body
      }

      //## Operation: operator<<%888481608
      friend ostream& operator << (ostream& os, const Rotation2D& rot)
      {
        //## begin Rotation2D::operator<<%888481608.body preserve=yes
		  os<<rot.cosa;
		  os<<rot.sina;
		  return os;
        //## end Rotation2D::operator<<%888481608.body
      }

      //## Operation: operator>>%888481609
      friend istream& operator >> (istream& is, Rotation2D& rot)
      {
        //## begin Rotation2D::operator>>%888481609.body preserve=yes
		  is>>rot.cosa;
		  is>>rot.sina;
		  return is;
        //## end Rotation2D::operator>>%888481609.body
      }

  protected:
  private:
    //## Constructors (specified)
      //## Operation: Rotation2D%880739329
      //	Private constructor.
      Rotation2D (double c, double s)
        //## begin Rotation2D::Rotation2D%880739329.initialization preserve=yes
		: cosa(c),sina(s)
        //## end Rotation2D::Rotation2D%880739329.initialization
      {
        //## begin Rotation2D::Rotation2D%880739329.body preserve=yes
        //## end Rotation2D::Rotation2D%880739329.body
      }

    // Data Members for Class Attributes

      //## Attribute: cosa%347F00DB0276
      //	cosine of the rotation angle.
      //## begin Rotation2D::cosa%347F00DB0276.attr preserve=no  private: double {UA} 
      double cosa;
      //## end Rotation2D::cosa%347F00DB0276.attr

      //## Attribute: sina%341FA84F02EE
      //	sin of the rotation angle.
      //## begin Rotation2D::sina%341FA84F02EE.attr preserve=no  private: double {UDA} 
      double sina;
      //## end Rotation2D::sina%341FA84F02EE.attr

  private:  //## implementation
};

//## Class: Transform2D%341FA7EB0073
//	A special sub-set of a full 3D Euclidean transformation,
//	which represents a rotation in the Z-plane followed by
//	an X and Y displacement.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: operates on%347F019E00B4;Vector2D { -> }
//## Uses: operates on%3625FEFE0356;Point2D { -> }

class Transform2D 
{
  public:
    //## Constructors (specified)
      //## Operation: Transform2D%874490604; C++
      //	Constructor.
      Transform2D (double dx = 0, double dy = 0, double dphi = 0)
        //## begin Transform2D::Transform2D%874490604.initialization preserve=yes
		: r(dphi), x0(dx,dy)
        //## end Transform2D::Transform2D%874490604.initialization
      {
        //## begin Transform2D::Transform2D%874490604.body preserve=yes
        //## end Transform2D::Transform2D%874490604.body
      }

      //## Operation: Transform2D%880739330
      explicit Transform2D (const Rotation2D& rr, const Point2D& p = Point2D(0,0))
        //## begin Transform2D::Transform2D%880739330.initialization preserve=yes
	: r(rr),x0(p)
        //## end Transform2D::Transform2D%880739330.initialization
      {
        //## begin Transform2D::Transform2D%880739330.body preserve=yes
        //## end Transform2D::Transform2D%880739330.body
      }

      //## Operation: Transform2D%880739331
      explicit Transform2D (const Point2D& p)
        //## begin Transform2D::Transform2D%880739331.initialization preserve=yes
		: r(0),x0(p)
        //## end Transform2D::Transform2D%880739331.initialization
      {
        //## begin Transform2D::Transform2D%880739331.body preserve=yes
        //## end Transform2D::Transform2D%880739331.body
      }


    //## Other Operations (specified)
      //## Operation: operator*%874490602; C++
      //	Multiplication (concatanation) operator.
      friend Transform2D operator * (const Transform2D& t2, const Transform2D& t1)
      {
        //## begin Transform2D::operator*%874490602.body preserve=yes
		// t3=t2*t1;
		return Transform2D(t2.r*t1.r,t2.r(t1.x0)+t2.x0);
        //## end Transform2D::operator*%874490602.body
      }

      //## Operation: operator*=%880624265; C++
      //	t1*=t2 facilitates pre-multiplication of t1 by t2, i.e.
      //	t1->t2*t1.
      const Transform2D& operator *= (const Transform2D& t)
      {
        //## begin Transform2D::operator*=%880624265.body preserve=yes
		  return *this = t*(*this);
        //## end Transform2D::operator*=%880624265.body
      }

      //## Operation: inv%874490605; C++
      //	Invert the transformation and return the result.
      Transform2D inv () const
      {
        //## begin Transform2D::inv%874490605.body preserve=yes
		Transform2D ti(*this);
		return ti.invert();
        //## end Transform2D::inv%874490605.body
      }

      //## Operation: invert%874490603; C++
      //	Invert (in-place) this transformation.
      const Transform2D& invert ()
      {
        //## begin Transform2D::invert%874490603.body preserve=yes
		r.invert();
		x0 = -r(x0);
		return *this;
        //## end Transform2D::invert%874490603.body
      }

      //## Operation: translation%880739298
      //	Returns the (x,y) translation as a Point2D.
      const Point2D& translation () const
      {
        //## begin Transform2D::translation%880739298.body preserve=yes
		  return x0;
        //## end Transform2D::translation%880739298.body
      }

      //## Operation: rotation%881574138
      //	Returns the rotation object.
      const Rotation2D& rotation () const
      {
        //## begin Transform2D::rotation%881574138.body preserve=yes
		  return r;
        //## end Transform2D::rotation%881574138.body
      }

      //## Operation: rotationAngle%880739318
      //	Returns the rotation angle in radian.
      double rotationAngle () const
      {
        //## begin Transform2D::rotationAngle%880739318.body preserve=yes
		  return r.rotation();
        //## end Transform2D::rotationAngle%880739318.body
      }

      //## Operation: sinphi%880739319
      //	Returns sin(rotation).
      double sinphi () const
      {
        //## begin Transform2D::sinphi%880739319.body preserve=yes
		  return r.sinphi();
        //## end Transform2D::sinphi%880739319.body
      }

      //## Operation: cosphi%880739320
      //	Returns cos(rotation).
      double cosphi () const
      {
        //## begin Transform2D::cosphi%880739320.body preserve=yes
		  return r.cosphi();
        //## end Transform2D::cosphi%880739320.body
      }

      //## Operation: isIdentity%880739321; C++
      //	Returns true if this transform is the identity.
      bool isIdentity () const
      {
        //## begin Transform2D::isIdentity%880739321.body preserve=yes
		  return x0.isZero() && r.isIdentity();
        //## end Transform2D::isIdentity%880739321.body
      }

      //## Operation: operator()%880739299; C++
      //	Transformation operations.
      Point2D operator () (const Point2D& p) const
      {
        //## begin Transform2D::operator()%880739299.body preserve=yes
		  return r(p)-x0;
        //## end Transform2D::operator()%880739299.body
      }

      //## Operation: operator()%880739300; C++
      Vector2D operator () (const Vector2D& v) const
      {
        //## begin Transform2D::operator()%880739300.body preserve=yes
 		  return r(v);
        //## end Transform2D::operator()%880739300.body
      }

      //## Operation: setTranslationX%881574134
      //	Modifiers.
      void setTranslationX (double x)
      {
        //## begin Transform2D::setTranslationX%881574134.body preserve=yes
		  x0.x=x;
        //## end Transform2D::setTranslationX%881574134.body
      }

      //## Operation: setTranslationY%881574135
      void setTranslationY (double y)
      {
        //## begin Transform2D::setTranslationY%881574135.body preserve=yes
		  x0.y=y;
        //## end Transform2D::setTranslationY%881574135.body
      }

      //## Operation: setRotation%881574136
      void setRotation (double phi)
      {
        //## begin Transform2D::setRotation%881574136.body preserve=yes
		  r.setRotation(phi);
        //## end Transform2D::setRotation%881574136.body
      }

      //## Operation: operator<<%888481610
      friend ostream& operator << (ostream& os, const Transform2D& t)
      {
        //## begin Transform2D::operator<<%888481610.body preserve=yes
		  os<<t.x0.x;
		  os<<t.x0.y;
		  os<<t.r;
		  return os;
        //## end Transform2D::operator<<%888481610.body
      }

      //## Operation: operator>>%888481611
      friend istream& operator >> (istream& is, Transform2D& t)
      {
        //## begin Transform2D::operator>>%888481611.body preserve=yes
		  is>>t.x0.x;
		  is>>t.x0.y;
		  is>>t.r;
		  return is;
        //## end Transform2D::operator>>%888481611.body
      }

  protected:
  private:
    // Data Members for Associations

      //## Association: EuclideanGeometry::<unnamed>%3625FEB401CA
      //## Role: Transform2D::r%3625FEB401CC
      //## begin Transform2D::r%3625FEB401CC.role preserve=no  private: Rotation2D { -> VHAN}
      Rotation2D r;
      //## end Transform2D::r%3625FEB401CC.role

      //## Association: EuclideanGeometry::<unnamed>%3625FEBA013C
      //## Role: Transform2D::x0%3625FEBA013E
      //## begin Transform2D::x0%3625FEBA013E.role preserve=no  private: Point2D { -> VHAN}
      Point2D x0;
      //## end Transform2D::x0%3625FEBA013E.role

  private:  //## implementation
};

// Class Rotation2D 




// Class Transform2D 




//## begin module%341FAA24028E.epilog preserve=yes
//## end module%341FAA24028E.epilog


#endif

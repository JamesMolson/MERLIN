//## begin module%347F031C012C.cm preserve=no
//## end module%347F031C012C.cm

//## begin module%347F031C012C.cp preserve=no
//## end module%347F031C012C.cp

//## Module: Space2D%347F031C012C; Package specification
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\Space2D.h

#ifndef Space2D_h
#define Space2D_h 1

//## begin module%347F031C012C.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%347F031C012C.additionalIncludes

//## begin module%347F031C012C.includes preserve=yes
//## end module%347F031C012C.includes

// VectorTags
#include "EuclideanGeometry/VectorTags.h"
//## begin module%347F031C012C.declarations preserve=no
//## end module%347F031C012C.declarations

//## begin module%347F031C012C.additionalDeclarations preserve=yes
//## end module%347F031C012C.additionalDeclarations


//## Class: TVec2D%347EFDAF0262; Parameterized Class
//	Template class for generating two-dimensional vectors
//	of the form (x,y). The template parameters
//	are the type of data storage (double, float etc.) and an
//	additional tag value. The tag class acts as a type-safe
//	mechanism for distinguising different types of three
//	vector (see Point2D and Vector2D).
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class T, class tag>
class TVec2D 
{
  public:
    //## Constructors (specified)
      //## Operation: TVec2D%880739301; C++
      //	Default constructor. Data is not initialised.
      TVec2D ()
        //## begin TVec2D::TVec2D%880739301.initialization preserve=yes
        //## end TVec2D::TVec2D%880739301.initialization
      {
        //## begin TVec2D::TVec2D%880739301.body preserve=yes
        //## end TVec2D::TVec2D%880739301.body
      }

      //## Operation: TVec2D%880739302; C++
      //	Copy constructor.
      TVec2D (const TVec2D& v)
        //## begin TVec2D::TVec2D%880739302.initialization preserve=yes
		: x(v.x),y(v.y)
        //## end TVec2D::TVec2D%880739302.initialization
      {
        //## begin TVec2D::TVec2D%880739302.body preserve=yes
        //## end TVec2D::TVec2D%880739302.body
      }

      //## Operation: TVec2D%880739303; C++
      //	Explicit constructor from the three vector components.
      TVec2D (const T& x1, const T& y1)
        //## begin TVec2D::TVec2D%880739303.initialization preserve=yes
		: x(x1),y(y1)
        //## end TVec2D::TVec2D%880739303.initialization
      {
        //## begin TVec2D::TVec2D%880739303.body preserve=yes
        //## end TVec2D::TVec2D%880739303.body
      }


    //## Other Operations (specified)
      //## Operation: operator=%880739304; C++
      //	Copy assignment
      const TVec2D& operator = (const TVec2D& v)
      {
        //## begin TVec2D::operator=%880739304.body preserve=yes
		  x=v.x;y=v.y;return *this;
        //## end TVec2D::operator=%880739304.body
      }

      //## Operation: operator+=%880739305; C++
      //	Arithmetic assignment.
      const TVec2D& operator += (const TVec2D& v)
      {
        //## begin TVec2D::operator+=%880739305.body preserve=yes
		  x+=v.x;y+=v.y;return *this;
        //## end TVec2D::operator+=%880739305.body
      }

      //## Operation: operator-=%880739306; C++
      const TVec2D& operator -= (const TVec2D& v)
      {
        //## begin TVec2D::operator-=%880739306.body preserve=yes
		  x-=v.x;y-=v.y;return *this;
        //## end TVec2D::operator-=%880739306.body
      }

      //## Operation: operator*=%880739307; C++
      const TVec2D& operator *= (const T& s)
      {
        //## begin TVec2D::operator*=%880739307.body preserve=yes
		  x*=s;y*=s;return *this;
        //## end TVec2D::operator*=%880739307.body
      }

      //## Operation: operator/=%880739308; C++
      const TVec2D& operator /= (const T& s)
      {
        //## begin TVec2D::operator/=%880739308.body preserve=yes
 		  x/=s;y/=s;return *this;
        //## end TVec2D::operator/=%880739308.body
      }

      //## Operation: operator-%880739309; C++
      TVec2D operator - () const
      {
        //## begin TVec2D::operator-%880739309.body preserve=yes
		  return TVec2D(-x,-y);
        //## end TVec2D::operator-%880739309.body
      }

      //## Operation: operator-%880739310; C++
      TVec2D operator - (const TVec2D& v) const
      {
        //## begin TVec2D::operator-%880739310.body preserve=yes
		  return TVec2D(x-v.x,y-v.y);
        //## end TVec2D::operator-%880739310.body
      }

      //## Operation: dot%880739311; C++
      //	Dot (inner) product.
      T dot (const TVec2D& v) const
      {
        //## begin TVec2D::dot%880739311.body preserve=yes
		  return x*v.x+y*v.y;
        //## end TVec2D::dot%880739311.body
      }

      //## Operation: isZero%880739312; C++
      //	Return true if all components are zero.
      bool isZero () const
      {
        //## begin TVec2D::isZero%880739312.body preserve=yes
		  return x==0&&y==0;
        //## end TVec2D::isZero%880739312.body
      }

      //## Operation: operator+%880739313; C++
      TVec2D operator + (const TVec2D& v) const
      {
        //## begin TVec2D::operator+%880739313.body preserve=yes
		  return TVec2D(x+v.x,y+v.y);
        //## end TVec2D::operator+%880739313.body
      }

      //## Operation: operator*%880739314; C++
      TVec2D operator * (T s) const
      {
        //## begin TVec2D::operator*%880739314.body preserve=yes
		  return TVec2D(s*x,s*y);
        //## end TVec2D::operator*%880739314.body
      }

      //## Operation: operator*%880739315; C++
      friend TVec2D operator * (T s, const TVec2D& v)
      {
        //## begin TVec2D::operator*%880739315.body preserve=yes
		  return TVec2D(s*v.x,s*v.y);
        //## end TVec2D::operator*%880739315.body
      }

      //## Operation: operator/%880739316; C++
      TVec2D operator / (T s) const
      {
        //## begin TVec2D::operator/%880739316.body preserve=yes
		  return TVec2D(x/s,y/s);
        //## end TVec2D::operator/%880739316.body
      }

      //## Operation: operator*%880739317; C++
      //	dot product.
      T operator * (const TVec2D& v) const
      {
        //## begin TVec2D::operator*%880739317.body preserve=yes
		  return dot(v);
        //## end TVec2D::operator*%880739317.body
      }

    // Data Members for Class Attributes

      //## Attribute: x%347EFE8B0140
      //## begin TVec2D::x%347EFE8B0140.attr preserve=no  public: T {UA} 
      T x;
      //## end TVec2D::x%347EFE8B0140.attr

      //## Attribute: y%347EFE980186
      //## begin TVec2D::y%347EFE980186.attr preserve=no  public: T {UA} 
      T y;
      //## end TVec2D::y%347EFE980186.attr

  protected:
  private:
  private:  //## implementation
};

//## Class: Point2D%347EFF78024E; Instantiated Class
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%347EFFEF00E6;PointTag { -> }

typedef TVec2D< double,PointTag > Point2D;

//## Class: Vector2D%347EFF7F0082; Instantiated Class
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%347EFFF40190;VectorTag { -> }

typedef TVec2D< double,VectorTag > Vector2D;

// Parameterized Class TVec2D 



//## begin Point2D.instantiation preserve=no
template class TVec2D< double,PointTag >;
//## end Point2D.instantiation
//## begin Vector2D.instantiation preserve=no
template class TVec2D< double,VectorTag >;
//## end Vector2D.instantiation
//## begin module%347F031C012C.epilog preserve=yes
//## end module%347F031C012C.epilog


#endif

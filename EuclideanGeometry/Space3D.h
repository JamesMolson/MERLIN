//## begin module%337972B4014D.cm preserve=no
//## end module%337972B4014D.cm

//## begin module%337972B4014D.cp preserve=no
//## end module%337972B4014D.cp

//## Module: Space3D%337972B4014D; Package specification
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Source file: C:\C++\Merlin\EuclideanGeometry\Space3D.h

#ifndef Space3D_h
#define Space3D_h 1

//## begin module%337972B4014D.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%337972B4014D.additionalIncludes

//## begin module%337972B4014D.includes preserve=yes
//## end module%337972B4014D.includes

// VectorTags
#include "EuclideanGeometry/VectorTags.h"
//## begin module%337972B4014D.declarations preserve=no
//## end module%337972B4014D.declarations

//## begin module%337972B4014D.additionalDeclarations preserve=yes
//## end module%337972B4014D.additionalDeclarations


//## Class: TVec3D%337841AC03B7; Parameterized Class
//	Template class for generating arithmetic three vectors
//	(Euclidean) of the form (x,y,z). The template parameters
//	are the type of data storage (double, float etc.) and an
//	additional tag value. The tag class acts as a type-safe
//	mechanism for distinguising different types of three
//	vector (see Point3D and Vector3D).
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3398129C0357; { -> }
//## Uses: <unnamed>%3398129C0389; { -> }

template <class T, class tag>
class TVec3D 
{
  public:
    //## Constructors (specified)
      //## Operation: TVec3D%863597460; C++
      //	Default constructor. Data is not initialised.
      TVec3D ();

      //## Operation: TVec3D%863597461; C++
      //	Copy constructor.
      TVec3D (const TVec3D<T,tag>& v);

      //## Operation: TVec3D%863597462; C++
      //	Explicit constructor from the three vector components.
      TVec3D (const T& x1, const T& y1, const T& z1);

    //## Equality Operations (generated)
      bool operator==(const TVec3D< T,tag > &right) const;

      bool operator!=(const TVec3D< T,tag > &right) const;


    //## Other Operations (specified)
      //## Operation: operator=%863597463; C++
      //	Copy assignment
      const TVec3D<T,tag>& operator = (const TVec3D<T,tag>& v);

      //## Operation: operator+=%863597464; C++
      //	Arithmetic assignment.
      const TVec3D<T,tag>& operator += (const TVec3D<T,tag>& v);

      //## Operation: operator-=%863597465; C++
      const TVec3D<T,tag>& operator -= (const TVec3D<T,tag>& v);

      //## Operation: operator*=%863597466; C++
      const TVec3D<T,tag>& operator *= (const T& s);

      //## Operation: operator/=%863597467; C++
      const TVec3D<T,tag>& operator /= (const T& s);

      //## Operation: operator-%864215976; C++
      TVec3D operator - () const;

      //## Operation: operator-%864215982; C++
      TVec3D operator - (const TVec3D<T,tag>& v) const;

      //## Operation: dot%863597468; C++
      //	Dot (inner) product.
      T dot (const TVec3D<T,tag>& v) const;

      //## Operation: isZero%863597469; C++
      //	Return true if all components are zero.
      bool isZero () const;

      //## Operation: operator+%864215981; C++
      TVec3D operator + (const TVec3D<T,tag>& v) const;

      //## Operation: operator*%864215983; C++
      TVec3D operator * (T s) const;

      //## Operation: operator/%864215984; C++
      TVec3D operator / (T s) const;

    // Data Members for Class Attributes

      //## Attribute: x%3398129C0342
      //## begin TVec3D::x%3398129C0342.attr preserve=no  public: T {UA} 
      T x;
      //## end TVec3D::x%3398129C0342.attr

      //## Attribute: y%3398129C0343
      //## begin TVec3D::y%3398129C0343.attr preserve=no  public: T {UA} 
      T y;
      //## end TVec3D::y%3398129C0343.attr

      //## Attribute: z%3398129C0344
      //## begin TVec3D::z%3398129C0344.attr preserve=no  public: T {UA} 
      T z;
      //## end TVec3D::z%3398129C0344.attr

  protected:
  private:
  private:  //## implementation
};

//## Class: Vector3D%3378447301D9; Instantiated Class
//	A 3-d vector (x,y,z).
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3398129D0041;VectorTag { -> }

typedef TVec3D< double,VectorTag > Vector3D;

//## Class: Point3D%33784D83009E; Instantiated Class
//	A (x,y,z) point.
//## Category: EuclideanGeometry%3625FD0E0014
//## Subsystem: EuclideanGeometry%36260ACC0366
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3398129D0073;PointTag { -> }

typedef TVec3D< double,PointTag > Point3D;

// Parameterized Class TVec3D 

//## Operation: TVec3D%863597460; C++
template <class T, class tag>
inline TVec3D<T,tag>::TVec3D ()
  //## begin TVec3D::TVec3D%863597460.initialization preserve=yes
  //## end TVec3D::TVec3D%863597460.initialization
{
  //## begin TVec3D::TVec3D%863597460.body preserve=yes
  //## end TVec3D::TVec3D%863597460.body
}

//## Operation: TVec3D%863597461; C++
template <class T, class tag>
inline TVec3D<T,tag>::TVec3D (const TVec3D<T,tag>& v)
  //## begin TVec3D::TVec3D%863597461.initialization preserve=yes
  :x(v.x),y(v.y),z(v.z)
  //## end TVec3D::TVec3D%863597461.initialization
{
  //## begin TVec3D::TVec3D%863597461.body preserve=yes
  //## end TVec3D::TVec3D%863597461.body
}

//## Operation: TVec3D%863597462; C++
template <class T, class tag>
inline TVec3D<T,tag>::TVec3D (const T& x1, const T& y1, const T& z1)
  //## begin TVec3D::TVec3D%863597462.initialization preserve=yes
  :x(x1),y(y1),z(z1)
  //## end TVec3D::TVec3D%863597462.initialization
{
  //## begin TVec3D::TVec3D%863597462.body preserve=yes
  //## end TVec3D::TVec3D%863597462.body
}


template <class T, class tag>
inline bool TVec3D<T,tag>::operator==(const TVec3D<T,tag> &right) const
{
  //## begin TVec3D::operator==%.body preserve=yes
  return x==right.x && y==right.y && z==right.z;
  //## end TVec3D::operator==%.body
}

template <class T, class tag>
inline bool TVec3D<T,tag>::operator!=(const TVec3D<T,tag> &right) const
{
  //## begin TVec3D::operator!=%.body preserve=yes
	return x!=right.x || y!=right.y || z!=right.z;
  //## end TVec3D::operator!=%.body
}



//## Other Operations (inline)
//## Operation: operator=%863597463; C++
template <class T, class tag>
inline const TVec3D<T,tag>& TVec3D<T,tag>::operator = (const TVec3D<T,tag>& v)
{
  //## begin TVec3D::operator=%863597463.body preserve=yes
  if(this!=&v){
  	x=v.x;
    y=v.y;
    z=v.z;
  }
  return *this;
  //## end TVec3D::operator=%863597463.body
}

//## Operation: operator+=%863597464; C++
template <class T, class tag>
inline const TVec3D<T,tag>& TVec3D<T,tag>::operator += (const TVec3D<T,tag>& v)
{
  //## begin TVec3D::operator+=%863597464.body preserve=yes
  x+=v.x;
  y+=v.y;
  z+=v.z;
  return *this;
  //## end TVec3D::operator+=%863597464.body
}

//## Operation: operator-=%863597465; C++
template <class T, class tag>
inline const TVec3D<T,tag>& TVec3D<T,tag>::operator -= (const TVec3D<T,tag>& v)
{
  //## begin TVec3D::operator-=%863597465.body preserve=yes
  x-=v.x;
  y-=v.y;
  z-=v.z;
  return *this;
  //## end TVec3D::operator-=%863597465.body
}

//## Operation: operator*=%863597466; C++
template <class T, class tag>
inline const TVec3D<T,tag>& TVec3D<T,tag>::operator *= (const T& s)
{
  //## begin TVec3D::operator*=%863597466.body preserve=yes
  x*=s;
  y*=s;
  z*=s;
  return *this;
  //## end TVec3D::operator*=%863597466.body
}

//## Operation: operator/=%863597467; C++
template <class T, class tag>
inline const TVec3D<T,tag>& TVec3D<T,tag>::operator /= (const T& s)
{
  //## begin TVec3D::operator/=%863597467.body preserve=yes
  x/=s;
  y/=s;
  z/=s;
  return *this;
  //## end TVec3D::operator/=%863597467.body
}

//## Operation: operator-%864215976; C++
template <class T, class tag>
inline TVec3D<T,tag> TVec3D<T,tag>::operator - () const
{
  //## begin TVec3D::operator-%864215976.body preserve=yes
  return TVec3D<T,tag>(-x,-y,-z);
  //## end TVec3D::operator-%864215976.body
}

//## Operation: operator-%864215982; C++
template <class T, class tag>
inline TVec3D<T,tag> TVec3D<T,tag>::operator - (const TVec3D<T,tag>& v) const
{
  //## begin TVec3D::operator-%864215982.body preserve=yes
  return TVec3D<T,tag>(x-v.x,y-v.y,z-v.z);
  //## end TVec3D::operator-%864215982.body
}

//## Operation: dot%863597468; C++
template <class T, class tag>
inline T TVec3D<T,tag>::dot (const TVec3D<T,tag>& v) const
{
  //## begin TVec3D::dot%863597468.body preserve=yes
  return x*v.x+y*v.y+z*v.z;
  //## end TVec3D::dot%863597468.body
}

//## Operation: isZero%863597469; C++
template <class T, class tag>
inline bool TVec3D<T,tag>::isZero () const
{
  //## begin TVec3D::isZero%863597469.body preserve=yes
  return x==0 && y==0 && z==0;
  //## end TVec3D::isZero%863597469.body
}

//## Operation: operator+%864215981; C++
template <class T, class tag>
inline TVec3D<T,tag> TVec3D<T,tag>::operator + (const TVec3D<T,tag>& v) const
{
  //## begin TVec3D::operator+%864215981.body preserve=yes
  return TVec3D<T,tag>(x+v.x,y+v.y,z+v.z);
  //## end TVec3D::operator+%864215981.body
}

//## Operation: operator*%864215983; C++
template <class T, class tag>
inline TVec3D<T,tag> TVec3D<T,tag>::operator * (T s) const
{
  //## begin TVec3D::operator*%864215983.body preserve=yes
  return TVec3D<T,tag>(s*x,s*y,s*z);
  //## end TVec3D::operator*%864215983.body
}

//## Operation: operator/%864215984; C++
template <class T, class tag>
inline TVec3D<T,tag> TVec3D<T,tag>::operator / (T s) const
{
  //## begin TVec3D::operator/%864215984.body preserve=yes
  return TVec3D<T,tag>(x/s,y/s,z/s);
  //## end TVec3D::operator/%864215984.body
}

// Parameterized Class TVec3D 





//## Other Operations (implementation)
//## Operation: operator*%864215985; C++
//## Qualification: friend
template <class T, class tag>
TVec3D<T,tag> operator * (T s, const TVec3D<T,tag>& v)
{
  //## begin TVec3D::operator*%864215985.body preserve=yes
  return TVec3D<T,tag>(s*v.x,s*v.y,s*v.z);
  //## end TVec3D::operator*%864215985.body
}

//## begin module%337972B4014D.epilog preserve=yes
template<class T, class tag>
inline TVec3D<T,tag> cross(const TVec3D<T,tag>& a, const TVec3D<T,tag>& b)
{
	return TVec3D<T,tag>(a.y*b.z-a.z*b.y,b.x*a.z-b.z*a.x,a.x*b.y-a.y*b.x);
}

template<class T, class tag>
inline T operator*(const TVec3D<T,tag>& v1, const TVec3D<T,tag>& v2)
{
	return v1.dot(v2);
}
//## end module%337972B4014D.epilog


#endif

/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//
// Class library version 3 (2004)
//
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004/12/13 08:38:53 $
// $Revision: 1.2 $
//
/////////////////////////////////////////////////////////////////////////

#ifndef PSvector_h
#define PSvector_h 1

#include "merlin_config.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include "TLAS/LinearAlgebra.h"

// Phase space coordinate indecies
typedef int PScoord;
#define ps_X  0
#define ps_XP 1
#define ps_Y  2
#define ps_YP 3
#define ps_CT 4
#define ps_DP 5

#define PS_LENGTH 10

class PSvector
{
public:

	PSvector ()
	{}

	explicit PSvector (Mfloat_t x)
	{
//		std::fill(v,v+PS_LENGTH,x);
		for(unsigned int n=0; n < PS_LENGTH; n++)
		{
			for(unsigned int m=0; m < MvectorLength; m++)
			{
				v[n][m] = x;
			}
		}
	}

	//	Component accessors.
	Mvector_t x ()  const
	{
		return v[0];
	}
	Mvector_t y ()  const
	{
		return v[2];
	}
	Mvector_t ct () const
	{
		return v[4];
	}
	Mvector_t xp () const
	{
		return v[1];
	}
	Mvector_t yp () const
	{
		return v[3];
	}
	Mvector_t dp () const
	{
		return v[5];
	}
	Mvector_t type () const
	{
		return v[6];
	}
	Mvector_t location () const
	{
		return v[7];
	}
	Mvector_t id () const
	{
		return v[8];
	}
	Mvector_t sd () const
	{
		return v[9];
	}

	//	Array access.
	Mvector_t operator [] (PScoord coord) const
	{
		return v[coord];
	}

	//	Component mutators.
	Mvector_t& x ()
	{
		return v[0];
	}
	Mvector_t& y ()
	{
		return v[2];
	}
	Mvector_t& ct ()
	{
		return v[4];
	}
	Mvector_t& xp ()
	{
		return v[1];
	}
	Mvector_t& yp ()
	{
		return v[3];
	}
	Mvector_t& dp ()
	{
		return v[5];
	}
	Mvector_t& type ()
	{
		return v[6];
	}
	Mvector_t& location ()
	{
		return v[7];
	}
	Mvector_t& id ()
	{
		return v[8];
	}
	Mvector_t& sd ()
	{
		return v[9];
	}

	//	Array access.
	Mvector_t& operator [] (PScoord coord)
	{
		return v[coord];
	}

	//	Conversion to a RealVector.
	/**
	Disable for now
	operator RealVector () const
	{
		return RealVector(v,PS_LENGTH);
	}
	*/

	bool operator == (const PSvector& psv) const
	{
		return memcmp(v,psv.v,PS_LENGTH*sizeof(Mvector_t))==0;
	}

	bool operator != (const PSvector& psv) const
	{
		return memcmp(v,psv.v,PS_LENGTH*sizeof(Mvector_t))!=0;
	}

	//	Sets the vector to zero.
	void zero ()
	{
//		std::fill(v,v+PS_LENGTH,0.0);
		for(unsigned int n=0; n < PS_LENGTH; n++)
		{
			for(unsigned int m=0; m < MvectorLength; m++)
			{
				v[n][m] = 0.0;
			}
		}
	}

	//	Arithmetic assignment
	PSvector& operator += (const PSvector& p)
	{
		Mvector_t *q=v;
		const Mvector_t *r=p.v;
		while(q!=(v+PS_LENGTH))
		{
			*(q++) += *(r++);
		}
		return *this;
	}

	PSvector& operator -= (const PSvector& p)
	{
		Mvector_t *q=v;
		const Mvector_t *r=p.v;
		while(q!=(v+PS_LENGTH))
		{
			*(q++) -= *(r++);
		}
		return *this;
	}

	PSvector& operator *= (Mvector_t x)
	{
		for(Mvector_t *q = v; q!=v+PS_LENGTH; q++)
		{
			(*q)*=x;
		}
		return *this;
	}

	PSvector& operator /= (Mvector_t x)
	{
		for(Mvector_t *q = v; q!=v+PS_LENGTH; q++)
		{
			(*q)/=x;
		}
		return *this;
	}

	// binary arithmetic operators
	PSvector operator+(const PSvector& rhs) const
	{
		PSvector rv(*this);
		return rv+=rhs;
	}

	PSvector operator-(const PSvector& rhs) const
	{
		PSvector rv(*this);
		return rv-=rhs;
	}

	//	Reads the vector as six floating point numbers,
	//	separated by spaces and terminated by a newline.
	friend std::ostream& operator<<(std::ostream& os, const PSvector& v);

	//	Outputs the vector in row form, space delimeted with a
	//	terminating newline.
	friend std::istream& operator>>(std::istream& is, PSvector& v);

private:
	Mvector_t __attribute__((aligned(16))) v[PS_LENGTH];
};

//	A linear array of PSvector objects.
typedef std::vector<PSvector> PSvectorArray;

#endif

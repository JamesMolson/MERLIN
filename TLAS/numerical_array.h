// numerical_array.h
// --------------------
// This template class mimics the std::valarray class. It is
// primarilly intended for use in TMatrixLib classes to provide
// a suitable replacement of buggy or incomplete implementations
// of the std lib (i.e. valarray). Hence only those functions
// required by TMatrixLib classes are implemented.
//
// when the macro USE_STD_VALARRAY is defined, then TMatrixLib
// will use the std lib valarray_array. 
//
// Eventually, this file should ``dissappear" :-)

#ifndef _h_numerical_array
#define _h_numerical_array

#include <vector> // implementation
#include <algorithm>
#include <cassert>

namespace TLAS {
	
	// forward declarations
	template<class T> class numerical_array;
	template<class T> class slice_array;
	template<class T> class gslice_array;
	class slice;
	class gslice;
	
	// class slice
	
	class slice {
	public:
		slice() {}
		slice(size_t start1 , size_t size1, size_t stride1)
			: st(start1),sz(size1),str(stride1) {}
		size_t start() const { return st; }
		size_t size() const { return sz; }
		size_t stride() const { return str; }
	private:
		size_t st,sz,str;
	};
	
	template<class T>
		class numerical_array {
	public:
		
		typedef std::vector<T>::iterator iterator;
		typedef std::vector<T>::const_iterator const_iterator;
		
		// constructors
		numerical_array()
			: array() {}
		explicit numerical_array(size_t n)
			: array(n) {}
		numerical_array(const T& val, size_t n)
			: array(n,val) {}
		numerical_array(const T *p, size_t n)
			: array(n) {
			std::copy(p,p+n,array.begin());
		}
		
		numerical_array(const slice_array<T>& sa);
		numerical_array(const gslice_array<T>& ga);
		
		const numerical_array& operator=(const T& rhs) {
			std::fill(array.begin(),array.end(),rhs);
			return *this;
		}
		
		size_t size() const {
			return array.size();
		}
		const T& operator[](size_t i) const {
			return array[i];
		}
		T& operator[](size_t i) {
			return array[i];
		}
		
		// Arithmetic operations
		numerical_array operator+=(const numerical_array& rhs) {
			vector<T>::iterator p = array.begin();
			vector<T>::const_iterator q = array.end();
			while(p!=array.end())
				*p++ += *q++;
			return *this;
		}
		
		numerical_array operator-=(const numerical_array& rhs) {
			vector<T>::iterator p = array.begin();
			vector<T>::const_iterator q = array.end();
			while(p!=array.end())
				*p++ -= *q++;
			return *this;
		}
		
		numerical_array operator*=(const numerical_array& rhs){
			vector<T>::iterator p = array.begin();
			vector<T>::const_iterator q = array.end();
			while(p!=array.end())
				*p++ *= *q++;
			return *this;
		}
		
		numerical_array operator/=(const numerical_array& rhs)
		{
			vector<T>::iterator p = array.begin();
			vector<T>::const_iterator q = array.end();
			while(p!=array.end())
				*p++ /= *q++;
			return *this;
		}
		
		// scalar ops
		numerical_array operator+=(const T& rhs)
		{
			for(vector<T>::iterator p = array.begin(); p!=array.end();p++)
				*p++ += rhs;
			return *this;
		}
		numerical_array operator-=(const T& rhs)
		{
			for(vector<T>::iterator p = array.begin(); p!=array.end();p++)
				*p++ -= rhs;
			return *this;
		}
		
		numerical_array operator*=(const T& rhs)
		{
			for(vector<T>::iterator p = array.begin(); p!=array.end();p++)
				*p++ *= rhs;
			return *this;
		}
		
		numerical_array operator/=(const T& rhs)
		{
			for(vector<T>::iterator p = array.begin(); p!=array.end();p++)
				*p++ /= rhs;
			return *this;
		}
		
		iterator begin() { return array.begin(); }
		iterator end() { return array.end(); }
		const_iterator begin() const { return array.begin(); }
		const_iterator end() const { return array.end(); }
		
		
		// slice operations
		slice_array<T> operator[](slice sl)
		{
			return slice_array<T>(*this,sl);
		}
		gslice_array<T> operator[](const gslice& gl)
		{
			return gslice_array<T>(array,gl);
		}
		numerical_array<T> operator[](slice sl) const
		{
			numerical_array* THIS = const_cast<numerical_array*>(this);
			return slice_array<T>(*THIS,sl);
		}
		numerical_array<T> operator[](const gslice& gl) const
		{
			numerical_array* THIS = const_cast<numerical_array*>(this);
			return gslice_array<T>(THIS->array,gl);
		}
		
		void resize(size_t new_size)
		{
			array.resize(new_size);
		}
		
	private:
		
		std::vector<T> array;
};

#define ARRAY_OP(op,x) numerical_array<T>::const_iterator q=x.begin();\
for(slice_itor p=begin();p!=end();p++,q++) (*p)##op##(*q)

template<class T>
class slice_array {
	
	struct slice_itor {
		size_t str;
		std::vector<T>::iterator p;
		
		slice_itor(std::vector<T>::iterator p1,size_t s)
			: p(p1),str(s) {}
		
		T& operator*() {return *p;}
		const T& operator*() const {return *p;}
		slice_itor operator++() {
			p+=str;
			return *this;
		}
		slice_itor operator++(int) {
			slice_itor tmp(*this);
			p+=str;
			return tmp;
		}
		bool operator!=(const slice_itor& rhs) const {
			return p!=rhs.p;
		}
	};
	
	slice_itor begin() {
		return slice_itor(array.begin()+sl.start(),sl.stride());
	}
	slice_itor end() { 
		return slice_itor(array.begin()+sl.start()+sl.size()*sl.stride(),sl.stride());
	}
	
	public:
		
		typedef T value_type;
		void operator=(const numerical_array<T> x) {
			std::copy(x.begin(),x.end(),begin());
		}
		void operator=(const T& x) {
			std::fill(begin(),end(),x);
		}	
		void operator*=(const numerical_array<T> x) {
			ARRAY_OP(*=,x);
		}
		void operator/=(const numerical_array<T> x) {
			ARRAY_OP(/=,x);
		}
		void operator+=(const numerical_array<T> x) {
			ARRAY_OP(+=,x);
		}
		void operator-=(const numerical_array<T> x) {
			ARRAY_OP(-=,x);
		}
		
		
	private:
		
		friend class numerical_array<T>;
		
		slice_array(numerical_array<T>& anArray, slice s)
			: array(anArray),sl(s) {}
		
		numerical_array<T>& array;
		slice sl;
};

class gslice {
public:
	gslice() {}
	gslice(size_t _S, const std::vector<size_t>& _L,
		const std::vector<size_t>& _D)
		: _Start(_S), _Len(_L), _Stride(_D) {}
	size_t start() const
	{return (_Start); }
	std::vector<size_t> size() const
	{return (_Len); }
	std::vector<size_t> stride() const
	{return (_Stride); }
	size_t _Nslice() const
	{return (_Len.size()); }
	size_t _Off(std::vector<size_t>& _Idx) const
	{size_t _I, _K = _Start;
	for (_I = 0; _I < _Idx.size(); ++_I)
		_K += _Idx[_I] * _Stride[_I];
	while (0 < _I--)
		if (++_Idx[_I] < _Len[_I])
			break;
		else
			_Idx[_I] = 0;
		return (_K); }
	size_t _Totlen() const
	{if (_Len.size() == 0)
	return (0);
	size_t _L = _Len[0];
	for (size_t _I = 0; ++_I < _Len.size(); )
		_L *= _Len[_I];
	return (_L); }
private:
	size_t _Start;
	std::vector<size_t> _Len;
	std::vector<size_t> _Stride;
};

// TEMPLATE CLASS gslice_array
#define _GSLOP(RHS) \
	std::vector<size_t> _Idx(_Nslice(),(size_t)0); \
	size_t _N = _Totlen(); \
	for (size_t _I = 0; _I < _N; ++_I) \
_Ptr[_Off(_Idx)] RHS;
#define _GSLOP2(RHS) \
	std::vector<size_t> _Idx(_L._Nslice(),(size_t)0); \
	size_t _N = _L._Totlen(); \
	for (size_t _I = 0; _I < _N; ++_I) \
_L._Data(_L._Off(_Idx)) RHS;

// class gslice_array

template<class _Ty>
class gslice_array : public gslice {
public:
	typedef _Ty value_type;
	void operator=(const numerical_array<_Ty>& _R) const
	{_GSLOP(= _R[_I]); }
	void operator=(const _Ty& _R)
	{_GSLOP(= _R); }
	_Ty& _Data(size_t _I) const
	{return (_Ptr[_I]); }
private:
	friend class numerical_array<_Ty>;
	gslice_array(std::vector<_Ty>& _Pd, const gslice& _Gs)
		: gslice(_Gs), _Ptr(_Pd) {}
	std::vector<_Ty>& _Ptr;
};
// gslice_array MEMBER TEMPLATE OPERATORS
template<class _Ty> inline
void operator*=(const gslice_array<_Ty>& _L,
				const numerical_array<_Ty>& _R)
{_GSLOP2(*= _R[_I]); }
template<class _Ty> inline
void operator/=(const gslice_array<_Ty>& _L,
				const numerical_array<_Ty>& _R)
{_GSLOP2(/= _R[_I]); }
template<class _Ty> inline
void operator%=(const gslice_array<_Ty>& _L,
				const numerical_array<_Ty>& _R)
{_GSLOP2(%= _R[_I]); }
template<class _Ty> inline
void operator+=(const gslice_array<_Ty>& _L,
				const numerical_array<_Ty>& _R)
{_GSLOP2(+= _R[_I]); }
template<class _Ty> inline
void operator-=(const gslice_array<_Ty>& _L,
				const numerical_array<_Ty>& _R)
{_GSLOP2(-= _R[_I]); }
template<class _Ty> inline
void operator^=(const gslice_array<_Ty>& _L,
				const numerical_array<_Ty>& _R)
{_GSLOP2(^= _R[_I]); }
template<class _Ty> inline
void operator&=(const gslice_array<_Ty>& _L,
				const numerical_array<_Ty>& _R)
{_GSLOP2(&= _R[_I]); }
template<class _Ty> inline
void operator|=(const gslice_array<_Ty>& _L,
				const numerical_array<_Ty>& _R)
{_GSLOP2(|= _R[_I]); }
template<class _Ty> inline
void operator<<=(const gslice_array<_Ty>& _L,
				 const numerical_array<_Ty>& _R)
{_GSLOP2(<<= _R[_I]); }
template<class _Ty> inline
void operator>>=(const gslice_array<_Ty>& _L,
				 const numerical_array<_Ty>& _R)
{_GSLOP2(>>= _R[_I]); }

template<class T>
numerical_array<T>::numerical_array(const slice_array<T>& sa)
	: array()
{
	assert(false);
}

template<class T>
numerical_array<T>::numerical_array(const gslice_array<T>& ga)
{
	assert(false);
}

}; // end namespace TLAS
#endif
//## begin module.cm preserve=no
// Specification for MCVMatrix
// last modified: 01/14/98 at 13:38:42
// This file is part of the MERLIN class library
// version 1.0beta
// ---------------------------------------------
//## end module.cm

//## begin module.cp preserve=no
// (c) 1997 Nicholas J. Walker (DESY) -- All Rights Reserved --
// ------------------------------------------------------------
//## end module.cp

//## Module: MCVMatrix; Package specification
//## Subsystem: NumericalUtils
//## Source file: c:\C++\Merlin\NumericalUtils\MCVMatrix.h

#ifndef MCVMatrix_h
#define MCVMatrix_h 1

//## begin module.includes preserve=yes
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
//## end module.includes

//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
#define MVCMTRX_REDUCE_MEMORY 1

using std::ostream;
using std::setprecision;
using std::setw;
using std::right;
using std::fixed;
using std::scientific;
using std::endl;

inline int ComputeIndex(int i, int j)
{
  if(i<j) std::swap(i,j);
  return i*(i+1)/2+j;
}

inline int ComputeIndex(int i)
{
  return i*(i+3)/2;
}
//## end module.additionalDeclarations


//## Class: MVCMatrix; Parameterized Class
//	An NxN matrix representing the full covariance matrix of
//	an N-variate data sample (including first-order moments,
//	or means). Variables are indexed from 0-(n-1).
//## Category: NumericalUtils; Global
//## Subsystem: NumericalUtils
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class T, int N>
class MVCMatrix 
{
public:
  //## Constructors (specified)
  //## Operation: MVCMatrix%884600583
  //	Default constructor initialises all values to zero.
  MVCMatrix ();


  //## Other Operations (specified)
  //## Operation: mean%869056635
  //	Return the mean of the n-th variable.
  T mean (int n) const;

  //## Operation: std%869056636
  //	Return the standard diviation of the n-th variable.
  T std (int n) const;

  //## Operation: variance%869056637
  //	Return the variance of the n-th variable.
  T variance (int n) const;

  //## Operation: r%869056638
  //	Return the correlation coefficient of the n-th and m-th
  //	variables =  s_mn/sqrt(s_mm*s_nn)
  T r (int n, int m) const;

  //## Operation: operator()%879852331; C++
  //	Matrix indexing. Returns <xi*xj>. Indexing runs from 0
  //	to N-1.
  T& operator () (int i, int j);

  //## Operation: operator()%879852332; C++
  const T& operator () (int i, int j) const;

  //## Operation: operator[]%884600578; C++
  //	Returns the mean value of the n-th parameter.
  T& operator [] (int n);

  //## Operation: operator[]%884600579; C++
  const T& operator [] (int n) const;

  //## Operation: zero%884688436
  //	Sets all elements to zero.
  void zero ();

  //## Operation: printFormatted%884688448; C++
  //	Prints the statistical data in a formatted table. If
  //	normalise==true, then diagonal terms are printed as
  //	correlation coefficients rij.
  void printFormatted (ostream& os, bool normalised = true) const;

  // logical comparisons
  bool operator==(const MVCMatrix<T,N>& rhs) const;
  bool operator!=(const MVCMatrix<T,N>& rhs) const {
	  return !operator==(rhs);
  }

protected:
private:
  // Data Members for Class Attributes

  //## Attribute: m1
  //	An array of the mean values of the distribution.
  //## begin MVCMatrix::m1.attr preserve=no  private: T[N] {UA} 
  T m1[N];
  //## end MVCMatrix::m1.attr

  //## Attribute: m2
  //	An array of the second-order moments (variances) of the
  //	distribution.
  //## begin MVCMatrix::m2.attr preserve=no  private: T[N*(1+N)/2] {UA} 
  T m2[N*(1+N)/2];
  //## end MVCMatrix::m2.attr

private:  //## implementation
};



// Parameterized Class MVCMatrix 


//## Other Operations (inline)
//## Operation: mean%869056635
template <class T, int N>
inline T MVCMatrix<T,N>::mean (int n) const
{
  //## begin MVCMatrix::mean%869056635.body preserve=yes
  return m1[n];
  //## end MVCMatrix::mean%869056635.body
}

//## Operation: std%869056636
template <class T, int N>
inline T MVCMatrix<T,N>::std (int n) const
{
  //## begin MVCMatrix::std%869056636.body preserve=yes
#ifndef MVCMTRX_REDUCE_MEMORY
  return sqrt(m2[n][n]);
#else
  return sqrt(m2[ComputeIndex(n)]);
#endif
  //## end MVCMatrix::std%869056636.body
}

//## Operation: variance%869056637
template <class T, int N>
inline T MVCMatrix<T,N>::variance (int n) const
{
  //## begin MVCMatrix::variance%869056637.body preserve=yes
#ifndef MVCMTRX_REDUCE_MEMORY
  return m2[n][n];
#else
  return m2[ComputeIndex(n)];
#endif
  //## end MVCMatrix::variance%869056637.body
}

//## Operation: r%869056638
template <class T, int N>
inline T MVCMatrix<T,N>::r (int n, int m) const
{
  //## begin MVCMatrix::r%869056638.body preserve=yes
  return n==m ? 1 : 
#ifndef MVCMTRX_REDUCE_MEMORY
    m2[n][m]/sqrt(variance(n)*variance(m));
#else
  m2[ComputeIndex(n,m)]/sqrt(variance(n)*variance(m));
#endif
  //## end MVCMatrix::r%869056638.body
}

//## Operation: operator()%879852331; C++
template <class T, int N>
inline T& MVCMatrix<T,N>::operator () (int i, int j)
{
  //## begin MVCMatrix::operator()%879852331.body preserve=yes
#ifndef MVCMTRX_REDUCE_MEMORY
  return m2[i][j];
#else
  return m2[ComputeIndex(i,j)];
#endif
  //## end MVCMatrix::operator()%879852331.body
}

//## Operation: operator()%879852332; C++
template <class T, int N>
inline const T& MVCMatrix<T,N>::operator () (int i, int j) const
{
  //## begin MVCMatrix::operator()%879852332.body preserve=yes
#ifndef MVCMTRX_REDUCE_MEMORY
  return m2[i][j];
#else
  return m2[ComputeIndex(i,j)];
#endif
  //## end MVCMatrix::operator()%879852332.body
}

//## Operation: operator[]%884600578; C++
//## Qualification: inlined
template <class T, int N>
inline T& MVCMatrix<T,N>::operator [] (int n)
{
  //## begin MVCMatrix::operator[]%884600578.body preserve=yes
  return m1[n];
  //## end MVCMatrix::operator[]%884600578.body
}

//## Operation: operator[]%884600579; C++
//## Qualification: inlined
template <class T, int N>
inline const T& MVCMatrix<T,N>::operator [] (int n) const
{
  //## begin MVCMatrix::operator[]%884600579.body preserve=yes
  return m1[n];
  //## end MVCMatrix::operator[]%884600579.body
}

//## Operation: zero%884688436
template <class T, int N>
inline void MVCMatrix<T,N>::zero ()
{
  //## begin MVCMatrix::zero%884688436.body preserve=yes
#ifndef MVCMTRX_REDUCE_MEMORY
  std::fill(m1,reinterpret_cast<T*>(m2)+N*N,T(0));
#else
  std::fill(m1,m2+N*(1+N)/2,T(0));
#endif
  //## end MVCMatrix::zero%884688436.body
}





// Parameterized Class MVCMatrix 



//## Operation: MVCMatrix%884600583
template <class T, int N>
MVCMatrix<T,N>::MVCMatrix ()
  //## begin MVCMatrix::MVCMatrix%884600583.initialization preserve=yes
  //## end MVCMatrix::MVCMatrix%884600583.initialization
{
  //## begin MVCMatrix::MVCMatrix%884600583.body preserve=yes
  zero();
  //## end MVCMatrix::MVCMatrix%884600583.body
}



//## Other Operations (implementation)
//## Operation: printFormatted%884688448; C++
template <class T, int N>
void MVCMatrix<T,N>::printFormatted (ostream& os, bool normalised) const
{
  //## begin MVCMatrix::printFormatted%884688448.body preserve=yes
  using std::setprecision;
  using std::setw;
  for(int i=0; i<N; i++) {
    os<<setw(12)<<right<<scientific<<setprecision(3)<<mean(i);
    os<<setw(12)<<right<<scientific<<setprecision(3)<<std(i);
    for(int j=1; j<N; j++) {
      if(j<=i) {
	if(normalised)
	  os<<setw(8)<<" ";
	else
	  os<<setw(12)<<" ";
      }
      else {
	os<<right<<setprecision(3);
	if(normalised) 
	  os<<setw(8)<<fixed<<r(i,j);
	else
	  os<<setw(12)<<scientific<<operator()(i,j);
      }
    }
    os<<endl;
  }
  //## end MVCMatrix::printFormatted%884688448.body
}

template<class T, int N>
bool MVCMatrix<T,N>::operator==(const MVCMatrix<T,N>& rhs) const
{
	register int i;
	for(i=0;i<N;i++)
		if(m1[i]!=rhs.m1[i])
			return false;

	for(i=0;i<N*(1+N)/2;i++)
		if(m2[i]!=rhs.m2[i])
			return false;
	return true;
}
//## begin module.epilog preserve=yes
//## end module.epilog
#endif

#include <fstream>
#include "TLAS/LinearAlgebra.h"
#include <algorithm> // for std::swap
#include <cmath>

#ifndef DEBUG
#include "NumericalUtils/MatrixPrinter.h"
#endif

namespace {
	
#ifndef DEBUG
	ofstream debug_os("tlas_debug.dat");
#endif

	// MSVC++ bug! Compiler should make correct resolution for abs()!!
	inline double ABS(double x) { return fabs(x); }
	inline double ABS(const Complex& z) { return abs(z); }

#define _SWAP(a,b) std::swap((a),(b))
	
	template<class T> double Inverse(Matrix<T>& a)
	{
		
		if(a.nrows() != a.ncols())
			throw TLAS::NonSquareMatrix();
		
		int n = a.nrows();
		
		Vector<int> indxc(n);
		Vector<int> indxr(n);
		Vector<int> ipiv(n);
		
		int icol, irow;
		double minpiv=1.0e9;
		double big;
		T dum, pivinv;
		
		for(int j=0; j<n; j++)
			ipiv(j)=0;
		
		for(int i=0; i<n; i++)
		{
			big = 0.0;
			for(j=0; j<n; j++)
				if(ipiv(j) != 1)
					for(int k=0; k<n; k++)
					{
						if(ipiv(k)==0)
						{
							if(ABS(a(j,k))>=big)
							{
								big = ABS(a(j,k));
								irow=j;
								icol=k;
							}
						}
						else if (ipiv[k]>1) 
							throw TLAS::SingularMatrix();
					}
					++ipiv(icol);
					
					if(irow!=icol)
						for(int l=0; l<n; l++) _SWAP(a(irow,l),a(icol,l));
						
						indxr(i)=irow;
						indxc(i)=icol;
						if(ABS(a(icol,icol))<minpiv) minpiv=ABS(a(icol,icol));
						if(minpiv==0.0)
						{
							cout<<"Singular"<<endl;
							throw TLAS::SingularMatrix();
						}
						
						pivinv = 1.0 / a(icol,icol);
						a(icol,icol) = 1.0;
						for(int l=0; l<n; l++) a(icol,l) *= pivinv;
						
						for(int m=0; m<n; m++)
							if(m!=icol)
							{
								dum = a(m,icol);
								a(m,icol) = 0.0;
								for(int l=0; l<n; l++) a(m,l) -= a(icol,l)*dum;
							}
		}
		
		for(int l=n-1; l>=0; l--)
		{
			if(indxr(l)!=indxc(l))
				for(int k=0; k<n; k++) _SWAP(a(k,indxr(l)),a(k,indxc(l)));
		}
		return minpiv;
	}
}; // end anonymous namespace

namespace TLAS {
	
	void EigenSystem(RealMatrix& t, ComplexVector& eigenvalues, ComplexMatrix& eigenvectors)
	{
		ComplexMatrix m(t);
		Matrix<int> s(6,6,0);
		
		s(0,1) = s(2,3) = s(4,5) = 1;
		s(1,0) = s(3,2) = s(5,4) = -1;
		
		eigenvalues.redim(3);
		eigenvectors.redim(3,6);

		for(int pln=0; pln<3; pln++)
		{
			//Guess an eigenvalue
			Complex cos_mu((t(2*pln,2*pln)+t(2*pln+1,2*pln+1))/2.0,0);
			Complex isin_mu = sqrt(cos_mu*cos_mu - Complex(1,0));
			Complex lambda(cos_mu + isin_mu);
			
			//Guess an eigenvector
			ComplexVector b(0.0,6);
			b(2*pln) = Complex(1/sqrt(2));
			b(2*pln+1) = b(2*pln);
			
			//Iterate!
			ComplexMatrix mp(m);
			
			double prox = 1.0;
			int iter = 0;
			while(prox>1.0e-22 && iter<100)
			{
				for(Subscript n=0; n<6; n++) 
					mp(n,n) = m(n,n) - lambda;
				
				ComplexMatrix minv(mp);
				prox = Inverse(minv);
				
				ComplexVector y(6);
				for(Subscript row=0; row<6; row++)
				{
					Complex sum=0.0;
					for(Subscript col=0; col<6; col++)
						sum += minv(row,col) * b(col);
					y(row) = sum;
				}
				
				Complex ynorm = 0.0;
				Complex ydotb = 0.0;
				for(n=0; n<6; n++)
				{
					ynorm += y(n) * y(n);
					ydotb += y(n) * b(n);
				}
				
				b = y / sqrt(ynorm);
				lambda += 1.0/ydotb;
				iter++;
			}
			
			//Now normalise to Transpose[Conjugate[b]].s.b = I
			Complex bnorm = 0.;
			
			for(Subscript row=0; row<6; row++) {
				for(Subscript col=0; col<6; col++) {
					bnorm += Complex(real(b(row)),-imag(b(row))) * Complex(0,-s(row,col)) * b(col);
				}
			}
			for(row=0; row<6; row++) {
				b(row) *= sqrt(Complex(1,0)/bnorm);
			}
			
			//		eigenvalues.push_back(lambda);
			//		eigenvectors.push_back(b);
			eigenvalues(pln) = lambda;
			eigenvectors.row(pln) = b;
		}
	}
	
	void Symplectify(RealMatrix& a)
	{
		IdentityMatrix Ident(6);
		RealMatrix I(Ident);
		RealMatrix s(Ident);
		
		for(int n=0; n<3; n++)
		{
			int m = 2 * n;
			s(m,m) = s(m+1,m+1) = 0;
			s(m,m+1) = 1;
			s(m+1,m) = -1;
		}
		
		RealMatrix Ipa(I + a);
#ifndef DEBUG
		MatrixForm(Ipa,debug_os);
#endif
		Inverse(Ipa);
		
		RealMatrix Ima(I - a);
		RealMatrix v(s * Ima * Ipa);
		
		RealMatrix w(6);
		for(int row=0; row<6; row++)
			for(int col=0; col<6; col++)
				w(row,col) = (v(row,col) + v(col,row))/2;
			
			RealMatrix sw(s * w);
			
			a = I - sw;
			Inverse(a);
			a = a * (I + sw);
			
			//Check Symplecticity
			/*	RealMatrix aT(6);
			for(row=0; row<6; row++)
			for(int col=0; col<6; col++)
			aT(row,col) = a(col,row);
			
			  RealMatrix aTsa(aT * s * a);
			  ofstream smatrix("smatrix.dat");
			  for(row=0; row<6; row++)
			  {
			  for(int col=0; col<6; col++) smatrix<<std::setw(14)<<aTsa(row,col);
			  smatrix<<endl;
			  }
			*/
	}
	
}; // end namespace TLAS
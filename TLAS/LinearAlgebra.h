// TLAS/LinearAlgebra.h

#ifndef _h_LinearAlgebra
#define _h_LinearAlgebra

#include "TLAS/TLAS.h"
#include "NumericalUtils/Complex.h"

namespace TLAS {
	
	//explicite instantiation for doubles
	template class Vector<double>;
	template class Matrix<double>;
	template class SubVector<double>;
	template class SubMatrix<double>;
	template class ConstSubVector<double>;
	template class ConstSubMatrix<double>;	
	
	typedef Vector<double> RealVector;
	typedef Matrix<double> RealMatrix;

	// explicite instantion for Complex
	template class Vector<Complex>;
	template class Matrix<Complex>;
	template class SubVector<Complex>;
	template class SubMatrix<Complex>;
	template class ConstSubVector<Complex>;
	template class ConstSubMatrix<Complex>;	
	
	typedef Vector<Complex> ComplexVector;
	typedef Matrix<Complex> ComplexMatrix;

	// Eigensystem
	void EigenSystem(RealMatrix& t, ComplexVector& eigenvalues, ComplexMatrix& eigenvectors);

	// Matrix symplectification
	void Symplectify(RealMatrix& a);

	// Eigensystem of a real symmetric matrix
	void EigenSystemSymmetricMatrix(RealMatrix& m, RealVector& eigenvalues);

}; // end namespace TLAS;

using namespace TLAS;

#endif

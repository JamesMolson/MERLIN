#include "BasicTransport/RTMap.h"
#include "NumericalUtils/MatrixPrinter.h"
#include "TLAS/LinearAlgebra.h"

PSvector RTMap::TermBase::X(0);

void RTMap::Print(std::ostream& os) const
{

	OPFormat opf(6);
	opf.scientific();

	// First output the linear map
	os<<"R:\n";
	{
		RealMatrix M(6,6,0.0);
		for(RtermList::const_iterator t = rs.begin(); t!=rs.end(); t++)
			M(t->i,t->j) = t->v;

		MatrixForm(M,os);
	}

	os<<"\nT:\n";
	for(int n=0;n<6;n++) {
		RealMatrix M(6,6,0.0);
		for(TtermList::const_iterator t = ts.begin(); t!=ts.end(); t++){
			if((t->i)==n) {
				if(t->j != t->k)
					M(t->k,t->j) = M(t->j,t->k) = t->v/2;
				else
					M(t->j,t->k) = t->v;
			}
		}
		MatrixForm(M,os,opf);
		os<<endl;
	}
}


	
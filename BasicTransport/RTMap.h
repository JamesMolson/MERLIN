// class RTMap
//
// A second-order TRANSPORT map for a PSvector
//
// class RTMap represents both the first-order R and second-order T TRANSPORT
// matrices. For efficiency, only non-zero terms are stored.

#ifndef _h_RTMap
#define _h_RTMap 1

#include "BeamModel/PSTypes.h"
#include <list>
#include <algorithm>
#include <iostream>

class RTMap {
private:

	class TermBase {
	public:
		TermBase(int i1, int j1):i(i1-1),j(j1-1) {}
		double v;
		const int i,j;
		static PSvector X;
	};

	class Rterm : public TermBase {
	public:
		Rterm(int i1, int j1) : TermBase(i1,j1) {}
		void operator()(const PSvector& p) const {
			X[i]+=v*p[j];
		}
	};

	class Tterm : public TermBase {
	public:
		Tterm(int i1, int j1, int k1)
			: TermBase(i1,j1),k(k1-1) {}
		void operator()(const PSvector& p) const {
			X[i]+=v*p[j]*p[k];
		}
		const int k;
	};

	typedef std::list<Rterm> RtermList;
	typedef std::list<Tterm> TtermList;

	struct ApplyMap {
		const PSvector& x0;
		ApplyMap(const PSvector& x) : x0(x) {}
		template<class M> 
			void operator()(const M& amap) { amap(x0); }
	};

public:

	// Construction
	RTMap() {}

	// Adding terms. Note that no effort 
	// is  made to check that a term has
	// not been added more than once.

	double& operator()(int i, int j) {
		rs.push_back(Rterm(i,j));
		return rs.back().v;
	}

	double& operator()(int i, int j, int k) {
		ts.push_back(Tterm(i,j,k));
		return ts.back().v;
	}

	//double operator()(int i, int j) const;
	//double operator()(int i, int j, int k) const;

	// Operating on a PSvector

	PSvector& Apply(PSvector& p) const {
		TermBase::X.zero();
		std::for_each(rs.begin(),rs.end(),ApplyMap(p));
		std::for_each(ts.begin(),ts.end(),ApplyMap(p));
		return p = TermBase::X;
	}

	// output
	void Print(std::ostream&) const;

private:

	RtermList rs;
	TtermList ts;
};


#endif
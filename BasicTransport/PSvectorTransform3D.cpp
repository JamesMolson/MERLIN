//## begin module%372ADFE502F8.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BasicTransport\PSvectorTransform3D.cpp
 * last modified 04/04/01 14:41:34
 */
//## end module%372ADFE502F8.cm

//## begin module%372ADFE502F8.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 *
 * Copyright (c) 2000 by The Merlin Collaboration.  
 * ALL RIGHTS RESERVED. 
 *
 * Permission to use, copy, modify, distribute and sell this
 * software and its documentation for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * No representations about the suitability of this software for
 * any purpose is made. It is provided "as is" without express
 * or implied warranty.
 */
//## end module%372ADFE502F8.cp

//## Module: PSvectorTransform3D%372ADFE502F8; Pseudo Package body
//## Subsystem: Merlin::BasicTransport%36BDEB0A021C
//## Source file: D:\dev\Merlin\BasicTransport\PSvectorTransform3D.cpp

//## begin module%372ADFE502F8.includes preserve=yes
//## end module%372ADFE502F8.includes

// PSvectorTransform3D
#include "BasicTransport/PSvectorTransform3D.h"
//## begin module%372ADFE502F8.additionalDeclarations preserve=yes
//## end module%372ADFE502F8.additionalDeclarations


// Class PSvectorTransform3D 



//## Operation: PSvectorTransform3D%925557236
PSvectorTransform3D::PSvectorTransform3D (const Transform3D& tfrm)
  //## begin PSvectorTransform3D::PSvectorTransform3D%925557236.initialization preserve=yes
  :T(tfrm),bNoRot(tfrm.R().isIdentity())
  //## end PSvectorTransform3D::PSvectorTransform3D%925557236.initialization
{
  //## begin PSvectorTransform3D::PSvectorTransform3D%925557236.body preserve=yes
  //## end PSvectorTransform3D::PSvectorTransform3D%925557236.body
}



//## Other Operations (implementation)
//## Operation: Apply%925557237
PSvector& PSvectorTransform3D::Apply (PSvector& p) const
{
  //## begin PSvectorTransform3D::Apply%925557237.body preserve=yes
	if(bNoRot) {
		// drift space with transverse displacement
		p.x()+=(T.X().z*p.xp()-T.X().x);
		p.y()+=(T.X().z*p.yp()-T.X().y);
		p.ct()+=T.X().z; //dubious
	}
	else {
		Point3D X(p.x(),p.y(),0);
		Vector3D V(p.xp(),p.yp(),1.0);
		
		X=T(X);
		V=T(V);
		
		// re-scale the "momentum" vector to (x',y',1)
		V.x/=V.z;
		V.y/=V.z;
		
		// copy back to p, applying any necessary drift
		// to bring z to zero
		p.x()  = X.x-X.z*V.x;
		p.y()  = X.y-X.z*V.y;
		p.ct()-= X.z; //dubious
		p.xp() = V.x;
		p.yp() = V.y;
	}
	return p;
  //## end PSvectorTransform3D::Apply%925557237.body
}

//## Operation: Apply%925557238
PSvectorArray& PSvectorTransform3D::Apply (PSvectorArray& pv) const
{
  //## begin PSvectorTransform3D::Apply%925557238.body preserve=yes
	std::for_each(pv.begin(),pv.end(),*this);
	return pv;
  //## end PSvectorTransform3D::Apply%925557238.body
}

//## begin module%372ADFE502F8.epilog preserve=yes
//## end module%372ADFE502F8.epilog

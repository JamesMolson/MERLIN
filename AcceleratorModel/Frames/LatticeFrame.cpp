//## begin module%3AB0CE2603A2.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Frames\LatticeFrame.cpp
 * last modified 05/04/01 12:24:01
 */
//## end module%3AB0CE2603A2.cm

//## begin module%3AB0CE2603A2.cp preserve=no
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
//## end module%3AB0CE2603A2.cp

//## Module: LatticeFrame%3AB0CE2603A2; Package body
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Source file: D:\dev\Merlin\AcceleratorModel\Frames\LatticeFrame.cpp

//## begin module%3AB0CE2603A2.includes preserve=yes
#include <cassert>
//## end module%3AB0CE2603A2.includes

// LatticeFrame
#include "AcceleratorModel/Frames/LatticeFrame.h"
//## begin module%3AB0CE2603A2.declarations preserve=no
//## end module%3AB0CE2603A2.declarations

//## begin module%3AB0CE2603A2.additionalDeclarations preserve=yes
#define VALID_SFRAME(sframe) \
assert(sframe==this || sframe==GLOBAL_FRAME || superFrame!=GLOBAL_FRAME)

// macro for transformations
#define _TRNSFM(func) \
	if(local_T) (*local_T)*=Transform3D::func; \
	else local_T = new Transform3D(Transform3D::func); \
	Invalidate();
//## end module%3AB0CE2603A2.additionalDeclarations


// Class LatticeFrame 










//## Other Operations (implementation)
//## Operation: GetFrameTransform%951841363
Transform3D LatticeFrame::GetFrameTransform (const LatticeFrame* sframe) const
{
  //## begin LatticeFrame::GetFrameTransform%951841363.body preserve=yes

	if(sframe==GLOBAL_FRAME)
		sframe = GetGlobalFrame();

	// The frame transformation to itself is the identity
	if(sframe==this)
		return Transform3D();
	
	if(sframe==superFrame)
		return GetLocalFrameTransform();


	Transform3D t1 = GetPhysicalTransform(sframe);
	double s = GetPosition(sframe);


	Transform3D t2 = sframe->GetGeometryTransform(s);

	return t1*t2.inv();
  //## end LatticeFrame::GetFrameTransform%951841363.body
}

//## Operation: GetPhysicalTransform%984653907
Transform3D LatticeFrame::GetPhysicalTransform (const LatticeFrame* sframe) const
{
  //## begin LatticeFrame::GetPhysicalTransform%984653907.body preserve=yes
	VALID_SFRAME(sframe);	

	// The frame transformation to itself is the identity.
	if(sframe==this)
		return Transform3D();
	
	Transform3D t0 = GetLocalFrameTransform();

	if(superFrame!=GLOBAL_FRAME) {
		Transform3D t1 = superFrame->GetGeometryTransform(0,s_0);
		Transform3D t2 = superFrame->GetPhysicalTransform(sframe);
		t0=t0*t1*t2;
	}

	return t0;
  //## end LatticeFrame::GetPhysicalTransform%984653907.body
}

//## Operation: GetPosition%951841365
double LatticeFrame::GetPosition (const LatticeFrame* sframe) const
{
  //## begin LatticeFrame::GetPosition%951841365.body preserve=yes
	VALID_SFRAME(sframe);	
	return sframe==superFrame ? s_0 : s_0 + superFrame->GetPosition(sframe);
  //## end LatticeFrame::GetPosition%951841365.body
}

//## Operation: GetGeometryExtent%984653908
AcceleratorGeometry::Extent LatticeFrame::GetGeometryExtent (const LatticeFrame* sframe) const
{
  //## begin LatticeFrame::GetGeometryExtent%984653908.body preserve=yes
	AcceleratorGeometry::Extent extent = GetLocalGeometryExtent();
	double s = GetPosition(sframe);	
	extent.first += s;
	extent.second += s;
	return extent;
  //## end LatticeFrame::GetGeometryExtent%984653908.body
}

//## Operation: GetBoundaryPlaneTransform%951841359
Transform3D LatticeFrame::GetBoundaryPlaneTransform (BoundaryPlane p) const
{
  //## begin LatticeFrame::GetBoundaryPlaneTransform%951841359.body preserve=yes
	// we ignore any global transformations of the top-level frame
	if(superFrame==GLOBAL_FRAME)
		return Transform3D();

	Transform3D t0=LocalBoundaryPlaneTransform(p);
	if(superFrame!=0 && superFrame->IsBoundaryPlane(p,this))
		t0=t0*(superFrame->GetBoundaryPlaneTransform(p));
	return t0;
  //## end LatticeFrame::GetBoundaryPlaneTransform%951841359.body
}

//## Operation: Translate%985116511
void LatticeFrame::Translate (double dx, double dy, double dz)
{
  //## begin LatticeFrame::Translate%985116511.body preserve=yes
	_TRNSFM(translation(dx,dy,dz));
  //## end LatticeFrame::Translate%985116511.body
}

//## Operation: RotateX%985116512
void LatticeFrame::RotateX (double angle)
{
  //## begin LatticeFrame::RotateX%985116512.body preserve=yes
	_TRNSFM(rotationX(angle));
  //## end LatticeFrame::RotateX%985116512.body
}

//## Operation: RotateY%985116513
void LatticeFrame::RotateY (double angle)
{
  //## begin LatticeFrame::RotateY%985116513.body preserve=yes
	_TRNSFM(rotationY(angle));
  //## end LatticeFrame::RotateY%985116513.body
}

//## Operation: RotateZ%985116514
void LatticeFrame::RotateZ (double angle)
{
  //## begin LatticeFrame::RotateZ%985116514.body preserve=yes
	_TRNSFM(rotationZ(angle));
  //## end LatticeFrame::RotateZ%985116514.body
}

//## Operation: ApplyLocalFrameTransform%985116515
void LatticeFrame::ApplyLocalFrameTransform (const Transform3D& t)
{
  //## begin LatticeFrame::ApplyLocalFrameTransform%985116515.body preserve=yes
	if(!local_T)
		local_T = new Transform3D(t);
	else
		(*local_T)*=t;

	Invalidate();
  //## end LatticeFrame::ApplyLocalFrameTransform%985116515.body
}

//## Operation: SetLocalFrameTransform%985116516
void LatticeFrame::SetLocalFrameTransform (const Transform3D& t)
{
  //## begin LatticeFrame::SetLocalFrameTransform%985116516.body preserve=yes
	if(!local_T)
		local_T = new Transform3D(t);
	else
		(*local_T)=t;

	Invalidate();
  //## end LatticeFrame::SetLocalFrameTransform%985116516.body
}

//## Operation: ClearLocalFrameTransform%985116517
void LatticeFrame::ClearLocalFrameTransform ()
{
  //## begin LatticeFrame::ClearLocalFrameTransform%985116517.body preserve=yes
	if(local_T){
		delete local_T;
		local_T=0;
	}
	Invalidate();
  //## end LatticeFrame::ClearLocalFrameTransform%985116517.body
}

//## Operation: GetGlobalFrame%985792509
LatticeFrame* LatticeFrame::GetGlobalFrame () const
{
  //## begin LatticeFrame::GetGlobalFrame%985792509.body preserve=yes
	return superFrame==0 ? const_cast<LatticeFrame*>(this) : superFrame->GetGlobalFrame();
  //## end LatticeFrame::GetGlobalFrame%985792509.body
}

//## Operation: LocalBoundaryPlaneTransform%984653919
Transform3D LatticeFrame::LocalBoundaryPlaneTransform (BoundaryPlane p) const
{
  //## begin LatticeFrame::LocalBoundaryPlaneTransform%984653919.body preserve=yes
	Transform3D t0 = GetLocalFrameTransform();
	if(!t0.isIdentity()) {
		Transform3D t = GetGeometryTransform(p);
		return t*t0*t.inv();
	}
	return t0;
  //## end LatticeFrame::LocalBoundaryPlaneTransform%984653919.body
}

//## begin module%3AB0CE2603A2.epilog preserve=yes
//## end module%3AB0CE2603A2.epilog

void LatticeFrame::Traverse(FrameTraverser &ft)
{
	ft.ActOn(this);
}

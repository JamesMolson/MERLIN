//## begin module%395B70170190.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Supports\SupportStructure.cpp
 * last modified 28/03/01 17:23:14
 */
//## end module%395B70170190.cm

//## begin module%395B70170190.cp preserve=no
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
//## end module%395B70170190.cp

//## Module: SupportStructure%395B70170190; Package body
//## Subsystem: Merlin::AcceleratorModel::Supports%395B6FFB0186
//## Source file: D:\dev\Merlin\AcceleratorModel\Supports\SupportStructure.cpp

//## begin module%395B70170190.includes preserve=yes
//## end module%395B70170190.includes

// SupportStructure
#include "AcceleratorModel/Supports/SupportStructure.h"
//## begin module%395B70170190.declarations preserve=no
//## end module%395B70170190.declarations

//## begin module%395B70170190.additionalDeclarations preserve=yes
//## end module%395B70170190.additionalDeclarations


// Class SupportStructure 





//## Operation: SupportStructure%962293951
SupportStructure::SupportStructure (const string& id, Type type)
  //## begin SupportStructure::SupportStructure%962293951.initialization preserve=yes
	: SequenceFrame(id)
  //## end SupportStructure::SupportStructure%962293951.initialization
{
  //## begin SupportStructure::SupportStructure%962293951.body preserve=yes
	sup1 = new AcceleratorSupport();
	sup2 = (type==girder) ? new AcceleratorSupport() : 0;
  //## end SupportStructure::SupportStructure%962293951.body
}

//## Operation: SupportStructure%962293952
SupportStructure::SupportStructure (const SupportStructure& rhs)
  //## begin SupportStructure::SupportStructure%962293952.initialization preserve=yes
: SequenceFrame(rhs)
  //## end SupportStructure::SupportStructure%962293952.initialization
{
  //## begin SupportStructure::SupportStructure%962293952.body preserve=yes
	sup1 = new AcceleratorSupport();
	if(rhs.sup2)
		sup2 = new AcceleratorSupport();
  //## end SupportStructure::SupportStructure%962293952.body
}


//## Operation: ~SupportStructure%962293953
SupportStructure::~SupportStructure ()
{
  //## begin SupportStructure::~SupportStructure%962293953.body preserve=yes
	delete sup1;
	if(sup2)
		delete sup2;
  //## end SupportStructure::~SupportStructure%962293953.body
}



//## Other Operations (implementation)
//## Operation: ExportSupports%962293956
int SupportStructure::ExportSupports (AcceleratorSupportList& supports)
{
  //## begin SupportStructure::ExportSupports%962293956.body preserve=yes
	supports.push_back(sup1);
	if(sup2)
		supports.push_back(sup2);
	return sup2 ? 2:1;
  //## end SupportStructure::ExportSupports%962293956.body
}

//## Operation: GetLocalFrameTransform%985682914
Transform3D SupportStructure::GetLocalFrameTransform () const
{
  //## begin SupportStructure::GetLocalFrameTransform%985682914.body preserve=yes
	UpdateSupportTransform();
	return LatticeFrame::GetLocalFrameTransform()*Ts;
  //## end SupportStructure::GetLocalFrameTransform%985682914.body
}

//## Operation: ConsolidateConstruction%962293960
void SupportStructure::ConsolidateConstruction ()
{
  //## begin SupportStructure::ConsolidateConstruction%962293960.body preserve=yes
	SequenceFrame::ConsolidateConstruction();
	
	Transform3D gT = GetPhysicalTransform(GLOBAL_FRAME);
	double s0 = GetPosition(GLOBAL_FRAME);
	
	if(!sup2) {
		// support is at origin, so this is now trivial
		sup1->SetPosition(s0,gT.X().x,gT.X().z);
		Rg = gT.R();
	}
	else {
		// Here life gets a little more complicated, as we need to transform
		// the origin information to the entrance and exit of the frame,
		// as that's where the supports are located.
		AcceleratorGeometry::Extent ext=GetLocalGeometryExtent();
		
		Transform3D t1 = GetGeometryTransform(AcceleratorGeometry::entrance)*gT;
		sup1->SetPosition(s0+ext.first,t1.X().x,t1.X().z);
		Rg = t1.R();
		
		t1 = GetGeometryTransform(AcceleratorGeometry::exit)*gT;
		sup2->SetPosition(s0+ext.second,t1.X().x,t1.X().z);
	}
  //## end SupportStructure::ConsolidateConstruction%962293960.body
}

//## Operation: UpdateSupportTransform%985600394
void SupportStructure::UpdateSupportTransform () const
{
  //## begin SupportStructure::UpdateSupportTransform%985600394.body preserve=yes
	
	// Check if cached state needs updating, otherwise
	// return.
	
	if(!sup1->modified || (sup2 && !sup2->modified))
		return;
	
	// The local frame transformation t0 must now be modified 
	// by any 'ground motion' like transformation from the
	// AcceleratorSupports.
	
	if(!sup2) {
		// This is the trivial case, with the translation applied 
		// to the centre of the frame
		Vector3D X = Rg(sup1->GetOffset());
		Ts = Transform3D::translation(X.x,X.y,X.z);
	}
	else {
		// This is much more complicated, expecially as
		// large offset of the two supports will effectively
		// stretch the geometry. We will assume that the offsets
		// are small, and that the stretching is negligble.
		
		Vector3D X1 = Rg(sup1->GetOffset());
		Vector3D X2 = Rg(sup2->GetOffset());
		
		// check to see if we have a simple translation
		if(X1==X2)
			Ts = Transform3D::translation(X1.x,X1.y,X1.z);
		else {
			
			// Approximate rotations about x- and y-axis.
			Vector3D dX=X2-X1;
			double s0 = sup1->DistanceTo(*sup2);
			double phix = -dX.y/s0;
			double phiy =  dX.x/s0;
			
			// Calculate the approximate transformation caused by the two offsets
			// about the entrance plane reference frame.
			
			Rotation3D R = Rotation3D::rotationX(phix)*Rotation3D::rotationY(phiy);
			Transform3D T1 = Transform3D(Point3D(X1.x,X1.y,X1.z),R);
			
			// Convert Ts to a transformation about the local frame origin.
			Transform3D Tin = GetGeometryTransform(AcceleratorGeometry::entrance);
			Ts = Tin.inv()*T1*Tin;
		}
	}

	sup1->modified = false;
	if(sup2)
		sup2->modified = false;
  //## end SupportStructure::UpdateSupportTransform%985600394.body
}

// Class GirderMount 


//## Other Operations (implementation)
//## Operation: GetType%962293958
const string& GirderMount::GetType () const
{
  //## begin GirderMount::GetType%962293958.body preserve=yes
	_TYPESTR(GirderMount);
  //## end GirderMount::GetType%962293958.body
}

//## Operation: Copy%962293959
ModelElement* GirderMount::Copy () const
{
  //## begin GirderMount::Copy%962293959.body preserve=yes
	return new GirderMount(*this);
  //## end GirderMount::Copy%962293959.body
}

// Class SimpleMount 


//## Other Operations (implementation)
//## Operation: GetType%985792507
const string& SimpleMount::GetType () const
{
  //## begin SimpleMount::GetType%985792507.body preserve=yes
	_TYPESTR(SimpleMount);
  //## end SimpleMount::GetType%985792507.body
}

//## Operation: Copy%985792508
ModelElement* SimpleMount::Copy () const
{
  //## begin SimpleMount::Copy%985792508.body preserve=yes
	return new SimpleMount(*this);
  //## end SimpleMount::Copy%985792508.body
}

//## begin module%395B70170190.epilog preserve=yes
//## end module%395B70170190.epilog

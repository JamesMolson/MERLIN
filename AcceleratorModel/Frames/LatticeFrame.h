//## begin module%3AB0CE1D0104.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Frames\LatticeFrame.h
 * last modified 05/04/01 12:24:01
 */
//## end module%3AB0CE1D0104.cm

//## begin module%3AB0CE1D0104.cp preserve=no
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
//## end module%3AB0CE1D0104.cp

//## Module: LatticeFrame%3AB0CE1D0104; Package specification
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Source file: D:\dev\Merlin\AcceleratorModel\Frames\LatticeFrame.h

#ifndef LatticeFrame_h
#define LatticeFrame_h 1

//## begin module%3AB0CE1D0104.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AB0CE1D0104.additionalIncludes

//## begin module%3AB0CE1D0104.includes preserve=yes
//## end module%3AB0CE1D0104.includes

// ModelElement
#include "AcceleratorModel/ModelElement.h"
// AcceleratorGeometry
#include "AcceleratorModel/AcceleratorGeometry.h"
// Transform3D
#include "EuclideanGeometry/Transform3D.h"
//## begin module%3AB0CE1D0104.declarations preserve=no
//## end module%3AB0CE1D0104.declarations

//## begin module%3AB0CE1D0104.additionalDeclarations preserve=yes
#define GLOBAL_FRAME (LatticeFrame*)0
//## end module%3AB0CE1D0104.additionalDeclarations

// Class FrameTraverser
// An abstract iterator class that is used to
// traverse in order the nested frame hierachy
class LatticeFrame;

class FrameTraverser {
public:

	virtual ~FrameTraverser() {}
	virtual void ActOn(LatticeFrame* frame) =0;
};

//## Class: LatticeFrame%38BBB00D01B8; Abstract
//	A LatticeFrame is a ModelElement that provides a
//	coordinate system for a subsection of the accelerator
//	lattice. A lattice frame is located on the accelerator
//	geometry at a specified position s. LatticeFrames can be
//	nested in a frame hierachy, but may not partially
//	overlap. A LatticeFrame may represent the frame for a
//	single component (see class ComponentFrame), or may be
//	constructed from a contiguous sequence of LatticeFrames
//	(sub-frames).
//
//	Since each LatticeFrame contains a section of the
//	lattice, it represents the AcceleratorGeometry for that
//	section (which forms a sub-geometry of the total lattice
//	geometry). A LatticeFrame can therefore provide all the
//	geometry transformation functions within the its local
//	s-frame. Sub-frames of a LatticeFrame are located at
//	specific (local) s positions on that geometry.
//
//	LatticeFrames can be rotated and translated.
//	Rotating/translating a LatticeFrame rotates/translates
//	all the associated sub-frames. LatticeFrame provides
//	methods for accessing the various coordinate
//	transformations between various frames in the hierachy.
//	Two types of coordinate transformations are
//	distinguished:
//
//	- Frame Transformations: if the location of a Lattice
//	Frame on a super-frames geometry is s, then the frame
//	transformation to that super-frame is defined as the
//	coordinate transformation between the LatticeFrame's
//	local coordinate frame, and the coordinate frame defined
//	on the super-frame's geometry at s. Note that if no
//	rotations have been applied to any of the frames in the
//	hierachy (up to the specified super-frame), then the
//	frame transformation is always the identity.
//
//	- Physical Transformations: The physical transformation
//	from a LatticeFrame to a specified super-frame is the
//	total coordinate transformation between the local frame
//	of the LatticeFrame, and the local frame of the
//	super-frame. This transformation represents the physical
//	3-D location and orientation of the LatticeFrame's local
//	frame in the local frame of the super-frame. In general
//	it is not the identity, even when no transformations
//	have been applied.
//
//	Frame Transformations are most important during typical
//	beam dynamics tracking operations, while Physical
//	Transformations can be used for surveying.
//## Category: Merlin::AcceleratorModel::Frames%3AB0B5BC015E
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class LatticeFrame : public ModelElement  //## Inherits: <unnamed>%3906DBB2007C
{
  public:
    //## Class: BoundaryPlane%3AB0DB390104
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef AcceleratorGeometry::BoundaryPlane BoundaryPlane;

  public:
    //## Constructors (specified)
      //## Operation: LatticeFrame%954184457
      //	Constructor
      explicit LatticeFrame (const string& id = "");

      //## Operation: LatticeFrame%956820765
      //	Copy constructor.
      LatticeFrame (const LatticeFrame& rhs);

    //## Destructor (specified)
      //## Operation: ~LatticeFrame%984653918
      virtual ~LatticeFrame ();


    //## Other Operations (specified)
      //## Operation: GetFrameTransform%951841363
      //	Frame Transformations.
      //
      //	Returns the frame transformation from the specified
      //	super-frame to this frame.
      virtual Transform3D GetFrameTransform (const LatticeFrame* sframe = GLOBAL_FRAME) const;

      //## Operation: GetLocalFrameTransform%951841364
      //	Returns the frame transformation from the immediate
      //	super-frame, i.e. the result of all transformations
      //	applied to this frame.
      virtual Transform3D GetLocalFrameTransform () const;

      //## Operation: GetPhysicalTransform%984653907
      //	Physical Transformations.
      //
      //	Returns the physical transformation from the specified
      //	super-frame to this frame.
      Transform3D GetPhysicalTransform (const LatticeFrame* sframe = GLOBAL_FRAME) const;

      //## Operation: GetLocalPhysicalTransform%984653909
      //	Returns the physical transformation from the immediate
      //	super-frame.
      Transform3D GetLocalPhysicalTransform () const;

      //## Operation: GetGeometry%984653910
      //	AcceleratorGeometry related operations.
      //
      //	Return the associated AcceleratorGeometry.
      const AcceleratorGeometry& GetGeometry () const;

      //## Operation: GetPosition%951841365
      //	Returns the position of this frame's origin in the
      //	specified super-frames s-frame.
      double GetPosition (const LatticeFrame* sframe = GLOBAL_FRAME) const;

      //## Operation: GetLocalPosition%984653911
      //	Returns the position of this frame's origin in the
      //	immediate super-frames s-frame.
      double GetLocalPosition () const;

      //## Operation: GetGeometryTransform%984653912
      //	Returns the AcceleratorGeometry transformation from s0
      //	to s (local s-frame).
      Transform3D GetGeometryTransform (double s0, double s) const throw (AcceleratorGeometry::BeyondExtent);

      //## Operation: GetGeometryTransform%985850581
      //	Returns the AcceleratorGeometry transformation from the
      //	local origin to s (local s-frame).
      Transform3D GetGeometryTransform (double s) const throw (AcceleratorGeometry::BeyondExtent);

      //## Operation: GetGeometryTransform%984653913
      //	Returns the transformation from the origin to the
      //	specified boundary plane.
      Transform3D GetGeometryTransform (BoundaryPlane p) const;

      //## Operation: GetTotalGeometryTransform%984653914
      //	Returns the transformation from the entrance plane frame
      //	to the exit plane frame.
      Transform3D GetTotalGeometryTransform () const;

      //## Operation: GetGeometryExtent%984653908
      //	Returns the extent of this frame's geometry in the
      //	s-frame of the specified super-frame.
      AcceleratorGeometry::Extent GetGeometryExtent (const LatticeFrame* sframe = GLOBAL_FRAME) const;

      //## Operation: GetLocalGeometryExtent%984653915
      //	Returns the local extent of this frame's geometry, i.e.
      //	the extent in the local s-frame.
      AcceleratorGeometry::Extent GetLocalGeometryExtent () const;

      //## Operation: GetGeometryLength%984653916
      //	Returns the total arc-length of the associated geometry.
      double GetGeometryLength () const;

      //## Operation: GetBoundaryPlaneTransform%951841359
      //	Returns transformation to the specified boundary plane
      //	reference frame. The transformation includes all effects
      //	of nested boundary planes which occur at the plane.
      virtual Transform3D GetBoundaryPlaneTransform (BoundaryPlane p) const;

      //## Operation: GetEntrancePlaneTransform%985283453
      //	Used during tracking. Returns the required
      //	transformation to the local entrance plane coordinate
      //	frame. Includes the effects of all nested frame
      //	boundaries which occur at this location.
      Transform3D GetEntrancePlaneTransform () const;

      //## Operation: GetExitPlaneTransform%985283454
      //	Used during tracking. Returns the required
      //	transformation from the local exit plane coordinate
      //	frame. Includes the effects of all nested frame
      //	boundaries which occur at this location.
      Transform3D GetExitPlaneTransform () const;

      //## Operation: IsTransformed%984653920
      //	Returns true if this frame has been locally transformed.
      bool IsTransformed () const;

      //## Operation: Translate%985116511
      //	Translates the frame by the relative vector (dx,dy,dz).
      void Translate (double dx, double dy, double dz);

      //## Operation: Translate%985116518
      //	Translates the frame by the relative vector X.
      void Translate (const Vector3D& X);

      //## Operation: TranslateX%986466241
      //	Translates the frame along the current x-axis by dx.
      void TranslateX (double dx);

      //## Operation: TranslateY%986466242
      //	Translates the frame along the current y-axis by dy.
      void TranslateY (double dy);

      //## Operation: TranslateZ%986466243
      //	Translates the frame along the current z-axis by dz.
      void TranslateZ (double dz);

      //## Operation: RotateX%985116512
      //	Rotates the frame about the current x-axis by angle.
      void RotateX (double angle);

      //## Operation: RotateY%985116513
      //	Rotates the frame about the current y-axis by angle.
      void RotateY (double angle);

      //## Operation: RotateZ%985116514
      //	Rotates the frame about the current z-axis by angle.
      void RotateZ (double angle);

      //## Operation: ApplyLocalFrameTransform%985116515
      //	Transform the frame (with respect to the current axes)
      //	by the transformation t.
      void ApplyLocalFrameTransform (const Transform3D& t1);

      //## Operation: SetLocalFrameTransform%985116516
      //	Set the local  frame transformation for this object.
      void SetLocalFrameTransform (const Transform3D& t);

      //## Operation: ClearLocalFrameTransform%985116517
      //	Clear the local frame transformation.
      void ClearLocalFrameTransform ();

      //## Operation: Invalidate%951848913
      //	Causes any cached state to be invalidated. The cached
      //	state should be re-calculated if and when required.
      virtual void Invalidate () const;

      //## Operation: ConsolidateConstruction%962031291
      //	Function called after construction of the Accelerator
      //	Model is complete. Allows the nested frame hierachy to
      //	perform certain state checks and updates, which are only
      //	possible once the entire model is complete.
      virtual void ConsolidateConstruction ();

      //## Operation: SetLocalPosition%951848933
      //	Sets the position of the LatticeFrame on the immediate
      //	super-frame's geometry.
      void SetLocalPosition (double s);

      //## Operation: SetSuperFrame%951841367
      //	Set the super frame of this LatticeFrame object. Returns
      //	the old super frame.
      LatticeFrame* SetSuperFrame (LatticeFrame* aFrame);

      //## Operation: ReplaceSubFrame%985182997
      //	Replace subFrame with newSubFrame. Returns true if
      //	successful (i.e. subFrame is a sub-frame of this Lattice
      //	Frame).
      virtual bool ReplaceSubFrame (LatticeFrame* subFrame, LatticeFrame* newSubFrame);

      //## Operation: IsGlobalFrame%985792510
      //	Returns true if this frame is the top-level frame of the
      //	hierachy.
      bool IsGlobalFrame () const;

      //## Operation: GetGlobalFrame%985792509
      //	Returns the top-level (global)  frame of the hieracy.
      LatticeFrame* GetGlobalFrame () const;

	  // Iterate a FrameTraverese object over the underlying
	  // frame hierachy.
	  virtual void Traverse(FrameTraverser& ft);

  protected:

    //## Other Operations (specified)
      //## Operation: SetGeometry%984653917
      //	Protected function called by concrete LatticeFrame
      //	classes during construction.
      void SetGeometry (const AcceleratorGeometry* geom);


  private:
    // Data Members for Class Attributes

      //## Attribute: s_0%38BBF2E0024E
      //	The s-position of this frame's origin on the super-frame
      //	s-frame.
      //## begin LatticeFrame::s_0%38BBF2E0024E.attr preserve=no  private: double {UA} 
      double s_0;
      //## end LatticeFrame::s_0%38BBF2E0024E.attr

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Frames::<unnamed>%3AB0DDEC0226
      //## Role: LatticeFrame::local_T%3AB0DDED02F8
      //	The local transformation for this frame.
      //## begin LatticeFrame::local_T%3AB0DDED02F8.role preserve=no  private: Transform3D { -> 0..1VHAN}
      Transform3D* local_T;
      //## end LatticeFrame::local_T%3AB0DDED02F8.role

      //## Association: Merlin::AcceleratorModel::Frames::<unnamed>%3AC23BD101B8
      //## Role: LatticeFrame::superFrame%3AC23BD300FA
      //## begin LatticeFrame::superFrame%3AC23BD300FA.role preserve=no  private: LatticeFrame { -> 0..1RHAN}
      LatticeFrame* superFrame;
      //## end LatticeFrame::superFrame%3AC23BD300FA.role

      //## Association: Merlin::AcceleratorModel::Frames::<unnamed>%3AB0C77C02D0
      //## Role: LatticeFrame::itsGeometry%3AB0C77D02C6
      //	The geometry associated with this frame.
      //## begin LatticeFrame::itsGeometry%3AB0C77D02C6.role preserve=no  private: AcceleratorGeometry { -> 1RHANC}
      const AcceleratorGeometry *itsGeometry;
      //## end LatticeFrame::itsGeometry%3AB0C77D02C6.role

  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: IsBoundaryPlane%951841370
      //	Returns true if aSubFrame is the first (entrance)
      //	sub-frame of this frame.
      virtual bool IsBoundaryPlane (BoundaryPlane p, const LatticeFrame* aSubFrame) const = 0;

      //## Operation: LocalBoundaryPlaneTransform%984653919
      Transform3D LocalBoundaryPlaneTransform (BoundaryPlane p) const;

};

// Class LatticeFrame 

//## Operation: LatticeFrame%954184457
inline LatticeFrame::LatticeFrame (const string& id)
  //## begin LatticeFrame::LatticeFrame%954184457.initialization preserve=yes
  : ModelElement(id),s_0(0),local_T(0),superFrame(0),itsGeometry(0)
  //## end LatticeFrame::LatticeFrame%954184457.initialization
{
  //## begin LatticeFrame::LatticeFrame%954184457.body preserve=yes
  //## end LatticeFrame::LatticeFrame%954184457.body
}

//## Operation: LatticeFrame%956820765
inline LatticeFrame::LatticeFrame (const LatticeFrame& rhs)
  //## begin LatticeFrame::LatticeFrame%956820765.initialization preserve=yes
  : ModelElement(rhs),s_0(0),local_T(0),superFrame(0),itsGeometry(0)
  //## end LatticeFrame::LatticeFrame%956820765.initialization
{
  //## begin LatticeFrame::LatticeFrame%956820765.body preserve=yes
  //## end LatticeFrame::LatticeFrame%956820765.body
}


//## Operation: ~LatticeFrame%984653918
inline LatticeFrame::~LatticeFrame ()
{
  //## begin LatticeFrame::~LatticeFrame%984653918.body preserve=yes
	if(local_T) delete local_T;
  //## end LatticeFrame::~LatticeFrame%984653918.body
}



//## Other Operations (inline)
//## Operation: GetLocalFrameTransform%951841364
inline Transform3D LatticeFrame::GetLocalFrameTransform () const
{
  //## begin LatticeFrame::GetLocalFrameTransform%951841364.body preserve=yes
	return local_T!=0 ? *local_T : Transform3D();
  //## end LatticeFrame::GetLocalFrameTransform%951841364.body
}

//## Operation: GetLocalPhysicalTransform%984653909
inline Transform3D LatticeFrame::GetLocalPhysicalTransform () const
{
  //## begin LatticeFrame::GetLocalPhysicalTransform%984653909.body preserve=yes
	return GetPhysicalTransform(superFrame);
  //## end LatticeFrame::GetLocalPhysicalTransform%984653909.body
}

//## Operation: GetGeometry%984653910
inline const AcceleratorGeometry& LatticeFrame::GetGeometry () const
{
  //## begin LatticeFrame::GetGeometry%984653910.body preserve=yes
	return *itsGeometry;
  //## end LatticeFrame::GetGeometry%984653910.body
}

//## Operation: GetLocalPosition%984653911
inline double LatticeFrame::GetLocalPosition () const
{
  //## begin LatticeFrame::GetLocalPosition%984653911.body preserve=yes
	return s_0;
  //## end LatticeFrame::GetLocalPosition%984653911.body
}

//## Operation: GetGeometryTransform%984653912
//## Exceptions: AcceleratorGeometry::BeyondExtent
inline Transform3D LatticeFrame::GetGeometryTransform (double s0, double s) const throw (AcceleratorGeometry::BeyondExtent)
{
  //## begin LatticeFrame::GetGeometryTransform%984653912.body preserve=yes
	return itsGeometry->GetGeometryTransform(s0,s);
  //## end LatticeFrame::GetGeometryTransform%984653912.body
}

//## Operation: GetGeometryTransform%985850581
//## Exceptions: AcceleratorGeometry::BeyondExtent
inline Transform3D LatticeFrame::GetGeometryTransform (double s) const throw (AcceleratorGeometry::BeyondExtent)
{
  //## begin LatticeFrame::GetGeometryTransform%985850581.body preserve=yes
	return itsGeometry->GetGeometryTransform(s);
  //## end LatticeFrame::GetGeometryTransform%985850581.body
}

//## Operation: GetGeometryTransform%984653913
inline Transform3D LatticeFrame::GetGeometryTransform (BoundaryPlane p) const
{
  //## begin LatticeFrame::GetGeometryTransform%984653913.body preserve=yes
	return itsGeometry->GetGeometryTransform(p);
  //## end LatticeFrame::GetGeometryTransform%984653913.body
}

//## Operation: GetTotalGeometryTransform%984653914
inline Transform3D LatticeFrame::GetTotalGeometryTransform () const
{
  //## begin LatticeFrame::GetTotalGeometryTransform%984653914.body preserve=yes
	return itsGeometry->GetTotalGeometryTransform();
  //## end LatticeFrame::GetTotalGeometryTransform%984653914.body
}

//## Operation: GetLocalGeometryExtent%984653915
inline AcceleratorGeometry::Extent LatticeFrame::GetLocalGeometryExtent () const
{
  //## begin LatticeFrame::GetLocalGeometryExtent%984653915.body preserve=yes
	return itsGeometry->GetGeometryExtent();
  //## end LatticeFrame::GetLocalGeometryExtent%984653915.body
}

//## Operation: GetGeometryLength%984653916
inline double LatticeFrame::GetGeometryLength () const
{
  //## begin LatticeFrame::GetGeometryLength%984653916.body preserve=yes
	return itsGeometry->GetGeometryLength();
  //## end LatticeFrame::GetGeometryLength%984653916.body
}

//## Operation: GetEntrancePlaneTransform%985283453
inline Transform3D LatticeFrame::GetEntrancePlaneTransform () const
{
  //## begin LatticeFrame::GetEntrancePlaneTransform%985283453.body preserve=yes
	return GetBoundaryPlaneTransform(AcceleratorGeometry::entrance);
  //## end LatticeFrame::GetEntrancePlaneTransform%985283453.body
}

//## Operation: GetExitPlaneTransform%985283454
inline Transform3D LatticeFrame::GetExitPlaneTransform () const
{
  //## begin LatticeFrame::GetExitPlaneTransform%985283454.body preserve=yes
	return GetBoundaryPlaneTransform(AcceleratorGeometry::exit).inv();
  //## end LatticeFrame::GetExitPlaneTransform%985283454.body
}

//## Operation: IsTransformed%984653920
inline bool LatticeFrame::IsTransformed () const
{
  //## begin LatticeFrame::IsTransformed%984653920.body preserve=yes
	return local_T!=0 && !local_T->isIdentity();
  //## end LatticeFrame::IsTransformed%984653920.body
}

//## Operation: Translate%985116518
inline void LatticeFrame::Translate (const Vector3D& X)
{
  //## begin LatticeFrame::Translate%985116518.body preserve=yes
	Translate(X.x,X.y,X.z);
  //## end LatticeFrame::Translate%985116518.body
}

//## Operation: TranslateX%986466241
inline void LatticeFrame::TranslateX (double dx)
{
  //## begin LatticeFrame::TranslateX%986466241.body preserve=yes
	Translate(dx,0,0);
  //## end LatticeFrame::TranslateX%986466241.body
}

//## Operation: TranslateY%986466242
inline void LatticeFrame::TranslateY (double dy)
{
  //## begin LatticeFrame::TranslateY%986466242.body preserve=yes
	Translate(0,dy,0);
  //## end LatticeFrame::TranslateY%986466242.body
}

//## Operation: TranslateZ%986466243
inline void LatticeFrame::TranslateZ (double dz)
{
  //## begin LatticeFrame::TranslateZ%986466243.body preserve=yes
	Translate(0,0,dz);
  //## end LatticeFrame::TranslateZ%986466243.body
}

//## Operation: Invalidate%951848913
inline void LatticeFrame::Invalidate () const
{
  //## begin LatticeFrame::Invalidate%951848913.body preserve=yes
  //## end LatticeFrame::Invalidate%951848913.body
}

//## Operation: ConsolidateConstruction%962031291
inline void LatticeFrame::ConsolidateConstruction ()
{
  //## begin LatticeFrame::ConsolidateConstruction%962031291.body preserve=yes
  //## end LatticeFrame::ConsolidateConstruction%962031291.body
}

//## Operation: SetLocalPosition%951848933
inline void LatticeFrame::SetLocalPosition (double s)
{
  //## begin LatticeFrame::SetLocalPosition%951848933.body preserve=yes
	s_0=s;
  //## end LatticeFrame::SetLocalPosition%951848933.body
}

//## Operation: SetSuperFrame%951841367
inline LatticeFrame* LatticeFrame::SetSuperFrame (LatticeFrame* aFrame)
{
  //## begin LatticeFrame::SetSuperFrame%951841367.body preserve=yes
	LatticeFrame* tmp=superFrame;
	superFrame = aFrame;
	return tmp;
  //## end LatticeFrame::SetSuperFrame%951841367.body
}

//## Operation: ReplaceSubFrame%985182997
inline bool LatticeFrame::ReplaceSubFrame (LatticeFrame* subFrame, LatticeFrame* newSubFrame)
{
  //## begin LatticeFrame::ReplaceSubFrame%985182997.body preserve=yes
	return false;
  //## end LatticeFrame::ReplaceSubFrame%985182997.body
}

//## Operation: IsGlobalFrame%985792510
inline bool LatticeFrame::IsGlobalFrame () const
{
  //## begin LatticeFrame::IsGlobalFrame%985792510.body preserve=yes
	return superFrame==0;
  //## end LatticeFrame::IsGlobalFrame%985792510.body
}

//## Operation: SetGeometry%984653917
inline void LatticeFrame::SetGeometry (const AcceleratorGeometry* geom)
{
  //## begin LatticeFrame::SetGeometry%984653917.body preserve=yes
	itsGeometry=geom;
  //## end LatticeFrame::SetGeometry%984653917.body
}

//## begin module%3AB0CE1D0104.epilog preserve=yes
//## end module%3AB0CE1D0104.epilog


#endif

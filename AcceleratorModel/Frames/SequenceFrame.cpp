//## begin module%3AB2348D0000.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Frames\SequenceFrame.cpp
 * last modified 20/04/01 17:24:22
 */
//## end module%3AB2348D0000.cm

//## begin module%3AB2348D0000.cp preserve=no
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
//## end module%3AB2348D0000.cp

//## Module: SequenceFrame%3AB2348D0000; Package body
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Source file: D:\dev\Merlin\AcceleratorModel\Frames\SequenceFrame.cpp

//## begin module%3AB2348D0000.includes preserve=yes
#include "NumericalUtils/utils.h"
//## end module%3AB2348D0000.includes

// AcceleratorGeometry
#include "AcceleratorModel/AcceleratorGeometry.h"
// SequenceFrame
#include "AcceleratorModel/Frames/SequenceFrame.h"
// deleters
#include "stdext/deleters.h"

class SequenceGeometry;

//## begin module%3AB2348D0000.declarations preserve=no
//## end module%3AB2348D0000.declarations

//## begin module%3AB2348D0000.additionalDeclarations preserve=yes
//## end module%3AB2348D0000.additionalDeclarations


//## Class: SequenceGeometry%3AB22C9F02D0; implementation
//	Implementation of an AcceleratorGeometry class used by
//	SequenceFrame to construct the required geometry object
//	to pass to its LatticeFrame base class during
//	construction (via LatticeFrame::SetGeometry).
//## Category: Merlin::AcceleratorModel::Frames%3AB0B5BC015E
//## Subsystem: Merlin::AcceleratorModel::Frames%3AB0B4F300A0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AB22E7102C6;SequenceFrame { -> F}
//## Uses: <unnamed>%3AC4D3D9021C;SequenceFrame::Origin { -> F}

class SequenceGeometry : public AcceleratorGeometry  //## Inherits: <unnamed>%3AB22D540366
{
  public:
    //## Class: TCache%3AB52A3402C6
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class TCache 
    {
      public:
        // Data Members for Class Attributes

          //## Attribute: t_in%3AB52A5100AA
          //## begin SequenceGeometry::TCache::t_in%3AB52A5100AA.attr preserve=no  public: Transform3D {UA} 
          Transform3D t_in;
          //## end SequenceGeometry::TCache::t_in%3AB52A5100AA.attr

          //## Attribute: t_out%3AB52A6501AE
          //## begin SequenceGeometry::TCache::t_out%3AB52A6501AE.attr preserve=no  public: Transform3D {UA} 
          Transform3D t_out;
          //## end SequenceGeometry::TCache::t_out%3AB52A6501AE.attr

      protected:
      private:
      private:  //## implementation
    };

  public:
    //## Constructors (specified)
      //## Operation: SequenceGeometry%984757497
      SequenceGeometry (SequenceFrame::FrameList* frames, SequenceFrame::Origin origin);

      //## Operation: SequenceGeometry%984757506
      //	Copy constructor.
      SequenceGeometry (const SequenceGeometry& rhs);

    //## Destructor (specified)
      //## Operation: ~SequenceGeometry%984757505
      ~SequenceGeometry ();


    //## Other Operations (specified)
      //## Operation: GetGeometryTransform%984757498
      //	Return the three-dimensional transformation between the
      //	frame at s0 and the frame at s. s and s0 are in the
      //	geometry's s-frame, and must be within the geometry
      //	extents.
      virtual Transform3D GetGeometryTransform (double s0, double s) const throw (BeyondExtent);

      //## Operation: GetGeometryTransform%984757499
      //	Returns the transformation from the geometry origin to
      //	the specified boundary plane.
      virtual Transform3D GetGeometryTransform (BoundaryPlane p) const;

      //## Operation: GetTotalGeometryTransform%984757500
      //	Returns the transformation from the entrance plane frame
      //	to the exit plane frame.
      virtual Transform3D GetTotalGeometryTransform () const;

      //## Operation: GetGeometryExtent%984757501
      //	Returns the local extent of this geometry.
      virtual AcceleratorGeometry::Extent GetGeometryExtent () const;

      //## Operation: GetGeometryLength%984757502
      //	Returns the total arc-length of the geometry.
      virtual double GetGeometryLength () const;

      //## Operation: CalculateCachedTransforms%984757503
      //	Calculates the cached transform state.
      void CalculateCachedTransforms ();

      //## Operation: CalculateCentreCT%987771847
      //	Calculates the cached transforms for centred origin.
      void CalculateCentreCT ();

    // Data Members for Class Attributes

      //## Attribute: len_t%38BC2BE300AA
      //## begin SequenceGeometry::len_t%38BC2BE300AA.attr preserve=no  public: double {UA} 
      double len_t;
      //## end SequenceGeometry::len_t%38BC2BE300AA.attr

      //## Attribute: omode%396C7F190199
      //## begin SequenceGeometry::omode%396C7F190199.attr preserve=no  public: SequenceFrame::Origin {UA} 
      SequenceFrame::Origin omode;
      //## end SequenceGeometry::omode%396C7F190199.attr

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: t_cache%3AB233E20082
      //## begin SequenceGeometry::t_cache%3AB233E20082.attr preserve=no  private: TCache* {UA} 
      TCache* t_cache;
      //## end SequenceGeometry::t_cache%3AB233E20082.attr

    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::Frames::<unnamed>%3AB230230122
      //## Role: SequenceGeometry::theFrameList%3AB2302400AA
      //## begin SequenceGeometry::theFrameList%3AB2302400AA.role preserve=no  private: SequenceFrame::FrameList { -> 1RHAN}
      SequenceFrame::FrameList* theFrameList;
      //## end SequenceGeometry::theFrameList%3AB2302400AA.role

  private:  //## implementation
};

// Class SequenceGeometry::TCache 

// Class SequenceGeometry 

//## Operation: SequenceGeometry%984757497
inline SequenceGeometry::SequenceGeometry (SequenceFrame::FrameList* frames, SequenceFrame::Origin origin)
  //## begin SequenceGeometry::SequenceGeometry%984757497.initialization preserve=yes
  : len_t(0),omode(origin),t_cache(0),theFrameList(frames)
  //## end SequenceGeometry::SequenceGeometry%984757497.initialization
{
  //## begin SequenceGeometry::SequenceGeometry%984757497.body preserve=yes
  //## end SequenceGeometry::SequenceGeometry%984757497.body
}


// Class SequenceFrame 




//## Operation: SequenceFrame%951848945
SequenceFrame::SequenceFrame (const string& id, Origin originLoc)
  //## begin SequenceFrame::SequenceFrame%951848945.initialization preserve=yes
  : LatticeFrame(id)
  //## end SequenceFrame::SequenceFrame%951848945.initialization
{
  //## begin SequenceFrame::SequenceFrame%951848945.body preserve=yes
	itsSeqGeom = new SequenceGeometry(&subFrames,originLoc);
	SetGeometry(itsSeqGeom);
  //## end SequenceFrame::SequenceFrame%951848945.body
}

//## Operation: SequenceFrame%956820766
SequenceFrame::SequenceFrame (const SequenceFrame& rhs)
  //## begin SequenceFrame::SequenceFrame%956820766.initialization preserve=yes
  : LatticeFrame(rhs)
  //## end SequenceFrame::SequenceFrame%956820766.initialization
{
  //## begin SequenceFrame::SequenceFrame%956820766.body preserve=yes
	itsSeqGeom = new SequenceGeometry(*(rhs.itsSeqGeom));
	SetGeometry(itsSeqGeom);
	CopySubFrames(rhs.subFrames);
  //## end SequenceFrame::SequenceFrame%956820766.body
}


//## Operation: ~SequenceFrame%951848934
SequenceFrame::~SequenceFrame ()
{
  //## begin SequenceFrame::~SequenceFrame%951848934.body preserve=yes
	if(itsSeqGeom)
		delete itsSeqGeom;
  //## end SequenceFrame::~SequenceFrame%951848934.body
}



//## Other Operations (implementation)
//## Operation: AppendFrame%951848935
void SequenceFrame::AppendFrame (LatticeFrame& aFrame)
{
  //## begin SequenceFrame::AppendFrame%951848935.body preserve=yes
	subFrames.push_back(&aFrame);
	aFrame.SetSuperFrame(this);

	// Update the geometry length
	itsSeqGeom->len_t += aFrame.GetGeometryLength();
  //## end SequenceFrame::AppendFrame%951848935.body
}

//## Operation: ConsolidateConstruction%962031290
void SequenceFrame::ConsolidateConstruction ()
{
  //## begin SequenceFrame::ConsolidateConstruction%962031290.body preserve=yes
	// First we need to set up the cached transform information
	// We assume that the origin of the sequence geometry is at 
	// the arc centre.

	double s;
	switch(itsSeqGeom->omode) {
	case originAtEntrance:
		s=0;
		break;
	case originAtCenter:
		s=-(itsSeqGeom->len_t)/2;
		break;
	case originAtExit:
		s=-(itsSeqGeom->len_t);
		break;
	}

	for(FrameList::iterator fi = subFrames.begin(); fi!=subFrames.end(); ++fi) {
		// First update the local position of each sub-frame
		// to reflect the centred origin
		AcceleratorGeometry::Extent ext = (*fi)->GetLocalGeometryExtent();
		s-=ext.first;
		(*fi)->SetLocalPosition(s);
		s+=ext.second;

		// now forward consolidation to the sub-frame
		(*fi)->ConsolidateConstruction();
	}

	itsSeqGeom->CalculateCachedTransforms();
  //## end SequenceFrame::ConsolidateConstruction%962031290.body
}

//## Operation: Invalidate%962313325
void SequenceFrame::Invalidate () const
{
  //## begin SequenceFrame::Invalidate%962313325.body preserve=yes
	if(!subFrames.empty()){
		(subFrames.front())->Invalidate();
		if(subFrames.size()>1)
			(subFrames.back())->Invalidate();
	}
  //## end SequenceFrame::Invalidate%962313325.body
}

//## Operation: Copy%956754080
ModelElement* SequenceFrame::Copy () const
{
  //## begin SequenceFrame::Copy%956754080.body preserve=yes
	return new SequenceFrame(*this);
  //## end SequenceFrame::Copy%956754080.body
}

//## Operation: ReplaceSubFrame%985182998
bool SequenceFrame::ReplaceSubFrame (LatticeFrame* subFrame, LatticeFrame* newSubFrame)
{
  //## begin SequenceFrame::ReplaceSubFrame%985182998.body preserve=yes
	FrameList::iterator fi = std::find(subFrames.begin(),subFrames.end(),subFrame);
	if(fi!=subFrames.end()) {
		*fi = newSubFrame;
		newSubFrame->SetSuperFrame(this);
		return true;
	}
	else
		return false;
  //## end SequenceFrame::ReplaceSubFrame%985182998.body
}

//## Operation: GetType%956754081
const string& SequenceFrame::GetType () const
{
  //## begin SequenceFrame::GetType%956754081.body preserve=yes
	_TYPESTR(SequenceFrame);
  //## end SequenceFrame::GetType%956754081.body
}

//## Operation: CopySubFrames%956820768
void SequenceFrame::CopySubFrames (const list<LatticeFrame*>& frames)
{
  //## begin SequenceFrame::CopySubFrames%956820768.body preserve=yes
	subFrames.clear();
	for(FrameList::const_iterator fi = frames.begin(); fi!=frames.end(); ++fi) {
		LatticeFrame* newCopy = static_cast<LatticeFrame*>((*fi)->Copy());
		subFrames.push_back(newCopy);
		newCopy->SetLocalPosition((*fi)->GetLocalPosition());
		newCopy->SetSuperFrame(this);
	}
  //## end SequenceFrame::CopySubFrames%956820768.body
}

//## Operation: IsBoundaryPlane%984757504
bool SequenceFrame::IsBoundaryPlane (BoundaryPlane p, const LatticeFrame* aSubFrame) const
{
  //## begin SequenceFrame::IsBoundaryPlane%984757504.body preserve=yes
	if(
		(p==AcceleratorGeometry::entrance && subFrames.front()==aSubFrame)||
		(p==AcceleratorGeometry::exit && subFrames.back()==aSubFrame))
		return true;
	else
		return false;
  //## end SequenceFrame::IsBoundaryPlane%984757504.body
}

// Class SequenceGeometry::TCache 



// Class SequenceGeometry 






//## Operation: SequenceGeometry%984757506
SequenceGeometry::SequenceGeometry (const SequenceGeometry& rhs)
  //## begin SequenceGeometry::SequenceGeometry%984757506.initialization preserve=yes
  //## end SequenceGeometry::SequenceGeometry%984757506.initialization
{
  //## begin SequenceGeometry::SequenceGeometry%984757506.body preserve=yes
  //## end SequenceGeometry::SequenceGeometry%984757506.body
}


//## Operation: ~SequenceGeometry%984757505
SequenceGeometry::~SequenceGeometry ()
{
  //## begin SequenceGeometry::~SequenceGeometry%984757505.body preserve=yes
	if(t_cache)
		delete t_cache;
  //## end SequenceGeometry::~SequenceGeometry%984757505.body
}



//## Other Operations (implementation)
//## Operation: GetGeometryTransform%984757498
//## Exceptions: BeyondExtent
Transform3D SequenceGeometry::GetGeometryTransform (double s0, double s) const throw (BeyondExtent)
{
  //## begin SequenceGeometry::GetGeometryTransform%984757498.body preserve=yes
	if(fequal(s,s0))
		return Transform3D();

	if(omode==SequenceFrame::originAtCenter) {
		s+=len_t/2;
		s0+=len_t/2;
	}
	else if(omode==SequenceFrame::originAtExit) {
		s+=len_t;
		s0+=len_t;
	}

	if(s<0||s>len_t||s0<0||s0>len_t)
		throw BeyondExtent();

	bool inv_t;
	if(inv_t=s0>s)
		std::swap(s,s0);

	SequenceFrame::FrameList::const_iterator fi = theFrameList->begin();
	double l;

	// First identify in which sub-frame s0 is
	for(;fi!=theFrameList->end();fi++) {
		l=(*fi)->GetGeometryLength();
		if(fequal(s0,l)||s0<l)
			break;
		s0-=l;
		s-=l;
	}

	assert(fi!=theFrameList->end());

	// s0 is now the distance from the entrance plane of *fi
	// to the requested starting point. 
	// Now check if s is also within this frame. If so,
	// return the local transform
	Extent ext = (*fi)->GetLocalGeometryExtent();
	if(fequal(s,l)||s<l)
		return (*fi)->GetGeometryTransform(ext.first+s0,ext.first+s);

	Transform3D t = (*fi)->GetGeometryTransform(ext.first+s0,ext.second);
	s-=l;
	fi++;

	for(;fi!=theFrameList->end();fi++) {
		l=(*fi)->GetGeometryLength();
		if(fequal(s,l)||s<l)
			break;
		t=((*fi)->GetTotalGeometryTransform())*t;
		s-=l;
	}
	if(fi==theFrameList->end())
		assert(fi!=theFrameList->end());

	// s is now the distance from the entrance plane of the *fi

	ext = (*fi)->GetLocalGeometryExtent();
	t = ((*fi)->GetGeometryTransform(ext.first,ext.first+s))*t;

	return inv_t ? t.inv() : t;
  //## end SequenceGeometry::GetGeometryTransform%984757498.body
}

//## Operation: GetGeometryTransform%984757499
Transform3D SequenceGeometry::GetGeometryTransform (BoundaryPlane p) const
{
  //## begin SequenceGeometry::GetGeometryTransform%984757499.body preserve=yes
	return p==entrance ? t_cache->t_in : t_cache->t_out;
  //## end SequenceGeometry::GetGeometryTransform%984757499.body
}

//## Operation: GetTotalGeometryTransform%984757500
Transform3D SequenceGeometry::GetTotalGeometryTransform () const
{
  //## begin SequenceGeometry::GetTotalGeometryTransform%984757500.body preserve=yes
	if(t_cache)
		return (t_cache->t_out)*((t_cache->t_in).inv());

	Transform3D t;
	for(SequenceFrame::FrameList::const_iterator fi = theFrameList->begin(); fi!=theFrameList->end(); fi++)
		t=((*fi)->GetTotalGeometryTransform())*t;

	return t;
  //## end SequenceGeometry::GetTotalGeometryTransform%984757500.body
}

//## Operation: GetGeometryExtent%984757501
AcceleratorGeometry::Extent SequenceGeometry::GetGeometryExtent () const
{
  //## begin SequenceGeometry::GetGeometryExtent%984757501.body preserve=yes
	Extent ext;
	switch(omode) {
	case SequenceFrame::originAtEntrance:
		ext.first=0;
		ext.second=len_t;
		break;
	case SequenceFrame::originAtCenter:
		ext.first=-len_t/2;
		ext.second=len_t/2;
		break;
	case SequenceFrame::originAtExit:
		ext.first=-len_t;
		ext.second=0;
		break;
	}

	return ext;
  //## end SequenceGeometry::GetGeometryExtent%984757501.body
}

//## Operation: GetGeometryLength%984757502
double SequenceGeometry::GetGeometryLength () const
{
  //## begin SequenceGeometry::GetGeometryLength%984757502.body preserve=yes
	return len_t;
  //## end SequenceGeometry::GetGeometryLength%984757502.body
}

//## Operation: CalculateCachedTransforms%984757503
void SequenceGeometry::CalculateCachedTransforms ()
{
  //## begin SequenceGeometry::CalculateCachedTransforms%984757503.body preserve=yes
	// Set up cached transformations for efficiency
	if(t_cache==0)
		t_cache = new TCache;

	switch(omode) {
	case SequenceFrame::originAtEntrance:
		t_cache->t_out = GetTotalGeometryTransform();
		break;
	case SequenceFrame::originAtCenter:
//		t_cache->t_in = GetGeometryTransform(0,-len_t/2);
//		t_cache->t_out = GetGeometryTransform(0,len_t/2);
		CalculateCentreCT();
		break;
	case SequenceFrame::originAtExit:
		t_cache->t_in = GetTotalGeometryTransform().inv();
		break;
	}

  //## end SequenceGeometry::CalculateCachedTransforms%984757503.body
}

//## Operation: CalculateCentreCT%987771847
void SequenceGeometry::CalculateCentreCT ()
{
  //## begin SequenceGeometry::CalculateCentreCT%987771847.body preserve=yes
	double s=0;
	double s0 = len_t/2;

	SequenceFrame::FrameList::const_iterator fi = theFrameList->begin();
	Transform3D t;

	for(;fi!=theFrameList->end();fi++) {
		s+=(*fi)->GetGeometryLength();
		if(fequal(s,s0)||s<s0)
			t=((*fi)->GetTotalGeometryTransform())*t;

		if(fequal(s,s0)) {
			t_cache->t_in = t.inv();
			t=Transform3D();
			break;
		}
		else if(s>s0) {
			Extent ext = (*fi)->GetLocalGeometryExtent();
			double s1 = ext.first+s-s0;
			t = (*fi)->GetGeometryTransform(ext.first,s1)*t;
			t_cache->t_in = t.inv();
			t = (*fi)->GetGeometryTransform(s1,ext.second);
			break;
		}
	}

	assert(fi!=theFrameList->end());
	fi++;

	for(;fi!=theFrameList->end();fi++)
		t=((*fi)->GetTotalGeometryTransform())*t;
		
	t_cache->t_out = t;
  //## end SequenceGeometry::CalculateCentreCT%987771847.body
}

//## begin module%3AB2348D0000.epilog preserve=yes
//## end module%3AB2348D0000.epilog

void SequenceFrame::Traverse(FrameTraverser &ft)
{
	// First act on this frame, and then
	// iterate the traverser over the sub-frames
	ft.ActOn(this);

	for(FrameList::iterator fi = subFrames.begin(); fi!=subFrames.end(); fi++)
		(*fi)->Traverse(ft);
}


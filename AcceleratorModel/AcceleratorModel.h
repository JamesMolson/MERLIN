//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%375C20240154.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file Merlin\AcceleratorModel\AcceleratorModel.h
 * last modified 03/06/02 12:34:26
 */
//## end module%375C20240154.cm

//## begin module%375C20240154.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 2001 by The Merlin Collaboration.
 * - ALL RIGHTS RESERVED - 
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
//## end module%375C20240154.cp

//## Module: AcceleratorModel%375C20240154; Package specification
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Source file: C:\C++\Merlin\AcceleratorModel\AcceleratorModel.h

#ifndef AcceleratorModel_h
#define AcceleratorModel_h 1

//## begin module%375C20240154.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%375C20240154.additionalIncludes

//## begin module%375C20240154.includes preserve=yes
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include "AcceleratorModel/Frames/ComponentFrame.h"
//## end module%375C20240154.includes

// AcceleratorComponent
#include "AcceleratorModel/AcceleratorComponent.h"
// ModelElement
#include "AcceleratorModel/ModelElement.h"
// ElementRepository
#include "AcceleratorModel/Implementation/ElementRepository.h"
// LatticeFrame
#include "AcceleratorModel/Frames/LatticeFrame.h"
// StringPattern
#include "utility/StringPattern.h"
// ring_iterator
#include "stdext/ring_iterator.h"

class ChannelServer;
class ComponentFrame;
template <class T> class TComponentFrame;
class RWChannel;
class ROChannel;

//## begin module%375C20240154.additionalDeclarations preserve=yes
using std::string;
using std::set;
using std::vector;
//## end module%375C20240154.additionalDeclarations


//## Class: AcceleratorModel%3906CBD901A5
//## Category: Merlin::AcceleratorModel%370B943B0384
//## Subsystem: Merlin::AcceleratorModel%371355260226
//## Persistence: Transient
//## Cardinality/Multiplicity: n



//## Uses: <unnamed>%39080ABE01A7;StringPattern { -> }
//## Uses: <unnamed>%39080B040111;AcceleratorModel::BadRange { -> F}
//## Uses: <unnamed>%3908143F02AA;TComponentFrame { -> F}
//## Uses: <unnamed>%39081644036B;deleter { -> }
//## Uses: sub-lattice%3908323E0201;AcceleratorModel::Beamline { -> F}
//## Uses: <unnamed>%3A9BCD210078;ROChannel { -> F}
//## Uses: <unnamed>%3A9BCD230398;RWChannel { -> F}
//## Uses: <unnamed>%3B65870100C0;ring_iterator { -> F}
//## Uses: <unnamed>%3B66961A0062;AcceleratorModel::RingIterator { -> F}

class AcceleratorModel 
{
  public:
    //## Class: FlatLattice%3908024F02C5
    //	A sequence of ComponentFrame objects representing the
    //	complete accelerator lattice.
    //## Category: Merlin::AcceleratorModel%370B943B0384
    //## Subsystem: Merlin::AcceleratorModel%371355260226
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    typedef std::vector<ComponentFrame*> FlatLattice;

    //## Class: BeamlineIterator%390802BF00BD
    //	Iterator definitions.
    //## Category: Merlin::AcceleratorModel%370B943B0384
    //## Subsystem: Merlin::AcceleratorModel%371355260226
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    //## Uses: <unnamed>%39081832038A;FlatLattice { -> }
    //## Uses: <unnamed>%3AC4903200A0;ComponentFrame { -> F}

    typedef FlatLattice::iterator BeamlineIterator;

    //## Class: ConstBeamlineIterator%390802C700F1
    //## Category: Merlin::AcceleratorModel%370B943B0384
    //## Subsystem: Merlin::AcceleratorModel%371355260226
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    //## Uses: <unnamed>%3908183501A3;FlatLattice { -> }

    typedef FlatLattice::const_iterator ConstBeamlineIterator;

    //## Class: Beamline%3907FD730276
    //	Represents the complete or  contiguous sub-section of
    //	the accelerator lattice.
    //## Category: Merlin::AcceleratorModel%370B943B0384
    //## Subsystem: Merlin::AcceleratorModel%371355260226
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    //## Uses: <unnamed>%3908041003A7;BeamlineIterator { -> }
    //## Uses: <unnamed>%390806A500D6;ConstBeamlineIterator { -> }
    //## Uses: <unnamed>%396B768401F4;Beamline::TRK { -> F}

    class Beamline 
    {
      protected:
        //## Class: TRK%396B74CB033E; protected; Parameterized Class
        //	Wrapper used by for template<T> void Track(T&) function.
        //## Category: Merlin::AcceleratorModel%370B943B0384
        //## Subsystem: Merlin::AcceleratorModel%371355260226
        //## Persistence: Transient
        //## Cardinality/Multiplicity: n



        template <class T>
        class TRK 
        {
          public:
            //## Constructors (specified)
              //## Operation: TRK%396B757D012C
              explicit TRK (T& aT)
                //## begin AcceleratorModel::Beamline::TRK::TRK%396B757D012C.initialization preserve=yes
                : _t(aT)
                //## end AcceleratorModel::Beamline::TRK::TRK%396B757D012C.initialization
              {
                //## begin AcceleratorModel::Beamline::TRK::TRK%396B757D012C.body preserve=yes
                //## end AcceleratorModel::Beamline::TRK::TRK%396B757D012C.body
              }


            //## Other Operations (specified)
              //## Operation: operator()%396B758B0352
              void operator () (ComponentFrame* frame)
              {
                //## begin AcceleratorModel::Beamline::TRK::operator()%396B758B0352.body preserve=yes
                _t(frame);
                //## end AcceleratorModel::Beamline::TRK::operator()%396B758B0352.body
              }

            // Data Members for Class Attributes

              //## Attribute: _t%396B753B01F4
              //## begin AcceleratorModel::Beamline::TRK::_t%396B753B01F4.attr preserve=no  public: T& {UA} 
              T& _t;
              //## end AcceleratorModel::Beamline::TRK::_t%396B753B01F4.attr

          protected:
          private:
          private: //## implementation
        };

      public:
        //## Constructors (specified)
          //## Operation: Beamline%3908042F03D3
          Beamline (BeamlineIterator fst, BeamlineIterator lst)
            //## begin AcceleratorModel::Beamline::Beamline%3908042F03D3.initialization preserve=yes
			: first(fst),last(lst)
            //## end AcceleratorModel::Beamline::Beamline%3908042F03D3.initialization
          {
            //## begin AcceleratorModel::Beamline::Beamline%3908042F03D3.body preserve=yes
            //## end AcceleratorModel::Beamline::Beamline%3908042F03D3.body
          }

          //## Operation: Beamline%3B669DD901E0
          Beamline ()
            //## begin AcceleratorModel::Beamline::Beamline%3B669DD901E0.initialization preserve=yes
            //## end AcceleratorModel::Beamline::Beamline%3B669DD901E0.initialization
          {
            //## begin AcceleratorModel::Beamline::Beamline%3B669DD901E0.body preserve=yes
            //## end AcceleratorModel::Beamline::Beamline%3B669DD901E0.body
          }


        //## Other Operations (specified)
          //## Operation: IsReversed%390804CE0057
          //	Returns true if the beamline is reversed.
          bool IsReversed ()
          {
            //## begin AcceleratorModel::Beamline::IsReversed%390804CE0057.body preserve=yes
			  return first>last;
            //## end AcceleratorModel::Beamline::IsReversed%390804CE0057.body
          }

          //## Operation: Track%3908052900A8
          //	Template function that iterates the functor object tobj
          //	over the Beamline. Returns a reference to tobj on exit.
          template<class T> T& Track (T& tobj)
          {
            //## begin AcceleratorModel::Beamline::Track%3908052900A8.body preserve=yes
			  // We make use of the TRK wrapper, to avoid the call to tobj's
			  // copy constructor
			  std::for_each(begin(),end(),TRK<T>(tobj));
			  return tobj;
			  // return std::for_each(begin(),end(),tobj);
            //## end AcceleratorModel::Beamline::Track%3908052900A8.body
          }

          //## Operation: begin%390804530122
          //	Standard library type iterator accessors.
          BeamlineIterator begin ()
          {
            //## begin AcceleratorModel::Beamline::begin%390804530122.body preserve=yes
			  return first;
            //## end AcceleratorModel::Beamline::begin%390804530122.body
          }

          //## Operation: begin%390804740224
          ConstBeamlineIterator begin () const
          {
            //## begin AcceleratorModel::Beamline::begin%390804740224.body preserve=yes
			  return first;
            //## end AcceleratorModel::Beamline::begin%390804740224.body
          }

          //## Operation: end%3908046C03B3
          BeamlineIterator end ()
          {
            //## begin AcceleratorModel::Beamline::end%3908046C03B3.body preserve=yes
			  return last+1;
            //## end AcceleratorModel::Beamline::end%3908046C03B3.body
          }

          //## Operation: end%390804840014
          ConstBeamlineIterator end () const
          {
            //## begin AcceleratorModel::Beamline::end%390804840014.body preserve=yes
			  return last+1;
            //## end AcceleratorModel::Beamline::end%390804840014.body
          }

          //## Operation: First%39080501017C
          //	Returns a reference to the first ComponentFrame.
          ComponentFrame& First ()
          {
            //## begin AcceleratorModel::Beamline::First%39080501017C.body preserve=yes
			  return **first;
            //## end AcceleratorModel::Beamline::First%39080501017C.body
          }

          //## Operation: First%3908051A0092
          const ComponentFrame& First () const
          {
            //## begin AcceleratorModel::Beamline::First%3908051A0092.body preserve=yes
			  return **first;
            //## end AcceleratorModel::Beamline::First%3908051A0092.body
          }

          //## Operation: Last%3908051302A5
          //	Returns a reference to the last ComponentFrame.
          ComponentFrame& Last ()
          {
            //## begin AcceleratorModel::Beamline::Last%3908051302A5.body preserve=yes
			  return **last;
            //## end AcceleratorModel::Beamline::Last%3908051302A5.body
          }

          //## Operation: Last%3908052101AB
          const ComponentFrame& Last () const
          {
            //## begin AcceleratorModel::Beamline::Last%3908052101AB.body preserve=yes
			  return **last;
            //## end AcceleratorModel::Beamline::Last%3908052101AB.body
          }
		

      protected:
      private:
        // Data Members for Class Attributes

          //## Attribute: first%39080413013E
          //## begin AcceleratorModel::Beamline::first%39080413013E.attr preserve=no  private: AcceleratorModel::BeamlineIterator {UA} 
          BeamlineIterator first;
          //## end AcceleratorModel::Beamline::first%39080413013E.attr

          //## Attribute: last%3908041A022F
          //## begin AcceleratorModel::Beamline::last%3908041A022F.attr preserve=no  private: AcceleratorModel::BeamlineIterator {UA} 
          BeamlineIterator last;
          //## end AcceleratorModel::Beamline::last%3908041A022F.attr

      private: //## implementation
    };

    //## Class: BadRange%39080AE1036A
    //## Category: Merlin::AcceleratorModel%370B943B0384
    //## Subsystem: Merlin::AcceleratorModel%371355260226
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    class BadRange 
    {
      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: Index%39080BCC0277
    //## Category: Merlin::AcceleratorModel%370B943B0384
    //## Subsystem: Merlin::AcceleratorModel%371355260226
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    typedef size_t Index;

    //## Class: RingIterator%3B6695C800F0
    //## Category: Merlin::AcceleratorModel%370B943B0384
    //## Subsystem: Merlin::AcceleratorModel%371355260226
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    //## Uses: <unnamed>%3B66962D022C;FlatLattice { -> }
    //## Uses: <unnamed>%3B6696420074;ring_iterator { -> }

    typedef ring_iterator<FlatLattice,FlatLattice::iterator> RingIterator;

    //## Constructors (specified)
      //## Operation: AcceleratorModel%39081B120388
      //	Constructor.
      AcceleratorModel ();

    //## Destructor (specified)
      //## Operation: ~AcceleratorModel%3908161802FA
      ~AcceleratorModel ();


    //## Other Operations (specified)
      //## Operation: GetBeamline%390807AE0222
      //	Returns the entire beamline of the model.
      Beamline GetBeamline ();

      //## Operation: GetBeamline%3908076E00CB
      //	Returns the beamline from elements n1 to n2.
      Beamline GetBeamline (Index n1, Index n2) throw (BadRange);

      //## Operation: GetBeamline%3908081B039B
      //	Returns a Beamline from the n1-th occurrence of the
      //	component whose qualified name  matches the pattern
      //	pat1, to the n2-th occurrence of the component matching
      //	patl2. Throws BadRange if no section is found.
      Beamline GetBeamline (const string& pat1, const string& pat2, int n1 = 1, int n2 = 1) throw (BadRange);

      //## Operation: GetRing%3B66952A00B7
      //	Assumes that the AcceleratorModel represents a ring
      //	accelerator, and returns a RingIterator which iterates
      //	continuously the ring. n represents the offset from the
      //	begining of the ring as defined in the AcceleratorModel.
      RingIterator GetRing (int n = 0);

      //## Operation: GetReversedBeamline%39080C26012C
      //	Returns the reversed complete beamline of the model.
      Beamline GetReversedBeamline ();

      //## Operation: ExtractComponents%39080C8A00CC
      //	Returns in results all ComponentFrame objects whose name
      //	matches the string pattern pat. Returns the length of
      //	results on exit. Note that the previous contents of
      //	results is overwritten. Components are returned in
      //	Beamline order.
      int ExtractComponents (const string& pat, vector<ComponentFrame*>& results);

      //## Operation: ExtractModelElements%39080D560274
      //	Returns in results all ModelElement objects whose name
      //	matches the string pattern pat. Returns the length of
      //	results on exit. Note that the previous contents of
      //	results is overwritten. The order results is undefined.
      int ExtractModelElements (const string& pat, vector<ModelElement*>& results);

      //## Operation: ExtractTypedComponents%39080DE40296
      //	template function returning TComponentFrame objects
      //	corresponding to AcceleratorComponents of type T.
      //	pattern is optional string pattern which can be used to
      //	match only those components with a specific
      //	(unqualified) name. Components are returned in Beamline
      //	order.
      template<class T> int ExtractTypedComponents (vector<TComponentFrame<T>*>& results, const string& pattern = "*")
      {
        //## begin AcceleratorModel::ExtractTypedComponents%39080DE40296.body preserve=yes
		  StringPattern p(pattern);
		  for(BeamlineIterator i = lattice.begin(); i!=lattice.end(); i++) {
			TComponentFrame<T>* cf = dynamic_cast<TComponentFrame<T>*>(*i);
			if(cf && p(cf->GetName()))
				results.push_back(cf);
		  }
		  return results.size();
        //## end AcceleratorModel::ExtractTypedComponents%39080DE40296.body
      }

      //## Operation: ExtractTypedElements%3908145E036D
      //	template function returning ModelElements of type T.
      //	pattern is optional string pattern which can be used to
      //	match only those components with a specific
      //	(unqualified) name. Order is undefined.
      template<class T> int ExtractTypedElements (T& results, const string& pattern = "*")
      {
        //## begin AcceleratorModel::ExtractTypedElements%3908145E036D.body preserve=yes
		  typedef typename T::value_type value_type;
		  StringPattern p(pattern);
		  for(ElementRepository::iterator i = theElements->begin(); i!=theElements->end(); i++) {
			  value_type mi = dynamic_cast<value_type>(*i);
			if(mi && p(mi->GetName()))
				results.push_back(mi);
		  }
		  return results.size();
        //## end AcceleratorModel::ExtractTypedElements%3908145E036D.body
      }
	  
	  // Returns the indecies of components matching par in iarray 
	  // for the entire beamline. iarray is overwritten by this function.
	  // Function returns length of iarray.
	  size_t GetIndecies(const std::string& pat, std::vector<Index>& iarray) const;

	  // Same as above, but limits search to the specified (sub-)beamline.
	  size_t GetIndecies(const Beamline&, const std::string& pat, std::vector<Index>& iarray) const;

      //## Operation: GetROChannels%3A9BCC60006E
      //	Returns in channels all ROChannels matching chID.
      //	Returns the number of channels found.
      size_t GetROChannels (const string& chID, std::vector<ROChannel*>& channels);

      //## Operation: GetRWChannels%3A9BCC6000DC
      //	Returns in channels all RWChannels matching chID.
      //	Returns the number of channels found.
      size_t GetRWChannels (const string& chID, std::vector<RWChannel*>& channels);

      //## Operation: GetROChannels%3CFB412C014E
      //	Returns read-only channels matching chid for all
      //	matching components in aBeamline. Note that only
      //	channels associated with AcceleratorComponents can be
      //	extracted using this method.
      size_t GetROChannels (Beamline& aBeamline, const std::string& chid, std::vector<ROChannel*>& channels);

      //## Operation: GetRWChannels%3CFB40D000C9
      //	Returns read-write channels matching chid for all
      //	matching components in aBeamline. Note that only
      //	channels associated with AcceleratorComponents can be
      //	extracted using this method.
      size_t GetRWChannels (Beamline& aBeamline, const std::string& chid, std::vector<RWChannel*>& channels);

      //## Operation: GetGlobalFrame%3AC2E29501B8
      //	Returns the top-level LatticeFrame (global frame) for
      //	the model. The global frame is the root object of the
      //	lattice frame hierachy.
      LatticeFrame& GetGlobalFrame ()
      {
        //## begin AcceleratorModel::GetGlobalFrame%3AC2E29501B8.body preserve=yes
		  return *globalFrame;
        //## end AcceleratorModel::GetGlobalFrame%3AC2E29501B8.body
      }

      //## Operation: GetGlobalFrame%3AC2E3A101D6
      const LatticeFrame& GetGlobalFrame () const
      {
        //## begin AcceleratorModel::GetGlobalFrame%3AC2E3A101D6.body preserve=yes
		  return *globalFrame;
        //## end AcceleratorModel::GetGlobalFrame%3AC2E3A101D6.body
      }

      //## Operation: AddModelElement%3AE843E400BE
      //	Allows clients to construct and add new ModelElement
      //	objects to the AcceleratorModel.
      void AddModelElement (ModelElement* element);

      //## Operation: ReportModelStatistics%3CAC27C9039A
      //	Prints to the specified stream statistics about the
      //	model.
      void ReportModelStatistics (std::ostream& os) const;

    // Data Members for Associations

  public:
  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::<unnamed>%3907FD7D03E3
      //## Role: AcceleratorModel::lattice%3907FD7E016E
      //## begin AcceleratorModel::lattice%3907FD7E016E.role preserve=no  private: AcceleratorModel::FlatLattice { -> 1VHgAN}
      FlatLattice lattice;
      //## end AcceleratorModel::lattice%3907FD7E016E.role

      //## Association: Merlin::AcceleratorModel::<unnamed>%3AC4C577029E
      //## Role: AcceleratorModel::globalFrame%3AC4C5780366
      //## begin AcceleratorModel::globalFrame%3AC4C5780366.role preserve=no  private: LatticeFrame { -> 0..1UHgAN}
      LatticeFrame* globalFrame;
      //## end AcceleratorModel::globalFrame%3AC4C5780366.role

      //## Association: Merlin::AcceleratorModel::<unnamed>%3AC4DDBA0028
      //## Role: AcceleratorModel::theElements%3AC4DDBA02BC
      //## begin AcceleratorModel::theElements%3AC4DDBA02BC.role preserve=no  private: ElementRepository { -> 0..1VHgAN}
      ElementRepository* theElements;
      //## end AcceleratorModel::theElements%3AC4DDBA02BC.role

      //## Association: Merlin::AcceleratorModel::Implementation::<unnamed>%3AC4DEC90028
      //## Role: AcceleratorModel::chServer%3AC4DEC903CA
      //## begin AcceleratorModel::chServer%3AC4DEC903CA.role preserve=no  private: ChannelServer { -> 0..1VFHgAN}
      ChannelServer* chServer;
      //## end AcceleratorModel::chServer%3AC4DEC903CA.role

  private: //## implementation
  //## begin AcceleratorModel%3906CBD901A5.friends preserve=no
    friend class AcceleratorModelConstructor;
  //## end AcceleratorModel%3906CBD901A5.friends
};

//## begin module%375C20240154.epilog preserve=yes
//## end module%375C20240154.epilog


#endif

//## begin module%371F12E80294.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdComponent\SectorBend.h
 * last modified 04/04/01 15:24:09
 */
//## end module%371F12E80294.cm

//## begin module%371F12E80294.cp preserve=no
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
//## end module%371F12E80294.cp

//## Module: SectorBend%371F12E80294; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Source file: D:\dev\Merlin\AcceleratorModel\StdComponent\SectorBend.h

#ifndef SectorBend_h
#define SectorBend_h 1

//## begin module%371F12E80294.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%371F12E80294.additionalIncludes

//## begin module%371F12E80294.includes preserve=yes
//## end module%371F12E80294.includes

// TemplateComponents
#include "AcceleratorModel/StdComponent/TemplateComponents.h"
// MultipoleField
#include "AcceleratorModel/StdField/MultipoleField.h"
// ArcGeometry
#include "AcceleratorModel/StdGeometry/ArcGeometry.h"
// ArcMultipoleField
#include "AcceleratorModel/StdComponent/ArcMultipoleField.h"

class ComponentTracker;

//## begin module%371F12E80294.declarations preserve=no
//## end module%371F12E80294.declarations

//## begin module%371F12E80294.additionalDeclarations preserve=yes
//## end module%371F12E80294.additionalDeclarations


//## Class: SectorBend%331EC8B9014D
//	Representation of a SectorBend magnet. By default, the
//	magnet is hard edged, with the pole-faces perpendicular
//	to the geometry. Pole faces can be rotated about the
//	local y-axis, and can also have a constant radius
//	curvature whioch gives rise to a sextupole component
//	(see TRANSPORT or MAD for details). As well as a
//	vertical B field, sector bends can have an additional
//	quadrupole and sextupole field component specified.
//## Category: Merlin::AcceleratorModel::StdComponent%331EC8B201EE
//## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%37032EAF01E0;ArcGeometry { -> }
//## Uses: <unnamed>%371F0CF90136;MultipoleField { -> }
//## Uses: <unnamed>%371F0D3D0352;TAccCompGF { -> }
//## Uses: <unnamed>%371F1D42028A;ComponentTracker { -> F}

class SectorBend : public ArcMultipoleField  //## Inherits: <unnamed>%371F0CC5015E
{
  public:
    //## Class: PoleFace%371F0B19005A
    //	POD containing information for the pole face of a sector
    //	bend.
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class PoleFace 
    {
      public:
        //## Constructors (specified)
          //## Operation: PoleFace%924771638
          PoleFace (double angle = 0, double f_int = 0, double hg = 0);

        // Data Members for Class Attributes

          //## Attribute: rot%371F0B5903C0
          //	Pole face rotation.
          //## begin SectorBend::PoleFace::rot%371F0B5903C0.attr preserve=no  public: double {UA} 
          double rot;
          //## end SectorBend::PoleFace::rot%371F0B5903C0.attr

          //## Attribute: fint%371F0B6C00FA
          //	fringe field integral.
          //## begin SectorBend::PoleFace::fint%371F0B6C00FA.attr preserve=no  public: double {UA} 
          double fint;
          //## end SectorBend::PoleFace::fint%371F0B6C00FA.attr

          //## Attribute: hgap%371F0B7200B4
          //	half gap magnet.
          //## begin SectorBend::PoleFace::hgap%371F0B7200B4.attr preserve=no  public: double {UA} 
          double hgap;
          //## end SectorBend::PoleFace::hgap%371F0B7200B4.attr

      protected:
      private:
      private:  //## implementation
    };

    //## Class: PoleFaceInfo%371F109602B2
    //	Pair struct for containing pointers to the entrance and
    //	exit pole face attributes.
    //## Category: <Top Level>
    //## Subsystem: Merlin::AcceleratorModel::StdComponent%3714A06602A8
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    //## Uses: <unnamed>%371F11760082;PoleFace { -> }

    class PoleFaceInfo 
    {
      public:
        //## Constructors (specified)
          //## Operation: PoleFaceInfo%924771651
          PoleFaceInfo ()
            //## begin SectorBend::PoleFaceInfo::PoleFaceInfo%924771651.initialization preserve=yes
			: entrance(0),exit(0)
            //## end SectorBend::PoleFaceInfo::PoleFaceInfo%924771651.initialization
          {
            //## begin SectorBend::PoleFaceInfo::PoleFaceInfo%924771651.body preserve=yes
            //## end SectorBend::PoleFaceInfo::PoleFaceInfo%924771651.body
          }

          //## Operation: PoleFaceInfo%924771648
          PoleFaceInfo (const PoleFaceInfo& rhs)
            //## begin SectorBend::PoleFaceInfo::PoleFaceInfo%924771648.initialization preserve=yes
            //## end SectorBend::PoleFaceInfo::PoleFaceInfo%924771648.initialization
          {
            //## begin SectorBend::PoleFaceInfo::PoleFaceInfo%924771648.body preserve=yes
			  Copy(rhs);
            //## end SectorBend::PoleFaceInfo::PoleFaceInfo%924771648.body
          }

        //## Destructor (specified)
          //## Operation: ~PoleFaceInfo%924771652
          ~PoleFaceInfo ()
          {
            //## begin SectorBend::PoleFaceInfo::~PoleFaceInfo%924771652.body preserve=yes
			  Clear();
            //## end SectorBend::PoleFaceInfo::~PoleFaceInfo%924771652.body
          }


        //## Other Operations (specified)
          //## Operation: operator=%924771649
          PoleFaceInfo& operator = (const PoleFaceInfo& rhs)
          {
            //## begin SectorBend::PoleFaceInfo::operator=%924771649.body preserve=yes
			  Clear();
			  Copy(rhs);
			  return *this;
            //## end SectorBend::PoleFaceInfo::operator=%924771649.body
          }

          //## Operation: SetInfo%924771655
          void SetInfo (PoleFace* e1, PoleFace* e2)
          {
            //## begin SectorBend::PoleFaceInfo::SetInfo%924771655.body preserve=yes
			  Clear();
			  entrance=e1;
			  exit=e2;
            //## end SectorBend::PoleFaceInfo::SetInfo%924771655.body
          }

          //## Operation: SetInfo%924771656
          void SetInfo (PoleFace* e1)
          {
            //## begin SectorBend::PoleFaceInfo::SetInfo%924771656.body preserve=yes
			  Clear();
			  entrance=exit=e1;
            //## end SectorBend::PoleFaceInfo::SetInfo%924771656.body
          }

        // Data Members for Class Attributes

          //## Attribute: entrance%371F10D102A8
          //## begin SectorBend::PoleFaceInfo::entrance%371F10D102A8.attr preserve=no  public: PoleFace* {UA} 
          PoleFace* entrance;
          //## end SectorBend::PoleFaceInfo::entrance%371F10D102A8.attr

          //## Attribute: exit%371F10E2028A
          //## begin SectorBend::PoleFaceInfo::exit%371F10E2028A.attr preserve=no  public: PoleFace* {UA} 
          PoleFace* exit;
          //## end SectorBend::PoleFaceInfo::exit%371F10E2028A.attr

      protected:
      private:
      private:  //## implementation

        //## Other Operations (specified)
          //## Operation: Clear%924771657
          void Clear ()
          {
            //## begin SectorBend::PoleFaceInfo::Clear%924771657.body preserve=yes
			  if(entrance) delete entrance;
			  if(exit && exit!=entrance) delete exit;
            //## end SectorBend::PoleFaceInfo::Clear%924771657.body
          }

          //## Operation: Copy%924771653
          void Copy (const PoleFaceInfo& rhs);

    };

  public:
    //## Constructors (specified)
      //## Operation: SectorBend%868873063
      //	Constructor taking the id of the dipole, the length
      //	(meter) and curvature (1/meter) of the dipole geometry,
      //	and the vertical magnetic field in Tesla.
      SectorBend (const string& id, double len, double h, double b0);


    //## Other Operations (specified)
      //## Operation: GetIndex%924771650
      //	Returns the unique index for this class of accelerator
      //	components.
      virtual int GetIndex () const;

      //## Operation: GetType%924771643
      virtual const string& GetType () const;

      //## Operation: RotateY180%884089487; C++
      //	Rotate the bend by 180 degrees about the vertical
      //	access. Causes the sign of the curvature to change, as
      //	well as the field to be rotated (via a call to Multipole
      //	Magnet::rotate()).
      virtual void RotateY180 ();

      //## Operation: PrepareTracker%924771642
      //	Primary tracking interface. Prepares the specified
      //	Tracker object for tracking this component.
      virtual void PrepareTracker (ComponentTracker& aTracker);

      //## Operation: Copy%924771644
      virtual ModelElement* Copy () const;

      //## Operation: GetPoleFaceInfo%924771645
      const PoleFaceInfo& GetPoleFaceInfo () const
      {
        //## begin SectorBend::GetPoleFaceInfo%924771645.body preserve=yes
		  return pfInfo;
        //## end SectorBend::GetPoleFaceInfo%924771645.body
      }

      //## Operation: SetPoleFaceInfo%924771646
      void SetPoleFaceInfo (PoleFace* entr, PoleFace* exit);

      //## Operation: SetPoleFaceInfo%924771658
      void SetPoleFaceInfo (PoleFace* pf);

      //## Operation: GetMatchedMomentum%924771659
      //	Returns the matched momentum  for the current field and
      //	geometry for a particle of charge q/e. Note that the
      //	returned momentum can be negative.
      double GetMatchedMomentum (double q) const;

      //## Operation: GetB0%924771660
      //	Returns the main dipole field in Tesla.
      double GetB0 () const
      {
        //## begin SectorBend::GetB0%924771660.body preserve=yes
		  return GetField().GetFieldScale();
        //## end SectorBend::GetB0%924771660.body
      }

      //## Operation: GetB1%951652580
      //	Returns the quadrupole field component  in Tesla/meter.
      double GetB1 () const;

      //## Operation: SetB0%924771661
      //	Sets the main dipole field (in Tesla).
      void SetB0 (double By)
      {
        //## begin SectorBend::SetB0%924771661.body preserve=yes
		  GetField().SetFieldScale(By);
        //## end SectorBend::SetB0%924771661.body
      }

      //## Operation: SetB1%951652579
      //	Sets the quadrupole field component for the dipole
      //	(mixed function magnet). B1 is defined as the quadrupole
      //	gradient in Tesla/meter.
      void SetB1 (double b1);

    // Data Members for Class Attributes

      //## Attribute: ID%371F13FC01B8
      //	Unique index for an Accelerator component.
      //## begin SectorBend::ID%371F13FC01B8.attr preserve=no  public: static const int {UA} UniqueIndex()
      static const int ID;
      //## end SectorBend::ID%371F13FC01B8.attr

  protected:
  private:
    // Data Members for Associations

      //## Association: Merlin::AcceleratorModel::StdComponent::class details::<unnamed>%371F0C42015E
      //## Role: SectorBend::pfInfo%371F0C430119
      //## begin SectorBend::pfInfo%371F0C430119.role preserve=no  private: SectorBend::PoleFaceInfo { -> 1VHAN}
      PoleFaceInfo pfInfo;
      //## end SectorBend::pfInfo%371F0C430119.role

  private:  //## implementation
};

//## begin module%371F12E80294.epilog preserve=yes
//## end module%371F12E80294.epilog


#endif

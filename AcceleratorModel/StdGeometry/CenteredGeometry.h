//## begin module%3AB0A74C02E4.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\StdGeometry\CenteredGeometry.h
 * last modified 03/04/01 13:43:32
 */
//## end module%3AB0A74C02E4.cm

//## begin module%3AB0A74C02E4.cp preserve=no
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
//## end module%3AB0A74C02E4.cp

//## Module: CenteredGeometry%3AB0A74C02E4; Package specification
//## Subsystem: Merlin::AcceleratorModel::StdGeometry%3AB0A71501AE
//## Source file: D:\dev\Merlin\AcceleratorModel\StdGeometry\CenteredGeometry.h

#ifndef CenteredGeometry_h
#define CenteredGeometry_h 1

//## begin module%3AB0A74C02E4.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AB0A74C02E4.additionalIncludes

//## begin module%3AB0A74C02E4.includes preserve=yes
//## end module%3AB0A74C02E4.includes

// AcceleratorGeometry
#include "AcceleratorModel/AcceleratorGeometry.h"
//## begin module%3AB0A74C02E4.declarations preserve=no
//## end module%3AB0A74C02E4.declarations

//## begin module%3AB0A74C02E4.additionalDeclarations preserve=yes
//## end module%3AB0A74C02E4.additionalDeclarations


//## Class: CenteredGeometry%371DD4EB02EE; Abstract
//	Base class for accelerator geometry types whose origin
//	is at the center of the their arc length. Hence their
//	extent extends from -length/2 to +length/2.
//## Category: Merlin::AcceleratorModel::StdGeometry%337727B1003C
//## Subsystem: Merlin::AcceleratorModel::StdGeometry%3AB0A71501AE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CenteredGeometry : public AcceleratorGeometry  //## Inherits: <unnamed>%371DD505037A
{
  public:
    //## Constructors (specified)
      //## Operation: CenteredGeometry%924687019
      //	Constructor taking the arc length of the geometry.
      explicit CenteredGeometry (double l);


    //## Other Operations (specified)
      //## Operation: GetGeometryLength%929041265
      //	Returns the total arc-length of the geometry.
      virtual double GetGeometryLength () const;

      //## Operation: GetGeometryExtent%924687020
      //	Returns the local extent of this geometry.
      virtual AcceleratorGeometry::Extent GetGeometryExtent () const;

  protected:

    //## Other Operations (specified)
      //## Operation: CheckBounds%924687021
      //	Used to check if (s1s2) is within the geometry bounds.
      void CheckBounds (double s1, double s2) const throw (BeyondExtent);

      //## Operation: CheckBounds%925300235
      //	Used to check if s1 is within the geometry bounds.
      void CheckBounds (double s) const throw (BeyondExtent);

    // Data Members for Class Attributes

      //## Attribute: len%3760121C0294
      //## begin CenteredGeometry::len%3760121C0294.attr preserve=no  protected: double {UA} 
      double len;
      //## end CenteredGeometry::len%3760121C0294.attr

  private:
  private:  //## implementation
};

// Class CenteredGeometry 

//## Operation: CenteredGeometry%924687019
inline CenteredGeometry::CenteredGeometry (double l)
  //## begin CenteredGeometry::CenteredGeometry%924687019.initialization preserve=yes
  : AcceleratorGeometry(),len(l)
  //## end CenteredGeometry::CenteredGeometry%924687019.initialization
{
  //## begin CenteredGeometry::CenteredGeometry%924687019.body preserve=yes
  //## end CenteredGeometry::CenteredGeometry%924687019.body
}



//## Other Operations (inline)
//## Operation: GetGeometryLength%929041265
inline double CenteredGeometry::GetGeometryLength () const
{
  //## begin CenteredGeometry::GetGeometryLength%929041265.body preserve=yes
	return len;
  //## end CenteredGeometry::GetGeometryLength%929041265.body
}

//## Operation: GetGeometryExtent%924687020
inline AcceleratorGeometry::Extent CenteredGeometry::GetGeometryExtent () const
{
  //## begin CenteredGeometry::GetGeometryExtent%924687020.body preserve=yes
	double s=len/2;
	return Extent(-s,s);
  //## end CenteredGeometry::GetGeometryExtent%924687020.body
}

//## Operation: CheckBounds%924687021
//## Exceptions: BeyondExtent
inline void CenteredGeometry::CheckBounds (double s1, double s2) const throw (BeyondExtent)
{
  //## begin CenteredGeometry::CheckBounds%924687021.body preserve=yes
	double hl=len/2;
	if(fabs(s1)>hl || fabs(s2)>hl)
		throw BeyondExtent();
  //## end CenteredGeometry::CheckBounds%924687021.body
}

//## Operation: CheckBounds%925300235
//## Exceptions: BeyondExtent
inline void CenteredGeometry::CheckBounds (double s) const throw (BeyondExtent)
{
  //## begin CenteredGeometry::CheckBounds%925300235.body preserve=yes
	if(fabs(s)>len/2)
		throw BeyondExtent();
  //## end CenteredGeometry::CheckBounds%925300235.body
}

// Class CenteredGeometry 


//## begin module%3AB0A74C02E4.epilog preserve=yes
//## end module%3AB0A74C02E4.epilog


#endif

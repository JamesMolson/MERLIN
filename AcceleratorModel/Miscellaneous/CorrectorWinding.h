//## begin module%3AE83CAD032A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Miscellaneous\CorrectorWinding.h
 * last modified 26/04/01 17:45:43
 */
//## end module%3AE83CAD032A.cm

//## begin module%3AE83CAD032A.cp preserve=no
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
//## end module%3AE83CAD032A.cp

//## Module: CorrectorWinding%3AE83CAD032A; Pseudo Package specification
//## Subsystem: Merlin::AcceleratorModel::Miscellaneous%3AE83E3F02F8
//## Source file: D:\dev\Merlin\AcceleratorModel\Miscellaneous\CorrectorWinding.h

#ifndef CorrectorWinding_h
#define CorrectorWinding_h 1

//## begin module%3AE83CAD032A.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%3AE83CAD032A.additionalIncludes

//## begin module%3AE83CAD032A.includes preserve=yes
//## end module%3AE83CAD032A.includes

// RectMultipole
#include "AcceleratorModel/StdComponent/RectMultipole.h"
// ModelElement
#include "AcceleratorModel/ModelElement.h"
//## begin module%3AE83CAD032A.additionalDeclarations preserve=yes
//## end module%3AE83CAD032A.additionalDeclarations


//## Class: CorrectorWinding%3AE83CAD032A
//	Represents a dipole corrector winding that can be added
//	to any RectMultipole component. The Bx and By field
//	values are in integrated strengths (Tesla.meter).
//## Category: Merlin::AcceleratorModel::Miscellaneous%3AE83E3F02F8
//## Subsystem: Merlin::AcceleratorModel::Miscellaneous%3AE83E3F02F8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CorrectorWinding : public ModelElement  //## Inherits: <unnamed>%3AE83CC1001E
{
  public:
    //## Constructors (specified)
      //## Operation: CorrectorWinding%988274723
      CorrectorWinding (RectMultipole& aMagnet);


    //## Other Operations (specified)
      //## Operation: SetBx%988274724
      void SetBx (double value);

      //## Operation: SetBy%988274725
      void SetBy (double value);

      //## Operation: GetBx%988274726
      double GetBx () const;

      //## Operation: GetBy%988274727
      double GetBy () const;

      //## Operation: GetName%988274728
      //	Return the name of the element.
      virtual const string& GetName () const;

      //## Operation: GetType%988274729
      //	Return the type string for the element.
      virtual const string& GetType () const;

      //## Operation: Copy%988274730
      //	Virtual constructor.
      virtual ModelElement* Copy () const;

  protected:
  private:
    // Data Members for Associations

      //## Association: <unnamed>%3AE83CD9024E
      //## Role: CorrectorWinding::magnet%3AE83CDA02A9
      //## begin CorrectorWinding::magnet%3AE83CDA02A9.role preserve=no  private: RectMultipole { -> 1RHAN}
      RectMultipole* magnet;
      //## end CorrectorWinding::magnet%3AE83CDA02A9.role

  private:  //## implementation
};

// Class CorrectorWinding 


//## Other Operations (inline)
//## Operation: GetName%988274728
inline const string& CorrectorWinding::GetName () const
{
  //## begin CorrectorWinding::GetName%988274728.body preserve=yes
	return magnet->GetName();
  //## end CorrectorWinding::GetName%988274728.body
}

//## begin module%3AE83CAD032A.epilog preserve=yes
//## end module%3AE83CAD032A.epilog


#endif

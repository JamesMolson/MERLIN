//## begin module%3AE83CAD032A.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\AcceleratorModel\Miscellaneous\CorrectorWinding.cpp
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

//## Module: CorrectorWinding%3AE83CAD032A; Pseudo Package body
//## Subsystem: Merlin::AcceleratorModel::Miscellaneous%3AE83E3F02F8
//## Source file: D:\dev\Merlin\AcceleratorModel\Miscellaneous\CorrectorWinding.cpp

//## begin module%3AE83CAD032A.includes preserve=yes
//## end module%3AE83CAD032A.includes

// CorrectorWinding
#include "AcceleratorModel/Miscellaneous/CorrectorWinding.h"
//## begin module%3AE83CAD032A.additionalDeclarations preserve=yes
//## end module%3AE83CAD032A.additionalDeclarations


// Class CorrectorWinding 


//## Operation: CorrectorWinding%988274723
CorrectorWinding::CorrectorWinding (RectMultipole& aMagnet)
  //## begin CorrectorWinding::CorrectorWinding%988274723.initialization preserve=yes
  : ModelElement(aMagnet.GetName()),magnet(&aMagnet)
  //## end CorrectorWinding::CorrectorWinding%988274723.initialization
{
  //## begin CorrectorWinding::CorrectorWinding%988274723.body preserve=yes
  //## end CorrectorWinding::CorrectorWinding%988274723.body
}



//## Other Operations (implementation)
//## Operation: SetBx%988274724
void CorrectorWinding::SetBx (double value)
{
  //## begin CorrectorWinding::SetBx%988274724.body preserve=yes
	if((*magnet).GetField().GetFieldScale()==0)
		return;

	double l=magnet->GetLength();
	(*magnet).GetField().SetComponent(0,0,value/l);
  //## end CorrectorWinding::SetBx%988274724.body
}

//## Operation: SetBy%988274725
void CorrectorWinding::SetBy (double value)
{
  //## begin CorrectorWinding::SetBy%988274725.body preserve=yes
	if((*magnet).GetField().GetFieldScale()==0)
		return;

	double l=magnet->GetLength();
	(*magnet).GetField().SetComponent(0,value/l,0);
  //## end CorrectorWinding::SetBy%988274725.body
}

//## Operation: GetBx%988274726
double CorrectorWinding::GetBx () const
{
  //## begin CorrectorWinding::GetBx%988274726.body preserve=yes
	return (*magnet).GetField().GetComponent(0).imag()*magnet->GetLength();
  //## end CorrectorWinding::GetBx%988274726.body
}

//## Operation: GetBy%988274727
double CorrectorWinding::GetBy () const
{
  //## begin CorrectorWinding::GetBy%988274727.body preserve=yes
	return (*magnet).GetField().GetComponent(0).real()*magnet->GetLength();
  //## end CorrectorWinding::GetBy%988274727.body
}

//## Operation: GetType%988274729
const string& CorrectorWinding::GetType () const
{
  //## begin CorrectorWinding::GetType%988274729.body preserve=yes
	_TYPESTR(CorrectorWinding)
  //## end CorrectorWinding::GetType%988274729.body
}

//## Operation: Copy%988274730
ModelElement* CorrectorWinding::Copy () const
{
  //## begin CorrectorWinding::Copy%988274730.body preserve=yes
	return new CorrectorWinding(*this);
  //## end CorrectorWinding::Copy%988274730.body
}

//## begin module%3AE83CAD032A.epilog preserve=yes
//## end module%3AE83CAD032A.epilog

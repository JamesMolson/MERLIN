//## begin module%36BDEBCD038E.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (1999)
 * 
 * file BasicTransport\TransportMatrix.h
 * last modified 02/25/00  03:10:44
 */
//## end module%36BDEBCD038E.cm

//## begin module%36BDEBCD038E.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 * Copyright (c) 1999 by N.J.Walker.  ALL RIGHTS RESERVED. 
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
//## end module%36BDEBCD038E.cp

//## Module: TransportMatrix%36BDEBCD038E; Package specification
//## Subsystem: BasicTransport%36BDEB0A021C
//## Source file: C:\C++\Merlin\BasicTransport\TransportMatrix.h

#ifndef TransportMatrix_h
#define TransportMatrix_h 1

//## begin module%36BDEBCD038E.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%36BDEBCD038E.additionalIncludes

//## begin module%36BDEBCD038E.includes preserve=yes
//## end module%36BDEBCD038E.includes

// LinearAlgebra
#include "TLAS/LinearAlgebra.h"
//## begin module%36BDEBCD038E.declarations preserve=no
//## end module%36BDEBCD038E.declarations

//## begin module%36BDEBCD038E.additionalDeclarations preserve=yes
//## end module%36BDEBCD038E.additionalDeclarations


//## Class: TransportMatrix%34955F88018D; Class Utility
//	Utility routines for constructing transport matrices (R
//	matrix).
//## Category: BasicTransport%34797A9700F7; Global
//## Subsystem: BasicTransport%36BDEB0A021C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%35DBF037033E;RealMatrix { -> }
//## Uses: <unnamed>%35DBF039003E;RealVector { -> }

class TransportMatrix 
{
  public:

    //## Other Operations (specified)
      //## Operation: Drift%882199461
      static RealMatrix Drift (double length, RealMatrix& R);

      //## Operation: SectorBend%882199462
      static RealMatrix& SectorBend (double length, double h, double Kx, RealMatrix& R);

      //## Operation: SectorBendT%951487844
      static RealMatrix& SectorBendT (double length, double h, double Kx, RealMatrix& T);

      //## Operation: Quadrupole%882199463
      static RealMatrix& Quadrupole (double length, double Kx, RealMatrix& R);

      //## Operation: QuadrupoleR%908350738
      //	Returns in R the 4x4 matrix representing the linear
      //	quadrupole map.
      static RealMatrix& QuadrupoleR (double length, double Kx, RealMatrix& R);

      //## Operation: QuadrupoleT%908350739
      //	Returns in T the 4x4 matrix representing the
      //	second-order quadrupole map.
      static RealMatrix& QuadrupoleT (double length, double Kx, RealMatrix& T);

      //## Operation: Srot%882199464
      static RealMatrix& Srot (double phi, RealMatrix& R);

      //## Operation: Srot%884688471
      static RealMatrix& Srot (double cosphi, double sinphi, RealMatrix& R);

      //## Operation: SrotR4%908464076
      static RealMatrix& SrotR4 (double cosphi, double sinphi, RealMatrix& R);

      //## Operation: SrotR4%908464077
      static RealMatrix& SrotR4 (double phi, RealMatrix& R);

      //## Operation: PoleFaceRot%882199465
      static RealMatrix& PoleFaceRot (double h, double theta, double fint, double hgap, RealMatrix& R);

      //## Operation: Solenoid%882199466
      //	Returns a linear matrix for a solenoid having a
      //	longitudinal field strength K0 (1/meter). A solenoid can
      //	also have an optional quadrupole component K1
      //	(1/meter^2). If either entrFringe or exitFringe are
      //	true, then the map contains the effects of the entrance
      //	or exit fringe fields respectively.
      static RealMatrix& Solenoid (double length, double K0, double K1, bool entrFringe, bool exitFringe, RealMatrix& R);

      //## Operation: TWRFCavity%882199467
      //	Travelling wave RF cavity (SLAC-91 rev. 2, page 90. )
      static RealMatrix& TWRFCavity (double length, double g, double f, double phi, double E0, RealMatrix& R);

      //## Operation: SWRFCavity%903606812
      //	Standing wave RF cavity
      static RealMatrix& SWRFCavity (int ncells, double g, double f, double phi, double E0, RealMatrix& R);

      //## Operation: Arb3DXForm%903606813
      //	Returns a linear map and a six-vector (dX) which
      //	approximates an arbitrary 3-D euclidean transformation.
      //	Note the map is in general not symplectic: in the case
      //	of large x- or y-axis rotations, errors may occur.
      static RealMatrix& Arb3DXForm (const RealMatrix& R3d, const RealVector& X, RealMatrix& R, RealVector& dX);

  protected:
  private:
  private:  //## implementation
};

// Class Utility TransportMatrix 


//## Other Operations (inline)
//## Operation: Quadrupole%882199463
inline RealMatrix& TransportMatrix::Quadrupole (double length, double Kx, RealMatrix& R)
{
  //## begin TransportMatrix::Quadrupole%882199463.body preserve=yes
	return SectorBend(length,0.0,Kx,R);
  //## end TransportMatrix::Quadrupole%882199463.body
}

//## Operation: Srot%882199464
inline RealMatrix& TransportMatrix::Srot (double phi, RealMatrix& R)
{
  //## begin TransportMatrix::Srot%882199464.body preserve=yes
	return phi==0 ? R : Srot(cos(phi),sin(phi),R);
  //## end TransportMatrix::Srot%882199464.body
}

//## Operation: SrotR4%908464077
inline RealMatrix& TransportMatrix::SrotR4 (double phi, RealMatrix& R)
{
  //## begin TransportMatrix::SrotR4%908464077.body preserve=yes
	return phi==0 ? R : SrotR4(cos(phi),sin(phi),R);
  //## end TransportMatrix::SrotR4%908464077.body
}

//## begin module%36BDEBCD038E.epilog preserve=yes
//## end module%36BDEBCD038E.epilog


#endif

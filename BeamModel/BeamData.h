//## begin module%36BDED6D0212.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamModel\BeamData.h
 * last modified 04/04/01 14:21:56
 */
//## end module%36BDED6D0212.cm

//## begin module%36BDED6D0212.cp preserve=no
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
//## end module%36BDED6D0212.cp

//## Module: BeamData%36BDED6D0212; Package specification
//## Subsystem: Merlin::BeamModel%3ACB10800370
//## Source file: D:\dev\Merlin\BeamModel\BeamData.h

#ifndef BeamData_h
#define BeamData_h 1

//## begin module%36BDED6D0212.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%36BDED6D0212.additionalIncludes

//## begin module%36BDED6D0212.includes preserve=yes
//## end module%36BDED6D0212.includes

//## begin module%36BDED6D0212.declarations preserve=no
//## end module%36BDED6D0212.declarations

//## begin module%36BDED6D0212.additionalDeclarations preserve=yes
//## end module%36BDED6D0212.additionalDeclarations


//## Class: BeamData%349504FF0104
//	Data structure for defining the 6-D beam phase space
//	(first- and second-order moments).
//## Category: Merlin::BeamModel%3ACB0C800384
//## Subsystem: Merlin::BeamModel%3ACB10800370
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class BeamData 
{
  public:
    //## Constructors (generated)
      BeamData()
        //## begin BeamData::BeamData.hasinit preserve=no
            : beta_x(0), beta_y(0), alpha_x(0), alpha_y(0), emit_x(0), emit_y(0), sig_dp(0), sig_z(0), x0(0), xp0(0), y0(0), yp0(0), ct0(0), p0(0), c_xy(0), c_xyp(0), c_xpy(0), c_xpyp(0), Dx(0), Dxp(0), Dy(0), Dyp(0), charge(1)
        //## end BeamData::BeamData.hasinit
      {
      }


    //## Other Operations (specified)
      //## Operation: ok%882180677
      //	Checks consistancy of definition. Returns true if *this
      //	is a valid beam, otherwise false.
      bool ok () const
      {
        //## begin BeamData::ok%882180677.body preserve=yes
		return emit_x>0 && emit_y>0 && beta_x>0 && beta_y>0;
        //## end BeamData::ok%882180677.body
      }

    // Data Members for Class Attributes

      //## Attribute: beta_x%3495058A0045
      //	TWISS beam parameters
      //## begin BeamData::beta_x%3495058A0045.attr preserve=no  public: double {UA} 0
      double beta_x;
      //## end BeamData::beta_x%3495058A0045.attr

      //## Attribute: beta_y%34950597026B
      //## begin BeamData::beta_y%34950597026B.attr preserve=no  public: double {UA} 0
      double beta_y;
      //## end BeamData::beta_y%34950597026B.attr

      //## Attribute: alpha_x%349505A502D9
      //## begin BeamData::alpha_x%349505A502D9.attr preserve=no  public: double {UA} 0
      double alpha_x;
      //## end BeamData::alpha_x%349505A502D9.attr

      //## Attribute: alpha_y%349505B500B5
      //## begin BeamData::alpha_y%349505B500B5.attr preserve=no  public: double {UA} 0
      double alpha_y;
      //## end BeamData::alpha_y%349505B500B5.attr

      //## Attribute: emit_x%349505DD0320
      //## begin BeamData::emit_x%349505DD0320.attr preserve=no  public: double {UA} 0
      double emit_x;
      //## end BeamData::emit_x%349505DD0320.attr

      //## Attribute: emit_y%349505E40230
      //## begin BeamData::emit_y%349505E40230.attr preserve=no  public: double {UA} 0
      double emit_y;
      //## end BeamData::emit_y%349505E40230.attr

      //## Attribute: sig_dp%349505E903A9
      //	Relative energy spread of beam.
      //## begin BeamData::sig_dp%349505E903A9.attr preserve=no  public: double {UA} 0
      double sig_dp;
      //## end BeamData::sig_dp%349505E903A9.attr

      //## Attribute: sig_z%349505F80058
      //	Beam length.
      //## begin BeamData::sig_z%349505F80058.attr preserve=no  public: double {UA} 0
      double sig_z;
      //## end BeamData::sig_z%349505F80058.attr

      //## Attribute: x0%3495060200A2
      //	Beam centroid.
      //## begin BeamData::x0%3495060200A2.attr preserve=no  public: double {UA} 0
      double x0;
      //## end BeamData::x0%3495060200A2.attr

      //## Attribute: xp0%349506170283
      //## begin BeamData::xp0%349506170283.attr preserve=no  public: double {UA} 0
      double xp0;
      //## end BeamData::xp0%349506170283.attr

      //## Attribute: y0%3495061B00BC
      //## begin BeamData::y0%3495061B00BC.attr preserve=no  public: double {UA} 0
      double y0;
      //## end BeamData::y0%3495061B00BC.attr

      //## Attribute: yp0%3495061D0372
      //## begin BeamData::yp0%3495061D0372.attr preserve=no  public: double {UA} 0
      double yp0;
      //## end BeamData::yp0%3495061D0372.attr

      //## Attribute: ct0%3495062401EB
      //## begin BeamData::ct0%3495062401EB.attr preserve=no  public: double {UA} 0
      double ct0;
      //## end BeamData::ct0%3495062401EB.attr

      //## Attribute: p0%3495063003E7
      //	Beam energy (momentum).
      //## begin BeamData::p0%3495063003E7.attr preserve=no  public: double {UA} 0
      double p0;
      //## end BeamData::p0%3495063003E7.attr

      //## Attribute: c_xy%349506340375
      //	X-Y coupling
      //## begin BeamData::c_xy%349506340375.attr preserve=no  public: double {UA} 0
      double c_xy;
      //## end BeamData::c_xy%349506340375.attr

      //## Attribute: c_xyp%3495064B001B
      //## begin BeamData::c_xyp%3495064B001B.attr preserve=no  public: double {UA} 0
      double c_xyp;
      //## end BeamData::c_xyp%3495064B001B.attr

      //## Attribute: c_xpy%3495064E0156
      //## begin BeamData::c_xpy%3495064E0156.attr preserve=no  public: double {UA} 0
      double c_xpy;
      //## end BeamData::c_xpy%3495064E0156.attr

      //## Attribute: c_xpyp%349506520101
      //## begin BeamData::c_xpyp%349506520101.attr preserve=no  public: double {UA} 0
      double c_xpyp;
      //## end BeamData::c_xpyp%349506520101.attr

      //## Attribute: Dx%3495065502F0
      //	Dispersion
      //## begin BeamData::Dx%3495065502F0.attr preserve=no  public: double {UA} 0
      double Dx;
      //## end BeamData::Dx%3495065502F0.attr

      //## Attribute: Dxp%3495065F0178
      //## begin BeamData::Dxp%3495065F0178.attr preserve=no  public: double {UA} 0
      double Dxp;
      //## end BeamData::Dxp%3495065F0178.attr

      //## Attribute: Dy%34950663014C
      //## begin BeamData::Dy%34950663014C.attr preserve=no  public: double {UA} 0
      double Dy;
      //## end BeamData::Dy%34950663014C.attr

      //## Attribute: Dyp%3495066600A6
      //## begin BeamData::Dyp%3495066600A6.attr preserve=no  public: double {UA} 0
      double Dyp;
      //## end BeamData::Dyp%3495066600A6.attr

      //## Attribute: charge%34CDCC28019C
      //	The charge of the particles in the beam. Should be -1 or
      //	+1.
      //## begin BeamData::charge%34CDCC28019C.attr preserve=no  public: double {UA} 1
      double charge;
      //## end BeamData::charge%34CDCC28019C.attr

  protected:
  private:
  private:  //## implementation
};

//## begin module%36BDED6D0212.epilog preserve=yes
//## end module%36BDED6D0212.epilog


#endif

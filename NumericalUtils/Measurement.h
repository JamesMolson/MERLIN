//## begin module.cm preserve=no
//	last created: 16:41:07 on 07/16/97
//## end module.cm

//## begin module.cp preserve=no
//	(c) 1997 Nicholas Walker - DESY -
//
//	-- All Rights Reserved --
//
//	This package is part of the MERLIN class library.
//## end module.cp

//## Module: Measurement; Package specification
//## Subsystem: NumericalUtils
//## Source file: c:\C++\Merlin\NumericalUtils\Measurement.h

#ifndef Measurement_h
#define Measurement_h 1

//## begin module.includes preserve=yes
//## end module.includes

//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: Measurement
//	POD representing a physically measured quantity, which
//	has a value and an associated error.
//## Category: NumericalUtils; Global
//## Subsystem: NumericalUtils
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class Measurement 
{
  public:
    //## Constructors (specified)
      //## Operation: Measurement%869056644
      Measurement (double v, double err);

      //## Operation: Measurement%869056646
      Measurement ();

    // Data Members for Class Attributes

      //## Attribute: value
      //## begin Measurement::value.attr preserve=no  public: double {UA} 
      double value;
      //## end Measurement::value.attr

      //## Attribute: error
      //## begin Measurement::error.attr preserve=no  public: double {UA} 
      double error;
      //## end Measurement::error.attr

  protected:
  private:
  private:  //## implementation
};



// Class Measurement 

inline Measurement::Measurement (double v, double err)
  //## begin Measurement::Measurement%869056644.hasinit preserve=no
  //## end Measurement::Measurement%869056644.hasinit
  //## begin Measurement::Measurement%869056644.initialization preserve=yes
  : value(v),error(err)
  //## end Measurement::Measurement%869056644.initialization
{
  //## begin Measurement::Measurement%869056644.body preserve=yes
  //## end Measurement::Measurement%869056644.body
}

inline Measurement::Measurement ()
  //## begin Measurement::Measurement%869056646.hasinit preserve=no
  //## end Measurement::Measurement%869056646.hasinit
  //## begin Measurement::Measurement%869056646.initialization preserve=yes
  //## end Measurement::Measurement%869056646.initialization
{
  //## begin Measurement::Measurement%869056646.body preserve=yes
  //## end Measurement::Measurement%869056646.body
}






// Class Measurement 





//## begin module.epilog preserve=yes
//## end module.epilog
#endif

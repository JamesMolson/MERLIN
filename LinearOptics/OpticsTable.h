//## begin module%1.2%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.2%.codegen_version

//## begin module%399BE03801BF.cm preserve=no
//## end module%399BE03801BF.cm

//## begin module%399BE03801BF.cp preserve=no
//## end module%399BE03801BF.cp

//## Module: OpticsTable%399BE03801BF; Package specification
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Source file: C:\C++\Merlin\LinearOptics\OpticsTable.h

#ifndef OpticsTable_h
#define OpticsTable_h 1

//## begin module%399BE03801BF.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%399BE03801BF.additionalIncludes

//## begin module%399BE03801BF.includes preserve=yes
#include "BeamModel/PStypes.h"
//## end module%399BE03801BF.includes

#include <list>
#include <set>
// OPFormat
#include "utility/OPFormat.h"
// AcceleratorModel
#include "AcceleratorModel/AcceleratorModel.h"
// BeamData
#include "BeamModel/BeamData.h"
// StringPattern
#include "utility/StringPattern.h"

class RMtrx;
typedef MVCMatrix< double , 6  > PSmoments;

//## begin module%399BE03801BF.additionalDeclarations preserve=yes
//## end module%399BE03801BF.additionalDeclarations


//## Class: OpticsTable%399BDF6901F4
//	OpticsTable is a class which calculates and ouput the
//	standard optics parameters for a specificed beamline.
//
//	The results are output as a table. Column 1 is always
//	the unqualified ID of the component. The remaining
//	columns can be specified using AddColumn(). The default
//	columns are
//
//	TYPE Z BX AX PHIX BY AY PHIY DX DXP
//
//	The output format of each numerical value (column) can
//	be specified independently, or can use the default
//	format specification.
//
//	Note that all output to the specified ostream are stings.
//## Category: Merlin::LinearOptics%3992C77E011C
//## Subsystem: Merlin::LinearOptics%3992D0D00339
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%399BDF940318;implementation: LinearMatrixTracker { -> }
//## Uses: <unnamed>%399BE5E20373;OpticsTable::Key { -> }
//## Uses: <unnamed>%399BE67E0291;OpticsTable::Location { -> }
//## Uses: <unnamed>%399BE69A004C;StringPattern { -> }
//## Uses: <unnamed>%399BEF7A0310;std::list { -> }
//## Uses: <unnamed>%39AA8B0403D9;std::set { -> }
//## Uses: <unnamed>%39ABAFE000CC;PSmoments { -> F}
//## Uses: <unnamed>%39ABB3D80312;RMtrx { -> F}

class OpticsTable 
{
  public:
    //## Class: Key%399BE53D02C1
    //## Category: Merlin::LinearOptics%3992C77E011C
    //## Subsystem: Merlin::LinearOptics%3992D0D00339
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef enum {BX,BY,AX,AY,PHIX,PHIY,DX,DXP,DY,DYP,Z,L,EX,EY,GEX,GEY,ENERGY} Key;

    //## Class: Location%399BE64102F7
    //## Category: Merlin::LinearOptics%3992C77E011C
    //## Subsystem: Merlin::LinearOptics%3992D0D00339
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef enum {noOutput,atEntrance,atCentre,atExit} Location;

  private: //## implementation
    //## Class: ColumnSpec%399BEF8D00C9; implementation
    //## Category: Merlin::LinearOptics%3992C77E011C
    //## Subsystem: Merlin::LinearOptics%3992D0D00339
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class ColumnSpec 
    {
      public:
        //## Constructors (specified)
          //## Operation: ColumnSpec%399BEFA602A5
          ColumnSpec (Key aKey, const OPFormat& aFmt);

        // Data Members for Class Attributes

          //## Attribute: cKey%399BEFAE0148
          //## begin OpticsTable::ColumnSpec::cKey%399BEFAE0148.attr preserve=no  public: Key {UA} 
          Key cKey;
          //## end OpticsTable::ColumnSpec::cKey%399BEFAE0148.attr

          //## Attribute: fmt%399BEFAE017A
          //## begin OpticsTable::ColumnSpec::fmt%399BEFAE017A.attr preserve=no  public: OPFormat {UA} 
          OPFormat fmt;
          //## end OpticsTable::ColumnSpec::fmt%399BEFAE017A.attr

      protected:
      private:
      private: //## implementation
    };

    //## Class: OutputSpec%39AA8A1A0007; implementation
    //	Specifies a location (row) in the table.
    //## Category: Merlin::LinearOptics%3992C77E011C
    //## Subsystem: Merlin::LinearOptics%3992D0D00339
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class OutputSpec 
    {
      public:
        //## Constructors (specified)
          //## Operation: OutputSpec%39AA8BC5015F
          OutputSpec ();

          //## Operation: OutputSpec%39AA8BCB010E
          OutputSpec (const string& anID, Location aPos);


        //## Other Operations (specified)
          //## Operation: operator<%39AA91C90196
          bool operator < (const OutputSpec& rhs) const;

        // Data Members for Class Attributes

          //## Attribute: id%39AA8A4F011C
          //## begin OpticsTable::OutputSpec::id%39AA8A4F011C.attr preserve=no  public: StringPattern {UA} 
          StringPattern id;
          //## end OpticsTable::OutputSpec::id%39AA8A4F011C.attr

          //## Attribute: loc%39AA8A680172
          //## begin OpticsTable::OutputSpec::loc%39AA8A680172.attr preserve=no  public: Location {UA} 
          Location loc;
          //## end OpticsTable::OutputSpec::loc%39AA8A680172.attr

      protected:
      private:
      private: //## implementation
    };

    //## Class: Twiss%39AD1D250035; implementation
    //	Simple POD struct containing the twiss data. Effectively
    //	adds the phase advance information to the BeamData
    //	struct.
    //## Category: Merlin::LinearOptics%3992C77E011C
    //## Subsystem: Merlin::LinearOptics%3992D0D00339
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    class Twiss : public BeamData  //## Inherits: <unnamed>%39AD1D770318
    {
      public:
        //## Constructors (generated)
          Twiss();


        //## Other Operations (specified)
          //## Operation: operator=%39AE157101A8
          void operator = (const BeamData& rhs);

        // Data Members for Class Attributes

          //## Attribute: phi_x%39AD1E3E006B
          //## begin OpticsTable::Twiss::phi_x%39AD1E3E006B.attr preserve=no  public: double {UA} 0
          double phi_x;
          //## end OpticsTable::Twiss::phi_x%39AD1E3E006B.attr

          //## Attribute: phi_y%39AD1E4303E3
          //## begin OpticsTable::Twiss::phi_y%39AD1E4303E3.attr preserve=no  public: double {UA} 0
          double phi_y;
          //## end OpticsTable::Twiss::phi_y%39AD1E4303E3.attr

      protected:
      private:
      private: //## implementation
    };

  public:
    //## Constructors (specified)
      //## Operation: OpticsTable%399BE9000276
      //	Constructor taking the beamline to be tracked, the
      //	initial beam parameters an the output stream.
      OpticsTable (const AcceleratorModel::Beamline bl, const BeamData& ibeam, ostream& anOs = cout);

      //## Operation: OpticsTable%399BE92B01D7
      //	Default constructor.
      OpticsTable ();


    //## Other Operations (specified)
      //## Operation: SetBeamline%399BE257006B
      //	Set the beamline to be tracked.
      void SetBeamline (const AcceleratorModel::Beamline& bl);

      //## Operation: SetInitialConditions%399BE2720223
      //	Sets the initial beamline conditions.
      void SetInitialConditions (const BeamData& beam0);

      //## Operation: AddOutputSpecifier%399BE29503D2
      //	Add an output specifier. By default, output is produced
      //	at the exit of every component in the beamline. When one
      //	or more specifiers is supplied, output is performed at
      //	only those components whose fully qualified name matches
      //	the supplied pattern. pos specifies whether the results
      //	are to be output at the entrance, centre or exit of the
      //	element.
      void AddOutputSpecifier (const string& pat, Location pos = atExit);

      //## Operation: ClearOutputSpecifiers%399BE86701AE
      //	Clear all user-supplied output specifiers.
      void ClearOutputSpecifiers ();

      //## Operation: ClearColumns%399BE3600211
      //	Clears the current column specifiers.
      void ClearColumns ();

      //## Operation: AddColumn%399BE3BF0177
      //	Append a new column to the output table. The value is
      //	output using the default number format.
      void AddColumn (Key key);

      //## Operation: AddColumn%399BE4A8003C
      //	Append a new column to the output table. The value is
      //	output using the specified format.
      void AddColumn (Key key, const OPFormat& fmtSpec);

      //## Operation: SetStream%399BE5FB0347
      //	Sets the output stream.
      void SetStream (ostream& anOs);

      //## Operation: Calculate%399BE61202BD
      //	Calculates and outputs the optics functions.
      void Calculate ();

      //## Operation: SetDefaultColumns%399BE62200A4
      //	Resets the column specifiers to the defaults.
      void SetDefaultColumns ();

      //## Operation: SetDefaultFormatSpecifier%399BE99E009C
      //	Sets the default format specifier. Column output not
      //	having a specific format specifier will use this format.
      void SetDefaultFormatSpecifier (const OPFormat& fmtSpec);

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: os%399BE1EA00DD
      //## begin OpticsTable::os%399BE1EA00DD.attr preserve=no  private: ostream* {UA} 
      ostream* os;
      //## end OpticsTable::os%399BE1EA00DD.attr

    // Data Members for Associations

      //## Association: Merlin::LinearOptics::<unnamed>%399BE150026C
      //## Role: OpticsTable::theBeamline%399BE150026E
      //## begin OpticsTable::theBeamline%399BE150026E.role preserve=no  private: AcceleratorModel::Beamline { -> VHgAN}
      AcceleratorModel::Beamline theBeamline;
      //## end OpticsTable::theBeamline%399BE150026E.role

      //## Association: Merlin::LinearOptics::<unnamed>%399BE1570172
      //## Role: OpticsTable::iBeam%399BE1570174
      //## begin OpticsTable::iBeam%399BE1570174.role preserve=no  private: BeamData { -> VHgAN}
      BeamData iBeam;
      //## end OpticsTable::iBeam%399BE1570174.role

      //## Association: Merlin::LinearOptics::<unnamed>%399BE522039F
      //## Role: OpticsTable::defaultFmtSpec%399BE52203A1
      //## begin OpticsTable::defaultFmtSpec%399BE52203A1.role preserve=no  private: OPFormat { -> VHgAN}
      OPFormat defaultFmtSpec;
      //## end OpticsTable::defaultFmtSpec%399BE52203A1.role

      //## Association: Merlin::LinearOptics::<unnamed>%399BEDA30042
      //## Role: OpticsTable::theColumns%399BEDA3027D
      //## begin OpticsTable::theColumns%399BEDA3027D.role preserve=no  private: std::list< ColumnSpec  > { -> VHgAN}
      std::list< ColumnSpec  > theColumns;
      //## end OpticsTable::theColumns%399BEDA3027D.role

      //## Association: Merlin::LinearOptics::<unnamed>%39AA8AB10130
      //## Role: OpticsTable::itsOutputSpecs%39AA8AB10339
      //## begin OpticsTable::itsOutputSpecs%39AA8AB10339.role preserve=no  private: std::set< OutputSpec  > { -> VHgAN}
      std::set< OutputSpec  > itsOutputSpecs;
      //## end OpticsTable::itsOutputSpecs%39AA8AB10339.role

  private: //## implementation

    //## Other Operations (specified)
      //## Operation: GetOutputSpec%399BEEC10115
      Location GetOutputSpec (const string& id);

      //## Operation: UpdateTwiss%39ABB343006F
      void UpdateTwiss (const PSmoments& S0, const RMtrx& R, double p0);

      //## Operation: OutputRow%39AD2A4900E6
      void OutputRow (const string& label, double z, double l);

      //## Operation: Init%39AE13B70351
      void Init ();

    // Data Members for Associations

      //## Association: Merlin::LinearOptics::<unnamed>%39AD1DB600E8
      //## Role: OpticsTable::lastTwiss%39AD1DB6037D
      //	Updated twiss parameters
      //## begin OpticsTable::lastTwiss%39AD1DB6037D.role preserve=no  implementation: OpticsTable::Twiss { -> VHgAN}
      Twiss lastTwiss;
      //## end OpticsTable::lastTwiss%39AD1DB6037D.role

};

// Class OpticsTable::ColumnSpec 

// Class OpticsTable::OutputSpec 


//## Other Operations (inline)
//## Operation: operator<%39AA91C90196
inline bool OpticsTable::OutputSpec::operator < (const OutputSpec& rhs) const
{
  //## begin OpticsTable::OutputSpec::operator<%39AA91C90196.body preserve=yes
	return id<rhs.id;
  //## end OpticsTable::OutputSpec::operator<%39AA91C90196.body
}

// Class OpticsTable::Twiss 

inline OpticsTable::Twiss::Twiss()
  //## begin Twiss::Twiss%39AD1D250035_const.hasinit preserve=no
      : phi_x(0),
        phi_y(0)
  //## end Twiss::Twiss%39AD1D250035_const.hasinit
  //## begin Twiss::Twiss%39AD1D250035_const.initialization preserve=yes
  //## end Twiss::Twiss%39AD1D250035_const.initialization
{
  //## begin OpticsTable::Twiss::Twiss%39AD1D250035_const.body preserve=yes
  //## end OpticsTable::Twiss::Twiss%39AD1D250035_const.body
}



//## Other Operations (inline)
//## Operation: operator=%39AE157101A8
inline void OpticsTable::Twiss::operator = (const BeamData& rhs)
{
  //## begin OpticsTable::Twiss::operator=%39AE157101A8.body preserve=yes
	BeamData::operator=(rhs);
  //## end OpticsTable::Twiss::operator=%39AE157101A8.body
}

// Class OpticsTable 

//## begin module%399BE03801BF.epilog preserve=yes
//## end module%399BE03801BF.epilog


#endif

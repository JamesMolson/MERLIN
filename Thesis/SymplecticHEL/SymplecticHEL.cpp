//Include relevant C++ headers

#include <iostream> // input/output
#include <sstream> // handles string streams
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <ctime> // used for random seed
#include <sys/stat.h> //to use mkdir

//include relevant MERLIN headers
#include "AcceleratorModel/Apertures/CollimatorAperture.h"
#include "AcceleratorModel/Apertures/SimpleApertures.h"

#include "BeamDynamics/ParticleTracking/ParticleBunchConstructor.h"
#include "BeamDynamics/ParticleTracking/ParticleTracker.h"
#include "BeamDynamics/ParticleTracking/ParticleBunchTypes.h"
#include "BeamDynamics/ParticleTracking/HollowELensProcess.h"
#include "BeamDynamics/ParticleTracking/SymplecticHollowELensProcess.h"
#include "BeamDynamics/ParticleTracking/Integrators/SymplecticIntegrators.h"
#include "BeamDynamics/ParticleTracking/BunchFilter.h"

#include "Collimators/CollimateProtonProcess.h"
#include "Collimators/ScatteringProcess.h"
#include "Collimators/ScatteringModel.h"
#include "Collimators/CollimatorDatabase.h"
#include "Collimators/MaterialDatabase.h"
#include "Collimators/ApertureConfiguration.h"
#include "Collimators/Dustbin.h"

#include "MADInterface/MADInterface.h"

#include "NumericalUtils/PhysicalUnits.h"
#include "NumericalUtils/PhysicalConstants.h"

#include "Random/RandomNG.h"

#include "RingDynamics/Dispersion.h"
#include "RingDynamics/PhaseAdvance.h"

// C++ std namespace, and MERLIN PhysicalUnits namespace

using namespace std;
using namespace PhysicalUnits;

// Main function, this executable can be run with the arguments number_of_particles seed

//e.g. for 1000 particles and a seed of 356: ./test 1000 356

int main(int argc, char* argv[])
{
    int seed = (int)time(NULL); // seed for random number generators
    int npart = 31;             // number of particles to track
    int nturns = 1E3;             // number of turns to track
    
    string bunch_dir, loss_dir, sp_dir, pn_dir, tune_dir, lattice_dir, case_dir, full_case_dir;
    
    //~ string directory = "/afs/cern.ch/user/h/harafiqu/public/MERLIN";	//lxplus harafiqu
	//~ string directory = "/home/haroon/git/Merlin";				//iiaa1
	string directory = "/home/HR/Downloads/MERLIN";					//M11x	
	//~ string directory = "/afs/cern.ch/user/a/avalloni/private/Merlin_all";	//lxplus avalloni
	
	string input_dir = "/Thesis/data/SymplecticHEL/";
	
	//~ string output_dir = "/HEL_RUNS/UserSim/outputs/E_HEL/";	
	string output_dir = "/Build/Thesis/outputs/SymplecticHEL/";
	//~ string output_dir = "/HEL_TESTS/UserSim/outputs/E_HEL/";
	
	string full_output_dir = (directory+output_dir);
	mkdir(full_output_dir.c_str(), S_IRWXU);
	
	bool batch = 1;
	if(batch){
		case_dir = "Test/";
	}
	
	
	bool collimation_on 			= 0;
		bool sixtrack 				= 0; 		//use sixtrack like scattering?
		bool dust 					= 1; 		//use dustbin
		if (collimation_on && dust){
			loss_dir = (full_output_dir+"Loss/");
			mkdir(loss_dir.c_str(), S_IRWXU);
			if(batch){
				loss_dir = (full_output_dir+"Loss/"+case_dir);
				mkdir(loss_dir.c_str(), S_IRWXU);
			}
		}
		
	bool cut_distn				= 1;		//cut out stable part of distn
	bool output_initial_bunch 	= 1;
	bool output_final_bunch 	= 1;
		if (output_initial_bunch || output_final_bunch){
			bunch_dir = (full_output_dir+"Bunch_Distn/");
			mkdir(bunch_dir.c_str(), S_IRWXU);
			if(batch){
				bunch_dir = (full_output_dir+"Bunch_Distn/"+case_dir);
				mkdir(bunch_dir.c_str(), S_IRWXU);
			}

		}
		
	bool track 					= 1;
	bool output_twiss			= 0;
		if(output_twiss){
			lattice_dir = (full_output_dir+"LatticeFunctions/");
			mkdir(lattice_dir.c_str(), S_IRWXU);
		}
	
	bool start_at_hel			= 0;		//Inject at HEL?
	bool start_at_IP1			= 1;		//Inject at IP1?
	
	bool hel_on 				= 1; 		//Hollow electron lens process?
	bool LHC_HEL				= 1;
		bool DCon							= 1;
		bool ACon							= 0;
		if(ACon){DCon=0;}
		bool Turnskipon						= 0;
		if(Turnskipon){ACon=0; DCon=0;}
		bool Diffusiveon					= 0;
		if(Diffusiveon){ACon=0; Turnskipon=0; DCon=0;}

	bool output_turn_bunch		= 0;		//Output particleno every turn
	bool single_particle		= 0;		//Track single particle
	bool every_bunch			= 1;		//output whole bunch every turn in a single file
		if(single_particle){
			output_turn_bunch = 1;
			//~ npart = 11;			
			sp_dir = (full_output_dir+"SingleParticle/");
			mkdir(sp_dir.c_str(), S_IRWXU);
		}
		if(output_turn_bunch){
			track = 1; 
			pn_dir = (full_output_dir+"ParticleNo/");
			mkdir(pn_dir.c_str(), S_IRWXU);
			if(batch){pn_dir = (
				full_output_dir+"ParticleNo/"+case_dir);
				mkdir(pn_dir.c_str(), S_IRWXU);
			}
		}	
	
	bool calc_tune				= 0;
	bool tune_test				= 0;
		if(tune_test){
			single_particle = 0;
			tune_dir = (full_output_dir+"Tune/");
			mkdir(tune_dir.c_str(), S_IRWXU);
			if(batch){
				tune_dir = (full_output_dir+"Tune/"+case_dir);
				mkdir(tune_dir.c_str(), S_IRWXU);
			}
		}
		
	bool input_distn 			= 0;	//use SixTrack input distn
	bool cleaning				= 0;
	if(cleaning){
		collimation_on 		= 1;
		track 				= 1;
		output_turn_bunch 	= 1;
		single_particle 	= 0;
		tune_test 			= 0;
		npart 				= 1E3;
		nturns 				= 1E5;
		start_at_hel		= 0;
		start_at_IP1		= 0;
		input_distn 		= 0;
	}	
	 
    if (argc >=2){
        npart = atoi(argv[1]);
    }

    if (argc >=3){
        seed = atoi(argv[2]);
    }

// Initialise the random number generator with the seed

    RandomNG::init(seed);

    double beam_energy = 7000.0;

    cout << "npart=" << npart << " nturns=" << nturns << " beam energy = " << beam_energy << endl;

    // Define useful variables
    double beam_charge = 1.1e11;
    double normalized_emittance = 3.5e-6;
    double gamma = beam_energy/PhysicalConstants::ProtonMassMeV/PhysicalUnits::MeV;
	double beta = sqrt(1.0-(1.0/pow(gamma,2)));
	double emittance = normalized_emittance/(gamma*beta);
	
///////////////////////////////////
// ACCELERATORMODEL CONSTRUCTION //
///////////////////////////////////
	cout << "MADInterface" << endl;

	MADInterface* myMADinterface = new MADInterface( directory+input_dir+"twiss_hllhc_b1_thick_HEL.tfs", beam_energy );
	//~ myMADinterface->TreatTypeAsDrift("RFCAVITY");
    //~ myMADinterface->TreatTypeAsDrift("SEXTUPOLE");
    //~ myMADinterface->TreatTypeAsDrift("OCTUPOLE");
	myMADinterface->ConstructApertures(false);
    AcceleratorModel* myAccModel = myMADinterface->ConstructModel();    

	int start_element_number;
	string start_element;
	string tcp_element = "TCP.C6L7.B1";    // HORIZONTAL COLLIMATOR (x)
    int tcp_element_number = myAccModel->FindElementLatticePosition(tcp_element.c_str());
    string hel_element = "HEL.B5R4.B1";
	int hel_element_number = myAccModel->FindElementLatticePosition(hel_element.c_str());
    string ip1_element = "IP1";
	int ip1_element_number = myAccModel->FindElementLatticePosition(ip1_element.c_str());	
    string end_element = "IP1.L1";
	int end_element_number = myAccModel->FindElementLatticePosition(end_element.c_str());	
	if(start_at_hel){		start_element = "HEL.B5R4.B1"; 	start_element_number = hel_element_number;}
	else if (start_at_IP1){	start_element = "IP1"; 			start_element_number = ip1_element_number;}
	else {					start_element = "TCP.C6L7.B1"; 	start_element_number = tcp_element_number;}
    
    cout << "Found element IP1 at element number " << ip1_element_number << endl;
    cout << "Found element TCP.C6L7 at element number " << tcp_element_number << endl;
    cout << "Found element HEL.B5R4 at element number " << hel_element_number << endl;
    cout << "Found element IP1.L1 at element number " << end_element_number << endl;
    cout << "Start element number " << start_element_number << endl;

///////////
// TWISS //
///////////
	LatticeFunctionTable* myTwiss = new LatticeFunctionTable(myAccModel, beam_energy);
    myTwiss->AddFunction(1,6,3);
    myTwiss->AddFunction(2,6,3);
    myTwiss->AddFunction(3,6,3);
    myTwiss->AddFunction(4,6,3);
    myTwiss->AddFunction(6,6,3);
    myTwiss->AddFunction(0,0,1);
    myTwiss->AddFunction(0,0,2);
    myTwiss->AddFunction(0,0,3);

    // Next we find the TWISS parameters
    double bscale1 = 1e-22;
      
	while(true)
	{
	cout << "start while(true) to scale bend path length" << endl;
		myTwiss->ScaleBendPathLength(bscale1);
		myTwiss->Calculate();

		if(!std::isnan(myTwiss->Value(1,1,1,0))) {break;}
		bscale1 *= 2;
	}

	if(output_twiss){
		ostringstream twiss_output_file; 
		twiss_output_file << (lattice_dir+"LatticeFunctions.dat");
		ofstream twiss_output(twiss_output_file.str().c_str());
		myTwiss->PrintTable(twiss_output);
	}
	
///////////////////////
// Collimator set up //
///////////////////////
	cout << "Collimator Setup" << endl;   
	MaterialDatabase* myMaterialDatabase = new MaterialDatabase();
	CollimatorDatabase* collimator_db = new CollimatorDatabase( directory+input_dir+"CollimatorFile_HL_HEL.txt", myMaterialDatabase,  true);
   
    collimator_db->MatchBeamEnvelope(true);
    collimator_db->EnableJawAlignmentErrors(false);

    collimator_db->SetJawPositionError(0.0 * nanometer);
    collimator_db->SetJawAngleError(0.0 * microradian);

    // HLv1.2  -0.2 sigma = -5.328E-5
    // HLv1.2  -0.3 sigma = -7.992E-5
    // HLv1.2  -1.2 sigma = -3.196E-4
    // HLv1.2  -0.7 sigma = -1.8648E-4
    
    //~ collimator_db->SelectImpactFactor(start_element, 1.0e-6);
    collimator_db->SelectImpactFactor(start_element, -5.328E-5);
    //~ collimator_db->SelectImpactFactor(start_element, -7.992E-5); 
    
    //using actual jaw position
    //~ collimator_db->SelectImpactFactor(start_element, -5.5053E-5);

    double impact = 6;
    try{
        impact = collimator_db->ConfigureCollimators(myAccModel, emittance, emittance, myTwiss);
    }
    catch(exception& e){
        std::cout << "Exception caught: " << e.what() << std::endl;
        exit(1);
    }
    if(std::isnan(impact)){
        cerr << "Impact is nan" << endl;
        exit(1);
    }
    cout << "Impact factor number of sigmas: " << impact << endl;
    delete collimator_db;
    
    
	cout << "\n\n\n\n\t\t\t\t EMITTANCE = " << emittance << endl;

////////////////////////////
// Aperture Configuration //
////////////////////////////

	ApertureConfiguration* myApertureConfiguration = new ApertureConfiguration(directory+input_dir+"lhc_b1_thick_corr.tfs",1);      
    
    myApertureConfiguration->ConfigureElementApertures(myAccModel);
    delete myApertureConfiguration;
    
    CollimatorAperture* CollimatorJaw;
    
    if(collimation_on){
		
		//CHECK FOR COLLIMATOR APERTURES	
		vector<Collimator*> TCP;
		int siz = myAccModel->ExtractTypedElements(TCP, start_element);
		
		cout << "\n\t Found " << TCP.size() << " Collimators when extracting" << endl;

		Aperture *ap = (TCP[0])->GetAperture();
		if(!ap)
			{cout << "Could not get tcp ap" << endl;	abort();}
		else{cout << "TCP aperture type = " << ap->GetApertureType() << endl;}

		CollimatorJaw = dynamic_cast<CollimatorAperture*>(ap);
		if(!CollimatorJaw)
			{cout << "Could not cast" << endl;	abort();}
			
		//PhaseAdvance(AcceleratorModel* aModel, LatticeFunctionTable* aTwiss, double refMomentum);
		PhaseAdvance* PA = new PhaseAdvance(myAccModel, myTwiss, beam_energy);
		double mu_x = PA->GetPhaseAdvanceX(hel_element_number);
		double mu_y = PA->GetPhaseAdvanceY(hel_element_number);
		
		cout << "PA.mux = " << mu_x << endl;
		cout << "PA.muy = " << mu_y << endl;
	}

///////////////////
// BEAM SETTINGS //
///////////////////

    Dispersion* myDispersion = new Dispersion(myAccModel, beam_energy);
    myDispersion->FindDispersion(start_element_number);

    BeamData mybeam;

    mybeam.charge = beam_charge/npart;
    mybeam.p0 = beam_energy;
    mybeam.beta_x = myTwiss->Value(1,1,1,start_element_number)*meter;
    mybeam.beta_y = myTwiss->Value(3,3,2,start_element_number)*meter;
    mybeam.alpha_x = -myTwiss->Value(1,2,1,start_element_number);
    mybeam.alpha_y = -myTwiss->Value(3,4,2,start_element_number);

    // Dispersion
    mybeam.Dx=myDispersion->Dx;
    mybeam.Dy=myDispersion->Dy;
    mybeam.Dxp=myDispersion->Dxp;
    mybeam.Dyp=myDispersion->Dyp;

    mybeam.emit_x = impact * impact * emittance * meter;
    impact =1;
    mybeam.emit_y = impact * impact * emittance * meter;
    mybeam.sig_z = 0.0;

    //Beam centroid
    mybeam.x0=myTwiss->Value(1,0,0,start_element_number);
    mybeam.xp0=myTwiss->Value(2,0,0,start_element_number);
    mybeam.y0=myTwiss->Value(3,0,0,start_element_number);
    mybeam.yp0=myTwiss->Value(4,0,0,start_element_number);
    mybeam.ct0=myTwiss->Value(5,0,0,start_element_number);

    mybeam.sig_dp = 0.0;

    // X-Y coupling
    mybeam.c_xy=0.0;
    mybeam.c_xyp=0.0;
    mybeam.c_xpy=0.0;
    mybeam.c_xpyp=0.0;

    delete myDispersion;

///////////
// BUNCH //
///////////

    ProtonBunch* myBunch;
    if(input_distn){
		ifstream* bunch_input = new ifstream("/home/HR/Downloads/MERLIN/UserSim/data/LHC_HEL_Input/input.txt");
		
		istream* is = bunch_input;
		myBunch = new ProtonBunch(beam_energy, mybeam.charge, *is);	

	}
	else{
		int node_particles = npart;
		ParticleBunchConstructor* myBunchCtor;

		if(single_particle || every_bunch){
			myBunchCtor = new ParticleBunchConstructor(mybeam, node_particles, tuneTestDistribution);
			//~ myBunchCtor = new ParticleBunchConstructor(mybeam, node_particles, vertTestDistribution);
		}
		else if(tune_test){
			myBunchCtor = new ParticleBunchConstructor(mybeam, node_particles, tuneTestDistribution);
			//~ myBunchCtor = new ParticleBunchConstructor(mybeam, node_particles, vertTestDistribution);
		}
		else{
			myBunchCtor = new ParticleBunchConstructor(mybeam, node_particles, horizontalHaloDistribution1);
			//~ myBunchCtor = new ParticleBunchConstructor(mybeam, node_particles, horizontalHaloDistribution2);
			//~ myBunchCtor = new ParticleBunchConstructor(mybeam, node_particles, flatDistribution);
			//~ myBunchCtor = new ParticleBunchConstructor(mybeam, node_particles, tuneTestDistribution);
		} 
	
//////////////////
// BUNCH FILTER //
//////////////////		
		if(collimation_on && cut_distn){ 
			double h_offset = myTwiss->Value(1,0,0,start_element_number);
			double JawPosition = (CollimatorJaw->GetFullWidth() / 2.0);
			cout << "h_offset: " << h_offset << endl;	
			cout << "Jaw position: " << JawPosition << endl;

			HorizontalHaloParticleBunchFilter* hFilter = new HorizontalHaloParticleBunchFilter();
			double tcpsig = 264.4E-6;
			hFilter->SetHorizontalLimit(4*tcpsig);
			hFilter->SetHorizontalOrbit(h_offset);
			
			myBunchCtor->SetFilter(hFilter); 
		}

		myBunch = myBunchCtor->ConstructParticleBunch<ProtonBunch>();
		delete myBunchCtor;

		myBunch->SetMacroParticleCharge(mybeam.charge);
	}


//////////////////////////
// OUTPUT INITIAL BUNCH ///
/////////////////////////
		if(output_initial_bunch)
	    {
		    ostringstream bunch_output_file;
		    bunch_output_file << (bunch_dir + "initial_bunch.txt");

		    ofstream* bunch_output = new ofstream(bunch_output_file.str().c_str());
		    myBunch->Output(*bunch_output);
		    delete bunch_output;

		 }
/////////////////////
// ParticleTracker //
/////////////////////

//Phase_ellipse
	AcceleratorModel::Beamline beamline1 = myAccModel->GetBeamline(ip1_element_number, hel_element_number);
	AcceleratorModel::Beamline beamline2 = myAccModel->GetBeamline(hel_element_number, end_element_number);
    ParticleTracker* myParticleTracker1 = new ParticleTracker(beamline1, myBunch);
    ParticleTracker* myParticleTracker2 = new ParticleTracker(beamline2, myBunch);

	myParticleTracker1->SetIntegratorSet(new ParticleTracking::SYMPLECTIC::StdISet());	
	myParticleTracker2->SetIntegratorSet(new ParticleTracking::SYMPLECTIC::StdISet());	
    
//Cleaning
	//~ AcceleratorModel::RingIterator beamline = myAccModel->GetRing(start_element_number);
    //~ ParticleTracker* myParticleTracker = new ParticleTracker(beamline, myBunch);

/////////////////////////
// Collimation Process //
/////////////////////////
	LossMapDustbin* myDustbin = new LossMapDustbin;
	if(collimation_on){
		CollimateProtonProcess* myCollimateProcess =new CollimateProtonProcess(2, 4, NULL);
	
		myCollimateProcess->SetDustbin(myDustbin);       

		//No scattering for HEL cleaning
		myCollimateProcess->ScatterAtCollimator(false);
	   
		ScatteringModel* myScatter = new ScatteringModel;
	  
		if(sixtrack){
			myScatter->SetScatterType(0);
		}
		else{
			myScatter->SetScatterType(4);
		}

		myCollimateProcess->SetScatteringModel(myScatter);
		myCollimateProcess->SetLossThreshold(200.0);
		myCollimateProcess->SetOutputBinSize(0.1);

		myParticleTracker1->AddProcess(myCollimateProcess);
		myParticleTracker2->AddProcess(myCollimateProcess);
		//~ myParticleTracker->AddProcess(myCollimateProcess);
	}			
	
/////////////////
// HEL Process //
/////////////////	
	if(hel_on){
		
		// HollowELensProcess (int priority, int mode, double current, double beta_e, double rigidity, double length_e);
		//~ HollowELensProcess* myHELProcess;
		SymplecticHollowELensProcess* myHELProcess;
			
		if(LHC_HEL){	// LHC: 3m, 10KeV, 5A
			myHELProcess = new SymplecticHollowELensProcess(3, 1, 5, 0.195, 2.334948339E4, 3.0);
			//~ myHELProcess = new HollowELensProcess(3, 1, 5, 0.195, 2.334948339E4, 3.0);
		}
		else{			//Tevatron: 2m, 5KeV, 1.2A
			myHELProcess = new SymplecticHollowELensProcess(2, 1, 1.2, 0.138874007, 2.334948339E4, 2.0);
			//~ myHELProcess = new HollowELensProcess(2, 1, 1.2, 0.138874007, 2.334948339E4, 2.0);
		}
				
		myHELProcess->SetRadialProfile();
		//~ myHELProcess->SetPerfectProfile();
		
		if(LHC_HEL){
			myHELProcess->SetRadiiSigma(4, 8, myAccModel, emittance, emittance, myTwiss);
		}
		else{//Tevatron
			myHELProcess->SetRadiiSigma(4, 6.8, myAccModel, emittance, emittance, myTwiss);
		}		
		
		if(ACon){
			//Set AC variables
			//HollowELensProcess::SetAC (double tune, double deltatune, double tunevarperstep, double turnsperstep, double multi) 
			//H20
			myHELProcess->SetAC(0.31, .002, 5E-5, 1E3, 2.);
			myHELProcess->SetOpMode(AC);
		}
		else if(DCon){
			myHELProcess->SetOpMode(DC);
		}
		else if(Diffusiveon){	
			myHELProcess->SetOpMode(Diffusive);
		}
		else if(Turnskipon){	
			myHELProcess->SetTurnskip(2);
			myHELProcess->SetOpMode(Turnskip);
		}
		myParticleTracker1->AddProcess(myHELProcess);	
		myParticleTracker2->AddProcess(myHELProcess);	
		//~ myParticleTracker->AddProcess(myHELProcess);	
	}
	
////////////////////////////
// Single particle output //
////////////////////////////	

		ostringstream p0_output_file;
		ostringstream p1_output_file;
		ostringstream p2_output_file;
		ostringstream p3_output_file;
		ostringstream p4_output_file;
		ostringstream p5_output_file;
		ostringstream p6_output_file;
		ostringstream p7_output_file;
		ostringstream p8_output_file;
		ostringstream p9_output_file;
		ostringstream p10_output_file;
	
		if(single_particle && hel_on && DCon){
			string dc_dir = (sp_dir+"DC/");
			mkdir(dc_dir.c_str(), S_IRWXU);
			p0_output_file << dc_dir << "p0.txt";
			p1_output_file << dc_dir << "p1.txt";
			p2_output_file << dc_dir << "p2.txt";
			p3_output_file << dc_dir << "p3.txt";
			p4_output_file << dc_dir << "p4.txt";
			p5_output_file << dc_dir << "p5.txt";
			p6_output_file << dc_dir << "p6.txt";
			p7_output_file << dc_dir << "p7.txt";
			p8_output_file << dc_dir << "p8.txt";
			p9_output_file << dc_dir << "p9.txt";
			p10_output_file << dc_dir << "p10.txt";
		}
		else if(single_particle && hel_on && ACon){
			string ac_dir = (sp_dir+"AC/");
			mkdir(ac_dir.c_str(), S_IRWXU);
			p0_output_file << ac_dir << "p0.txt";
			p1_output_file << ac_dir << "p1.txt";
			p2_output_file << ac_dir << "p2.txt";
			p3_output_file << ac_dir << "p3.txt";
			p4_output_file << ac_dir << "p4.txt";
			p5_output_file << ac_dir << "p5.txt";
			p6_output_file << ac_dir << "p6.txt";
			p7_output_file << ac_dir << "p7.txt";
			p8_output_file << ac_dir << "p8.txt";
			p9_output_file << ac_dir << "p9.txt";
			p10_output_file << ac_dir << "p10.txt";
		}
		else if(single_particle && hel_on && Diffusiveon){
			string diff_dir = (sp_dir+"Diff/");
			mkdir(diff_dir.c_str(), S_IRWXU);
			p0_output_file << diff_dir << "p0.txt";
			p1_output_file << diff_dir << "p1.txt";
			p2_output_file << diff_dir << "p2.txt";
			p3_output_file << diff_dir << "p3.txt";
			p4_output_file << diff_dir << "p4.txt";
			p5_output_file << diff_dir << "p5.txt";
			p6_output_file << diff_dir << "p6.txt";
			p7_output_file << diff_dir << "p7.txt";
			p8_output_file << diff_dir << "p8.txt";
			p9_output_file << diff_dir << "p9.txt";
			p10_output_file << diff_dir << "p10.txt";
		}
		else if (single_particle){
			string nh_dir = (sp_dir+"nH/");
			mkdir(nh_dir.c_str(), S_IRWXU);
			p0_output_file << nh_dir << "p0.txt";
			p1_output_file << nh_dir << "p1.txt";
			p2_output_file << nh_dir << "p2.txt";
			p3_output_file << nh_dir << "p3.txt";
			p4_output_file << nh_dir << "p4.txt";
			p5_output_file << nh_dir << "p5.txt";
			p6_output_file << nh_dir << "p6.txt";
			p7_output_file << nh_dir << "p7.txt";
			p8_output_file << nh_dir << "p8.txt";
			p9_output_file << nh_dir << "p9.txt";
			p10_output_file << nh_dir << "p10.txt";
		}
		
		ofstream* p0_output = new ofstream(p0_output_file.str().c_str());
		ofstream* p1_output = new ofstream(p1_output_file.str().c_str());
		ofstream* p2_output = new ofstream(p2_output_file.str().c_str());
		ofstream* p3_output = new ofstream(p3_output_file.str().c_str());
		ofstream* p4_output = new ofstream(p4_output_file.str().c_str());
		ofstream* p5_output = new ofstream(p5_output_file.str().c_str());
		ofstream* p6_output = new ofstream(p6_output_file.str().c_str());
		ofstream* p7_output = new ofstream(p7_output_file.str().c_str());
		ofstream* p8_output = new ofstream(p8_output_file.str().c_str());
		ofstream* p9_output = new ofstream(p9_output_file.str().c_str());
		ofstream* p10_output = new ofstream(p10_output_file.str().c_str());
		
		ostringstream particle_no_file;
        particle_no_file << pn_dir<< "No.txt";
        ofstream* particle_no_output = new ofstream(particle_no_file.str().c_str());
        
// Output bunch every turn in one file
		ostringstream bo_file;
		bo_file << bunch_dir << "total_bunch.txt";
		
		//truncate (clear) the file first to prevent appending to last run
		ofstream* boclean = new ofstream(bo_file.str().c_str(), ios::trunc);
		ofstream* bo = new ofstream(bo_file.str().c_str(), ios::app);
		
		//~ ofstream* bo;
		//~ (*bo).open (bo_file.str().c_str(), std::ofstream::out | std::ofstream::app);
//////////////////
// TRACKING RUN //
//////////////////

	if(track){
		if(output_turn_bunch)
		(*particle_no_output) << "0\t" << myBunch->size() << endl;
		
		//~ if(single_particle && hel_on){
			//~ myBunch->OutputIndexParticle(*p0_output,0);
			//~ myBunch->OutputIndexParticle(*p1_output,1);
			//~ myBunch->OutputIndexParticle(*p2_output,2);
			//~ myBunch->OutputIndexParticle(*p3_output,3);
			//~ myBunch->OutputIndexParticle(*p4_output,4);
			//~ myBunch->OutputIndexParticle(*p5_output,5);
			//~ myBunch->OutputIndexParticle(*p6_output,6);
			//~ myBunch->OutputIndexParticle(*p7_output,7);
			//~ myBunch->OutputIndexParticle(*p8_output,8);
			//~ myBunch->OutputIndexParticle(*p9_output,9);
			//~ myBunch->OutputIndexParticle(*p10_output,10);
		//~ }
		
		for (int turn=1; turn<=nturns; turn++)
		{
			//~ myParticleTracker = new ParticleTracker(beamline1, myBunch);
			
			cout << "Turn " << turn <<"\tParticle number: " << myBunch->size() << endl;
			if(output_turn_bunch)
			(*particle_no_output) << turn <<"\t" << myBunch->size() << endl;

			myParticleTracker1->Track(myBunch);
			//~ myParticleTracker->Track(myBunch);
			
			
			//Split the tracker to output at HEL
			if(every_bunch){myBunch->Output(*bo);}
			
			if(single_particle && hel_on){
				myBunch->OutputIndexParticle(*p0_output,0);
				myBunch->OutputIndexParticle(*p1_output,1);
				myBunch->OutputIndexParticle(*p2_output,2);
				myBunch->OutputIndexParticle(*p3_output,3);
				myBunch->OutputIndexParticle(*p4_output,4);
				myBunch->OutputIndexParticle(*p5_output,5);
				myBunch->OutputIndexParticle(*p6_output,6);
				myBunch->OutputIndexParticle(*p7_output,7);
				myBunch->OutputIndexParticle(*p8_output,8);
				myBunch->OutputIndexParticle(*p9_output,9);
				myBunch->OutputIndexParticle(*p10_output,10);
			}
					
			myParticleTracker2->Track(myBunch);

			if( myBunch->size() <= 1 ) break;
		}
	}
    
////////////////////////////
// OUTPUT DUSTBIN LOSSES ///
////////////////////////////
	if(dust){
		ostringstream dustbin_file;
		//~ if(batch){		dustbin_file << (loss_dir+case_dir+"HELdustbin_losses.txt");		}
		dustbin_file << (loss_dir+"HELdustbin_losses.txt");	
		ofstream* dustbin_output = new ofstream(dustbin_file.str().c_str());
		if(!dustbin_output->good())    {
			std::cerr << "Could not open dustbin loss file" << std::endl;
			exit(EXIT_FAILURE);
		} 
		
		myDustbin->Finalise(); 
		myDustbin->Output(dustbin_output); 
	}									
//////////////////////////
// OUTPUT FINAL BUNCH ///
/////////////////////////
	if(output_final_bunch){
		ostringstream bunch_output_file2;
		bunch_output_file2 << bunch_dir << "final_bunch.txt";

		ofstream* bunch_output2 = new ofstream(bunch_output_file2.str().c_str());
		myBunch->Output(*bunch_output2);
		delete bunch_output2;
	 }
   
    cout << "npart: " << npart << endl;
    cout << "left: " << myBunch->size() << endl;
    cout << "absorbed: " << npart - myBunch->size() << endl;
    
    cout << setprecision(14) <<"Emittance = " << emittance << endl;
	cout << setprecision(14) <<"TCP beta_x = " << myTwiss->Value(1,1,1,tcp_element_number)*meter << endl;
	cout << setprecision(14) <<"IP1 beta_x = " << myTwiss->Value(1,1,1,(ip1_element_number))*meter << endl;
	cout << setprecision(14) <<"HEL beta_x = " << myTwiss->Value(1,1,1,hel_element_number)*meter << endl;

    delete myMaterialDatabase;
    delete myBunch;
    delete myTwiss;
    delete myAccModel;
    delete myMADinterface;
    delete p0_output;	
	delete p1_output;
	delete p2_output;
	delete p3_output;
	delete p4_output;
	delete p5_output;
	delete p6_output;
	delete p7_output;
	delete p8_output;
	delete p9_output;
	delete p10_output;

    return 0;
}

//================================================================
// Calculate integral flux energies from GOES flux measurements
// 
// written by Leslie Mayer
//================================================================
// This is to figure out how many columns wide the actual code is :
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//1     10         20        30        40        50        60        70        80


#define DIAGNOSTICS // turn on diagnostic writes to file

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>   // for formatting output
using namespace std;

#include "GoesDataClass.h"

// BEGIN CODE ========================================================================
// Functions
bool openInputFile(string inDIR, string inputFileName, ifstream & inputFile);
bool openOutputFile(string outDIR, string outputFileName, ofstream & outputFile);

int main (int argc, const char* argv[] ) 
{
  // ensure the correct number of parameters are used.
  if ( argc == 3 ) 
  {
     // Print each argument on the command line.
     for( int i = 0; i < argc; i++ )
     {
        printf( "arg %d: %s\n", i, argv[i] );
     }
  }
  else 
  {
     printf("Incorrect number of input parameters\n");
     printf("Syntax is :\n");
     printf("goes_int_flux 2001_09_26_GOES08 proxy\n");
     return 1;
  }


  // Strings for filenames & directories
  string inputDiffFluxFileName, integralFluxFileName, differentialFluxFileName;
  string correctionsFileName, flagFileName, gammaFileName;

  // Strings for directories
  string inDIR, outDIR;

  // Strings for making iput, output filenames
  string temp, datadate, type;

  bool hasMissingFlux = false;

  ifstream inputDiffFluxFile;
  ifstream correctionsFile;
  ofstream integralFluxFile;
  ofstream differentialFluxFile;
  ofstream outFLAG;

  // Define gamma output file in case we are in debug mode
  ofstream gammaFile;

  // Define diagnostic output file in case we are in debug or diagnostic mode
  ofstream diagnosticFile;

  //---------------------------------------------------
  // Set names of files
  //--------------------------------------------------
  datadate = argv[1];
  type = argv[2];

  inDIR = "../DATA/DIAGNOSTICS/INPUT/";
  cout << "inDIR = " << inDIR << endl;

  // Input differential flux file name
  inputDiffFluxFileName = datadate + "_" + type + "_flux.dat";
  cout << "inputDiffFluxFileName = " << inputDiffFluxFileName << endl;

  correctionsFileName = datadate + "_" + type + "_corrections.dat";
  cout << "correctionsFileName = " << correctionsFileName << endl;

  outDIR = "../DATA/DIAGNOSTICS/OUTPUT/";

  // print outDIR
  cout << "outDIR = " << outDIR << endl;

  // For Calculated Integral fluxes
  integralFluxFileName = datadate + "_" + type + "_L2_INT.dat";
  cout << "integralFluxFileName = " << integralFluxFileName << endl;

  // For Calculated Differential fluxes
  differentialFluxFileName = datadate + "_" + type + "_L2_DIFF.dat";
  cout << "differentialFluxFileName = " << differentialFluxFileName << endl;

  // For writing out flag values
  flagFileName =  datadate + "_" + type + "_L2_FLAG.dat";
  cout << "flagFileName = " << flagFileName << endl;

  // Open input files
  if ( !openInputFile(inDIR, inputDiffFluxFileName, inputDiffFluxFile) ) return 1;
  if ( !openInputFile(inDIR, correctionsFileName, correctionsFile) ) return 1;

  // Open output files
  if ( !openOutputFile(outDIR, integralFluxFileName, integralFluxFile) ) return 1;
  if ( !openOutputFile(outDIR, differentialFluxFileName, differentialFluxFile) ) return 1;
  if ( !openOutputFile(outDIR, flagFileName, outFLAG) ) return 1;

  #ifdef DEBUG 
     cout << endl;
     cout << "In DEBUG mode ......................." << endl;
     // For writing out final gamma values
     gammaFileName = datadate + "_" + type + "_GAMMA.dat";
     cout << "gammaFileName = " << gammaFileName << endl;
     if ( !openOutputFile(outDIR, gammaFileName, gammaFile) ) return 1;
  #endif


  #ifdef DIAGNOSTICS
     cout << endl;
     cout << "IN DIAGNOSTICS MODE ***************************************** : " << endl;
     string diagnosticFileName;
     diagnosticFileName =  datadate + "_" + type +"_diagnostic_out.dat";
     cout << "diagnosticFileName = " << diagnosticFileName << endl;
     if ( !openOutputFile(outDIR, diagnosticFileName, diagnosticFile) ) return 1;
  #endif

  // The differential flux data we are reading in
  // & using to calculate differential & integral fluxes
  GoesDataClass goes_data;

  // Read corrected flux values
  goes_data.readFlux(inputDiffFluxFile);

  // Read direction values
  goes_data.readDirection(inputDiffFluxFile);

  // Read corrections flux values
  goes_data.readCorrections(correctionsFile);

  // Keep going to end of file for either file
  while(!inputDiffFluxFile.fail() && !correctionsFile.fail())
  {

     #ifdef DIAGNOSTICS
       goes_data.printDateTime(diagnosticFile);
       diagnosticFile << "Inputs : " << endl;
       goes_data.printFlux(diagnosticFile);
       goes_data.printCorrections(diagnosticFile);
     #endif


     // Make sure the corrected & corrections dates are exactly the same
     if  ( goes_data.notSameDateTime()  )
     {
         return 1;
     }

     // Check for missing values
     hasMissingFlux = goes_data.hasMissingFlux();

     // If (no fluxes are missing) then calculate the integral flux
     if (!hasMissingFlux) {

        // Calculate differential & integral fluxes
        goes_data.calculateDifferentialandIntegralFlux 
                  (integralFluxFile, differentialFluxFile, gammaFile, outFLAG, diagnosticFile);

     } else {

        #ifdef DEBUG
           // Print to screen that the data is missing
           goes_data.printMissingFluxMessage();
        #endif

        // Write missing values out to file
        goes_data.writeMissingFlux(integralFluxFile, differentialFluxFile, gammaFile, outFLAG);

     }

     // Read corrected flux values
     goes_data.readFlux(inputDiffFluxFile);

     // Read direction values
     goes_data.readDirection(inputDiffFluxFile);

     // Read corrections flux values
     goes_data.readCorrections(correctionsFile);

     #ifdef DEBUG
       cout << "goes_int_flux : inputDiffFluxFile.fail() = " <<    inputDiffFluxFile.fail() ;
       cout << "   correctionsFile.fail() = " <<    correctionsFile.fail() << endl;
     #endif

     // Writing missing flag to flags file
     outFLAG << setw(1) << hasMissingFlux << endl;

  }

  // Close files
  inputDiffFluxFile.close();
  correctionsFile.close();
  integralFluxFile.close();
  differentialFluxFile.close();
  outFLAG.close();
  gammaFile.close();

  return 0;
} // main

// Open input file
bool openInputFile(string inDIR, string inputFileName, ifstream & inputFile)
{
   string temp;
   temp = inDIR + inputFileName;
   cout << "goes_int_flux : Opening " << temp << endl;
   inputFile.open(temp.c_str());   // have to convert string to char for open()
   if (inputFile == NULL)
   {
      cout << "goes_int_flux : Error in opening " << temp << " for reading" << endl;
      return false;
   }
   return(true);
}

// Open output file
bool openOutputFile(string outDIR, string outputFileName, ofstream & outputFile)
{
   string temp;
   temp = outDIR + outputFileName;
   cout << "goes_int_flux : Opening " << temp << endl;
   outputFile.open(temp.c_str());   // have to convert string to char for open()
   if (outputFile == NULL)
   {
      cout << "goes_int_flux : Error in opening " << temp << " for writing" << endl;
      return false;
   }
   return(true);
}


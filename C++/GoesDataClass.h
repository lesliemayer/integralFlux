//==============================================================================
// Name : GoesDataClass
// Function : Provides variables and functions for the GOESR SEISS 5 minute
//            proton flux data.
// Description :  This class has the flux variables and methods for 
//                printing and computing differential and integral fluxes.
//
// Reference :  GOES-R SEISS Integral Flux Algorithm Theoretical Basis Document,
//              GOES-R SEISS Differential-To-Integral Flux Algorithm Implementation
//              and User's Guide, STAR C Coding Standards.
//                
// Dependencies :  Includes standard C++ libraries fstream, iostream, string,
//                 iomanip, definitions.h, DirectionClass.h, GammaClass.h,
//                 EnergyClass.h, UncorrectedCountsClass.h, math.h, 
//                 iostream, and namespace std.
//                 
// Restrictions :
// History : see SVN summary
//==============================================================================
#ifndef GOES_DATA_CLASS_H
#define GOES_DATA_CLASS_H

//#define DEBUG  // for debugging prints
//#define DIAGNOSTICS // turn on diagnostic writes to file

#include <fstream>
#include <iostream>
#include <string>    
#include "DirectionClass.h"
#include "definitions.h"
                                                                                   
using namespace std;

class GoesDataClass
{

private:
   static const int GOES_SIZE = SET_GOES_SIZE ;  
   static const int INTEGRAL_SIZE = SET_INTEGRAL_SIZE ; 
   static const int OUT_FLUX_SIZE = SET_OUT_FLUX_SIZE ;

   // Missing data value to check for 
   static const double MISSING = SET_MISSING ;

   // Missing data for the output
   static const double OUTMISSING = -99999. ;

   string date, time;
   string CorrectionsDate, CorrectionsTime;
   double flux[GOES_SIZE];
   double Corrections[GOES_SIZE];

   DirectionClass directions;

   // Gamma indices for calculating differential GREATER_ENERGY values for variable flux out
   // Uses extrapolation method
   // (based on energy edges of the channels)
   static const int INDEX_DF [OUT_FLUX_SIZE];

   // Energy values for which we want to output differential fluxes
   static const double ENERGY_DIFF_FLUX_OUT [OUT_FLUX_SIZE];

   // Indices for which gamma to use for calulating integral flux energies
   static const int INDEX_GAMMA [INTEGRAL_SIZE];

   // Indices of geometric center energy > integral flux E (at what central energy to adding up areas)
   // These are the central Energies to use for area calculation, not for the gammas!
   // THESE STAY THE SAME WHETHER WE ARE INTERP OR EXTRAP FOR GAMMA ************************
   // THESE CAN CHANGE IF CENTRAL ENERGIES CHANGE ******************
   static const int INDEX_BEGIN_AREA [INTEGRAL_SIZE];

   // > energies we want to calculate integral flux for  (>1Mev, >5Mev,.....)
   static const double GREATER_ENERGY [INTEGRAL_SIZE];

public:
   GoesDataClass();
   ~GoesDataClass();
   void printDateTime(ofstream & outFile);
   void printFlux();
   void printFlux(ofstream & outFile);
   void printCorrections();
   void printCorrections(ofstream & outFile);
   void readFlux(ifstream & infile);
   void readDirection(ifstream & infile);
   void writeDirection(ofstream & outfile);
   void writeMissingDirection(ofstream & outfile);
   void readCorrections(ifstream & corrfile);
   bool notSameDateTime();
   bool hasMissingFlux();

   // Print to screen that the data is missing
   void printMissingFluxMessage();

   // Write missing values out to file
   void writeMissingFlux(ofstream & outfile, ofstream & outFluxFile, 
                         ofstream & outGAMMA, ofstream & outFLAG);

   // Calculate the integral flux from the goes differential flux
   void calculateDifferentialandIntegralFlux(ofstream & outfile, ofstream & outFluxFile, 
                                             ofstream & outGAMMA, ofstream & flagFILE, ofstream & debugFile);  

   // Write out to file
   void writeIntegralFlux(ofstream & outfile, double *int_flux);
   void writeDirections(ofstream & outfile);
   void writeDifferentialFlux(ofstream & outFluxFile, double *Jif);
   void writeGamma(ofstream & outGAMMA, double *gamma) ;

   // Write out missing data to a file
   void writeIntegralFlux(ofstream & outfile);
   void writeDifferentialFlux(ofstream & outFluxFile);
   void writeGamma(ofstream & outGAMMA);

   // Write flags for missing data out to a file
   void writeMissingFlags(ofstream & outFILE) ;

};


#endif

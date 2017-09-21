#include <math.h>
#include "GammaClass.h"
#include "EnergyClass.h"
#include "UncorrectedCountsClass.h"
#include "GoesDataClass.h"
using namespace std;

// Name : GoesDataClass
// Function : Constructor for the GoesDataClass.         
// Description : Does nothing.
// Calling Sequence :  Automatically called when an object of GoesDataClass
//                     is created.
// Inputs : None.
// Outputs : None.          
// Restrictions : None.
GoesDataClass::GoesDataClass()
{

}


// Name : ~GoesDataClass
// Function : Destructor for the GoesDataClass.         
// Description :  Release any resources allocated by the object.
// Calling Sequence :  Automatically called when an object of GoesDataClass 
//                     passes out of scope or is explicitly deleted.
// Inputs : None.
// Outputs : None.          
// Restrictions : None.
GoesDataClass::~GoesDataClass()
{

}

// Name : writeIntegralFlux
// Function : Write the date, time, integral flux values to a text file.
// Description :  Loop through integral flux array and write the
//                date, time, and formatted integral flux value to a text file.                
// Calling Sequence :  object.writeIntegralFlux(outFile, int_flux)
// Inputs : outfile
// Outputs : None.                 
// Restrictions :  ofstream outfile must already be open.
void GoesDataClass::writeIntegralFlux(ofstream & outfile, double *int_flux)
{
  outfile << date << " " <<  time << " " ;

  for(int j=0; j<INTEGRAL_SIZE-1; j++) 
  {
      outfile << fixed << setprecision(3) << setw(11) << int_flux[j] << "  ";
  }
  outfile << fixed << setprecision(3) << setw(11) << int_flux[INTEGRAL_SIZE-1] << " ";
}

// Name : writeDifferentialFlux
// Function : Write the date, time, calculated differential flux values to a text file.
// Description :  Loop through differential flux array and write the
//                date, time, and formatted differential flux value to a text file.                
// Calling Sequence :  object.writeDifferentialFlux(outFluxFile, Jif)
// Inputs : outFluxFile, Jif
// Outputs : None.                 
// Restrictions :  ofstream outFluxFile must already be open.
void GoesDataClass::writeDifferentialFlux(ofstream & outFluxFile, double *Jif)
{
  outFluxFile << date << " " <<  time << " " ;

  for(int j=0; j<OUT_FLUX_SIZE-1; j++) 
  {
      outFluxFile << fixed << setprecision(6) << setw(14) << Jif[j] << "  ";
  }
  outFluxFile << fixed << setprecision(6) << setw(14) << Jif[OUT_FLUX_SIZE-1] << endl;
}

// Name : writeGamma
// Function : Write the date, time, gamma values to a text file.
// Description :  Loop through gamma array and write the
//                date, time, and formatted gamma value to a text file.                
// Calling Sequence :  object.writeGamma(outGAMMA, gamma)
// Inputs : outGAMMA, gamma
// Outputs : None.                 
// Restrictions :  ofstream outGAMMA must already be open.
void GoesDataClass::writeGamma(ofstream & outGAMMA, double *gamma)
{
   outGAMMA << date << " " <<  time << " " ;

  for(int j=0; j<GOES_SIZE-2; j++) 
  {
      outGAMMA << fixed << setprecision(3) << setw(11) << gamma[j] << "  ";
  }
  outGAMMA << fixed << setprecision(3) << setw(11) << gamma[GOES_SIZE-2] << endl;
}

// Name : writeIntegralFlux
// Function : Write the date, time, missing integral flux values to a text file.
// Description :  Loop through missing values and write the
//                date, time, and missing value to a text file.                
// Calling Sequence :  object.writeIntegralFlux(outfile)
// Inputs : outfile
// Outputs : None.                 
// Restrictions :  ofstream outfile must already be open.
void GoesDataClass::writeIntegralFlux(ofstream & outfile)
{
  outfile << date << " " <<  time << " " ;

  for(int j=0; j<INTEGRAL_SIZE-1; j++) 
  {
      outfile << fixed << setprecision(3) << setw(11) << OUTMISSING << "  ";
  }
  outfile << fixed << setprecision(3) << setw(11) << OUTMISSING << " ";

}

// Name : writeDifferentialFlux
// Function : Write the date, time, missing differential flux values to a text file.
// Description :  Loop through missing values and write the
//                date, time, and missing value to a text file.                
// Calling Sequence :  object.writeDifferentialFlux(outFluxFile)
// Inputs : outFluxFile
// Outputs : None.                 
// Restrictions :  ofstream outFluxFile must already be open.
void GoesDataClass::writeDifferentialFlux(ofstream & outFluxFile)
{
  outFluxFile << date << " " <<  time << " " ;

  for(int j=0; j<OUT_FLUX_SIZE-1; j++) 
  {
      outFluxFile << fixed << setprecision(6) << setw(14) << OUTMISSING << "  ";
  }
  outFluxFile << fixed << setprecision(6) << setw(14) << OUTMISSING << endl;
}


// Name : writeGamma
// Function : Write the date, time, missing gamma values to a text file.
// Description :  Loop through missing values and write the
//                date, time, and missing value to a text file.                
// Calling Sequence :  object.writeGamma(outGAMMA)
// Inputs : outGAMMA
// Outputs : None.                 
// Restrictions :  ofstream outGAMMA must already be open.
void GoesDataClass::writeGamma(ofstream & outGAMMA) 
{
   outGAMMA << date << " " <<  time << " " ;

  for(int j=0; j<GOES_SIZE-2; j++) 
  {
      outGAMMA << fixed << setprecision(3) << setw(11) << OUTMISSING << "  ";
  }
  outGAMMA << fixed << setprecision(3) << setw(11) << OUTMISSING << endl;
}

// Name : writeMissingFlags
// Function : Write the date, time, missing flag values to a text file.
// Description :  Loop through missing values for convergence flags, 
//                gamma limit flags, and gamma default flags, and write the
//                date, time, and missing value to a text file.                
// Calling Sequence :  object.writeMissingFlags(outFILE)
// Inputs : outFILE
// Outputs : None.                 
// Restrictions :  ofstream outFILE must already be open.
void GoesDataClass::writeMissingFlags(ofstream & outFILE) 
{
   outFILE << date << " " <<  time << " " ;

  // Energy convergence flags
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFILE << setw(1) << false << " ";
  }
  outFILE << "   ";

  // Gamma Limit flags
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
      outFILE << setw(1) << false << " ";
  }
  outFILE << "   ";

  // Gamma default flags
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
      outFILE << setw(1) << false << " ";
  }
  outFILE << "  ";

}

// Name : printDateTime
// Function : Write the date, time values to a text file.
// Description : Write the date, time values to a text file.                
// Calling Sequence :  object.printDateTime(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void GoesDataClass::printDateTime(ofstream & outFile)
{
  outFile << endl;
  outFile << "GoesDataClass : date, time : " << endl;
  outFile << date << " " << time;
  outFile << endl << endl;

}

// Name : printFlux
// Function : Print the flux values to standard out.
// Description : Loop through flux values and print to standard out.                
// Calling Sequence :  object.printFlux()
// Inputs : None.
// Outputs : None.                 
// Restrictions :  None.
void GoesDataClass::printFlux()
{
  cout << endl;
  cout << "GoesDataClass : flux[]: " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      cout << flux[j] << " " ;
  }
  cout << endl << endl;

}


// Name : printFlux
// Function : Print the flux values to a text file.
// Description : Loop through flux values and write formatted flux to
//               a text file.                
// Calling Sequence :  object.printFlux(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void GoesDataClass::printFlux(ofstream & outFile)
{
  outFile << endl;
  outFile << "GoesDataClass : flux[]: " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << fixed << setprecision(7) << setw(15) << flux[j] << "  ";
  }
  outFile << endl << endl;

}


// Name : printCorrections
// Function : Print the Corrections values to standard out.
// Description : Loop through Corrections values and print to standard out.                
// Calling Sequence :  object.printCorrections()
// Inputs : None.
// Outputs : None.                 
// Restrictions :  None.
void GoesDataClass::printCorrections()
{
  cout << "GoesDataClass : Corrections[]: " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      cout << Corrections[j] << " " ;
  }
  cout << endl << endl;

}


// Name : printCorrections
// Function : Print the Corrections values to a text file.
// Description : Loop through Corrections values and print to a text file.                
// Calling Sequence :  object.printCorrections(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void GoesDataClass::printCorrections(ofstream & outFile)
{
  outFile << "GoesDataClass : Corrections[]: " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << Corrections[j] << " " ;
  }
  outFile << endl << endl;

}

// Name : readFlux
// Function : Read the date, time, and flux values from a text file.
// Description : Read date, time, then, loop through flux values and 
//               read from a text file.                
// Calling Sequence :  object.readFlux(flux_infile)
// Inputs : flux_infile
// Outputs : None.                 
// Restrictions :  ifstream flux_infile must already be open.
void GoesDataClass::readFlux(ifstream & flux_infile)
{
  flux_infile >> date >> time;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      flux_infile >> flux[j];
  } 
}


// Name : readDirection
// Function : Read the direction object from a text file.
// Description : Calls the DirectionClass method readDirection to
//               read the direction vector into the DirectionClass object.         
// Calling Sequence :  object.readDirection(infile)
// Inputs : infile
// Outputs : None.                 
// Restrictions :  ifstream infile must already be open.
void GoesDataClass::readDirection(ifstream & infile)
{
   directions.readDirection(infile);
}

// Name : writeDirection
// Function : Write the direction object to a text file.
// Description : Calls the DirectionClass method writeDirection to
//               write the direction vector to a text file.         
// Calling Sequence :  object.writeDirection(outfile)
// Inputs : outfile
// Outputs : None.                 
// Restrictions :  ofstream outfile must already be open.
void GoesDataClass::writeDirection(ofstream & outfile)
{
   directions.writeDirection(outfile);
}

// Name : writeMissingDirection
// Function : Write the direction object missing value to a text file.
// Description : Calls the DirectionClass method writeMissingDirection to
//               write the missing direction vector to a text file.         
// Calling Sequence :  object.writeMissingDirection(outfile)
// Inputs : outfile
// Outputs : None.                 
// Restrictions :  ofstream outfile must already be open.
void GoesDataClass::writeMissingDirection(ofstream & outfile)
{
   directions.writeMissingDirection(outfile);
}

// Name : readCorrections
// Function : Read the Corrections values from a text file.
// Description : Read date, time, then
//               Loop through Corrections values and read from a text file.                
// Calling Sequence :  object.readCorrections(corrfile)
// Inputs : corrfile
// Outputs : None.                 
// Restrictions :  ifstream corrfile must already be open.
void GoesDataClass::readCorrections(ifstream & corrfile)
{
  corrfile >> CorrectionsDate >> CorrectionsTime;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      corrfile >> Corrections[j] ;
  }
}


// Name : notSameDateTime
// Function : Compare date & times of corrected fluxes vs Corrections fluxes.
// Description :  Make sure corrected & Corrections dates are exactly the same
//                to make sure they exactly match up in time.
//                The strcmp function returns 0 (false) if strings are equal.        
// Calling Sequence :  object.notSameDateTime()
// Inputs : None.
// Outputs : boolean value notSame           
// Restrictions :  This is comparing the string values of date and time.
bool GoesDataClass::notSameDateTime()
{
   bool notSame;
   notSame = strcmp(date.c_str(), CorrectionsDate.c_str()) + 
             strcmp(time.c_str(), CorrectionsTime.c_str());

   if (notSame) 
   { 
       cout << "notSameDateTime: date & time strings do not match : " << endl;
       cout << date << " " << time << " " << CorrectionsDate << " " << CorrectionsTime << endl;
   }
   return notSame;
}


// Name : hasMissingFlux
// Function : Check for any missing flux values.
// Description : Initialize isMissing to false,  then loop through
//               flux and if any are missing, set isMissing to true.      
// Calling Sequence :  object.hasMissingFlux()
// Inputs : None.
// Outputs : boolean value isMissing           
// Restrictions : None.
bool GoesDataClass::hasMissingFlux()
{
   // Initialize isMissing to false
   bool isMissing = 0; 

   for (int i=0; i<GOES_SIZE; i++) 
   {
        if (flux[i] <= MISSING)  isMissing = 1;
   }
    return(isMissing);
}


// Name : printMissingFluxMessage
// Function : Print a message that the flux has missing values.
// Description : Print message, date, time, and all flux values to standard out.     
// Calling Sequence :  object.printMissingFluxMessage()
// Inputs : None.
// Outputs : None.         
// Restrictions : None.
void GoesDataClass::printMissingFluxMessage()
{
       cout << "A VALUE IS MISSING ............" << endl;
       cout << "date: " << date ;
       cout << " time: " << time << endl;
       cout << "goes flux: " ;

       for (int j=0; j<GOES_SIZE; j++) 
       {
            cout << flux[j] << "  ";
       }
       cout << endl;
}


// Name : writeMissingFlux
// Function : Write the missing values out to file.
// Description : Write missing values for gamma, integral flux, direction,
//               differential flux, and flags out to the appropriate text files.
// Calling Sequence :  object.writeMissingFlux()
// Inputs : outfile, outFluxFile, outGAMMA, outFLAG
// Outputs : None.         
// Restrictions : All input files must already be open.
void GoesDataClass::writeMissingFlux(ofstream & outfile, ofstream & outFluxFile, 
                                     ofstream & outGAMMA, ofstream & outFLAG)
{
  // Write the gammas out to a file
  writeGamma(outGAMMA);

  // Write out the missing integral fluxes
  writeIntegralFlux(outfile);

  // Write out missing direction vector
  writeMissingDirection(outfile);

  // Write out the missing differental fluxes
  writeDifferentialFlux(outFluxFile);

  // Write out flags to flag file
  writeMissingFlags(outFLAG);

}


// Name : calculateDifferentialandIntegralFlux
// Function : Calculate differential and integral fluxes.
// Description : Does all the calculations for the final differential and
//               integral flux values, and writes out the results to text
//               files.   The calculations involve 1) getting the counts,
//               2) calculating the standard deviation of the counts, 3)
//               determining if these are background values, 4) appropriately
//               determining the gamma values, 5) iterating to determine the
//               center energies, 6) resetting the gamma values for the new
//               center energies, 7) calculating all the individual areas under
//               the differential flux curve using the appropriate gammas, 8)
//               calculating specific differential fluxes, 9) adding up the
//               appropriate areas to get the specific integral fluxes, 10)
//               writing the results out to files.
// Calling Sequence :  object.calculateDifferentialandIntegralFlux(outfile, 
//                     outFluxFile, outGAMMA, outFLAG, diagnosticFile)
// Inputs : outfile, outFluxFile, outGAMMA, outFLAG
// Outputs : None.         
// Restrictions : All input files must already be open.
void GoesDataClass::calculateDifferentialandIntegralFlux
                                    (ofstream & outfile, ofstream & outFluxFile, 
                                     ofstream & outGAMMA, ofstream & outFLAG, 
                                     ofstream & diagnosticFile)
{

  // J0 of the gamma section we are looking at
  double j0 [GOES_SIZE - 1] = {0.};

  // Area between each geometric energy (hence GOES_SIZE - 1)
  double area [GOES_SIZE - 1] = {0.};

  // Calculated Differential flux
  double Jif [OUT_FLUX_SIZE - 1] = {0.};

  // These are the little areas starting at wanted integral flux energies
  // to the beginning of the next geometic energy (that's why its size 
  // INTEGRAL_SIZE, 
  // not INTEGRAL_SIZE-1
  double area_if [INTEGRAL_SIZE] = {0.};

  // Sum of integral flux areas between two geometric energies (area)
  // is size SIZE - 1 b/c is the areas b/t the geometric energies 
  // which are size SIZE
  double total_area [GOES_SIZE - 1] = {0.};

  // Wanted values of integral fluxes for output to file
  double int_flux [INTEGRAL_SIZE] = {0.};


  //Declare GammaClass object
  GammaClass gamma_c(date, time);


  //Declare EnergyClass object
  EnergyClass energy_c;

  #ifdef DIAGNOSTICS
    diagnosticFile << "Initialization : " << endl << endl;
    energy_c.printEnergy(diagnosticFile);
    gamma_c.printIsBackground(diagnosticFile);
    gamma_c.printHasGammaLimit(diagnosticFile);
    energy_c.printIsNotConverged(diagnosticFile);
  #endif

  // Declare uc_counts as an UncorrectedCountsClass object
  UncorrectedCountsClass uc_counts;

  // Get uncorrected & corrected counts
  uc_counts.calculateCounts(flux, Corrections);

  // Print counts
  #ifdef DIAGNOSTICS
    cout << "WRITING TO DIAGNOSTICS FILE ................................." << endl;
    diagnosticFile << "Outputs : " << endl << endl ;
    uc_counts.printUncorrectedCounts(diagnosticFile);
    uc_counts.printCorrectedCounts(diagnosticFile);
  #endif

  // Calculate new standard deviations
  uc_counts.calculateStandardDeviation();

  // Print 
  #ifdef DIAGNOSTICS
    uc_counts.printAvgUncorrectedCounts(diagnosticFile);
    uc_counts.printStandardDeviation(diagnosticFile);
    uc_counts.printCorrectedCountsDelta(diagnosticFile);
  #endif


  // Determine if we need to use the default gamma
  uc_counts.useDefault(gamma_c.isBackground);

  gamma_c.setGamma(energy_c.energy, flux);

  // Check whether gamma is within bounds, or whether we need to set it to the default value
  gamma_c.checkGammaValues();

  #ifdef DEBUG
    cout << "BEFORE ITERATING ON ENERGY : " << endl;
    gamma_c.printGamma();
  #endif

  #ifdef DIAGNOSTICS
    gamma_c.printGamma(diagnosticFile);
  #endif


  // Energy class for doing the iteration
  EnergyClass energy_iter;

  #ifdef DEBUG
    energy_iter.printEnergy();
  #endif

  // Iterate until all energies converge,  or have iterated MAX_ITERATIONS times
  int Eiter = 0;
  while ( Eiter < energy_iter.MAX_ITERATIONS && !energy_iter.isDoneIterating() ) 
  {

     #ifdef DIAGNOSTICS
       diagnosticFile << endl << "Iteration " << Eiter + 1 << " : " << endl;
     #endif

     // Get a new set of energies using gamma_c
     energy_iter.computeNewEnergy(gamma_c.gamma); 

     #ifdef DEBUG
       // Print the new energies
       energy_iter.printNewEnergy();  
     #endif

     // See which energies converged
     energy_iter.setFinalEnergyIfConverged();  

     #ifdef DEBUG
       // print final e's
       energy_iter.printFinalEnergy(); 
     #endif

     // Reset gamma w/ the new energies
     gamma_c.setGamma(energy_iter.newEnergy, flux);

     // Either reset gamma to default, and check for min max
     gamma_c.checkGammaValues();

     #ifdef DEBUG
       gamma_c.printGamma();
     #endif

     #ifdef DIAGNOSTICS
       energy_iter.printNewEnergy(diagnosticFile);
       gamma_c.printGamma(diagnosticFile);
       energy_iter.printAbsDiff(diagnosticFile);
       energy_iter.printConvergence(diagnosticFile);
       energy_iter.printIsNotConverged(diagnosticFile);
     #endif

     Eiter++;
  }

  // Energies that didn't converge 
  // get set back to the geometric mean
  // after the maximum number of iterations
  energy_iter.setUnconvergedEnergy();

  // Reset gamma with the final energies
  gamma_c.setGamma(energy_iter.finalEnergy, flux);

  // Either reset gamma to default, and check for min max
  gamma_c.checkGammaValues();


// Get the areas
 for (int n=0; n<GOES_SIZE - 1; n++)  
 {
       // Set 1 - gamma values
       gamma_c.setOneMinusGamma();

       j0[n] = flux[n]*exp(gamma_c.gamma[n]*log(energy_iter.finalEnergy[n])) ;

       area[n] = ( exp( gamma_c.oneMinusGamma[n]*log(energy_iter.finalEnergy[n+1]) ) - 
                   exp( gamma_c.oneMinusGamma[n]*log(energy_iter.finalEnergy[n]) ) );

       area[n] = ( j0[n]/gamma_c.oneMinusGamma[n] )*area[n];
  }

  // Get j at energies that we want to output
  for (int n=0; n<OUT_FLUX_SIZE; n++)  
  {
     Jif[n] = j0[INDEX_DF[n]] *
              exp(-1.*( gamma_c.gamma[INDEX_DF[n]]*log( ENERGY_DIFF_FLUX_OUT[n] ) ) );
  }

  // Get areas at integral fluxes energies to the next geometric energy
  for (int n=0; n<INTEGRAL_SIZE; n++)  
  {
      area_if[n] = ( exp( (gamma_c.oneMinusGamma[INDEX_GAMMA[n]])*log(energy_iter.finalEnergy[INDEX_BEGIN_AREA[n]]) ) 
                      - exp( (gamma_c.oneMinusGamma[INDEX_GAMMA[n]])*log(GREATER_ENERGY[n]) ) );

      area_if[n] = ( j0[INDEX_GAMMA[n]]/(gamma_c.oneMinusGamma[INDEX_GAMMA[n]]) )*area_if[n];

      #ifdef DEBUG
         cout << "CalcDiffIntFlux : 1. - gamma_c.gamma[INDEX_GAMMA[n] = " << 
                  1. - gamma_c.gamma[INDEX_GAMMA[n]] << endl;
         cout << "CalcDiffIntFlux : gamma_c.oneMinusGamma[INDEX_GAMMA[n]] = " << 
                  gamma_c.oneMinusGamma[INDEX_GAMMA[n]] << endl;
      #endif
  }


  // Add up areas
  // Define last gamma defined area total 
  // Set last total_area to last area 
  total_area[GOES_SIZE-2] = area[GOES_SIZE-2];

  //Add up gamma defined areas 1st (the areas between each set of geometric energies)
  for (int n=GOES_SIZE-3; n>-1; n--)  
  {
     total_area[n] = total_area[n+1] + area[n];
  }


  // Use INDEX_BEGIN_AREA to get integral flux area.
  // Get the total integral flux by adding total areas between each geometric energy
  // to the sliver of area between the >E energy and the 1st geometric energy
  for (int n=0; n<INTEGRAL_SIZE; n++)  
  {
     int_flux[n] = total_area[INDEX_BEGIN_AREA[n]] + area_if[n];
  }


  //cout << "FINAL ENERGIES :  " << endl;
  #ifdef DIAGNOSTICS
    diagnosticFile << endl << "Final Results: " << endl;
    energy_iter.printFinalEnergy(diagnosticFile);  
    gamma_c.printIsBackground(diagnosticFile);
    gamma_c.printHasGammaLimit(diagnosticFile);
    gamma_c.printGamma(diagnosticFile);
    gamma_c.printOneMinusGamma(diagnosticFile);
  #endif


   // Write integral flux out to a file
   writeIntegralFlux(outfile, int_flux);  

   writeDirection(outfile);


   // Write calculated differential flux out to a file
   writeDifferentialFlux(outFluxFile, Jif); 

   #ifdef DEBUG
     // Write gammas out to a file
     writeGamma(outGAMMA, gamma_c.gamma);
   #endif

   // Write flags out to a file
   // Write out convergence flag values
   energy_iter.writeIsNotConverged(date, time, outFLAG);
   gamma_c.writeHasGammaLimit(outFLAG);
   gamma_c.writeIsBackground(outFLAG);

}


// Set arrays of constants

//-------------------------------------------------------------------------------------
// gamma indices for calculating differential flux values for variable ENERGY_DIFF_FLUX_OUT
//  Use extrapolation instead of interpolation
//  (based on energy edges of the channels)
//-------------------------------------------------------------------------------------
const int GoesDataClass::INDEX_DF [OUT_FLUX_SIZE] = SET_INDEX_DF ;


// > energies we want to calculate  flux for  (5Mev, 15Mev,.....)
const double GoesDataClass::ENERGY_DIFF_FLUX_OUT [OUT_FLUX_SIZE] =  SET_ENERGY_DIFF_FLUX_OUT ;


// Indices for which gamma to use for integral flux energies
// 1  5 10 30 50 60 100
// Using extrapolation instead of interpolation
//  (based on energy edges of the channels)
const int GoesDataClass::INDEX_GAMMA [INTEGRAL_SIZE] =  SET_INDEX_GAMMA ;


//-----------------------------------------------------------------------------------------
// Index of geometric center energy > integral flux E (at what central energy to
// start adding up areas)
// These are the central Energies to use for area calculation, not for the gammas!
//-----------------------------------------------------------------------------------------
const int GoesDataClass::INDEX_BEGIN_AREA [INTEGRAL_SIZE] = SET_INDEX_BEGIN_AREA ;


// > Energies we want to calculate integral flux for  (>1Mev, >5Mev,.....)
const double GoesDataClass::GREATER_ENERGY [INTEGRAL_SIZE] = SET_GREATER_ENERGY  ;


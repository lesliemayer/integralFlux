//==============================================================================
// Name : UncorrectedCountsClass
// Function : Provides variables and functions for the GOESR SEISS 5 minute
//            uncorrected and corrrected proton counts for the differential flux data.
// Description :  This class has the variables and methods for 
//                printing and computing counts and the standard deviation.
//
// Reference :  GOES-R SEISS Integral Flux Algorithm Theoretical Basis Document,
//              GOES-R SEISS Differential-To-Integral Flux Algorithm Implementation
//              and User's Guide, STAR C Coding Standards.
//                
// Dependencies :  Includes standard C++ libraries fstream, iostream,
//                 iomanip, definitions.h, math.h, and namespace std.
//                 
// Restrictions :
// History : see SVN summary
//==============================================================================

#ifndef UNCOUNTS_H
#define UNCOUNTS_H

//#define DEBUG

#include <iostream>
#include <fstream>   // for writing out to a file (ofstream)
#include <iomanip>   // for formatting output

#include <math.h>
#include "definitions.h"
using namespace std;

class UncorrectedCountsClass 
{
public:
   UncorrectedCountsClass();
   ~UncorrectedCountsClass();
   void calculateCounts(double *flux, double *corrections);
   void printUncorrectedCounts();
   void printUncorrectedCounts(ofstream & File);
   void printCorrectedCounts();
   void printCorrectedCounts(ofstream & File);
   void printAvgUncorrectedCounts(ofstream & File);
   void printStandardDeviation();
   void printStandardDeviation(ofstream & File);
   void printCorrectedCountsDelta(ofstream & outFile);
   void calculateStandardDeviation();

   void useDefault(bool *gamma_default);
   void useTestDefault(bool *gamma_default);

private:
   // Size of instrument channels
   static const int GOES_SIZE = SET_GOES_SIZE ;

   // Uncorrected counts
   double uncorrectedCounts[GOES_SIZE]; 

   // Corrected counts
   double correctedCounts[GOES_SIZE];  

   // Delta time,  in seconds (for 5 minute interval)
   static const double DELTA_TIME = 300.; 

   // Number of seconds in a day
   static const double SECONDS_IN_DAY = 14400.;

   // SECONDS_IN_DAY/DELTA_TIME = # of points to use for standand deviation
   static const double NUMBER_OF_POINTS; 

   // Previous average of uncorrected counts
   static double previousAvgUncorrectedCounts[GOES_SIZE]; 

   // Average of uncorrected counts
   static double AvgUncorrectedCounts[GOES_SIZE]; 

   // Standard deviation of uncorrected counts for the last time period
   static double standardDeviation[GOES_SIZE]; 

   // Constant standard deviations used to test vs Juan's algorithm
   static const double testcaseStandardDeviation[GOES_SIZE];

   // Geometric factor of the SEISS instrument
   static const double geometricFactor[GOES_SIZE];
   static const double upperLimit[GOES_SIZE];

};


#endif

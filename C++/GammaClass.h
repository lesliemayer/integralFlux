//==============================================================================
// Name : GammaClass
// Function : Provides variables and functions for the GOESR SEISS gamma values.
// Description :  This class has the gamma variables and methods for 
//                printing and computing gamma variables.
//
// Reference :  GOES-R SEISS Integral Flux Algorithm Theoretical Basis Document,
//              GOES-R SEISS Differential-To-Integral Flux Algorithm Implementation
//              and User's Guide, STAR C Coding Standards.
//                
// Dependencies :  Includes standard C++ libraries fstream, iomanip, definitions.h,
//                 iostream, cmath, and namespace std.
//                 
// Restrictions :
// History : see SVN summary
//==============================================================================

// class defining the gamma value for GOES proton data
#ifndef GAMMA_CLASS_H
#define GAMMA_CLASS_H

#include <fstream>
#include <iomanip>   // for formatting output
#include "definitions.h"
using namespace std;

class GammaClass
{

private:
   // Size of gamma array
   // This is from the definitions.h file 
   static const int GOES_SIZE = SET_GOES_SIZE ;  

   // Maximum, mininum values allowed for gamma
   static const double MAX_GAMMA = 8.;
   static const double MIN_GAMMA = -8.;

   // Default gammas
   static const double DEFAULT_GAMMA[GOES_SIZE - 1];
   string date;
   string time;
   bool hasGammaLimit[GOES_SIZE-1];

public:
   double gamma[GOES_SIZE-1];
   bool isBackground[GOES_SIZE-1];
   double oneMinusGamma[GOES_SIZE-1];

   GammaClass();
   GammaClass(string & _date, string & _time);
   ~GammaClass();

   void setGamma(const double *energy, double *flux);
   void printGamma();
   void printGamma(ofstream & outFile);
   void printOneMinusGamma(ofstream & outFile);
   void printDefaultGamma();
   void printIsBackground();
   void printIsBackground(ofstream & outFile);
   void printHasGammaLimit(ofstream & outFile);

   void checkGammaValues();
   void setOneMinusGamma();
   void writeGamma(ofstream & outGAMMA);
   void writeGamma(string & date, string & time, ofstream & outGAMMA);
   void writeHasGammaLimit(ofstream & outFLAGS);
   void writeIsBackground(ofstream & outFLAGS);

}; 


#endif

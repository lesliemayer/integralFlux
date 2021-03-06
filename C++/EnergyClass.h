//==============================================================================
// Name : EnergyClass
// Function : Provides variables and functions for the GOESR SEISS energies.
// Description :  This class has the energy variables and methods for 
//                printing and computing energy variables.
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

#ifndef ENERGY_CLASS_H
#define ENERGY_CLASS_H

#include <fstream>
#include <iomanip>   // for formatting output
#include "definitions.h"
using namespace std;

class EnergyClass
{

private:
   // Size of energy array
   static const int GOES_SIZE = SET_GOES_SIZE ;

   // # for checking energy convergence
   static const double CONVERGENCE_STANDARD = 0.01;
   static const double lowerEnergy[GOES_SIZE];
   static const double upperEnergy[GOES_SIZE];
   double previousEnergy[GOES_SIZE];

   // Flag for center energy convergence
   bool isNotConverged[GOES_SIZE];

   // calculate center energy
   double calculateCenterEnergy(double gamma, int j); 

public:
   // Maximum # of iterations on center energy allowed
   static const int MAX_ITERATIONS = 10; 


   EnergyClass();
   ~EnergyClass();
   double energy[GOES_SIZE];
   double newEnergy[GOES_SIZE];
   double finalEnergy[GOES_SIZE];

   void printEnergy();
   void printEnergy(ofstream & outFile);
   void printNewEnergy(ofstream & outFile);
   void printIsNotConverged(ofstream & outFile);
   void printAbsDiff(ofstream & outFile);
   void printConvergence(ofstream & outFile);
   void printFinalEnergy();
   void printFinalEnergy(ofstream & outFile);
   void printNewEnergy();
   void computeNewEnergy(double *gamma);
   void setFinalEnergyIfConverged();
   bool isDoneIterating();
   void setUnconvergedEnergy();
   void writeIsNotConverged(string & _date, string & _time, ofstream & outFLAGS);

};  


#endif

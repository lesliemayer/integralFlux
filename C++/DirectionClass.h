//==============================================================================
// Name : DirectionsClass
// Function : Provides variables and functions for the GOESR satellite directions.
// Description :  This class has the direction variables and methods for 
//                reading, printing, and writing the direction variables.
//
// Reference :  GOES-R SEISS Integral Flux Algorithm Theoretical Basis Document,
//              GOES-R SEISS Differential-To-Integral Flux Algorithm Implementation
//              and User's Guide, STAR C Coding Standards.
//                
// Dependencies :  Includes standard C++ libraries fstream, iomanip, iostream,
//                 math.h, cmath, and namespace std.
//                 
// Restrictions :
// History : see SVN summary
//==============================================================================

#ifndef DIRECTIONS_CLASS_H
#define DIRECTIONS_CLASS_H

#include <fstream>
#include <iomanip>   // for formatting output
using namespace std;

class DirectionClass
{

private:
   // Size of directions
   static const int SIZE = 3; 

   // Missing data for the output
   static const double OUTMISSING = -999.9 ;

   // Direction array
   double direction[SIZE];


public:

   DirectionClass();
   ~DirectionClass();

   void readDirection(ifstream & infile);
   void printDirection();
   void printDirection(ofstream & outFile);
   void writeDirection(ofstream & outfile);
   void writeMissingDirection(ofstream & outfile);
};  


#endif

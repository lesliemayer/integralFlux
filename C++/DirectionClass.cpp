#include <iostream>
#include <math.h>
#include <cmath>
#include "DirectionClass.h"
using namespace std;


// Name : DirectionClass
// Function : Constructor for the DirectionClass.         
// Description :  Initializes all directions to 0.
// Calling Sequence :  Automatically called when an object of DirectionClass 
//                     is created.
// Inputs : None.
// Outputs : None.          
// Restrictions : None.
DirectionClass::DirectionClass()
{
 for(int j=0; j<SIZE; j++) 
 {
    // Intitialize with 0's
    direction[j] = 0.0;
 }
}


// Name : ~DirectionClass
// Function : Destructor for the DirectionClass.         
// Description :  release any resources allocated by the object.
// Calling Sequence :  Automatically called when an object of DirectionClass 
//                     passes out of scope or is explicitly deleted.
// Inputs : None.
// Outputs : None.          
// Restrictions : None.
DirectionClass::~DirectionClass()
{

}

// Name : readDirection
// Function : Reads the satellite directions from a text file.     
// Description :  Loop through direction array and read in the
//                value from the infile.                
// Calling Sequence :  object.readDirection(infile)
// Inputs : ifstream & infile
// Outputs : None.                 
// Restrictions :  ifstream infile must already be opened.
void DirectionClass::readDirection(ifstream & infile)
{
  for(int j=0; j<SIZE; j++) 
  {
      infile >> direction[j];
  } 

} 


// Name : printDirection
// Function : Print the direction values to standard out.
// Description :  Loop through direction array and print the
//                value.                
// Calling Sequence :  object.printDirection()
// Inputs : None.
// Outputs : None.                 
// Restrictions : None.
void DirectionClass::printDirection()
{
  cout << "printDirection = " ;
  for(int j=0; j<SIZE; j++) 
  {
         cout << direction[j] << " " ;
  }
  cout << endl << endl;

} 


// Name : printDirection
// Function : Print the direction values to a text file.
// Description :  Loop through direction array and print the
//                formatted value to file outFile.              
// Calling Sequence :  object.printDirection(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions : ofstream outFile must already be open.
void DirectionClass::printDirection(ofstream & outFile)
{
  outFile << "DirectionClass : Direction[]: " ;
  for(int j=0; j<SIZE; j++) 
  {
      outFile << fixed << setprecision(2) << setw(8) << direction[j] << " " ;
  }
  outFile << endl << endl;

} 


// Name : writeDirection
// Function : Print the direction values to a text file.
// Description :  Loop through direction array and print the
//                formatted value to file outFile.              
// Calling Sequence :  object.writeDirection(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions : ofstream outFile must already be open.
void DirectionClass::writeDirection(ofstream & outfile)
{
  for(int j=0; j<SIZE; j++) 
  {
      outfile << fixed << setprecision(2) << setw(8) << direction[j] << " ";
  } 
  outfile << endl;
} 

// Name : writeMissingDirection
// Function : Write the missing direction values to a text file.
// Description :  Loop through direction array and print the
//                formatted value to file outFile.              
// Calling Sequence :  object.writeMissingDirection(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions : ofstream outFile must already be open.
void DirectionClass::writeMissingDirection(ofstream & outfile)
{
  for(int j=0; j<SIZE; j++) 
  {
      outfile << fixed << setprecision(2) << setw(8) << OUTMISSING << " ";
  } 
  outfile << endl;
} 


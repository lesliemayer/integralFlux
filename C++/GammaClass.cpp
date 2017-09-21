#include <iostream>
#include <cmath>

#include "GammaClass.h"
using namespace std;

// Name : GammaClass
// Function : Constructor for the GammaClass.         
// Description :  Initializes member variables date, time, gamma, oneMinusGamma, 
//                isBackground, hasGammaLimit.
// Calling Sequence :  Automatically called when an object of GammaClass 
//                     is created.
// Inputs : None.
// Outputs : None.          
// Restrictions : None.
GammaClass::GammaClass()
{
  // Initialize date & time
  date = " ";
  time = " ";

  // Initialize variables
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
      gamma[j]= 0.;
      oneMinusGamma[j]= 0.;
      isBackground[j] = 0 ;
      hasGammaLimit[j] = false;
  }

}


// Name : GammaClass
// Function : Constructor for the GammaClass.         
// Description :  Initializes member variables date, time, gamma, oneMinusGamma, 
//                isBackground, hasGammaLimit.
// Calling Sequence :  Automatically called when an object of GammaClass 
//                     is created.
// Inputs : date, time
// Outputs : None.          
// Restrictions : None.
GammaClass::GammaClass(string& _date, string& _time)
{
  date = _date;
  time = _time;
  // Initialize variables
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
     gamma[j]= 0.;
     oneMinusGamma[j]= 0.;
     isBackground[j] = 0 ;
     hasGammaLimit[j] = false;
  }
}


// Name : ~GammaClass
// Function : Destructor for the GammaClass.         
// Description : Release any resources allocated by the object.
// Calling Sequence :  Automatically called when an object of GammaClass 
//                     passes out of scope or is explicitly deleted.
// Inputs : None.
// Outputs : None.          
// Restrictions : None.
GammaClass::~GammaClass()
{

}

// Name : printGamma
// Function : Print the gamma values to standard out.
// Description :  Loop through gamma array and print the
//                value to standard out.                
// Calling Sequence :  object.printGamma()
// Inputs : None.
// Outputs : None.                 
// Restrictions :  None.
void GammaClass::printGamma()
{
  cout << "printGamma = " ;
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
      cout << gamma[j] << " " ;
  }
  cout << endl << endl;
}

// Name : printGamma
// Function : Print the gamma values to outFile.
// Description :  Loop through gamma array and print the
//                value to a text file.                
// Calling Sequence :  object.printGamma(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void GammaClass::printGamma(ofstream & outFile)
{
  outFile << "GammaClass : gamma[]: " ;
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
      outFile << fixed << setprecision(6) << setw(11) << gamma[j] << "  ";
  }
  outFile << endl ;
}


// Name : printOneMinusGamma
// Function : Print the oneMinusGamma values to outFile.
// Description :  Loop through oneMinusGamma array and write the
//                value to a text file.                
// Calling Sequence :  object.printOneMinusGamma(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void GammaClass::printOneMinusGamma(ofstream & outFile)
{
  outFile << "GammaClass : oneMinusGamma[]: " ;
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
      outFile << fixed << setprecision(6) << setw(11) << oneMinusGamma[j] << "  ";
  }
  outFile << endl ;
}


// Name : printDefaultGamma
// Function : Print the default gamma values.
// Description :  Loop through default gamma array and print the
//                value to standard out.                
// Calling Sequence :  object.printDefaultGamma()
// Inputs : None.
// Outputs : None.                 
// Restrictions :  None.
void GammaClass::printDefaultGamma()
{
  cout << "printDefaultGamma = " ;
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
         cout << DEFAULT_GAMMA[j] << " " ;
  }
  cout << endl << endl;
}

// Name : printIsBackground
// Function : Print the isBackground values.
// Description :  Loop through isBackground array and print the
//                value to standard out.                
// Calling Sequence :  object.printIsBackground()
// Inputs : None.
// Outputs : None.                 
// Restrictions :  None.
void GammaClass::printIsBackground()
{
  cout << "printIsBackground = " ;
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
         cout << isBackground[j] << " " ;
  }
  cout << endl << endl;
} 


// Name : printIsBackground
// Function : Print the isBackground values to outFile.
// Description :  Loop through isBackground array and write the
//                value to a text file.                
// Calling Sequence :  object.printIsBackground(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void GammaClass::printIsBackground(ofstream & outFile)
{
  outFile << "GammaClass : isBackground[]: " ;
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
         outFile << isBackground[j] << " " ;
  }
  outFile << endl << endl;
}


// Name : printHasGammaLimit
// Function : Print the hasGammaLimit values to a text file.
// Description :  Loop through isBackground array and write the
//                value to a text file.                
// Calling Sequence :  object.printHasGammaLimit(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void GammaClass::printHasGammaLimit(ofstream & outFile)
{
  outFile << "GammaClass : hasGammaLimit[]: " ;
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
         outFile << hasGammaLimit[j] << " " ;
  }
  outFile << endl << endl;
}


// Name : setGamma
// Function : Set the gamma values.
// Description :  Loop through neighboring flux values and set the gamma values.
// Calling Sequence :  object.setGamma(energy, flux)
// Inputs : energy, flux
// Outputs : None.                 
// Restrictions :  None of fluxes or energies should equal 0.
void GammaClass::setGamma(const double *energy, double *flux)
{
    for (int n=0; n<GOES_SIZE-1; n++)  // goes to size-1
    {
       gamma[n] = ( log(flux[n]/flux[n+1]) )/ ( log(energy[n+1]/energy[n]) ) ;
    }
}

// Name : setOneMinusGamma
// Function : Set the oneMinusGamma values.
// Description :  Loop through gamma values and subtract from 1 to 
//                get oneMinusGamma values.
// Calling Sequence :  object.setOneMinusGamma()
// Inputs : None.
// Outputs : None.                 
// Restrictions :  None.
void GammaClass::setOneMinusGamma()
{
   for (int n=0; n<GOES_SIZE - 1; n++)  // goes to size-1
   {
      oneMinusGamma[n] = 1. - gamma[n] ;
   }
}

// Name : writeGamma
// Function : Print the gamma values to a text file.
// Description :  Loop through the gamma array and write the
//                date, time, and gamma value to a text file.                
// Calling Sequence :  object.writeGamma(date, time, outGAMMA)
// Inputs : date, time, outGAMMA
// Outputs : None.                 
// Restrictions :  ofstream outGAMMA must already be open.
void GammaClass::writeGamma(string & _date, string & _time, ofstream & outGAMMA)
{
  outGAMMA << _date << " " <<  _time << " " ;

  for(int j=0; j<GOES_SIZE-2; j++) 
  {
      outGAMMA << fixed << setprecision(3) << setw(11) << gamma[j] << "  ";
  }
  outGAMMA << fixed << setprecision(3) << setw(11) << gamma[GOES_SIZE-2] << endl;
}

// Name : writeGamma
// Function : Print the gamma values to a text file.
// Description :  Loop through the gamma array and write the
//                date, time, and gamma value to a text file.                
// Calling Sequence :  object.writeGamma(outGAMMA)
// Inputs : outGAMMA
// Outputs : None.                 
// Restrictions :  ofstream outGAMMA must already be open.
void GammaClass::writeGamma(ofstream & outGAMMA)
{
  outGAMMA << date << " " <<  time << " " ;
  for(int j=0; j<GOES_SIZE-2; j++) 
  {
      outGAMMA << fixed << setprecision(3) << setw(11) << gamma[j] << "  ";
  }
  outGAMMA << fixed << setprecision(3) << setw(11) << gamma[GOES_SIZE-2] << endl;
}

// Name : checkGammaValues
// Function : Check the values of gamma.
// Description : Loop through the gamma array, check whether it should be set to 
//               a default value, if not, then check and make sure gamma is within the
//               max/min limits. If not reset the gamma limit flag.
// Calling Sequence :  object.checkGammaValues()
// Inputs : None.
// Outputs : None.                 
// Restrictions :  None.
void GammaClass::checkGammaValues()
{
  for (int n=0; n<GOES_SIZE - 1; n++)  // goes to size-1 
      {
       // If not using default, calculate gamma
       if (isBackground[n] != 1) 
       { 
           // Make sure gamma is not above or below max/min gamma
           if (gamma[n] < MIN_GAMMA) 
           {
               gamma[n] = MIN_GAMMA;
               hasGammaLimit[n] = true;
           }
           else if (gamma[n] > MAX_GAMMA) 
           {
               gamma[n] = MAX_GAMMA;
               hasGammaLimit[n] = true;
           } 

      } 
      else 
      {  // Use the default gamma
           gamma[n] = DEFAULT_GAMMA[n];
      } // if (isBackground != 1)
  }
}

// Name : writeHasGammaLimit
// Function : Print the gamma limit flag values to a text file.
// Description :  Loop through the gamma limit flag array and write the
//                values to a text file.                
// Calling Sequence :  object.writeHasGammaLimit(outFLAGS)
// Inputs : outFLAGS
// Outputs : None.                 
// Restrictions :  ofstream outFLAGS must already be open.
void GammaClass::writeHasGammaLimit(ofstream & outFLAGS)
{
  for (int k=0; k<GOES_SIZE-2; k++)
  {
     outFLAGS << setw(1) << hasGammaLimit[k] << " ";
  }
   outFLAGS << setw(1) << hasGammaLimit[GOES_SIZE-2] << "    ";
}

// Name : writeIsBackground
// Function : Print the background flag values to a text file.
// Description :  Loop through the background limits array and write the
//                values to a text file.                
// Calling Sequence :  object.writeIsBackground(outFLAGS)
// Inputs : outFLAGS
// Outputs : None.                 
// Restrictions :  ofstream outFLAGS must already be open.
void GammaClass::writeIsBackground(ofstream & outFLAGS)
{
  for (int k=0; k<GOES_SIZE-2; k++)
  {
     outFLAGS << setw(1) << isBackground[k] << " ";
  }
   outFLAGS << setw(1) << isBackground[GOES_SIZE-2] << "   ";
}


// Set arrays of constants

const double GammaClass::DEFAULT_GAMMA[GOES_SIZE-1] = SET_DEFAULT_GAMMA ;



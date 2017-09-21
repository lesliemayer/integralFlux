#include <iostream>
#include <cmath>
#include "EnergyClass.h"
using namespace std;

// Name : EnergyClass
// Function : Constructor for the EnergyClass.         
// Description :  Initializes energy, newEnergy, finalEnergy, isNotConverged
//                member variables.
// Calling Sequence :  Automatically called when an object of EnergyClass 
//                     is created.
// Inputs : None.
// Outputs : None.          
// Restrictions : None.
EnergyClass::EnergyClass()
{
 for(int j=0; j<GOES_SIZE; j++) 
 {
     // Intitialize with geometric energies
     energy[j] = sqrt(lowerEnergy[j])*sqrt(upperEnergy[j]);

     // Initialize newEnergy to be the same as original energy
     newEnergy[j] = energy[j];  

     finalEnergy[j] = -1.;  // Intialize to an impossible value

     isNotConverged[j] = true;  // set to true, reset to false when it converges

 }
}


// Name : ~EnergyClass
// Function : Destructor for the EnergyClass.         
// Description :  release any resources allocated by the object.
// Calling Sequence :  Automatically called when an object of EnergyClass 
//                     passes out of scope or is explicitly deleted.
// Inputs : None.
// Outputs : None.          
// Restrictions : None.
EnergyClass::~EnergyClass()
{

}


// Name : printEnergy
// Function : Print the energy values to standard out.
// Description :  Loop through energy array and print the
//                value.                
// Calling Sequence :  object.printEnergy()
// Inputs : None.
// Outputs : None.                 
// Restrictions : None.
void EnergyClass::printEnergy()
{
  cout << "printEnergy = " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
         cout << energy[j] << " " ;
  }
  cout << endl << endl;

} 



// Name : printEnergy
// Function : Print the energy values to outFile.
// Description :  Loop through energy array and print the
//                value to a text file.                
// Calling Sequence :  object.printEnergy(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void EnergyClass::printEnergy(ofstream & outFile)
{
  outFile << "EnergyClass : Energy[]: " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << fixed << setprecision(6) << setw(11) << energy[j] << " " ;
  }
  outFile << endl << endl;

} 



// Name : printNewEnergy
// Function : Print the newEnergy values to outFile.
// Description :  Loop through newEnergy array and print the
//                value to a text file.                
// Calling Sequence :  object.printNewEnergy(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void EnergyClass::printNewEnergy(ofstream & outFile)
{
  outFile << "EnergyClass : newEnergy[]: " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << fixed << setprecision(6) << setw(11) << newEnergy[j] << " " ;
  }
  outFile << endl << endl;

} 



// Name : printIsNotConverged
// Function : Print the isNotConverged values to outFile.
// Description :  Loop through isNotConverged array and print the
//                value to a text file.                
// Calling Sequence :  object.printIsNotConverged(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void EnergyClass::printIsNotConverged(ofstream & outFile)
{
  outFile << "EnergyClass : isNotConverged[]: " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << isNotConverged[j] << " " ;
  }
  outFile << endl << endl;

} 


// Name : printAbsDiff
// Function : Print the absolute difference of newEnergy - previousEnergy values
//            to outFile.
// Description :  Take the absolute difference of newEnergy and previousEnergy
//                arrays and print the values to a text file.              
// Calling Sequence :  object.printAbsDiff(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void EnergyClass::printAbsDiff(ofstream & outFile)
{
  outFile << "EnergyClass : abs(newEnergy - previousEnergy): " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << abs(newEnergy[j] - previousEnergy[j]) << " " ;
  }
  outFile << endl << endl;

} 

// Name : printConvergence
// Function : Print the Convergence standard * previousEnergy values
//            to outFile.
// Description :  Take the CONVERGENCE_STANDARD*previousEnergy value
//                and print the values to a text file.                
// Calling Sequence :  object.printConvergence(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  ofstream outFile must already be open.
void EnergyClass::printConvergence(ofstream & outFile)
{
  outFile << "EnergyClass : CONVERGENCE_STANDARD*previousEnergy: " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << CONVERGENCE_STANDARD*previousEnergy[j] << " " ;
  }
  outFile << endl << endl;

} 



// Name : printFinalEnergy
// Function : Print the finalEnergy values.
// Description :  Loop through and print the finalEnergy values
//                to standard out.          
// Calling Sequence :  object.printFinalEnergy()
// Inputs : None.
// Outputs : None.                 
// Restrictions :  None.
void EnergyClass::printFinalEnergy()
{
  cout << "printFinalEnergy = " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      cout << finalEnergy[j] << " " ;
  }
  cout << endl;

} 


// Name : printFinalEnergy 
// Function : Print the finalEnergy values to a file.
// Description :  Loop through and print the finalEnergy values
//                to outFile.          
// Calling Sequence :  object.printFinalEnergy(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions :  None.
void EnergyClass::printFinalEnergy(ofstream & outFile)
{
  outFile << "EnergyClass : finalEnergy[]: " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << finalEnergy[j] << " " ;
  }
  outFile << endl;

} 


// Name : printNewEnergy
// Function : Print the newEnergy values.
// Description :  Loop through and print the newEnergy values
//                to standard out.          
// Calling Sequence :  object.printNewEnergy()
// Inputs : None.
// Outputs : None.                 
// Restrictions :  None.
void EnergyClass::printNewEnergy()
{
  cout << "printNewEnergy = " ;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      cout << newEnergy[j] << " " ;
  }
  cout << endl;

} 

// Name : isDoneIterating
// Function : Check to see if we are done iterating on the center energy.
// Description :  Loop through finalEnergy values and if any are negative,
//                then we're not done iterating.
// Calling Sequence : check = object.isDoneIterating()
// Inputs : None.
// Outputs : flag             
// Restrictions :  None.
bool EnergyClass::isDoneIterating()
{
   // initialize flag to true
  bool flag = 1 ; 

  // if any of the finalEnergy's are negative, then we're not done iterating
  for (int j=0; j<GOES_SIZE; j++) 
  {
     if (finalEnergy[j] < 0) { flag = 0 ; }
  }
  return flag;
}

// Name : calculateCenterEnergy
// Function : Calculate the center energy of the SEISS channel.
// Description :  Depending on the value of gamma, calculate the center
//                energy from the lowerEnergy and upperEnergy of the channel.
// Calling Sequence : centerEnergy = object.calculateCenterEnergy(gamma, j)
// Inputs : gamma value,  index of array
// Outputs : Center energy.    
// Dependencies : Uses the pow subroutine from the C++ math library.
// Restrictions :  None.
double EnergyClass::calculateCenterEnergy(double gamma, int j) 
{
     double center, mgam;

     if (gamma == 0.0) 
     {
         center = 0.5*(lowerEnergy[j] + upperEnergy[j]);
         #ifdef DEBUG
            cout << "EnergyClass:calculateCenterEnergy : gamma == 0 " << endl;
         #endif
     } 
     else if (gamma == 1.0) 
     {
         center = (upperEnergy[j] - lowerEnergy[j]) / log(upperEnergy[j]/lowerEnergy[j]);

         #ifdef DEBUG
           cout << "calculateCenterEnergy : gamma == 1 " << endl;
         #endif
     } 
     else 
     {
         mgam = 1. - gamma;
         center = (mgam*(upperEnergy[j] - lowerEnergy[j])) / 
            ( pow(upperEnergy[j],mgam) - pow(lowerEnergy[j],mgam) );
         center = pow(center, 1.0/gamma );
     }  
    
     return center;

}

// Name : computeNewEnergy
// Function : Reset the previous center energy, and calculate the new center 
//            energy of the SEISS channel.
// Description :  Depending on the value of gamma, calculate the center
//                energy from the lowerEnergy and upperEnergy of the channel.
// Calling Sequence : object.computeNewEnergy(gamma)
// Inputs : gamma values array
// Outputs : None.        
// Dependencies :  Uses calculateCenterEnergy method within the EnergyClass.
// Restrictions :  None.
void EnergyClass::computeNewEnergy(double *gamma)
{
   double newLower[GOES_SIZE];
   double newUpper[GOES_SIZE];

   // initialize value of previous energy
   for(int j=0; j<GOES_SIZE; j++) 
   {
       if (finalEnergy[j] >= 0) 
       {
           previousEnergy[j] = finalEnergy[j];
       } else {
           previousEnergy[j] = newEnergy[j];
       }
   }

   // Calculate newEnergy for each gamma
   newUpper[GOES_SIZE-1] = 0.;

   //cout << "computeNewEnergy : newUpper = " ;
   for(int j=0; j<GOES_SIZE-1; j++) 
   {
       newUpper[j] = calculateCenterEnergy(gamma[j], j);
       #ifdef DEBUG
          cout << j << ": " << newUpper[j] << "  " ;
       #endif
   } 
   #ifdef DEBUG
      cout << endl;
   #endif

   // Calculate other newLower 
   newLower[0] = 0.;

   #ifdef DEBUG
      cout << "computeNewEnergy : newLower = " ;
   #endif

   for (int j=1; j<GOES_SIZE; j++) 
   {
        newLower[j] = calculateCenterEnergy(gamma[j-1], j);
        #ifdef DEBUG
           cout << j << ": " << newLower[j] << "  " ;
        #endif
   } 
   #ifdef DEBUG
      cout << endl;
   #endif

   // Average the middle channels of energies b/c there are 2 gamma's for each
   newEnergy[0] = newUpper[0]; // 1st energy
   newEnergy[GOES_SIZE-1] = newLower[GOES_SIZE-1];
   for (int k=1; k<GOES_SIZE-1; k++) 
   {
       newEnergy[k] = (newLower[k] + newUpper[k])*0.5;
   }
}


// Name : setFinalEnergyIfConverged
// Function :  Set the final center energy if the energy has converged.
// Description :  For each center energy, check to see if it has met the
//                the convergence standard for the first time.  If so, set
//                the final center energy and reset the convergence boolean
//                variable.
// Calling Sequence : object.setFinalEnergyIfConverged()
// Inputs : None.
// Outputs : None.        
// Restrictions :  None.
void EnergyClass::setFinalEnergyIfConverged()
{
   #ifdef DEBUG
      cout << "check_converge : finalEnergy = " ;
   #endif

   // If abs(newEnergy - previousEnergy) < CONVERGENCE_STANDARD*previousEnergy  
   // then the energy converged
   for (int k=0; k<GOES_SIZE; k++) 
   {
       if  (  ( abs(newEnergy[k] - previousEnergy[k]) < (CONVERGENCE_STANDARD*previousEnergy[k]) ) 
                 && (finalEnergy[k] < 0)  )
       {
           finalEnergy[k] = newEnergy[k];
           isNotConverged[k] = false; // Reset to false
       }
       #ifdef DEBUG
          cout << k << ": " << finalEnergy[k] << "  " ;
       #endif
    } // for
    #ifdef DEBUG
       cout << endl;
    #endif
}


// Name : setUnconvergedEnergy
// Function :  Set the unconverged center energy back to the geometric mean.
// Description :  For each center energy, check to see if it has not converged.
//                If so, set the unconverged center energy back to the geometric mean.
// Calling Sequence : object.setUnconvergedEnergy()
// Inputs : None.
// Outputs : None.        
// Restrictions :  None.
void EnergyClass::setUnconvergedEnergy()
{
   for (int k=0; k<GOES_SIZE; k++)  
   {   
     if (finalEnergy[k] < 0) 
     {
        finalEnergy[k] = energy[k];
     }
   }
}

// Name : writeIsNotConverged
// Function :  Write out the convergence flags.
// Description :  Write each convergence flag out to a text file.
// Calling Sequence : object.writeIsNotConverged(_date, _time, outFLAGS)
// Inputs : date, time, outFLAGS
// Outputs : None.        
// Restrictions :  ofstream outFLAGS must already be open.
void EnergyClass::writeIsNotConverged(string & _date, string & _time, ofstream & outFLAGS)
{
  outFLAGS << _date << " " <<  _time << " " ;
 
  for (int k=0; k<GOES_SIZE-1; k++)  
  {
     outFLAGS << setw(1) << isNotConverged[k] << " ";
  }
   outFLAGS << setw(1) << isNotConverged[GOES_SIZE-1] << "    ";
}


// Set arrays of constants
const double EnergyClass::lowerEnergy[GOES_SIZE] = SET_lowerEnergy ;

const double EnergyClass::upperEnergy[GOES_SIZE]  = SET_upperEnergy ;




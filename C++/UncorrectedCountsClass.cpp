
#include "UncorrectedCountsClass.h"


// Name : UncorrectedCountsClass
// Function : Constructor for the UncorrectedCountsClass.         
// Description : Initializes uncorrectedCounts, correctedCounts, and
//               standardDeviation.
// Calling Sequence :  Automatically called when an object of UncorrectedCountsClass
//                     is created.
// Inputs : None.
// Outputs : None.          
// Restrictions : None.
UncorrectedCountsClass::UncorrectedCountsClass()
{
   for(int j=0; j<GOES_SIZE; j++) 
   {
     uncorrectedCounts[j] = 0.;
     correctedCounts[j] = 0.;
     standardDeviation[j] = sqrt(AvgUncorrectedCounts[j]*DELTA_TIME);
   } 
}


// Name : ~UncorrectedCountsClass
// Function : Destructor for the UncorrectedCountsClass.         
// Description :  Release any resources allocated by the object.
// Calling Sequence :  Automatically called when an object of UncorrectedCountsClass 
//                     passes out of scope or is explicitly deleted.
// Inputs : None.
// Outputs : None.          
// Restrictions : None.
UncorrectedCountsClass::~UncorrectedCountsClass()
{
  
}


// Name : printUncorrectedCounts
// Function : Print the uncorrectedCounts.
// Description :  Loop through uncorrectedCounts and print to standard out.               
// Calling Sequence :  object.printUncorrectedCounts()
// Inputs : None.
// Outputs : None.                 
// Restrictions : None.
void UncorrectedCountsClass::printUncorrectedCounts()
{
  cout << "UncorrectedCountsClass : uncorrectedCounts[]:" << endl;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      cout << uncorrectedCounts[j] << " " ;
  }  
  cout << endl;
  cout << endl;
}


// Name : printUncorrectedCounts
// Function : Print the uncorrectedCounts to a text file.
// Description :  Loop through uncorrectedCounts and print to a text file.               
// Calling Sequence :  object.printUncorrectedCounts(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions : ofstream outFile must already be open.
void UncorrectedCountsClass::printUncorrectedCounts(ofstream & outFile)
{
  outFile << "UncorrectedCountsClass : uncorrectedCounts[]:" << endl;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << fixed << setprecision(6) << setw(11) << uncorrectedCounts[j] << "  ";
  }  
  cout << endl;
  cout << endl;
}

// Name : printCorrectedCounts
// Function : Print the correctedCounts.
// Description :  Loop through correctedCounts and print to standard out.               
// Calling Sequence :  object.printCorrectedCounts()
// Inputs : None.
// Outputs : None.                 
// Restrictions : None.
void UncorrectedCountsClass::printCorrectedCounts()
{
  cout << "UncorrectedCountsClass : correctedCounts[]:" << endl;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      cout << correctedCounts[j] << " " ;
  }  
  cout << endl;
  cout << endl;
}

// Name : printCorrectedCounts
// Function : Print the correctedCounts to a text file.
// Description :  Loop through correctedCounts and print to a text file.               
// Calling Sequence :  object.printCorrectedCounts(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions : ofstream outFile must already be open.
void UncorrectedCountsClass::printCorrectedCounts(ofstream & outFile)
{
  outFile << endl;
  outFile << "UncorrectedCountsClass : correctedCounts[]:" << endl;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << fixed << setprecision(6) << setw(11) << correctedCounts[j] << "  ";
  }  
  cout << endl;
  cout << endl;
}

// Name : printAvgUncorrectedCounts
// Function : Print the AvgUncorrectedCounts to a text file.
// Description : Loop through AvgUncorrectedCounts and print to a text file.               
// Calling Sequence :  object.printAvgUncorrectedCounts(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions : ofstream outFile must already be open.
void UncorrectedCountsClass::printAvgUncorrectedCounts(ofstream & outFile)
{
  outFile << endl;
  outFile << "UncorrectedCountsClass : AvgUncorrectedCounts[]:" << endl;
  for(int j=0; j<GOES_SIZE; j++) 
  {
      outFile << fixed << setprecision(6) << setw(11) << AvgUncorrectedCounts[j] << "  ";
  }  
  cout << endl;
  cout << endl;
}


// Name : printStandardDeviation
// Function : Print the standardDeviation values to standard out.
// Description : Loop through standardDeviation and print to standard out.               
// Calling Sequence :  object.printStandardDeviation()
// Inputs : None.
// Outputs : None.                 
// Restrictions : None.
void UncorrectedCountsClass::printStandardDeviation()
{
  cout << "UncorrectedCountsClass : standardDeviation[]: " << endl;
  for (int j=0; j<GOES_SIZE; j++) 
  {
      cout << j << " " << standardDeviation[j] << endl;
  }  
  cout << endl;
  cout << endl;
}

// Name : printStandardDeviation
// Function : Print the standardDeviation values to a text file.
// Description : Loop through standardDeviation and print to a text file.               
// Calling Sequence :  object.printStandardDeviation(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions : ofstream outFile must already be open.
void UncorrectedCountsClass::printStandardDeviation(ofstream & outFile)
{
  outFile << endl;
  outFile << "UncorrectedCountsClass : standardDeviation[]: " << endl;
  for (int j=0; j<GOES_SIZE; j++) 
  {
      outFile << fixed << setprecision(6) << setw(11) << standardDeviation[j] << " " ;
  }  
  outFile << endl;
  outFile << endl;
}


// Name : printCorrectedCountsDelta
// Function : Print the correctedCounts[j]*DELTA_TIME values to a text file.
// Description : Loop through correctedCounts[j]*DELTA_TIME and do a formatted
//               write to a text file.               
// Calling Sequence :  object.printCorrectedCountsDelta(outFile)
// Inputs : outFile
// Outputs : None.                 
// Restrictions : ofstream outFile must already be open.
void UncorrectedCountsClass::printCorrectedCountsDelta(ofstream & outFile)
{
  outFile << endl;
  outFile << "UncorrectedCountsClass : correctedCounts*DELTA_TIME[]: " << endl;
  for (int j=0; j<GOES_SIZE; j++) 
  {
      outFile << fixed << setprecision(6) << setw(11) << correctedCounts[j]*DELTA_TIME << " " ;
  }  
  outFile << endl;
  outFile << endl;
}


// Name : calculateCounts
// Function : Calculate the uncorrected and corrected counts.
// Description : Convert flux + corrections to uncorrected counts, and
//               corrections to corrected counts, using the geometricFactor.
// Calling Sequence :  object.calculateCounts(flux, corrections)
// Inputs : flux, corrections
// Outputs : None.                 
// Restrictions : corrections should already be set.
void UncorrectedCountsClass::calculateCounts(double *flux, double *corrections)
{
 for (int j=0; j<GOES_SIZE; j++) 
 {
     uncorrectedCounts[j] = geometricFactor[j] * (flux[j] + corrections[j]) ;
     correctedCounts[j] = geometricFactor[j] * flux[j];
 }
}

// Name : calculateStandardDeviation
// Function : Calculate the standard deviation of uncorrected counts.
// Description :  If the uncorrected counts is below the upper limit,
//                add this to the running average of the uncorrrected counts, then
//                use this average to calculate the standard deviation.
// Calling Sequence : object.calculateStandardDeviation()
// Inputs : None.
// Outputs : None.                 
// Restrictions : None.
void UncorrectedCountsClass::calculateStandardDeviation()
{
 #ifdef DEBUG
    cout << "calculateStandardDeviation : " << endl;
 #endif
 for(int j=0; j<GOES_SIZE; j++) 
 {
     #ifdef DEBUG
        cout << "upperLimit[" << j << "] : " << upperLimit[j] << "  uncorrectedcounts : " << uncorrectedCounts[j] << endl;
     #endif
     if ( uncorrectedCounts[j] < upperLimit[j] ) 
     {
        #ifdef DEBUG
           cout << "j: " << j << " previousAvgUncorrectedCounts: ";
           cout << previousAvgUncorrectedCounts[j] << " AvgUncorrectedCounts: ";
           cout << AvgUncorrectedCounts[j] << endl;
        #endif
        AvgUncorrectedCounts[j] = previousAvgUncorrectedCounts[j] + 
                           ( uncorrectedCounts[j] - previousAvgUncorrectedCounts[j] )/
                                           NUMBER_OF_POINTS ;

        #ifdef DEBUG
           cout << "after calc AvgUncorrectedCounts: " << AvgUncorrectedCounts[j] << endl;
        #endif

        //get standard deviation
        standardDeviation[j] = sqrt(AvgUncorrectedCounts[j]*DELTA_TIME);

        //reset previousAvgUncorrectedCounts
        previousAvgUncorrectedCounts[j] = AvgUncorrectedCounts[j];
        #ifdef DEBUG
           cout << "standard deviation = " << standardDeviation[j] << endl;
        #endif
     } 
     else 
     { 
        #ifdef DEBUG 
           cout << "j: " << j << " uncorrectedCounts:" << uncorrectedCounts[j] << " not < " ;
           cout << upperLimit[j] << " not updating standardDeviation " << endl;
        #endif 
     } // ( uncorrectedCounts[J] < upperLimit[j] ) 
 } // for(int j=0; j<GOES_SIZE; j++)
} 

// Name : useDefault
// Function : Check to see if we should use default gamma and set the gamma_default 
//            flag.
// Description : If the correctedCounts*DELTA_TIME < standardDeviation, then
//               the default gamma should be used.
// Calling Sequence : object.useDefault(gamma_default)
// Inputs : gamma_default
// Outputs : None.                 
// Restrictions : None.
void UncorrectedCountsClass::useDefault(bool *gamma_default)
{
  #ifdef DEBUG
     cout << "useDefault " << endl;
  #endif
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
      #ifdef DEBUG
         cout << "j = " << j << " correctedCounts[j]*DELTA_TIME = " << correctedCounts[j]*DELTA_TIME << " ;
         cout << correctedCounts[j+1]*DELTA_TIME = " << correctedCounts[j+1]*DELTA_TIME << endl;
      #endif 
      if ( correctedCounts[j]*DELTA_TIME < standardDeviation[j] ) // Just check one side, not both
      {
         #ifdef DEBUG
            cout << "use default for gamma " << j << endl;
         #endif 
         gamma_default[j] = 1;
      } 
  } //  end of for(int j=0; j<GOES_SIZE; j++)
} 

// Name : useTestDefault
// Function : Check to see if we should use default gamma and set the gamma_default 
//            flag.
// Description : If the correctedCounts*DELTA_TIME < testcasestandardDeviation, then
//               the default gamma should be used.  This is for testing purposes only.
// Calling Sequence : object.useTestDefault(gamma_default)
// Inputs : gamma_default
// Outputs : None.                 
// Restrictions : None.
void UncorrectedCountsClass::useTestDefault(bool *gamma_default)
{
  #ifdef DEBUG
     cout << "useTestDefault " << endl;
  #endif
  for(int j=0; j<GOES_SIZE-1; j++) 
  {
      #ifdef DEBUG
         cout << "j = " << j << " correctedCounts[j]*DELTA_TIME = " << correctedCounts[j]*DELTA_TIME ;
         cout << " correctedCounts[j+1]*DELTA_TIME = " << correctedCounts[j+1]*DELTA_TIME << endl;
      #endif
      if ( correctedCounts[j]*DELTA_TIME < testcaseStandardDeviation[j] ) 
      {
         #ifdef DEBUG
            cout << "use default for gamma " << j << endl;
         #endif
         gamma_default[j] = 1;
      } 
  } // end of for(int j=0; j<GOES_SIZE; j++)
} 


// Set arrays of constants


// Number of points used in the standard deviation calculation
const double UncorrectedCountsClass::NUMBER_OF_POINTS = (SECONDS_IN_DAY/DELTA_TIME);

// Geometric factor for the instrument
const double UncorrectedCountsClass::geometricFactor[GOES_SIZE] = SET_geometricFactor ;

// If the uncorrected counts < upperLimit,  include them in the standard deviation calculation
const double UncorrectedCountsClass::upperLimit[GOES_SIZE] = SET_upperLimit;

double UncorrectedCountsClass::previousAvgUncorrectedCounts[GOES_SIZE] = SET_seed ;

double UncorrectedCountsClass::AvgUncorrectedCounts[GOES_SIZE] = SET_seed ;

double UncorrectedCountsClass::standardDeviation[GOES_SIZE];

// For testing against IDL code
const double UncorrectedCountsClass::testcaseStandardDeviation[GOES_SIZE] = SET_testcaseStandardDeviation ;



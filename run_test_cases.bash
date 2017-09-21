#!/bin/bash
cd ./C++/

# make sure there are no spaces in following command:
# define file names
SEISSMAIN="goes_int_flux.cpp"
GOESCLASSFILE="GoesDataClass.h"
ENERGYFILE="EnergyClass.h"
MAKEFILE="Makefile.goes_int_flux"

# turn on diagnostics
echo "turning on diagnostics in $SEISSMAIN"
sed -i -r 's/\/*#define DIAGNOSTICS/#define DIAGNOSTICS/g' $SEISSMAIN
echo "turning on diagnostics in $GOESCLASSFILE"
sed -i -r 's/\/*#define\s+DIAGNOSTICS/#define DIAGNOSTICS/g' $GOESCLASSFILE


#compile
make -f $MAKEFILE clean
make -f $MAKEFILE
echo " "

# do diagnostic tests
./goes_int_flux 2001_09_26_0000_GOES10 diagnostic
echo " "
echo " "
./goes_int_flux 2001_09_26_1925_GOES08 diagnostic
echo " "
echo " "
./goes_int_flux 2001_11_23_1200_GOES08_FIT diagnostic
echo " "
echo " "
./goes_int_flux 2001_11_24_2300_GOES10 diagnostic
echo " "
echo " "
./goes_int_flux 2006_12_05_0600_GOES11 diagnostic
echo " "
echo " "
./goes_int_flux 2006_12_08_0100_GOES11 diagnostic
echo " "
echo " "

# change maximum number of iterations from 10 to 1
echo "Changing MAX_ITERATIONS to 1 for testing :" 
#USE regular expressions (-r)
sed -i -r 's/\bMAX_ITERATIONS\b\s*=\s*[0-9]+\s*;/MAX_ITERATIONS = 1;/g' $ENERGYFILE


#re-compile
make -f $MAKEFILE clean
make -f $MAKEFILE
echo " "
./goes_int_flux 2006_12_08_0100_GOES11 diagnostic
echo " "

# change maximum number of iterations back to 10
echo "Changing back to MAX_ITERATIONS to 10"
sed -i -r 's/\bMAX_ITERATIONS\b\s*=\s*[0-9]+\s*;/MAX_ITERATIONS = 10;/g' $ENERGYFILE

# turn off diagnostics
echo "Turning off diagnostics in $SEISSMAIN"
sed -i 's/#define DIAGNOSTICS/\/\/#define DIAGNOSTICS/g' $SEISSMAIN
echo "Turning off diagnostics in $GOESCLASSFILE"
sed -i -r 's/#define\s+DIAGNOSTICS/\/\/#define DIAGNOSTICS/g' $GOESCLASSFILE
echo " "

#re-compile
make -f $MAKEFILE clean
make -f $MAKEFILE
echo " "

# do performance tests
./goes_int_flux 2004_07_25_GOES11 proxy
echo " "
./goes_int_flux 2004_07_25_GOES10 proxy
echo " "
./goes_int_flux 2001_09_24_GOES08 proxy
echo " "
./goes_int_flux 2001_09_24_GOES10 proxy
echo " "
./goes_int_flux 2001_11_22_GOES08 proxy
echo " "
./goes_int_flux 2001_11_22_GOES10 proxy
echo " "
./goes_int_flux 2006_12_03_GOES10 proxy
echo " "
./goes_int_flux 2006_12_03_GOES11 proxy
echo " "


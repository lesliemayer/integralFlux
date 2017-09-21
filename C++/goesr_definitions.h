#define SET_GOES_SIZE 10   // all classes

//GammaClass
#define SET_DEFAULT_GAMMA  { 1.3, 1.3, 1.3, 1.4, 1.6, 1.7, 1.9, 1.9, 2. }

// EnergyClass
#define SET_lowerEnergy { 1.0, 1.9, 3.2, 6.5, 12., 25., 40., 80., 150., 275. }
#define SET_upperEnergy { 1.9, 3.2, 6.5, 12., 25., 40., 80., 150., 275., 500. }

// UnCorrectedCountsClass
// Geometric factor for the instrument
#define SET_geometricFactor { .05, .073, .185, .308, 1.3, 2.98, 14.4, 46.3, 97.5, 175.5 }
#define SET_upperLimit  { .05, .063, .105, .087, .138, .158, .744, .883, .949, 1.442 }
#define SET_seed  { .06, .052, .032, .014, .027, .06, .1, .165, .26, .29 }
#define SET_testcaseStandardDeviation  {}

// GoesDataClass
#define SET_INTEGRAL_SIZE 7
#define SET_OUT_FLUX_SIZE 8
#define SET_MISSING -99999.
//                    1  5 10 15 30 50 60 100
#define SET_INDEX_DF  { 0, 2, 3, 4, 5, 6, 6, 7 }
#define SET_ENERGY_DIFF_FLUX_OUT  {1., 5., 10., 15., 30., 50., 60., 100.}
//                        1  5 10 30 50 60 100
#define SET_INDEX_GAMMA  { 0, 2, 3, 5, 6, 6, 7 }
#define SET_INDEX_BEGIN_AREA  { 0, 3, 4, 5, 6, 7, 7 }
#define SET_GREATER_ENERGY { 1., 5., 10., 30., 50., 60., 100. } 

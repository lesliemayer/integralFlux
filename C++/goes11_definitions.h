#define SET_GOES_SIZE 7   // all classes

//GammaClass
#define SET_DEFAULT_GAMMA  {1.3, 1.4, 1.5, 1.7, 1.9, 2.0}

// EnergyClass
#define SET_lowerEnergy {0.6, 4.2, 8.7, 15., 39., 84., 110.}
#define SET_upperEnergy {4.2, 8.7, 14.5, 44., 82., 200., 500.}

// UnCorrectedCountsClass
// Geometric factor for the instrument
#define SET_geometricFactor { .202, .252, .325, 4.64, 15.5, 90., 300. }
#define SET_upperLimit  {.2, .09, .07, .25, .8, 1.2, 2.5 }
#define SET_seed  {.06, .018, .01, .05, .1, .19, .29}
#define SET_testcaseStandardDeviation  {.02, .008, .006, .02, .03, .04, .04}

// GoesDataClass
#define SET_INTEGRAL_SIZE 7 
#define SET_OUT_FLUX_SIZE 8
#define SET_MISSING -99999.
//                    1  5 10 15 30 50 60 100
#define SET_INDEX_DF  {0, 1, 2, 2, 3, 4, 4, 5}
#define SET_ENERGY_DIFF_FLUX_OUT  {1., 5., 10., 15., 30., 50., 60., 100.}
//                        1  5 10 30 50 60 100
#define SET_INDEX_GAMMA  {0, 1, 2, 3, 4, 4, 5}
#define SET_INDEX_BEGIN_AREA  {0, 1, 2, 4, 4, 5, 5}
#define SET_GREATER_ENERGY { 1., 5., 10., 30., 50., 60., 100. } 

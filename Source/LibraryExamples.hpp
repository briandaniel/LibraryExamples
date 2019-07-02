/*
 * LibraryExamples.hpp
 *
 *  Created on: Jun 26, 2019
 *      Author: brian
 */

#ifndef LIBRARYEXAMPLES_HPP_
#define LIBRARYEXAMPLES_HPP_


// Standard includes
#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <complex>
#include <cstdio>
#include <ctime>
#include <vector>
#include <mpi.h>
#include <iomanip>

using namespace std;

// Library includes
#include "Nonl_Examples.hpp"
#include "ExamplesVis.hpp"
#include "Examples.hpp"
#include "LumpModelSystems/SingleFiberVarResSystem/SingleFiberVarResSystem.hpp"

// Standard constant definitions
#define PI 3.141592653589793
#define RTHIRD 1.259921049894873165 // 2^(1/3)
#define THIRD  0.333333333333333333 // 1/3

// Parallel commands
#define ROOT_ID 0	 // id of root processor



// local functions
void displayHelp();



#endif /* LIBRARYEXAMPLES_HPP_ */

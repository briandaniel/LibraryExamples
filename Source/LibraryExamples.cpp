/*
 * LibraryExamples.cpp
 *
 *  Created on: Jun 26, 2019
 *      Author: brian
 */

#include "LibraryExamples.hpp"

int main(int argc, char** argv) {

	// ---------------- Set up parallel MPI environment ---------------- //
	// Initialize the MPI environment.
	MPI_Init(NULL, NULL);

	// Get the number of processes
	int Nprocs, procID;
	MPI_Comm_size(MPI_COMM_WORLD, &Nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &procID);
	double t1, t2;
	t1 = MPI_Wtime();

	// default: no success;
	bool success = 0;

	int solutionSetting = 0;

	// If no solution setting is given display help
	if( argc <= 1 )
	{
		displayHelp();
		solutionSetting = -1;
	}
	else
	{
		solutionSetting = strtol(argv[1], NULL, 10);
		if(procID == ROOT_ID) cout << "Solution setting = " << solutionSetting << endl;
	}



	if( solutionSetting == 202 )
	{
		testNewtonsMethod();
	}
	else if ( solutionSetting == 101 )
	{
		testBFGSBndMPISW();
		testBFGSBnd();
		testBFGSBnd_MPI();
		testLMExpMPI();
		testBFGS_MPI();
		testBFGS_booth();
		testBFGS();
		testHessian();
		testGAParallel();
		testGA();
		testLMExp();
		testLMCubicLinearCoef();
		testSimplexSearch();
		testCreateObject();
		testGradientEvaluation();
		testGradientApproxMultMPI();
		testGradientApproxMultMPIRecur();
	}
	else if ( solutionSetting == 102)
	{
		testBFGSBndMPISW();
	}
	else if ( solutionSetting == 103)
	{
		testBFGSBnd();
	}
	else
	{
		cout << "That solution setting does not exist :-(" << endl;
	}



	t2 = MPI_Wtime();
	cout <<  "Elapsed computation time = " << t2 - t1 << " on proc: " << procID << endl;

	MPI_Finalize();



	return (success);

}



void displayHelp()
{
	cout << endl << "No solution setting given. Choose from: " << endl;
	cout << "  101: Run all the optimization examples" << endl;
	cout << "  102: testBFGSBndMPISW();" << endl;
	cout << "  103: testBFGSBnd();" << endl;

	cout << "  201: Run all the nonlinear solver examples" << endl;
	cout << "  202: Run the Newton's method example" << endl;


	cout << endl;
}











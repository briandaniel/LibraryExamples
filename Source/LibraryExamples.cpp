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
	if( argc > 1 )
	{
		solutionSetting = argv[1][0] - '0';
	}
	if(procID == ROOT_ID) cout << "Solution setting = " << solutionSetting << endl;



	if( solutionSetting == 0 )
	{
		testNewtonsMethod();

	}
	else if ( solutionSetting == 1 )
	{

	}



	t2 = MPI_Wtime();
	cout <<  "Elapsed computation time = " << t2 - t1 << " on proc: " << procID << endl;

	MPI_Finalize();



	return (success);

}




#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../rand_matrix/randm.h"
#include "../utils/files.h"

#define ORDER 8192
#define TESTS 10

// Matrices
double A[ORDER * ORDER];
double B[ORDER * ORDER];
double C[ORDER * ORDER];

// Prototyped function written bellow main()
void dgemm(int, double*, double*, double*);

int main(void) {
	// Register
	char* filename = "out.csv";
	printf("All results will be written in %s\n\n", filename);
	
	// Header of csv file
	header(filename);
	
	// Seed as the actual time
	srand((unsigned int) time(NULL));
	
	// Random matrices
	printf("Creating Matrices...\n");
	random_matrix(ORDER, A);
	random_matrix(ORDER, B);
	
	// Empty matrix C -> future result
	empty_matrix(ORDER, C);
	
	printf("All spaces created!\n\n");
	
	// Here execution really begins
	printf("Multipling Matrices...\n\n");
	
	
	// -------------- MAIN --------------
	int tests_made = 0;
	while (tests_made < TESTS) {
		
		// -------------------------- //
		clock_t start_time = clock(); // The benchmark is made
									  // in this part of code
		dgemm(ORDER, A, B, C);		  // That`s why it is
									  // the marked!
		clock_t end_time = clock();	  //
		// -------------------------- //
		
		
		// Calculating all times and logging info
		double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		double performance = 1 / execution_time;
		
		// Output in terminal for checking
		logging(tests_made, execution_time, performance);		
		
		// Writing the util csv data
		body(filename, tests_made, execution_time, performance);
		
		// Randomizing matrices again
		random_matrix(ORDER, A);
		random_matrix(ORDER, B);
		
		// Cleaning result matrix
		empty_matrix(ORDER, C);
		
		tests_made++;
	}
	// -------------- MAIN --------------
		
	return EXIT_SUCCESS;
}


// Function to be tested
void dgemm(int order, double* A, double* B, double* C) {
	/*
	* Multiply two matrices (A and B) and inserts 
	* the result in another given space (C)
	* Result: C = AB
	*/
	
	for (int line = 0; line < order; line++) {
		for (int column = 0; column < order; column++) {
			
			double Cij = C[line + column * order];
			for (int index = 0; index < order; index++)
				Cij += A[line + index * order] * B[index + column * order];
			C[line + column * order] = Cij;
		}
	}
}
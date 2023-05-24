#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "rand_matrix/randm.h"

#define ORDER 8192
#define TESTS 10

// Matrices
double A[ORDER * ORDER];
double B[ORDER * ORDER];
double C[ORDER * ORDER];

void dgemm(int, double*, double*, double*);

int main(void) {
	// Register
	char* filename = "out_O1.csv";
	printf("All results will be written in %s\n\n", filename);
	
	// Header of output file
	FILE *file = fopen(filename, "w");		
	if (file == NULL) {
		fprintf(stderr, "Error in open file %s\n", filename);
		return EXIT_FAILURE;
	}	
	// Print result in output.txt
	fprintf(
		file,
		"Test,Execution,Performance\n"
	);	
	fclose(file);	
	
	
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
		
		printf("Execution Time: %f\n", execution_time);
		printf("Performance: %f\n", performance);
		printf("Test: %i/10\n-------------------------------------\n", tests_made + 1);
		
		
		
		// ---------------- OUTPUT ----------------
		FILE *file = fopen(filename, "a");
		
		if (file == NULL) {
			fprintf(stderr, "Error in open file %s\n", filename);
			return EXIT_FAILURE;
		}
		
		// Print result in output.txt
		fprintf(
			file,
			"%i,%f,%f\n", tests_made + 1, execution_time, performance
		);
		
		fclose(file);		
		// ---------------- OUTPUT ----------------
		
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
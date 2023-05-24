#ifndef RAND_H
#define RAND_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void empty_matrix(int order, double* A) {
	/*
	* Receives a random matrix (by malloc)
	* and turn all its elements to zero.
	*/
	
	int order_squared = order * order;
	
	for (int i = 0; i < order_squared; i++)
		A[i] = (double) 0.0;
}


void random_matrix(int order, double* A) {
	/*
	* Given a matrix, randomize all its
	* entries with rand() function.
	*/
	
	int order_squared = order * order;
	for (int i = 0; i < order_squared; i++)
		A[i] = ((double) rand() / RAND_MAX) * 5.0;

}


double* create_matrix(int order) {
	/*
	* Generate a random matrix with
	* double numbers.
	* Matrix n x n, n = order
	*/
	
	int order_squared = order * order;
	
	double* matrix = (double*) malloc(sizeof(double) * order_squared);
	
	// All entries to zero
	empty_matrix(order, matrix);
	
	return matrix;
}


void show_matrix(int order, double* A) {	
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++)
			printf("%0.3f    ", A[i + j*order]);
		printf("\n");
	}
}

#endif //RAND_H
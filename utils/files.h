/*
 * .h file created by the necessity of call
 * small functions for write .csv files as
 * output and log infos in this work
 * NOTHING USEFULL TO SEE HERE
 */


#ifndef FILES_H
#define FILES_H

#include <stdio.h>

void header(char* filename) {
	/*
	 * All .csv files needs to start
	 * with a header like
	 *  |  Test,Execution,Performance  | 
	 * to declare what numbers are
	 * represented in each column.
	 */
	
	
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		fprintf(stderr, "File %s could not be opened\n\n", filename);
		fclose(file);
		return;
	}
	
	// Just the header
	fprintf(file, "Test,Execution,Performance\n");	
	
	// Important!
	fclose(file);
	return;
}


void body(char* filename, int test, double execution_time, double performance) {
	/*
	 * All the date we need to get
	 * the .csv file. Here in 'a' (append)
	 * mode since we dont want erase the headers
	 */
	 
	 FILE* file = fopen(filename, "a");
	 if (file == NULL) {
		 fprintf(stderr, "File %s could not be opened\n\n", filename);
		 fclose(file);
		 return;
	 }
	 
	 // Writes the data
	 fprintf(
		file,
		"%i,%f,%f\n",
		test + 1, execution_time, performance
	 );	 
	 
	 fclose(file);
	 return;	 
}


void logging(int test, double execution_time, double performance) {
	// Just for smart calls and reduce code
	printf("Execution Time: %f\n", execution_time);
	printf("Performance: %f\n", performance);
	printf("Test: %i/10\n-------------------------------------\n", test + 1);
	return;
}



#endif //FILES_H
/*
 CS 361: HW#4
 University of Illinois at Chicago
 Fall 2014
 
 Author: Bresia Prudente
 ACCC ID: bprude2
 UIN: 679176497
 */

/*
 FIRST CHILD'S TO DO LIST
 1.Close unused pipe ends
 2.Redirect stdin and stdout with dup2
 3.exec child program with shmid and msgid as arguments
 4.Parse shmid and msgid from command line arguments
 5.Set signal handlers
 6.While true:
    a. read xMin, xMax, yMin, yMax, nRows, nCols, and maxIters from stdin
    b. Implement Mandelbrot algorithm to fill shared memory. ( See below. )
    c. Write xMin, xMax, yMin, yMax, nRows, and nCols to stdout
    d. Write done message to message queue
 7. When SIGUSR1 arrives, exit with non-negative exit code equal to number of images calculated.
 8. ( If any errors occur, exit with a different negative exit code for each potential problem. )
 */

#include "header.h"

void signalHandler( int sig ){
	int status;
}//end signalHandler

int main( int argc, const char *argv[] ){
    
	//Print student information
	/*printf("\nAuthor: Bresia Prudente\n"
		   "ACCC ID: bprude2\n");
    printf("mandelCalc");
	*/
	//Check arguments
	if ( argc != 2 ) {
		printf("Error: Missing or invalid arguments.\n"
			   "Usage: shmID msgqID\n\n");
	}//end if
	else {
        //sanity check
        printf("calc: shmid = %s, msgqid = %s\n", argv[0], argv[1]);
        
    }//end else
    
    return 0;
    
}//end main
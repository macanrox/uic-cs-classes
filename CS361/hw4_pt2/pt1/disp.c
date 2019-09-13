/*
 CS 361: HW#4
 University of Illinois at Chicago
 Fall 2014
 
 Author: Bresia Prudente
 ACCC ID: bprude2
 UIN: 679176497
 */

/*
 SECOND CHILD'S TO DO LIST
 1. Close unused pipe ends
 2. Redirect stdin with dup2
 3. exec child program with shmid and msgid as arguments
 4. Parse shmid and msgid from command line arguments
 5. Set signal handlers
 6. While true:
    a. read xMin, xMax, yMin, yMax, nRows, and nCols from stdin
    b. Read data from shared memory and display image on screen
    c. Read filename from message queue and save data to a data file. Close file.
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
    printf("mandelDisplay");
	*/
	//Check arguments
	if ( argc != 3 ) {
		printf("Error: Missing or invalid arguments.\n"
			   "Usage: shmID msgqID1 msgqID2\n\n");
	}//end if
	else {
        //sanity check
        printf("disp: shmid = %s, msgqid = %s, msgqid2 = %s\n", argv[0], argv[1], argv[2]);
	}//end else
    
    return 0;
	
}//end main
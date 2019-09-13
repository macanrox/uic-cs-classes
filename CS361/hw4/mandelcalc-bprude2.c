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

int shmID, msgqID1;

int main( int argc, const char *argv[] ){
    
	//Check arguments
	if ( argc != 2 ) {
		printf("Error: Missing or invalid arguments.\n"
			   "Usage: shmID msgqID\n\n");
	}//end if
	else {
        
        //Parse the command line arguments
        shmID = atoi(argv[0]);
        msgqID1 = atoi(argv[1]);
        
        //Receive message queue
        /*msgbuf *q1 = (msgbuf*)malloc(sizeof(msgbuf));
        msgrcv(msgqID, &q1, (sizeof(q1->mtext)+1), MSGTYPE1, 0);
        printf("CHILD 1: Read message type %ld and \"%s\" from message queue\n", q1->msgtype, q1->mtext);   //debug*/
        
        //Set signal handler to catch SIGUSR1
        //signal(SIGUSR1, signalHandler);
        
        //Read values from pipe
        /*float xMin, xMax, yMin, yMax;
        int nRows, nCols, maxIters;
        scanf("%f %f %f %f %d %d %d", &xMin, &xMax, &yMin, &yMax, &nRows, &nCols, &maxIters);*/
        
        //Attach shared memory
        int *shmPtr = (int*)shmat(shmID, NULL, 0);
        
        //Do algorithm here
        
        //for now just pass this value
        *shmPtr = 10;
        //printf("CHILD 1: Value added to the shared memory is %d\n", *shmPtr);
        
        //Detach shared memory
        shmdt(shmPtr);
        
        //Send a done message back to parent
        /*q1->msgtype = MSGTYPE3;
        strcpy(q1->mtext, "CHILD 1 is done");
        //Send done message
        if ((msgsnd(msgqID1, &q1, (sizeof(q1->mtext)+1), 0) < 0)){
            perror("msgsnd");
            exit(-1);
        }//end if*/
        
    }//end else
    
    return 0;
    
}//end main

//signal handler that handles SIGCHLD, SIGINT, and SIGUSR1
void signalHandler( int sig ){
    
	int status;
    pid_t pid1, pid2;
	pid_t returnID;
	returnID = wait( &status );
	printf("\nCaught signal: %d\n", sig);
    
    switch (sig) {
            //if SIGUSR1
        case SIGUSR1:
            printf("Process %d received SIGUSR1\n", getpid());
            //parent
            if (pid1 == getpid()) {
                printf("Process %d is passing SIGUSR to %d\n", getpid(), pid2);
                kill(pid2, SIGUSR1);
                sleep(3);
            }//end if
            //child
            else {
                printf("Process %d will terminate itself\n", getpid());
                kill(getpid(), SIGINT);
                sleep(3);
            }//end else
            
        default:
            break;
            
    }//end switch
    
}//end void usrSignalHandler

/*
 CS 361: HW #4
 University of Illinois at Chicago
 Fall 2014
 
 Author: Bresia Prudente
 ACCC ID: bprude2
 UIN: 679176497
 */

/*
 PARENT'S TO DO LIST
 1. Create pipe(s)
 2. Create message queue(s)
 3. Create shared memory
 4. Set signal handler for SIGCHLD ( In case children exit
 due to error conditions )
 5. Fork Children
 6. Close unused pipe ends
 7. While true:
    a. Read problem info from keyboard
    b. If user is not done yet:
        i. Write filename to message queue
        ii. Write xMin, xMax, yMin, yMax, nRows, nCols, and maxIters to pipe
        iii. Listen for done messages from both children
    c. else:
        i. Send SIGUSR1 signals to both children
        ii. Wait for both children, and report exit codes.
 8. Report final results and exit
 */

#include "header.h"

void runSrc(int pfd[]);
void runDest(int pfd[]);

int main( int argc, const char *argv[] ){
	
	//Print student information
	printf("\nAuthor: Bresia Prudente\n"
		   "ACCC ID: bprude2\n");
    
    int pid, status, returnID;
    int fd[2];
    const int READ = 0, WRITE = 1;
    
    pipe(fd);
    
    runSrc(fd);
    runDest(fd);
    close(fd[READ]);
    close(fd[WRITE]);
    
    pid = wait(&status);
    returnID = WEXITSTATUS(status);
    while (pid != -1) {
        fprintf(stderr, "Child %d exited with status %d\n", pid, returnID);
    }
    exit(0);
    
}//end main

void runSrc(int pfd[]){
    
    const int READ = 0, WRITE = 1;
    int pid;
    pid = fork();
    
    switch (pid) {
        //child
        case 0:
            dup2(pfd[WRITE], WRITE);
            close(pfd[READ]);
            execlp("./calc", "1", "2", NULL);
            perror("execlp");
            break;
        
        //parent
        default:
            break;
        
        //fork error
        case -1:
            perror("fork");
            exit(1);
    }//end switch
    
}//end void runSrc

void runDest(int pfd[]){
    
    const int READ = 0, WRITE = 1;
    int pid;
    pid = fork();
    
    switch (pid) {
        //child
        case 0:
            dup2(pfd[READ], READ);
            close(pfd[WRITE]);
            execlp("./disp", "1", "2", "3", NULL);
            perror("execlp");
            break;
            
        //parent
        default:
            break;
            
        //fork error
            perror("fork");
            exit(1);
    }//end switch
    
}//end void runDest

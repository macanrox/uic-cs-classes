
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

int main( int argc, const char *argv[] ){
	
	//Print student information
	printf("\nAuthor: Bresia Prudente\n"
		   "ACCC ID: bprude2\n");
    
	////////////
	// PIPES //
	//////////
    
    //Create two pipes for the children
    const int READ = 0, WRITE = 1;
    int p1[2], p2[2];
    char buf1[80];
    char buf2[80];
    
    pipe(p1);
    pipe(p2);
    
    //Pipe error messages
    if ( (pipe(p1) < 0) || (pipe(p2) < 0)) {
        perror("pipe");
        exit(-1);
    }//end if
    
	////////////////////
	// FORK CHILDREN //
	///////////////////
    
    //pid_t calcPid;  //child 1
    //pid_t dispPid;  //child 2
    pid_t returnID; //parent to return children values
    int status; //child exit status
    
    //child 1 fork error test
    calcPid = fork();   //child 1 fork
    if (calcPid < 0) {
        perror("fork");
        exit(-1);
    }//end if
    
    //Fork child 1
    else if (calcPid == 0){
        
        //print child info
		printf("\nCHILD 1: PID is %d\n", getpid());	//get child ID
		printf("CHILD 1: Parent PID is %d\n", getppid());	//get parent ID
        
        //child 1 READS from parent
        /*close(p1[WRITE]);   //close unused end of pipe 1
        read(p1[READ], buf1, sizeof(buf1)); //read from pipe
        dup2(p1[READ], STDIN_FILENO);   //duplicate pipe end
        close(p1[READ]);    //close used end of pipe 1
        
        //sanity test
        printf("CHILD 1 received this from parent: %s\n", buf1);*/
        
        //execute
        execlp("./calc", "1", "2", NULL);  //change accordingly
        
        //child 1 WRITES to child 2
        /*char *child1msg = "Child 1 Test";
        
        close(p2[READ]);    //close unused end of pipe 2
        write(p2[WRITE], child1msg, strlen(child1msg)+1);   //change accordingly
        dup2(p2[WRITE], STDOUT_FILENO); //duplicate pipe end
        sleep(2);   //wait for the child to finish its job
        close(p2[WRITE]);   //close used end of pipe 2*/
        
        //quit child
        printf("CHILD 1 exiting...\n");
        _exit(EXIT_SUCCESS);   //if child tries to return, exit
        
    }//end else
    
    //Fork child 2
    dispPid = fork();
    if (dispPid < 0) {
        perror("fork");
        exit(-1);
    }//end if
    
    else if (dispPid == 0){
            
        //print child info
        printf("\nCHILD 2: PID is %d\n", getpid());	//get child ID
        printf("CHILD 2: Parent PID is %d\n", getppid());	//get parent ID
        
        //child 2 RECEIVES from child 1
        /*close(p2[WRITE]);   //close unused end
        read(p2[READ], buf2, sizeof(buf2)); //read from pipe
        dup2(p2[READ], STDIN_FILENO);   //duplicate pipe end
        close(p2[READ]);    //close used end of pipe 2
        
        //sanity test
        printf("CHILD 2 received this from CHILD 1: %s\n", buf2);*/
        
        //execute
        execlp("./disp", "1", "2", "3", NULL);  //execute mandeldisp
        
        //quit child
        printf("CHILD 2 exiting...\n");
        _exit(EXIT_SUCCESS);   //if child tries to return, exit
    
    }//end if

    //Parent

    /*//Pipes
    char *parentmsg = "Parent Test";    //sanity test
    close(p1[READ]); //close unused end of pipe 1
    write(p1[WRITE], parentmsg, strlen(parentmsg)+1);   //change accordingly
    close(p1[WRITE]);   //close used end of pipe 1*/
    
    ////////////////////////
    // CHILD EXIT STATUS //
    //////////////////////
    wait(&status);
    printf("\nCHILD PROCESS EXIT STATUS\n");

    //child 1
    if (WIFEXITED(status))
        printf("CHILD %d exited with status %d\n", calcPid, returnID);
    else
        printf("CHILD %d did not terminate\n", calcPid);
    
    //child 2
    if (WIFEXITED(status) == 0)
        printf("CHILD %d exited with status %d\n", dispPid, returnID);
    else
        printf("CHILD %d did not terminate\n", dispPid);
    
    printf("\nPARENT exit\n\n");
    exit(0);
    
}//end main 

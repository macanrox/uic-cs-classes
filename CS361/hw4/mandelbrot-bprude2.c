
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

int msgqID, msgqID2, shmID;

int main( int argc, const char *argv[] ){
	
	//Print student information
	printf("\nAuthor: Bresia Prudente\n"
		   "ACCC ID: bprude2\n");
    
    printf("\nIf you need to quit the program at any point, enter 'ctrl+c'\n");
    
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
    
    /////////////////////
	// MESSAGE QUEUES //
	////////////////////
    key_t key;  //key passed to msgget()
    key = IPC_PRIVATE;
    //int msgqID, msgqID2;  //msg queue ID that returns value from msgget()
    char msgBuffer[10], msgBuffer2[10], msgBuffer3[10];
    char shmBuffer[10], shmBuffer2[10];
    
    //0600 for rw permission by user
    msgqID = msgget( key, IPC_CREAT | 0600 );
    msgqID2 = msgget( key, IPC_CREAT | 0600);
    
    //Error check
    if (msgqID < 0 /*|| msgqID2 < 0*/) {
        perror("msgget()");
        exit(-1);
    }//end if
    
    ///////////////////
	// SHARED MEMORY //
	///////////////////
    key_t key2;
    key2 = 1234; //value for shared memory
	int shmflg;	//shmflg to be passed to shmget()
	//int shmID;	//shared memory ID
    int *ptr;
    char *shm, *s, c;
	
	//Grab and create shared memory
    if ((shmID = shmget(IPC_PRIVATE, SHMSZE, IPC_CREAT | 0600)) == -1) {
        perror("shmid");
        exit(-1);
    }//end if
    
    //Attach the memory segment to data space
    //ptr = (int *)shmat(shmID, 0, 0);
    
    //Detach shared memory
    //shmdt(ptr);
    
	////////////////////
	// FORK CHILDREN //
	///////////////////
    pid_t calcPid;  //child 1
    pid_t dispPid;  //child 2
    pid_t returnID; //parent to return children values
    int status; //child exit status
    
    //child 1 fork error test
    calcPid = fork();   //child 1 fork
    if (calcPid < 0) {
        perror("fork");
        exit(-1);
    }//end if
    
    //Set a signal handler for SIGCHLD
    signal(SIGCHLD, signalHandler);
    
    //Fork child 1
    if (calcPid == 0){
        
        //print child info
		//printf("\nCHILD 1: PID is %d\n", getpid());	//get child ID
		//printf("CHILD 1: Parent PID is %d\n", getppid());	//get parent ID
        
        //Catch signal SIGUSR1
        signal(SIGUSR1, signalHandler);
        
        //Attach shared memory and add valuess
        /*ptr = (int *)shmat(shmID, 0, 0);
        *ptr = 5;   //change accordingly
        printf("CHILD 1: Value added to the shared memory is %d\n", *ptr);*/
        
        //Receive message queue #1
        msgbuf *q1 = (msgbuf*)malloc(sizeof(msgbuf));
        msgrcv(msgqID, q1, (sizeof(q1->mtext)+1), MSGTYPE1, 0);
        //printf("CHILD 1: Read message type %ld and \"%s\" from message queue\n", q1->msgtype, q1->mtext);
        //printf("CHILD 1: msgqID is %d\n", msgqID); //debug;
        
        //while (TRUE) {
            
            //child 1 READS from parent
            close(p1[WRITE]);   //close unused end of pipe 1
            close(p2[READ]);    //close unused end of pipe 2
            
            dup2(p1[READ], STDIN_FILENO);   //redirect stdin with dup2
            read(p1[READ], buf1, sizeof(buf1)+1); //read from pipe 1
            
            //sanity test
            //printf("CHILD 1 received this from parent: %s\n", buf1);
            
        //}//end while

        //Send a done message back to parent
        q1->msgtype = 3;
        strcpy(q1->mtext, "CHILD 1 is done");
        //Send done message
        if ((msgsnd(msgqID, q1, (sizeof(q1->mtext)+1), 0) < 0)){
            perror("msgsnd");
            exit(-1);
        }//end if
        
        dup2(p2[WRITE], STDOUT_FILENO); //redirect stdout with dup2
        //write(p2[WRITE], child1msg, strlen(child1msg));   //write to pipe 2
       
        //Convert ids from int to const char *
        sprintf(msgBuffer, "%d", msgqID);
        sprintf(shmBuffer, "%d", shmID);
        
        //execute
        execlp("./calc", shmBuffer, msgBuffer, NULL);  //change accordingly
        
        //quit child
        printf("CHILD 1 exiting...\n");
        _exit(EXIT_SUCCESS);   //if child tries to return, exit
        
    }//end else
    
    //Fork child 2
    else {
        
        dispPid = fork();
        if (dispPid < 0) {
            perror("fork");
            exit(-1);
        }//end if
        
        if (dispPid == 0) {
            
            //print child info
            //printf("\nCHILD 2: PID is %d\n", getpid());	//get child ID
            //printf("CHILD 2: Parent PID is %d\n", getppid());	//get parent ID
            
            //Catch SIGUSR1 signal
            signal(SIGUSR1, signalHandler);
            
            //Receive message queue #1
            msgbuf *q2 = (msgbuf*)malloc(sizeof(msgbuf));
            msgrcv(msgqID, q2, (sizeof(q2->mtext)+1), MSGTYPE1, 0);
            //printf("CHILD 2: Read message type %ld and \"%s\" from message queue\n", q2->msgtype, q2->mtext);
            //printf("CHILD 2: msgqID is %d\n", msgqID); //debug
            
            //Send a done message back to parent
            q2->msgtype = 3;
            strcpy(q2->mtext, "CHILD 2 is done");
            //Send done message
            if ((msgsnd(msgqID, q2, (sizeof(q2->mtext)+1), 0) < 0)){
                perror("msgsnd");
                exit(-1);
            }//end if
            
            //Receive message queue #2
            msgbuf *fq2 = (msgbuf*)malloc(sizeof(msgbuf));
            msgrcv(msgqID2, fq2, (sizeof(fq2->mtext)+1), MSGTYPE2, 0);
            //printf("CHILD 2: Read message type %ld and \"%s\" from message queue\n", fq2->msgtype, fq2->mtext);
            //printf("CHILD 2: msgqID is %d\n", msgqID2); //debug
            
            //Take the filename
            //FILE *fptr = fopen("output.txt", "w");
            //if file doesn't exist, create it
            //if(fptr == NULL){
                //fptr = fopen("mandelbrot.txt", "w");
            //}//end if
            
            //Attach shared memory and add valuess
            ptr = (int *)shmat(shmID, 0, 0);
            //printf("CHILD 2: Value read from the shared memory is %d\n", *ptr);
            
            //Detach shared memory
            shmdt((void*)ptr);
                
            //child 2 RECEIVES from child 1
            close(p2[WRITE]);   //close unused end
            dup2(p2[READ], STDIN_FILENO);   //duplicate pipe end
            read(p2[READ], buf2, sizeof(buf2)); //read from pipe
            close(p2[READ]);    //close used end of pipe 2
            
            //sanity test
            //printf("CHILD 2 received this from CHILD 1: %s\n", buf2);
            
            //Convert ids from int to const char *
            sprintf(msgBuffer2, "%d", msgqID);
            sprintf(msgBuffer3, "%d", msgqID2);
            sprintf(shmBuffer2, "%d", shmID);
            
            //execute
            execlp("./disp", shmBuffer2, msgBuffer2, msgBuffer3, NULL);  //execute mandeldisp
            
            //detach shared memory
            //shmdt(y);
            
            //quit child
            printf("CHILD 2 exiting...\n");
            _exit(EXIT_SUCCESS);   //if child tries to return, exit
            
        }//end if
        
        //Parent
        else {
            
            //Send message queue #1 to child 1
            char *msg1 = "Message #1";
            msgbuf *buf = (msgbuf*)malloc(sizeof(msgbuf));
            buf->msgtype = MSGTYPE1;
            strcpy(buf->mtext, msg1); //write message here
            msgsnd( msgqID, buf, (sizeof(buf->mtext)+1), 0 );
            //printf("Sent message queue #1 to CHILD 1\n");
            
            //Send message queue #1 to child 2
            msgbuf *buf2 = (msgbuf*)malloc(sizeof(msgbuf));
            buf2->msgtype = MSGTYPE1;
            strcpy(buf2->mtext, msg1); //write message here
            msgsnd( msgqID, buf2, (sizeof(buf2->mtext)+1), 0 );
            //printf("Sent message queue #1 to CHILD 2\n");
            //printf("\n");
            
            //Pipes
            close(p1[READ]); //close unused end of pipe 1
            close(p2[WRITE]);   //close unused end of pipe 2
            
            while (TRUE) {
            
                //set up a signal
                signal(SIGINT, signalHandler);
                
                //Prompt user for input
                float xMin, xMax, yMin, yMax;
                int nRows, nCols, maxIters;
                char xminbuf[5], xmaxbuf[5], yminbuf[5], ymaxbuf[5], nrowsbuf[5], ncolsbuf[5], maxiterbuf[5];

                printf("\nEnter values for xMin, xMax, yMin, yMax, nRows, nCols, and maxIters followed by spaces\n"
                       "> ");
                scanf("%f %f %f %f %d %d %d", &xMin, &xMax, &yMin, &yMax, &nRows, &nCols, &maxIters);
                printf("\n");
                
                if (xminbuf != 0 || xmaxbuf != 0 || yminbuf != 0 || ymaxbuf != 0 || nrowsbuf != 0 || ncolsbuf != 0 || maxiterbuf != 0) {

                    //Send message queue #2 to child 2
                    char *fp = "output.txt";
                    msgbuf *fbuf = (msgbuf*)malloc(sizeof(msgbuf));
                    fbuf->msgtype = MSGTYPE2;
                    strcpy(fbuf->mtext, fp); //write message here
                    msgsnd( msgqID2, fbuf, (sizeof(fbuf->mtext)+1), 0 );
                    printf("Sent message queue #2 to CHILD 2\n");
                    
                    //Write values to pipe
                    write(p1[WRITE], &xMin, sizeof(xMin));
                    write(p1[WRITE], &xMax, sizeof(xMax));
                    write(p1[WRITE], &yMin, sizeof(yMin));
                    write(p1[WRITE], &yMax, sizeof(yMax));
                    write(p1[WRITE], &nRows, sizeof(nRows));
                    write(p1[WRITE], &nCols, sizeof(nCols));
                    write(p1[WRITE], &maxIters, sizeof(maxIters));
                    close(p1[WRITE]);
                    
                    //Listen for done messages from children
                    //Receive message queue from child 1
                    msgbuf *recmsg1 = (msgbuf*)malloc(sizeof(msgbuf));
                    msgrcv(msgqID, recmsg1, (sizeof(recmsg1->mtext)+1), 3, 0);
                    printf("PARENT: \"%s\"\n", recmsg1->mtext);
                    
                    //Receive message queue from child 2
                    msgbuf *recmsg2 = (msgbuf*)malloc(sizeof(msgbuf));
                    msgrcv(msgqID, recmsg2, (sizeof(recmsg2->mtext)+1), 3, 0);
                    printf("PARENT: \"%s\"\n", recmsg2->mtext);
                    
                }//end if
                
                //Otherwise the user is done with the program
                else {
                    
                    //Send SIGUSR1 signal to children
                    signal(SIGUSR1, signalHandler);
                    
                    //Wait for the children and report exit codes
                    wait(&status);
                    printf("\nCHILD PROCESS EXIT STATUS\n");
                    
                    //child 1
                    if (WIFEXITED(status))
                        printf("CHILD %d exited with status %d\n", calcPid, returnID);
                    else
                        printf("CHILD %d did not terminate\n", calcPid);
                    
                    //child 2
                    if (WIFEXITED(status))
                        printf("CHILD %d exited with status %d\n", dispPid, returnID);
                    else
                        printf("CHILD %d did not terminate\n", dispPid);
                    
                    break;
                    
                }//end else
                
            }//end while
            
            //sanity test
            printf("PARENT: msgqID is %d\n", msgqID); //debug
            printf("PARENT: msgqID2 is %d\n", msgqID2);   //debug
            printf("PARENT: shmID is %d\n", shmID); //debug
            printf("\n");
            
            //Control the resources
            struct msqid_ds ds;
            struct shmid_ds sds;
            
            printf("\nRemoving message queue ID #1 and #2\n");   //debug
            if( (msgctl(msgqID, IPC_RMID, &ds) < 0) || (msgctl(msgqID2, IPC_RMID, &ds) < 0) ){
                perror("msgctl");
                exit(-1);
            }//end if
            
            printf("Removing shared memory ID");    //debug
            if ((shmctl(shmID, IPC_RMID, &sds) < 0)) {
                perror("shmctl");
                exit(-1);
            }//end if
            
            printf("\nPARENT exit\n\n");
            _exit(EXIT_SUCCESS);
        }//end else
        
    }//end if
    
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
            //if SIGCHLD
        case SIGCHLD:
            if ( returnID < 0 ) {
                perror( "wait" );
                exit(-1);
            }//end if
            
            //inspect exit status
            if ( WIFEXITED( status )) {
                printf("Child %d terminated normally\n", returnID);
            }//end if
            else if( WIFSIGNALED( status )){
                printf("Child %d terminated by signal %d\n", returnID, WTERMSIG(status));
            }//end else if
            break;
            
            //if SIGINT
        case SIGINT:
            printf("\nCLEARING UP RESOURCES\n");
            
            //Control the resources
            struct msqid_ds ds;
            struct shmid_ds sds;
            
            printf("Removing message queue ID #1 and #2\n");   //debug
            if( (msgctl(msgqID, IPC_RMID, &ds) < 0) || (msgctl(msgqID2, IPC_RMID, &ds) < 0) ){
                perror("msgctl");
                exit(-1);
            }//end if
            
            printf("Removing shared memory ID\n");    //debug
            if ((shmctl(shmID, IPC_RMID, &sds) < 0)) {
                perror("shmctl");
                exit(-1);
            }//end if
            
            printf("\nPROGRAM TERMINATING...\n");
            
            exit(0);
            
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


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

//Struct for user defined message buffer
typedef struct {
    long userMsgType;   //message type
    int code;
    char mtext[MSGSIZE]; //message text of size 80 bytes
} msgbuf;
/*
int sendMsg( int msgqID, struct msgbuf *qbuf ){
    
    int result, length;
    
    length = sizeof(struct msgbuf) - sizeof(long);
    result = msgsnd(qid, qbuf, length, 0);
    
    if (result == -1) {
        return(-1);
    }//end if
    
    return(result);
    
}//end int sendMsg
 */

//signal handler that handles SIGCHLD
void childSignalHandler( int sig ){
    
	int status;
	pid_t returnID;
	returnID = wait( &status );
	
	printf("\nCaught signal: %d\n", sig);
	
	if ( sig == SIGCHLD ) {
		
		if ( returnID < 0 ) {
			perror( "wait()" );
			exit(-1);
		}//end if
		
		//inspect exit status
		if ( WIFEXITED( status )) {
			printf("Child %d terminated normally\n", returnID);
		}//end if
		else if( WIFSIGNALED( status )){
			
			printf("Child %d terminated by signal\n", returnID);
			printf(": %d\n", WTERMSIG( status ));
			
		}//end else if
		
	}//end if
	
}//end void childSignalHandler

int main( int argc, const char *argv[] ){
	
	//Print student information
	printf("\nAuthor: Bresia Prudente\n"
		   "ACCC ID: bprude2\n");
    
    //Prompt user for input
    int xMin, xMax, yMin, yMax;
    
    ////////////
	// PIPES //
	//////////
	
	//Create 2 pipes for children
	const int READ = 0, WRITE = 1;	//define read and write
	int fd1[2], fd2[2];
	char buffer[80];
	int nRows = 42, nCols = 24;	//for mandelbrot calculations
    
    //Create a pipe
    pipe(fd1);
    pipe(fd2);
	
	//Check if pipe/s was created successfully
	if ( (pipe( fd1 ) < 0) || (pipe(fd2) < 0) ) {	//pipefd == &pipefd[0]
		perror( "pipe()" );
		exit(-1);
	}//end if
    
    /*close(fd1[READ]);
    FILE *out = fdopen(fd[WRITE]);
    fprintf(out, "%d %d", nRows, Ncols);
    fflush(out);*/
    
    /////////////////////
	// MESSAGE QUEUES //
	////////////////////
    key_t key;  //key passed to msgget()
    key = IPC_PRIVATE;
    int msgflg; //msg flag to pass to msgget()
    int msgqID, msgqID2;  //msg queue ID that returns value from msgget()
    //msgbuf sndbuf;  //size of buffer sent
    //msgbuf  rcvbuf; //size of buffer received
    //size_t  bufLen; //length of buffer
    char msgBuffer[10];
    char msgBuffer2[10];
    msgbuf q1, q2, q3, q4;
    char *msg1 = "Message Queue #1";
    char *msgChild = "Done";
    
    //0600 for rw permission by user
    msgqID = msgget( key, IPC_CREAT | 0600 );
    msgqID2 = msgget( key, IPC_CREAT | 0600);
    
    //Error check
    if (msgqID < 0 || msgqID2 < 0) {
        perror("msgget()");
        exit(-1);
    }//end if
	
	////////////////////
	// FORK CHILDREN //
	///////////////////
    
	pid_t calcPid;	//child 1 process
	pid_t displayPid;	//child 2 process
	pid_t returnID;	//parent: to return status
	int status;	//for the parent: child's exit status
    int childExec, childExec2;
    //int bytes;
    
    //sanity check
    //char *args[3] = {"1", "2", "3"};
    snprintf(msgBuffer, (sizeof(msgqID)), "%d", msgqID);
    snprintf(msgBuffer2, (sizeof(msgqID2)), "%d", msgqID2);
    const char child1msg[3] = {*argv[1], *argv[2], *argv[3]};
    const char parentmsg[3] = {*argv[1], *argv[2], *argv[3]};
    char bufTest1[20];
    char bufTest2[20];
    
    //printf("\nSize of msgBuffer %lu\n", (sizeof(msgqID)));
    //printf("Size of msgBuffer2 %lu\n", (sizeof(msgqID2)));
    //printf("Size of argv[1] %lu\n", (sizeof(argv[1])));
    printf("Size of parent array %lu\n", (sizeof(parentmsg)));
    
    int x, y;
    for (x = 0; x < (sizeof(parentmsg)); x++) {
        printf("parentmsg1: %c\n", parentmsg[x]);
    }
    
	//Error check
	calcPid = fork();	//child 1
	if ( calcPid < 0 ) {
		perror( "fork()" );
		exit(-1);
	}//end if
	
	//fork child 1
	if( calcPid == 0 ){
        
        //child 1 READS from parent
        close(fd1[WRITE]);  //close write end of pipe 1
        //close(fd2[READ]);   //close read end of pipe 2
        read(fd1[READ], bufTest1, 20);  //read from pipe 1
        dup2(fd1[READ], STDIN_FILENO);  //duplicate used end
        close(fd1[READ]);   //close used end
        printf("Received message from parent\n");
        
        //debug
        printf("\n");
        int x;
        for (x = 0; x < 3; x++) {
            printf("CHILD 1 received this from PARENT: %c\n", bufTest1[x]);
        }//end for*/
        
        //Receive message queue
        /*msgrcv(msgqID, &q1, sizeof(q1.mtext)+1, MSGTYPE1, 0);
        printf("CHILD 1: Read message type %ld and \"%s\" from message queue\n",
               q1.userMsgType, q1.mtext);
        printf("CHILD 1: msgqID is %d\n", msgqID); *///debug
        //fflush(stdout);
        
        //Send "done"
        //strcpy(q1.mtext, "done");
        //msgsnd(msgqID, &q1, sizeof(q1.mtext)+1, 0);
        
        printf("Size of child array %lu\n", (sizeof(child1msg)));
        
        /*const char *test[x];
        printf("\n");
        int y;
        for (y = 0; y < 3; y++) {
            printf("CHILD 1 is sending this to CHILD 2: %s\n", test[y]);
        }//end for*/
        
        printf("CHILD 1: PID is %d\n", getpid());   //get child id
        printf("CHILD 1: Parent PID is %d\n", getppid());   //get parent id of child 1
        printf("\n");
        
        //Change the filename and args accordingly
        childExec = execlp( "./calc", &parentmsg[0], &parentmsg[1], (char *)NULL );	//execute mandelCalc
        printf("\n");
        
        // Check if executed properly
        if (childExec == -1)
            perror("execlp()");
        
        //child 1 WRITES to child 2
        printf("Writing to child 2\n");
        close(fd2[READ]);
        write( fd2[WRITE], child1msg, (sizeof(child1msg)) );  //write message
        dup2(fd2[WRITE], STDOUT_FILENO);
        close( fd2[WRITE] );
		
		printf("CHILD 1 exit\n");
		_exit(0);	//if it tries to return, exit
		
		
	}//end else if
    
    //fork child 2
	else {
        
		displayPid = fork();
		if ( displayPid == 0 ) {
            
            //child 2 READS from child 1
            close( fd2[WRITE] );    //close write end of pipe 2
            read( fd2[READ], bufTest2, 20 );
            close( fd2[READ] ); //close used end
            dup2( fd2[READ], STDIN_FILENO );    //duplicate pipe end
            
            //Receive message queue
            /*msgrcv(msgqID, &q3, MAX, MSGTYPE2, 0);
            printf("CHILD 1: Read message type %ld and \"%s\" from message queue\n", q3.userMsgType, q3.mtext);
            printf("CHILD 1: msgqID is %d\n", msgqID); //debug*/
            
            //debug
            printf("\n");
            int x;
            for (x = 0; x < 3; x++) {
                printf("CHILD 2 received this from CHILD 1: %c\n", bufTest2[x]);
            }//end for
            
			printf("CHILD 2: PID is %d\n", getpid());	//get child ID
			printf("CHILD 2: Parent PID is %d\n", getppid());	//get parent ID
			
            //Change the filename and args accordingly
            printf("\n");
			childExec2 = execlp( "./disp", &child1msg[0], &child1msg[1], &child1msg[2], (char *)NULL );	//execute mandelDisplay
            
            // Check if executed properly
            if (childExec2 == -1)
                perror("execlp()");
 
            //Send "done"
            /*strcpy(q4.mtext, "done");
            msgsnd(msgqID, &q4, sizeof(q4.mtext)+1, 0);*/
            
			printf("CHILD 2 exit\n");
			_exit(0);	//if it tries to return, exit
			
		}//end if
        
	}//end else
    
    //Parent
    printf("\nPARENT: PID is %d\n", getpid());	//get parent ID
    
    //close pipes
    close(fd1[READ]);   //close read end of pipe 1
    write(fd1[WRITE], parentmsg, (sizeof(parentmsg)));
    close(fd1[WRITE]);
    
    //Send message queue #1
    /*q1.userMsgType = MSGTYPE1;
    strcpy(q1.mtext, msg1); //write message here
    msgsnd( msgqID, &q1, sizeof(q1.mtext)+1, 0 );
    printf("Sent message queue #1\n");*/
    
    //Send message queue #2
    /*q3.userMsgType = MSGTYPE2;
    strcpy(q3.mtext, "Message Queue #2");
    msgsnd(msgqID2, &q3, sizeof(q3.mtext)+1, 0);*/
    
    printf("\nPARENT: msgqID is %d\n", msgqID); //debug
    //printf("PARENT: msgqID2 is %d\n", msgqID2);   //debug
    
    ////////////////////////
    // CHILD EXIT STATUS //
    //////////////////////
    wait( &status );
    wait(&status);
    returnID = WEXITSTATUS( status );
    printf("\nCHILD PROCESS EXIT STATUS\n");
    
    //child 1
    if ( WIFEXITED(status) )
        printf("CHILD %d exited with status %d\n", calcPid, returnID);
    else
        printf("CHILD %d did not terminate\n", calcPid);
    
    //child 2
    if ( WIFEXITED(status) )
        printf("CHILD %d exited with status %d\n", displayPid, returnID);
    else
        printf("CHILD %d did not terminate\n", displayPid);
    
    /*msgrcv(msgqID, &q1, sizeof(q2.mtext)+1, MSGTYPE1, 0);
    printf("PARENT: Read message type %ld and \"%s\" from message queue\n",
           q2.userMsgType, q2.mtext);*/
    
    //msgrcv(msgqID2, &q4, sizeof(q4.mtext)+1, MSGTYPE2, 0);
    //printf("PARENT: Read message type %ld and \"%s\" from message queue\n",
    //       q4.userMsgType, q4.mtext);
    
    //Control the resource
    //This removes the message queue(s) when the program finishes
    struct msqid_ds ds;
    msgctl( msgqID, IPC_RMID, &ds );
    msgctl( msgqID2, IPC_RMID, &ds );

    printf("\nPARENT exit\n\n");
    exit(0);
	
	return 0;
	
}//end main 

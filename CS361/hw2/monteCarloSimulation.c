/*
 
 CS 361: HW #2
 
 Author: Bresia Prudente
 ACCC ID: bprude2
 
 */

#include "header.h"

unsigned long int numOfEval = 0;    //number of evaluations attempted
unsigned long int numOfSegFaults = 0;   //number of segmentation faults generated
sigjmp_buf envBuf; //buffer for longjmp
int pid1, pid2, status;

/*
 * childHandler handles SIGUSR1 and SIGUSR2 signals
 */
void childHandler( int sig ){
    
    int counter;
    printf("Caught signal # %d\n", sig);
    
    switch (sig) {
        case SIGUSR1:
            counter++;
            printf("Process %d: Received SIGUSR1\n", getpid());
            // if parent, pass and kill pid2
            if ( pid1 == getpid() && (numOfEval = (pow(numOfEval, 10)))) {
                printf("Process %d passing SIGUSR1 to %d\n", getpid(), pid2);
                kill( pid2, SIGUSR1 );
            }//end if
            // otherwise it's a child
            else if ( counter > ULONG_MAX ){
                printf("Process %d is passing SIGUSR 2 to itself\n", getpid());
                kill( getpid(), SIGUSR2 );
            }//end else
            break;
            
        case SIGUSR2:
            printf("Process %d: Received SIGUSR2\n", getpid());
            // if parent, pass and kill
            if ( pid1 == getpid()) {
                printf("Process %d passing SIGUSR2 to %d\n", getpid(), pid2);
                kill( pid2, SIGUSR2 );
            }//end if
            // otherwise it's the child
            else {
                printf("Process %d will terminate itself using SIGINT\n", getpid());
                kill( getpid(), SIGINT );
            }//end else
        default:
            break;
    }//end switch
    
}//end childHandler

/*
 * keyboardInterruptHandler handles signals that uses keyboard commands
 */
void keyboardInterruptHandler( int sig ){
    
    printf("Caught signal # %d\n", sig);
    
    switch (sig) {
        case SIGINT:
            printf("Number of Evaluations: %lu\n", numOfEval);
            printf("Number of Segmentation Faults: %lu\n", numOfSegFaults);
            exit(0);
            break;
        case SIGTSTP:
            printf("Number of Evaluations: %lu\n", numOfEval);
            printf("Number of Segmentation Faults: %lu\n", numOfSegFaults);
            break;
        default:
            break;
    }//end switch
    
}//end keyboardInterruptHandler


/*
 * segFaultHandler handles segmentation violation signals
 */
void segFaultHandler( int sig ){
    
    printf("Caught signal # %d\n", sig);
    
    // If SIGSEGV
    if ( sig == SIGSEGV ) {
        printf("Segmentation fault detected!");
        siglongjmp( envBuf, 1 );
    }//end if
    
    exit(sig);
    
}//end segFaultHandler

// MAIN
int main( int argc, char **argv ){
    
    // Print author credentials
    printf("\nAuthor: Bresia Prudente\n"
           "ACCC ID: bprude2\n\n");

    srand(time(NULL));  //initialize random generator
    
    // Parse command line arguments
    // Command prompt and read command line from user
    char *token, *userPrompt = "Monte $ ";
    char *cmd[COMMANDS], cmdLine[MAX_LEN];
    char delim[] = " \t\r\n"; //delimiter for space
    
    // Loop for user input
    while ( (fputs(userPrompt, stdout) > 0) && (fgets(cmdLine, sizeof(cmdLine), stdin)) != NULL ){
        
        // Copy tokenized input to char array
        int count = 0;
        token = cmdLine;
        while ( (cmd[count++] = strtok(token, delim)) ) {
            
            token = strtok(NULL, delim);
            
        }//end while
    }//end while

    // Set up signal handlers
    if (SIGSEGV == TRUE) {
        
        // increment global handlers
        numOfEval++;
        numOfSegFaults++;
        
        // if evaluation counter < limit, handler returns using longjmp
        if (numOfEval < ULONG_MAX) {
            
            signal( SIGSEGV, segFaultHandler );
            
        }//end if
        else {
            printf("Number of Evaluations: %lu\n", numOfEval);
            printf("Number of Segmentation Faults: %lu\n", numOfSegFaults);
            exit(0);
        }//end else
    }//end if
    
    if (SIGINT == TRUE) {
        
        // Print final results and exit
        signal( SIGINT, keyboardInterruptHandler );
        
    }//end if
    
    if (SIGTSTP == TRUE) {
        
        // Report current result
        signal( SIGTSTP, keyboardInterruptHandler );
        
    }//end if
    
    if (SIGUSR1 == TRUE) {
        int counter;    //for checking how often SIGUSR1 arrives
        counter++;
        
        signal( SIGUSR1, childHandler );
        
    }//end if
    
    // Set up a for() loop to generate and test random addresses
    // 1000 should be replaced with ULONG_MAX later
    for (numOfEval = 0; numOfEval < ULONG_MAX; numOfEval++) {
        
        // set a setjmp to remember context of the beginning of the loop
        int jumpHere;
        jumpHere = sigsetjmp( envBuf, 1 );
        
        if ( jumpHere) {
            numOfEval++;
        }//end if
        
        // call rand() and store return value in an int * variable
        int tempRandNum = rand()%ULONG_MAX + 1;
        int *randNum = &tempRandNum;
        
        // copy pointer address to int variable
        //int copyRandNum = *randNum;
        
        printf("%d", randNum[numOfEval]);   //sanity test
        
    }//end for
    
    return 0;

    
}//end main
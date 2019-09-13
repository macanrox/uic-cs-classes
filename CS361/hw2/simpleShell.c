/*
 
 CS 361: HW #2
 
 Author: Bresia Prudente
 ACCC ID: bprude2
 
 */

#include "header.h"

int main ( void ){
    
    // Print author credentials
    printf("\nAuthor: Bresia Prudente\n"
           "ACCC ID: bprude2\n\n");
    
    // Command prompt and read command line from user
    char *token, *userPrompt = "Shell $ ";
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
        
        //Prompt program to exit
        if ( strcmp(cmd[0], "exit") == 0 ){
            
            printf("\nProgram exiting...\n\n");
            break;
            
        }//end if
        
        // Fork off child
        pid_t pid;
        int status = 0, option = 0;
        struct rusage rusage;
        pid = fork();
        int exit_status;
        
        // Child things
        if ( pid < 0 ) {
            
            perror("fork");
            exit(1);
            
        }//end if
        else if ( pid == 0 ) {
            
            printf("Child Process\n");
            printf("Chid PID: %d\n\n", pid);
            execvp( cmd[0], cmd);
            if ( execvp(cmd[0], cmd) < 0 ) {
                
                printf("Program failed to execute!\n");
                exit(0);
                
            }//end if
            
        }//end else if
        // Parent things
        else {
            
            // Parent status
            printf("Parent Process\n");
            printf("Parent PID: %d\n\n", pid);
            wait4(pid, &status, option, &rusage);
            
            // Check the child status
            if ( WIFEXITED(status) ) {
                exit_status = WEXITSTATUS( status );
                printf("\nChild returned - %d\n", WEXITSTATUS(status));
            }//end if
            else {
                if ( WIFSIGNALED(status) ) {
                    printf("\nChild exited by signal - %d\n", WTERMSIG(status));
                }//end if
            }//end else
            
            printf("Parent after wait.\n");
            printf("Number of page faults: %ld\n\n", rusage.ru_majflt);

        }//end else
        
    }//end while
    
    return 0;
    
}//end main
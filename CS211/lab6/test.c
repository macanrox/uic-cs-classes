/*
 Lab 6
 Author: Bresia Anne Prudente
 netID:  bprude2
 Class:  CS 211
 Lab:    11-12:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define CODELENGTH 4
#define NUMSYMBOLS 6

/*  Create 3 functions:
    
    1) Generate random code for user to guess ( 4 values )
    2) Grab code guesses from user
    3) Compare the guess with the randomized code
 
 */


void genCode (int code[], int randGen);
void getGuess (int code[], ...);
int checkGuess (int code[], int guess[], ...);


int main( int argc, char **argv )
{
    

    /* Debug */
    int debugMode;
    
    if ( debugMode == TRUE )
    {
        printf (" Debugging Information \n");
    }    
    
}//end main

/* Generate code here */
void genCode (int code[], int randGen)
{
    
    /* Initialize random seed */
    srand( time( NULL ) );
    
    /* Generate random numbers */
    randGen = rand() % 6;
    
    printf( "%d", randGen );
    
}//end void genCode

/*  Grab code guesses from user 
 
 If guess isn't correct:
 -> provide the user feedback 
 -> allow another chance to guess.
 
 If guess is correct: 
 -> congratulate 
 -> include number of guesses it took to reach correct code 
 -> quit program.
 
 */
void getGuess (int guess[], ...)
{
    
}//end void getGuess

/* Compare user guesses with code generator */
int checkGuess (int code[], int guess[], ...)
{
    
}//end int checkGuess
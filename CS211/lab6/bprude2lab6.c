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

/************************************************
	Create 3 functions:

    1) Generate random code for user to guess ( 4 values )
    2) Grab code guesses from user
    3) Compare the guesses with randomized code

 ************************************************/

void genCode (int code[]);
void getGuess (int code[]);
int checkGuess (int code[], int guess[]);


int main( int argc, char **argv )
{
	/*	Set up the code for debugging.
		This allows the user to see the code.
	*/
	int newCode[CODELENGTH];
	genCode(newCode);

	/* If there's 2 inputs, then there's a flag. */
	if( argc == 2 )
	{
		int debugMode;

		printf( "Debugging Information.\n"
				"The code is: " );

		/* Display the code. */
		for( debugMode=0; debugMode<CODELENGTH; debugMode++ )
		{
			printf( " %d", newCode[debugMode]);
		}

	}

	/*	Get user guesses.
		Display an error message if the user inputs a value
		that's not between 1-6.
	*/
	printf( "\nGuess the code by entering 4 numbers between 1-6.\n"
			"	Example: 5 3 2 6\n"
			"You may use repeating variables if you wish.\n");

	int newGuess[CODELENGTH];
	getGuess(newGuess);

	/* Check validity of guess. */
	int g, state;
	state = FALSE;

	for( g=0; g<CODELENGTH; g++ )
	{
		if( newGuess[g] > 1 && newGuess[g] < 7 )
		{
			state = TRUE;
		}
		else
		{
			state = FALSE;
		}
	}

	/*	If the guess is valid, then continue.
		If invalid, prompt error message.
		Otherwise, pass the code and guess to checkGuess for comparison.
	*/
	if( state == FALSE )
	{
		printf( "Invalid guess! Your guess must be a number between 1-6.\n"
				"Please try again.");
	}
	else
	{
		checkGuess( newCode, newGuess );
	}

}//end main

/***********************************************
	Generate code here.
	Each code contains 4 randomized integers.
	Each unique integers should be between 1-6
************************************************/
void genCode (int code[])
{
	/* Initialize random seed */
    srand( time( NULL ) );

    /* Declare and initialize variables */
	int i;

    for( i=0; i<CODELENGTH; i++ )
    {
		/* Generate random numbers between 1-6 */
    	int randNumbers = rand() % NUMSYMBOLS + 1;

    	/* Save random numbers to an array and print */
		code[i] = randNumbers;
	}
	//printf( "\nCode has been generated.\n" );

}//end void genCode

/************************************************
	Grab code guesses from user
*************************************************/
void getGuess (int guess[])
{
	int j;

	for( j=0; j<CODELENGTH; j++ )
	{
		/* Grabs user input and store the information */
		scanf( "%d", &guess[j] );

	}//end for( j=0

}//end void getGuess

/************************************************
	Compare user guesses with code generator

 	If guess isn't correct:
 	-> provide the user feedback
 	-> allow another chance to guess.

 	If guess is correct:
 	-> congratulate
 	-> include number of guesses it took to reach correct code
 	-> quit program.
************************************************/
int checkGuess (int code[], int guess[])
{
	int x, y, match, nearMatch, numGuess, newGuess[CODELENGTH];
	match = nearMatch = numGuess = 0;

	for( y=0; y<CODELENGTH; y++ )
	{
		if( code[y] == guess[y] )
		{
			match++;
		}
	}

	/*	If user successfully solves the puzzle,
		congratulate, count guesses and exit program.
	*/
	if( match == CODELENGTH )
	{
		printf( "Congratulations!\n"
		 		"It has taken you %d guesses to solve the code.", numGuess);

		exit(-1);

	}//end if (match...

	else
	{
		for( x=0; x<CODELENGTH; x++ )
		{
			printf( "Your guess ");

			if( code[x] == guess[x] )
			{
				match++;
			}

    		/* Use a counter to find the number of near matches*/
			if( code[x] != guess[x] &&
		  	   (code[x] == guess[x + 1] ||
		    	code[x] == guess[x + 2] ||
		  		code[x] == guess[x + 3] ||
		  		code[x] == guess[x - 1] ||
		  		code[x] == guess[x - 2] ||
		  		code[x] == guess[x - 3] )
		 	  )

			{
				nearMatch++;
			}

			/*	If the user incorrectly guesses, give another chance.
				Also keep track of number of guesses
			*/
			printf( "is incorrect. Please try again!\n"
					"Match: %d\n"
					"Near match: %d\n", match, nearMatch );

			getGuess(guess);

			numGuess++;

			checkGuess( code, guess );


		}//end for( x=0...

	}//end else

}//end int checkGuess

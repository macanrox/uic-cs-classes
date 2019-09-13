/*
 Lab 7:  Stack Calculator
 Author: Bresia Anne Prudente
 netID:  bprude2
 Class:  CS 211
 Lab:    11-12:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define STACKSIZE 10

/************************************************
    Stack has 5 operations:

    1) push
        -> value is added to array starting from bottom-most
           position of the array
    2) pop
        -> most recent value (highest position in array) is
           removed from the stack
    3) top
        -> returns the top-most value in the array

    4) isEmpty
        -> checks if the stack is empty
        -> pop or top cannot be performed if this is true
        -> is true if there no values else it's false

    5) isFull
        -> checks if the array has no open positions
        -> push cannot be performed if this is true

				*************

    User can enter:
    integer value
        -> negative or position integer is pushed into stack
            -> if stack is full, give error message and
               ignore input value

    'q'
    	-> quits the program

    'c'
        -> clears all values in stack

    '='
        -> display top value on stack (after performing operation)

    arithmetic operation
        -> take top 2 values, perform operation and push result onto stack
        -> if there are less than 2 values, give error and ignore input
           also put stack back in same state prior to entering input
        -> ** order of operands is important ** !!!

    Other info:
    When values are pushed, increment tos
    When values are popped, decrement tos

 ************************************************/

/* stack function signatures */
void push (int stack[], int *tos, int val);
void pop (int stack[], int *tos);

int top (int stack[], int tos);
int isFull (int tos); /* returns a boolean value */
int isEmpty (int tos); /* returns a boolean value */

int main( int argc, char **argv )
{

    int newStack[STACKSIZE];
    int tosPosition = -1;	// initialized to -1 indicates empty stack
    int x, input;

	/* If there's 2 inputs, then there's a flag. */
	if( argc == 2 )
	{
		int debugMode;

		printf( "Debugging Information.\n");

		/* Display the stack contents. */
		for( debugMode=0; debugMode<STACKSIZE; debugMode++ )
		{
			printf( "%d", newStack[debugMode] );
		}

	}

	while( strcmp( argv[0], "q" ) != '\0' )
	{

		printf( "\nEnter a value or an operand. There must be at least two values and an operand."
				"\nType in '=' to calculate your desired values."
				"\nYou can quit the program by typing in 'q'."
				"\nIf you wish to clear a stack that's full, type in 'c'."
				"\n\n");

		push( newStack, &tosPosition, x );

		pop( newStack, &tosPosition );

		top( newStack, tosPosition );

		if( !strcmp( argv[0], "q" ) )
		{
			printf( "\nYou chose to quit the program." );
			exit(-1);
		}
		else if( !strcmp( argv[0], "c" ) )
		{
			newStack[STACKSIZE] = newStack[-1];
		}

	}

}//end main

void push (int stack[], int *tos, int val)
{
	int i;
	*tos = -1;

	for( i=0; i<1; i++ )
	{
		scanf( "%d", &val );

		stack[STACKSIZE - *tos ] = val;
		*tos++;

	}

}//end void push

void pop (int stack[], int *tos)
{
	int j;

	for( j=0; j<1; j++ )
	{
		stack[STACKSIZE - 1];
		*tos--;
	}

}//end void pop

int top (int stack[], int tos)
{
	int x, newStack[STACKSIZE], tosPosition;

	push( newStack, &tosPosition, x );
	pop( newStack, &tosPosition );

	int k, l;
	int top = stack[0];

	for( k=0; k<STACKSIZE; k++ )
	{
		if( stack[k] > top )
		{
			top = stack[k];
		}
		return top;
	}

}//end int top

int isFull (int tos)
{
	int x, newStack[STACKSIZE], tosPosition, state;
	state = FALSE;

	push( newStack, &tosPosition, x );

	if( tos == 10 )
	{
		state = TRUE;
		printf( "The stack is full!"
				"\nPlease clear the stack or start a new program.\n");
	}
	else
	{
		state = FALSE;
	}

}//end int isFull

int isEmpty (int tos)
{
	int x, newStack[STACKSIZE], tosPosition, state;
	state = FALSE;

	pop( newStack, &tosPosition );
	top( newStack, tosPosition);

	if( tos == -1 )
	{
		state = TRUE;
		printf( "The stack is empty!"
				"\nYou must add at least 2 integers to use the pop or top function.\n");

	}
	else
	{
		state = FALSE;
	}

}//end isEmpty

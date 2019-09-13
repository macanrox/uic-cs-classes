/*
 Lab 8:  Balanced Symbol Checker
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
#define MAXCHAR 300
#define STACKSIZE 0

/************************************************

    Stack checks for symbol pairs:
        -> parentheses: ()
        -> curly braces: {}
        -> square brackets: []
        -> angle brackets: < >

 ************************************************/

/*
	Create a new struct
*/
typedef struct dynArr
{
		double *location;
		int length;
		int currentSize;

}dynArrType;

/* stack function signatures */
int getInput( char stack, int *tos );
int isFlag( char string[], char *isFlag );
void processFlag( char *stack, int *tos, char message );
void printStack( char *stack, int tos );

void push (dynArrType *a, char *stack, int *tos, int *length, double val);
void pop (char *stack, int *tos);
int isEmpty( int tos );
int isFull( int tos );
int top (char stack[], int tos);

int debugMode = FALSE;

int main( int argc, char **argv )
{
	int topOfStack = 0;
	char stack;
	char input[300];

/*
	If there's 2 inputs and is "-d", then prompt debug.
*/
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'd')
	{
		debugMode = TRUE;
		printf( "Stack is now: %s \n", &stack );
	}

	while( getInput( stack, &topOfStack ) )
	{
		printStack( &stack, topOfStack );
	}

	exit( 0 );


}//end main

/*
	Where the magic happens.
*/
int getInput( char stack, int *tos )
{
	char string[MAXCHAR];
	char flag;

	/* Print the message and get user input. */
	printf( "\nEnter any or all of the symbols: "
			"\n\nparentheses: ( )"
			"\ncurly braces: { }"
			"\nsquare brackets: [ ]"
			"\nangle brackets: < >"
			"\n\nYou can quit the program anytime by typing in 'q'."
			"\nYou may also turn on debug by typing in '-d'."
			"\n\n");
	fgets( string, MAXCHAR, stdin );

	/* If user inputs "q", then program exits. */
	if( string[0] == 'q')
	{
		exit( 0 );
	}

	/* If debugMode is prompted, update on new stack. */
	if( debugMode )
	{
		printf( "Stack is now: %s ", &stack );

	}


}//end getInput

/*
	If user input returns true, print these messages and perform operations.
*/
void processFlag( char *stack, int *tos, char message )
{
	switch( message )
	{
		case 'd':
				if( *tos == -1 )
				{
					printf( "The stack is empty, please try again."
							"\n" );
				}
				else
				{
					printf( "The stack is: %s", &stack);

				}
		case 'q':
				exit(0);
	}

	return;
}//end void processFlag

void printStack( char stack[], int tos )
{
	int i = 0;

	if( isEmpty( tos ))
	{
		printf( "The stack is balanced.\n" );
		return;
	}

	printf( "Stack is: " );
	while( i < tos )
	{
		printf( " %c ", stack[i] );
		i++;
	}

}

/*
	Check if user inputs brackets, otherwise disregard other inputs.
*/
int isBracket( char value )
{

	int returnVal = FALSE;

	switch( value )
	{
		case '{':
			returnVal = TRUE;
			break;
		case '(':
			returnVal = TRUE;
			break;
		case '[':
			returnVal = TRUE;
			break;
		case '<':
			returnVal = TRUE;
			break;
		default:
				return FALSE;

	}//end switch

	return returnVal;

}//end isBracket

/*
	If the opening brackets, match with their closing brackets
	then the stack is balanced. Otherwise, returns false.
*/
int isBracketClosed( char value )
{

	int returnVal = FALSE;

	switch( value )
	{
			case '}':
				returnVal = TRUE;
				break;
			case ')':
				returnVal = TRUE;
				break;
			case ']':
				returnVal = TRUE;
				break;
			case '>':
				returnVal = TRUE;
				break;
			default:
					return FALSE;
	}
}

/*
	Check the user input and return if true.
*/
int isFlag( char string[], char *flag )
{
	int returnVal = FALSE;

	if( strlen( string ) == 2 )
	{
		switch( string[0] )
		{
			case 'd':
					*flag = 'd';
					returnVal = TRUE;
					break;
			case 'q':
					*flag = 'q';
					returnVal = TRUE;
					break;

		}//end switch
	}//end if( strlen...

	return returnVal;

}//end isFlag

/*
	Grow the stack array if it's full.
*/
void push (dynArrType *a, char *stack, int *tos, int *length, double val)
{
	double *temp;	//new array that allocates stack size
	int i;

    if( a->currentSize >= a->length )
    {

        /* allocate new dynamic entry into larger size */
        temp = ( double * )malloc( sizeof( double )*( a->length * 2 ) );   //how big we want array to grow

		for( i=0; i<a->length; i++ )
		{
			temp[i] = a->location[i];
		}

        /*  1. Copy stack value to temp
            2. Deallocate current stack array (but keep temp array)
            3. Have stack array refer to new dynamic array
        */
        free( a->location );	//frees up space for new stack
        a->location = temp;
        a->length = a->length * 2;

    }//end if(...

	a->location[a->currentSize] - val;
	a->currentSize++;


}//end void push

/*

*/
int isEmpty( int tos )
{
	if( tos == 0 )
	{
		return TRUE;
	}

	return FALSE;
}

int isFull( int tos )
{
	if( tos == STACKSIZE )
	{
		return TRUE;
	}

	return FALSE;
}

int top( char stack[], int tos )
{
	if( isEmpty(tos) )
	{
		return TRUE;
	}

	return stack[tos];
}

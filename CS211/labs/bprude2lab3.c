/*
 Lab 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

int main( int argc, char **argv )
{
	FILE *src;
    int isFlagPresent(int argc, char **argv, char *flag);    //loops to find if certain flag is present

	/* Process the filename/s. */
	if( argc != 2 )
	{
		printf( "Usage: %s <Line Count><Character/Byte Count><Max Line Count><Input File Name>\n", argv[0] );
		exit(-1);
	}
	else
	{
		src = fopen( argv[1], "r" );

		if( src == NULL )
		{
			puts( "Could not open file, please try again.\n" );
			exit(-1);
		}
	}

	    /* Count each character, word and line. */
		int c, numLine, numWord, numChar, state;
		state = FALSE;
		numLine = numWord = numChar = 0;

		while( (c = fgetc( src )) != EOF )
		{
			++numChar;

			if( c == '\n' )
			{
				++numLine;
			}
			if( c == ' ' || c == '\n' || c == '\t' )
			{
				state = FALSE;
			}
			else if( state == FALSE )
			{
				state == TRUE;
				++numWord;
			}
	}

    /* Count each character. */
	int numLines = 0;
	int lineCount = 0;
	char c;

	while(( c = getc( src )) != EOF )
	{
		if( c == '\n')
		{
			lineCount++;
		}

		putc ( c, stdout);

		if( lineCount == numLines )
		{
			break;
		}
	}

	int x;
	while( (x = fgetc( src )) != EOF )
	{
		printf( "%c", x );
	}


		if ( isspace(c) )
		{
			c = ' ';
			putchar (c);
			i++;
			numChar++;
		}

    argv[2] = "-w";
    argv[3] = "-c";
    argv[4] = "-l";
    argv[5] = "-L";


	if( argc >= 6)
	{
	    if( strcmp( argv[1], "-w") == 0)
		{

            numLines = atoi( argv[2] );			        // # of lines at argv[2]
            src = fopen( argv[3], "r" );				// filename is at argv[3]
		}
		else
		{
            src = fopen( argv[1], "r" );			    // filename is at argv[1]
            numLines = atoi( argv[3] );			        // number of lines at argv[3]
            argv[2] = "-n";                             //-n is argv[2];
        }
	}
    fclose( src );
}

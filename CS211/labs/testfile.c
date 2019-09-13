/*
 		Lab 3
 		Author: Bresia Anne Prudente
 		netID:  bprude2
 		Class:  CS 211
 		Lab:    11-12:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 10000
#define TRUE 1
#define FALSE 0

extern void copy (char to[], char from[]);

/* copy: copy 'from' into 'to'; assume 'to' is ig enough */
void copy (char to[], char from[])
{
  int i = 0;
  while ((to[i] = from[i]) != '\0')
  {
    ++i;
  }
}//end void copy

int main( int argc, char **argv )
{
	FILE *src;
    int isFlagPresent(int argc, char **argv, char *flag);    /* Loops to find if certain flags are present. */

	/* Process the filename/s. */
	if( argc != 2 )											/* Checks to see if there are 2 entries in argv by checking argc*/
	{
		printf( "Usage: %s <Line Count><Character/Byte Count><Max Line Count><Input File Name>\n", argv[0] );
		exit(-1);
	}
	else
	{
		src = fopen( argv[1], "r" );						/* Opens up source file */

		if( src == NULL )
		{
			puts( "Could not open file, please try again.\n" );
			exit(-1);
		}
	}

	char *fileName = argv[1];		/* Grab the name of the file */

    /* Count each character, word and line. */
	int c, numLine, numWord, numChar, state;
	state = FALSE;
	numLine = numWord = numChar = 0;

 	/* Grabs longest line and sends back number of characters*/
 	int len;            	/* current line length */
 	int max;            	/* maximum length seen so far */
 	char line[MAXLINE];    		/* current input line */
 	char longest[MAXLINE]; 		/* longest line saved here */
 	len = strlen( line );
	max = strlen( longest );

	while( (c = fgetc( src )) != EOF )
	{
		++numChar;

		if( c == '\n' )
		{
			++numLine;
		}
		if( c != '\n')
		{
			++len;

		   	if (len > max)
		   	{
		    	max = len;
		   	}
		}
		if( isspace(c) )
		{
			state = FALSE;
		}
		else if( state == FALSE )
		{
			state = TRUE;
			++numWord;
		}
    }


	printf( "%d %d %d %s\n", numLine, numWord, numChar, fileName);		// to double check if this works

    argv[2] = "-w";
    argv[3] = "-c";
    argv[4] = "-l";
    argv[5] = "-L";


	if( argc >= 6)
	{
	    if( strcmp( argv[1], "-w") == 0)
		{

            int numLines = atoi( argv[2] );			        // # of lines at argv[2]
            src = fopen( argv[3], "r" );				// filename is at argv[3]
		}
		else
		{
            src = fopen( argv[1], "r" );			    // filename is at argv[1]
            int numLines = atoi( argv[3] );			        // number of lines at argv[3]
            argv[2] = "-n";                             //-n is argv[2];
        }
	}
    fclose( src );
}

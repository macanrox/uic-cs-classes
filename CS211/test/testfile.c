/*
	Lab 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main( int argc, char **argv )
{
	FILE *file;
	char b[MAX];

	/* Process the filename */
	if( argc != 2 )
	{
		printf( "Usage: %s <input file name> <output file name>\n", argv[0] );
		exit(-1);
	}
	else
	{
		file = fopen( argv[1], "r" );

		if( file == NULL )
		{
			puts( "Could not open file\n" );
			exit(-1);
		}
	}

    /* Count each character. */
	int numLines = 10;
	int lineCount = 0;
	char c;

	while(( c = getc( file )) != EOF )				       // EOF = "End Of File"
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

	/* Find how many line file has. */
	int x;
	while( (x = fgetc( file )) != EOF )
	{
		printf( "%c", x );
	}

    /* Show results. */
	if( argc == 4)
	{
	    if( strcmp( argv[1], "-n") == 0)
		{

				numLines = atoi( argv[2] );			       // # of lines at argv[2]
				file = fopen( argv[3], "r" );				// filename is at argv[3]
		}
		else
		{
				file = fopen( argv[1], "r" );			   // filename is at argv[1]
				numLines = atoi( argv[3] );			        // number of lines at argv[3]
				argv[2] = "-n";		           		   //-n is argv[2];
                }
	}
    fclose( file );
}

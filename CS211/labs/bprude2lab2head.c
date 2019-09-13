/*
	Lab 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main( int argc, char **argv )
{
	FILE *src;
	char b[MAX];

	if( argc != 2 )
	{
		printf( "Usage: %s <input file name> <output file name>\n", argv[0] );
		exit(-1);
	}
	else
	{
		src = fopen( argv[1], "r" );

		if( src == 0 )
		{
			printf( "Could not open file\n" );
		}
		else
		{
			int x;
			while(( x = fgetc(src) ) != EOF )
			{
				printf( "%c", x );
			}
			fclose(src);
		}
	}

	/* Try to open source file. */
	if( ( src = fopen( "bprude2lab2head.c", "r" )) == NULL )			//-n is argv[1]
	{
		puts( "Can't open input file." );
		exit(-1);
	}

    /* Count each character. */
	int numLines = 10;
	int lineCount = 0;
	char c;

	while(( c = getc( src )) != EOF )				       // EOF = "End Of File"
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
	while( fgetc( src ) != EOF )
	{
		puts( b );
	}

    /* Show results. */
	if( argc == 4)
	{
	    if( strcmp( argv[1], "-n") == 0)
		{

				numLines = atoi( argv[2] );			       // # of lines at argv[2]
				src = argv[3];							   // filename is at argv[3]
		}
		else
		{
				src = argv[1];			   					// filename is at argv[1]
				numLines = argv[3];			        	   // number of lines at argv[3]
				"-n" = ( argv[2] );		           		   //-n is argv[2];
                }
	}
    return 0;
}

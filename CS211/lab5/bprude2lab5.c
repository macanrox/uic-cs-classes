/*
 		Lab 5
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

int main( int argc, char **argv )
{
	/* Declare source variables */
	FILE *src;
	char file[100];

	/* Open the files, else display error message. */
    if( argc != 2 )
    {
        puts( "Specify file that you want to open." );
        scanf( "%s", &file );
        src = fopen( file, "r" );
    }
    else if( src = fopen( argv[1], "r" ))
    {
		if( src == NULL )
		{
			printf( "Unable to open file, please try again." );
			exit(-1);
		}
	}

	/* Declare and initialize variables */
	char fileInput[256][101], fileOutput[256][301], buffer[256];
	char hash = '#';
	int c, numSub, numChar, numLine, numWord, state;
	c = numSub = numChar = 0;

	//* Store and print data from strings *//

	while( fgets( buffer, 256, src ) )
	{
		strcpy( fileInput[numChar], buffer );
		printf( "%s", fileInput);
    }

	 fclose( src );

}//end main
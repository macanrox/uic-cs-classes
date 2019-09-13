/*
 		Lab 4
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


/*
 char nounList[500][41];         // gives us 500 words that are 40 characters long
                                // can't have nounList[500][40] because 40 is a NULL character
 
srand( time(NULL));             // initialize random seed

char buf;
char bufferSize;

fgets( buf,bufferSize, src )
strcpy( nounList[1], buf )

char *getNoun( char[500][41], int nounSite);
char nL[][41];
char *n[41];

return nL(i);
 */

int main( int argc, char **argv )
{
    
    FILE *src;
    
    if( (src = fopen( argv[1], "r" )) == NULL )
    {
        puts( "Could not open file, please try again.\n" );
        exit(-1);
    }
    
    /* Grab the name of the file */
    char *fileName = argv[1];
    
    /* Count each character, word and line */
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
    
    
    char noun[500][41];
    char verb[500][41];
    char adj[500][41];
    char art[500][41];    
    int i, j;
    
    while( c != EOF )
    {
        for( i = 0; i < 500; i++)
        {
            for( j = 0; j < 41; j++ )
            {
                noun[i][j] = fgetc( src );
            }//end for( j...
        }//end for( i...
    }//end while( c...
    
    printf( "%c", noun[i][j]);
    
}//end main
 
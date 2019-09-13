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
#define LINE_LENGTH 20

int main( int argc, char **argv )
{
	/* Declare source variables */
	FILE *src;
    char string[100];
    
	/*  Have user open a file.
        If file name isn't given, prompt user to open a file.
    */
    if( argc != 2 && ( src = fopen( argv[1], "r" ) ) )
    {
        printf( "Usage: %s <Input File Name><Output File Name>\n", argv[0] );
		exit(-1);
    }   
    
    /* Get all the contents of the file */
    else
    {
        char *fileName = argv[LINE_LENGTH];
        fgets( fileName, LINE_LENGTH, src );
        fputs( fileName, src );
        
        printf( "%s\n", fileName );
        
	}
    
    
	/* Declare and initialize variables 
	char noun[500][41], buffer[41];
	int numArt;
	numArt  = 0;
	*/
    
	//* Store and print data from strings *//
    
	/* ARTICLE 
	while( fgets( buffer, 41, src ) )
	{
		strcpy( article[numArt], buffer );
		if (article[numArt] != '\0')
		{
			numArt++;
		}
	}    */
    
    //fclose( src );
}//end main
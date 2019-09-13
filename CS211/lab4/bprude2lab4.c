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

int main( int argc, char **argv )
{
	/* Declare source variables */
	FILE *src;
	FILE *src2;
	FILE *src3;
	FILE *src4;

	/* Open the files, else display error message. */
    if( (src = fopen( "articles.txt", "r" )) == NULL &&
    	(src2 = fopen( "adjectives.txt", "r" )) == NULL &&
    	(src3 = fopen( "nouns.txt", "r" )) == NULL &&
    	(src4 = fopen( "verbs.txt", "r" )) == NULL)
    {
        puts( "Could not open files, please try again.\n" );
        exit(-1);
    }
    else
    {
		src = fopen( "articles.txt", "r" );
		src2 = fopen( "adjectives.txt", "r" );
		src3 = fopen( "nouns.txt", "r" );
		src4 = fopen( "verbs.txt", "r" );
	}

	/* Declare and initialize variables */
	char noun[500][41], verb[500][41], adjective[500][41], article[500][41], buffer[41];
	int numArt, numAdj, numNoun, numVerb;
	numArt = numAdj = numNoun = numVerb = 0;
	srand( time(NULL) );      // initialize random seed

	//* Store and print data from strings *//

	/* ARTICLE */
	while( fgets( buffer, 41, src ) != NULL )
	{
		strcpy( article[numArt], buffer );
		numArt++;
	}

    /* ADJECTIVE */
	/*	Chances of 0-7 adjectives being chosen
		0 = 20%
		1 = 40%
		2 = 20%
		3 = 10%
		4 = 5%
		5 = 2%
		6 = 2%
		7 = 1%
	*/
	while( fgets( buffer, 41, src2 ) != NULL )
	{
		strcpy( adjective[numAdj], buffer );
		numAdj++;
	}

	/* NOUN */
	while( fgets( buffer, 41, src3 ) != NULL )
	{
		strcpy( noun[numNoun], buffer );
		numNoun++;
	}

	/* VERB */
	while( fgets( buffer, 41, src4 ) != NULL )
	{
		strcpy( verb[numVerb], buffer );
		numVerb++;

	}

	/* 	Generate two sentence forms  which
		each have a 50% chance of displaying.
	*/

	/* Sentence forms have a max of 41 characters */
	char sentenceForm1[41];
	char sentenceForm2[41];

	srand( time( NULL ) );
	int r = rand() % 100;

	/* Default one-time sentence generator */
	int i;
	for( i = 0; i < 1; i++)
	{
		srand( time( NULL ) );
		int sentence = rand() % 2;

		/* Execute Sentence Form #1 */
		if( sentence == 0 )
		{
			sprintf( sentenceForm1, "%s %s %s %s.",
					article[ rand() % numArt ],
					adjective[ rand() % numAdj ],
					noun[ rand() % numNoun ],
					verb[ rand() % numVerb ]
			 	   );

			sentenceForm1[0] = toupper( sentenceForm1[0] );		//capitalize the first letter
			puts( sentenceForm1 );		//append result into new string
		}
		else
		/* Execute Sentence Form #2 */
		{
			sprintf( sentenceForm2, "%s %s %s %s %s %s %s.",
							article[ rand() % numArt ],
							adjective[ rand() % numAdj ],
							noun[ rand() % numNoun ],
							verb[ rand() % numVerb ],
							article[ rand() % numArt ],
							adjective[ rand() % numAdj ],
							noun[ rand() % numNoun ]
			   	  );//end sprintf

			sentenceForm2[0] = toupper( sentenceForm2[0] );
			puts( sentenceForm2 );
		}//end else...
	}//end for( i = 0...

}//end main
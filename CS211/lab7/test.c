/*
 Lab 9: Maze Solver
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

/*
	mazeStruct creates the size of the maze
*/
typedef struct mazeStruct
{
	char arr[31][31];  /* allows for a maze of size 30x30 */
	int xsize, ysize;
	int xstart, ystart;
	int xend, yend;
	
} maze;

/*
	Where the magic happens.
*/

int main (int argc, char **argv)
{
	maze m1;
	
	int xpos, ypos;
	int i,j;
	
	FILE *src;
	
	/* 
		Check if the user enters 2 commands,
		otherwise display an error and exit.
	*/
	if(argc != 2) 
	{
		printf("Usage: %s <input file name>\n", argv[0]);
		exit(-1);
	}
	
	/* Try to open the input file. */
	if ( ( src = fopen( argv[1], "r" )) == NULL )
	{
		puts( "Can't open input file." );
		exit(-1);
	}
	
	/* read in the size, starting and ending positions in the maze */
	fscanf (src, "%d %d", &m1.xsize, &m1.ysize);
	fscanf (src, "%d %d", &m1.xstart, &m1.ystart);
	fscanf (src, "%d %d", &m1.xend, &m1.yend);
	
	/* print them out to verify the input */
	printf ("size: %d, %d\n", m1.xsize, m1.ysize);
	printf ("start: %d, %d\n", m1.xstart, m1.ystart);
	printf ("end: %d, %d\n", m1.xend, m1.yend);
	
	/* initialize the maze to empty */
	for (i = 0; i < m1.xsize+2; i++)
	{
		for (j = 0; j < m1.ysize+2; j++)
		{
			m1.arr[i][j] = '.';
		}
	}
	
	/* mark the borders of the maze with *'s */
	for (i=0; i < m1.xsize+2; i++)
    {
		m1.arr[i][0] = '*';
		m1.arr[i][m1.ysize+1] = '*';
    }
	
	for (i=0; i < m1.ysize+2; i++)
    {
		m1.arr[0][i] = '*';
		m1.arr[m1.xsize+1][i] = '*';
    }
	
	/* mark the starting and ending positions in the maze */
	m1.arr[m1.xstart][m1.ystart] = 's';
	m1.arr[m1.xend][m1.yend] = 'e';
	
	/* mark the blocked positions in the maze with *'s */
	while (fscanf (src, "%d %d", &xpos, &ypos) != EOF)
    {
		m1.arr[xpos][ypos] = '*';
    }
	
	/* print out the initial maze */
	for (i = 0; i < m1.xsize+2; i++)
    {
		for (j = 0; j < m1.ysize+2; j++)
       printf ("%c", m1.arr[i][j]);
     printf("\n");
    }

}//end main

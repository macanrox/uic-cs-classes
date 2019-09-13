/*
 Lab 9: Maze Solver
 Author: Bresia Anne Prudente
 netID:  bprude2
 Class:  CS 211
 Lab:    11-12:50
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int debugMode = FALSE;

/***************************************************************************
 The blocked positions and the edges of the maze are filled in with *'s. 
 The start position is filled in with a 's'. 
 The end position in filled in with a 'e'. 
 The other positions are filled in with periods.
 ***************************************************************************/

/*
 mazeStruct defines the maze size
 */
typedef struct mazeStruct
{
	char arr[31][31];  /* allows for a maze of size 30x30 */
	int xsize, ysize;
	int xstart, ystart;
	int xend, yend;
	
} maze;

typedef struct nodeStruct
{
	int val;
	struct nodeStruct *next;
	int yPos;
	int xPos;
	
} node;

typedef node* nodePtr;

void push( nodePtr *head, int v );
void pop( node **head, int *sx, int *sy );
void f1( int *p );

int top( node *head );
int isEmpty( node *head );

/********************************************
 MAIN
 *******************************************/

int main (int argc, char **argv)
{
	
	nodePtr head1 = NULL;
	node* head2 = NULL;
	int x;
	
	f1( &x );
	push (&head1, 3);
	push (&head1, 5);
	push (&head1, 7);
	
	maze m1;
	
	int xpos, ypos;
	int i,j;
	
	FILE *src;
	
	/* Check if the user input 2 command line arguments, otherwise display an error */
	if(argc != 2) 
	{
		printf("Usage: %s <input file name>\n", argv[0]);
		exit(-1);
	}
	
	/* Check if the user calls for debugging. */
	if ( debugMode == TRUE )
	{
		printf (" The stack size is: %d ", head1 );
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
		{
			printf ("%c", m1.arr[i][j]);
		}
		
		printf("\n");
    }
	
}//end main

/********************************************
 FUNCTIONS
 *******************************************/

void f1( int *p )
{
	*p = *p + 1;
}

/*
 PUSH function adds the values into an array.
 */
void push( nodePtr *head, int v)
{
	nodePtr temp;
	temp = (nodePtr) malloc ( sizeof( node ) );
	temp -> val = v;
	temp -> next = *head;
	*head = temp;
}

/*
 POPS function gets rid of the values in the array.
 */
void pop( node **head, int *sx, int *sy )
{
	
	node *temp,*temp2;
	
	temp = *head;
	*head = temp->next;
	temp2 = *head;
	
	*sx = temp2->xPos;
	*sy = temp2->yPos;
	
	/* Clear memory */
	free(temp);
	free(temp2);
}

/*
 TOP function returns the most recent value in the array.
 */
int top (node *head)
{
	return head->val;
}

/*
 ISEMPTY returns a boolean value if the array is empty.
 */
int isEmpty (node *head) 
{
	int isEmpty = FALSE;
	if ( head == NULL )
	{
		isEmpty = TRUE;
	}
	
	return isEmpty;
}




/*
	FINAL:	10:30 - 12:30
	Author: Bresia Anne Prudente
	netID:	bprude2
	Class:	CS 211
 */

#include "convert.c"

/******************************************************
							MAIN
 ******************************************************/
int main( int argc, char **argv )
{
	while( 0 )
	{
		char infix[20], postfix[20];
	
		printf("Enter the infix string: \n");
		gets(infix);
		
		/* Check if the input contains 'q'
		   else proceed with conversion */
		if( infix == "q" )
		{
			printf("Quitting program.\n");
			exit(0);
		}
		else
		{
			convertTo(infix, postfix);
			printf("The postfix string is: \n");
			puts(postfix);
			getch();
		}
	}
	
}//end main

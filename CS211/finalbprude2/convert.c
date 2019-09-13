/*
	FINAL:	10:30 - 12:30
	Author: Bresia Anne Prudente
	netID:	bprude2
	Class:	CS 211
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

/******************************************************
						FUNCTIONS
 ******************************************************/

char stack[MAX];
int top = -1;
char pop();
void push(char item);

int output(char c)
{
	switch(c)
	{
		case '+':
			;
		case '-':
			return 2;
			break;
		case '*':
			;
		case '/':
			return 4;
			break;
		case '^':
			;
		case '$':
			return 6;
			break;
		case '(':
			;
		case ')':
			;
	}
}

int isOperator(char c)
{
	switch(c)
	{
		case '+':
			;
		case '-':
			;
		case '*':
			;
		case '/':
			;
		case '^':
			;
		case '(':
			;
		case ')':
			return 1;
			break;
		default:
			return 0;
	}
}

void convertTo( char infix[], char postfix[] )
{
	int x,y,c = 0;
	
	for( x=0; x<strlen(infix); x++ )
	{
		c = infix[x];
		
		if( isOperator(c) == 0 )
		{
			postfix[y] = c;
			y++;
		}
		else
		{
			if( c == '(' )
			{
				push(c);
			}
			/* If it ends with an ')' then pop out '(' */
			else if( c == ')' )
			{
				while( stack[top] != '(' )
				{
					postfix[y] = pop();
					y++;
				}
				pop();
			}
			else
			{
				if( output(c) > output( stack[top] ))
				{
					push(c);
				}
				else
				{
					while( output(c) <= output( stack[top] ))
					{
						postfix[y] = pop();
						y++;
					}//end while( output...
					push(c);
					
				}//end else
			}//end else
		}//end else
	}//end for( x...

}//end void convertTo

void push(char value)
{
	top++;
	stack[top] = value;
}//end void push

char pop()
{
	char s;
	s = stack[top];
	top--;
	
	return s;
}//end char pop


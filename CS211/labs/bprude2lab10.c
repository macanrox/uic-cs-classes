/*
 Lab 10: Recursion
 Author: Bresia Anne Prudente
 netID:  bprude2
 Class:  CS 211
 Lab:    11-12:50
 */

/*
 
 Program will implement following recursive algorithms:
 
 -> factorial
 -> fibonacci
 -> isPrime
 -> Greatest Common Divisor (Using Dijkstra's Algorithm)
 -> poweronentiation
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

int debugMode = FALSE;

int factorial( int n );
int helpFibonacci( int n, int k, int fibk, int fibk1 );
int fibonacci( int n );
bool factorInRange( int m, int n );
bool isPrime( int n );
int gcd( int m, int n );
int power( int m, int n );

/***************************************************
						MAIN
 **************************************************/
int main (int argc, char **argv)
{	
	
	int entry;
	
	while( 1 )
	{
		/* If there's 2 inputs, then there's a flag */
		if( argc == 2 ) 
		{
			debugMode = TRUE;
			printf("\nDebugging Information.\n");
		}
		
		/* Print message and prompt the user for value */
		printf("\nWhich of the recursive algorithms would you like to use?\n"
			   "Enter a value:\n\n"
			   "0 Exit Program\n"
			   "1 Factorial\n"
			   "2 Fibonacci\n"
			   "3 isPrime\n"
			   "4 Greatest Common Divisor (Using Dijkstra's Algorithm)\n"
			   "5 Exponentiation\n");
		
		printf("\nChoose a choice from above: \n");
	
		scanf( "%d", &entry );
	
		/* If the user inputs 0, exit the program
		   If the user inputs 1-5, then prompt the user for the proper number of inputs
		 */
	
		switch( entry )
		{
			case 0:
			{
				printf("Quitting program.\n");
				exit( -1 );
			}
			case 1:
			{
				int value, result;
				
				if( debugMode = TRUE )
				{
					printf("\nfactorial( %d )\n\n", value);
				}
				
				printf("Enter a single integer: ");
				scanf("%d", &value);
				
				if( debugMode = TRUE )
				{
					int temp;
					printf("\n");
					for( temp=value; temp>=0; temp-- )
					{
						printf("factorial( %d ) = %d\n", temp, temp);
					}
					printf("\n");
				}
				
				result = factorial( value );
				printf("The answer is: %d\n", result);
				
				break;
			}
			case 2:
			{
				int value, result;
				printf("Enter a single integer: ");
				scanf("%d", &value);
				
				result = fibonacci( value );
				printf("The answer is: %d\n", result);
				
				break;
			}
			case 3:
			{
				int value, result;
				printf("Enter a single integer: ");
				scanf("%d", &value);
				 
				result = isPrime( value );
				if( result == 1 )
				{
					printf("The answer is a prime number.\n");
				}
				else
				{
					printf("The answer is not a prime number.\n");
				}
				
				break;
			}	
			case 4:
			{
				int v1, v2, result;
				printf("Enter 2 integers with spaces\n"
					   "   Example: 5 6\n");
				scanf( "%d %d", &v1, &v2 );
				
				result = gcd( v1, v2 );
				printf("The greatest common denominator is: %d\n", result);
				
				break;
			}
			case 5:
			{
				int base, exponent, result;
				printf("Enter the base and exponent with spaces\n"
					   "   Example: 5 6\n");
				scanf( "%d %d", &base, &exponent);
				result = power( base, exponent );
				
				printf("The answer is: %d\n", result);
				break;
			}
			default:
			{
				printf("Invalid value! It must be a value between 0-5.\n");
				break;
			}

			
		}//end switch
	}//end while

	
}//end main

/***************************************************
					FUNCTIONS 
 **************************************************/

int factorial( int n )
{
	
	if( n == 0 )
	{
		return 1;
	}
	else
	{
		return( n * factorial( n-1 ));
	}

	
}//end int factorial

int helpFibonacci( int n, int k, int fibk, int fibk1 )
{
	
	if( n == k )
	{
		return fibk;
	}
	else 
	{
		return helpFibonacci( n, k+1, fibk+fibk1, fibk );
	}

	
}//end int helpFibonacci

int fibonacci( int n )
{
	
	if( n <= 1 )
	{
		return n;
	}
	else
	{
		return ( helpFibonacci(n, 1, 1, 0 ) );
	}
	
}//end int fibonacci
			   
bool factorInRange( int k, int n )
{
	
	if( k >= n )
	{
		return FALSE;
	}
	else if(( n % k ) == 0 )
	{
		return TRUE;
	}
	else 
	{
		return factorInRange( k+1, n );
	}
	
}//end bool factorInRange
			   
bool isPrime( int n )
{
	
	return ( ( n > 1 ) && !factorInRange( 2, n ) );
	
}//end bool isPrime

int gcd( int m, int n )
{
	
	if( m == n )
	{
		return m;
	}
	else if( m > n )
	{
		return gcd( m-n, n );
	}
	else
	{
		return gcd( m, n-m );
	}

	
}//end int gcd

int power( int m, int n )
{
	
	if( m == 0 )
	{
		return 0;
	}
	else if( n == 0 )
	{
		return 1;
	}
	else if( n > 0 )
	{
		return( m * power( m, n-1 ) );
	}
	else
	{
		return ( ( 1/m ) * power( m, n+1 ) );
	}
	
}//end int power

			  





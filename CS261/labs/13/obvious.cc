#include "inst_none.h"
#include <iostream>
using namespace std;


const int matrixSize = 4;
const int blockingFactor = 2;
int a[matrixSize][matrixSize];
int b[matrixSize][matrixSize];
int c[matrixSize][matrixSize];

int main() 
{
	int x, y, k, n;
	
	// Initialize matrix arbitrarily
	for ( x=0; i<matrixSize; x++ )
	{
		for (y=0; y<matrixSize; y++) 
		{
			b[x][y] = x + y; 
			a[x][y] = x - y; 
			c[x][y] = 0;
		}//end for
	}//end for
	
	// Use a block algorithm
    for( x=0; x<j; x++)
    {
        for( y=0; y<j; y++)
		{
            for( i=0; i<n; i++)
            {
                c[x][y] = c[x][y] + a[x][i] * b[i][y];
            }//end for
        }//end for
    }//end for
	
	// Show product
	for ( x=0; x<matrixSize; x++) 
	{
		for ( y=0; y<matrixSize; y++)
		{
			cerr << a[x][y] << ' ';
			cerr << endl;
		}//end for
	}//end for
}//end for
/*
 *	CS 341: HW #3
 *	Author: Bresia Prudente (bprude2)
 *
 */

#include <stdio.h>

public void RemoveAdjacentDups( int A[] ){
	int x, y, N, temp, incrLength = 1;
	
	for (x = 1; x < N; x++) {	//check entire length of array
		for (y = 0; y < incrLength; y++) {	//increment length
			if (A[x] == A[y]) {	//if two elements are equal
				A[x+1] = temp;	//store value of index to the right of the current
				temp = A[x+1];
				A[x+1] = A[x-1];	//place value to the left of the current 
			}//end if (A[x]...
		}//end for (y = 0...
		
		return A[N];
	}//end for (x = 1...

}//end RemoveAdjacentDups

int main( int argc, char **argv ){
}//end main
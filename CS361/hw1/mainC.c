/* HW #1
 * Author: Bresia Prudente (bprude2)
 */

#include "func2C.c"
#include <stdio.h>
#define N 17    //set value, 10+(last non-zero digit of UIN)

// <type1> is char
// <type2> is float
// <type3> is float
// <type4> is double

//////////////////////////
// Global declarations //
////////////////////////

char mainCHello[] = "Hello", *mainCWorld = "World";

char mainCGlobal = N, mainCGlobalArray[N] = {N}, *mainCGlobalPtr = &mainCGlobal,
mainCInitGlobal = N, mainCInitGlobalArray[N] = {N}, *mainCInitGlobalPtr = &mainCInitGlobal;

static float mainCStaticGlobal = N, mainCStaticGlobalArray[N] = {N},
*mainCStaticGlobalPtr, mainCStaticInitGlobal = N,
mainCStaticInitGlobalArray[N] = {N}, *mainCStaticInitGlobalPtr = &mainCStaticInitGlobal;

////////////////
// Functions //
//////////////

// All functions print out the values of "hello" and "world"
// followed by "from <func>" where <func> is the name of the function

double func1C( char func1C_arg1, char * func1C_arg2 ){

	//Declare local variables
	float func1CLocal = N, func1CLocalArray[N] = {N}, * func1CLocalPtr = &func1CLocal,
    func1CInitLocal = N, func1CInitLocalArray[N] = {N}, * func1CInitLocalPtr = & func1CInitLocal;

	static double func1CStaticLocal = N, func1CStaticLocalArray[N] = {N}, 
	*func1CStaticLocalPtr = &func1CStaticLocal, func1CStaticInitLocal = N,
    func1CStaticInitLocalArray[N] = {N}, *func1CStaticInitLocalPtr = &func1CStaticInitLocal;
	
	//Print out the value of "hello" and "world" in main
	int i = 0;
	printf("Value of Hello is: %d from func1C.\n", mainCHello[i]);
	printf("Value of World is: %d from func1C.\n", *mainCWorld);
    
    //Add total of func1C
    int j, k;
    float func1CTotal, sumFunc1CLocal, sumFunc1CInitLocal = 0;
    for (j = 0; j < N; j++) {
        sumFunc1CInitLocal += func1CInitLocalArray[j];
        sumFunc1CLocal += func1CLocalArray[j];
    }//end for
    
    double sumFunc1CStaticLocal, sumFunc1CStaticInitLocal = 0;
    for (k = 0; k < N; k++) {
        sumFunc1CStaticLocal += func1CLocalArray[k];
        sumFunc1CStaticInitLocal += func1CStaticInitLocalArray[k];
    }//end for
    
    func1CTotal = func1CLocal + sumFunc1CLocal + *func1CLocalPtr + func1CInitLocal + sumFunc1CInitLocal + *func1CInitLocalPtr + func1CStaticLocal + sumFunc1CStaticLocal + *func1CStaticLocalPtr + func1CStaticInitLocal + sumFunc1CStaticInitLocal + *func1CStaticInitLocalPtr;
    
    return func1CTotal;

}//end double func1C

// Main prints the total it calculates.
// Only includes results of func1 and func2 in its total
int main( int argc, char **argv ){

	//Declare local variables
	float mainLocal = N, mainLocalArray[N] = {N}, * mainLocalPtr = &mainLocal, mainInitLocal = N,
	mainInitLocalArray[N] = {N}, * mainInitLocalPtr = & mainInitLocal;

	static double mainStaticLocal = N, mainStaticLocalArray[N] = {N},
    * mainStaticLocalPtr = &mainStaticLocal, mainStaticInitLocal = N,
    mainStaticInitLocalArray[N] = {N}, * mainStaticInitLocalPtr = & mainStaticInitLocal;
	
	//Print out user information
	printf("\nAuthor: Bresia Prudente\nACCC username: bprude2\n\n");

	//Print out the value of "hello" and "world" in main
	int i = 0;
	printf("Value of Hello is: %d from main.\n", mainCHello[i]);
	printf("Value of World is: %d from main.\n", *mainCWorld);

	//Call func1C and func2C
	double x, y, TOTAL = 0;
	x = func1C( mainCGlobal, mainCGlobalPtr );
	y = func2C( mainCGlobal, mainCGlobalPtr );

	//Now calculate both func1 and func2 and print their results.
	TOTAL = x+y;
	printf("\nResult of func1C and func2C is: %f.\n\n", TOTAL);
    
    return 0;


}//end main

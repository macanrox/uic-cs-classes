/* HW #1
 * Author: Bresia Prudente (bprude2)
 */

#include <stdio.h>
#define N 17    //set value, 10+(last non-zero digit of UIN)

//////////////////////////
// Global declarations //
////////////////////////

char func2CHello[] = "Hello", * func2CWorld = "World";

char func2CGlobal = N, func2CGlobalArray[N] = {N}, *func2CGlobalPtr = &func2CGlobal, func2CInitGlobal = N, 
func2CInitGlobalArray[N] = {N}, *func2CInitGlobalPtr = &func2CInitGlobal;

static float func2CStaticGlobal = N, func2CStaticGlobalArray[N] = {N}, *func2CStaticGlobalPtr = &func2CStaticGlobal, 
func2CStaticInitGlobal =  N, func2CStaticInitGlobalArray[N] = {N}, 
*func2CStaticInitGlobalPtr = &func2CStaticInitGlobal;

////////////////
// Functions //
//////////////

// All functions print the values of "hello" and "world"
// followed by "from <func>" where <func> is the name of the function.

//func3 is a static function that gets called into func2
static double func3C( char func3C_arg1, char * func3C_arg2 ){
	
	float func3CLocal = N, func3CLocalArray[N] = {N}, *func3CLocalPtr = &func3CLocal, func3CInitLocal = N,
	func3CInitLocalArray[N] = {N}, *func3CInitLocalPtr = &func3CInitLocal;
	
	static double func3CStaticLocal = N, func3CStaticLocalArray[N] = {N}, *func3CStaticLocalPtr = &func3CStaticLocal,
	func3CStaticInitLocal = N, func3CStaticInitLocalArray[N] = {N},
	*func3CStaticInitLocalPtr = &func3CStaticInitLocal;
	
	//Print out the value of "hello" and "world" in func3C
    int i = 0;
	printf("Value of Hello is: %d from func3C.\n", func2CHello[i]);
	printf("Value of World is: %d from func3C.\n", *func2CWorld);
    
    //Add all arrays
    float func3FloatTotal, sumFunc3CLocal, sumFunc3CInitLocal = 0;
    int j, k;
    for (j = 0; j < N; j++) {
        sumFunc3CLocal += func3CLocalArray[j];
        sumFunc3CInitLocal += func3CInitLocalArray[j];
    }//end for
    
    double sumFunc3CStaticLocal, sumFunc3CStaticInitLocal = 0;
    for (k = 0; k < N; k++) {
        sumFunc3CStaticLocal += func3CStaticLocalArray[k];
        sumFunc3CStaticInitLocal += func3CStaticInitLocalArray[k];
    }//end for
    
    func3FloatTotal = func3CLocal + sumFunc3CLocal+ func3CLocal + *func3CInitLocalPtr + sumFunc3CInitLocal + *func3CInitLocalPtr + func3CStaticLocal + sumFunc3CStaticLocal + *func3CStaticLocalPtr + func3CStaticInitLocal + sumFunc3CStaticInitLocal + *func3CStaticInitLocalPtr;
    
    return func3FloatTotal;
	
}//end static double func3C...

//func2 adds in the result of func3
double func2C( char func2C_arg1, char * func2C_arg2 ){

	float func2CLocal = N, func2CLocalArray[N] = {N}, *func2CLocalPtr = &func2CLocal, func2CInitLocal = N,
	func2CInitLocalArray[N] = {N}, *func2CInitLocalPtr = &func2CInitLocal;

	static double func2CStaticLocal = N, func2CStaticLocalArray[N] = {N}, *func2CStaticLocalPtr = &func2CStaticLocal,
	func2CStaticInitLocal = N, func2CStaticInitLocalArray[N] = {N},
	*func2CStaticInitLocalPtr = &func2CStaticInitLocal;

	//Print out the value of "hello" and "world" in func2C
	int a = 0;
	printf("Value of Hello is: %d from func2C.\n", func2CHello[a]);
	printf("Value of World is: %d from func2C.\n", *func2CWorld);
	
	//Add all of the arrays
	int i, j;
	//Add the sums of the float arrays
	float sumFunc2CLocal, sumFunc2CInitLocal = 0;
	for(i = 0; i < N; i++ ){
		sumFunc2CLocal += func2CLocalArray[i];
		sumFunc2CInitLocal += func2CInitLocalArray[i];
    }//end for
	
	//Add the sums of the static double arrays
	double sumFunc2CStaticLocal, sumFunc2CStaticInitLocal = 0;
    for(j = 0; j < N; j++ ){
		sumFunc2CStaticLocal += func2CStaticLocalArray[j];
		sumFunc2CStaticInitLocal += func2CStaticInitLocalArray[j];
    }
	
	//Add up all values for func2C
	float func2Total = 0;
	func2Total = func2CLocal + sumFunc2CLocal + *func2CLocalPtr + func2CInitLocal + sumFunc2CInitLocal +
	+ *func2CInitLocalPtr + func2CStaticLocal + sumFunc2CStaticLocal + *func2CStaticLocalPtr + func2CStaticInitLocal + 
	+ sumFunc2CStaticInitLocal + *func2CStaticInitLocalPtr;
		
	//Call and initialize func2C and func3C
	double func3CTotal, func2Result = 0;
	func3CTotal = func3C( func2CGlobal, &func2CGlobal );
	
	//Display the result of func2C and func3C
	func2Result = func2Total + func3CTotal;
	
	return(func2Result);

}//end double func2C...

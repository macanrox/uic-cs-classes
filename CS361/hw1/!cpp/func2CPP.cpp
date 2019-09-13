/* HW #1
 * Author: Bresia Prudente (bprude2)
 */

#include <stdio.h>
#define N 17
using namespace std;

//////////////////////////
// Global declarations //
////////////////////////

char func2CPPHello[] = "Hello", * func2CPPWorld = "World"; 

char func2CPPGlobal = N, func2CPPGlobalArray[N] = {N}, * func2CPPGlobalPtr = &func2CPPGlobal, 
func2CPPInitGlobal = N, func2CPPInitGlobalArray[N] = {N}, 
* func2CPPInitGlobalPtr = & func2CPPInitGlobal; 

static float func2CPPStaticGlobal = N, func2CPPStaticGlobalArray[N] = {N}, 
* func2CPPStaticGlobalPtr = &func2CPPStaticGlobal, func2CPPStaticInitGlobal = N, 
func2CPPStaticInitGlobalArray[N] = {N}, * func2CPPStaticInitGlobalPtr = & func2CPPStaticInitGlobal; 


////////////////
// Functions //
//////////////

double func2CPP( char func2CPP_arg1, char * func2CPP_arg2, char & func2CPP_arg3 ){

}//end double func2CPP

static double func3CPP( char func3CPP_arg1, char * func3CPP_arg2, char & func3CPP_arg3 ){

}//end static double func3CPP

double func2BCPP( char * func2BCPP_arg1, char & func2BCPP_arg2, char func2BCPP_arg3 ){

}//end double func2BCPP

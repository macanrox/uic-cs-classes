/* HW #1
 * Author: Bresia Prudente (bprude2)
 */

#include <iostream>
#define N 17
using namespace std;

//////////////////////////
// Global declarations //
////////////////////////

char mainCPPHello[] = "Hello", * mainCPPWorld = "World"; 

char mainCPPGlobal = N, mainCPPGlobalArray[N] = {N}, * mainCPPGlobalPtr = &mainCPPGlobal, mainCPPInitGlobal = N, 
mainCPPInitGlobalArray[N] = {N}, * mainCPPInitGlobalPtr = & mainCPPInitGlobal; 

static float mainCPPStaticGlobal = N, mainCPPStaticGlobalArray[N] = {N}, 
* mainCPPStaticGlobalPtr = &mainCPPStaticGlobal, mainCPPStaticInitGlobal = N, 
mainCPPStaticInitGlobalArray[N] = {N}, * mainCPPStaticInitGlobalPtr = & mainCPPStaticInitGlobal; 

////////////////
// Functions //
//////////////

double func1CPP( char func1CPP_arg1, char * func1CPP_arg2, char  & funcCPP_arg3 ){

}//end double func1CPP

int main( int argc, char ** argv ){

}//end main

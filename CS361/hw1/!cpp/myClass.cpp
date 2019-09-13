/* HW #1
 * Author: Bresia Prudente (bprude2)
 */

#include <iostream.h>
#include "myClass.h"
#define N 17
using namespace std;

//////////////////////////
// Global declarations //
////////////////////////

char MyClassHello[] = "Hello", * myClassWorld = "World"; 

char myClassGlobal = N, myClassGlobalArray[N] = {N}, * myClassGlobalPtr = &myClassGlobal, myClassInitGlobal = N, 
myClassInitGlobalArray[N] = {N}, * myClassInitGlobalPtr = & myClassInitGlobal; 

//Initialize static variables

//Constructor
MyClass::MyClass(void)
{	
}

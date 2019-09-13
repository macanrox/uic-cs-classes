/* HW #1
 * Author: Bresia Prudente (bprude2)
 */

#include <iostream>
#define N 17
using namespace std;

public:
	char myclassClass = N, myclassClassArray[N] = {N}, * myclassClassPtr = &myclassClass, myclassInitClass, 
	myclassInitClassArray[N], * myclassInitClassPtr;
	
	static float myclassStaticClass = N, myclassStaticClassArray[N] = {N}, 
	* myclassStaticClassPtr = &myclassStaticClass, myclassStaticInitClass, myclassStaticInitClassArray[N], 
	* myclassStaticInitClassPtr;

	MyClass();
	double method( char methodArg, char * methodArgPtr, char & methodArgRef );
	static double staticMethod( char staticMethodArg, char * staticMethodArgPtr, char & staticMethodArgRef );

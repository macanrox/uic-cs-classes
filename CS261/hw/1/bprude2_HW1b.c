/* CORRECTION: #include <stdio.h>

   The program cannot execute unless it has the "stdio.h" header file which
   is a standard input/output header file contains definitions and function declarations.
   It includes the preprocessor and is used when required by the program.
*/
#include <stdio.h>

// insertion sort, several errors

int X[10],  // input array
    Y[10],  // workspace array
    NumInputs,  // length of input array
    NumY = 0;  // current number of
               // elements in Y

void GetArgs(int AC, char **AV)

{  int I;

   NumInputs = AC - 1;
   for (I = 0; I < NumInputs; I++)
      X[I] = atoi(AV[I+1]);
}

/* 	ERROR: for(K = NumY-1; K > JJ; K++)
	CORRECTION: for(K = NumY; K > JJ; K--)

   "NumY-1" was changed to "NumY" and "K++" was changed to "K--".
   Since we start at the end of the array, this function should be
   decrementing instead of incrementing the values.
*/
void ScootOver(int JJ)

{  int K;

   for (K = NumY; K > JJ; K--)
      Y[K] = Y[K-1];
}

/* 	ERROR: if (NumY = 0)
	CORRECTION: if (NumY == 0)

    After I performed arbitrary command line inputs in gdb, I used the "step"
    and "n" command to double check the function. I noticed that the
    void GetArgs() function ran fine, but there were issues within
    void ProcessData() -it wasn't printing the right array element values-
    and void Insert().

    For this problem, the conditional "=" should be "==" because this
    function should be testing for equality.
*/
void Insert(int NewY)

{  int J;


   if (NumY == 0)  { // Y empty so far,
                    // easy case
      Y[0] = NewY;
      return;
   }

 /*   ERROR: for (J = 0; J < NumY; J++)  {
  	  CORRECTION: for (J = 0; J <= NumY; J++)  {

      "J < NumY" was changed to "J <= NumY" since the value "J" cannot be
      less than "NumY". If "J" started at 0 and "NumY" is equal to 0, that's
      like saying (0 < 0) which doesn't logically make any sense.
*/

   // need to insert just before the first Y
   // element that NewY is less than
   for (J = 0; J <= NumY; J++)  {
      if (NewY < Y[J])  {
         // shift Y[J], Y[J+1],... rightward
         // before inserting NewY
         ScootOver(J);
         Y[J] = NewY;
         return;
      }

 /*   CORRECTION:
 	  		else if((NewY > Y[J]) && (Y[J] == 0))
	  		{
		  		Y[J] = NewY;
	  		}

      An else-if statement is needed or otherwise the values of "Y[J]" will
      equal to 0.
*/
	  else if((NewY > Y[J]) && (Y[J] == 0))
	  {
		  Y[J] = NewY;
	  }
   }
}

void ProcessData()

{

   for (NumY = 0; NumY < NumInputs; NumY++)
      // insert new Y in the proper place
      // among Y[0],...,Y[NumY-1]
      Insert(X[NumY]);
}

void PrintResults()

{  int I;

   for (I = 0; I < NumInputs; I++)
      printf("%d\n",Y[I]);
}

int main(int Argc, char ** Argv)

{

   GetArgs(Argc,Argv);
   ProcessData();
   PrintResults();
}


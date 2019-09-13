/* Bresia Prudente, bprude2
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct ELE *tree_ptr;
struct ELE {
    long val;
    tree_ptr left;
    tree_ptr right;
};

//A.
long traverse(tree_ptr tp)
{
     long result;
     if(tp == NULL)
     {
          return 1;
     }//end if
     
     long a = traverse(tp->right);
     long b = traverse(tp->left);
     
     if(tp->val >= a)
     {
         result = tp->val;
     }//end if
     else
     {
         result = a; 
     }//end else
     
     if(result < b)
     {
         result = b;
     }//end if
     return result;
}//end long


/* B.
   This finds the max value in the tree.
   When it finds no value, it returns the min value.
*/

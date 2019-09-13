/* Bresia Prudente, bprude2
*/

#include "stack.h"

// Linked list implementation of stack module

//This contains all the nodes
struct stack_struct {
       //TODO
       ElemType val;
       stack_struct *next;
       stack_struct *hi;
       int SIZE;
};

//This creates a new stack 
Stack stk_create(int cap){
      //TODO
      Stack x = (Stack)malloc(sizeof(Stack));
      x->SIZE = 0;
      x->hi = NULL;
}

//This should deallocate memory 
void stk_free(Stack s) {
    // TODO
    free(s);
}

//Each new value gets 'pushed' into the stack
int stk_push(Stack s, ElemType val){
      // TODO
      int i = 0;
      struct stack_struct *temp;
      temp = (struct stack_struct*)malloc(sizeof(struct stack_struct));
      
      if(s == NULL){
           printf("Stack is full!");
           exit(0);
      }//end if
      
      s->next = temp;
      free(s->next);
      temp = s;
      
      s->SIZE++;
      s->val = val;
      return 1;
}

ElemType stk_pop(Stack s){
    // TODO
    //stuff goes here
   // return Elemtype val;
   if(s->SIZE == -1){
            abort();
   }
   s->SIZE--;
   
   return s->val;
}

int stk_is_full(Stack s){
     return 0;
}

int stk_is_empty(Stack s){
   // TODO
   if(s->hi == NULL){   //return 1 if stack has no elements
       return 1; 
   }             
   else{
       return 0;   //otherwise return 0;
   }//end else
}

int stk_size(Stack s){
    // TODO
    Stack curr = s;
    int size = 0;
    while(curr != NULL)
    {
         s++;
         curr = s;
    }//end while
    return size;
}

void stk_clear(Stack s){
    // TODO
    s->SIZE = -1;
}

void stk_print(Stack s) {
      // TODO
      int i;
      printf("----TOP----\n");
      for(i=s->SIZE; i>=0; i--){
          printf(FORMAT_STRING, s->val);
      }//end for
      printf("----BOTTOM----\n");
}

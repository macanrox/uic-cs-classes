#include <stdio.h>
#include <stdlib.h>

// stack.h establishes the interface functions for stacks.

// a Stack is a pointer to a structure
// where is this struct defined?
typedef struct stack_struct *Stack;

// These two lines are for setting the type of objects the stack
//    stores and how to print them.
// They may be modified to create stacks of non-int types without
//     changing stack.c
typedef double  ElemType;

#define FORMAT_STRING "  %lf\n"

// initializes and returns an empty stack
extern Stack stk_create(int cap);

// deallocates storage for stack
extern void stk_free(Stack s);

// pushes val onto stack.  returns 0 or 1
//   depending on success or failure (if already full)
extern int stk_push(Stack s, ElemType val);

// pops and returns top value from stack.
// if stack is empty, entire program aborts!  Caller's responsibility
// to make sure stack not empty.
extern ElemType stk_pop(Stack s);

// self-explanatory
extern int stk_is_full(Stack s);

// self-explanatory
extern int stk_is_empty(Stack s);

// returns number of elements on the stack
extern int stack_size(Stack s);

// empties stack
extern void stk_clear(Stack s);

// dumps stack contents
extern void stk_print(Stack s);

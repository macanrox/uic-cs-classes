
#include "stack.h"


struct stack_struct {
       // ElemType items[CAPACITY];

       ElemType *items;
       int capacity;
       int top;
};


Stack stk_create(int cap){
       Stack s = malloc(sizeof(struct stack_struct));

       cap =( cap > 16 ? cap : 16);
       // alloacte items
       s->items = malloc(cap * sizeof(ElemType));
       s->capacity = cap;
       s->top = -1;
       return s;
}

void stk_free(Stack s) {
     free(s->items);
     free(s);
}

int stk_push(Stack s, ElemType val){
     ElemType *arr;
     int i;
     if(s->top == s->capacity - 1)
     {
       arr = malloc(2*s->capacity*sizeof(ElemType));
       for(i=0; i<s->capacity; i++)
                arr[i] = s->items[i];
       free(s->items);
       s->items = arr;

       s->capacity *= 2;

     }
     s->top++;
     s->items[s->top] = val;
     return 1;
}

ElemType stk_pop(Stack s){
     if(s->top == -1)
       abort();  // library function which terminates program!!!
     s->top--;
     return s->items[s->top+1];
}

int stk_is_full(Stack s){
     return 0;
}

int stk_is_empty(Stack s){
     return s->top == -1;
}

int stk_size(Stack s) {
    return s->top+1;
}

void stk_clear(Stack s){
      s->top = -1;
}

void stk_print(Stack s) {
     int i;
     printf("----TOP-----\n");

     for(i=s->top; i>=0; i--) {
                printf(FORMAT_STRING, s->items[i]);
     }
     printf("---BOTTOM----\n");
}


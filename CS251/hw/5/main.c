#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {

    Stack s;

    s = stk_create(10);

    stk_push(s, 1.7);
    stk_push(s, 3.14);
    stk_print(s);

    stk_pop(s);

    stk_print(s);

}

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *a, *b, *c;

    printf("enter n: ");
    if(scanf("%d", &n) != 1 || n < 10)
    {
        fprintf(stderr, "bad input.  goodbye\n");
        abort();
    }

    printf("sizeof(double) %d\n", sizeof(double) );

    printf("running experiments with n=%d\n", n);

    a = gen_int_array(n, 5000);
    b = clone_int_array(a, n);
    c = clone_int_array(a, n);

    ssort(a, n);
    isort(b, n);
    msort_int(c, n);
    free(a);
    free(b );
    free(c);

    if(n<50)
        dump_int_array(c, n);

}

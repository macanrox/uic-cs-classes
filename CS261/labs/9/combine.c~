#include "combine.h"

/* Combining functions */

char inner1_descr[] = "inner1: original loop no unrolling";
/* $begin inner1 */
void inner1(vec_ptr u, vec_ptr v, data_t *dest)
{
long int i;
int length = vec_length(u);
data_t *udata = get_vec_start(u);
data_t *vdata = get_vec_start(v);
data_t sum = (data_t) 0;
for (i=0;i<length;i++){
    sum = sum + udata[i] * vdata[i];
    }
*dest = sum;
}


char inner4_descr[] = "inner4: unroll 2x and 2 accumulators"; 
/* $begin inner4 */
void inner4(vec_ptr u, vec_ptr v, data_t *dest)
{
long int i;
int length = vec_length(u);
data_t *udata = get_vec_start(u);
data_t *vdata = get_vec_start(v);
data_t sum = (data_t) 0;
/* declare and initialize the length which we want to perform the 2 inner products */
int limit = length - 1;
/* Store the product into a temp variable */
data_t temp1 = (data_t) 0;

/* This performs 2 accumulators by combining 2 elements at a time */
for(i=0; i<limit; i+=2)
{
	sum += udata[i] * vdata[i];
	temp1 += udata[i+1] * vdata[i+1];
}
sum += temp1;

/* If there are any remaining elements, do inner products for them */
for (i=0;i<length;i++){
    sum = sum + udata[i] * vdata[i];
    }
*dest = sum;
}

void register_combiners(void)
{
    add_combiner(inner1, inner1, inner1_descr);
    add_combiner(inner4, inner1, inner4_descr);
}

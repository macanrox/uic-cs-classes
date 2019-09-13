#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

extern void isort(int a[], int n);
extern void ssort(int a[], int n);
extern void msort_int(int a[], int n);



void msort(void *base, size_t n, size_t size,
             int (*cmp)(const void *, const void *));


extern int * gen_int_array(int n, int max_val);
extern void dump_int_array(int *a, int n);
extern int * clone_int_array(int *a, int n);

#endif // SORT_H_INCLUDED

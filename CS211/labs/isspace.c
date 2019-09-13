/*
 Lab 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
   int getline(void);
   void copy(void);
   /* print longest input line; specialized version */
   main()
   {
       int len;
       extern int max;
       extern char longest[];
       max = 0;
       while ((len = getline()) > 0)
           if (len > max) {
               max = len;
               copy();
           }
       if (max > 0)  /* there was a line */
           printf("%s", longest);
       return 0;
   }
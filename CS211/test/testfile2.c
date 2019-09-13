#include <stdio.h>
#include <stdlib.h>
#define MAX 256

   int main(int argc, char **argv)
   {
     FILE *src;
     char b[MAX];

     if(argc != 3) {
         printf("Usage: %s <input file name> <output file name>\n", argv[0]);
         exit(-1);
     }

     /* Try to open source and destination files. */

     if ( ( src = fopen( argv[1], "r" )) == NULL )
     {
        puts( "Can't open input file." );
        exit(-1);
     }

     /* Copy one file to the next. */


   char c;
   int counter;
   int printLines;

   while( (c=fgetc(src)) != EOF )
     {
          if (c=='\n'){
             counter++;

            putchar(c);

        }
        if (counter == printLines){
        break;
        }
     }

     /* All done, close up shop. */

     fclose( src );

   }

/*
    Lab 1
    Name:   Bresia Prudente
	net-ID: bprude2
	Class: 	CS 211
    Lab:    11-12:50

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 256
   
   int main(int argc, char **argv)
   {
     FILE *src, *dst;
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
     if ( (dst = fopen( argv[2], "w" )) == NULL )
     {
        puts( "Can't open output file." );
        fclose( src );
        exit(-1);
     }
   
     /* Copy one file to the next. */
     while( ( fgets( b, MAX, src ) ) != NULL )
     {
        fputs( b, dst );
     }
   
     /* All done, close up shop. */
   
     fclose( src );
     fclose( dst );
   }

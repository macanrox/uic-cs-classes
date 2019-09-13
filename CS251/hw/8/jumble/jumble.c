#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ht.h"

#define SIZE_T 85000

int main(int argc, char **argv)
{
    //Declare and initialize variables
    FILE *f;
    char strArr[50] = {'\0'};
    int quit = 0;
    char *ptr;
    char sort_Str[50];
    int len = 0;
	hTable *ht;
	ht = create (TABLESIZE);
	
    //Print an error message if there's not at least 2 args
    if(argc != 2) 
	{
        printf("Usage: %s <input file name> \n", argv[0]);
        exit(-1);
    }//end if
	
	//Open file
    if((f = fopen(argv[1], "r")) == NULL) 
	{
        printf("Cannot open file, please try again.\n");
		exit(-1);
    }//end if
	
    while(fscanf(f,"%s",strArr) == 1)  
	{
		printf("Search: %s\n", string);
        len = strlen(strArr) ;
		
        //Save original string
		strcpy(sort_Str, strArr);
		
        qsort(strArr, len, sizeof(char), cmp);
		printf("Sort: %s\n", string);
        
        insert(strArr, ht);
		insert(sort_Str, ht);
    }//end while
	
    fclose(f);
	
    //Loop asks user to enter a string and then sort them into hash tables
	//Keep going until they use a 'q' or 'Q' flag
    while(!quit) 
	{
        printf("\nEnter the word that you'd like to unscramble: ");
		
        fflush(stdout);
		
        if(fgets(strArr, sizeof(strArr), stdin) != NULL) 
			break;
		ptr = strchr(string, '\n');
		if(ptr != NULL)
			*ptr = '\0';
		if((strArr[0] == 'q' || strArr[0] == 'Q') && strArr[1] == '\0')
                quit = 1;
		else 
		{
			printf("Search: %s\n", string);
			len = strlen(strArr);
			strcpy(sort_Str, strArr);
				
			qsort(strArr, len, sizeof(char), cmp);
			printf("Sort: %s\n", sort_Str);
			
			list *get = search(sort_Str, ht);
			if(get != NULL)
				printf("Got: %s\n", get->string);
			else
				printf("The word cannot be found in the dictionary.\n");
            }//end else
        }//end if
    }
    //Free hash table
    freeHash(ht);
	
    return 0;
}
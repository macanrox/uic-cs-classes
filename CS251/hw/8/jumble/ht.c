#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ht.h"

#define SIZE_T 85000

//static hashTable_t *hashTable_create
//This creates a new hash table that keeps track of information.
static hTable * htCreate(int size)
{
	hTable *ht;
	
	if(size < 1)
		return NULL;
	
	if((ht = malloc(sizeof(hTable))) == NULL)
		return NULL;
	
	if((ht->bucket = malloc(sizeof(list *) * size)) == NULL)
		return NULL;
	
	int x;
	for(x=0; x<size, x++)
	{
		ht->bucket[x] = NULL;
	}
	
	return ht;
}//end hashTable_t

//static int simpleHash 
//This is the hash table for sorting the strings into ints
static int simpleHash(char *string, hTable *ht)
{
	int sum = 0;
	while(*string)
	{
		sum += (*string);
		string++;
	}
	
	return sum % SIZE_T;
}//end int simpleHash

//static list * search
//This searches for a value from the hash table that matches the key.
//Then it returns the value matching the given key.
static list * search(char *string, hTable *ht)
{
	int key = simpleHash(string, ht);
	list *aPtr;
	
	printf("Search yielded: %s\n", string);
	printf("Search yielded: %d (5d)\n", key, SIZE_T);
	
	for (aPtr = ht->bucket[key]; aPtr != NULL; aPtr = aPtr->next)
	{
        printf("Search: %s\n", aPtr->string);
		if ((strcmp(string, aPtr->string)) == 0)
        {
            printf("Search: %s\n", aPtr->string);
			return aPtr;
        }
	}//end for
	
    printf("Search: Object not found\n");
	
	return NULL;
}//end list * search

//int insert
//This puts a value into a table with the given key.
//Even if the key isn't given, an error isn't given. 
static int insert(char *string, hTable *ht)
{
	list *newList;
	list *oldList;
	unsigned int key = simpleHash(string, ht);
	
    printf("Insert: %s (%d)\n", string, key);
	
    oldList = search(string, ht);
	
    if(oldList != NULL)
    {
        printf("Insert: Found string %s\n", oldList->str);
        return 2;
    }
	
    if((newList = malloc(sizeof(list))) == NULL) exit(1);
	
    newList->str = strdup(str);
    newList->next = ht->bucket[key];
    ht->bucket[key] = newList;
    printf("Insert\n");
	
    return 0;
}//end int insert

//void freeHash
//This frees up the memory in a hash table
static void freeHash(hTable *ht)
{
	int x;
	list *aPtr, *temp;
	
	if(ht == NULL)
		return;
	
	for(x=0; x<SIZE_T; x++)
	{
		aPtr = ht->bucket[x];
		while(aPtr != NULL)
		{
			temp = aPtr;
			aPtr = aPtr->next;
			free(temp->string);
			free(temp);
		}//end while
	}
	free(ht->bucket);
	free(ht);
}//end void freeHash

//int cmp
//This compares two objects
static int cmp(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}//end int cmp
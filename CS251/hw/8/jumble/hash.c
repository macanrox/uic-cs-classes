#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE_T 85000
#define CONSTANT 0.75

typedef struct lst
{
	char * str;
	struct  lst *next;
}list;


typedef struct hash_table
{
	int size;
	list **bucket;
}hTable;

//hashTable_t *hashTable_create
//This creates a new hash table that keeps track of information.
hTable *htCreate(int size)
{
	hTable * ht;
	
	if(size < 1)
		return NULL;
	
	if((ht = malloc(sizeof(hTable))) == NULL)
		return NULL;
	
	int x;
	for(x=0; x<size; x++)
	{
		ht->bucket[i] = NULL;
	}
	
	ht->size = size;
	
	return ht;
}//end hashTable_t

int hash0(char *str, hTable *ht)
{
	int sum = 0;
	while(*str)
	{
		sum += (*str);
		str++;
	}

	return sum % ht->size;
}//end int hash0

int hash1(char *str, hTable *ht)
{
	int sum, x = 0;
	while (*str)
 	{
 		sum += (*str)*(pow(31, x));
 		str++;
 		i++;
 	}

 	return sum % ht->size;
 }

//list * search
//This searches for a value from the hash table that matches the key.
//Then it returns the value matching the given key.
list * search(char *str, hTable *ht)
{
	list *aPtr;
	
	int key = hash0(str, ht);
	
	for(aPtr = ht->bucket[key]; aPtr != NULL; aPtr = aPtr->next)
	{
		if((strcmp(str, aPtr->str)) == 0)
			return aPtr;
	}
	
	return NULL;
}//end list * search

//int insert
//This puts a value into a table with the given key.
//Even if the key isn't given, an error isn't given. 
int insert(char *str, hTable *ht)
{
	list *newList;
	list *oldList;
	unsigned int key = hash0(str, ht);
	
	if((newlist = malloc(sizeof(list))) == NULL)
		return 1;
	
	oldList = search(str, ht);
	
	if(oldList != NULL)
		return 1;
	
	newList->str = strdup(str);
	newList->next = ht->bucket[key];
	ht->bucket[key] = newList;
	
	return 0;
}//end int insert

void freeHash(hTable *ht)
{
	int x;
	list *aPtr, *temp;
	
	if(ht == NULL)
		return;
	
	for(x=0; x<ht->size; x++)
	{
		aPtr = ht->bucket[x];
		while(aPtr != NULL)
		{
			temp = aPtr;
			aPtr = aPtr->next;
			free(temp->str);
			free(temp);
		}//end while
	}
	free(ht->bucket);
	free(ht);
}//end void freeHash

int cmp(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}//end int cmp
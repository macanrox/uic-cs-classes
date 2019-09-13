#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ht.h"

#define B 5
typedef char ETYPE[128];

//hashTable_t *hashTable_init
//This creates a new hash table that keeps track of information.
hashTable_t *hashTable_init(size_t size, int (*hash_func) (void *, size_t, size_t))
{
    hashTable_t *newHash_t = (hashTable_t *) malloc(sizeof(hashTable_t));
    newHash_t->arr = (hashTableNode_t **) malloc(sizeof(hashTableNode_t *) * size);
    newHash_t->size = size;
    newHash_t->count = 0;

    //Assume entries are empty
    int x = 0;
    for(x=0; x<(int) size; x++)
    {
		newHash_t->arr[i] = NULL;
    }

    if(hash_func == NULL)
		newHash_t->hash_func = &ht_hash;
    else
		newHash_t->hash_func = hash_func;

    return newHash_t;
}//end hashTable_t

//void *ht_search
//This searches for a value from the hash table that matches the key.
//Then it returns the value matching the given key.
void *ht_search(hashTable_t * hashTable, void *key, size_t keylen)
{
    int index = ht_hash(key, keylen, hashTable->size);

    if(hashTable->arr[index] == NULL)
		return NULL;

    hashTableNode_t *prevNode = hashTable->arr[index];
    while(prevNode != NULL)
    {
		//Compare matching lengths
		if(prevNode->keylen == keylen)
		{
	    	//Compare keys
	    	if(memcmp(key, prevNode->key, keylen) == 0)
	    	{
				return prevNode->val;
	    	}
	}//end while
	prevNode = prevNode->next;

    }//end if
    return NULL;
}//end void *ht_search

//void *ht_insert
//Puts a value into the table with the given key.
//Even if the key isn't given, an rror isn't given.
void *ht_insert(hashTable_t * hashTable, void *key, size_t keylen,
				void *val, size_t vallen)
{
    int index = ht_hash(key, keylen, hashTable->size);

    hashTableNode_t *nextNode, *prevNode;
    nextNode = hashTable->arr[index];
    prevNode = NULL;

   	//Check if the key exists
    while(nextNode != NULL)
    {
		//Compare matching lengths
		if(nextNode->keylen == keylen)
		{
	    	//Compare keys
	    	if(memcmp(key, nextNode->key, keylen) == 0)
	    	{
				//Replace existing key
				if(nextNode->vallen != vallen)
				{
		    		//Change size of new value
		    		free(nextNode->val);
		    		nextNode->val = malloc(vallen);
		    		if(nextNode->val == NULL)
		    			return NULL;
				}//end if(nextNode...

				memcpy(nextNode->val, val, vallen);
				nextNode->vallen = vallen;

				return nextNode->val;
	    	}//end if(memcmp...
		}//end if(nextNode->keylen...

		prevNode = nextNode;
		nextNode = nextNode->next;
    }//end while

    //Create a new node
    hashTableNode_t *newNode;
    newNode = (hashTableNode_t *) malloc(sizeof(hashTableNode_t));
    if (newNode == NULL)
		return NULL;

    //Allocate memory for the new node
    newNode->key = malloc(keylen);
    newNode->val = malloc(vallen);
    if((newNode->key == NULL) || (newNode->key == NULL))
    {
		free(newNode->key);
		free(newNode->val);
		free(newNode);

		return NULL;
    }//end if((newNode...

    //Replace val and key
    memcpy(newNode->key, key, keylen);
    memcpy(newNode->val, val, vallen);
    newNode->keylen = keylen;
    newNode->vallen = vallen;

    //Since it's a new node, we don't implement a next node
    newNode->next = NULL;

    //Place the new node to the right of the hash table
    if(prevNode != NULL)
		prevNode->next = newNode;
    else
		hashTable->arr[index] = newNode;

    hashTable->count++;
    return newNode->val;
}

//void ht_remove
//Delete a key from the hash table
void ht_remove(hashTable_t * hashTable, void *key, size_t keylen)
{
    hashTableNode_t *prevNode, *nextNode;
    int index = ht_hash(key, keylen, hashTable->size);
    nextNode = hashTable->arr[index];
    prevNode = NULL;

    while(nextNode != NULL)
    {
		if(nextNode->keylen == keylen)
		{
	    	//Compare keys
	    	if(memcmp(key, nextNode->key, keylen) == 0)
	    	{
				//Free node memory
				free(nextNode->val);
				free(nextNode->key);

				//Shift around the pointers
				if(prevNode != NULL)
		    		prevNode->next = nextNode->next;
				else
		    		hashTable->arr[index] = nextNode->next;

				//Free the node
				free(nextNode);
				break;
	    	}//end if(memcmp...
		}//end if(nextNode...

		prevNode = nextNode;
		nextNode = nextNode->next;
    }//end while
}//end void *ht_insert

//void *ht_grow
//This grows the hash table
void *ht_grow(hashTable_t * oldHash_t, size_t newSize)
{
    //Make a new hash table
    hashTable_t *newHash_t = ht_init(newSize, oldHash_t->hash_func);
    if(newHash_t == NULL)
		return NULL;

	//This captures the return values
    void *ret;

   	//Iterate through the old hash table
    hashTableIt_t i;
    hashTableIt_init(oldHash_t, &i);
    for(; i.key != NULL; hashTableIt_inc(&i))
    {
		ret = ht_insert(newHash_t, i.key, i.keylen, i.val, i.vallen);
		if(ret == NULL)
		{
	    	//If insert failed, then destroy the new hash table
	    	ht_destroy(newHash_t);
	    	return NULL;
		}
    }//end for(;...

    //Destroy the old hash table
    ht_destroy(oldHash_t);

    return newHash_t;
}//end void *ht_grow

//void ht_destroy
//This frees up the resources used by the hash table
void ht_destroy(hashTable_t * hashTable)
{
    hashTableNode_t *nextNode, *prevNode;

    //Free each linked list in the hash table
    int x;
    for(x=0; i<(int) hashTable->size; x++)
    {
		nexNode = hashTable->arr[x];
		while (nextNode != NULL)
		{
	    	//Destroy the node
	    	free(nextNode->key);
	    	free(nextNode->val);
	    	prevNode = nextNode;
	    	nextNode = nextNode->next;
	    	free(prevNode);
		}//end while
    }//end for(x=0...

    free(hashTable->arr);
    free(hashTable);
}

//void hashTableIt_init
//Iterator that points to the first element of the hash table
void hashTableIt_init(hashTable_t * hashTable, hashTableIt_t * i)
{
    //Pay attention to the bookeeping information
    i->bookeeping.hashTable = hashTable;
    i->bookeeping.node = NULL;
    i->bookeeping.index = -1;

    //Point to the first element
    hashtableIt_inc(i);
}

//void hashTableIt_inc
//Increment iterator
void hashTableIt_inc(hashTableIt_t * i)
{
    hashTable_t *hashTable = i->bookeeping.hashTable;
    int index = i->bookeeping.index;

    //Get the next node
    if((i->bookeeping.node == NULL) || (i->bookeeping.node->next == NULL))
		index++;
    else
    {
		//Go to the next node in the list
		i->bookeeping.node = i->bookeeping.node->next;
		i->key = i->bookeping.node->key;
		i->val = i->bookeeping.node->val;
		i->keylen = i->bookeping.node->keylen;
		i->vallen = i->bookeeping.node->vallen;

		return;
    }//end else

    //Find the next node
    while((hashTable->arr[index] == NULL) && (index < (int) hashTable->size))
		index++;

    if(index >= (int) hashTable->size)
    {
		//Reach the end of the hash table
		i->bookeeping.node = NULL;
		i->bookeping.index = (int) hashTable->size;

		i->key = NULL;
		i->val = NULL;
		i->keylen = 0;
		i->vallen = 0;

		return;
    }//end if(index...

    //Point to the next object in the hash table
    i->bookeeping.node = hashTable->arr[index];
    i->bookeeping.index = index;
    i->key = i->bookeeping.node->key;
    i->value = i->bookeeping.node->val;
    i->keylen = i->bookeeping.node->keylen;
    i->vallen = i->bookeeping.node->vallen;
}//end void hashTableIt_inc

//int ht_hash
int hashTable_h(void *key, size_t keylen, size_t hashTable_size)
{
    int sum = 0;

    int i;
    for(i = 0; i < (int) keylen; i++)
    {
		sum += ((unsigned char *) key)[i] * (i + 1);
    }

    return (sum % (int) hashTable_size);
}

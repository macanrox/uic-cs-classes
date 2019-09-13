#include <stdlib.h>
#include <string.h>

typedef struct hashTableNode_t {
    void *key;			//key for the node
    size_t keylen;		//key length
    void *val;			//node value
    size_t vallen;		//value length

    struct hashtab_node_t *next;
} hashTableNode_t;

typedef struct hashTable_t {
    hashTableNode_t **arr;
    size_t size;		//hash size
    int count;			//keeps track of the number of items in the table
    int (*hash_func) (void *, size_t, size_t);	//hash function
} hashTable_t;

//Used for iterating through the hash table
typedef struct hashTableIt_t {
    //Keeps track of the key and value of item
    void *key;
    void *val;
    size_t keylen;
    size_t vallen;

	//This is used to store the items (book keeping)
    struct hashTableBook_t {
	hashTable_t *hashTable;
	hashTableNode_t *node;
	int index;
    } bookeeping;

} hashTableIt_t;

/**************** FUNCTIONS ****************/
hashTable_t *hashTable_init(size_t size, int (*hash_func)(void *key, size_t keylen, size_t hashTable_size));

void *ht_search(hashTable_t * hashTable, void *key, size_t keylen);

void *ht_insert(hashTable_t * hashTable, void *key, size_t keylen, void *val, size_t vallen);

void ht_remove(hashTable_t * hashTable, void *key, size_t keylen);

void *ht_grow(hashTable_t * hashTable, size_t newSize);

void ht_destroy(hashTable_t * hashTable);

void hashTableIt_init(hashTable_t * hashTable, hashTableIt_t * i);

void hashTableIt_inc(hashTableIt_t * i);

int hashTable_h(void *key, size_t key_size, size_t hashTable_size);

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "tmap.h"

// don't forget to define your tmap_struct!!!
struct node		//binary search tree
{
	char *name;
	double value;
	int rightLen;
	int leftLen;
	int pos;

	struct node *left;
	struct node *right;

};

struct tmap_struct	//handle for bst and hashtable
{
	struct node *root;
	int position;
	int pairs;
	int height;
	int numInsert;
	int numRebalance;
};

/**
* Creates and initializes a tmap.  Returns pointer to
*  created tmap.
* Parameter:  fname gives the name of a file containing
*  name/value pairs, one pair per line.  The tmap is
*  initialized with these values.
*
*  File format example:
*
     bob 2.911
     larry 1.8
     mike 2.9
*
*  If fname is NULL an empty tmap is initialized.
**/
TMAP_PTR tmap_create(char *fname){

	//Attempt to open the file
	//otherwise return an error message
	printf("%s", fname);
	fflush(stdout);
	FILE *src;
	src = fopen(fname, "r");
	if(src == NULL)
	{

		t->position = 0;
		t->pairs = 0;
		t->height = 0;
		t->numInsert = 0;
		t->numRebalance = 0

		return t;
	}//end if

	double value;
	char str[30];
	t->position = 0;
	TMAP_PTR head = malloc(sizeof(struct tmap_struct));

	while(feof(src) == 0)
	{
		fscanf(src, "%s", str);
		fscanf(src, "lf", &value);
		t->root = insert(t->root, str, value, t->positions);
		t->pairs = t->pairs + 1;
		t->position = t->position + 1;
	}//end while

	t->height = height(t->root);
	return t;

}//end TMAP_PTR tmap_create

/**
* Inserts given name-value pair into tmap.
*
* returns 1 if succeeds; 0 for failure.
*
* For partial credit:  you may assume that every insert
*   is for a name not currently in the tmap.
*
* For full credit:  if there is an entry with the same
*   name already in the tmap you change the associated
*   value to be the parameter val (and modify the tree
*   accordingly).
*
* Runtime O(log n) (ammortized)
**/
int tmap_insert(TMAP_PTR t, char * name, double val){

	t->root = tmap_insert(t->root, name, val);
	t->pairs = t->pairs + 1;
	t->position = t->position

	return 1;

}//end int tmap_insert

/**
* returns the number of name-value pairs in the map
*
* Runtime:  O(1)
*/
int tmap_size(TMAP_PTR t){

	return t->pairs;

}//end tmap_size

/**
* returns the height of the underlying tree
*
* Runtime:  O(1)
*/
int tmap_height(TMAP_PTR t){

	int temp;
	if(t->height == NULL)
		temp = (int)log2(t->pairs);
	else
	{
		temp = t->height;
	}//end else

	return temp;

}//end int tmap_height


/**
* returns pointer to NAME_VAL pair which is the
*   i'th entry in the sorted sequence.
*
* if i=1, you return the min entry
* if i=n, you return the max entry
* if n=n/2 you return the median entry (or close)
* if(i < 1 || i > n) return NULL;
*
* Runtime:  O(log n)
*/
NAME_VAL * tmap_get_ith(TMAP_PTR t, int i){

	struct node *k = t->root;
	NAME_VAL *temp = malloc(sizeof(NAME_VAL));
	temp->name = malloc(30*sizeof(char));
	temp->value = 0;

	while(k != NULL)
	{

		if(k->pos == i)
		{
			temp->name = k->name;
			temp->value = k->value;

			return temp;
		}//end if(k->pos
		if(i < k->pos)
			k = k->left;
		else
			k = k->right;

	}//end while

	return temp;

}//end NAME_VAL * tmap_get_ith

/**
* returns the number of entries in the map with values
*   between min and max inclusive -- i.e., the number of
*   entries where min <= val <= max
*
* Runtime:  O(log n)
*/
int tmap_range_size(TMAP_PTR t, double min, double max){
}

/**
* returns an array populated with all entries in the given range.
*   number of such entries is reported through the integer pointer
*   parameter m (so the caller knows the length of the array).
*
* Runtime requirement is "output dependent" in that it depends on
*   the map size AND the number of elements in the range (m).
*
* Runtime:  O(m + log n)
*/
NAME_VAL * tmap_extract_range(TMAP_PTR t, double min, double max, int *m){
}

/**
* Prints the following
*
*   The current size of the map.
*   The current height of the tree.
*   The total number of successful insertions since creation.
*   The total number of successful deletions since creation (if supported)
*   The total number of rebalancing operations performed since creation
*   The total "work" done over all rebalancing operations; an individual
*      rebalancing operation does work equal to the size of the subtree
*      being rebalanced since the operation is linear in the size of the
*      subtree being rebalanced.
*/
void tmap_stats(TMAP_PTR t){

	printf("Size of map: %d\n", t->pairs);
	printf("Height of the tree: %d\n", t->height);
	printf("Total number of insertions: %d\n", t->numInsert);
	printf("Total number of rebalances: %d\n", t->numRebalance);

}//end void tmap_stats


/**
* deallocates all memory associated with the map.
*
*/
//Need to create a destroy function for the other struct
void tmap_destroy_tree(struct node *tree){

	if(tree == NULL)
		return;
	tmap_destroy_tree(r->left);
	tmap_destroy_tree(r->right);
	free(tree);

}//end void tmap_destroy_tree

void tmap_destroy(TMAP_PTR t){

	tmap_destroy_tree(t->root);
	free(t);

}//end void tmap_destroy


/**  BONUS FEATURES ****/

/**
* If an entry has the given name, a pointer to that NAME_VAL
*   is returned.
* If no such entry, NULL is returned.
*
* Runtime:  O(1) for full bonus points.
*           O(log n) for partial bonus points
*           Theta(n):  no bonus points, but it might be handy for debugging.
*/
NAME_VAL * tmap_name2value(TMAP_PTR t, char *name){
}


/**
* removes entry corresponding to the given name (if such an entry
*   exists).  On success 1 is returned; if no such entry exists, 0
*   is returned.
*
* Runtime:  O(log n) amortized for bonus credit.
*/
int tmap_remove_by_name(TMAP_PTR t, char *name){
}







typedef struct name_val {
    char *name;
    double value;
}NAME_VAL;


// incomplete type.  Definition in tmap.c
struct tmap_struct;

typedef struct tmap_struct *TMAP_PTR;  // serves as "handle" to tmap



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
extern TMAP_PTR tmap_create(char *fname);

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
extern int tmap_insert(TMAP_PTR t, char * name, double val);

/**
* returns the number of name-value pairs in the map
*
* Runtime:  O(1)
*/
extern int tmap_size(TMAP_PTR t);


/**
* returns the height of the underlying tree
*
* Runtime:  O(1)
*/
extern int tmap_height(TMAP_PTR t);


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
extern NAME_VAL * tmap_get_ith(TMAP_PTR t, int i);

/**
* returns the number of entries in the map with values
*   between min and max inclusive -- i.e., the number of
*   entries where min <= val <= max
*
* Runtime:  O(log n)
*/
extern int tmap_range_size(TMAP_PTR t, double min, double max);


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
extern NAME_VAL * tmap_extract_range(TMAP_PTR t, double min, double max, int *m);

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
extern void tmap_stats(TMAP_PTR t);


/**
* deallocates all memory associated with the map.
*
*/
extern void tmap_destroy(TMAP_PTR t);




/**  BONUS FEATURES ****/

/**
* If an entry has the given name, a pointer to that NAME_VAL
*   is returned.
* If no such entry, NULL is returned.
*
* Runtime:  O(1) on average for full bonus points.
*           O(log n) for partial bonus points
*           Theta(n):  no bonus points, but it might be handy for debugging.
*/
extern NAME_VAL * tmap_name2value(TMAP_PTR t, char *name);


/**
* removes entry corresponding to the given name (if such an entry
*   exists).  On success 1 is returned; if no such entry exists, 0
*   is returned.
*
* Runtime:  O(log n) amortized for bonus credit.
*/
extern int tmap_remove_by_name(TMAP_PTR t, char *name);







/***** STRUCTS *****/
typedef struct linkedList
{
	char *string;
	struct  lst *next;
}list;


typedef struct hash_table
{
	list **bucket;
}hTab;

/******** FUNCTIONS ********/
static hTable * htCreate(int size);

static int simpleHash(char *string, hTable *ht);

static list * search(char *string, hTable *ht);

static int insert(char *string, hTable *ht);

static void freeHash(hTable *ht);

static int cmp(const void *a, const void *b);
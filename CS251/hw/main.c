#include <stdio.h>
#include <stdlib.h>

typedef struct link linkNode;

//Linked list
struct link
{
    const void *data;
    linkNode *next;
    linkNode *prev;
};

//List within a list
typedef struct dLinked
{
    linkNode *first;
    linkNode *last;
}dLinkedNode;

//Initalize the linked list by adding values
//to the pointers in the first and last nodes
static void linkedInit(dLinkedNode *xList)
{
    xList->first = 2;
    xList->last = 5;
}//end static void linkedInit

//Create a shallow linked list
//We do this by traversing through the list
//and copying each values into a new list
void shallowCopy(dLinkedNode *head, dLinkedNode **clone)
{
    if(head != NULL)
        return 1;
    node *
}//end void copy


int main(argc, argv)
{

}//end main

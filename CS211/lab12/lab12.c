/*
    Lab 12: Binary Trees
    Author: Bresia Anne Prudente
    netID:  bprude2
    Class:  CS 211
    Lab:    11-12:50
 */

#include <stdio.h>
#include <stdlib.h>


/*

 add
 empty
 list items in "in-order"
 list items in "pre-order"
 list items in "post-order"
 
 q: quit program
 
 a <int>: add integer value to binary tree (left subtree < element and right subtree > element )
 
 e: empty values and deallocate nodes
 
 i: list items in binary tree "in-order"
    -> left subtree, element, then right subtree in this order
    -> must write recursively
 
 r: list items in binary tree "pre-order"
    -> list element, left subtree, then right subtree in this order
    -> must write recursively
 
 p: list the items in binary tree "post-order"
    -> list left subtree, right subtree, then element in this order
    -> must write recursively
 
 */

/* doubly linked list */
typedef struct nodeStruct
{
    
    int value;
    struct nodeStruct *left;
    struct nodeStruct *right;
    struct nodeStruct *next;
    
}node;

typedef node *nodePtr;

/******************************************************
                      FUNCTIONS
 ******************************************************/

/*
 set curr to root of tree
 
 while ( curr is not NULL)
 {
 if (value to insert is less than element at curr)
 set curr to left subtree of curr
 else
 set curr to right subtree of curr
 }
 Insert new node at curr
 */

/*
    to search if value is in tree, check the root.
        -> if root is empty ( root == NULL ), then return FALSE and stop
           else return TRUE and stop
        -> if value < value in node, left subtree
           if value > value in node, right subtree
        
 */

void insert( bnode *hd, int v )
{
    
    //for regular linked list, need to tweak for this assignment
    if( *hd == NULL )
    {
        *hd = (bnodePtr)malloc(sizeof(node));
        (*hd)->value = v;
        (*hd)->next = v;
        (*hd)->next = NULL;
    }
    else
    {
        add( &((*hd)->next) );
    }

}//end void insert

void empty()
{
    
}//end void empty

void inOrder()
{
    
}//end void inOrder

void preOrder()
{
    
}//end void preOrder

void postOrder()
{
    
}//end void postOrder

/******************************************************
                        MAIN
 ******************************************************/
int main( int argc, char **argv )
{
    int num;
    char entry;
    
    while(1)
    {
        /* Prompt message and get user input. */
        printf("\nMake a selection from the following: \n"
               "q   Quit\n"
               "a   Add\n"
               "e   Empty"
               "i   List items in 'in-order'\n"
               "r   List items in 'pre-order'\n"
               "p   List items in 'post-order'\n");
        
        printf("Choose a value: ");
        scanf("%s", &entry);
        
        switch( entry )
        {
                
            case 'q':
            {
                printf("Quitting program.");
                exit(-1);
                break;
            }
            case 'a':
            {
                break;
            }
            case 'e':
            {
                break;
            }
            case 'i':
            {
                break;
            }
            case 'r':
            {
                break;
            }
            case 'p':
            {
                break;
            }
                
        }//end switch
        
    }//end while
    
}//end main

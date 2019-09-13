/*
 Lab 11: Linked List
 Author: Bresia Anne Prudente
 netID:  bprude2
 Class:  CS 211
 Lab:    11-12:50
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	
	int value;
	struct node *next;
	
} *head;


/********************************************
 FUNCTIONS
 ********************************************/

/********************************************
 insert
 
 Adds an integer value to the linked list.
 The values go in order from largest to smallest.
 ********************************************/
int insert( int v )
{
	
	struct node *temp;
	temp = head;
	
	/* If the list empty, add the first node */
	if( head == NULL )
	{
		head = malloc( sizeof( struct node ));
		temp = head;
	}
	else 
	{
		while( ( temp->next ) != NULL )
		{
			temp = temp->next;
		}
		
		temp->next = malloc( sizeof( struct node ));
		temp = temp->next;
	}
	
	temp->value = v;
	temp->next = NULL;
	
}//end int insert

/******************************************** 
 delete
 
 Deletes the desired value from the linked list.
 Also deallocates the nodes.
 ********************************************/
int delete( int v )
{
	
	struct node *current, *previous;
	current = head;
	
	if( current == NULL )
	{
		printf("The list is empty.\n");
	}
	
	/* Traverse through the list */
	while( current != NULL )
	{
		/* If a value matches the user input, then deallocate node */
		if( current->value == v )
		{
			if( current == head )
			{
				head = current->next;
				free( current );
				return 0;
			}
			else
			{
				previous->next = current->next;
				free( current );
				return 0;
			}
		}
		/* If value doesn't match, keep on traversing through list */
		else
		{
			previous = current;
			current = current->next;
		}
		
	}//end while
	
}//end int delete

/*********************************************
 contains
 
 Displays a message if the integer value 
 exists in the linked list.
 *********************************************/
int contains( int v )
{
	struct node *ptr;
	ptr = head;
	
	if( ptr == NULL )
	{
		printf("List is empty.\n");
	}
	else if( ptr != NULL && ( ptr->value == v ) )
	{
		return 1;
	}
	else
	{
		while( ptr != NULL )
		{
			ptr = ptr->next;
			
			if( ptr->value == v )
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
			break;
		}
	}
	
	
}//end void contains

/*********************************************
 empty
 
 Empties the entire list. 
 *********************************************/
void empty()
{
	struct node *temp;
	
	while( head != NULL )
	{
		temp = head;
		head = temp->next;
		free( head );
	}
	
}//end void empty

/*********************************************
 listItems
 
 Displays current integer values in linked list.
 *********************************************/
void listItems( struct node *list )
{
	if( list != NULL )
	{
		printf(" -> %d ", list->value);
		listItems( list->next );
	}
	
	
}//end void listItems

/*********************************************
 listItemsReverse
 
 Displays current integer values in 
 linked list in reverse order.
 *********************************************/
void listItemsReverse( struct node* reverseList )
{
	
	if( reverseList == NULL )
	{
		printf("The list is empty.\n");
	}
	else if( reverseList != NULL )
	{
		listItemsReverse( reverseList->next );
		printf(" -> %d ", reverseList->value );
	}
	
}//end void listItemsReverse

/********************************************
 MAIN
 ********************************************/
int main( int argc, char **argv )
{
	
	while(1)
	{
		char entry;
		int num;
		
		/* Print message and prompt the user for value */
		printf("\nWhat would you like to do with the linked list?\n"
			   "q	Exit program.\n"
			   "i	Insert an integer value.\n"
			   "d	Delete an integer value.\n"
			   "c	Check if this integer is contained in list.\n"
			   "e	Empty everything.\n"
			   "l	List all items.\n"
			   "r	List all items in reverse order.\n");
		
		printf("\nChoose a choice from above: ");
		scanf( "%s", &entry );
		
		/* switch case for the different values */
		switch( entry )
		{
				
			case 'q':	
			{
				printf("\nQuitting program.\n");
				exit(-1);
			}
			case 'i':
			{
				printf("\nWhat value would you like to add?\n");
				scanf("%d", &num);
				insert( num );
				
				break;
			}
			case 'd':
			{
				printf("\nWhat value would you like to delete?\n");
				scanf("%d", &num);
				delete( num );
				
				break;
			}
			case 'c':
			{
				int result;
				
				printf("\nWhat value would you like to check?\n");
				scanf("%d", &num);
				result = contains( num );
				
				if( result == 1 )
				{
					printf("The element exists.\n");
				}
				else 
				{
					printf("The element doesn't exist.\n");
				}
				
				break;
			}
			case 'e':
			{
				empty();
				break;
			}
			case 'l':
			{
				listItems(head);
				break;
			}
			case 'r':
			{
				listItemsReverse(head);
				break;
			}
			default:
			{
				printf("\nNot a valid selection! Choose a different value.\n");
			}
				
		}//end switch
		
	}//end while    
	
}//end main


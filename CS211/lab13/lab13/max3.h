//prototypes go here
//globally needed information

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DECKSIZE 52
#define VALUE 9
#define FACE 4

typedef struct{
    int value;
    char suit [10];
    char name [10];
}Card;


Card cards[DECKSIZE];
char faceName[13][10]={"two","three","four","five","six","seven","eight","nine","ten","jack","queen","king","ace"};

char suitName[4][10]={"spades","diamonds","clubs","hearts"};
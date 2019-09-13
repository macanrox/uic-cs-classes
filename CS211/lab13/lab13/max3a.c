/*
 Lab 13: Multiple Source Files
 Author: Bresia Anne Prudente
 netID:  bprude2
 Class:  CS 211
 Lab:    11-12:50
 */

#include "max3.h"

void printDeck(Card cards[]){
    int i;
    
    for(i=0; i < DECKSIZE;i++){
        printf("%s of %s value=%d\n",cards[i].name,cards[i].suit,cards[i].value);
        if((i+1)%13==0 && i!=0)printf("------------------\n\n");
    }
}


void shuffle(Card cards[]){
    Card temp;
    int i;
    int this;
    int that;
    
    for(i=0;i<100;i++){
        this=rand()%(DECKSIZE);
        that=rand()%(DECKSIZE);
        /* printf("%d and %d\n", this, that); */
        temp = cards[this];
        cards[this]=cards[that];
        cards[that]=temp;
        
    }
}

void initDeck(Card cards[]){
    int suitCount=0;
    int faceCount=0;
    int i;
    
    srand(time(NULL));
    
    for(i=0;i<DECKSIZE;i++){
        if(faceCount<9){
            cards[i].value=faceCount+2;
        }
        else{
            cards[i].value=10;
        }
        strcpy(cards[i].suit, suitName[suitCount]);
        strcpy(cards[i].name, faceName[faceCount++]);
        if(faceCount==13){
            cards[i].value=11;
            suitCount++;
            faceCount=0;
        }
    }
    
    /* printDeck(cards); */
    shuffle(cards);
    /* printDeck(cards); */
}

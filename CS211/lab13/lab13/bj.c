/*
 Lab 13: Multiple Source Files
 Author: Bresia Anne Prudente
 netID:  bprude2
 Class:  CS 211
 Lab:    11-12:50
 */

#include "max3.h"

int evaluateHand(Card hand[], int numCards)
{
    int points = 0;
    int i;
    
    for (i = 0; i < numCards; i++)
    {
        points = points + hand[i].value;
    }
    
    for (i = 0; i < numCards; i++)
    {
        if (points > 21 && hand[i].value == 11)
            points = points - 10;
    }
    
    if (points > 21)
        points = -1;
    
    return points;  
}

int main(){
    
    Card deck[DECKSIZE];
    Card player[5];
    Card dealer[5];
    int cardsLeft;
    int playerCount;
    int dealerCount;
    int i;
    
    initDeck(deck);
    cardsLeft = 52;
    
    player[0] = deck[--cardsLeft];
    dealer[0] = deck[--cardsLeft];
    player[1] = deck[--cardsLeft];
    dealer[1] = deck[--cardsLeft];
    playerCount = 2;
    dealerCount = 2;
    
    printf ("Player\'s cards:\n");
    for ( i = 0; i < playerCount ; i++)
        printf ("  %s of %s\n", player[i].name, player[i].suit); 
    printf ("  Points: %d\n", evaluateHand(player, playerCount));
    printf ("Dealer shows: %s of %s\n", dealer[0].name, dealer[0].suit);
    
    if (evaluateHand(dealer, dealerCount) == 21)
    {
        dealerBlackJack(player, playerCount, dealer, dealerCount);
    }
    else if (evaluateHand(player, playerCount) == 21)
    {
        printf ("Player has Blackjack.  You win.\n");
    }
    else
    {
        playHand(player, playerCount, dealer, dealerCount, deck, cardsLeft);
    }
    
    return 0;
}
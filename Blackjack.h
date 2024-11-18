#ifndef Blackjack_h
#define Blackjack_h

#include <iostream>
#include <vector>
using namespace std;

struct Card {
  int suit;
  int value;
};

void createDeck(vector<Card> &deck); 
//PRE: deck is empty 
//POST: deck is loaded with 52 cards
Card dealCard(vector<Card> &deck); 
//PRE: The deck has cards and is shuffled 
//POST: returns the "top" card and removes from deck
int calcHand(vector<Card> hand);  
//PRE: hand is not empty
//POST: returns the sum of the values of the cards in hand
void showHand(vector<Card> &hand);  
//PRE: none 
//POST: displays the cards in hand
void blackjack();
//PRE: none 
//POST: plays a game of blackjack


#endif
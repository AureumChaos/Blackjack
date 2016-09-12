//*********************************************************************
//
// Deck.cpp
//
// A class that defines a deck of cards
//
// Author: Jeff Bassett
//
// Updates:
//    09/09/2016  Created
//    09/12/2016  Added addCard() method.
// 
//*********************************************************************

#include <random>
#include <algorithm>

#include "deck.h"

using namespace std;


//*********************************************************************
//
// Deck::Deck
//
// Constructor - Create a standard deck of 52 cards.
//
//*********************************************************************
Deck::Deck()
{
    int suit;
    int rank;
    
    for(suit = 0; suit < Card::NUM_SUITS; suit++)
        for(rank = 0; rank < Card::NUM_RANKS; rank++)
            theDeck.push_back(new Card(rank, suit));
}


//*********************************************************************
//
// Deck::~Deck
//
// Destructor - Delete all the cards in the deck.
//
//*********************************************************************
Deck::~Deck()
{
    while(!theDeck.empty())
    {
        Card *card = takeTopCard();
        delete card;
    }
}


//*********************************************************************
//
// Deck::shuffle
//
// Randomly shuffle all the cards in the deck.
//
//*********************************************************************
void Deck::shuffle()
{
    //random_shuffle(theDeck.begin(), theDeck.end());

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(theDeck.begin(), theDeck.end(), g);
}


//*********************************************************************
//
// Deck::addCard
//
// Adds a card to the top of the deck.  The deck takes responsible for memory
// deallocation of the card.
//
//*********************************************************************
void Deck::addCard(Card *card)
{
    theDeck.push_back(card);
}


//*********************************************************************
//
// Deck::takeTopCard
//
// Retreives the card on the top of the deck.  The caller becomes
// responsible for memory deallocation of the card.
//
//*********************************************************************
Card * Deck::takeTopCard()
{
    // Taking from the back should be a lot faster.
    Card *theCard = theDeck.back();
    theDeck.pop_back();

    return theCard;
}



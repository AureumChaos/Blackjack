//*********************************************************************
//
// Deck.h
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

#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>

class Deck
{
    private:
        vector<Card *> theDeck;  // Might make sense to inherit instead

    public:
        Deck();
        ~Deck();

        void shuffle();
        int size() {return theDeck.size();};
        void addCard(Card*);
        Card * takeTopCard();
};

#endif



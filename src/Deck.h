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


#undef DLL_SIG
#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILD_DLL
#define DLL_SIG __declspec(dllexport)
#else
#define DLL_SIG __declspec(dllimport)
#endif

#ifdef __cplusplus
}
#endif

//#define DLL_SIG 


class DLL_SIG Deck
{
    private:
        vector<Card *> theDeck;

    public:
        Deck();
        ~Deck();

        void shuffle();
        int size() {return theDeck.size();};
        void addCard(Card*);
        Card * takeTopCard();
};

#endif // DECK_H



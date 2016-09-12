//*********************************************************************
//
// Player.cpp
//
// A base class for different types of players
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
// 
//*********************************************************************

#include <iostream>
#include <cassert>

#include "Player.h"


//*********************************************************************
//
// Player::~Player
//
// Destructor - Clean up any allocated memory
//
//*********************************************************************
Player::~Player()
{
    while(!hand.empty())
    {
        delete(hand.back());
        hand.pop_back();
    }
}



//*********************************************************************
//
// Player::returnCardsToDeck
//
// Move the cards in the players hand back to the deck.  The deck is now
// responsible for memory deallocation.
//
//*********************************************************************
void Player::returnCardsToDeck(Deck &deck)
{
    while(!hand.empty())
    {
        Card *card = hand.back();
        deck.addCard(card);
        hand.pop_back();
    }
}




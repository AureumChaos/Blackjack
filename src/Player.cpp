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
#include <sstream>
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
// Player::displayHand
//
// Display the contents of the player's hand
//
//*********************************************************************
void Player::displayHand(BaseUI &ui, bool hide)
{
    stringstream ss;

    ss << name << ":" << endl;
    ui.text(ss.str());

    hand.display(ui, hide);

    if(!hide)
    {
        ss.str("");
        ss << "Hand value: " << handValue() << endl;
        ui.text(ss.str());
    }
}



//*********************************************************************
//
// Player::returnCards
//
// Move the cards in the players hand back to the deck.  The deck is now
// responsible for memory deallocation.
//
//*********************************************************************
void Player::returnCards(Deck &deck)
{
    while(!hand.empty())
    {
        Card *card = hand.back();
        deck.addCard(card);
        hand.pop_back();
    }
}




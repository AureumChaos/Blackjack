//*********************************************************************
//
// card.cpp
//
// A class that defines a playing card
//
// Author: Jeff Bassett
//
// Updates:
//    09/09/2016  Created
// 
//*********************************************************************

#include <iostream>
#include <cassert>

#include "card.h"


const int Card::NUM_RANKS = 13;
const int Card::NUM_SUITS = 4;

const string Card::SUIT_NAMES[] = {"Diamonds", "Hearts", "Clubs", "Spades"};
const string Card::RANK_NAMES[] = {"2", "3", "4", "5", "6", "7", "8", "9",
    "10", "Jack", "Queen", "King", "Ace"};
const int Card::RANK_VALUES[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};


//*********************************************************************
//
// Card::Card
//
// Constructor - Creates a card with the appropriate suit and rank.
//
//*********************************************************************
Card::Card(int rank_, int suit_)
{
    assert(rank_ < Card::NUM_RANKS);
    assert(suit_ < Card::NUM_SUITS);
    rank = rank_;
    suit = suit_;
}


//*********************************************************************
//
// Card::display
//
// Display a card
//
//*********************************************************************
void Card::display()
{
    cout << RANK_NAMES[this->rank] << " of " << SUIT_NAMES[this->suit];
}



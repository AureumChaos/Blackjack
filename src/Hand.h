//*********************************************************************
//
// hand.h
//
// A class that defines a hand of cards in Blackjack
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
// 
//*********************************************************************

#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <vector>

class Hand: public vector<Card *>
{
    public:
        ~Hand();

        void display();
        int value();
};

#endif



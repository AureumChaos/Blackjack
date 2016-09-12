//*********************************************************************
//
// Hand.h
//
// A class that defines a hand of cards in Blackjack
//
// Notes:
//    This class ended up being less complicated and less useful than I
//    expected.  I considered just moving the functionality into the Player
//    class, but then I thought that this might come in handy if I ever wanted
//    to implement splitting.
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
//    09/12/2016  Added evalHand() method to determine "soft" hands too.
// 
//*********************************************************************

#ifndef HAND_H
#define HAND_H

#include <vector>

#include "BaseUI.h"
#include "Card.h"

class Hand: public vector<Card *>
{
    public:
        ~Hand();

        void display(BaseUI &ui, bool hide);
        void evalHand(int &value, bool &isSoft);
        int value();
};

#endif



//*********************************************************************
//
// Dealer.h
//
// A class that define the automated actions of the dealer player.
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
// 
//*********************************************************************

#ifndef DEALER_H
#define DEALER_H

#include <string>

#include "Player.h"
#include "BaseUI.h"

using namespace std;


class Dealer : public Player
{
    public:
        Dealer() : Player("Dealer") {};
        virtual ~Dealer() {};

        virtual Action decideAction(BaseUI &ui, const Game &game);
};

#endif

//*********************************************************************
//
// Dealer.cpp
//
// A class that define the automated actions of the dealer player.
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
// 
//*********************************************************************

#include <iostream>
#include <cassert>

#include "Dealer.h"
#include "Game.h"


//*********************************************************************
//
// Dealer::decideAction
//
// Return the dealer's decision of whether to "hit" or "stay".
//
//*********************************************************************
Action Dealer::decideAction(BaseUI &ui, const Game &game)
{
    int value;
    bool isSoft;
    hand.evalHand(value, isSoft);

    if(value < 17 || (value == 17 && isSoft))
        return(HIT);

    return(STAY);
}



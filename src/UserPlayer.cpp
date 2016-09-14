//*********************************************************************
//
// UserPlayer.cpp
//
// A class that allows the user to interract with the game as a player.
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
// 
//*********************************************************************

#include <iostream>
#include <cassert>

#include "UserPlayer.h"
#include "Game.h"


//*********************************************************************
//
// UserPlayer::displayHand
//
// Display the user's hand.  Ignore the hide flag.
//
//*********************************************************************
void UserPlayer::displayHand(BaseUI &ui, bool hide)
{
    Player::displayHand(ui, false);
}


//*********************************************************************
//
// UserPlayer::decideAction
//
// Return the player's decision of whether to "hit" or "stay".
//
//*********************************************************************
enum Action UserPlayer::decideAction(BaseUI &ui, const Game &game)
{
    game.displayState(ui, true);

    Action possible_actions[] = {HIT, STAY};
    const char* char_choices[] = {"yes", "no"};
    vector<string> choices(char_choices, char_choices + 2);
    string question("Would you like another card (yes=hit, no=stay)?");

    int c = ui.choose(question, choices, 1);
    ui.text("You chose " + choices[c] + "\n");

    return possible_actions[c];
}



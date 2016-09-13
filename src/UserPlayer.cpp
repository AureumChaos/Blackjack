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

    const char* char_choices[] = {"stay", "hit"};
    vector<string> choices(char_choices, char_choices + 2);
    string question("What do you want to do?");

    int c = ui.choose(question, choices);
    ui.text("You chose " + choices[c] + "\n");

    Action action;
    switch(c)
    {
        case 0:
            action = STAY;
            break;
        case 1:
            action = HIT;
            break;
        default:
            cerr << "UserPlayer::decideAction" << endl;
            cerr << "Unkown action.  This should never happen!!" << endl;
    }

    return action;
}



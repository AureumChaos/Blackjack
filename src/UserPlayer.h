//*********************************************************************
//
// UserPlayer.h
//
// A class that allows the user to interract with the game as a player.
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
// 
//*********************************************************************

#ifndef USERPLAYER_H
#define USERPLAYER_H

#include <string>

#include "Player.h"

using namespace std;


class UserPlayer : public Player
{
    public:
        UserPlayer() : Player("You") {};
        virtual ~UserPlayer() {};

        virtual enum Action decideAction(const Game &game);
};

#endif

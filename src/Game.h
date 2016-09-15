//*********************************************************************
//
// Game.h
//
// A class that defines the main flow of a game of Blackjack.
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
// 
//*********************************************************************

#ifndef GAME_H
#define GAME_H

#include <string>

#include "Deck.h"
#include "Player.h"
#include "UserPlayer.h"
#include "Dealer.h"
#include "BaseUI.h"
//#include "ConsoleUI.h"

using namespace std;


class Game
{
    private:
        Deck deck;

        UserPlayer  *user;
        Dealer      *dealer;
        vector<Player *>  players;

    public:
        Game();
        ~Game();
        void deal();
        void play(BaseUI &ui);
        int score() {return user->compareHands(*dealer);};;
        void cleanup();
        void displayState(BaseUI &ui, bool hide) const;

        Player *getDealer() {return dealer;};
        Player *getUser() { return user;};
        Deck &getDeck() { return deck;};
};

#endif

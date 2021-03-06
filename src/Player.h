//*********************************************************************
//
// Player.h
//
// A virtual base class for different types of players.
//
// Author: Jeff Bassett
//
// Updates:
//    09/09/2016  Created
// 
//*********************************************************************

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Hand.h"
#include "Deck.h"
#include "BaseUI.h"
class Game;  // Forward reference


using namespace std;

// XXX Can I scope this to the class somehow?
enum Action {HIT, STAY};

class Player
{
    protected:
        string   name;
        Hand     hand;

    public:
        Player(string playerName) : name(playerName) {};
        virtual ~Player();

        virtual void addCard(Card *card) {hand.push_back(card);};
        virtual int handValue() {return hand.value();};
        virtual void returnCards(Deck &deck);
        virtual void displayHand(BaseUI &ui, bool hide);
        virtual int compareHands(Player &otherPlayer)
           {return hand.compareHands(otherPlayer.hand);};

        virtual Action decideAction(BaseUI &ui, const Game &game) = 0;  // Pure
           // I'm not thrilled about passing the Game instance into this
           // function, but I thought it provided more options for future
           // expansion.  For now, the only thing the dealer needs to know is
           // the best hand that any of the other players have, but if we
           // implemented other automated players, they might need more
           // information about the game state.
};

#endif



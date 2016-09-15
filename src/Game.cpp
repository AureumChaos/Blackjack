//*********************************************************************
//
// Game.cpp
//
// A class that defines the main flow of a game of Blackjack.
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
// 
//*********************************************************************

#include <iostream>
#include <sstream>
#include <cassert>

#include "Game.h"


//*********************************************************************
//
// Game::Game
//
// Constructor
//
//*********************************************************************
Game::Game()
{
    user = 0L;
    user = new UserPlayer();
    players.push_back(user);

    dealer = new Dealer();
    players.push_back(dealer);
}


//*********************************************************************
//
// Game::~Game
//
// Destructor
//
//*********************************************************************
Game::~Game()
{
    while(!players.empty())
    {
        delete players.back();
        players.pop_back();
    }
}


//*********************************************************************
//
// Game::deal
//
// Initial deal.  2 cards to each player.
//
//*********************************************************************
void Game::deal()
{
    deck.shuffle();

    for(int i = 0; i < 2; i++)
    {
        vector<Player *>::iterator p_iter;
        for(p_iter = players.begin(); p_iter != players.end(); ++p_iter)
            (*p_iter)->addCard(deck.takeTopCard());
    }
}


//*********************************************************************
//
// Game::play
//
//*********************************************************************
void Game::play(BaseUI &ui)
{
    vector<Player *>::iterator p_iter;
    for(p_iter = players.begin(); p_iter != players.end(); ++p_iter)
    {
        while((*p_iter)->handValue() <= 21 &&
              (*p_iter)->decideAction(ui, *this) == HIT)
        {
            (*p_iter)->addCard(deck.takeTopCard());
        }
    }
}


//*********************************************************************
//
// Game::cleanup
//
//*********************************************************************
void Game::cleanup()
{
    vector<Player *>::iterator p_iter;
    for(p_iter = players.begin(); p_iter != players.end(); ++p_iter)
    {
        (*p_iter)->returnCards(deck);
    }
}


//*********************************************************************
//
// Game::displayState
//
//*********************************************************************
void Game::displayState(BaseUI &ui, bool hide) const
{
    // I'm kind of assuming only 2 players here.  If there are ever more,
    // this might need to be rewritten.
    vector<Player *>::const_reverse_iterator riter;
    for(riter = players.rbegin(); riter != players.rend(); ++riter)
    {
        (*riter)->displayHand(ui, hide);

        ui.text("\n");
    }
}



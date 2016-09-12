//*********************************************************************
//
// main.cpp
//
// A test harness for the various classes.  The main entry point will
// probably change by the time I'm done.
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
// 
//*********************************************************************


#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Game.h"
#include "ConsoleUI.h"


int main()
{
    Game game;
    ConsoleUI ui;

    ui.text("Deal...\n");
    game.deal();
    game.displayState(ui);
    ui.text("\n");

    ui.text("Play...\n");
    game.play();
    game.displayState(ui);
    ui.text("\n");

    ui.text("Score...\n");
    game.score();
    game.displayState(ui);
    ui.text("\n");

    ui.text("Cleanup...\n");
    game.cleanup();
    game.displayState(ui);
    ui.text("\n");
}



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
#include <vector>
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

    const char* char_yes_no[] = {"yes", "no"};
    vector<string> yes_no(char_yes_no, char_yes_no + 2);

    int answer = 1;
    while(yes_no[answer] == "no")
    {
        game.deal();
        game.play(ui);

        game.displayState(ui, false);  // Show all cards
        int result = game.score();
        switch(result)
        {
            case -1:
                ui.text("The Dealer won.\n");
                break;
            case 0:
                ui.text("Push. No winner.\n");
                break;
            case 1:
                ui.text("You won!\n");
                break;
        }

        game.cleanup();
        answer = ui.choose("Would you like to quit?", yes_no, 1);
    }
}



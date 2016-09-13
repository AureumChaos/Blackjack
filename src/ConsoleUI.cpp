//*********************************************************************
//
// ConsoleUI.cpp
//
// A class that defines a simple text user interface.
//
// Author: Jeff Bassett
//
// Updates:
//    09/12/2016  Created
// 
//*********************************************************************

#include <iostream>
#include <string>
using namespace std;

#include "Card.h"
#include "ConsoleUI.h"

const string ConsoleUI::RANK_ABBR[] = {"A", "1", "2", "3", "4", "5", "6", "7", "8",
                                  "9", "10", "J", "Q", "K"};
const string ConsoleUI::SUIT_UNICODE[] = {"\u2660", "\u2661", "\u2662", "\u2663"};


//*********************************************************************
//
// ConsoleIU::text
//
// Output some text.
//
//*********************************************************************
void ConsoleUI::text(const string &str)
{
    cout << str;
}


//*********************************************************************
//
// ConsoleIU::drawCard
//
// Draw a playing card at the current text cursor location, and update
// the text cursor location accordingly.
//
// Draw the back of a card if rank = -1.
//
//*********************************************************************
void ConsoleUI::drawCard(int rank, int suit)
{
    // Just write it out
    if (rank == -1)
        cout << "   <hidden>";
    else
    {
        cout << "   " << Card::RANK_NAMES[rank] << " of ";
        cout << Card::SUIT_NAMES[suit] << endl;
    }

    // Use unicode to draw suits
/*
    if (rank == -1)
        cout << "XX ";
    else
        wcout << ConsoleUI::RANK_ABBR << ConsoleUI::SUIT_UNICODE << " ";
*/    
}


//*********************************************************************
//
// ConsoleIU::choose
//
// Return a user selection from a list.
//
//*********************************************************************
int ConsoleUI::choose(const string &question,
                      const vector<string> &choices,
                      int myDefault)
{
    string input;

    while(1)   // use return to exit loop
    {
        cout << question << " (";

        int len = choices.size();
        for (int i = 0; i < len; i++)
        {
            cout << choices[i];
            if (i == myDefault)
                cout << "[default]";

            if(i != len-1)
                cout << ", ";
        }
        cout << ")" << endl;

        getline(cin, input);
        if(input.empty())
            return myDefault;

        for (int i = 0; i < choices.size(); i++)
            if (input.compare(choices[i]) == 0)
                return i;
    }
}




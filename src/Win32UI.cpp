//*********************************************************************
//
// Win32UI.cpp
//
// A class that defines a GUI interface using the Win32 API.
//
// Author: Jeff Bassett
//
// Updates:
//    09/14/2016  Created
// 
//*********************************************************************

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

#include "Card.h"
#include "Win32UI.h"

const string Win32UI::RANK_ABBR[] = {"A", "1", "2", "3", "4", "5", "6",
                                     "7", "8", "9", "10", "J", "Q", "K"};
const wchar_t* Win32UI::SUIT_UNICODE[] = {L"\u2660", L"\u2661", L"\u2662", L"\u2663"};


//*********************************************************************
//
// Win32IU::resetCursor
//
// Output some text.
//
//*********************************************************************
void Win32UI::resetCursor()
{
    cursorX = 10;
    cursorY = 10;
}


//*********************************************************************
//
// Win32IU::setContext
//
// Output some text.
//
//*********************************************************************
void Win32UI::setContext(HDC new_hdc)
{
    hdc = new_hdc;

    SIZE size;
    string myStr("M");
    GetTextExtentPoint32(hdc, myStr.c_str(), myStr.size(), &size);
    textHeight = size.cy;

    resetCursor();
}


//*********************************************************************
//
// Win32IU::text
//
// Output some text.
//
//*********************************************************************
void Win32UI::text(const string &str)
{
    TextOut(hdc, cursorX, cursorY, str.c_str(), str.size());
    cursorY += textHeight;
}


//*********************************************************************
//
// Win32IU::drawCard
//
// Draw a playing card at the current text cursor location, and update
// the text cursor location accordingly.
//
// Draw the back of a card if rank = -1.
//
//*********************************************************************
void Win32UI::drawCard(int rank, int suit)
{
    // Just write it out
    if (rank == -1)
        cout << "   <hidden>";
    else
    {
        string card("   " + Card::RANK_NAMES[rank] + " of " +
                    Card::SUIT_NAMES[suit]);
        text(card);
    }

    // I was going to us unicode to draw some cooler looking cards, but
    // unicode is kind of a bitch.  It's like a virus that takes over your
    // entire program.  I eventually decided to back out just to make sure I
    // could get something that works.
/*
    if (rank == -1)
        cout << "XX ";
    else
        wcout << Win32UI::RANK_ABBR << Win32UI::SUIT_UNICODE << " ";
*/    
}


//*********************************************************************
//
// Win32IU::choose
//
// Return a user selection from a list.
//
//*********************************************************************
int Win32UI::choose(const string &question,
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




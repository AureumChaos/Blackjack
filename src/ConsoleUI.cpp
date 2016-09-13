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

#include "ConsoleUI.h"

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




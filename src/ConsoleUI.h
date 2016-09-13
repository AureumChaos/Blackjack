//*********************************************************************
//
// ConsoleUI.h
//
// A class that defines a simple text user interface.
//
// Author: Jeff Bassett
//
// Updates:
//    09/12/2016  Created
// 
//*********************************************************************

#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
#include <vector>
using namespace std;

#include "BaseUI.h"

class ConsoleUI : public BaseUI
{
    public:
        static const string RANK_ABBR[];
        static const string SUIT_UNICODE[];

        ConsoleUI() {};
        ~ConsoleUI() {};
        virtual void text(const string &str);
        virtual void drawCard(int rank, int suit);
        virtual int choose(const string &question,
                           const vector<string> &choices,
                           int myDefault=0);
};

#endif

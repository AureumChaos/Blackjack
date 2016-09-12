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
        ConsoleUI() {};
        ~ConsoleUI() {};
        virtual void text(const string &str);
        virtual int choose(const string &question,
                           const vector<string> choices,
                           int myDefault=0);
};

#endif

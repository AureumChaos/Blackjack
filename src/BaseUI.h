//*********************************************************************
//
// BaseUI.h
//
// An abstract base class that defines a user interface.
//
// I don't actually have Windows on any of my computers, so I figured I'd just
// do the initial development on my Mac.  Instead of editting the code later
// to put the right Windows GUI calls in, I figured I'd make a couple of ui
// classes.  This way I can switch back and forth whenever I need to.  It
// might come in handy when I'm debugging.
//
// Author: Jeff Bassett
//
// Updates:
//    09/12/2016  Created
// 
//*********************************************************************

#ifndef BASEUI_H
#define BASEUI_H

#include <string>
#include <vector>
using namespace std;


class BaseUI
{
    public:
        BaseUI() {};
        virtual ~BaseUI() {};
        virtual void text(const string &str) = 0;
        virtual int choose(const string &question,
                           const vector<string> choices,
                           int myDefault=0) = 0;
};

#endif

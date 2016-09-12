//*********************************************************************
//
// Hand.cpp
//
// A class that defines a hand of cards in Blackjack
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
//    09/12/2016  Added evalHand() method to determine "soft" hands too.
// 
//*********************************************************************

#include <iostream>

#include "hand.h"

using namespace std;


//*********************************************************************
//
// Hand::~Hand
//
// Destructor - Delete all the cards in the hand
//
//*********************************************************************
Hand::~Hand()
{
    while(!empty())
    {
        delete back();
        pop_back();
    }
}


//*********************************************************************
//
// Hand::display
//
// Display the contants of the hand
//
//*********************************************************************
void Hand::display()
{
    vector<Card *>::iterator iter;
    for (iter = this->begin(); iter != this->end(); ++iter)
        (*iter)->display();
}


//*********************************************************************
//
// Hand::evalHand
//
// Collects and returns information about the current hand, including the
// value of the hand (with aces counted properly) and whether the had is soft
// or not (i.e. has a high value ace).
//
//*********************************************************************
void Hand::evalHand(int &value, bool &isSoft)
{
    int handVal = 0;
    int num_elevens = 0;   // The number of aces that were counted as 11

    vector<Card *>::iterator iter;
    for (iter = this->begin(); iter != this->end(); ++iter)
    {
        int val = (*iter)->value();

        // Keep track of aces
        if(val == 11)
            num_elevens++;

        handVal += val;
    }

    while(handVal > 21 && num_elevens > 0)
    {
        handVal -= 10;  // Count an ace as a 1
        num_elevens--;
    }

    value = handVal;
    isSoft = num_elevens > 0;
}


//*********************************************************************
//
// Hand::value
//
// I made this a function because calling evalHand can be a pain sometimes.
//
//*********************************************************************
int Hand::value()
{
    int value;
    bool isSoft;

    evalHand(value, isSoft);
    return value;
}



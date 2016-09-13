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
#include <sstream>

#include "BaseUI.h"
#include "Hand.h"

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
void Hand::display(BaseUI &ui, bool hide)
{
    stringstream ss;
    int i = 0;
    vector<Card *>::iterator iter;

    for (iter = this->begin(); iter != this->end(); ++iter)
    {
        if(hide && i == 0)
            ui.text("   <hidden>\n");
        else
            (*iter)->display(ui);

        i++;
    }
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


//*********************************************************************
//
// Hand::compareHands
//
// Compares this hand with another to determine which is the winner (if any).
//
// return values:
//   -1: The other hand wins.
//    0: Push. Tie. No hand wins.
//    1: This hand wins
//
//*********************************************************************
int Hand::compareHands(Hand &otherHand)
{
    int WIN=1, PUSH=0, LOSE=-1;
    int thisValue = this->value();   // No need to call these more than once.
    int otherValue = otherHand.value();

    if (thisValue > 21)
    {
        if(otherValue > 21)
            return PUSH;
        else
            return LOSE;
    }

    if (thisValue > otherValue || otherValue > 21)
        return WIN;

    if (thisValue == otherValue)
    {
        int thisSize = this->size();
        int otherSize = otherHand.size();

        // Handle cases of natural blackjack
        if(thisSize == 2 && otherSize > 2)
            return WIN;

        if(thisSize > 2 && otherSize == 2)
            return LOSE;

        return PUSH;
    }

    return LOSE;
}



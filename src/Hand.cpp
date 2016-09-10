//*********************************************************************
//
// hand.cpp
//
// A class that defines a hand of cards in Blackjack
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
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
    {
        (*iter)->display();
        cout<<endl;
    }
}


//*********************************************************************
//
// Hand::value
//
// Calculates the value of the hand.  In particular, this function deals
// with the values of aces appropriately.
//
//*********************************************************************
int Hand::value()
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

    return handVal;
}



//*********************************************************************
//
// card.h
//
// A class that defines a playing card
//
// Author: Jeff Bassett
//
// Updates:
//    09/09/2016  Created
// 
//*********************************************************************

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;


class Card
{
    private:
        int suit;
        int rank;

        static const string SUIT_NAMES[];
        static const string RANK_NAMES[];
        static const int RANK_VALUES[];

    public:
        static const int NUM_SUITS;
        static const int NUM_RANKS;

        Card(int rank, int suit);
        ~Card() {};
        void display();
        int value() {return Card::RANK_VALUES[this->rank];};
};

#endif

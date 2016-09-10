
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Card.h"
#include "Deck.h"
#include "Hand.h"


int main()
{
    Deck deck;
    Hand hand;

    deck.shuffle();

    //hand.push_back(deck.takeTopCard());
    //hand.display();
    //cout << hand.value() << endl << endl;

    hand.push_back(new Card(8, 0));   // 10 of Diamonds
    hand.display();
    cout << hand.value() << endl << endl;

    hand.push_back(new Card(5, 0));   // 7 of Diamonds
    hand.display();
    cout << hand.value() << endl << endl;

    hand.push_back(new Card(12, 0));   // Ace of Diamonds
    hand.display();
    cout << hand.value() << endl << endl;

    hand.push_back(new Card(12, 1));   // Ace of Hearts
    hand.display();
    cout << hand.value() << endl << endl;

    hand.push_back(new Card(12, 2));   // Ace of Clubs
    hand.display();
    cout << hand.value() << endl << endl;

    hand.push_back(new Card(12, 3));   // Ace of Spades
    hand.display();
    cout << hand.value() << endl << endl;
}



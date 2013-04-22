//
//  deck.h
//  PokerEval
//
//  Created by Nicholas Rodofile on 14/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __PokerEval__deck__
#define __PokerEval__deck__

#include <iostream>
#include "card.h"
#include "random.h"

const int CARDS_IN_DECK = 52;

class Deck{

public:
    Deck();
    ~Deck();
    Card* DealNextCard();
    void Shuffle();
    void DisplayDeck();
    
private:
    const int SHUFFLE_AMOUNT = 1000;
    const int START = 0;
    Card** deck;
    int cardsDealt;
    void SwapCard(int pickPos, int placePos);
};

#endif /* defined(__PokerEval__deck__) */

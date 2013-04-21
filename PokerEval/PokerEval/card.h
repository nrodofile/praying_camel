//
//  card.h
//  PokerEval
//
//  Created by Nicholas Rodofile on 14/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __PokerEval__card__
#define __PokerEval__card__

#include <iostream>
#include <string>


using namespace std;


const int TOTAL_SUITS = 4;
const int TOTAL_RANKS = 13;

enum Rank{

    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

enum Suit{
    DIAMONDS, CLUBS, HEARTS, SPADES
};
const string SUIT[TOTAL_SUITS] = {"♥", "♦", "♠", "♣"};
//const string SUIT[TOTAL_SUITS] = {"H", "D", "S", "C"};
const string RANK[TOTAL_RANKS] = {"2", "3", "4", "5", "6", "7", "8",
									"9", "T", "J", "Q", "K", "A"};

class Card{
    
private:
    Rank rank;
    Suit suit;
    
public:
    Card();
    Card(Rank rank, Suit suit);
    ~Card();
    Rank GetRank();
    Suit GetSuit();
    string ToString();
};

#endif /* defined(__PokerEval__card__) */

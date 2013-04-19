//
//  hand.h
//  PokerEval
//
//  Created by Nicholas Rodofile on 19/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __PokerEval__hand__
#define __PokerEval__hand__

#include <iostream>
#include "card.h"

enum HandType{
	HIGH_CARD, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND,
	STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND,
	STRAIGHT_FLUSH
};

class Hand	{
public:
	Hand(int player);
	~Hand();
	void AddCard(Card *card);
	void Evaluate();
	int GetValue();
	HandType GetHandType();
	void ClearHand();
	string ToString();
private:
	const int CARDS_IN_HAND = 5;
	const int FIRST = 0;
	int playerId;
	int totalCards;
	Card** hand;
	HandType handType;
};

#endif /* defined(__PokerEval__hand__) */

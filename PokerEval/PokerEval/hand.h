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


class Hand	{
public:
	Hand(int player);
	~Hand();
	void AddCard(Card *card);
	void Evaluate();
	int GetValue();
	string ToString();
private:
	enum HandType{
		HIGH_CARD, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND,
		STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND,
		STRAIGHT_FLUSH
	};
	int playerId;
};

#endif /* defined(__PokerEval__hand__) */

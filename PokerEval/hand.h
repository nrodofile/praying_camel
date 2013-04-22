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
#include <vector>
#include <list>
#include "card.h"
#include "cardComparer.h"
#include <math.h>

enum HandType{
	HIGH_CARD, ONE_PAIR, TWO_PAIRS, THREE_OF_A_KIND,
	STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND,
	STRAIGHT_FLUSH
};

const string HAND_TYPE[9] = {
	"High Card", "One Pair", "Two Pairs", "Three of a Kind",
	"Stright", "Flush", "Full House", "Four of a Kind",
	"Stright Flush"};

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
	const int FIRST_CARD = 1;
	const int ONE_CARD = 1;
	const int ONE_RANK = 1;
	vector<Card*> hand;
	vector<Card*>::iterator it;
	HandType type;
	enum Kind{
		FOUR = 4,
		THREE = 3,
		PAIR = 2
	};

	int Id;
	int value;
	void EvaluateType();
	void EvaluateValue();
	void EvalStandard();
	void EvalKind(Kind kind);
	bool IsFlush();
	bool IsStraight();
	bool IsN_Of_A_Kind(Kind kind, bool sort);
	bool IsPair(Kind kind, bool two, bool sort);
	double base = 13.0;
};

#endif /* defined(__PokerEval__hand__) */

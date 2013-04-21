//
//  hand.cpp
//  PokerEval
//
//  Created by Nicholas Rodofile on 19/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "hand.h"

/*
 *  Hand - Constructor
 *--------------------------------------------------
 *  Sets player ID  
 */
Hand::Hand(int playerID){
	this->playerId = playerID;
}

/*
 *	~Hand - Distructor
 *--------------------------------------------------
 *	Deletes the hand vector
 */
Hand::~Hand(){

}

/*
 *	AddCard
 *--------------------------------------------------
 *	Adds card to hand, checks if the hand 
 *	full before adding the card to the hand
 */
void Hand::AddCard(Card *card){
	if(hand.size() >= CARDS_IN_HAND){
		cerr << "Player " << to_string(playerId) <<
				"'s Hand is FULL!!" << endl;
	}else{
		hand.push_back(card);
	}
}

/*
 * Evaluate
 *--------------------------------------------------
 *  Pre:
 *  Post:
 *--------------------------------------------------
 */
void Hand::Evaluate(){
	
	sort(hand.begin(), hand.end(), CardComparer());
	EvaluateType();
}

/*
 * EvaluateType
 *--------------------------------------------------
 *  Pre:	Type of hand is Unknown
 *  Post:	The type of hand is evaluated
 *--------------------------------------------------
 *	Evaluates the hand on each hand type available
 *
 */
void Hand::EvaluateType(){
	
	if(IsStraight() && 	IsFlush()){
		type = STRAIGHT_FLUSH;
	}else if (IsN_Of_A_Kind(FOUR)){
		type = FOUR_OF_A_KIND;
	}else if (	IsN_Of_A_Kind(THREE) && IsPair(PAIR, false)){
		type = FULL_HOUSE;
	}else if (IsFlush()){
		type = FLUSH;
	}else if (IsStraight()){
		type = STRAIGHT;
	}else if (IsN_Of_A_Kind(THREE)){
		type = THREE_OF_A_KIND;
	}else if (IsPair(PAIR, true)){
		type = TWO_PAIRS;
	}else if (IsPair(PAIR, false)){
		type = ONE_PAIR;
	}else{
		type = HIGH_CARD;
	}
}

/*
 * IsStraight
 *--------------------------------------------------
 *	Checks if the next card is one rank higher than 
 *	the current card.
 *
 *	Returns: true if the hand contains a straight 
 */
bool Hand::IsStraight(){
	int straight = FIRST;
	for (int card = FIRST; card < hand.size()-1; card++){
		if(hand.at(card+1)->GetRank() == hand.at(card)->GetRank()+1){
			straight++;
		}else{
			return false;
		}
	}
	return (straight == CARDS_IN_HAND-1);
}

/*
 * IsFlush
 *--------------------------------------------------
 *	Check if all the cards in the hand have the same
 *	Suit as the first card.
 *
 *	Returns: true if the hand contains a straight 
 */
bool Hand::IsFlush(){
	int flush = FIRST;
	for (int card = FIRST+1; card < hand.size(); card++){
		if(hand.at(card)->GetSuit() == hand.at(FIRST)->GetSuit()){
			flush++;
		}else{
			return false;
		}
	}
	return (flush == CARDS_IN_HAND-1);
}


/*
 * IsN_Of_A_Kind
 *--------------------------------------------------
 *	checks the hand for a kind (3 of a kind or four
 *	of a kind), loops through and trys to find the
 *	kind requested.
 *	
 *	Returns: true if the kind is found
 */
bool Hand::IsN_Of_A_Kind(Kind kind){
	int found = 1;
	for(int i = 0; i < CARDS_IN_HAND - kind; ++i){
		for (int card = FIRST; card < kind; card++){
			if( hand.at(card+i)->GetRank() == hand.at(card+(1+i))->GetRank()){
				found++;
				if(found == kind){
					return true;
				}
			}else{
				found = 1;
			}
		}
	}
	return false;
}

/*
 * IsPair
 *--------------------------------------------------
 *	checks if pairs exists in the hand, can check for 
 *	2 pairs of pairs
 *	Returns: true if a pair is found
 *	Returns: true if 2 pairs are found;
 */
bool Hand::IsPair(Kind kind, bool twoPairs){
	int found = FIRST_CARD;
	int pair = 0;
	for(int i = 0; i < CARDS_IN_HAND - FIRST_CARD; i++){
		if(hand.at(i)->GetRank() == hand.at(i+1)->GetRank()){
			found++;
		}else{
			if(found == kind){
				pair++;
			}
			found = FIRST_CARD;
		}
	}
	if(found == kind){
		pair++;
	}
	if(twoPairs && (pair == PAIR)){
		return true;
	}else if(pair && !twoPairs){
		return true;
	}
	return false;
}


/*
 * ClearHand
 *--------------------------------------------------
 *  Pre:	The vector is populated with cards
 *  Post:	All cards are removed from the vector
 *--------------------------------------------------
 */
void Hand::ClearHand(){
	hand.erase(hand.begin(), hand.end());
}

/*
 *	GetValue
 *--------------------------------------------------
 *  Returns: The value of the hand
 */
int Hand::GetValue(){
	return value;
}

/*
 *	GetHandType
 *--------------------------------------------------
 *  Returns: The hand type of the hand
 */
HandType Hand::GetHandType(){
	return type;
}

/*
 *	ToString
 *--------------------------------------------------
 *  Pre:
 *  Post:
 *--------------------------------------------------
 *  Returns: All the cards in the hand
 */
string Hand::ToString(){
	Evaluate();////////MAY NEED DELEATE
	string playersHand;
	for (int card = FIRST; card < hand.size(); card++){
		playersHand += hand.at(card)->ToString() + "\t";
	}

	return 	"Player " + to_string(playerId) +
					"\t" + playersHand + HAND_TYPE[type];
}


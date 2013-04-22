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
	this->Id = playerID;
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
		cerr << "Player " << to_string(Id) <<
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
	EvaluateValue();
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
	}else if (IsN_Of_A_Kind(FOUR, true)){
		type = FOUR_OF_A_KIND;
	}else if (	IsN_Of_A_Kind(THREE, false) && IsPair(PAIR, false, false)){
		type = FULL_HOUSE;
	}else if (IsFlush()){
		type = FLUSH;
	}else if (IsStraight()){
		type = STRAIGHT;
	}else if (IsN_Of_A_Kind(THREE, true)){
		type = THREE_OF_A_KIND;
	}else if (IsPair(PAIR, true, false)){
		type = TWO_PAIRS;
	}else if (IsPair(PAIR, false, false)){
		type = ONE_PAIR;
	}else{
		type = HIGH_CARD;
	}
}

void Hand::EvaluateValue(){
	int val = ACE;
	switch(type){
		case HIGH_CARD:
			EvalStandard();
			break;
		case ONE_PAIR:
			val = ACE;
			value += pow ((hand.at(FIRST)->GetRank()*base),CARDS_IN_HAND-ONE_CARD);
			value += pow ((val*base),CARDS_IN_HAND-(ONE_CARD*2));

			for(int i = 2; i > CARDS_IN_HAND; i++){
				value += pow ((val*base),i);
			}
		case TWO_PAIRS:
			EvalKind((Kind)4);
			break;
		case THREE_OF_A_KIND:
			EvalKind(THREE);
			break;
		case STRAIGHT:
			EvalStandard();
			break;
		case FLUSH:
			EvalStandard();
			break;
		case FULL_HOUSE:
			EvalStandard();
			break;
		case FOUR_OF_A_KIND:
			EvalKind(FOUR);
			break;
		case STRAIGHT_FLUSH:
			EvalStandard();
			break;
		default:
			EvalStandard();
	}
}

void Hand::EvalStandard(){
	for(int i = CARDS_IN_HAND-1; i > 0; i--){
		value += pow ((hand.at(i)->GetRank()*13.0),i);
	}
}

void Hand::EvalKind(Kind kind){
	int val = ACE;
	value += pow ((hand.at(FIRST)->GetRank()*13.0),CARDS_IN_HAND-1);
	for(int i = 1; i > ((kind) - ONE_CARD); i++){
		value += pow ((val*13.0),i);
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
	int handSize = CARDS_IN_HAND - ONE_CARD;
	if(hand.at(CARDS_IN_HAND-ONE_CARD)->GetRank() == ACE){
		if(hand.at(FIRST)->GetRank()==TWO){
			straight++;
			handSize--;
		}
	}	
	for (int card = FIRST; card <handSize; card++){
		if(hand.at(card+ONE_CARD)->GetRank() == hand.at(card)->GetRank()+ONE_RANK){
			straight++;
		}else{
			return false;
		}
	}
	return (straight == CARDS_IN_HAND - ONE_CARD);
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
	for (int card = FIRST+ONE_CARD; card < hand.size(); card++){
		if(hand.at(card)->GetSuit() == hand.at(FIRST)->GetSuit()){
			flush++;
		}else{
			return false;
		}
	}
	return (flush == CARDS_IN_HAND - ONE_CARD);
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
bool Hand::IsN_Of_A_Kind(Kind kind, bool sort){
	int found = FIRST_CARD;
	for(int i = 0; i < CARDS_IN_HAND - kind; ++i){
		for (int card = FIRST; card < kind; card++){
			if( hand.at(card+i)->GetRank() ==
				hand.at(card+(ONE_CARD+(ONE_CARD * i)))->GetRank()){
				found++;
				if(found == kind){
					if (sort){
						for(int j = card + ONE_CARD; j>0; j--){
							Card *aKind = hand.at(card+ONE_CARD);
							hand.erase(hand.begin()+(card+ONE_CARD));
							hand.insert(hand.begin(),aKind);
						}
					}				
				return true;
				}
			}else{
				found = ONE_CARD;
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
bool Hand::IsPair(Kind kind, bool twoPairs, bool sort){
	int found = FIRST_CARD;
	int pair = 0;
	for(int card = 0; card < CARDS_IN_HAND - FIRST_CARD; card++){
		Card *card1 = hand.at(card);
		Card *card2 = hand.at(card + ONE_CARD);
		
		if(card1->GetRank() == card2->GetRank()){
			found++;
		}else{
			if(found == kind){
				pair++;
				if(sort){
				Card *pair1 = hand.at(card);
				Card *pair2 = hand.at(card - ONE_CARD);
				hand.erase(hand.begin()+card);
				hand.erase(hand.begin()+(card -ONE_CARD));
				hand.insert(hand.begin(),pair1);
				hand.insert(hand.begin(),pair2); 
				}
			}
			found = FIRST_CARD;
		}
	}
	if(found == kind){
		pair++;
		if(sort){
			Card *pair1 = hand.at(CARDS_IN_HAND-1);
			Card *pair2 = hand.at(CARDS_IN_HAND - 2);
			hand.erase(hand.begin()+(CARDS_IN_HAND-1));
			hand.erase(hand.begin()+(CARDS_IN_HAND - 2));
			hand.insert(hand.begin(),pair1);
			hand.insert(hand.begin(),pair2);
		}
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
 *  Returns: All the cards in the hand
 */
string Hand::ToString(){
	sort(hand.begin(), hand.end(), CardComparer());
	string playersHand = "Player " + to_string(Id) + "\t";
	for (int card = FIRST; card < hand.size(); card++){
		playersHand += hand.at(card)->ToString() + "\t";
	}

	return playersHand + HAND_TYPE[type];
}


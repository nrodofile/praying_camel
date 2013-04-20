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

void Hand::EvaluateType(){
	
	//STRAIGHT
	int straight = FIRST;
	for (int card = FIRST; card < hand.size()-1; card++){
		if(hand.at(card+1)->GetRank() == hand.at(card)->GetRank()+1){
			straight++;
		}else{
			break;
		}
	}
	if(straight == CARDS_IN_HAND-1){
		handType = STRAIGHT;
	}
	
	int flush = FIRST;
	for (int card = FIRST; card < hand.size()-1; card++){
		if(hand.at(card)->GetSuit() == hand.at(FIRST)->GetSuit()){
			flush++;
		}else{
			break;
		}
	}
	if(flush == CARDS_IN_HAND-1){
		handType = FLUSH;
	}
		
	//FOUR_OF_A_KIND,
	//FULL_HOUSE,
	//FLUSH,
	//STRAIGHT,
	//THREE_OF_A_KIND,
	//TWO_PAIRS,
	//ONE_PAIR,
	//HIGH_CARD,








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
	return handType;
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
	string playersHand;
	for (int card = FIRST; card < hand.size(); card++){
		playersHand += hand.at(card)->ToString() + "\t";
	}

	return 	"Player " + to_string(playerId) +
					"\t" + playersHand + HAND_TYPE[handType];
}


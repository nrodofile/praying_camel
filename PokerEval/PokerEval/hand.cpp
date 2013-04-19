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
	hand = new Card*[CARDS_IN_HAND];
	this->playerId = playerID;
	totalCards = 0;
}

/*
 *	~Hand - Distructor
 *--------------------------------------------------
 *	Deletes the hand vecter
 */
Hand::~Hand(){
    delete hand;
}

/*
 *	AddCard
 *--------------------------------------------------
 *	Adds card to hand, checks if the hand 
 *	full before adding the card to the hand
 */
void Hand::AddCard(Card *card){
	if(totalCards >= CARDS_IN_HAND){
		cerr << "Player " << to_string(playerId) <<
				"'s Hand is FULL!!" << endl;
	}else{
		hand[totalCards] = card;
		totalCards++;
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
	
}

void Hand::ClearHand(){
	totalCards = 0;
}

/*
 *	GetValue
 *--------------------------------------------------
 *  Pre:	the request of the hand
 *  Post:
 *--------------------------------------------------
 *  Returns: The value of the hand
 */
int Hand::GetValue(){
	return 0;
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
	for (int card = FIRST; card < totalCards; card++){
		playersHand += hand[card]->ToString() + "\t";
	}

	return 	"Player " + to_string(playerId) +
					"\t" + playersHand;
}


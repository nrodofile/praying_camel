//
//  main.cpp
//  PokerEval
//
//  Created by Nicholas Rodofile on 14/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "deck.h"
#include "card.h"
#include "hand.h"
//#include "handcomparer.h"

#include "cardComparer.h" //Remove


using namespace std;

const int PLAYERS = 10;
const int CARDS_PER_PLAYER = 5;


int main(int argc, char *argv[]) {


	cout << "Stright Flush" << endl;
	Hand SF =  Hand(1);
	for (int i = 0; i < CARDS_PER_PLAYER; i++){

		Card *card = new Card((Rank)(i+5), (Suit)0);
		SF.AddCard(card);
	}
	cout << SF.ToString() <<endl <<endl;
	
	
	cout << "Four OF A kind" << endl;
	Hand FOAK =  Hand(1);
	for (int i = 0; i < 4; i++){
		
		Card *card = new Card((Rank)(1), (Suit)i);
		FOAK.AddCard(card);
	}
	Card *cardFOAK = new Card((Rank)(2), (Suit)1);
	FOAK.AddCard(cardFOAK);
	cout << FOAK.ToString() <<endl <<endl;
	
	
	cout << "FullHouse" << endl;
	Hand FH =  Hand(1);
	for (int i = 0; i < 3; i++){
		
		Card *card = new Card((Rank)(1), (Suit)i);
		FH.AddCard(card);
	}
	for (int i = 0; i < 2; i++){
		
		Card *card = new Card((Rank)(2), (Suit)i);
		FH.AddCard(card);
	}

	cout << FH.ToString() <<endl <<endl;
	
	cout << "Flush" << endl;
	Hand F =  Hand(1);
	for (int i = 0; i < 4; i++){
		
		Card *card = new Card((Rank)(i), (Suit)2);
		F.AddCard(card);
	}
	Card *cardF = new Card((Rank)(11), (Suit)2);
	F.AddCard(cardF);
	cout << F.ToString() <<endl <<endl;

	
	cout << "Stright" << endl;
	Hand S =  Hand(1);
	for (int i = 0; i < 4; i++){
		
		Card *card = new Card((Rank)(i), (Suit)0);
		S.AddCard(card);
	}
	Card *cardS = new Card((Rank)(4), (Suit)1);
	S.AddCard(cardS);
	cout << S.ToString() <<endl <<endl;
	
	
	cout << "Three OF A Kind" << endl;
	Hand TOAK =  Hand(1);
	for (int i = 0; i < 3; i++){
		
		Card *card = new Card((Rank)(1), (Suit)i);
		TOAK.AddCard(card);
	}
	Card *cardTOAK = new Card((Rank)(4), (Suit)1);
	TOAK.AddCard(cardTOAK);
	
	Card *cardTOAK1 = new Card((Rank)(12), (Suit)3);
	TOAK.AddCard(cardTOAK1);
	cout << TOAK.ToString() <<endl <<endl;
	
	
	
	cout << "TWO PAIRS" << endl;
	Hand TP =  Hand(1);
	for (int i = 0; i < 2; i++){
		
		Card *card = new Card((Rank)(1), (Suit)i);
		TP.AddCard(card);
	}
	for (int i = 0; i < 2; i++){
		
		Card *card = new Card((Rank)(2), (Suit)i);
		TP.AddCard(card);
	}
	Card *cardTP = new Card((Rank)(4), (Suit)1);
	TP.AddCard(cardTP);

	cout << TP.ToString() <<endl <<endl;

	
	cout << "One Pair" << endl;
	Hand OP =  Hand(1);
	for (int i = 0; i < 2; i++){
		
		Card *card = new Card((Rank)(1), (Suit)i);
		OP.AddCard(card);
	}
	Card *cardOP = new Card((Rank)(9), (Suit)2);
	OP.AddCard(cardOP);
	Card *cardOP1 = new Card((Rank)(11), (Suit)1);
	OP.AddCard(cardOP1);
	Card *cardOP2 = new Card((Rank)(8), (Suit)3);
	OP.AddCard(cardOP2);
	
	cout << OP.ToString() <<endl <<endl;
	
	
	
	
	
	cout << "Deal Test" << endl;
	Deck deck;
	Hand **player = new Hand*[PLAYERS];
	for(int p = 0; p < PLAYERS; p++){
		player[p] = new Hand(p+1);
	}
	deck.Shuffle();
	deck.DisplayDeck();

	for(int d = 0; d < CARDS_PER_PLAYER; d++){
		for(int p = 0; p < PLAYERS; p++){
			player[p]->AddCard(deck.DealNextCard());
		}
	}

	for(int i = 0; i < PLAYERS; i++){
		cout << player[i]->ToString() << endl;
	}

	for(int i = 0; i < PLAYERS; i++){
		player[i]->ClearHand();
	}

	for(int i = 0; i < PLAYERS; i++){
		delete player[i];
	}
	return 0;
    
}


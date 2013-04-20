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

#include "cardComparer.h"


using namespace std;

const int PLAYERS = 10;
const int CARDS_PER_PLAYER = 5;


int main(int argc, char *argv[]) {
    
	Deck *deck = new Deck();
	Hand **player = new Hand*[PLAYERS];
	for(int p = 0; p < PLAYERS; p++){
		player[p] = new Hand(p+1);
	}

	cout << "second" << endl;
	deck->Shuffle();
	deck->DisplayDeck();

	for(int d = 0; d < CARDS_PER_PLAYER; d++){
		for(int p = 0; p < PLAYERS; p++){
			player[p]->AddCard(deck->DealNextCard());
		}
	}

	for(int i = 0; i < PLAYERS; i++){
		player[i]->Evaluate();
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


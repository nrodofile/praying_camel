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
#include "handcomparer.h"

using namespace std;

const int PLAYERS = 10;
const int CARDS_PER_PLAYER = 5;


int main(int argc, char *argv[]) {
	
    // Declare Deck and vector of pointer to Hand
	Deck *deck = new Deck();
	vector<Hand*> table;
	
    // create Hand for each player
	for(int p = 0; p < PLAYERS; p++){
		Hand *player = new Hand(p);
		table.push_back(player);
	}
	
	
	/// NOTE>>>>> changed argc expression to true
	
    // allow for testing from file
    if (argc == 2) {
		
        // open the file and check it exists
        ifstream infile;
        infile.open(argv[1]);
        if (infile.fail()) {
            cerr <<  "Error: Could not find file" << endl;
            return 1;
        }
		
        // read the cards into the hands
        int rank, suit;
        for (int card = 0; card < CARDS_PER_PLAYER; card++) {
            for (int i = 0; i < PLAYERS; i++) {
                infile >> rank >> suit;
                Card *card = new Card((Rank)rank, (Suit)suit);
                table.at(i)->AddCard(card);
            }
        }
		
        // close the file
        infile.close();
    } else {
		
        // shuffle
		deck->Shuffle();
		
        // deal the cards
		for(int card = 0; card < CARDS_PER_PLAYER; card++){
			for (int player = 0; player <  PLAYERS; player++){
				table.at(player)->AddCard(deck->DealNextCard());
			}
		}
    }
	
    // evaluate the hands
	for (int player = 0; player < PLAYERS; player++){
		table.at(player)->Evaluate();
	}
    // sort the hands
	sort(table.begin(), table.end(), HandComparer());
	
    // output the hands
	for (int player = 0; player <  PLAYERS; player++){
		cout << table.at(player)->ToString() << endl;
	}
	
	
	
	
	return 0;
}


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

	Card *card = new Card((Rank)9,(Suit)1);
		Card *card1 = new Card((Rank)9,(Suit)1);
		Card *card2 = new Card((Rank)10,(Suit)2);
		Card *card3 = new Card((Rank)11,(Suit)1);
		Card *card4 = new Card((Rank)12,(Suit)1);

	Hand player =  Hand(1);
	player.AddCard(card);
		player.AddCard(card1);
		player.AddCard(card2);
		player.AddCard(card3);
		player.AddCard(card4);

	player.Evaluate();
	cout << player.ToString();

    
	return 0;
    
}


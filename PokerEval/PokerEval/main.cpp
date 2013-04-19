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
    
//    Random *random_suit = new Random(1,4);
//    Random *random_rank = new Random(1,10);
//
//    for (int j = 0; j < 2; j++){
//        for (int i = 0;i <52; i++ ){
//            int suit = random_suit->RandomInt();
//            int rank = random_rank->RandomInt();
//            cout << suit << rank << " ";
//        }
//        cout << endl;
//    }
//
//    random_rank->~Random();
//    random_suit->~Random();
//
//    cout << "Deal Test" << endl;
//
//    Deck *deck = new Deck();
//
//    Card *card = deck->DealNextCard();
//    //cout << card->ToString() << endl;
//    
//    for(int i = 0; i < 30; i++){
//        card = deck->DealNextCard();
//        cout << card->ToString() << endl;
//    }
//    cout << "shuffle Test" << endl;
//    
//    cout << "shuffle Test" << endl;
//    
//    deck->Shuffle();
//    deck->DisplayDeck();
//    
//    Card *card;
    //cout << card->ToString() << endl;
//	cout << "shuffle deal Test" << endl;
//	
//    for(int i = 0; i < 100; i++){
//        card = deck->DealNextCard();
//        if(card == NULL){
//            cout << "NULL" << endl;
//        }else{
//            cout << card->ToString() << endl;
//        }
//        if(i == 75){
//            deck->Shuffle();
//        }
//    }
//	Hand **player = new Hand*[PLAYERS];
//	for(int p = 0; p < PLAYERS; p++){
//		player[p] = new Hand(p+1);
//	}
//	
//	cout << "second" << endl;
//	deck->Shuffle();
//	deck->DisplayDeck();
//	
//	for(int d = 0; d < CARDS_PER_PLAYER; d++){
//		for(int p = 0; p < PLAYERS; p++){
//			player[p]->AddCard(deck->DealNextCard());
//		}
//	}
//
//	for(int i = 0; i < PLAYERS; i++){
//		cout << player[i]->ToString() << endl;
//	}
//	
//	for(int i = 0; i < PLAYERS; i++){
//		player[i]->ClearHand();
//	}
//
//	for(int i = 0; i < PLAYERS; i++){
//		delete player[i];
//	}
//		delete player;
	Card *card1 = new Card((Rank)9,(Suit)1);
	Card *card2 = new Card((Rank)8,(Suit)2);
	CardComparer compare = CardComparer();
	if(compare.operator()(card2, card1)){
		cout << "yes";
	}else{
		cout << "no";
	}
	
    return 0;
    
}


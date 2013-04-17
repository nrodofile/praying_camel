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
#include "random.h" //remove
//#include "hand.h"
//#include "handcomparer.h"

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
    
//    cout << "Deal Test" << endl;
    
    Deck *deck = new Deck();
    
//    Card *card = deck->DealNextCard();
//    //cout << card->ToString() << endl;
//    
//    for(int i = 0; i < 30; i++){
//        card = deck->DealNextCard();
//        cout << card->ToString() << endl;
//    }
//    cout << "shuffle Test" << endl;
    
    cout << "shuffle Test" << endl;
    
    deck->Shuffle();
    deck->DisplayDeck();
    
    Card *card = deck->DealNextCard();
    //cout << card->ToString() << endl;
    
    for(int i = 0; i < 100; i++){
        card = deck->DealNextCard();
        if(card == NULL){
            cout << "NULL" << endl;
        }else{
            cout << card->ToString() << endl;
        }
        if(i == 75){
            deck->Shuffle();
        }
    }
    cout << "shuffle deal Test" << endl;
    
   // card->~Card();
    deck->~Deck();
    return 0;
    
}


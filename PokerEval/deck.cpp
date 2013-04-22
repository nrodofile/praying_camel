//
//  deck.cpp
//  PokerEval
//
//  Created by Nicholas Rodofile on 14/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "deck.h"

/*--------------------------------------------------
 *  Deck Constructor
 *--------------------------------------------------
 *  No Argument constructor – Creates Vecter of 
 *  Card* objects and initialises them.
 *  Initialises cardsDealt to the start of the deck.
 */
Deck::Deck(){
    deck = new Card*[CARDS_IN_DECK];
    for (int suit = START; suit < TOTAL_SUITS; suit++){
        for (int rank = START; rank < TOTAL_RANKS; rank++){
            deck[suit * TOTAL_RANKS + rank] = new Card((Rank)rank,(Suit)suit);
        }
    }
    cardsDealt = START;
}

/*--------------------------------------------------
 *  Deck destructor
 *--------------------------------------------------
 *  Deletes the contents of the deck Vecter of
 *  Card*
 */
Deck::~Deck(){
    for (int card = START; card < CARDS_IN_DECK; card++){
        delete deck[card];
    }
    delete deck;
}

/*
 *  DealNextCard
 *--------------------------------------------------
 *  Pre:    cardsDealt has not been incremented
 *  Post:   cardsDealt incremented and pointer 
 *          of card returned
 *--------------------------------------------------
 *  Returns:    Null if All cards are dealt
 *  Returns:    a pointer to the next Card object
 *              from the deck
 */
Card* Deck::DealNextCard(){
    if(cardsDealt > CARDS_IN_DECK){
			cerr << "Deck out of cards" << endl;
        return NULL;
    }
    return deck[cardsDealt++];
}

/*--------------------------------------------------
 *  Shuffle
 *--------------------------------------------------
 *  Shuffles the cards in the deck to the suffle amount
 *  and resets the cards being dealt
 */
void Deck::Shuffle(){
    Random *position = new Random(START, CARDS_IN_DECK);
    for(int shuffle = START; shuffle < SHUFFLE_AMOUNT; shuffle++){
        SwapCard(position->RandomInt(), position->RandomInt());
    }
    cardsDealt = START;
    position->~Random();
}

/*--------------------------------------------------
 *  SwapCard
 *--------------------------------------------------
 *  picks card from one position 
 *  swaps card with a second position 
 */
void Deck::SwapCard(int pos1, int pos2){
    Card *card = deck[pos1];
    deck[pos1] = deck[pos2];
    deck[pos2] = card;
    card->~Card();
}

/*--------------------------------------------------
 *  DisplayDeck
 *--------------------------------------------------
 *  Displays All cards in deck from the top
 *  Displays in 4 rows
 */
void Deck::DisplayDeck(){
    for (int suit = START; suit < TOTAL_SUITS; suit++) {
        for (int rank = START; rank < TOTAL_RANKS; rank++) {
            cout << deck[suit * TOTAL_RANKS + rank]->ToString() << "\t";
        }
        cout << endl;
    }
}
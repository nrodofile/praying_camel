//
//  card.cpp
//  PokerEval
//
//  Created by Nicholas Rodofile on 14/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "card.h"

/*--------------------------------------------------
 *  Card Constructor
 *--------------------------------------------------
 *  No Argument constructor 
 */
Card::Card(){
    
}//END

/*--------------------------------------------------
 *  Card Constructor
 *--------------------------------------------------
 *  Argument constructor – 
 *  initialises rank and suit
 *  
 */
Card::Card(Rank rank, Suit suit){    
    this->rank = rank;
    this->suit = suit;
}

/*--------------------------------------------------
 *  Card Destructor
 *--------------------------------------------------
 *  Does nothing
 */
Card::~Card(){

}

/*--------------------------------------------------
 *  GetRank
 *--------------------------------------------------
 *  Returns:    Rank of the card
 */
Rank Card::GetRank(){
    return rank;
}

/*--------------------------------------------------
 *  GetRank
 *--------------------------------------------------
 *  Returns:    Suit of the card
 */
Suit Card::GetSuit(){
    return suit;
}

/*--------------------------------------------------
 *  ToString
 *--------------------------------------------------
 *  Returns:    The Suit and the Rank of the card
 *              in the form of a string using Chars 
 *              from the Suits and Rank arrays.
 */

string Card::ToString(){
    return SUIT[suit] + RANK[rank];
}
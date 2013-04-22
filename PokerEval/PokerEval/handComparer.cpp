//
//  handComparer.cpp
//  PokerEval
//
//  Created by Nicholas Rodofile on 22/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "handComparer.h"
bool HandComparer::operator()(Hand *player1, Hand *player2){
	if(player1->GetHandType() == player2->GetHandType()){
			return (player1->GetValue() < player2->GetValue());
	}
	return (player1->GetHandType() < player2->GetHandType());
}
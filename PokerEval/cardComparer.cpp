//
//  cardComparer.cpp
//  PokerEval
//
//  Created by Nicholas Rodofile on 19/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "cardComparer.h"

bool CardComparer::operator()(Card *card1, Card *card2){
	if(card1->GetRank() < card2->GetRank()){
		return true;
	}
	return false;
}
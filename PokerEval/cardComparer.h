//
//  cardComparer.h
//  PokerEval
//
//  Created by Nicholas Rodofile on 19/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __PokerEval__cardComparer__
#define __PokerEval__cardComparer__

#include <iostream>
#include "card.h"

class CardComparer{
public:
	bool operator() (Card*, Card*);
};
#endif /* defined(__PokerEval__cardComparer__) */

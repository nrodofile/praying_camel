//
//  handComparer.h
//  PokerEval
//
//  Created by Nicholas Rodofile on 22/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __PokerEval__handComparer__
#define __PokerEval__handComparer__

#include <iostream>
#include "hand.h"

class HandComparer{
public:
	bool operator() (Hand*, Hand*);
};
#endif /* defined(__PokerEval__handComparer__) */

//
//  random.h
//  PokerEval
//
//  Created by Nicholas Rodofile on 14/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __PokerEval__random__
#define __PokerEval__random__

#include <iostream>
#include <cstdlib>
#include <ctime>

class Random
{
    
private:
    int low;
    int high;
    void Randomise();

public:
    Random(int low, int high);
    ~Random();
    int RandomInt();
};

#endif /* defined(__PokerEval__random__) */

//
//  random.cpp
//  PokerEval
//
//  Created by Nicholas Rodofile on 14/04/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "random.h"
/*
 *  Random Constructor
 *--------------------------------------------------
 *  No Argument constructor – Initialises low and 
 *  height.
 *  Initialises random generator
 */
Random::Random(int low, int high){
    this->low = low;
    this->high = high;
    Randomise();
}

/*
 *  Random Destructor
 *--------------------------------------------------
 *  does nothing.
 */
Random::~Random(){
    //Does nothing 
}

/*
 *  DealNextCard
 *--------------------------------------------------
 *  Pre:    Random number not generated
 *  Post:   Random number is generated from high and
 *          low 
 *--------------------------------------------------
 *  Returns:    RandomInt derived from high and low
 *--------------------------------------------------
 *  creates random number in decimal then casts it
 *  to an integer.
 *
 */
int Random::RandomInt(){
    double random = double(rand() / (double(RAND_MAX) + 1));
    int randomInt = int(random * (high - low));
    return low + randomInt;
}

/*
 *  DealNextCard
 *--------------------------------------------------
 *  Initialises the random-number generator.
 */
void Random::Randomise(){ 
    srand(int(time(NULL)));
}
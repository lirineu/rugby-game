#ifndef ATTACKER_H
#define ATTACKER_H

// Standard headers
#include <stdlib.h>

// Internal headers
#include "position.h"
#include "spy.h"

// Functions

/**
 * Main algorithm to move Attacker player in a Game.
 * Given the player position, it should decide the next direction
 * they will take in the field.
 */
direction_t execute_attacker_strategy(position_t attacker_position,
                                      Spy defender_spy){
    static int Rodada = 0;
    int Max, Rand, DirVer, DirHor;
    direction_t Dir;

    Rodada++;

    Max = RAND_MAX;
    Rand = random();

    if(Rand > 0.7 * Max){
        DirVer = -1;
    }
    else if(Rand < 0.3 * Max){
        DirVer = 1;
    }
    else{
        DirVer = 0;
    }

    Rand = random();


    if(Rand > 0.9 * Max){
        DirHor = -1;
    }
    else if(Rand < 0.8 * Max){
        DirHor = 1;
    }
    else{
        DirHor = 0;
    }

    Dir = {DirVer, DirHor};

    move_position(attacker_position, Dir);

    return;    
}

#endif // ATTACKER_H

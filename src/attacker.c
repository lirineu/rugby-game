// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
  {
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
}

/*----------------------------------------------------------------------------*/

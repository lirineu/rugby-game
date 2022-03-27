#ifndef DEFENDER_H
#define DEFENDER_H

//Standard headers
#include <stdlib.h>

// Internal headers
#include "position.h"
#include "spy.h"

// Functions

/**
 * Main algorithm to move Defender player in a Game.
 * Given the player position, it should decide the next direction
 * they will take in the field.
 */
direction_t execute_defender_strategy(position_t defender_position,
                                      Spy attacker_spy){
  static int Rodada = 0;
  static int Random = random();
  static position_t Spy;
  position_t Dir;
  
  Rodada++;
  

  if(Rodada < Random){
    Dir = DIR_RIGHT;
  }
  else if(Rodada == Random){
    Spy = get_spy_position(attacker_spy);
    if(Spy.j > defender_position.j){
        Dir = DIR_STAY;
    }
    else if(Spy.i > defender_position.i){
        Dir = DIR_DOWN_LEFT;
    }
    else if(Spy.i < defender_position.i){
        Dir = DIR_DOWN_RIGHT;
    }
    else{
        Dir = DIR_RIGHT;
    }

  }
  else{
    if(Spy.j > defender_position.j){
        Dir = DIR_STAY;
    }
    else if(Spy.i > defender_position.i){
        Dir = DIR_DOWN_LEFT;
    }
    else if(Spy.i < defender_position.i){
        Dir = DIR_DOWN_RIGHT;
    }
    else{
        Dir = DIR_RIGHT;
    }
  }
  
  move_position(defender_position, Dir);

  return;
}

#endif // DEFENDER_H

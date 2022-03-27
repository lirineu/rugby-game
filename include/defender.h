#ifndef DEFENDER_H
#define DEFENDER_H

//Standard headers
//#include <stdlib.h>

// Internal headers
#include "position.h"
#include "spy.h"

// Functions

/**
 * Main algorithm to move Defender player in a Game.
 * Given the player position, it should decide the next direction
 * they will take in the field.
 */
direction_t execute_defender_strategy(position_t defender_position, Spy attacker_spy){

  static int Rodada = 0;
  static position_t Spy;
  direction_t Dir;
  static int Random;
  
  if(Rodada == 0){
      Random = random()%10;
  }

  Rodada++;

  if(Rodada < Random){
    Dir.i = 0;
    Dir.j = -1;
  }
  else if(Rodada == Random){
    Spy = get_spy_position(attacker_spy);
    if(Spy.j > defender_position.j){
        Dir.i = Dir.j = 0;
    }
    else if(Spy.i > defender_position.i){
        Dir.i = 1;
        Dir.j = -1;
    }
    else if(Spy.i < defender_position.i){
        Dir.i = Dir.j = -1;
    }
    else{
        Dir.i = 0;
        Dir.j = -1;
    }

  }
  else{
    if(Spy.j > defender_position.j){
        Dir.i = Dir.j = 0;
    }
    else if(Spy.i > defender_position.i){
        Dir.i = 1;
        Dir.j = -1;
    }
    else if(Spy.i < defender_position.i){
        Dir.i = Dir.j = -1;
    }
    else{
        Dir.i = 0;
        Dir.j = -1;
    }
  }
  
  return Dir;
}

#endif // DEFENDER_H

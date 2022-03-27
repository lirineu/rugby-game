// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  {
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
}

/*----------------------------------------------------------------------------*/

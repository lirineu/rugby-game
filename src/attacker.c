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

int modulo (int x){
  if(x<0) return x * -1;
  return x;
}

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
  {
    static int Rodada = 0;
    static position_t Spy;
    static int Random;
    int Max, Rand;
    direction_t Dir;

    if(Rodada == 0){
      Random = random()%10;
    }

    Rodada++;

    Max = RAND_MAX;

    if(Rodada == Random){
      Spy = get_spy_position(defender_spy);
    }

    if(Rodada>= Random){
      if(modulo((int) Spy.i - attacker_position.i) > modulo((int) Spy.j - attacker_position.j)){
         Dir.i = 0;
         Dir.j = 1;
      }
      else if(Spy.i < attacker_position.i){
        Dir.i = 1;
        Dir.j = 0;
      }
      else{
        Dir.i = -1;
        Dir.j = 0;
      }
    }
    else{
      Rand = random();

      if(Rand > 0.7 * Max){
          Dir.i = -1;
      }
      else if(Rand < 0.3 * Max){
          Dir.i = 1;
      }
      else{
          Dir.i = 0;
      }

      Rand = random();


      if(Rand > 0.9 * Max){
          Dir.j = -1;
      }
      else if(Rand < 0.8 * Max){
          Dir.j = 1;
      }
      else{
          Dir.j = 0;
      }
    }
    return Dir;    
}
}

/*----------------------------------------------------------------------------*/

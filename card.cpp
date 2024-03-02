#include "card.h"


Card::Card(){
  // default card with rank 1 and default suit of spade
  rank = 1;
  suit = spade;
}


Card::Card(suits sv, int rnk){
  rank = rnk;
  suit = sv;
}

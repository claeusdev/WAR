#pragma once
#include "card.h"
#include "deck.h"

class Player {
public:
  Player(Deck &);
  Card draw();
  void add_points(int);
  int score();
  void replace_card(Deck &);

protected:
  Card cards[3];
  int total_score;
  int removed_card;
};

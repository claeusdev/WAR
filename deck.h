#pragma once
#include "card.h"
#include <vector>

class Deck {
public:
  Deck();

  void shuffle();
  bool isEmpty();
  Card draw(); // return the next card

protected:
  int top_card; // holds one index larger than next available class

  std::vector<Card> cards; // all cards
};

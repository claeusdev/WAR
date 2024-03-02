#include "deck.h"
#include <algorithm>

Deck::Deck() {
  top_card = 0;
  for (int i = 1; i <= 13; i++) {
    Card c1(diamond, i), c2(heart, i), c3(spade, i), c4(club, i);
    cards[top_card++] = c1;
    cards[top_card++] = c2;
    cards[top_card++] = c3;
    cards[top_card++] = c4;
  }
};

Card Deck::draw() {
  if (!isEmpty()) {
    return cards[--top_card];
  }

  Card ace_of_space(spade, 1);
  return ace_of_space;
};

bool Deck::isEmpty() { return top_card <= 0; }

void Deck::shuffle() {
  srand(time(0)); // Seed the random number generator

  for (size_t i = 0; i < cards.size(); ++i) {
    // Generate a random index to swap with
    size_t j = rand() % cards.size();

    // Swap elements at indices i and j
    std::swap(cards[i], cards[j]);
  }
}

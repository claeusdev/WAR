#include "player.h"
#include "deck.h"
#include "utils.h"

RandomInteger randomizer;

Player::Player(Deck &aDeck) {
  total_score = 0;

  for (int i = 0; i < 3; i++) {
    cards[i] = aDeck.draw();
  }

  removed_card = 0;
}

Card Player::draw() {
  removed_card = randomizer(3);
  return cards[removed_card];
}

void Player::add_points(int pts) { total_score += pts; }

int Player::score() { return total_score; }

void Player::replace_card(Deck &deck) { cards[removed_card] = deck.draw(); }

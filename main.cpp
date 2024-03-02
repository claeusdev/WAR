// This is a very simple implementation of the WAR game.
//
// WAR is a simple card game for 2 players. In this game:
// 1. all the 52 cards in a normal deck is shuffled
// 2. each player draws 3 cards
// 3. remaining cards are placed face down between the 2 players.
// 4. Game proceeds in a series of rounds.
// 5. in each round each player reveals a card, if the cards match then both
// players get to keep their cards, else the one with the higher card keeps both
// cards.
// 6. After each round both players pick a a new card from the deck.
// 7. The game ends when the deck is exhausted.
//
#include "card.h"
#include "deck.h"
#include "player.h"
#include <iostream>
#include <ostream>
#include <sys/types.h>

std::ostream &operator<<(std::ostream &out, Card &card);

int main() {

  Deck main_deck;
  main_deck.shuffle();

  Player p1(main_deck);
  Player p2(main_deck);

  while (!main_deck.isEmpty()) {
    Card c1 = p1.draw();
    std::cout << "Player 1 draws: " << c1 << std::endl;
    Card c2 = p2.draw();
    std::cout << "Player 2 draws: " << c2 << std::endl;

    if (c1.rank == c2.rank) {
      p1.add_points(1);
      p2.add_points(1);

      std::cout << "Tie game" << std::endl;
    } else if (c1.rank > c2.rank) {
      p1.add_points(1);
      std::cout << "Player 1 won this round..." << std::endl;
    } else {
      p2.add_points(1);
      std::cout << "Player 2 won this round..." << std::endl;
    }
  }

  std::cout << "Player 1 has: " << p1.score() << std::endl;
  std::cout << "Player 2 has: " << p2.score() << std::endl;

  return 0;
}

std::ostream &operator<<(std::ostream &out, Card &card) {
  // first output rank
  switch (card.rank) {
  case 1:
    out << "Ace";
    break;
  case 11:
    out << "Ace";
    break;
  case 12:
    out << "Ace";
    break;
  case 13:
    out << "Ace";
    break;
  default:
    out << card.rank;
  }

  // then output the suit
  switch (card.suit) {
  case diamond:
    out << " of Diamonds";
    break;
  case spade:
    out << " of Spades";
    break;
  case heart:
    out << " of Heart";
    break;
  case club:
    out << " of Clubs";
    break;
  default:

    break;
  }
  return out;
};

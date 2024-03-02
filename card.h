#pragma once
enum suits { diamond, club, heart, spade };

class Card {
public:
  Card();           // card with default values;
  Card(suits, int); // card with given values;

  int rank;
  int suit;
};

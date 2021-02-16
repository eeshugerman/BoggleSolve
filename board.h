#ifndef BOARD_H
#define BOARD_H

#include <vector>

struct Tile {
  char letter;
  int i;
  int j;
};

class Board {
private:
  Tile *tiles[4][4];

public:
  static const int BOARD_SIZE = 4;

  Board();
  ~Board();

  void fillBoardRandom();
  void fillBoardUser();
  char getLetter(int i, int j);
  bool contains(int i, int j);
  void printBoard();

};

#endif // BOARD_H

#ifndef BOARD_H
#define BOARD_H

#include <vector>

struct Tile {
    char letter;
    int i;
    int j;
};

class Board {
  public:
    static const int BOARD_SIZE = 4;

    Board();
    void fillBoardRandom();
    void fillBoardUser();
    char getLetter(int i, int j);
    bool contains(int i, int j);
    void printBoard();

  private:
    // should be on the heap perhaps, if we want
    // to generalize to BOARD_SIZE >> 4
    Tile tiles[BOARD_SIZE][BOARD_SIZE];
};

#endif // BOARD_H

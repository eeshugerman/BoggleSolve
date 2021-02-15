#ifndef GAME_H
#define GAME_H
#include "dictionary.h"
#include <string>
#include <vector>

struct Tile {
  char letter;
  Tile *prev;
  int i;
  int j;
};

class Boggle {
private:
  std::string buildWord(Tile *prevPath);
  bool checkVisited(Tile *toCheck, Tile *current);
  void removeDuplicateWords();

  Dictionary *dictionary;
  Tile *board[4][4];
  std::vector<std::string> words;
  std::vector<Tile *> searchTiles;

public:
  Boggle(Dictionary *dict);
  ~Boggle();
  void fillBoardRandom();
  void fillBoardUser(std::vector<char> letters);
  void printBoard();
  void findWords(Tile *prev, int i, int j);
  void printWords();
  void saveWords();
  void clearWords();
};

#endif // GAME_H

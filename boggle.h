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

private:
  std::string buildWord(Tile *prev_path);
  bool checkVisited(Tile *to_check, Tile *current);
  void removeDuplicateWords();

  Dictionary *dictionary;
  Tile *board[4][4];
  std::vector<std::string> words;
  std::vector<Tile *> search_tiles;
};

#endif // GAME_H

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
  void FillBoardRandom();
  void FillBoardUser(std::vector<char> letters);
  void PrintBoard();
  void FindWords(Tile *prev, int i, int j);
  void PrintWords();
  void SaveWords();
  void ClearWords();

private:
  std::string BuildWord(Tile *prev_path);
  bool CheckVisited(Tile *to_check, Tile *current);
  void RemoveDuplicateWords();

  Dictionary *dictionary;
  Tile *board[4][4];
  std::vector<std::string> words;
  std::vector<Tile *> search_tiles;
};

#endif // GAME_H

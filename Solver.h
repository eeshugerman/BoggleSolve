#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Dictionary.h"

#include <string>
#include <vector>

struct PathNode {
    char letter;
    PathNode* prev;
    int i;
    int j;
};

class Solver {
  private:
    static const int BOARD_SIZE = 4;

    Dictionary* dictionary;
    Board* board;
    std::vector<std::string> words;
    std::vector<PathNode*> garbage;

    std::string buildWord(PathNode* node);
    bool isRepeat(PathNode* node);
    void removeDuplicateWords();
    void findWordsFromNode(PathNode* node);

  public:
    Solver(Dictionary* dict, Board* board);
    ~Solver();
    void findWords();
    void printWords();
};

#endif // GAME_H

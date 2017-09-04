#ifndef GAME_H
#define GAME_H
#include <vector>
#include <cstddef>
#include <string>
#include "dictionary.h"


struct Tile
{
    char letter;
    Tile* prev;
    int i;
    int j;
};


class Boggle
{
    public:
        Boggle(Dictionary* dictionary);
        virtual ~Boggle();
        void FillBoardRandom();
        void FillBoardUser(std::vector<char> letters);
        void PrintBoard();
        void FindWords(Tile* prev, int i, int j);
        void PrintWords();
        void ClearWords();
    protected:
    private:
        std::string BuildWord(Tile* prev_path);
        bool CheckVisited(Tile* to_check, Tile* current);
        void RemoveDuplicateWords();

        Dictionary* english;
        Tile* board[4][4];
        std::vector<std::string> words;
};



#endif // GAME_H

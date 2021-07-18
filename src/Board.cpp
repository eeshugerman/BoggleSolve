#include "Board.h"
#include "Dictionary.h"

#include <chrono>
#include <random>

Board::Board() {
    fillRandom();
}

void Board::fillCustom() {
    std::string msg = "Please enter one row at a time (4 letters, no spaces, "
                      "lowercase), each followed by the enter key.";

    std::cout << msg << std::endl;

    for (int i = 0; i < BOARD_SIZE; i++) {
        char row[4];
        std::cin >> row;
        for (int j = 0; j < BOARD_SIZE; j++) {
            tiles[i][j] = Tile { row[j], i, j };
        }
    }
}

void Board::fillRandom() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::uniform_int_distribution<int> distribution(0, ALPHABET_SIZE - 1);
    std::default_random_engine generator(seed);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int randInt = distribution(generator);
            char randChar = 'a' + randInt;
            tiles[i][j] = Tile { randChar, i, j };
        }
    }
}

char Board::getLetter(int i, int j) {
    return tiles[i][j].letter;
}

bool Board::contains(int i, int j) {
    return (0 <= i and i < BOARD_SIZE) and (0 <= j and j < BOARD_SIZE);
}

void Board::print() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << tiles[i][j].letter << " ";
        }
        std::cout << std::endl;
    }
}

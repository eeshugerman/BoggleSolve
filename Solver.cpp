#include "Solver.h"
#include "Dictionary.h"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

Solver::Solver(Dictionary* dict, Board* board) {
    dictionary = dict;
    this->board = board;
}

Solver::~Solver() {
    for (PathNode* node : garbage) {
        delete node;
    }
}

bool Solver::isRepeat(PathNode* node) {
    PathNode* prev = node->prev;
    while (prev) {
        if (prev->i == node->i and prev->j == node->j) {
            return true;
        }
        prev = prev->prev;
    }
    return false;
}

std::string Solver::buildWord(PathNode* node) {
    std::vector<char> wordV;
    while (node != NULL) {
        wordV.push_back(node->letter);
        node = node->prev;
    }
    std::string word(wordV.begin(), wordV.end());
    reverse(word.begin(), word.end());
    return word;
}

void Solver::removeDuplicateWords() {
    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());
}

void Solver::printWords() {
    std::cout << "Found " << words.size() << " words:" << std::endl;
        for (std::string word : words) {
        std::cout << word << std::endl;
    }
}

void Solver::findWordsFromNode(PathNode* node) {
    garbage.push_back(node);

    if (isRepeat(node)) {
        return;
    }

    std::string candidate = buildWord(node);

    if (dictionary->isWord(candidate)) {
        words.push_back(candidate);
    }

    if (!dictionary->isPrefix(candidate)) {
        return;
    }

    for (int iStep = -1; iStep <= 1; iStep++) {
        for (int jStep = -1; jStep <= 1; jStep++) {
            int iNext = node->i + iStep;
            int jNext = node->j + jStep;

            if (!board->contains(iNext, jNext)) {
                continue;
            }

            PathNode* next = new PathNode {
                .letter = board->getLetter(iNext, jNext),
                .prev = node,
                .i = iNext,
                .j = jNext
            };
            findWordsFromNode(next);
        }
    }
}

void Solver::findWords() {
    for (int i = 0; i < board->BOARD_SIZE; i++) {
        for (int j = 0; j < board->BOARD_SIZE; j++) {
            PathNode* start = new PathNode {
                .letter = board->getLetter(i, j),
                .prev = NULL,
                .i = i,
                .j = j,
            };
            findWordsFromNode(start);
        }
    }
    removeDuplicateWords();
}

#include "boggle.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

Boggle::Boggle(Dictionary *dict) {
  dictionary = dict;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      board[i][j] = NULL;
    }
  }
}

Boggle::~Boggle() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      delete board[i][j];
    }
  }

  for (unsigned i = 0; i < search_tiles.size(); i++) {
    delete search_tiles[i];
  }
}

void Boggle::fillBoardUser(vector<char> letters) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j] != NULL) {
        delete board[i][j];
      }
    }
  }

  int k = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      Tile *tile = new Tile;
      tile->letter = letters[k];
      tile->prev = NULL;
      tile->i = i;
      tile->j = j;
      board[i][j] = tile;
      k++;
    }
  }
}

void Boggle::fillBoardRandom() {

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j] != NULL) {
        delete board[i][j];
      }
    }
  }
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  uniform_int_distribution<int> distribution(0, 25);
  default_random_engine generator(seed);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int rand_int = distribution(generator);
      char rand_char = 'a' + rand_int;

      Tile *tile = new Tile;
      tile->letter = rand_char;
      tile->prev = NULL;
      tile->i = i;
      tile->j = j;

      board[i][j] = tile;
    }
  }
}

void Boggle::printBoard() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << board[i][j]->letter << " ";
    }
    cout << endl;
  }
}

bool Boggle::checkVisited(Tile *to_check, Tile *path) {
  while (path) {
    if (path->i == to_check->i and path->j == to_check->j) {
      return true;
    }
    path = path->prev;
  }
  return false;
}

std::string Boggle::buildWord(Tile *path) {
  vector<char> wordV;
  while (path != NULL) {
    wordV.push_back(path->letter);
    path = path->prev;
  }
  string word(wordV.begin(), wordV.end());
  reverse(word.begin(), word.end());
  return word;
}

void Boggle::clearWords() { words.clear(); }

void Boggle::removeDuplicateWords() {
  sort(words.begin(), words.end());
  words.erase(unique(words.begin(), words.end()), words.end());
}

void Boggle::printWords() {
  removeDuplicateWords();

  for (int i = 0; i < (int)words.size(); i++) {
    cout << words[i] << endl;
  }
}

void Boggle::saveWords() {
  removeDuplicateWords();

  ofstream outFile("solution.txt");

  for (int i = 0; i < (int)words.size(); i++) {
    outFile << words[i] << endl;
  }
}

void Boggle::findWords(Tile *prev, int i, int j) {
  if (checkVisited(board[i][j], prev)) {
    return;
  }

  Tile *tile = new Tile;
  tile->letter = board[i][j]->letter;
  tile->i = i;
  tile->j = j;
  tile->prev = prev;

  search_tiles.push_back(tile);

  string candidate = buildWord(tile);

  if (prev != NULL and prev->prev != NULL) // more than two letters
  {
    if (dictionary->isWord(candidate)) {
      words.push_back(candidate);
    }
  }

  if (dictionary->isPrefix(candidate)) {
    int delta[3] = {-1, 0, 1};

    for (int del_i_idx = 0; del_i_idx < 4; del_i_idx++) {
      for (int del_j_idx = 0; del_j_idx < 4; del_j_idx++) {
        int i_next = i + delta[del_i_idx];
        int j_next = j + delta[del_j_idx];

        if (i_next >= 0 and i_next < 4 and j_next >= 0 and j_next < 4) {
          findWords(tile, i_next, j_next);
        }
      }
    }
  }
}

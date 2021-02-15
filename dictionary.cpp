#include "dictionary.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Node::Node() {
  parent = NULL;
  isWord = false;
  for (int i = 0; i < 26; i++) {
    children[i] = NULL;
  }
}

Node::~Node() {
  for (int i = 0; i < 26; i++) {
    delete children[i];
  }
}

Dictionary::Dictionary() {
  root = new Node;
  ifstream words("english_words.txt");
  string line;
  while (getline(words, line)) {
    if (line.length() > 2 and line.length() < 17) {
      addWord(line);
    }
  }
  words.close();
}

Dictionary::~Dictionary() { delete root; }

int Dictionary::charToInt(char c) {
  int x = c - 'a';
  return x;
}

void Dictionary::addWord(string word) {
  Node *node = root;
  for (int i = 0; i < (int)word.length(); i++) {
    char letter = word[i];
    int childIdx = charToInt(letter);
    if (node->children[childIdx]) {
      node = node->children[childIdx];
    }
    else {
      Node *childNode = new Node;
      node->children[childIdx] = childNode;
      childNode->parent = node;
      node = childNode;
    }
  }
  node->isWord = true;
}

bool Dictionary::isPrefix(string word) {
  Node *node = root;

  for (int i = 0; i < (int)word.length(); i++) {
    char c = word[i];
    int x = charToInt(c);
    node = node->children[x];
    if (node == NULL) {
      return false;
    }
  }

  for (int x = 0; x < 26; x++) {
    if (node->children[x]) {
      return true;
    }
  }
  return false;
}

bool Dictionary::isWord(string word) {
  Node *node = root;

  for (int i = 0; i < (int)word.length(); i++) {
    char c = word[i];
    int x = charToInt(c);
    node = node->children[x];
    if (node == NULL) {
      return false;
    }
  }

  return node->isWord;
}

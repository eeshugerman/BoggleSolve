#ifndef PREFIXDICTIONARY_H
#define PREFIXDICTIONARY_H
#include <iostream>
#include <string>

class Node {
public:
  Node();
  ~Node();
  Node *parent;
  Node *children[26];
  bool isWord;
};

class Dictionary { // as a trie, aka prefix tree
private:
  int charToInt(char c);
  Node *root;

public:
  Dictionary();
  ~Dictionary();
  void addWord(std::string word);
  bool isWord(std::string word);
  bool isPrefix(std::string word);
};

#endif // PREFIXDICTIONARY_H

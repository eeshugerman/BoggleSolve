#ifndef PREFIXDICTIONARY_H
#define PREFIXDICTIONARY_H
#include <iostream>
#include <string>

# define ALPHABET_SIZE 26

struct TrieNode {
  TrieNode();
  ~TrieNode();
  TrieNode *parent;
  TrieNode *children[ALPHABET_SIZE];
  bool isWord;
};

class Dictionary { // as a trie, aka prefix tree
private:
  static const unsigned MIN_WORD_LENGTH = 3;
  static const unsigned MAX_WORD_LENGTH = 16;

  int charToInt(char c);
  TrieNode *root;

public:
  Dictionary();
  ~Dictionary();
  void addWord(std::string word);
  bool isWord(std::string word);
  bool isPrefix(std::string word);
};

#endif // PREFIXDICTIONARY_H

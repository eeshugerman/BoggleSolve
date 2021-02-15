#ifndef PREFIXDICTIONARY_H
#define PREFIXDICTIONARY_H
#include <iostream>
#include <string>

class Dictionary // as a trie, aka prefix tree
{

private:
  class Node {
  public:
    Node();
    ~Node();
    Node *parent;
    Node *children[26];
    bool is_word;
    // Node(const Node &obj);
    //{
    // std::cout<<"copy constructor called" << std::endl;
    //};

    // Node& operator=(const Node& obj)
    //{
    // std::cout<<"copy assignment operator called" << std::endl;
    //};
  };
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

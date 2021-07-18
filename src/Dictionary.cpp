#include "Dictionary.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

TrieNode::TrieNode() {
    parent = NULL;
    isWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = NULL;
    }
}

TrieNode::~TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        delete children[i];
    }
}

Dictionary::Dictionary() {
    root = new TrieNode();

    ifstream words("english_words.txt"); // TODO: don't hardcode this
    string line;
    while (getline(words, line)) {
        const unsigned wordLength = line.length();
        if (MIN_WORD_LENGTH <= wordLength and wordLength <= MAX_WORD_LENGTH) {
            addWord(line);
        }
    }
    words.close();
}

Dictionary::~Dictionary() {
    delete root;
}

int Dictionary::charToInt(char c) {
    int x = c - 'a';
    return x;
}

void Dictionary::addWord(string word) {
    TrieNode* node = root;
    for (char letter : word) {
        int childIdx = charToInt(letter);
        if (node->children[childIdx]) {
            node = node->children[childIdx];
        }
        else {
            TrieNode* childNode = new TrieNode();
            node->children[childIdx] = childNode;
            childNode->parent = node;
            node = childNode;
        }
    }
    node->isWord = true;
}

bool Dictionary::isPrefix(string word) {
    TrieNode* node = root;

    for (char letter : word) {
        int childIdx = charToInt(letter);
        node = node->children[childIdx];
        if (node == NULL) {
            return false;
        }
    }

    for (int x = 0; x < ALPHABET_SIZE; x++) {
        if (node->children[x]) {
            return true;
        }
    }
    return false;
}

bool Dictionary::isWord(string word) {
    TrieNode* node = root;

    for (char letter : word) {
        int childIdx = charToInt(letter);
        node = node->children[childIdx];
        if (node == NULL) {
            return false;
        }
    }
    return node->isWord;
}

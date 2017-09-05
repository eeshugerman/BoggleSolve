#include "dictionary.h"
#include <iostream>
#include <string>

using namespace std;

Dictionary::Node::Node()
{
	parent = NULL;
	is_word = false;
	for (int i = 0; i < 26; i++)
	{
		children[i] = NULL;
	}
}

Dictionary::Node::~Node()
{
	for (int i = 0; i < 26; i++)
	{
		delete children[i];
		children[i] = NULL;
	}
}

Dictionary::Dictionary()
{
    root = new Node;
}

Dictionary::~Dictionary()
{
    delete root;
}

int Dictionary::charToInt(char c)
{
	int x = c - 'a';
	return x;
}

void Dictionary::addWord(string word)
{
	Node* node = root;
	for (int i = 0; i < (int)word.length(); i++)
	{
		char letter = word[i];
		int child_idx = charToInt(letter);
		if (node->children[child_idx])
		{
			node = node->children[child_idx];
		}
		else
		{
			Node* new_node = new Node;
			node->children[child_idx] = new_node;
			new_node->parent = node;
			//new_node->letter = letter;
			node = new_node;
		}
	}
	node->is_word = true;
}


bool Dictionary::isPrefix(string word)
{
	Node* node = root;
	
	for (int i = 0; i < (int)word.length(); i++)
	{
		char c = word[i];
		int x = charToInt(c);
		node = node->children[x];
		if (node == NULL)
		{
			return false;
		}
	}
	
	for (int x = 0; x < 26; x++)
	{
		if (node->children[x])
		{
			return true;
		}
	}
	
	return false;
}


bool Dictionary::isWord(string word)
{
	Node* node = root;
	
	for (int i = 0; i < (int)word.length(); i++)
	{
		char c = word[i];
		int x = charToInt(c);
		node = node->children[x];
		if (node == NULL)
		{
			return false;
		}
	}

	return node->is_word;
}



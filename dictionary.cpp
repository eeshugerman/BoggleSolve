#include "dictionary.h"
#include <iostream>
#include <string>

using namespace std;

Dictionary::Dictionary()
{
    root = NULL;
}

Dictionary::~Dictionary()
{
    delete root;
}

void Dictionary::addWord(string word)
{
    // trie, aka prefix tree is constructed
    Node* z = new Node;
    z->word = word;
    z->l = NULL;
    z->r = NULL;

    Node* x = root;
    Node* parent = NULL;

    if (root == NULL)
    {
        root = z;
        root->parent = NULL;
    }
    else
    {
        while(x != NULL)
        {
            parent = x;
            if(word.compare(x->word) < 0)
            {
                x = x->l;
            }
            else
            {
                x = x->r;
            }
        }

        z->parent = parent;
        if(word.compare(parent->word) < 0)
        {
            parent->l = z;
        }
        else
        {
            parent->r = z;
        }
    }
}

bool Dictionary::isPrefixPublic(string word)
{
    return isPrefix(root,word);
}

bool Dictionary::isPrefix(Node* subTree, string word)
{
    if (subTree == NULL)
    {
        return false;
    }

    if(word.length() < subTree->word.length())
    {
        string nodePrefix = subTree->word.substr(0,word.length());
        if(nodePrefix == word)
        {
            return true;
        }
    }

    if(word.compare(subTree->word) < 0)
    {
        return isPrefix(subTree->l, word);
    }

    else if(word.compare(subTree->word) > 0)
    {
        return isPrefix(subTree->r, word);
    }
    
    else
    {
		if(subTree->l == NULL and subTree->r == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
    }
}

bool Dictionary::isWordPublic(string word)
{
    return isWord(root, word);
}

bool Dictionary::isWord(Node* subTree, string word)
{
    if (subTree == NULL)
    {
        return false;
    }


    if(word.compare(subTree->word) < 0)
    {
        return isWord(subTree->l, word);
    }

    else if(word.compare(subTree->word) > 0)
    {
        return isWord(subTree->r, word);
    }
    
    else 
    {
		return true;
	}
}

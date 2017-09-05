#ifndef PREFIXDICTIONARY_H
#define PREFIXDICTIONARY_H
#include <string>




class Dictionary	    // as a trie, aka prefix tree 
{
	private:
		class Node
		{
			public:
				Node();
				~Node();
				Node* parent;
				Node* children[26];
				bool is_word;
				//char letter;
		};
		
    public:
        Dictionary();
        ~Dictionary();
        void addWord(std::string word);
        bool isWord(std::string word);
        bool isPrefix(std::string word);
        Node* getRoot();
    

    private:
		int charToInt(char c);
		Node* root;
};

#endif // PREFIXDICTIONARY_H

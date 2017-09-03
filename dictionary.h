#ifndef PREFIXDICTIONARY_H
#define PREFIXDICTIONARY_H
#include <string>

struct Node
{
    std::string word;
    Node* parent;
    Node* l;
    Node* r;
    ~Node()
    {
        delete l;
        l = NULL;
        delete r;
        r = NULL;
    }
};


class Dictionary
{
    public:
        Dictionary();
        virtual ~Dictionary();
        void addWord(std::string word);
        bool isWordPublic(std::string word);
        bool isPrefixPublic(std::string word);
        Node* getRoot();

    protected:
    private:
        bool isWord(Node* root, std::string word);
        bool isPrefix(Node* root, std::string word);
        Node* root;
};

#endif // PREFIXDICTIONARY_H

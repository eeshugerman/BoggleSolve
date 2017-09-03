#include "boggle.h"
#include <random>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Boggle::Boggle(Dictionary* dictionary)
{
    english = dictionary;
}

Boggle::~Boggle()
{
    //dtor
}

void Boggle::FillBoardUser(vector<char> letters)
{
    int k = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            Tile* new_tile = new Tile;
            new_tile->letter = letters[k];
            new_tile->prev = NULL;
            board[i][j] = new_tile;
            k++;
        }
    }
}

void Boggle::FillBoardRandom()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    uniform_int_distribution<int> distribution(0,25);
    default_random_engine generator(seed);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int rand_int = distribution(generator);
            char rand_char = 'a' + rand_int;

            Tile* new_tile = new Tile;
            new_tile->letter = rand_char;
            new_tile->prev = NULL;
            new_tile->i = i;
            new_tile->j = j;

            board[i][j] = new_tile;
        }
    }
}

void Boggle::PrintBoard()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<board[i][j]->letter<<" ";
        }
        cout<<endl;
    }
}

bool Boggle::CheckVisited(Tile* to_check, Tile* path)
{
    bool ans = false;
    while(path)
    {
        if(path->i == to_check->i and path->j == to_check->j)
        {
            ans = true;
            break;
        }
        path = path->prev;
    }
    return ans;
}

std::string Boggle::BuildWord(Tile* path)
{
    vector<char> wordV;
    while(path != NULL)
    {
        wordV.push_back(path->letter);
        path = path->prev;
    }
    string word(wordV.begin(), wordV.end());
    return word;
}

void Boggle::ClearWords()
{
    words.clear();
}

void Boggle::RemoveDuplicateWords()
{
    sort(words.begin(), words.end());
    words.erase(unique(words.begin(),words.end()),words.end());
}

void Boggle::PrintWords()
{
    RemoveDuplicateWords();

    for(int i = 0; i < (int)words.size(); i++)
    {
        cout<<words[i]<<endl;
    }
}

void Boggle::FindWords(Tile* prev, int i, int j)
{
    if(not CheckVisited(board[i][j], prev))
    {
        Tile* new_tile = new Tile;
        new_tile->letter = board[i][j]->letter;
        new_tile->i = i;
        new_tile->j = j;
        new_tile->prev = prev;

        string candidate = BuildWord(new_tile);


        if(prev != NULL)
        {
            if(prev->prev != NULL) // is more than 2 letters
            {
                if(english->isWordPublic(candidate))
                {
                    words.push_back(candidate);
                }
            }
        }

        if(english->isPrefixPublic(candidate))
        {
            if(i == 0 and j == 0) // top left corner
            {
                FindWords(new_tile, 1, 0);
                FindWords(new_tile, 0, 1);
                FindWords(new_tile, 1 ,1);
            }
            else if(i == 0 and j!= 3 and j != 0) // top
            {
                FindWords(new_tile, i, j + 1);
                FindWords(new_tile, i + 1, j + 1);
                FindWords(new_tile, i + 1, j);
                FindWords(new_tile, i + 1, j - 1);
                FindWords(new_tile, i, j - 1);
            }
            else if(i == 0 and j == 3) // top right
            {
                FindWords(new_tile, 0, 2);
                FindWords(new_tile, 1, 2);
                FindWords(new_tile, 1, 3);
            }
            else if(j == 3 and i!= 3 and i != 0) //right
            {
                FindWords(new_tile, i - 1, j);
                FindWords(new_tile, i - 1, j - 1);
                FindWords(new_tile, i, j - 1);
                FindWords(new_tile, i + 1, j - 1);
                FindWords(new_tile, i + 1, j);
            }
            else if(j == 3 and i == 3) //bottom right
            {
                FindWords(new_tile, 2, 3);
                FindWords(new_tile, 2, 2);
                FindWords(new_tile, 3, 2);
            }
            else if(i == 3 and j!= 3 and j != 0) // bottom
            {
                FindWords(new_tile, i, j + 1);
                FindWords(new_tile, i - 1, j + 1);
                FindWords(new_tile, i - 1, j);
                FindWords(new_tile, i - 1, j - 1);
                FindWords(new_tile, i, j - 1);
            }
            else if(i == 3 and j == 0) // bottom left
            {
                FindWords(new_tile, 2, 0);
                FindWords(new_tile, 2, 1);
                FindWords(new_tile, 3, 1);

            }
            else if(j == 0 and i!= 3 and i != 0) // left
            {
                FindWords(new_tile, i - 1, j);
                FindWords(new_tile, i - 1, j + 1);
                FindWords(new_tile, i, j + 1);
                FindWords(new_tile, i + 1, j + 1);
                FindWords(new_tile, i + 1, j);
            }
            else
            {
                FindWords(new_tile, i - 1, j);
                FindWords(new_tile, i - 1, j + 1);
                FindWords(new_tile, i, j + 1);
                FindWords(new_tile, i + 1, j + 1);
                FindWords(new_tile, i + 1, j);
                FindWords(new_tile, i + 1, j - 1);
                FindWords(new_tile, i, j - 1);
                FindWords(new_tile, i - 1, j - 1);
            }
        }
    }
}



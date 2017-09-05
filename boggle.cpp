#include "boggle.h"
#include <fstream>
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
            Tile* tile = new Tile;
            tile->letter = letters[k];
            tile->prev = NULL;
            tile->i = i;
            tile->j = j;
            board[i][j] = tile;
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

            Tile* tile = new Tile;
            tile->letter = rand_char;
            tile->prev = NULL;
            tile->i = i;
            tile->j = j;

            board[i][j] = tile;
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
    while(path)
    {
        if(path->i == to_check->i and path->j == to_check->j)
        {
            return true;
        }
        path = path->prev;
    }
    return false;
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
    reverse(word.begin(), word.end());
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
	
	ofstream outFile("solution.txt");
	
    for(int i = 0; i < (int)words.size(); i++)
    {
        cout << words[i] << endl;
        outFile << words[i] <<endl;
    }
}

void Boggle::FindWords(Tile* prev, int i, int j)
{
    if(CheckVisited(board[i][j], prev))
    {
		return;
	}

	Tile* tile = new Tile;
	tile->letter = board[i][j]->letter;
	tile->i = i;
	tile->j = j;
	tile->prev = prev;

	string candidate = BuildWord(tile);
	if (candidate == "dung")
	{
		cout<<candidate<<endl;
	}
	
	if(prev != NULL and prev->prev != NULL)	// more than two letters
	{
		if(english->isWord(candidate))
		{
			words.push_back(candidate);
		}
	}

	if(english->isPrefix(candidate))
	{
		int delta [3] = {-1, 0, 1};
		
		for (int del_i_idx = 0; del_i_idx < 4; del_i_idx++)
		{
			for (int del_j_idx = 0; del_j_idx < 4; del_j_idx++)
			{
				int i_next = i + delta[del_i_idx];
				int j_next = j + delta[del_j_idx];
				
				if (i_next >= 0 and i_next < 4 and
					j_next >= 0 and j_next < 4)
				{
					FindWords(tile, i_next, j_next);
				}
			}
		}
	}
	else
	{
		return;
	}
}


	



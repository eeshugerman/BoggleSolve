#include <iostream>
#include <fstream>
#include "boggle.h"
#include "dictionary.h"

using namespace std;

int main()
{
    Dictionary english;

    ifstream words("english_words.txt");
    string line;
    while(getline(words,line))
    {
        if(line.length() > 2 and  line.length() < 17)
        {
            english.addWord(line);
        }
    }

    Boggle boggle(&english);
    boggle.FillBoardRandom();

    int choice;
    while(true)    
    {
        cout<<"------------------------"<<endl;
        cout<<"          Menu          "<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1. New random board"	<<endl;
        cout<<"2. New custom board"	<<endl;
        cout<<"3. Print board"		<<endl;
        cout<<"4. Print possible words"	<<endl;
        cout<<"5. Quit"			<<endl;


        cin >> choice;
	if (cin.fail())
	{
	    cin.clear();
	    cin.ignore(10000, '\n');
	    choice = 0;
	}

        if(choice == 1)
        {
            boggle.FillBoardRandom();
            boggle.PrintBoard();
        }

        else if(choice == 2)
        {
            cout<<"Please enter one letter at a time, followed by the enter key."<<endl;
            cout<<"Letters will be stored left to right, top to bottom."<<endl;
            vector<char> letters;
            for(int i = 0; i < 16; i++)
            {
                char letter;
                cin >> letter;
                letters.push_back(letter);
            }
            cout<<endl;
            boggle.FillBoardUser(letters);
            boggle.PrintBoard();
        }

        else if(choice == 3)
        {
            boggle.PrintBoard();
        }

        else if(choice == 4)
        {
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
		    cout<<i<<j<<endl;
                    boggle.FindWords(NULL, i,j);
                }
            }
            cout<<endl;
            boggle.PrintBoard();
            cout<<endl;
            boggle.PrintWords();
            boggle.ClearWords();
        }

        else if (choice == 5)
        {
            cout<<"Goodbye!"<<endl;
            break;
        }
	
	else
	{
	    cout<<"Invalid option, please try again."<<endl;
	}
	
    }

}

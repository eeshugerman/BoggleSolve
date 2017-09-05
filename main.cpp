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
        //cout<<"6. Read board from file"<<endl;


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
            cout<<"Please enter one row (4 letters, no spaces) at a time, each followed by the enter key."<<endl;
            vector<char> letters;
            for(int i = 0; i < 4; i++)
            {
                char row[4];
                cin >> row;
                
				for(int i = 0; i < 4; i++)
				{
					letters.push_back(row[i]);
				}
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
        
        else if (choice == 6)
        {
			ifstream inFile;
			inFile.open("test_board.txt");
            vector<char> letters;
			char row[4];
			while (inFile >> row)
			{
				for(int i = 0; i < 4; i++)
				{
					letters.push_back(row[i]);
				}
			}	
			cout<<endl;
            boggle.FillBoardUser(letters);
            boggle.PrintBoard();
				
		}
	
		else
		{
			cout<<"Invalid option, please try again."<<endl;
		}
	
    }

}

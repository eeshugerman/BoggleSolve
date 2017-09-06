#include <iostream>
#include <fstream>
#include <vector>
#include "boggle.h"
#include "dictionary.h"

using namespace std;

void RandomBoard(Boggle game)
{

}

void CustomBoard(Boggle game)
{
	cout << "Please enter one row at a time (4 letters, no spaces, "
			"lowercase), each followed by the enter key." 
	<< endl;
		  
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
	game.FillBoardUser(letters);
	game.PrintBoard();
}

void Solve(Boggle game)
{
	game.ClearWords();

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			game.FindWords(NULL, i,j);
		}
	}
	cout<<endl;
	game.PrintBoard();
	cout<<endl;
	game.PrintWords();
}

void LoadTestBoard(Boggle game)
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
	inFile.close();
	game.FillBoardUser(letters);
	game.PrintBoard();
}

int main()
{
    Dictionary english;
    Boggle game(&english);
    
    game.FillBoardRandom();

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
        //cout<<"6. Load test board"<<endl;


        cin >> choice;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			choice = 0;
		}

        if(choice == 1)
        {
			game.FillBoardRandom();
			game.PrintBoard();        
		}
        else if(choice == 2)
        {
			CustomBoard(game);
        }
        else if(choice == 3)
        {
            game.PrintBoard();
        }
        else if(choice == 4)
        {
			Solve(game);
        }
        else if (choice == 5)
        {
            cout<<"Goodbye!"<<endl;
            return 0;
        }
        else if (choice == 6)
        {
			LoadTestBoard(game);
		}
		else if (choice == 7)
		{
			game.SaveWords();
		}
		else
		{
			cout<<"Invalid option, please try again."<<endl;
		}
	
    }

}

#include "boggle.h"
#include "dictionary.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void customBoard(Boggle *game) {
  cout << "Please enter one row at a time (4 letters, no spaces, "
          "lowercase), each followed by the enter key."
       << endl;

  vector<char> letters;
  for (int i = 0; i < 4; i++) {
    char row[4];
    cin >> row;

    for (int i = 0; i < 4; i++) {
      letters.push_back(row[i]);
    }
  }
  cout << endl;
  game->fillBoardUser(letters);
  game->printBoard();
}

void solve(Boggle *game) {
  game->clearWords();

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      game->findWords(NULL, i, j);
    }
  }
  cout << endl;
  game->printBoard();
  cout << endl;
  game->printWords();
}

void loadTestBoard(Boggle *game) {
  ifstream inFile;
  inFile.open("test_board.txt");
  vector<char> letters;
  char row[4];
  while (inFile >> row) {
    for (int i = 0; i < 4; i++) {
      letters.push_back(row[i]);
    }
  }
  cout << endl;
  inFile.close();
  game->fillBoardUser(letters);
  game->printBoard();
}

int main() {
  Dictionary english;
  Boggle game(&english);

  game.fillBoardRandom();

  int choice;
  while (true) {
    cout << "------------------------" << endl;
    cout << "          Menu          " << endl;
    cout << "------------------------" << endl;
    cout << "1. New random board" << endl;
    cout << "2. New custom board" << endl;
    cout << "3. Print board" << endl;
    cout << "4. Print possible words" << endl;
    cout << "5. Quit" << endl;
    // cout<<"6. Load test board"<<endl;

    cin >> choice;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(10000, '\n');
      choice = 0;
    }

    switch(choice) {
      case 1:
        game.fillBoardRandom();
        game.printBoard();
        break;
      case 2:
        customBoard(&game);
        break;
      case 3:
        game.printBoard();
        break;
      case 4:
        solve(&game);
        break;
      case 5:
        cout << "Goodbye!" << endl;
        return 0;
      case 6:
        loadTestBoard(&game);
        break;
      case 7:
        game.saveWords();
        break;
      default:
        cout << "Invalid option, please try again." << endl;
        break;
      }
  }
}

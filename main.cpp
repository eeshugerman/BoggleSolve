#include "solver.h"
#include "dictionary.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main() {
  while (true) {
    cout << "------------------------" << endl;
    cout << "          Menu          " << endl;
    cout << "------------------------" << endl;
    cout << "1. New random board" << endl;
    cout << "2. New custom board" << endl;
    cout << "3. Print board" << endl;
    cout << "4. Print possible words" << endl;
    cout << "5. Quit" << endl;

    int choice;
    cin >> choice;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Board *board = new Board();
    Dictionary *dict = new Dictionary();
    Solver solver = Solver(dict, board);

    switch(choice) {
      case 1:
        board->fillBoardRandom();
        board->printBoard();
        break;
      case 2:
        board->fillBoardUser();
        break;
      case 3:
        board->printBoard();
        break;
      case 4:
        solver.findWords();
        solver.printWords();
        break;
      case 5:
        cout << "Goodbye!" << endl;
        return 0;
      default:
        cout << "Invalid option, please try again." << endl;
        break;
    }
  }
}

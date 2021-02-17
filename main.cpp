#include "Board.h"
#include "Dictionary.h"
#include "Solver.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
  Board board = Board();
  Dictionary dict = Dictionary();
  Solver solver = Solver(&dict, &board);

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

    switch (choice) {
    case 1:
      board.fillBoardRandom();
      board.printBoard();
      break;
    case 2:
      board.fillBoardUser();
      break;
    case 3:
      board.printBoard();
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

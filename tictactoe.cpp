#include <iostream>
#include <vector>
#include "functions.hpp"

int main() {

  int x = 1;
  int o = -1;
  int turn = x;
  char turn_char = 'x';

  bool win = false;
  int turns = 0;

  std::vector<std::vector<int>> board = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  // mainloop:
  while (!win && turns != 9) {
    display_board(board);
    int square;
    std::cout << turn_char << ", choose square: ";
    std::cin >> square;
    std::vector<std::vector<int>> returned = make_move(square, turn, board);
    board = {};
    for (int i = 0; i < 3; i++) {
      board.push_back(returned[i]);
    }
    if (returned[3][0] == 1) {
      win = check_win(turn, board);
      if (win) {
        display_board(board);
        std::cout << turn_char << " wins! Congratulations!\n";
      }
      turn = - turn;
      if (turn_char == 'x') {turn_char = 'o';}
      else {turn_char = 'x';}
    }
    else {
      std::cout << "INVALID MOVE\n";
    }

    if (turns == 9 && !win) {
      std::cout << "Tie game!";
    }
    turns++;
  }
  return 0;
}

#include <iostream>
#include <vector>

bool check_win(int turn, std::vector<std::vector<int>> board) {
  // check columns:
  for (int column = 0; column < 3; column++) {
    if (board[0][column] == board[1][column] && board[1][column] == board[2][column] && board[2][column] == turn) {return true;}
  }
  // check rows:
  for (int row = 0; row < 3; row++) {
    if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][2] == turn) {return true;}
  }

  // check diagnols:
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == turn) {return true;}
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == turn) {return true;}

  // if no wins return false:
  return false;
}

std::vector<std::vector<int>> make_move(int square, int player, std::vector<std::vector<int>> board) {
  bool ok = true;
  int row = 0;
  int column;
  while (square > 3) {
    square -= 3;
    row++;
  }

  column = square - 1;

  if (board[row][column] == 0) {
    board[row][column] = player;
  }
  else {ok = false;}

  if (ok) {board.push_back({1});}
  else if (!ok) {board.push_back({0});}

  return board;


}

void display_board(std::vector<std::vector<int>> board) {
  std::string board_display = "    |   |\n";

  for (int i = 0; i < board.size(); i++) {

    std::vector<std::string> chars;
    for (int x = 0; x < 3; x++) {
      if (board[i][x] == 0) {
        chars.push_back("{" + std::to_string((3 * i) + x + 1) + "}");
      }
      else if (board[i][x] == 1) {
        chars.push_back(" x ");
      }
      else {
        chars.push_back(" o ");
      }
    }

    board_display += " " + chars[0] + "|" + chars[1] + "|" + chars[2] + " \n";

    if (i != 2) {      
      board_display += "----+---+----\n";
    }
  }

  board_display += "    |   |\n";

  std::cout << board_display;

}

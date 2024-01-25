#include <iostream>
#include <vector>
#include "tic-tac-toe-functions.hpp"
using namespace std;


int main() {
    vector<std::string> tic_tac_toe_board;
    for (int i = 0; i < 9; i++) {
    tic_tac_toe_board.push_back("|   ");
  }
    int end = 0;
    string status;
    while (end == 0) {
    print_board(tic_tac_toe_board);
    place_piece("| x ", tic_tac_toe_board);
    status = end_game("| x ", tic_tac_toe_board);
    if (status == "tie") {
        cout << "Tie. Game Over.\n";
        end = end + 1;
    }
    if (status == "win") {
        cout << "X wins! Game Over.\n";
        end = end + 1;
        print_board(tic_tac_toe_board);
        break;
    }
    print_board(tic_tac_toe_board);
    place_piece("| o ", tic_tac_toe_board);
     status = end_game("| o ", tic_tac_toe_board);
    if (status == "tie") {
       cout << "Tie. Game Over.\n";
        end = end + 1;
    }
    if (status == "win") {
        cout << "O wins! Game Over.\n";
        end = end + 1;
        print_board(tic_tac_toe_board);
        break;
    }
}
}
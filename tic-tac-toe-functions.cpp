#include <iostream>
#include <vector>

void print_board(std::vector<std::string> board) {
  std::cout << board[0] << board[1] << board[2] << "|\n";
  std::cout << "-------------\n";
  std::cout << board[3] << board[4] << board[5] << "|\n";
  std::cout << "-------------\n";
  std::cout << board[6] << board[7] << board[8] << "|\n";
}


void place_piece(std::string player, std::vector<std::string> &board) {
    if (player == "| x ") {
        std::cout << "x's turn. Which position will you place your piece at? (1-9)\n";
    }
    else {
        std::cout << "o's turn. Which position will you place your piece at? (1-9)\n";
    }
    int position;
    std::cin >> position; 
    while (!(position > 0 && position < 10 && board[position - 1] == "|   ")) {
        std::cout << "Invalid position.\n";
        std::cin >> position;
    }

    board[position - 1] = player;
}

std::string end_game(std::string player, std::vector<std::string> board) {
    int counter = 0;
    for (int i = 0; i < board.size(); i++) {
        if (!(board[i] == "|   ")) {
            counter++;
        }
    }       
    if (counter == 9) {
        return "tie";
    }
    
    if ((board[0] == player && board[1] == player && board[2] == player) || 
    (board[3] == player && board[4] == player && board[5] == player) || 
    (board[6] == player && board[7] == player && board[8] == player)) {
        return "win";
    }

    if ((board[0] == player && board[3] == player && board[6] == player) || 
    (board[1] == player && board[4] == player && board[7] == player) || 
    (board[2] == player && board[5] == player && board[8] == player)) {
        return "win";
    }    

    if ((board[0] == player && board[4] == player && board[8] == player) || 
    (board[2] == player && board[4] == player && board[6] == player)) {
        return "win";
    }
    
    return "continue";
}
#include <iostream>
#include <stdbool.h>

#include "tictactoe.h"

TicTacToe::TicTacToe(int n) : GridGame(n) {
}

TicTacToe::~TicTacToe() {
}

bool TicTacToe::check_rows(char symbol) const {
    int occurrences = 0;

    for(int i = 0; i < grid.n; i++) {
        for(int j = 0; j < grid.n; j++) {
            char move = grid.get_cell(i, j);
            if(move == symbol) {
                occurrences++;
                if(occurrences == grid.n) {
                    return true;
                }
            }
            else {
                occurrences = 0;
                break;
            }
        }
    }

    return false;
}

bool TicTacToe::check_cols(char symbol) const {
    int occurrences = 0;

    for(int i = 0; i < grid.n; i++) {
        for(int j = 0; j < grid.n; j++) {
            char move = grid.get_cell(j, i);
            if(move == symbol) {
                occurrences++;
                if(occurrences == grid.n) {
                    return true;
                }
            }
            else {
                occurrences = 0;
                break;
            }
        }
    }

    return false;
}

bool TicTacToe::check_diagonals(char move) const {
    return (grid.get_cell(0, 0) == move && grid.get_cell(1, 1) == move && grid.get_cell(2, 2) == move) ||
           (grid.get_cell(0, 2) == move && grid.get_cell(1, 1) == move && grid.get_cell(2, 0) == move);
}

bool TicTacToe::user_won() const {
    return check_rows('X') || check_cols('X') ||
           check_diagonals('X');
}

bool TicTacToe::opponent_won() const {
    return check_rows('O') || check_cols('O') ||
           check_diagonals('O');
}

int TicTacToe::get_status() const {
    if(user_won()) {
        return 1;
    }
    else if(opponent_won()) {
        return 2;
    }
    else if(grid.is_full()) {
        return 0;
    }

    return 3;
}

bool TicTacToe::place_mark(int row, int col, Player player) {
    if(grid.empty_at(col*grid.n + row)) {
        Move move;
        if(player == Player::User) {
            move = Move::X;
        }
        else {
            move = Move::O;
        }

        grid.set_cell(row, col, move);
        return true;
    }

    return false;
}

void TicTacToe::place_mark(Player player) {
    std::cout << "This is the AI's function" << std::endl;
}

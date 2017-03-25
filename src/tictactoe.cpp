#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <sstream>

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
    return (grid.get_cell(0, 0) == move &&
            grid.get_cell(1, 1) == move &&
            grid.get_cell(2, 2) == move) || (grid.get_cell(0, 2) == move &&
                                             grid.get_cell(1, 1) == move &&
                                             grid.get_cell(2, 0) == move);
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
        std::cout << "Congratulations! You have won!" << std::endl;
        return 1;
    }
    else if(opponent_won()) {
        std::cout << "Too bad! Your opponent has won!" << std::endl;
        return 2;
    }
    else if(grid.is_full()) {
        std::cout << "The game is a tie" << std::endl;
        return 0;
    }

    return 3;
}

bool TicTacToe::place_mark(int row, int col, Player player) {
    if(grid.empty_at(row, col)) {
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

bool TicTacToe::invalid_coordinates(int x, int y) {
    return x < 0 || x > 2 || y < 0 || y > 2;
}

void TicTacToe::do_turn(Player player) {
    Move curr_token;
    switch(player) {
        case Player::User:
            std::cout << "Your turn" << std::endl;
            curr_token = player_token;
            break;
        case Player::Opponent:
            std::cout << "Opponent's turn" << std::endl;
            curr_token = opponent_token;
            break;
        default:
            std::cout << "Unable to determine turn" << std::endl;
    }

    bool parsing_error = true;
    do {
        std::cout << "Enter the coordinates of the spot you wish to place "
                  << grid.determine_move(curr_token)
                  << " in the format (x y): ";
        std::string coords;
        std::getline(std::cin, coords);
        std::stringstream parser(coords);
        int x, y;
        parser >> x >> y;
        if(parser.fail()) {
            std::cout << "Incorrect format for selecting a spot."
                      << "Use the format (x y)"
                      << std::endl;
        }
        else if(invalid_coordinates(x, y)) {
            std::cout << "The coordinates you have entered are not within the"
                      << "dimensions of the board"
                      << std::endl;
        }
        else if(!grid.empty_at(x, y)) {
            std::cout << "The location you have specified is not vacant"
                      << std::endl;
        }
        else {
            place_mark(x, y, player);
            parsing_error = false;
        }
    } while(parsing_error);

    grid.num_moves--;
}

void TicTacToe::run() {
    std::cout << "Welcome to tic-tac-toe!" << std::endl;
    player_token = Move::X;
    opponent_token = Move::O;
    turn = Player::User;
    while(grid.num_moves > 0) {
        do_turn(turn);
        display();
        if(get_status() != 3) {
            break;
        }
        if(turn == Player::User) {
            turn = Player::Opponent;
        }
        else {
            turn = Player::User;
        }
    }
}

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

void TicTacToe::do_turn() {
    Move curr_token;
    switch(whose_turn) {
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
            std::cout << "Incorrect format for selecting a spot. "
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
            place_mark(x, y, whose_turn);
            parsing_error = false;
        }
    } while(parsing_error);

    grid.num_moves--;
}

void TicTacToe::configure_turn() {
    bool invalid_input = true;
    do {
        std::cout << "Enter who you wish to go first (player/cpu): ";
        std::string first_turn;
        std::getline(std::cin, first_turn);
        if(first_turn.compare("player") == 0) {
            whose_turn = Player::User;
            std::cout << "It will be your turn to start this game"
                      << std::endl;
            invalid_input = false;
        }
        else if(first_turn.compare("cpu") == 0) {
            std::cout << "It will be your opponent's turn to start this game"
                      << std::endl;
            whose_turn = Player::Opponent;
            invalid_input = false;
        }
        else {
            std::cout << "You have entered an invalid player. "
                      << "Please enter 'player' or 'cpu'"
                      << std::endl;
        }
    } while(invalid_input);
}

void TicTacToe::configure_token() {
    bool invalid_input = true;
    do {
        std::cout << "Enter the token you wish to have (X/O): ";
        std::string whose_token;
        std::getline(std::cin, whose_token);
        if(whose_token.compare("X") == 0) {
            player_token = Move::X;
            opponent_token = Move::O;
            std::cout << "Your token is "
                      << grid.determine_move(player_token)
                      << " Your opponent's token is "
                      << grid.determine_move(opponent_token)
                      << std::endl;
            invalid_input = false;
        }
        else if(whose_token.compare("O") == 0) {
            player_token = Move::O;
            opponent_token = Move::X;
            invalid_input = false;
        }
        else {
            std::cout << "You have entered an invalid token. "
                      << "Please enter 'X' or 'O'"
                      << std::endl;
        }
    } while(invalid_input);
}

void TicTacToe::run() {
    std::cout << "Welcome to tic-tac-toe!" << std::endl;

    bool wants_to_play = true;
    while(wants_to_play) {
        configure_turn();
        configure_token();
        while(grid.num_moves > 0) {
            do_turn();
            display();
            if(get_status() != 3) {
                break;
            }
            if(whose_turn == Player::User) {
                whose_turn = Player::Opponent;
            }
            else {
                whose_turn = Player::User;
            }
        }

        std::cout << "Thanks for playing!" << std::endl;

        bool invalid_input = true;
        do {
            std::cout << "Do you wish to play again? (y/n): ";
            std::string play_status;
            std::getline(std::cin, play_status);
            if(play_status.compare("y") == 0) {
                wants_to_play = true;
                restart();
                grid.num_moves = grid.n*grid.n;
                invalid_input = false;
            }
            else if(play_status.compare("n") == 0) {
                wants_to_play = false;
                invalid_input = false;
            }
            else {
                std::cout << "Invalid input!" << std::endl;
            }
        } while(invalid_input);
    }
}

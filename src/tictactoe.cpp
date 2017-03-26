#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <sstream>
#include <tuple>
#include <vector>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "tictactoe.h"

TicTacToe::TicTacToe(int n) : GridGame(n) {}

TicTacToe::~TicTacToe() {}

bool TicTacToe::check_rows(const Grid& grid, char symbol) const {
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

bool TicTacToe::check_cols(const Grid& grid, char symbol) const {
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

bool TicTacToe::check_diagonals(const Grid& grid, char symbol) const {
    return (grid.get_cell(0, 0) == symbol &&
            grid.get_cell(1, 1) == symbol &&
            grid.get_cell(2, 2) == symbol) || (grid.get_cell(0, 2) == symbol &&
                                             grid.get_cell(1, 1) == symbol &&
                                             grid.get_cell(2, 0) == symbol);
}

bool TicTacToe::user_won(const Grid& grid) const {
    return check_rows(grid, grid.determine_move(user_token)) || check_cols(grid, grid.determine_move(user_token)) ||
           check_diagonals(grid, grid.determine_move(user_token));
}

bool TicTacToe::opponent_won(const Grid& grid) const {
    return check_rows(grid, grid.determine_move(opponent_token)) || check_cols(grid, grid.determine_move(opponent_token)) ||
           check_diagonals(grid, grid.determine_move(opponent_token));
}

int TicTacToe::get_status() const {
    if(user_won(this->grid)) {
        std::cout << "Congratulations! You have won!" << std::endl;
        return 1;
    }
    else if(opponent_won(this->grid)) {
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
            move = user_token;
        }
        else {
            move = opponent_token;
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
    return x < 0 || x > grid.n-1 || y < 0 || y > grid.n-1;
}

std::vector<std::tuple<int, int>> TicTacToe::filter_possible_moves(
    std::vector<std::tuple<Grid, int, int>> possibilities
)
{
    std::vector<std::tuple<Grid, int, int>>::iterator curr_possibility;
    std::vector<std::tuple<int, int>> final_choices;
    for(curr_possibility = possibilities.begin();
        curr_possibility < possibilities.end();
        curr_possibility++)
    {
        for(int i = 0; i < grid.n; i++) {
            for(int j = 0; j < grid.n; j++) {
                Grid curr_grid = std::get<0>(*curr_possibility);
                curr_grid.set_cell(i, j, user_token);
                if(!user_won(curr_grid)) {
                    std::tuple<int, int> new_choice = std::make_tuple(std::get<1>(*curr_possibility), std::get<2>(*curr_possibility));
                    final_choices.push_back(new_choice);
                    curr_grid.set_cell(i, j, Move::None);
                }
            }
        }
    }

    return final_choices;
}

std::vector<std::tuple<int, int>> TicTacToe::find_possible_moves() {
    std::vector<std::tuple<Grid, int, int>> test_grids;

    for(int i = 0; i < grid.n; i++) {
        for(int j = 0; j < grid.n; j++) {
            if(grid.empty_at(i, j)) {
                Grid test_grid = grid;
                test_grid.set_cell(i, j, opponent_token);
                test_grids.push_back(std::make_tuple(test_grid, i, j));
            }
        }
    }

    return filter_possible_moves(test_grids);
}

std::tuple<int, int> TicTacToe::find_available_move() {
    std::vector<std::tuple<int,
                           int>> possible_moves = find_possible_moves();
    srand(time(NULL));
    int location = rand() % possible_moves.size();

    return std::make_tuple(std::get<0>(possible_moves.at(location)), std::get<1>(possible_moves.at(location)));
}

std::tuple<int, int> TicTacToe::find_winning_move() {
    for(int i = 0; i < grid.n; i++) {
        for(int j = 0; j < grid.n; j++) {
            if(grid.empty_at(i, j)) {
                Grid test_grid = grid;
                test_grid.set_cell(i, j, opponent_token);
                if(opponent_won(test_grid)) {
                    return std::make_tuple(i, j);
                }
            }
        }
    }

    return std::make_tuple(-1, -1);
}

std::tuple<int, int> TicTacToe::find_blocking_move() {
    for(int i = 0; i < grid.n; i++) {
        for(int j = 0; j < grid.n; j++) {
            if(grid.empty_at(i, j)) {
                Grid test_grid = grid;
                test_grid.set_cell(i, j, user_token);
                if(user_won(test_grid)) {
                    return std::make_tuple(i, j);
                }
            }
        }
    }

    return std::make_tuple(-1, -1);
}

void TicTacToe::do_opponent_turn() {
    std::cout << "Opponent's turn" << std::endl;

    std::tuple<int, int> best_move;
    int row, col;

    best_move = find_winning_move();
    row = std::get<0>(best_move);
    col = std::get<1>(best_move);
    if(row != -1 && col != -1) {
        place_mark(row, col, Player::Opponent);
        return;
    }

    best_move = find_blocking_move();
    row = std::get<0>(best_move);
    col = std::get<1>(best_move);
    if(row != -1 && col != -1) {
        place_mark(row, col, Player::Opponent);
        return;
    }


    best_move = find_available_move();
    row = std::get<0>(best_move);
    col = std::get<1>(best_move);
    place_mark(row, col, Player::Opponent);
}

void TicTacToe::do_player_turn() {
    std::cout << "Your turn" << std::endl;

    bool parsing_error = true;
    do {
        std::cout << "Enter the coordinates of the spot you wish to place "
                  << grid.determine_move(user_token)
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
            place_mark(x, y, Player::User);
            parsing_error = false;
        }
    } while(parsing_error);
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
            user_token = Move::X;
            opponent_token = Move::O;
            std::cout << "Your token is "
                      << grid.determine_move(user_token)
                      << " Your opponent's token is "
                      << grid.determine_move(opponent_token)
                      << std::endl;
            invalid_input = false;
        }
        else if(whose_token.compare("O") == 0) {
            user_token = Move::O;
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
        restart();
        configure_turn();
        configure_token();
        while(grid.num_moves > 0) {
            if(whose_turn == Player::User) {
                do_player_turn();
                whose_turn = Player::Opponent;
            }
            else {
                do_opponent_turn();
                whose_turn = Player::User;
            }
            grid.num_moves--;
            display();
            if(get_status() != 3) {
                break;
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

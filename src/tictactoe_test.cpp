#include <iostream>
#include <assert.h>

#include "grid.h"
#include "grid_game.h"
#include "tictactoe.h"
#include "new_game.h"

void test_clear_board(Grid& grid) {
    for(int i = 0; i < grid.n; i++) {
        for(int j = 0; j < grid.n; j++) {
            char symbol = grid.get_cell(i, j);
            assert(symbol == ' ');
        }
    }
}

void test_grid() {
    Grid grid(3);
    grid.set_cell(0, 0, Move::X);
    // grid.display();
    // assert(grid.empty_at(8) == false);
    // assert(grid.empty_at(7) == true);
    // test_clear_board(grid);
}

void test_tie_game() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 0, Player::User);
    tic_tac_toe.place_mark(0, 1, Player::User);
    tic_tac_toe.place_mark(0, 2, Player::Opponent);

    tic_tac_toe.place_mark(1, 0, Player::Opponent);
    tic_tac_toe.place_mark(1, 1, Player::User);
    tic_tac_toe.place_mark(1, 2, Player::User);

    tic_tac_toe.place_mark(2, 0, Player::User);
    tic_tac_toe.place_mark(2, 1, Player::Opponent);
    tic_tac_toe.place_mark(2, 2, Player::Opponent);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 0);
}

void test_complete_first_row() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 0, Player::User);
    tic_tac_toe.place_mark(0, 1, Player::User);
    tic_tac_toe.place_mark(0, 2, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 1);
}

void test_complete_second_row() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(1, 0, Player::User);
    tic_tac_toe.place_mark(1, 1, Player::User);
    tic_tac_toe.place_mark(1, 2, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 1);
}

void test_complete_third_row() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(2, 0, Player::User);
    tic_tac_toe.place_mark(2, 1, Player::User);
    tic_tac_toe.place_mark(2, 2, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 1);
}

void test_partial_first_row() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 0, Player::User);
    tic_tac_toe.grid.set_cell(0, 1, Move::None);
    tic_tac_toe.place_mark(0, 2, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 3);
}

void test_partial_second_row() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(1, 0, Player::User);
    tic_tac_toe.grid.set_cell(1, 1, Move::None);
    tic_tac_toe.place_mark(1, 2, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 3);
}

void test_partial_third_row() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(2, 0, Player::User);
    tic_tac_toe.grid.set_cell(2, 1, Move::None);
    tic_tac_toe.place_mark(2, 2, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 3);
}

void test_rows() {
    test_complete_first_row();
    test_complete_second_row();
    test_complete_third_row();

    test_partial_first_row();
    test_partial_second_row();
    test_partial_third_row();
}

void test_complete_first_col() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 0, Player::User);
    tic_tac_toe.place_mark(1, 0, Player::User);
    tic_tac_toe.place_mark(2, 0, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 1);
}

void test_complete_second_col() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 1, Player::User);
    tic_tac_toe.place_mark(1, 1, Player::User);
    tic_tac_toe.place_mark(2, 1, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 1);
}

void test_complete_third_col() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 2, Player::User);
    tic_tac_toe.place_mark(1, 2, Player::User);
    tic_tac_toe.place_mark(2, 2, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 1);
}

void test_partial_first_col() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 0, Player::User);
    tic_tac_toe.grid.set_cell(1, 0, Move::None);
    tic_tac_toe.place_mark(2, 0, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 3);
}

void test_partial_second_col() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 1, Player::User);
    tic_tac_toe.grid.set_cell(1, 1, Move::None);
    tic_tac_toe.place_mark(2, 1, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 3);
}

void test_partial_third_col() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 2, Player::User);
    tic_tac_toe.grid.set_cell(1, 2, Move::None);
    tic_tac_toe.place_mark(2, 2, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 3);
}

void test_cols() {
    test_complete_first_col();
    test_complete_second_col();
    test_complete_third_col();

    test_partial_first_col();
    test_partial_second_col();
    test_partial_third_col();
}

void test_partial_diagonal() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 2, Player::User);
    tic_tac_toe.grid.set_cell(1, 1, Move::None);
    tic_tac_toe.place_mark(2, 0, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 3);
}

void test_upper_diagonal() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 2, Player::User);
    tic_tac_toe.place_mark(1, 1, Player::User);
    tic_tac_toe.place_mark(2, 0, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 1);
}

void test_lower_diagonal() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 0, Player::User);
    tic_tac_toe.place_mark(1, 1, Player::User);
    tic_tac_toe.place_mark(2, 2, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 1);
}

void test_diagonals() {
    test_lower_diagonal();
    test_upper_diagonal();
    test_partial_diagonal();
}

void test_restart() {
    TicTacToe tic_tac_toe(3);

    tic_tac_toe.place_mark(0, 0, Player::User);
    tic_tac_toe.place_mark(1, 1, Player::Opponent);
    tic_tac_toe.place_mark(2, 2, Player::User);

    tic_tac_toe.display();
    int game_over = tic_tac_toe.get_status();
    assert(game_over == 3);

    tic_tac_toe.restart();
    tic_tac_toe.display();
    game_over = tic_tac_toe.get_status();
    assert(game_over == 3);
}

void test_tictactoe() {
    test_rows();
    test_cols();
    test_diagonals();

    test_tie_game();

    test_restart();
}

void test_game() {
    TicTacToe game(3);
    game.run();
}

void test_AI() {
    // Should place to block user
    TicTacToe game1(3);

    game1.user_token = Move::X;
    game1.opponent_token = Move::O;

    game1.place_mark(0, 0, Player::User);
    game1.place_mark(2, 0, Player::User);
    game1.place_mark(1, 1, Player::Opponent);
    game1.place_mark(2, 2, Player::Opponent);
    game1.display();

    game1.do_opponent_turn();
    game1.display();
    std::cout << "Placed to block" << std::endl;

    game1.~TicTacToe();

    // Should place to win
    TicTacToe game2(3);

    game2.user_token = Move::X;
    game2.opponent_token = Move::O;

    game2.place_mark(0, 0, Player::Opponent);
    game2.place_mark(0, 2, Player::Opponent);
    game2.place_mark(1, 1, Player::User);
    game2.place_mark(2, 0, Player::User);
    game2.display();

    game2.do_opponent_turn();
    game2.display();
    std::cout << "Placed to win" << std::endl;

    game2.~TicTacToe();

    // Should place randomly
    TicTacToe game3(3);

    game3.user_token = Move::X;
    game3.opponent_token = Move::O;

    game3.place_mark(0, 0, Player::Opponent);
    game3.place_mark(1, 1, Player::User);
    game3.display();

    game3.do_opponent_turn();
    game3.display();
    std::cout << "Placed randomly" << std::endl;

    game3.~TicTacToe();
}

void test_copy_constructor() {
    TicTacToe game1(3);
    std::cout << "Displaying grid1" << std::endl;
    game1.place_mark(0, 0, Player::User);
    game1.place_mark(0, 2, Player::Opponent);
    game1.place_mark(1, 1, Player::Opponent);
    game1.display();

    TicTacToe game2(3);
    game2.grid = game1.grid;
    std::cout << "Displaying grid2" << std::endl;
    game2.display();
}

int main() {
    // test_grid();
    // test_tictactoe();
    // test_game();
    test_AI();

    // test_copy_constructor();

    std::cout << "All tests passed!" << std::endl;
	return 0;
}

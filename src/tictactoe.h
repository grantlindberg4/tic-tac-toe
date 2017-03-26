#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <tuple>
#include <vector>

#include "grid_game.h"

class TicTacToe : public GridGame {
    bool check_rows(char symbol) const;
    bool check_cols(char symbol) const;
    bool check_diagonals(char symbol) const;

    bool user_won() const;
    bool opponent_won() const;

    void do_player_turn();
    std::vector<std::tuple<int, int>> filter_possible_moves(
        std::vector<std::tuple<Grid, int, int>> possibilities
    );
    std::tuple<int, int> find_best_move();
    std::vector<std::tuple<int, int>> find_possible_moves();

    bool invalid_coordinates(int x, int y);

    void configure_turn();
    void configure_token();
public:
    void do_opponent_turn();
    TicTacToe(int n);
    ~TicTacToe();

    Move player_token;
    Move opponent_token;
    Player whose_turn;

    int get_status() const;
    bool place_mark(int row, int col, Player player);
    void place_mark(Player player);
    void run();
};

#endif

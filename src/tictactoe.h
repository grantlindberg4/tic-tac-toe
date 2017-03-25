#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "grid_game.h"

class TicTacToe : public GridGame {
    bool check_rows(char symbol) const;
    bool check_cols(char symbol) const;
    bool check_diagonals(char move) const;
    bool user_won() const;
    bool opponent_won() const;
    void do_turn(Player player);
    bool invalid_coordinates(int x, int y);
    Move player_token;
    Move opponent_token;
    Player turn;
public:
    TicTacToe(int n);
    ~TicTacToe();

    int get_status() const;
    bool place_mark(int row, int col, Player player);
    void place_mark(Player player);
    void run();
};

#endif

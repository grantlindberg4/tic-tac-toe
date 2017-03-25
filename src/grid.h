#ifndef GRID_H
#define GRID_H

#include <stdbool.h>

enum class Move {
	X,
	O,
	None
};

enum class Player {
	User,
	Opponent
};

class Grid {
public:
	int n;
	int num_moves;
	char* board;
	char determine_move(Move move);
	bool empty_at(int i);
	Grid(int n);
	~Grid();
	void set_cell(int row, int col, Move move);
	char get_cell(int row, int col) const;
	void clear();
	bool is_full() const;
};

#endif

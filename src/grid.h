#ifndef GRID_H
#define GRID_H

enum Move {
	X,
	O,
	None
};

class Grid {
public:
	int n;
	char* board;
	char determine_move(Move move);
	Grid(int n);
	~Grid();
	void set_cell(Move move, int cell);
	char get_cell(int cell);
	void clear();
	void display();
};

#endif

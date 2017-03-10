#ifndef GRID_H
#define GRID_H

enum Move {
	X,
	O,
	None
};

class Grid {
protected:
	int n;
	char* board;
	char determine_move(Move move);
public:
	Grid(int n);
	~Grid();
	void set_cell(char move, int cell);
	void clear();
	void display();
};

#endif

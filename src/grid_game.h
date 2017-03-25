#ifndef GRID_GAME_H
#define GRID_GAME_H

#include "grid.h"

class GridGame {
public:
	GridGame(int n);
	virtual ~GridGame();
	Grid grid;
	virtual int get_status() const = 0;
	virtual bool place_mark(int row, int col, Player player) = 0;
	virtual void place_mark(Player player) = 0;
	void display() const;
	void restart();
};

#endif

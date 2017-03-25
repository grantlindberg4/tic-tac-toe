#include <iostream>

#include "grid.h"
#include "grid_game.h"

GridGame::GridGame(int n) : grid(n) {
}

GridGame::~GridGame() {
}

void GridGame::display() const {
	for(int i = 0; i < grid.n; i++) {
		std::cout << "-------------" << std::endl;
		for(int j = 0; j < grid.n; j++) {
			std::cout << "| ";
			std::cout << grid.board[i*grid.n + j] << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "-------------" << std::endl;
}

void GridGame::restart() {
	grid.clear();
}

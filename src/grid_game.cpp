#include <iostream>

#include "grid.h"
#include "grid_game.h"

GridGame::GridGame(int n) : grid(n) {
}

GridGame::~GridGame() {
}

void GridGame::display() const {
	for(int i = 0; i < grid.n; i++) {
		for(int cell = 0; cell < grid.n; cell++) {
			std::cout << "---";
		}
		for(int cell = 0; cell < grid.n+1; cell++) {
			std::cout << "-";
		}
		std::cout << std::endl;
		for(int j = 0; j < grid.n; j++) {
			std::cout << "| ";
			std::cout << grid.board[i*grid.n + j] << " ";
		}
		std::cout << "|" << std::endl;
	}
	for(int cell = 0; cell < grid.n; cell++) {
		std::cout << "---";
	}
	for(int cell = 0; cell < grid.n+1; cell++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}

void GridGame::restart() {
	grid.clear();
	grid.num_moves = grid.n*grid.n;
}

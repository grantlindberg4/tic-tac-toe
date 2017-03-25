#include <iostream>

#include "grid.h"
#include "grid_game.h"

GridGame::GridGame(int n) : grid(n) {
	std::cout << "Creating grid game" << std::endl;
}

GridGame::~GridGame() {
	std::cout << "Destroying grid game" << std::endl;
}

void GridGame::display() const {
	for(int i = 0; i < grid.n; i++) {
		std::cout << "-------------" << std::endl;
		for(int j = 0; j < grid.n; j++) {
			std::cout << "| ";
			std::cout << grid.board[j*grid.n + i] << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "-------------" << std::endl;
}

void GridGame::restart() {
	grid.clear();
}

#include <iostream>
#include "grid.h"

Grid::Grid(int n) : n(n) {
	board = new char[n];
	std::cout << "Creating Grid" << std::endl;
	clear();
}
Grid::~Grid() {
    std::cout << "Deleting Grid" << std::endl;
    delete(board);
}

void Grid::clear() {
	for(int i = 0; i < n*n; i++) {
		set_cell(Move::None, i);
	}
}

void Grid::set_cell(Move move, int cell) {
	char symbol = determine_move(move);
	this->board[cell] = symbol;
}

char Grid::get_cell(int cell) {
	return this->board[cell];
}

void Grid::display() {
	for(int i = 0; i < n; i++) {
		std::cout << "-------------" << std::endl;
		for(int j = 0; j < n; j++) {
			std::cout << "| ";
			std::cout << board[j*n + i] << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "-------------" << std::endl;
}

char Grid::determine_move(Move move) {
	switch(move) {
		case X:
			return 'X';
		case O:
			return 'O';
		case None:
			return ' ';
		default:
			return ' ';
	}
}

#include <iostream>
#include "grid.h"

Grid::Grid(int n) : n(n) {
	board = new char[n];
	std::cout << "Creating Grid" << std::endl;
}
Grid::~Grid() {
    std::cout << "Deleting Grid" << std::endl;
    delete(board);
}

void Grid::clear() {
	for(int i = 0; i < n*n; i++) {
		char move = determine_move(Move::None);
		set_cell(move, i);
	}
}

void Grid::set_cell(char move, int cell) {
	this->board[cell] = move;
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

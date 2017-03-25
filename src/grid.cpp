#include <iostream>

#include "grid.h"

Grid::Grid(int n) : n(n) {
	board = new char[n];
	num_moves = n*n;
	std::cout << "Creating Grid" << std::endl;
	clear();
}

Grid::~Grid() {
    std::cout << "Deleting Grid" << std::endl;
    delete(board);
}

bool Grid::empty_at(int i) {
	return !(board[i] == 'X' || board[i] == 'O');
}

void Grid::clear() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			set_cell(i, j, Move::None);
		}
	}
}

void Grid::set_cell(int row, int col, Move move) {
	char symbol = determine_move(move);
	this->board[col*n + row] = symbol;
}

char Grid::get_cell(int row, int col) const {
	return this->board[col*n + row];
}

char Grid::determine_move(Move move) {
	switch(move) {
		case Move::X:
			return 'X';
		case Move::O:
			return 'O';
		case Move::None:
			return ' ';
		default:
			return ' ';
	}
}

bool Grid::is_full() const {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(get_cell(i, j) == ' ') {
				return false;
			}
		}
	}

	return true;
}

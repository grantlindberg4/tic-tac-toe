#include <iostream>

#include "grid.h"

Grid::Grid(int n) : n(n) {
	board = new char[n*n];
	clear();
}

Grid::Grid(const Grid& grid) {
	n = grid.n;
	board = new char[n*n];
	for(int i = 0; i < n*n; i++) {
		board[i] = grid.board[i];
	}
}

Grid::~Grid() {
    delete(board);
}

bool Grid::empty_at(int row, int col) const {
	return !(get_cell(row, col) == 'X' || get_cell(row, col) == 'O');
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
	this->board[row*n + col] = symbol;
}

char Grid::get_cell(int row, int col) const {
	return this->board[row*n + col];
}

char Grid::determine_move(Move move) const {
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

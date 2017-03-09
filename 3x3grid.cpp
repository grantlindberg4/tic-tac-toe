#include <iostream>

enum Move {
	X,
	O,
	None
};

class Grid {
protected:
	int n;
	char* board;
	char determine_move(Move move) {
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
public:
	Grid(int n) : n(n) {
		board = new char[n];
		std::cout << "Creating Grid" << std::endl;
	}
	~Grid() {
		std::cout << "Deleting Grid" << std::endl;
		delete(board);
	}
	void clear() {
		for(int i = 0; i < n*n; i++) {
			char move = determine_move(Move::None);
			this->board[i] = move;
		}
	}
	void display() {
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
};

int main() {
	Grid grid(3);
	grid.clear();
	grid.display();
	return 0;
}

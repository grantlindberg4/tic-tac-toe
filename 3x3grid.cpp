#include <iostream>

enum Move {
	X = 'X',
	O = 'O',
	None = (char)0
};

class Grid {
protected:
	int n;
	Move* board;
public:
	Grid(int n) : n(n) {
		board = new Move[n];
		std::cout << "Creating Grid" << std::endl;
	}
	~Grid() {
		std::cout << "Deleting Grid" << std::endl;
	}
	void clear() {
		for(int i = 0; i < n*n; i++) {
			this->board[i] = Move::None;
		}
	}
	void display() {
		for(int i = 0; i < n; i++) {
			std::cout << "-------------" << std::endl;
			for(int j = 0; j < n; j++) {
				std::cout << "| ";
				std::cout << board[j*n + i] << " ";
			}
			std::cout << "|";
			std::cout << std::endl;
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

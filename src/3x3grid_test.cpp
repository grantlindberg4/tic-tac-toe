#include <iostream>
#include "grid.h"
#include <assert.h>

void test_clear_board(Grid& grid) {
    for(int i = 0; i < grid.n * grid.n; i++) {
        char symbol = grid.get_cell(i);
        assert(symbol == ' ');
    }
}

void test_grid() {
    Grid grid(3);
    // grid.set_cell(Move::X, 8);
    grid.display();
    test_clear_board(grid);
}

int main() {
    test_grid();
    std::cout << "All tests passed!" << std::endl;
	return 0;
}

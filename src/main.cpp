#include <iostream>

#include "grid_game.h"
#include "tictactoe.h"
#include "new_game.h"

enum GameMode {
	NormalGame,
	ModfiedGame
};

GameMode configure_game_mode() {

	bool invalid_input = true;
	do {
		std::cout << "Enter the game mode you wish to play (3x3/4x4): ";
		std::string game_mode;
		std::getline(std::cin, game_mode);
		if(game_mode.compare("3x3") == 0) {
			return NormalGame;
		}
		else if(game_mode.compare("4x4") == 0) {
			return ModfiedGame;
		}
		else {
			std::cout << "Invalid input!" << std::endl;
		}
	} while(invalid_input);
}

int main() {
	std::cout << "Welcome to tic-tac-toe!" << std::endl;

	bool wants_to_play = true;
	while(wants_to_play) {
		GameMode game_mode = configure_game_mode();
		if(game_mode == NormalGame) {
			TicTacToe game(3);
			wants_to_play = game.run();
		}
		else if(game_mode == ModfiedGame) {
			NewGame game(4);
			wants_to_play = game.run();
		}
	}

	return 0;
}

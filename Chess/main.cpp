#include "Game.h"

int maing()
{
	/*
	Colors startPlayer = WHITE;
	Game game = Game(startPlayer);
	Board board = game.getGameBoard();
	*/
	Game game = Game(WHITE);
	game.playGame(WHITE);
	//Board board = Board();
	//board.printBoard();
	//board.move(1, 3, 3, 3, WHITE);
	//board.move(0, 3, 1, 3, WHITE); //error! for some reason is taken doesn't have correct parameters!
	
	//std::cout << std::endl;
	/*
	if (board(1, 3) == nullptr)
	{
		std::cout << "YES!" << std::endl;
	}*/
	//std:: cout << std::endl;
	//board.printBoard();
	return 0;
}
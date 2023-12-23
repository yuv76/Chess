#include "Game.h"

int main()
{
	/*
	Colors startPlayer = WHITE;
	Game game = Game(startPlayer);
	Board board = game.getGameBoard();
	*/

	Board board = Board();
	std::cout << board(1, 0) << std::endl;
	std::cout << board(1, 0)->getType() << " " << board(1, 0)->getColor() << std::endl;
	board.move(1, 0, 2, 0, WHITE);
	
	if (board(0, 1) == nullptr)
	{
		std::cout << "YES!" << std::endl;
	}
	std::cout << board(2, 0)->getType() << std::endl;
	//board.printBoard();
}
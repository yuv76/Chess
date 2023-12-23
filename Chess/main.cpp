#include "Game.h"

int main()
{
	/*
	Colors startPlayer = WHITE;
	Game game = Game(startPlayer);
	Board board = game.getGameBoard();
	*/

	Board board = Board();
	std::cout << board(0, 0)->getType() << " " << board(0, 0)->getColor() << std::endl;
	board.move(0, 0, 3, 0, WHITE);
	
	if (board(0, 0) == nullptr)
	{
		std::cout << "YES!" << std::endl;
	}
	std::cout << board(3, 0)->getType() << std::endl;
	//board.printBoard();
}
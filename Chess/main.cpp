#include "Game.h"

int main()
{
	Colors startPlayer = WHITE;
	Game game = Game(startPlayer);
	Board board = game.getGameBoard();
}
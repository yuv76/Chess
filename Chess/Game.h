#pragma once
#include "Board.h"

enum WinState{WHITE_WON, BLACK_WON, UNDETERMINED};

class Game
{
private:
	Board _gameBoard;
	WinState _winner;
	Colors _turn;
	bool _gameOver;//not sure this is needed

public:
	Game(Colors startPlayer);
	~Game();
	WinState getWinState();
	Colors getTurn();
	Board& getGameBoard();

	void playGame();
	void nextTurn(int* move);
	int* extractMsg(std::string msg);
};

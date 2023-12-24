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

	std::string decodeMsg(std::string msg);
	void sendNextMove();
	void playGame(Colors FirstPlayer);
	MsgCode turn(int* move,  bool& validFlag);
	int* checkMsg(std::string msg, MsgCode& code);
};

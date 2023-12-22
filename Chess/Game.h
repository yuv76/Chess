#pragma once
#include "Board.h"

enum WinState{WHITE_WON, BLACK_WON, UNDETERMINED};
enum MsgCode {VALID, CHESS, NO_PIECE, PIECE_IN_DEST, CAUSE_CHESS, INVALID_INDEXES, ILLEGAL_TOOL_MOVE, SAME_POS, CHECKMATE};

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
	void startGame(Colors FirstPlayer);
	MsgCode turn(std::string move); // might help
};


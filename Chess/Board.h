#pragma once
#include "Piece.h"

#define ROWS 8
#define COLS 8
#define MUN_OF_BLANK_START_LINES 4

class Board
{
private:
	Piece*** _pieces;
	//std::string _kingPosition;
public:
	Board();
	~Board();
	Piece*** getPieces();
	bool move(std::string move);
	bool isTaken(std::string dest);
	bool eat(std::string eatingPos, std::string eatedPos);
	bool isEating(std::string move);
	bool checkIfChess(std::string move);
	bool checkIfCheckmate(std::string move);
	std::string toString();
};


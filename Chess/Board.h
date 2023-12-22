#pragma once
#include "Piece.h"

#define BOARD_SIZE 64
#define ROWS 8
#define COLS 8
#define MUN_OF_BLANK_START_LINES 4

class Board
{
private:
	Piece* _pieces[ROWS][COLS];
	//std::string _kingPosition;	good idea
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


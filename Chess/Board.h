#pragma once
#include "Piece.h"

#define BLANK_POS '#'

#define BOARD_SIZE 64 // wasn't used... why needed?
#define ROWS 8
#define COLS 8
#define MUN_OF_BLANK_START_LINES 4

class Board
{
private:
	Piece* _pieces[ROWS][COLS];
	int _whiteKingPosition[2];
	int _blackKingPosition[2];
public:
	Board();
	~Board();
	bool move(std::string move);
	bool isTaken(std::string dest);
	bool eat(std::string eatingPos, std::string eatedPos);
	bool isEating(std::string move);
	bool checkIfChess(std::string move);
	bool checkIfCheckmate(std::string move);
	std::string toString();
	Piece* operator()(int rowIndex, int colIndex);

	//for backend interface
	void printBoard();
};


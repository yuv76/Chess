#pragma once
#include "Piece.h"

#define BLANK_POS '#'

#define BOARD_SIZE 64 // wasn't used... why needed?
#define ROWS 8
#define COLS 8
#define MUN_OF_BLANK_START_LINES 6 //4 /will be returned to 4 after pawn implementation.

#define ASCII_SUB_FOR_COL 97
#define ASCII_SUB_FOR_ROW 49

#define CHECK_SOURCE_POSITION true
#define CHECK_DEST_POSITION false

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
	bool eat(std::string eatingPos, std::string eatedPos);
	bool isEating(std::string move);
	MsgCode isTaken(int row, int col, bool isSource);
	MsgCode checkIfChess(std::string move);
	MsgCode checkIfCheckmate(std::string move);
	MsgCode canOtherKingGetEaten(int row, int col);
	std::string toString();
	Piece* operator()(int rowIndex, int colIndex);

	//for backend interface
	void printBoard();
};


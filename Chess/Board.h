#pragma once
#include "Piece.h"
#include "Tower.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

#define BLANK_POS '#'

#define BOARD_SIZE 64
#define ROWS 8
#define COLS 8
#define MUN_OF_BLANK_START_LINES 6 //4 /will be returned to 4 after pawn implementation.

#define ASCII_SUB_FOR_COL 97
#define ASCII_SUB_FOR_ROW 49

#define CHECK_SOURCE_POSITION true
#define CHECK_DEST_POSITION false

enum MsgCode { VALID, CHESS, NO_PIECE, PIECE_IN_DEST, CAUSE_CHESS, INVALID_INDEXES, ILLEGAL_TOOL_MOVE, SAME_POS, CHECKMATE };

class Board
{
private:
	Piece* _pieces[ROWS][COLS];
	int _whiteKingPosition[2];
	int _blackKingPosition[2];
public:
	Board();
	~Board();
	MsgCode move(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn);
	bool isEating(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn);
	bool isTaken(int row, int col, Colors turn);
	MsgCode checkIfChess(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn);
	MsgCode checkIfCheckmate(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn);
	MsgCode canOtherKingGetEaten(int row, int col);
	std::string toString();
	Piece* operator()(int rowIndex, int colIndex);

	//for backend interface
	void printBoard();
};


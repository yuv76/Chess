#pragma once

#include "Piece.h"

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Tower.h" 


#define BLANK_POS '#'

#define BOARD_SIZE 64
#define ROWS 8
#define COLS 8
#define MUN_OF_BLANK_START_LINES 6 //4 /will be returned to 4 after pawn implementation.

#define ASCII_SUB_FOR_COL 97
#define ASCII_SUB_FOR_ROW 49

#define FIRST_ROW_BLACK 7
#define FIRST_ROW_WHITE 0
#define START_KING_COL 3

#define CHECK_SOURCE_POSITION true
#define CHECK_DEST_POSITION false

#define BUFF_SIZE 1024

enum MsgCode {VALID, CHESS, NO_PIECE, PIECE_IN_DEST, CAUSE_SELF_CHESS, INVALID_INDEXES, ILLEGAL_TOOL_MOVE, SAME_POS, CHECKMATE, CASTLING, CASTLING_AND_CHESS, CASTLING_AND_MATE};

class Board
{
private:
	Piece* _pieces[ROWS][COLS];
	int _whiteKingPosition[2];
	int _blackKingPosition[2];
public:
	Board();
	~Board();
	MsgCode Castle(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn);
	bool isPathChessedForCastling(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn);
	bool isPathClear(int sourceRow, int sourceCol, int destRow, int destCol);
	MsgCode checkIfCanMove(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn);
	void changePieceLocation(int sourceRow, int sourceCol, int destRow, int destCol);
	MsgCode move(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn);
	bool isTaken(int row, int col, Colors turn);
	bool checkIfChess(Colors turn, int kingRow, int kingCol);
	bool checkIfCanMoveSomewhere(int sourceRow, int sourceCol, Colors turn);
	bool checkIfThereIsAPieceThatCanMove(Colors turn);
	bool checkIfCheckmate(Colors turn);
	char* toString();
	bool didMoveCauseChess(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn, int kingRow, int kingCol);

	Piece* operator()(int rowIndex, int colIndex);

	//for back-end interface
	void printBoard();
};

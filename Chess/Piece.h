#pragma once
#include <string>
#include <iostream>

enum Types {TOWER, KING, QUEEN, BISHOP, KNIGHT, PAWN};
enum Colors {WHITE, BLACK};
enum MsgCode {VALID, CHESS, NO_PIECE, PIECE_IN_DEST, CAUSE_CHESS, INVALID_INDEXES, ILLEGAL_TOOL_MOVE, SAME_POS, CHECKMATE};

#define MAX_ROW_AND_COL 8

class Piece
{
private:
	Colors _color;
	Types _type;
	// Might turn out to be unneeded
	int _letterLocation;
	int _numberLocation;

public:
	Piece(Colors color, Types type, int row, int col);
	virtual ~Piece();
	Types getType();
	Colors getColor();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) = 0;
};
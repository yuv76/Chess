#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(Colors color, Types type, int row, int col);
	~Queen();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);
};
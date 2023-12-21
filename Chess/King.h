#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(Colors color, Types type, int row, int col);
	~King();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);
};

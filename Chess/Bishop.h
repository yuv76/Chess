#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Colors color, Types type, int row, int col);
	~Bishop();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);
};
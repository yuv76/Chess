#pragma once
#include "Piece.h"

class Tower :public Piece
{
public:
	Tower(Colors color, Types type, int row, int col);
	~Tower();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);
};
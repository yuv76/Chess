#pragma once
#include "Piece.h"

class knight : public Piece
{
public:
	knight(Colors color, Types type, int row, int col);
	~knight();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);
};
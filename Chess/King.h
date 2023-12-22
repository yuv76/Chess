#pragma once
#include "Piece.h"

#define WHITE_KING 'K'
#define BlACK_KING 'k'

class King : public Piece
{
public:
	King(Colors color, Types type, int row, int col);
	virtual ~King();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);

	friend std::ostream& operator<<(std::ostream& os, King& king);
};

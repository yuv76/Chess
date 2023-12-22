#pragma once
#include "Piece.h"

#define WHITE_KNIGHT 'N'
#define BlACK_KNIGHT 'n'

class knight : public Piece
{
public:
	knight(Colors color, Types type, int row, int col);
	virtual ~knight();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);

	friend std::ostream& operator<<(std::ostream& os, knight& Knig);
};
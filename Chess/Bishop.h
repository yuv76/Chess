#pragma once
#include "Piece.h"

#define WHITE_BISHOP 'B'
#define BlACK_BISHOP 'b'

class Bishop : public Piece
{
public:
	Bishop(Colors color, Types type, int row, int col);
	virtual ~Bishop();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);

	friend std::ostream& operator<<(std::ostream& os, Bishop& bish);
};
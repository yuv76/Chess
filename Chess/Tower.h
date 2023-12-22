#pragma once
#include "Piece.h"

#define WHITE_TOWER 'R'
#define BLACK_TOWER 'r'

class Tower : public Piece
{
public:
	Tower(Colors color, Types type, int row, int col);
	virtual ~Tower();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);

	friend std::ostream& operator<<(std::ostream& os, Tower& tow);
};

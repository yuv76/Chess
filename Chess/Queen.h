#pragma once
#include "Piece.h"

#define WHITE_QUEEN 'Q'
#define BLACK_QUEEN 'q'

class Queen : public Piece
{
public:
	Queen(Colors color, Types type, int row, int col);
	virtual ~Queen();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);

	friend std::ostream& operator<<(std::ostream& os, Queen& que);
};


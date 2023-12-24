#pragma once
#include "Piece.h"

#define WHITE_QUEEN 'Q'
#define BLACK_QUEEN 'q'

class Queen : public Piece
{
public:
	Queen(Colors color, Types type, int row, int col);
	virtual ~Queen();
	bool canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const override;
	
	virtual char getInitial(Colors color);
};

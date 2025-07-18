#pragma once
#include "Piece.h"

#define WHITE_TOWER 'R'
#define BLACK_TOWER 'r'

class Tower : public Piece
{
public:
	Tower(Colors color, Types type, int row, int col);
	virtual ~Tower();
	bool canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const override;

	virtual char getInitial(Colors color);
};


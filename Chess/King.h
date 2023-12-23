#pragma once
#include "Piece.h"

#define WHITE_KING 'K'
#define BlACK_KING 'k'

class King : public Piece
{
public:
	King(Colors color, Types type, int row, int col);
	virtual ~King();
	bool canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const override;

	friend std::ostream& operator<<(std::ostream& os, King& king);
};

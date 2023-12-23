#pragma once
#include "Piece.h"

#define WHITE_KNIGHT 'N'
#define BlACK_KNIGHT 'n'

class knight : public Piece
{
public:
	knight(Colors color, Types type, int row, int col);
	virtual ~knight();
	bool canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const override;

	virtual void getInitial(std::ostream& os, Colors color);
};
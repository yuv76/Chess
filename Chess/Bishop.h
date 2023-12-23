#pragma once
#include "Piece.h"

#define WHITE_BISHOP 'B'
#define BlACK_BISHOP 'b'

class Bishop : public Piece
{
public:
	Bishop(Colors color, Types type, int row, int col);
	virtual ~Bishop();
	bool canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const override;

	virtual void getInitial(std::ostream& os, Colors color);
};
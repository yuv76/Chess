#pragma once
#include "Piece.h"

#define DIDNT_WALK_YET false

#define WHITE_PAWN 'P'
#define BLACK_PAWN 'p'

class Pawn : public Piece
{
public:
	Pawn(Colors color, Types type, int row, int col);
	virtual ~Pawn();
	bool canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const override;
	bool canEat(int sourceRow, int sourceCol, int destRow, int destCol) const;

	virtual char getInitial(Colors color);
};
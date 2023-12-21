#pragma once
#include "Piece.h"

#define DIDNT_WALK_YET false

class Pawn : public Piece
{
private:
	bool _hasWalked;
public:
	Pawn(Colors color, Types type, int row, int col);
	~Pawn();
	bool getIfWalked();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);
	bool canEat(int row, int col);
};
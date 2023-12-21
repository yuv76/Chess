#pragma once

class pawn
{
private:
	bool _hasWalked;
public:
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol);
	virtual bool canEatKing(int row, int col);
	bool canEat(int row, int col);
};
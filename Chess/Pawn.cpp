#include "Pawn.h"

/*

*/
Pawn::Pawn(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col), _hasWalked(DIDNT_WALK_YET)
{}

/*

*/
Pawn::~Pawn()
{

}

/*

*/
bool Pawn::getIfWalked()
{

}

/*

*/
bool Pawn::canBeMoved(int sourceRow, int sourceCol, int dest, int destCol)
{

}

/*

*/
bool Pawn::canEatKing(int row, int col)
{

}

/*

*/
bool Pawn::canEat(int row, int col)
{

}

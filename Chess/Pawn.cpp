#include "Pawn.h"


/*
C'tor for Pawn object
input: pawn's color, type, row and column
output: none
*/
Pawn::Pawn(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col), _hasWalked(DIDNT_WALK_YET)
{}

/*
D'tor for pawn object
input: none
output: none
*/
Pawn::~Pawn()
{}

/*
Returns whether the pawn had moved already or not
input: none
output: true if already walked, false otherwise
*/
bool Pawn::getIfWalked()
{
	return this->_hasWalked;
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

/*
the << operator, will print P uppercase if white or lowercase if black
input: stream, Knight
output: stream with the letter
*/
std::ostream& operator<<(std::ostream& os, Pawn& paw)
{
	char expression = ' ';

	if (paw.getColor() == WHITE)
	{
		expression = WHITE_PAWN;
	}
	else
	{
		expression = BLACK_PAWN;
	}
	os << expression;
	return os;
}

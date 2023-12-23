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
function checks if pawn can move in this direction.
input: source row and col, dest row and col.
output: true if can be moved and false if not.
*/
bool Pawn::canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	if (this->_hasWalked == false)
	{
		if (destRow - sourceRow == 2 && destCol - sourceCol == 0)
		{
			return true;
		}
	}
	if (destRow - sourceRow == 1 && destCol - sourceCol == 0)
	{
		return true;
	}
	return false;
}


/*
function checks if pawn can eat in the route (from [sourceRow][sourceCol] to [destRow][destCol].
input: source row and col, dest row and col.
output: true if can eat and false if not.
*/
bool Pawn::canEat(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	if (destRow - sourceRow == 1 && destCol - sourceCol == 1)
	{
		return true;
	}
	return false;
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

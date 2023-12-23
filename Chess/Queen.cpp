#include "Queen.h"

/*
C'tor for Queen object
input: queen's color, type, row and column
output: none
*/
Queen::Queen(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for Queen object
input: none
output: none
*/
Queen::~Queen()
{}

/*
function checks if Queen can move in this direction.
input: source row and col, dest row and col.
output: true if can be moved and false if not.
*/
bool Queen::canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	if (((destRow - sourceRow == destCol - sourceCol) || (destRow - sourceRow == -1 * (destCol - sourceCol))) || (sourceRow == destRow || sourceCol == destCol))
	{
		return true;
	}
	return false;
}



/*
the << operator, will print Q uppercase if white or lowercase if black
input: stream, Knight
output: stream with the letter
*/
std::ostream& operator<<(std::ostream& os, Queen& que)
{
	char expression = ' ';

	if (que.getColor() == WHITE)
	{
		expression = WHITE_QUEEN;
	}
	else
	{
		expression = BLACK_QUEEN;
	}
	os << expression;
	return os;
}
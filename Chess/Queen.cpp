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
prints queen's initial, according to its color
input: the queen's color
output: the initial
*/
void Queen::getInitial(std::ostream& os, Colors color)
{
	char expression = ' ';

	if (color == WHITE)
	{
		expression = WHITE_QUEEN;
	}
	else
	{
		expression = BLACK_QUEEN;
	}
	os << expression;
}

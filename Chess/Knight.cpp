#include "Knight.h"

/*
C'tor for knight object
input: knight's color, type, row and column
output: none
*/
knight::knight(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for knight object
input: none
output: none
*/
knight::~knight()
{

}

/*
function checks if knight can move in this direction.
input: source row and col, dest row and col.
output: true if can be moved and false if not.
*/
bool knight::canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	if (abs(destRow - sourceRow) == 2 && abs(destCol - sourceCol) == 1)
	{
		return true;
	}
	if (abs(destRow - sourceRow) == 1 && abs(destCol - sourceCol) == 2)
	{
		return true;
	}
	return false;
}

/*
prints knight's initial, according to its color
input: the knight's color
output: the initial
*/
char knight::getInitial(Colors color)
{
	char expression = ' ';

	if (color == WHITE)
	{
		expression = WHITE_KNIGHT;
	}
	else
	{
		expression = BlACK_KNIGHT;
	}
	return expression;
}

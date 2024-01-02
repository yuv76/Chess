#include "King.h"

/*
C'tor for king object.
input: king's color, type, row and column.
output: none
*/
King::King(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for king object.
input: none.
output: none.
*/
King::~King()
{

}

/*
function checks if king can move in this direction.
input: source row and col, dest row and col.
output: true if can be moved and false if not.
*/
bool King::canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	//check king's movements to all 8 sides.
	if (((destRow - sourceRow == 1) && (destCol == sourceCol)) || ((destRow - sourceRow == 1) && (destCol - sourceCol == 1)) || ((destRow - sourceRow == 1) && (destCol - sourceCol == -1)))
	{
		return true;
	}
	if (((destRow - sourceRow == -1) && (destCol == sourceCol)) || ((destRow - sourceRow == -1) && (destCol - sourceCol == 1)) || ((destRow - sourceRow == -1) && (destCol - sourceCol == -1)))
	{
		return true;
	}
	if ((destCol - sourceCol == 1) && (destRow == sourceRow))
	{
		return true;
	}
	if (((destCol - sourceCol == -1) && (destRow == sourceRow)))
	{
		return true;
	}
	return false;
}

/*
prints king's initial, according to its color.
input: the king's color.
output: the initial.
*/
char King::getInitial(Colors color)
{
	char expression = ' ';

	if (color == WHITE)
	{
		expression = WHITE_KING;
	}
	else
	{
		expression = BlACK_KING;
	}
	return expression;
}

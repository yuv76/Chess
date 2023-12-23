#include "Bishop.h"

/*
C'tor for Bishop object
input: bishop's color, typerow and column
output: none.
*/
Bishop::Bishop(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for bishop object
input: none.
output: none.
*/
Bishop::~Bishop()
{}

/*
function checks if Bishop can move in this direction.
input: source row and col, dest row and col.
output: true if can be moved and false if not.
*/
bool Bishop::canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	if ((destRow - sourceRow == destCol - sourceCol) || (destRow - sourceRow == -1 * (destCol - sourceCol)))
	{
		return true;
	}
	return false;
}

/*

*/
char Bishop::getInitial(Colors color)
{
	char expression = ' ';

	if (color == WHITE)
	{
		expression = WHITE_BISHOP;
	}
	else
	{
		expression = BlACK_BISHOP;
	}
	return expression;
}

/*
the << operator, will print B uppercase if white or lowercase if black
input: stream, bishop
output: stream with the letter
*/
std::ostream& operator<<(std::ostream& os, Bishop& bish)
{
	Colors color = bish.getColor();
	os << bish.getInitial(color);
	return os;
}

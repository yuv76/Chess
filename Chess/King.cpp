#include "King.h"

/*
C'tor for king object
input: king's color, type, row and column
output: none
*/
King::King(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for king object
input: none
output: none
*/
King::~King()
{

}

/*
function checks if king can move in this direction.
input: source row and col, dest row and col.
output: true if can be moved and false if not.
*/
bool King::canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol)
{
	if (destRow - sourceRow == 1 || destRow - sourceRow == -1 || destCol - sourceCol == 1 || destCol - sourceCol == -1)
	{
		return true;
	}
	return false;
}


/*
the << operator, will print K uppercase if white or lowercase if black
input: stream, king
output: stream with the letter
*/
std::ostream& operator<<(std::ostream& os, King& king)
{
	char expression = ' ';

	if (king.getColor() == WHITE)
	{
		expression = WHITE_KING;
	}
	else
	{
		expression = BlACK_KING;
	}
	os << expression;
	return os;
}
